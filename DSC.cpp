#include "DSC.h"
#include "command.h"
#include <QMessageBox>

DivaScriptOpcode::DivaScriptOpcode(QTextEdit* logEdit)
{
    QFile dbfile(":/opcode_db/db.json");
    dbfile.open(QIODevice::ReadOnly);

    jsondb=QJsonDocument::fromJson(dbfile.readAll());
    jsonob=jsondb.object();
    jsonkeys=jsonob.keys();

    dbfile.close();

    this->logEdit=logEdit;
}

int DivaScriptOpcode::getOpcodeParamCount(int opcodeNumber)
{
    for(int i=0; i<jsonkeys.length(); i++)
    {
        const QJsonValue val_top = jsonob.value(jsonkeys.at(i));
        const QJsonValue val_mid = val_top.toObject().value("info_"+gameStr());
        const QJsonValue val = val_mid.toObject().value("id");
        if(val.toInt(-2)==opcodeNumber)
        {
            return val_mid.toObject().value("len").toInt(-1);
        }
    }

    return -1;
}

int DivaScriptOpcode::getOpcodeNumber(QString opcodeString)
{
    return jsonob.value(opcodeString).toObject().value("info_"+gameStr()).toObject().value("id").toInt(-1);
}

QString DivaScriptOpcode::getOpcodeString(int opcodeNumber)
{
    for(int i=0; i<jsonkeys.length(); i++)
    {
        const QJsonValue val_top = jsonob.value(jsonkeys.at(i));
        const QJsonValue val_mid = val_top.toObject().value("info_"+gameStr());
        const QJsonValue val = val_mid.toObject().value("id");
        if(val.toInt(-2)==opcodeNumber)
        {
            return jsonkeys.at(i);
        }
    }

    logEdit->append("E: DSC is corrupted. Unknown opcode "+QString::number(opcodeNumber)+'\n');
    return "UNKNOWN_OPCODE_"+QString::number(opcodeNumber);
}

void DivaScriptOpcode::fillCommandListWidget(QListWidget* qlw)
{
    for(int i=0; i<jsonkeys.length(); i++)
    {
        qlw->addItem(jsonkeys.at(i));
    }
}

void DivaScriptOpcode::logger(QString log)
{
    logEdit->append(log+"\n");
}

void DivaScriptOpcode_F::readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode)
{
    datastream.setByteOrder(uibyteorder);
    datastream.skipRawData(4);
    textedit->clear();
    textedit->setUndoRedoEnabled(false);
    textedit->setUpdatesEnabled(false);
    textedit->blockSignals(true);
    while(!(file.atEnd()))
    {
        int opc;
        datastream >> opc;
        QString ops = getOpcodeString(opc);
        if(!testmode) textedit->insertPlainText(ops+"(");
        for(int i=0; i<getOpcodeParamCount(opc); i++)
        {
            int byte;
            datastream >> byte;
            if(!testmode)
            {
                if(i) textedit->insertPlainText(", ");
                textedit->insertPlainText(QString::number(byte));
            }
        }
        if(!testmode) textedit->insertPlainText(");\n");
    }
    textedit->blockSignals(false);
    textedit->setUndoRedoEnabled(true);
    textedit->setUpdatesEnabled(true);
    editWidgets.tabedit->setEnabled(false);
}

void DivaScriptOpcode_F::writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder)
{
    datastream.setByteOrder(uibyteorder);
    datastream << 302121504;
    QString line;
    QStringList commandlist;
    commandlist=textedit->document()->toPlainText().split(';', Qt::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
    for(int i=0; i<commandlist.length(); i++)
    {
        QStringList splitcommand=commandlist.at(i).split('(', Qt::SkipEmptyParts);
        if(!splitcommand.length()) continue;
        int opcode=getOpcodeNumber(splitcommand.at(0));
        datastream << opcode;
        QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', Qt::SkipEmptyParts);
        int expcount=getOpcodeParamCount(opcode);
        if(!(splitparams.length()==expcount))
        {
            logger("E: Parameter count mismatch for opcode 0x"+QString::number(opcode, 16). toUpper()+" AKA "+splitcommand.at(0)+"\nExpected: "+QString::number(expcount)+"\nGot: "+QString::number(splitparams.length()));
            file.close();
            return;
        }
        for(int j=0; j<splitparams.length(); j++)
            datastream << splitparams.at(j).toInt();
    }
};

void DivaScriptOpcode_F2::readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode)
{
    datastream.setByteOrder(uibyteorder);
    datastream.skipRawData(72);
    textedit->clear();
    textedit->setUndoRedoEnabled(false);
    textedit->setUpdatesEnabled(false);
    textedit->blockSignals(true);
    while(!(file.atEnd()))
    {
        int opc;
        datastream >> opc;
        if((uibyteorder==QDataStream::LittleEndian&&opc==1128681285)||(uibyteorder==QDataStream::BigEndian&&opc==1162823235)) break; // "EOFC"
        QString ops = getOpcodeString(opc);
        if(!testmode) textedit->insertPlainText(ops+"(");
        for(int i=0; i<getOpcodeParamCount(opc); i++)
        {
            int byte;
            datastream >> byte;
            if(!testmode)
            {
                if(i) textedit->insertPlainText(", ");
                textedit->insertPlainText(QString::number(byte));
            }
        }
        if(!testmode) textedit->insertPlainText(");\n");
    }
    textedit->blockSignals(false);
    textedit->setUndoRedoEnabled(true);
    textedit->setUpdatesEnabled(true);
    editWidgets.tabedit->setEnabled(false);
}

