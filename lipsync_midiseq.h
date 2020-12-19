#ifndef LIPSYNC_VSQX_H
#define LIPSYNC_VSQX_H
#include <QVector>
#include <QFile>
#include <QPlainTextEdit>
#include <lipsync_settings.h>

namespace midiseq
{
    class Sequence
    {
    public:
        struct Note
        {
            unsigned int note_number = 0; // n
            unsigned long long tick = 0; // t
            unsigned long long duration = 0; // dur
            QString lyric = ""; // y
            QString phonemes = ""; // p
        };

        struct Part
        {
            unsigned long long tick = 0; // t
            unsigned long long playTime = 0; // playTime
            //QString part_name = ""; // name
            //QString part_comment = ""; // comment
            QVector<Note> note_vector; // note
        };

        struct Track
        {
            unsigned int track_number = 0; // tNo
            //QString track_name = ""; // name
            //QString track_comment = ""; // comment
            QVector<Part> part_vector; // vsPart
        };

        struct TimeSignature
        {
            unsigned long long measure = 0; // m; starting from the first pre-measure
            unsigned int numerator = 0; // nu
            unsigned int denominator = 0; // de
        };

        struct Tempo
        {
            unsigned long long tick = 0; // t
            unsigned long long value = 0; // v
        };

        struct MasterTrack
        {
            //QString sequence_name = ""; // seqName
            //QString sequence_comment = ""; // comment
            unsigned long long sequence_resolution = 0; // resolution
            unsigned long long sequence_preMeasure = 0; // preMeasure
            QVector<TimeSignature> sequence_timeSignature_vector; // timeSig;
            QVector<Tempo> sequence_tempo_vector; // tempo;
        };

        MasterTrack master_track; // masterTrack
        QVector<Track> track_vector; // vsTrack

        virtual void readSequence(QFile &file)=0;
        virtual ~Sequence(){};
    };

    class Sequence_VSQX : public Sequence
    {
    public:
        void readSequence(QFile &file);
    };

    class DscSequence
    {
    private:
        const int mouth_ft_a=0;
        const int mouth_ft_i=10;
        const int mouth_ft_u=11;
        const int mouth_ft_e=1;
        const int mouth_ft_o=2;
        const int mouth_ft_m=8;

        unsigned long long getTempo(Sequence &sequence, unsigned long long tick);
        unsigned long long getTsNum(Sequence &sequence, unsigned long long measure);
        unsigned long long getTsDen(Sequence &sequence, unsigned long long measure);
        int getMouthId(char phoneme);

    public:
        struct DscSequenceCommand
        {
            int divaTime = 0;
            int mouthId = -1;
        };

        QVector<DscSequenceCommand> dsc_sequence_commands;

        void fromSequence(Sequence &sequence, VSQX_Settings &settings);
        void applyCommands(QPlainTextEdit *dscpte, VSQX_Settings &settings);
    };
}

#endif // LIPSYNC_VSQX_H
