#include <QXmlStreamReader>
#include "lipsync_midiseq.h"
#include "command.h"
#include "logger.h"
#include "debug.h"

#define readULL reader.readElementText().toULongLong
#define readUI reader.readElementText().toUInt
#define errorChk(); if(reader.hasError()) {debugger("An error has occurred." << reader.error() << reader.errorString());}

void midiseq::Sequence_VSQX :: readSequence(QFile &file)
{
    QXmlStreamReader reader(&file);

    if(reader.readNextStartElement())
    {
        if(reader.name() == "vsq4" || reader.name() == "vsq3")
        {
            while(reader.readNextStartElement())
            {
                debugger("Name (1):" << reader.name());
                errorChk();
                if(reader.name() == "masterTrack")
                {
                    while(reader.readNextStartElement())
                    {
                        debugger("Name (2):" << reader.name());
                        errorChk();
                        if(reader.name() == "resolution")
                            this->master_track.sequence_resolution = readULL();
                        else if(reader.name() == "preMeasure")
                            this->master_track.sequence_preMeasure = readULL();
                        else if(reader.name() == "timeSig")
                        {
                            TimeSignature ts;
                            while(reader.readNextStartElement())
                            {
                                debugger("Name (3):" << reader.name());
                                errorChk();
                                if(reader.name() == "m" || reader.name() == "posMes")
                                    ts.measure = readULL();
                                else if(reader.name() == "nu" || reader.name() == "nume")
                                    ts.numerator = readUI();
                                else if(reader.name() == "de" || reader.name() == "denomi")
                                    ts.denominator = readUI();
                            }
                            this->master_track.sequence_timeSignature_vector.append(ts);
                        }
                        else if(reader.name() == "tempo")
                        {
                            Tempo temp;
                            while(reader.readNextStartElement())
                            {
                                debugger("Name (3):" << reader.name());
                                errorChk();
                                if(reader.name() == "t" || reader.name() == "posTick")
                                    temp.tick = readULL();
                                else if(reader.name() == "v" || reader.name() == "bpm")
                                    temp.value = readULL();
                            }
                            this->master_track.sequence_tempo_vector.append(temp);
                        }
                        else reader.skipCurrentElement();
                    }
                }
                else if(reader.name() == "vsTrack")
                {
                    Track trk;
                    while(reader.readNextStartElement())
                    {
                        debugger("Name (2b):" << reader.name());
                        errorChk();
                        if(reader.name() == "tNo" || reader.name() == "vsTrackNo")
                            trk.track_number = readUI();
                        else if(reader.name() == "vsPart" || reader.name() == "musicalPart")
                        {
                            Part prt;
                            while(reader.readNextStartElement())
                            {
                                debugger("Name (3b):" << reader.name());
                                errorChk();
                                if(reader.name() == "t" || reader.name() == "posTick")
                                    prt.tick = readULL();
                                else if(reader.name() == "playTime")
                                    prt.playTime = readULL();
                                else if(reader.name() == "note")
                                {
                                    Note nt;
                                    while(reader.readNextStartElement())
                                    {
                                        debugger("Name (4):" << reader.name());
                                        errorChk();
                                        if(reader.name() == "n" || reader.name() == "noteNum")
                                            nt.note_number = readUI();
                                        else if(reader.name() == "t" || reader.name() == "posTick")
                                            nt.tick = readULL();
                                        else if(reader.name() == "dur" || reader.name() == "durTick")
                                            nt.duration = readULL();
                                        else if(reader.name() == "y" || reader.name() == "lyric")
                                            nt.lyric = reader.readElementText();
                                        else if(reader.name() == "p" || reader.name() == "phnms")
                                            nt.phonemes = reader.readElementText();
                                        else reader.skipCurrentElement();
                                    }
                                    prt.note_vector.append(nt);
                                }
                                else reader.skipCurrentElement();
                            }
                            trk.part_vector.append(prt);
                        }
                        else reader.skipCurrentElement();
                    }
                    this->track_vector.append(trk);
                }
                else reader.skipCurrentElement();
            }
        }
    }

    debugger("End");
    return;
}

unsigned long long midiseq::DscSequence :: getTempo(Sequence &sequence, unsigned long long tick)
{
    for(int i=0; i<sequence.master_track.sequence_tempo_vector.length(); i++)
        if(sequence.master_track.sequence_tempo_vector.at(i).tick>=tick) return sequence.master_track.sequence_tempo_vector.at(i).value;

    return sequence.master_track.sequence_tempo_vector.at(0).value;
}

unsigned long long midiseq::DscSequence :: getTsNum(Sequence &sequence, unsigned long long measure)
{
    for(int i=0; i<sequence.master_track.sequence_timeSignature_vector.length(); i++)
        if(sequence.master_track.sequence_timeSignature_vector.at(i).measure>=measure) return sequence.master_track.sequence_timeSignature_vector.at(i).numerator;

    return sequence.master_track.sequence_timeSignature_vector.at(0).numerator;
}

unsigned long long midiseq::DscSequence :: getTsDen(Sequence &sequence, unsigned long long measure)
{
    for(int i=0; i<sequence.master_track.sequence_timeSignature_vector.length(); i++)
        if(sequence.master_track.sequence_timeSignature_vector.at(i).measure>=measure) return sequence.master_track.sequence_timeSignature_vector.at(i).denominator;

    return sequence.master_track.sequence_timeSignature_vector.at(0).denominator;
}