void DivaScriptOpcode_F2::writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder)
{
    datastream.setByteOrder(QDataStream::ByteOrder::LittleEndian);
    // TODO endianness flag 0x10 LE, 0x18 BE?
    datastream << 1129535056 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
    datastream.setByteOrder(uibyteorder);
    QString line;
    QStringList commandlist;
    commandlist=textedit->document()->toPlainText().split(';', Qt::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
    for(int i=0; i<commandlist.length(); i++)
    {
        QStringList splitcommand=commandlist.at(i).split('(', Qt::SkipEmptyParts);
        if(!splitcommand.length()) continue;
        int opcode=getOpcodeNumber(splitcommand.at(0));
        datastream << opcode;
        QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', Qt::SkipEmptyParts);
        int expcount=getOpcodeParamCount(opcode);
        if(!(splitparams.length()==expcount))
        {
            logger("E: Parameter count mismatch for opcode 0x"+QString::number(opcode, 16). toUpper()+" AKA "+splitcommand.at(0)+"\nExpected: "+QString::number(expcount)+"\nGot: "+QString::number(splitparams.length()));
            file.close();
            return;
        }
        for(int j=0; j<splitparams.length(); j++)
            datastream << splitparams.at(j).toInt();
    }
    datastream.setByteOrder(QDataStream::ByteOrder::LittleEndian);
    datastream << 1128681285 << 0 << 0 << 0 << 0 << 0 << 0;
    // ???:
    int size=(int)(file.size())-92;
    file.seek(4);
    datastream << size;
    file.seek(20);
    datastream << size;
}

void DivaScriptOpcode_X::readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode)
{
    datastream.setByteOrder(uibyteorder);
    datastream.skipRawData(72);
    textedit->clear();
    textedit->setUndoRedoEnabled(false);
    textedit->setUpdatesEnabled(false);
    textedit->blockSignals(true);
    while(!(file.atEnd()))
    {
        int opc;
        datastream >> opc;
        if((uibyteorder==QDataStream::LittleEndian&&opc==1128681285)||(uibyteorder==QDataStream::BigEndian&&opc==1162823235)) break; // "EOFC"
        QString ops = getOpcodeString(opc);
        if(!testmode) textedit->insertPlainText(ops+"(");
        for(int i=0; i<getOpcodeParamCount(opc); i++)
        {
            int byte;
            datastream >> byte;
            if(!testmode)
            {
                if(i) textedit->insertPlainText(", ");
                textedit->insertPlainText(QString::number(byte));
            }
        }
        if(!testmode) textedit->insertPlainText(");\n");
    }
    textedit->blockSignals(false);
    textedit->setUndoRedoEnabled(true);
    textedit->setUpdatesEnabled(true);
    editWidgets.tabedit->setEnabled(false);
}

void DivaScriptOpcode_X::writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder)
{
    datastream.setByteOrder(QDataStream::ByteOrder::LittleEndian);
    // TODO endianness flags like F 2nd??
    datastream << 1129535056 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
    datastream.setByteOrder(uibyteorder);
    QString line;
    QStringList commandlist;
    commandlist=textedit->document()->toPlainText().split(';', Qt::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
    for(int i=0; i<commandlist.length(); i++)
    {
        QStringList splitcommand=commandlist.at(i).split('(', Qt::SkipEmptyParts);
        if(!splitcommand.length()) continue;
        int opcode=getOpcodeNumber(splitcommand.at(0));
        datastream << opcode;
        QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', Qt::SkipEmptyParts);
        int expcount=getOpcodeParamCount(opcode);
        if(!(splitparams.length()==expcount))
        {
            logger("E: Parameter count mismatch for opcode 0x"+QString::number(opcode, 16). toUpper()+" AKA "+splitcommand.at(0)+"\nExpected: "+QString::number(expcount)+"\nGot: "+QString::number(splitparams.length()));
            file.close();
            return;
        }
        for(int j=0; j<splitparams.length(); j++)
            datastream << splitparams.at(j).toInt();
    }
    datastream.setByteOrder(QDataStream::ByteOrder::LittleEndian);
    datastream << 1128681285 << 0 << 0 << 0 << 0 << 0 << 0;
}

void DivaScriptOpcode_FT::readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode)
{
    datastream.setByteOrder(uibyteorder);
    datastream.skipRawData(4);
    textedit->clear();
    textedit->setUndoRedoEnabled(false);
    textedit->setUpdatesEnabled(false);
    textedit->blockSignals(true);
    while(!(file.atEnd()))
    {
        int opc;
        datastream >> opc;

        QString ops = getOpcodeString(opc);
        if(!testmode) textedit->insertPlainText(ops+"(");
        for(int i=0; i<getOpcodeParamCount(opc); i++)
        {
            int byte;
            datastream >> byte;
            if(!testmode)
            {
                if(i) textedit->insertPlainText(", ");
                textedit->insertPlainText(QString::number(byte));
            }
        }
        if(!testmode) textedit->insertPlainText(");\n");
    }
    textedit->blockSignals(false);
    textedit->setUndoRedoEnabled(true);
    textedit->setUpdatesEnabled(true);
    editWidgets.tabedit->setEnabled(false);
}

void DivaScriptOpcode_FT::writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder)
{
    datastream.setByteOrder(uibyteorder);
    datastream << 335874337;
    QString line;
    QStringList commandlist;
    commandlist=textedit->document()->toPlainText().split(';', Qt::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
    for(int i=0; i<commandlist.length(); i++)
    {
        QStringList splitcommand=commandlist.at(i).split('(', Qt::SkipEmptyParts);
        if(!splitcommand.length()) continue;
        int opcode=getOpcodeNumber(splitcommand.at(0));
        datastream << opcode;
        QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', Qt::SkipEmptyParts);
        int expcount=getOpcodeParamCount(opcode);
        if(!(splitparams.length()==expcount))
        {
            logger("E: Parameter count mismatch for opcode 0x"+QString::number(opcode, 16). toUpper()+" AKA "+splitcommand.at(0)+"\nExpected: "+QString::number(expcount)+"\nGot: "+QString::number(splitparams.length()));
            file.close();
            return;
        }
        for(int j=0; j<splitparams.length(); j++)
            datastream << splitparams.at(j).toInt();
    }
}

void DivaScriptOpcode_PDA::readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode)
{
    datastream.setByteOrder(uibyteorder);
    textedit->clear();
    textedit->setUndoRedoEnabled(false);
    textedit->setUpdatesEnabled(false);
    textedit->blockSignals(true);
    while(!(file.atEnd()))
    {
        int opc;
        datastream >> opc;
        QString ops = getOpcodeString(opc);
        if(!testmode) textedit->insertPlainText(ops+"(");
        for(int i=0; i<getOpcodeParamCount(opc); i++)
        {
            int byte;
            datastream >> byte;
            if(!testmode)
            {
                if(i) textedit->insertPlainText(", ");
                textedit->insertPlainText(QString::number(byte));
            }
        }
        if(!testmode) textedit->insertPlainText(");\n");
    }
    textedit->blockSignals(false);
    textedit->setUndoRedoEnabled(true);
    textedit->setUpdatesEnabled(true);
    editWidgets.tabedit->setEnabled(false);
}

void DivaScriptOpcode_PDA::writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder)
{
    datastream.setByteOrder(uibyteorder);
    QString line;
    QStringList commandlist;
    commandlist=textedit->document()->toPlainText().split(';', Qt::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
    for(int i=0; i<commandlist.length(); i++)
    {
        QStringList splitcommand=commandlist.at(i).split('(', Qt::SkipEmptyParts);
        if(!splitcommand.length()) continue;
        int opcode=getOpcodeNumber(splitcommand.at(0));
        datastream << opcode;
        QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', Qt::SkipEmptyParts);
        int expcount=getOpcodeParamCount(opcode);
        if(!(splitparams.length()==expcount))
        {
            logger("E: Parameter count mismatch for opcode 0x"+QString::number(opcode, 16). toUpper()+" AKA "+splitcommand.at(0)+"\nExpected: "+QString::number(expcount)+"\nGot: "+QString::number(splitparams.length()));
            file.close();
            return;
        }
        for(int j=0; j<splitparams.length(); j++)
            datastream << splitparams.at(j).toInt();
    }
}

void DivaScriptOpcode_DIVA::readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode)
{
    datastream.setByteOrder(uibyteorder);
    textedit->clear();
    textedit->setUndoRedoEnabled(false);
    textedit->setUpdatesEnabled(false);
    textedit->blockSignals(true);
    while(!(file.atEnd()))
    {
        int opc;
        datastream >> opc;
        QString ops = getOpcodeString(opc);
        if(!testmode) textedit->insertPlainText(ops+"(");
        for(int i=0; i<getOpcodeParamCount(opc); i++)
        {
            int byte;
            datastream >> byte;
            if(!testmode)
            {
                if(i) textedit->insertPlainText(", ");
                textedit->insertPlainText(QString::number(byte));
            }
        }
        if(!testmode) textedit->insertPlainText(");\n");
    }
    textedit->blockSignals(false);
    textedit->setUndoRedoEnabled(true);
    textedit->setUpdatesEnabled(true);
    editWidgets.tabedit->setEnabled(false);
}

void DivaScriptOpcode_DIVA::writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder)
{
    datastream.setByteOrder(uibyteorder);
    QString line;
    QStringList commandlist;
    commandlist=textedit->document()->toPlainText().split(';', Qt::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
    for(int i=0; i<commandlist.length(); i++)
    {
        QStringList splitcommand=commandlist.at(i).split('(', Qt::SkipEmptyParts);
        if(!splitcommand.length()) continue;
        int opcode=getOpcodeNumber(splitcommand.at(0));
        datastream << opcode;
        QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', Qt::SkipEmptyParts);
        int expcount=getOpcodeParamCount(opcode);
        if(!(splitparams.length()==expcount))
        {
            logger("E: Parameter count mismatch for opcode 0x"+QString::number(opcode, 16). toUpper()+" AKA "+splitcommand.at(0)+"\nExpected: "+QString::number(expcount)+"\nGot: "+QString::number(splitparams.length()));
            file.close();
            return;
        }
        for(int j=0; j<splitparams.length(); j++)
            datastream << splitparams.at(j).toInt();
    }
}

void DivaScriptOpcode_DIVA2::readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode)
{
    datastream.setByteOrder(uibyteorder);
    textedit->clear();
    textedit->setUndoRedoEnabled(false);
    textedit->setUpdatesEnabled(false);
    textedit->blockSignals(true);
    while(!(file.atEnd()))
    {
        int opc;
        datastream >> opc;
        QString ops = getOpcodeString(opc);
        if(!testmode) textedit->insertPlainText(ops+"(");
        for(int i=0; i<getOpcodeParamCount(opc); i++)
        {
            int byte;
            datastream >> byte;
            if(!testmode)
            {
                if(i) textedit->insertPlainText(", ");
                textedit->insertPlainText(QString::number(byte));
            }
        }
        if(!testmode) textedit->insertPlainText(");\n");
    }
    textedit->blockSignals(false);
    textedit->setUndoRedoEnabled(true);
    textedit->setUpdatesEnabled(true);
    editWidgets.tabedit->setEnabled(false);
}