int midiseq::DscSequence :: getMouthId(char phoneme)
{
    switch(phoneme)
    {
        case 'V':
        case '@':
        case '{':
        case 'Q':
            return mouth_ft_a;

        case 'e':
            return mouth_ft_e;

        case 'I':
        case 'i':
            return mouth_ft_i;

        case 'O':
            return mouth_ft_o;

        case 'U':
        case 'u':
            return mouth_ft_u;

        default:
            return -1;
    }
}

void midiseq::DscSequence :: fromSequence(Sequence &sequence, VSQX_Settings &settings)
{
    const unsigned long long seq_resolution = sequence.master_track.sequence_resolution;
    const unsigned long long seq_preMeasure = sequence.master_track.sequence_preMeasure;

    int offset = settings.offset*100;
    if(settings.exclude_premeasure)
    {
        double preMeasureTicks = seq_resolution * seq_preMeasure;
        double preTempo = getTempo(sequence, 0); // not actually correct
        double preTsDen = getTsDen(sequence, 0); // not correct, either
        double preMeasureDuration = ((preMeasureTicks/(preTempo/6000))/(seq_resolution/preTsDen))*100000;
        offset -= qRound(preMeasureDuration);
    }

    int lastTime = -1;
    for(int i=0; i<sequence.track_vector.length(); i++)
        for(int j=0; j<sequence.track_vector.at(i).part_vector.length(); j++)
            for(int k=0; k<sequence.track_vector.at(i).part_vector.at(j).note_vector.length(); k++)
            {
                DscSequenceCommand cmd;
                double part_tick = sequence.track_vector.at(i).part_vector.at(j).tick;
                double note_tick = sequence.track_vector.at(i).part_vector.at(j).note_vector.at(k).tick;
                double total_tick = part_tick + note_tick;
                double tempo = getTempo(sequence, total_tick);
                double time = ((total_tick/(tempo/6000))/seq_resolution)*100000;
                cmd.divaTime = qRound(time) + offset;
                if(lastTime!=-1&&cmd.divaTime-lastTime>settings.transition_timeout) // mouth timeout
                {
                    DscSequenceCommand cmd_close;
                    cmd_close.divaTime = lastTime + settings.transition_timeout;
                    cmd_close.mouthId = mouth_ft_m;
                    dsc_sequence_commands.append(cmd_close);
                }
                lastTime = cmd.divaTime;
                for(int l=0; l < sequence.track_vector.at(i).part_vector.at(j).note_vector.at(k).phonemes.length(); l++)
                {
                    cmd.mouthId = getMouthId(sequence.track_vector.at(i).part_vector.at(j).note_vector.at(k).phonemes.at(l).toLatin1());
                    debugger("Phoneme:" << sequence.track_vector.at(i).part_vector.at(j).note_vector.at(k).phonemes.at(l).toLatin1() << "Mouth ID:" << cmd.mouthId);
                    if(cmd.mouthId!=-1) break;
                }

                debugger("Time:" << cmd.divaTime << "Mouth ID:" << cmd.mouthId);
                dsc_sequence_commands.append(cmd);
            }
    DscSequenceCommand cmd_close;
    cmd_close.divaTime = lastTime + settings.transition_timeout;
    cmd_close.mouthId = mouth_ft_m;
    dsc_sequence_commands.append(cmd_close);
}

void midiseq::DscSequence :: applyCommands(QPlainTextEdit *dscpte, VSQX_Settings &settings)
{
    logger::log("Adding DSC commands...\n");

    QStringList commandlist;
    commandlist=dscpte->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");

    if(settings.delete_existing)
    {
        for(int i=0; i<commandlist.length(); i++)
        {
            //if(commandlist.at(i).simplified().startsWith("MOUTH_ANIM("+QString::number(settings.performer)+','))
            if(commandlist.at(i).simplified().startsWith("MOUTH_ANIM("+QString::number(settings.performer)+',')||(commandlist.at(i).simplified().startsWith("EDIT_MOUTH_ANIM(")&&commandlist.at(i-1).simplified().startsWith("SET_CHARA("+QString::number(settings.performer)+')')))
                commandlist.removeAt(i);
        }
    }

    for(int i=0; i<dsc_sequence_commands.length(); i++)
        if(dsc_sequence_commands.at(i).mouthId!=-1)
        {
            //insertCommand(commandlist, dsc_sequence_commands.at(i).divaTime, "MOUTH_ANIM("+QString::number(settings.performer)+",0,"+QString::number(dsc_sequence_commands.at(i).mouthId)+','+dsc_sequence_commands.at(i).transitionTime+",-1)");
            logger::log(hmsTimeFromDivaTime(dsc_sequence_commands.at(i).divaTime)+" - MI: "+QString::number(dsc_sequence_commands.at(i).mouthId)+"; TT: "+QString::number(settings.transition_duration)+"\n");
            //insertCommand(commandlist, dsc_sequence_commands.at(i).divaTime, "MOUTH_ANIM("+QString::number(settings.performer)+",0,"+QString::number(dsc_sequence_commands.at(i).mouthId)+','+QString::number(settings.transition_duration)+",-1)");
            insertCommand(commandlist, dsc_sequence_commands.at(i).divaTime, "SET_CHARA("+QString::number(settings.performer)+");\nEDIT_MOUTH_ANIM("+QString::number(dsc_sequence_commands.at(i).mouthId)+','+QString::number(settings.transition_duration)+')');
        }

    dscpte->document()->clear();
    for(int i=0; i<commandlist.length(); i++)
        if(commandlist.at(i).isEmpty())
            dscpte->insertPlainText(commandlist.at(i));
        else
            dscpte->insertPlainText(commandlist.at(i)+';');

}