void DivaScriptOpcode_DIVA2::writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder)
{
    datastream.setByteOrder(uibyteorder);
    QString line;
    QStringList commandlist;
    commandlist=textedit->document()->toPlainText().split(';', Qt::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
    for(int i=0; i<commandlist.length(); i++)
    {
        QStringList splitcommand=commandlist.at(i).split('(', Qt::SkipEmptyParts);
        if(!splitcommand.length()) continue;
        int opcode=getOpcodeNumber(splitcommand.at(0));
        datastream << opcode;
        QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', Qt::SkipEmptyParts);
        int expcount=getOpcodeParamCount(opcode);
        if(!(splitparams.length()==expcount))
        {
            logger("E: Parameter count mismatch for opcode 0x"+QString::number(opcode, 16). toUpper()+" AKA "+splitcommand.at(0)+"\nExpected: "+QString::number(expcount)+"\nGot: "+QString::number(splitparams.length()));
            file.close();
            return;
        }
        for(int j=0; j<splitparams.length(); j++)
            datastream << splitparams.at(j).toInt();
    }
}

void DivaScriptOpcode_DIVA2Edit::readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode)
{
    QTextCodec *codec = QTextCodec::codecForName("Shift_JIS");
    if(codec==nullptr) return;

    const int DIVA_SCRIPT_OFFSET = 0xE108;
    const int LYRICS_OFFSET = 0x2C2AC;
    const int BPM_OFFSET = 0x337DC;
    const int SONGEND_OFFSET = 0x353FC;
    const int STAGE_OFFSET = 0x35408;
    const int BAR_COUNT = 600;
    const int LYRICS_LENGTH = 0x29;
    const short max = 32767;

    // Initialize table
    for(int i=0; i < BAR_COUNT; i++)
        editWidgets.bartable->insertRow(0);
    for(int i=0; i < 4; i++)
        editWidgets.bartable->insertColumn(0);

    int dtoffset=0;

    if(uibyteorder==QDataStream::ByteOrder::BigEndian) dtoffset=16;
    datastream.setByteOrder(uibyteorder);
    textedit->clear();
    textedit->setUndoRedoEnabled(false);
    textedit->setUpdatesEnabled(false);
    textedit->blockSignals(true);

    // DSC
    file.seek(DIVA_SCRIPT_OFFSET+dtoffset);
    for(short s=0; s<max; s++)
    {
        int opc;
        datastream >> opc;
        if(getOpcodeParamCount(opc)==-1) break;
        QString ops = getOpcodeString(opc);
        if(!testmode) textedit->insertPlainText(ops+"(");
        for(int i=0; i<getOpcodeParamCount(opc); i++)
        {
            int byte;
            datastream >> byte;
            if(!testmode)
            {
                if(i) textedit->insertPlainText(", ");
                textedit->insertPlainText(QString::number(byte));
            }
        }
        if(!testmode) textedit->insertPlainText(");\n");
    }

    // Lyrics
    {
        file.seek(LYRICS_OFFSET+dtoffset);
        QString line;
        for(int i=0; i<BAR_COUNT; i++)
        {
            char* data = new char[LYRICS_LENGTH];
            file.read(data, LYRICS_LENGTH);
            line = codec->toUnicode(data);
            if(!(line.isEmpty()||line.isNull()))
                editWidgets.bartable->setItem(i, 0, new QTableWidgetItem(line));
            delete[] data;
        }
    }

    // BPM changes
    {
        file.seek(BPM_OFFSET+dtoffset);
        for(int i=0; i<BAR_COUNT; i++)
        {
            int bpm;
            datastream >> bpm;
            if(bpm!=-1) editWidgets.bartable->setItem(i, 1, new QTableWidgetItem(QString::number(bpm)));
        }
        for(int i=0; i<BAR_COUNT; i++)
        {
            int changebar;
            datastream >> changebar;
            if(changebar!=-1) editWidgets.bartable->setItem(i, 2, new QTableWidgetItem(QString::number(changebar)));
        }
    }

    // TS changes
    {
        for(int i=0; i<BAR_COUNT; i++)
        {
            int ts;
            datastream >> ts;
            if(ts!=-1) editWidgets.bartable->setItem(i, 3, new QTableWidgetItem(QString::number(ts+1)));
        }
    }

    const int STAGE_COUNT = 20;
    const int MOTION_COUNT = 30;
    const int HAND_ITEM_COUNT = 9;
    const int EFFECT_COUNT = 11;
    const int NAME_LENGTH = 0x28;

    // Song end
    {
        file.seek(SONGEND_OFFSET+dtoffset);
        int end;
        datastream >> end;
        if(end!=-1) editWidgets.songend->setValue(end);
    }

    // Modules
    {
        for(int i=0; i<2; i++)
        {
            int module;
            datastream >> module;
            if(module!=-1) editWidgets.modulelist->addItem(QString::number(module));
        }
    }

    // Stages
    {
        file.seek(STAGE_OFFSET+dtoffset);
        for(int i=0; i<STAGE_COUNT; i++)
        {
            int stage;
            datastream >> stage;
            if(stage!=-1) editWidgets.stagelist->addItem(QString::number(stage));
        }
    }

    // Motions
    {
        for(int i=0; i<MOTION_COUNT; i++)
        {
            int motion;
            datastream >> motion;
            if(motion!=-1) editWidgets.motionlist->addItem(QString::number(motion));
        }
    }

    // Button SFX
    {
        int sfx;
        datastream >> sfx;
        if(sfx!=-1) editWidgets.buttonsfx->setValue(sfx);
    }

    // Hand Items
    {
        for(int i=0; i<HAND_ITEM_COUNT; i++)
        {
            int hitem;
            datastream >> hitem;
            if(hitem!=-1) editWidgets.handitemlist->addItem(QString::number(hitem));
        }
    }

    // Effects
    {
        for(int i=0; i<EFFECT_COUNT; i++)
        {
            int effect;
            datastream >> effect;
            if(effect!=-1) editWidgets.effectlist->addItem(QString::number(effect));
        }
    }

    // Edit Name
    {
        char *data = new char[NAME_LENGTH];
        file.read(data, NAME_LENGTH);
        QString editname=codec->toUnicode(data);
        editWidgets.editname->setText(editname);
        delete[] data;
    }

    // Song Name
    {
        char *data = new char[NAME_LENGTH];
        file.read(data, NAME_LENGTH);
        QString songname=codec->toUnicode(data);
        editWidgets.songname->setText(songname);
        delete[] data;
    }

    // Start Time
    {
        int time;
        datastream >> time;
        editWidgets.songstart->setValue(time);
    }
    textedit->blockSignals(false);
    textedit->setUndoRedoEnabled(true);
    textedit->setUpdatesEnabled(true);
    editWidgets.tabedit->setEnabled(true);
}

int DivaScriptOpcode_Mirai::getOpcodeNumber(QString opcodeString)
{
    if(opcodeString=="END") return 0x00;
    else if(opcodeString=="TIME") return 0x01;
    else if(opcodeString=="MIKU_MOVE") return 0x02;
    else if(opcodeString=="MIKU_ROT") return 0x03;
    else if(opcodeString=="MIKU_DISP") return 0x04;
    else if(opcodeString=="MIKU_SHADOW") return 0x05;
    else if(opcodeString=="TARGET") return 0x06;
    else if(opcodeString=="SET_MOTION") return 0x07;
    else if(opcodeString=="SET_PLAYDATA") return 0x08;
    else if(opcodeString=="EFFECT") return 0x09;
    else if(opcodeString=="FADEIN_FIELD") return 0x0A;
    else if(opcodeString=="EFFECT_OFF") return 0x0B;
    else if(opcodeString=="SET_CAMERA") return 0x0C;
    else if(opcodeString=="DATA_CAMERA") return 0x0D;
    else if(opcodeString=="CHANGE_FIELD") return 0x0E;
    else if(opcodeString=="HIDE_FIELD") return 0x0F;
    else if(opcodeString=="MOVE_FIELD") return 0x10;
    else if(opcodeString=="FADEOUT_FIELD") return 0x11;
    else if(opcodeString=="EYE_ANIM") return 0x12;
    else if(opcodeString=="MOUTH_ANIM") return 0x13;
    else if(opcodeString=="HAND_ANIM") return 0x14;
    else if(opcodeString=="LOOK_ANIM") return 0x15;
    else if(opcodeString=="EXPRESSION") return 0x16;
    else if(opcodeString=="LOOK_CAMERA") return 0x17;
    else if(opcodeString=="LYRIC") return 0x18;
    else if(opcodeString=="MUSIC_PLAY") return 0x19;
    else if(opcodeString=="MODE_SELECT") return 0x1A;
    else if(opcodeString=="EDIT_MOTION") return 0x1B;
    else if(opcodeString=="BAR_TIME_SET") return 0x1C;
    else if(opcodeString=="SHADOWHEIGHT") return 0x1D;
    else if(opcodeString=="EDIT_FACE") return 0x1E;
    else if(opcodeString=="MOVE_CAMERA") return 0x1F;
    else if(opcodeString=="PV_END") return 0x20;
    else if(opcodeString=="SHADOWPOS") return 0x21;
    else if(opcodeString=="EDIT_LYRIC") return 0x22;
    else if(opcodeString=="EDIT_TARGET") return 0x23;
    else if(opcodeString=="EDIT_MOUTH") return 0x24;
    else if(opcodeString=="SET_CHARA") return 0x25;
    else if(opcodeString=="EDIT_MOVE") return 0x26;
    else if(opcodeString=="EDIT_SHADOW") return 0x27;
    else if(opcodeString=="EDIT_EYELID") return 0x28;
    else if(opcodeString=="EDIT_EYE") return 0x29;
    else if(opcodeString=="EDIT_ITEM") return 0x2A;
    else if(opcodeString=="EDIT_EFFECT") return 0x2B;
    else if(opcodeString=="EDIT_DISP") return 0x2C;
    else if(opcodeString=="EDIT_HAND_ANIM") return 0x2D;
    else if(opcodeString=="AIM") return 0x2E;
    else if(opcodeString=="HAND_ITEM") return 0x2F;
    else if(opcodeString=="EDIT_BLUSH") return 0x30;
    else if(opcodeString=="NEAR_CLIP") return 0x31;
    else if(opcodeString=="CLOTH_WET") return 0x32;
    else if(opcodeString=="LIGHT_ROT") return 0x33;
    else if(opcodeString=="SCENE_FADE") return 0x34;
    else if(opcodeString=="TONE_TRANS") return 0x35;
    else if(opcodeString=="SATURATE") return 0x36;
    else if(opcodeString=="FADE_MODE") return 0x37;
    else if(opcodeString=="AUTO_BLINK") return 0x38;
    else if(opcodeString=="PARTS_DISP") return 0x39;
    else if(opcodeString=="TARGET_FLYING_TIME") return 0x3A;
    else if(opcodeString=="CHARA_SIZE") return 0x3B;
    else if(opcodeString=="CHARA_HEIGHT_ADJUST") return 0x3C;
    else if(opcodeString=="ITEM_ANIM") return 0x3D;
    else if(opcodeString=="CHARA_POS_ADJUST") return 0x3E;
    else if(opcodeString=="SCENE_ROT") return 0x3F;
    else if(opcodeString=="EDIT_MOT_SMOOTH_LEN") return 0x40;
    else if(opcodeString=="PV_BRANCH_MODE") return 0x41;
    else if(opcodeString=="DATA_CAMERA_START") return 0x42;
    else if(opcodeString=="MOVIE_PLAY") return 0x43;
    else if(opcodeString=="MOVIE_DISP") return 0x44;
    else if(opcodeString=="WIND") return 0x45;
    else if(opcodeString=="OSAGE_STEP") return 0x46;
    else if(opcodeString=="OSAGE_MV_CCL") return 0x47;
    else if(opcodeString=="CHARA_COLOR") return 0x48;
    else if(opcodeString=="SE_EFFECT") return 0x49;
    else if(opcodeString=="EDIT_MOVE_XYZ") return 0x4A;
    else if(opcodeString=="EDIT_EYELID_ANIM") return 0x4B;
    else if(opcodeString=="EDIT_INSTRUMENT_ITEM") return 0x4C;
    else if(opcodeString=="EDIT_MOTION_LOOP") return 0x4D;
    else if(opcodeString=="EDIT_EXPRESSION") return 0x4E;
    else if(opcodeString=="EDIT_EYE_ANIM") return 0x4F;
    else if(opcodeString=="EDIT_MOUTH_ANIM") return 0x50;
    else if(opcodeString=="EDIT_CAMERA") return 0x51;
    else if(opcodeString=="EDIT_MODE_SELECT") return 0x52;
    else if(opcodeString=="PV_END_FADEOUT") return 0x53;
    else return -1;
}

QString DivaScriptOpcode_Mirai::getOpcodeString(int opcodeNumber)
{
    switch(opcodeNumber)
    {
        case 0x00: return "END";
        case 0x01: return "TIME";
        case 0x02: return "MIKU_MOVE";
        case 0x03: return "MIKU_ROT";
        case 0x04: return "MIKU_DISP";
        case 0x05: return "MIKU_SHADOW";
        case 0x06: return "TARGET";
        case 0x07: return "SET_MOTION";
        case 0x08: return "SET_PLAYDATA";
        case 0x09: return "EFFECT";
        case 0x0A: return "FADEIN_FIELD";
        case 0x0B: return "EFFECT_OFF";
        case 0x0C: return "SET_CAMERA";
        case 0x0D: return "DATA_CAMERA";
        case 0x0E: return "CHANGE_FIELD";
        case 0x0F: return "HIDE_FIELD";
        case 0x10: return "MOVE_FIELD";
        case 0x11: return "FADEOUT_FIELD";
        case 0x12: return "EYE_ANIM";
        case 0x13: return "MOUTH_ANIM";
        case 0x14: return "HAND_ANIM";
        case 0x15: return "LOOK_ANIM";
        case 0x16: return "EXPRESSION";
        case 0x17: return "LOOK_CAMERA";
        case 0x18: return "LYRIC";
        case 0x19: return "MUSIC_PLAY";
        case 0x1A: return "MODE_SELECT";
        case 0x1B: return "EDIT_MOTION";
        case 0x1C: return "BAR_TIME_SET";
        case 0x1D: return "SHADOWHEIGHT";
        case 0x1E: return "EDIT_FACE";
        case 0x1F: return "MOVE_CAMERA";
        case 0x20: return "PV_END";
        case 0x21: return "SHADOWPOS";
        case 0x22: return "EDIT_LYRIC";
        case 0x23: return "EDIT_TARGET";
        case 0x24: return "EDIT_MOUTH";
        case 0x25: return "SET_CHARA";
        case 0x26: return "EDIT_MOVE";
        case 0x27: return "EDIT_SHADOW";
        case 0x28: return "EDIT_EYELID";
        case 0x29: return "EDIT_EYE";
        case 0x2A: return "EDIT_ITEM";
        case 0x2B: return "EDIT_EFFECT";
        case 0x2C: return "EDIT_DISP";
        case 0x2D: return "EDIT_HAND_ANIM";
        case 0x2E: return "AIM";
        case 0x2F: return "HAND_ITEM";
        case 0x30: return "EDIT_BLUSH";
        case 0x31: return "NEAR_CLIP";
        case 0x32: return "CLOTH_WET";
        case 0x33: return "LIGHT_ROT";
        case 0x34: return "SCENE_FADE";
        case 0x35: return "TONE_TRANS";
        case 0x36: return "SATURATE";
        case 0x37: return "FADE_MODE";
        case 0x38: return "AUTO_BLINK";
        case 0x39: return "PARTS_DISP";
        case 0x3A: return "TARGET_FLYING_TIME";
        case 0x3B: return "CHARA_SIZE";
        case 0x3C: return "CHARA_HEIGHT_ADJUST";
        case 0x3D: return "ITEM_ANIM";
        case 0x3E: return "CHARA_POS_ADJUST";
        case 0x3F: return "SCENE_ROT";
        case 0x40: return "EDIT_MOT_SMOOTH_LEN";
        case 0x41: return "PV_BRANCH_MODE";
        case 0x42: return "DATA_CAMERA_START";
        case 0x43: return "MOVIE_PLAY";
        case 0x44: return "MOVIE_DISP";
        case 0x45: return "WIND";
        case 0x46: return "OSAGE_STEP";
        case 0x47: return "OSAGE_MV_CCL";
        case 0x48: return "CHARA_COLOR";
        case 0x49: return "SE_EFFECT";
        case 0x4A: return "EDIT_MOVE_XYZ";
        case 0x4B: return "EDIT_EYELID_ANIM";
        case 0x4C: return "EDIT_INSTRUMENT_ITEM";
        case 0x4D: return "EDIT_MOTION_LOOP";
        case 0x4E: return "EDIT_EXPRESSION";
        case 0x4F: return "EDIT_EYE_ANIM";
        case 0x50: return "EDIT_MOUTH_ANIM";
        case 0x51: return "EDIT_CAMERA";
        case 0x52: return "EDIT_MODE_SELECT";
        case 0x53: return "PV_END_FADEOUT";
        default:
        QString opcode="UNKNOWN_OPCODE_0x"+QString::number(opcodeNumber, 16);
        QMessageBox::warning(nullptr, "Warning", opcode);
        return opcode;
    }
}

int DivaScriptOpcode_Mirai::getOpcodeParamCount(int opcodeNumber)
{
    switch(opcodeNumber)
    {
        case 0x00: return 0;
        case 0x01: return 1;
        case 0x02: return 4;
        case 0x03: return 2;
        case 0x04: return 2;
        case 0x05: return 2;
        case 0x06: return 7;
        case 0x07: return 4;
        case 0x08: return 2;
        case 0x09: return 6;
        case 0x0A: return 2;
        case 0x0B: return 1;
        case 0x0C: return 6;
        case 0x0D: return 2;
        case 0x0E: return 2;
        case 0x0F: return 1;
        case 0x10: return 3;
        case 0x11: return 2;
        case 0x12: return 3;
        case 0x13: return 5;
        case 0x14: return 5;
        case 0x15: return 4;
        case 0x16: return 4;
        case 0x17: return 5;
        case 0x18: return 2;
        case 0x19: return 0;
        case 0x1A: return 2;
        case 0x1B: return 4;
        case 0x1C: return 2;
        case 0x1D: return 2;
        case 0x1E: return 1;
        case 0x1F: return 21;
        case 0x20: return 0;
        case 0x21: return 3;
        case 0x22: return 2;
        case 0x23: return 5;
        case 0x24: return 1;
        case 0x25: return 1;
        case 0x26: return 7;
        case 0x27: return 1;
        case 0x28: return 1;
        case 0x29: return 2;
        case 0x2A: return 1;
        case 0x2B: return 2;
        case 0x2C: return 1;
        case 0x2D: return 2;
        case 0x2E: return 3;
        case 0x2F: return 3;
        case 0x30: return 1;
        case 0x31: return 2;
        case 0x32: return 2;
        case 0x33: return 3;
        case 0x34: return 6;
        case 0x35: return 6;
        case 0x36: return 1;
        case 0x37: return 1;
        case 0x38: return 2;
        case 0x39: return 3;
        case 0x3A: return 1;
        case 0x3B: return 2;
        case 0x3C: return 2;
        case 0x3D: return 4;
        case 0x3E: return 4;
        case 0x3F: return 1;
        case 0x40: return 2;
        case 0x41: return 1;
        case 0x42: return 2;
        case 0x43: return 1;
        case 0x44: return 1;
        case 0x45: return 3;
        case 0x46: return 3;
        case 0x47: return 3;
        case 0x48: return 2;
        case 0x49: return 1;
        case 0x4A: return 9;
        case 0x4B: return 3;
        case 0x4C: return 2;
        case 0x4D: return 4;
        case 0x4E: return 2;
        case 0x4F: return 3;
        case 0x50: return 2;
        case 0x51: return 23;
        case 0x52: return 1;
        case 0x53: return 2;
        default: return -1;
    }
}

void DivaScriptOpcode_Mirai::readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode)
{
    datastream.setByteOrder(uibyteorder);
    datastream.skipRawData(4);
    textedit->clear();
    textedit->setUndoRedoEnabled(false);
    textedit->setUpdatesEnabled(false);
    textedit->blockSignals(true);
    while(!(file.atEnd()))
    {
        int opc;
        datastream >> opc;
        QString ops = getOpcodeString(opc);
        if(!testmode) textedit->insertPlainText(ops+"(");
        for(int i=0; i<getOpcodeParamCount(opc); i++)
        {
            int byte;
            datastream >> byte;
            if(!testmode)
            {
                if(i) textedit->insertPlainText(", ");
                textedit->insertPlainText(QString::number(byte));
            }
        }
        if(!testmode) textedit->insertPlainText(");\n");
    }
    textedit->blockSignals(false);
    textedit->setUndoRedoEnabled(true);
    textedit->setUpdatesEnabled(true);
    editWidgets.tabedit->setEnabled(false);
}

void DivaScriptOpcode_Mirai::writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder)
{
    datastream.setByteOrder(QDataStream::ByteOrder::LittleEndian);
    datastream << 302121504;
    datastream.setByteOrder(uibyteorder);
    QString line;
    QStringList commandlist;
    commandlist=textedit->document()->toPlainText().split(';', Qt::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
    for(int i=0; i<commandlist.length(); i++)
    {
        QStringList splitcommand=commandlist.at(i).split('(', Qt::SkipEmptyParts);
        if(!splitcommand.length()) continue;
        int opcode=getOpcodeNumber(splitcommand.at(0));
        datastream << opcode;
        QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', Qt::SkipEmptyParts);
        int expcount=getOpcodeParamCount(opcode);
        if(!(splitparams.length()==expcount))
        {
            logger("E: Parameter count mismatch for opcode 0x"+QString::number(opcode, 16). toUpper()+" AKA "+splitcommand.at(0)+"\nExpected: "+QString::number(expcount)+"\nGot: "+QString::number(splitparams.length()));
            file.close();
            return;
        }
        for(int j=0; j<splitparams.length(); j++)
            datastream << splitparams.at(j).toInt();
    }
}

DivaScriptOpcode* formatSelection(int dscfmt, QTextEdit* logEdit)
{
    debugger("DSC format: "+QString::number(dscfmt));

    switch(dscfmt)
    {
        case 0: return new DivaScriptOpcode_DIVA(logEdit);
        case 1: return new DivaScriptOpcode_DIVA2(logEdit);
        case 2: return new DivaScriptOpcode_DIVA2Edit(logEdit);
        case 3: return new DivaScriptOpcode_PDA(logEdit);
        case 4: return new DivaScriptOpcode_FT(logEdit);
        case 5: return new DivaScriptOpcode_F(logEdit);
        case 6: return new DivaScriptOpcode_F2(logEdit);
        case 7: return new DivaScriptOpcode_X(logEdit);
        case 8: return new DivaScriptOpcode_Mirai(logEdit);
        default: return new DivaScriptOpcode(logEdit);
    }
}

void mergeDsc(QStringList &mergelist, QPlainTextEdit *dest, QPlainTextEdit *import, bool &isLoading, QTextEdit *logEdit)
{
#define IMPORT_NODEFAULT time_branch_import[0]<0
#define IMPORT_NOFAIL time_branch_import[1]<0
#define IMPORT_NOSUCCESS time_branch_import[2]<0
#define DEST_NODEFAULT time_branch_dest[0]<0
#define DEST_NOFAIL time_branch_dest[1]<0
#define DEST_NOSUCCESS time_branch_dest[2]<0

    QStringList commandList_import = import->document()->toPlainText().split('\n');
    QStringList commandList_dest = dest->document()->toPlainText().split('\n');

    for(int i=0; i<commandList_import.length(); i++)
    {
        // Get input command
        QString cmd_import = commandList_import.at(i).simplified();

        // Skip PV_END, END, PV_BRANCH_MODE, TIME, etc
        QStringList cmd_import_split = cmd_import.split('(');
        if(cmd_import_split.length()<1) continue;
        if(cmd_import.isEmpty()||!mergelist.contains(cmd_import_split.at(0))) continue; // TODO substr??

        // Input time
        int time_in = getTimeFromTimeCommand(commandList_import.at(findTimeOfCommand(commandList_import, i)));
        if(time_in<0) continue;

        // Input branch
        int branch_in = findBranchOfCommand(commandList_import, i);
        if(branch_in<0) branch_in = 0;

        // Insert command
        insertCommand(commandList_dest, time_in, cmd_import, branch_in, ";");
    }

    isLoading = true;
    dest->clear();
    for(int i=0; i<commandList_dest.length(); i++)
        dest->appendPlainText(commandList_dest.at(i).simplified());
    isLoading = false;

    // TODO fix branch, end, etc
    // time should be relative to branch
    // multiple branch commands
    // TIME, then PV_BRANCH_MODE
    // PV_BRANCH_MODE(0), then PV_END, then END
}
