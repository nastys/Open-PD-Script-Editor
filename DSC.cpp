#include <QString>
#include <QFile>
#include <QPlainTextEdit>
#include <QTableWidget>
#include <QDataStream>
#include <QTextCodec>
#include <QDebug>
#include "mainwindow.h"

class DivaScriptOpcode_F
{
public:
    static int getOpcodeNumber(QString opcodeString)
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
    static QString getOpcodeString(int opcodeNumber)
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
            default: return "UNKNOWN_OPCODE_0x"+QString::number(opcodeNumber, 16);
        }
    }
    static int getOpcodeParamCount(int opcodeNumber)
    {
        switch(opcodeNumber)
        {
            case 0x00: return 0;
            case 0x01: return 1;
            case 0x02: return 4;
            case 0x03: return 2;
            case 0x04: return 2;
            case 0x05: return 2;
            case 0x06: return 11;
            case 0x07: return 4;
            case 0x08: return 2;
            case 0x09: return 6;
            case 0x0A: return 2;
            case 0x0B: return 1;
            case 0x0C: return 6;
            case 0x0D: return 2;
            case 0x0E: return 1;
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
            case 0x51: return 24;
            case 0x52: return 1;
            case 0x53: return 2;
            default: return -1;
        }
    }
    static void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        datastream.skipRawData(4);
        plaintextedit->clear();
        while(!(file.atEnd()))
        {
            int opc;
            datastream >> opc;
            plaintextedit->appendPlainText(getOpcodeString(opc)+"(");
            for(int i=0; i<getOpcodeParamCount(opc); i++)
            {
                if(i) plaintextedit->insertPlainText(", ");
                int byte;
                datastream >> byte;
                plaintextedit->insertPlainText(QString::number(byte));
            }
            plaintextedit->insertPlainText(");");
        }

        editWidgets.tabedit->setEnabled(false);
    }
    static void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        datastream << 302121504;
        QString line;
        QStringList commandlist;
        commandlist=plaintextedit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
        for(int i=0; i<commandlist.length(); i++)
        {
            QStringList splitcommand=commandlist.at(i).split('(', QString::SkipEmptyParts);
            int opcode=getOpcodeNumber(splitcommand.at(0));
            datastream << opcode;
            QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', QString::SkipEmptyParts);
            int expcount=getOpcodeParamCount(opcode);
            if(!(splitparams.length()==expcount))
            {
                qDebug() << "E: Parameter count mismatch for opcode" << "0x"+QString::number(opcode, 16).toUpper() << "AKA" << splitcommand.at(0) << endl << "Expected:" << expcount << endl << "Got:" << splitparams.length();
                file.close();
                return;
            }
            for(int j=0; j<splitparams.length(); j++)
                datastream << splitparams.at(j).toInt();
        }
    }
};

class DivaScriptOpcode_F2
{
public:
    static int getOpcodeNumber(QString opcodeString)
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
        else if(opcodeString=="RESERVE0") return 0x54;
        else if(opcodeString=="RESERVE1") return 0x55;
        else if(opcodeString=="RESERVE2") return 0x56;
        else if(opcodeString=="RESERVE3") return 0x57;
        else if(opcodeString=="PV_AUTH_LIGHT_PRIORITY") return 0x58;
        else if(opcodeString=="PV_CHARA_LIGHT") return 0x59;
        else if(opcodeString=="PV_STAGE_LIGHT") return 0x5A;
        else if(opcodeString=="TARGET_EFFECT") return 0x5B;
        else if(opcodeString=="FOG") return 0x5C;
        else if(opcodeString=="BLOOM") return 0x5D;
        else if(opcodeString=="COLOR_CORRECTION") return 0x5E;
        else if(opcodeString=="DOF") return 0x5F;
        else if(opcodeString=="CHARA_ALPHA") return 0x60;
        else if(opcodeString=="AUTO_CAPTURE_BEGIN") return 0x61;
        else if(opcodeString=="MANUAL_CAPTURE") return 0x62;
        else if(opcodeString=="TOON_EDGE") return 0x63;
        else if(opcodeString=="SHIMMER") return 0x64;
        else if(opcodeString=="ITEM_ALPHA") return 0x65;
        else if(opcodeString=="MOVIE_CUT") return 0x66;
        else if(opcodeString=="EDIT_CAMERA_BOX") return 0x67;
        else if(opcodeString=="EDIT_STAGE_PARAM") return 0x68;
        else if(opcodeString=="EDIT_CHANGE_FIELD") return 0x69;
        else return -1;
    }
    static QString getOpcodeString(int opcodeNumber)
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
            case 0x54: return "RESERVE0";
            case 0x55: return "RESERVE1";
            case 0x56: return "RESERVE2";
            case 0x57: return "RESERVE3";
            case 0x58: return "PV_AUTH_LIGHT_PRIORITY";
            case 0x59: return "PV_CHARA_LIGHT";
            case 0x5A: return "PV_STAGE_LIGHT";
            case 0x5B: return "TARGET_EFFECT";
            case 0x5C: return "FOG";
            case 0x5D: return "BLOOM";
            case 0x5E: return "COLOR_CORRECTION";
            case 0x5F: return "DOF";
            case 0x60: return "CHARA_ALPHA";
            case 0x61: return "AUTO_CAPTURE_BEGIN";
            case 0x62: return "MANUAL_CAPTURE";
            case 0x63: return "TOON_EDGE";
            case 0x64: return "SHIMMER";
            case 0x65: return "ITEM_ALPHA";
            case 0x66: return "MOVIE_CUT";
            case 0x67: return "EDIT_CAMERA_BOX";
            case 0x68: return "EDIT_STAGE_PARAM";
            case 0x69: return "EDIT_CHANGE_FIELD";
            default: return "UNKNOWN_OPCODE_0x"+QString::number(opcodeNumber, 16);
        }
    }
    static int getOpcodeParamCount(int opcodeNumber)
    {
        switch(opcodeNumber)
        {
            case 0x00: return 0;
            case 0x01: return 1;
            case 0x02: return 4;
            case 0x03: return 2;
            case 0x04: return 2;
            case 0x05: return 2;
            case 0x06: return 12;
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
            case 0x51: return 22;
            case 0x52: return 1;
            case 0x53: return 2;
            case 0x54: return 1;
            case 0x55: return 6;
            case 0x56: return 1;
            case 0x57: return 9;
            case 0x58: return 2;
            case 0x59: return 3;
            case 0x5A: return 3;
            case 0x5B: return 11;
            case 0x5C: return 3;
            case 0x5D: return 2;
            case 0x5E: return 3;
            case 0x5F: return 3;
            case 0x60: return 4;
            case 0x61: return 1;
            case 0x62: return 1;
            case 0x63: return 3;
            case 0x64: return 3;
            case 0x65: return 4;
            case 0x66: return 1;
            case 0x67: return 112;
            case 0x68: return 1;
            case 0x69: return 1;
            default: return -1;
        }
    }
    static void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        datastream.skipRawData(72);
        plaintextedit->clear();
        while(!(file.atEnd()))
        {
            int opc;
            datastream >> opc;
            if((uibyteorder==QDataStream::LittleEndian&&opc==1128681285)||(uibyteorder==QDataStream::BigEndian&&opc==1162823235)) break; // "EOFC"
            plaintextedit->appendPlainText(getOpcodeString(opc)+"(");
            for(int i=0; i<getOpcodeParamCount(opc); i++)
            {
                if(i) plaintextedit->insertPlainText(", ");
                int byte;
                datastream >> byte;
                plaintextedit->insertPlainText(QString::number(byte));
            }
            plaintextedit->insertPlainText(");");
        }

        editWidgets.tabedit->setEnabled(false);
    }
    static void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(QDataStream::ByteOrder::LittleEndian);
        datastream << 1129535056 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
        datastream.setByteOrder(uibyteorder);
        QString line;
        QStringList commandlist;
        commandlist=plaintextedit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
        for(int i=0; i<commandlist.length(); i++)
        {
            QStringList splitcommand=commandlist.at(i).split('(', QString::SkipEmptyParts);
            int opcode=getOpcodeNumber(splitcommand.at(0));
            datastream << opcode;
            QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', QString::SkipEmptyParts);
            int expcount=getOpcodeParamCount(opcode);
            if(!(splitparams.length()==expcount))
            {
                qDebug() << "E: Parameter count mismatch for opcode" << "0x"+QString::number(opcode, 16).toUpper() << "AKA" << splitcommand.at(0) << endl << "Expected:" << expcount << endl << "Got:" << splitparams.length();
                file.close();
                return;
            }
            for(int j=0; j<splitparams.length(); j++)
                datastream << splitparams.at(j).toInt();
        }
        datastream.setByteOrder(QDataStream::ByteOrder::LittleEndian);
        datastream << 1128681285 << 0 << 0 << 0 << 0 << 0 << 0;
        int size=(int)(file.size())-92;
        file.seek(4);
        datastream << size;
        file.seek(20);
        datastream << size;
    }
};

class DivaScriptOpcode_MGF
{
public:
    static int getOpcodeNumber(QString opcodeString)
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
        else if(opcodeString=="RESERVE") return 0x54;
        else if(opcodeString=="PV_AUTH_LIGHT_PRIORITY") return 0x55;
        else if(opcodeString=="PV_CHARA_LIGHT") return 0x56;
        else if(opcodeString=="PV_STAGE_LIGHT") return 0x57;
        else if(opcodeString=="TARGET_EFFECT") return 0x58;
        else if(opcodeString=="FOG") return 0x59;
        else if(opcodeString=="BLOOM") return 0x5A;
        else if(opcodeString=="COLOR_CORRECTION") return 0x5B;
        else if(opcodeString=="DOF") return 0x5C;
        else if(opcodeString=="CHARA_ALPHA") return 0x5D;
        else if(opcodeString=="AUTO_CAPTURE_BEGIN") return 0x5E;
        else if(opcodeString=="MANUAL_CAPTURE") return 0x5F;
        else if(opcodeString=="TOON_EDGE") return 0x60;
        else if(opcodeString=="SHIMMER") return 0x61;
        else if(opcodeString=="ITEM_ALPHA") return 0x62;
        else if(opcodeString=="MOVIE_CUT") return 0x63;
        else if(opcodeString=="CROSSFADE") return 0x64;
        else if(opcodeString=="SUBFRAMERENDER") return 0x65;
        else if(opcodeString=="EVENT_JUDGE") return 0x66;
        else if(opcodeString=="TOON__EDGE") return 0x67;
        else if(opcodeString=="FOG_ENABLE") return 0x68;
        else if(opcodeString=="EDIT_CAMERA_BOX_") return 0x69;
        else if(opcodeString=="EDIT_STAGE_PARAM") return 0x6A;
        else return -1;
    }
    static QString getOpcodeString(int opcodeNumber)
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
            case 0x54: return "RESERVE";
            case 0x55: return "PV_AUTH_LIGHT_PRIORITY";
            case 0x56: return "PV_CHARA_LIGHT";
            case 0x57: return "PV_STAGE_LIGHT";
            case 0x58: return "TARGET_EFFECT";
            case 0x59: return "FOG";
            case 0x5A: return "BLOOM";
            case 0x5B: return "COLOR_CORRECTION";
            case 0x5C: return "DOF";
            case 0x5D: return "CHARA_ALPHA";
            case 0x5E: return "AUTO_CAPTURE_BEGIN";
            case 0x5F: return "MANUAL_CAPTURE";
            case 0x60: return "TOON_EDGE";
            case 0x61: return "SHIMMER";
            case 0x62: return "ITEM_ALPHA";
            case 0x63: return "MOVIE_CUT";
            case 0x64: return "CROSSFADE";
            case 0x65: return "SUBFRAMERENDER";
            case 0x66: return "EVENT_JUDGE";
            case 0x67: return "TOON__EDGE";
            case 0x68: return "FOG_ENABLE";
            case 0x69: return "EDIT_CAMERA_BOX_";
            case 0x6A: return "EDIT_STAGE_PARAM";
            default: return "UNKNOWN_OPCODE_0x"+QString::number(opcodeNumber, 16);
        }
    }
    static int getOpcodeParamCount(int opcodeNumber)
    {
        switch(opcodeNumber)
        {
            case 0x00: return 0;
            case 0x01: return 1;
            case 0x02: return 4;
            case 0x03: return 2;
            case 0x04: return 2;
            case 0x05: return 2;
            case 0x06: return 12;
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
            case 0x54: return 9;
            case 0x55: return 2;
            case 0x56: return 3;
            case 0x57: return 3;
            case 0x58: return 11;
            case 0x59: return 3;
            case 0x5A: return 2;
            case 0x5B: return 3;
            case 0x5C: return 3;
            case 0x5D: return 4;
            case 0x5E: return 1;
            case 0x5F: return 1;
            case 0x60: return 3;
            case 0x61: return 3;
            case 0x62: return 4;
            case 0x63: return 1;
            case 0x64: return 3;
            case 0x65: return 1;
            case 0x66: return 1;
            case 0x67: return 1;
            case 0x68: return 1;
            case 0x69: return 36;
            case 0x6A: return 2;
            default: return -1;
        }
    }
    static void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        datastream.skipRawData(72);
        plaintextedit->clear();
        while(!(file.atEnd()))
        {
            int opc;
            datastream >> opc;
            if((uibyteorder==QDataStream::LittleEndian&&opc==1128681285)||(uibyteorder==QDataStream::BigEndian&&opc==1162823235)) break; // "EOFC"
            plaintextedit->appendPlainText(getOpcodeString(opc)+"(");
            for(int i=0; i<getOpcodeParamCount(opc); i++)
            {
                if(i) plaintextedit->insertPlainText(", ");
                int byte;
                datastream >> byte;
                plaintextedit->insertPlainText(QString::number(byte));
            }
            plaintextedit->insertPlainText(");");
        }

        editWidgets.tabedit->setEnabled(false);
    }
    static void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(QDataStream::ByteOrder::LittleEndian);
        datastream << 1129535056 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
        datastream.setByteOrder(uibyteorder);
        QString line;
        QStringList commandlist;
        commandlist=plaintextedit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
        for(int i=0; i<commandlist.length(); i++)
        {
            QStringList splitcommand=commandlist.at(i).split('(', QString::SkipEmptyParts);
            int opcode=getOpcodeNumber(splitcommand.at(0));
            datastream << opcode;
            QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', QString::SkipEmptyParts);
            int expcount=getOpcodeParamCount(opcode);
            if(!(splitparams.length()==expcount))
            {
                qDebug() << "E: Parameter count mismatch for opcode" << "0x"+QString::number(opcode, 16).toUpper() << "AKA" << splitcommand.at(0) << endl << "Expected:" << expcount << endl << "Got:" << splitparams.length();
                file.close();
                return;
            }
            for(int j=0; j<splitparams.length(); j++)
                datastream << splitparams.at(j).toInt();
        }
        datastream.setByteOrder(QDataStream::ByteOrder::LittleEndian);
        datastream << 1128681285 << 0 << 0 << 0 << 0 << 0 << 0;
    }
};

class DivaScriptOpcode_X
{
public:
    static int getOpcodeNumber(QString opcodeString)
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
        else if(opcodeString=="DUMMY") return 0x1F;
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
        else if(opcodeString=="CHARA_SHADOW_QUALITY") return 0x4A;
        else if(opcodeString=="STAGE_SHADOW_QUALITY") return 0x4B;
        else if(opcodeString=="COMMON_LIGHT") return 0x4C;
        else if(opcodeString=="TONE_MAP") return 0x4D;
        else if(opcodeString=="IBL_COLOR") return 0x4E;
        else if(opcodeString=="REFLECTION") return 0x4F;
        else if(opcodeString=="CHROMATIC_ABERRATION") return 0x50;
        else if(opcodeString=="STAGE_SHADOW") return 0x51;
        else if(opcodeString=="REFLECTION_QUALITY") return 0x52;
        else if(opcodeString=="PV_END_FADEOUT") return 0x53;
        else if(opcodeString=="CREDIT_TITLE") return 0x54;
        else if(opcodeString=="BAR_POINT") return 0x55;
        else if(opcodeString=="BEAT_POINT") return 0x56;
        else if(opcodeString=="RESERVE") return 0x57;
        else if(opcodeString=="PV_AUTH_LIGHT_PRIORITY") return 0x58;
        else if(opcodeString=="PV_CHARA_LIGHT") return 0x59;
        else if(opcodeString=="PV_STAGE_LIGHT") return 0x5A;
        else if(opcodeString=="TARGET_EFFECT") return 0x5B;
        else if(opcodeString=="FOG") return 0x5C;
        else if(opcodeString=="BLOOM") return 0x5D;
        else if(opcodeString=="COLOR_CORRECTION") return 0x5E;
        else if(opcodeString=="DOF") return 0x5F;
        else if(opcodeString=="CHARA_ALPHA") return 0x60;
        else if(opcodeString=="AUTO_CAPTURE_BEGIN") return 0x61;
        else if(opcodeString=="MANUAL_CAPTURE") return 0x62;
        else if(opcodeString=="TOON_EDGE") return 0x63;
        else if(opcodeString=="SHIMMER") return 0x64;
        else if(opcodeString=="ITEM_ALPHA") return 0x65;
        else if(opcodeString=="MOVIE_CUT") return 0x66;
        else if(opcodeString=="EDIT_CAMERA_BOX") return 0x67;
        else if(opcodeString=="EDIT_STAGE_PARAM") return 0x68;
        else if(opcodeString=="EDIT_CHANGE_FIELD") return 0x69;
        else if(opcodeString=="MIKUDAYO_ADJUST") return 0x6A;
        else if(opcodeString=="LYRIC_2") return 0x6B;
        else if(opcodeString=="LYRIC_READ") return 0x6C;
        else if(opcodeString=="LYRIC_READ_2") return 0x6D;
        else if(opcodeString=="ANNOTATION") return 0x6E;
        else if(opcodeString=="STAGE_EFFECT") return 0x6F;
        else if(opcodeString=="SONG_EFFECT") return 0x70;
        else if(opcodeString=="SONG_EFFECT_ATTACH") return 0x71;
        else if(opcodeString=="LIGHT_AUTH") return 0x72;
        else if(opcodeString=="FADE") return 0x73;
        else if(opcodeString=="SET_STAGE_EFFECT_ENV") return 0x74;
        else if(opcodeString=="COMMON_EFFECT_AET_FRONT") return 0x75;
        else if(opcodeString=="COMMON_EFFECT_AET_FRONT_LOW") return 0x76;
        else if(opcodeString=="COMMON_EFFECT_PARTICLE") return 0x77;
        else if(opcodeString=="SONG_EFFECT_ALPHA_SORT") return 0x78;
        else if(opcodeString=="LOOK_CAMERA_FACE_LIMIT") return 0x79;
        else if(opcodeString=="ITEM_LIGHT") return 0x7A;
        else if(opcodeString=="CHARA_EFFECT") return 0x7B;
        else if(opcodeString=="MARKER") return 0x7C;
        else if(opcodeString=="CHARA_EFFECT_CHARA_LIGHT") return 0x7D;
        else if(opcodeString=="ENABLE_COMMON_LIGHT_TO_CHARA") return 0x7E;
        else if(opcodeString=="ENABLE_FXAA") return 0x7F;
        else if(opcodeString=="ENABLE_TEMPORAL_AA") return 0x80;
        else if(opcodeString=="ENABLE_REFLECTION") return 0x81;
        else if(opcodeString=="BANK_BRANCH") return 0x82;
        else if(opcodeString=="BANK_END") return 0x83;
        else if(opcodeString=="VR_LIVE_MOVIE") return 0x84;
        else if(opcodeString=="VR_CHEER") return 0x85;
        else if(opcodeString=="VR_CHARA_PSMOVE") return 0x86;
        else if(opcodeString=="VR_MOVE_PATH") return 0x87;
        else if(opcodeString=="VR_SET_BASE") return 0x88;
        else if(opcodeString=="VR_TECH_DEMO_EFFECT") return 0x89;
        else if(opcodeString=="VR_TRANSFORM") return 0x8A;
        else if(opcodeString=="GAZE") return 0x8B;
        else if(opcodeString=="TECH_DEMO_GESUTRE") return 0x8C;
        else if(opcodeString=="VR_CHEMICAL_LIGHT_COLOR") return 0x8D;
        else if(opcodeString=="VR_LIVE_MOB") return 0x8E;
        else if(opcodeString=="VR_LIVE_HAIR_OSAGE") return 0x8F;
        else if(opcodeString=="VR_LIVE_LOOK_CAMERA") return 0x90;
        else if(opcodeString=="VR_LIVE_CHEER") return 0x91;
        else if(opcodeString=="VR_LIVE_GESTURE") return 0x92;
        else if(opcodeString=="VR_LIVE_CLONE") return 0x93;
        else if(opcodeString=="VR_LOOP_EFFECT") return 0x94;
        else if(opcodeString=="VR_LIVE_ONESHOT_EFFECT") return 0x95;
        else if(opcodeString=="VR_LIVE_PRESENT") return 0x96;
        else if(opcodeString=="VR_LIVE_TRANSFORM") return 0x97;
        else if(opcodeString=="VR_LIVE_FLY") return 0x98;
        else if(opcodeString=="VR_LIVE_CHARA_VOICE") return 0x99;
        else return -1;
    }
    static QString getOpcodeString(int opcodeNumber)
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
            case 0x1F: return "DUMMY";
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
            case 0x4A: return "CHARA_SHADOW_QUALITY";
            case 0x4B: return "STAGE_SHADOW_QUALITY";
            case 0x4C: return "COMMON_LIGHT";
            case 0x4D: return "TONE_MAP";
            case 0x4E: return "IBL_COLOR";
            case 0x4F: return "REFLECTION";
            case 0x50: return "CHROMATIC_ABERRATION";
            case 0x51: return "STAGE_SHADOW";
            case 0x52: return "REFLECTION_QUALITY";
            case 0x53: return "PV_END_FADEOUT";
            case 0x54: return "CREDIT_TITLE";
            case 0x55: return "BAR_POINT";
            case 0x56: return "BEAT_POINT";
            case 0x57: return "RESERVE";
            case 0x58: return "PV_AUTH_LIGHT_PRIORITY";
            case 0x59: return "PV_CHARA_LIGHT";
            case 0x5A: return "PV_STAGE_LIGHT";
            case 0x5B: return "TARGET_EFFECT";
            case 0x5C: return "FOG";
            case 0x5D: return "BLOOM";
            case 0x5E: return "COLOR_CORRECTION";
            case 0x5F: return "DOF";
            case 0x60: return "CHARA_ALPHA";
            case 0x61: return "AUTO_CAPTURE_BEGIN";
            case 0x62: return "MANUAL_CAPTURE";
            case 0x63: return "TOON_EDGE";
            case 0x64: return "SHIMMER";
            case 0x65: return "ITEM_ALPHA";
            case 0x66: return "MOVIE_CUT";
            case 0x67: return "EDIT_CAMERA_BOX";
            case 0x68: return "EDIT_STAGE_PARAM";
            case 0x69: return "EDIT_CHANGE_FIELD";
            case 0x6A: return "MIKUDAYO_ADJUST";
            case 0x6B: return "LYRIC_2";
            case 0x6C: return "LYRIC_READ";
            case 0x6D: return "LYRIC_READ_2";
            case 0x6E: return "ANNOTATION";
            case 0x6F: return "STAGE_EFFECT";
            case 0x70: return "SONG_EFFECT";
            case 0x71: return "SONG_EFFECT_ATTACH";
            case 0x72: return "LIGHT_AUTH";
            case 0x73: return "FADE";
            case 0x74: return "SET_STAGE_EFFECT_ENV";
            case 0x75: return "COMMON_EFFECT_AET_FRONT";
            case 0x76: return "COMMON_EFFECT_AET_FRONT_LOW";
            case 0x77: return "COMMON_EFFECT_PARTICLE";
            case 0x78: return "SONG_EFFECT_ALPHA_SORT";
            case 0x79: return "LOOK_CAMERA_FACE_LIMIT";
            case 0x7A: return "ITEM_LIGHT";
            case 0x7B: return "CHARA_EFFECT";
            case 0x7C: return "MARKER";
            case 0x7D: return "CHARA_EFFECT_CHARA_LIGHT";
            case 0x7E: return "ENABLE_COMMON_LIGHT_TO_CHARA";
            case 0x7F: return "ENABLE_FXAA";
            case 0x80: return "ENABLE_TEMPORAL_AA";
            case 0x81: return "ENABLE_REFLECTION";
            case 0x82: return "BANK_BRANCH";
            case 0x83: return "BANK_END";
            case 0x84: return "VR_LIVE_MOVIE";
            case 0x85: return "VR_CHEER";
            case 0x86: return "VR_CHARA_PSMOVE";
            case 0x87: return "VR_MOVE_PATH";
            case 0x88: return "VR_SET_BASE";
            case 0x89: return "VR_TECH_DEMO_EFFECT";
            case 0x8A: return "VR_TRANSFORM";
            case 0x8B: return "GAZE";
            case 0x8C: return "TECH_DEMO_GESUTRE";
            case 0x8D: return "VR_CHEMICAL_LIGHT_COLOR";
            case 0x8E: return "VR_LIVE_MOB";
            case 0x8F: return "VR_LIVE_HAIR_OSAGE";
            case 0x90: return "VR_LIVE_LOOK_CAMERA";
            case 0x91: return "VR_LIVE_CHEER";
            case 0x92: return "VR_LIVE_GESTURE";
            case 0x93: return "VR_LIVE_CLONE";
            case 0x94: return "VR_LOOP_EFFECT";
            case 0x95: return "VR_LIVE_ONESHOT_EFFECT";
            case 0x96: return "VR_LIVE_PRESENT";
            case 0x97: return "VR_LIVE_TRANSFORM";
            case 0x98: return "VR_LIVE_FLY";
            case 0x99: return "VR_LIVE_CHARA_VOICE";
            default: return "UNKNOWN_OPCODE_0x"+QString::number(opcodeNumber, 16);
        }
    }
    static int getOpcodeParamCount(int opcodeNumber)
    {
        switch(opcodeNumber)
        {
            case 0x00: return 0;
            case 0x01: return 1;
            case 0x02: return 4;
            case 0x03: return 2;
            case 0x04: return 2;
            case 0x05: return 2;
            case 0x06: return 12;
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
            case 0x4A: return 2;
            case 0x4B: return 2;
            case 0x4C: return 2;
            case 0x4D: return 2;
            case 0x4E: return 2;
            case 0x4F: return 2;
            case 0x50: return 3;
            case 0x51: return 2;
            case 0x52: return 2;
            case 0x53: return 2;
            case 0x54: return 1;
            case 0x55: return 1;
            case 0x56: return 1;
            case 0x57: return 9;
            case 0x58: return 2;
            case 0x59: return 3;
            case 0x5A: return 3;
            case 0x5B: return 11;
            case 0x5C: return 3;
            case 0x5D: return 2;
            case 0x5E: return 3;
            case 0x5F: return 3;
            case 0x60: return 4;
            case 0x61: return 1;
            case 0x62: return 1;
            case 0x63: return 3;
            case 0x64: return 3;
            case 0x65: return 4;
            case 0x66: return 1;
            case 0x67: return 112;
            case 0x68: return 1;
            case 0x69: return 1;
            case 0x6A: return 7;
            case 0x6B: return 2;
            case 0x6C: return 2;
            case 0x6D: return 2;
            case 0x6E: return 5;
            case 0x6F: return 2;
            case 0x70: return 3;
            case 0x71: return 3;
            case 0x72: return 2;
            case 0x73: return 2;
            case 0x74: return 2;
            case 0x75: return 2;
            case 0x76: return 2;
            case 0x77: return 2;
            case 0x78: return 3;
            case 0x79: return 5;
            case 0x7A: return 3;
            case 0x7B: return 3;
            case 0x7C: return 2;
            case 0x7D: return 3;
            case 0x7E: return 2;
            case 0x7F: return 2;
            case 0x80: return 2;
            case 0x81: return 2;
            case 0x82: return 2;
            case 0x83: return 2;
            case 0x84: return 2;
            case 0x85: return 2;
            case 0x86: return 2;
            case 0x87: return 2;
            case 0x88: return 2;
            case 0x89: return 2;
            case 0x8A: return 2;
            case 0x8B: return 2;
            case 0x8C: return 2;
            case 0x8D: return 2;
            case 0x8E: return 5;
            case 0x8F: return 9;
            case 0x90: return 9;
            case 0x91: return 5;
            case 0x92: return 3;
            case 0x93: return 7;
            case 0x94: return 7;
            case 0x95: return 6;
            case 0x96: return 9;
            case 0x97: return 5;
            case 0x98: return 5;
            case 0x99: return 2;
            default: return -1;
        }
    }
    static void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        datastream.skipRawData(72);
        plaintextedit->clear();
        while(!(file.atEnd()))
        {
            int opc;
            datastream >> opc;
            if((uibyteorder==QDataStream::LittleEndian&&opc==1128681285)||(uibyteorder==QDataStream::BigEndian&&opc==1162823235)) break; // "EOFC"
            plaintextedit->appendPlainText(getOpcodeString(opc)+"(");
            for(int i=0; i<getOpcodeParamCount(opc); i++)
            {
                if(i) plaintextedit->insertPlainText(", ");
                int byte;
                datastream >> byte;
                plaintextedit->insertPlainText(QString::number(byte));
            }
            plaintextedit->insertPlainText(");");
        }

        editWidgets.tabedit->setEnabled(false);
    }
    static void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(QDataStream::ByteOrder::LittleEndian);
        datastream << 1129535056 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
        datastream.setByteOrder(uibyteorder);
        QString line;
        QStringList commandlist;
        commandlist=plaintextedit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
        for(int i=0; i<commandlist.length(); i++)
        {
            QStringList splitcommand=commandlist.at(i).split('(', QString::SkipEmptyParts);
            int opcode=getOpcodeNumber(splitcommand.at(0));
            datastream << opcode;
            QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', QString::SkipEmptyParts);
            int expcount=getOpcodeParamCount(opcode);
            if(!(splitparams.length()==expcount))
            {
                qDebug() << "E: Parameter count mismatch for opcode" << "0x"+QString::number(opcode, 16).toUpper() << "AKA" << splitcommand.at(0) << endl << "Expected:" << expcount << endl << "Got:" << splitparams.length();
                file.close();
                return;
            }
            for(int j=0; j<splitparams.length(); j++)
                datastream << splitparams.at(j).toInt();
        }
        datastream.setByteOrder(QDataStream::ByteOrder::LittleEndian);
        datastream << 1128681285 << 0 << 0 << 0 << 0 << 0 << 0;
    }
};

class DivaScriptOpcode_FT
{
public:
    static int getOpcodeNumber(QString opcodeString)
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
        else if(opcodeString=="MOT_SMOOTH") return 0x40;
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
        else if(opcodeString=="TARGET_FLAG") return 0x54;
        else if(opcodeString=="ITEM_ANIM_ATTACH") return 0x55;
        else if(opcodeString=="SHADOW_RANGE") return 0x56;
        else if(opcodeString=="HAND_SCALE") return 0x57;
        else if(opcodeString=="LIGHT_POS") return 0x58;
        else if(opcodeString=="FACE_TYPE") return 0x59;
        else if(opcodeString=="SHADOW_CAST") return 0x5A;
        else if(opcodeString=="EDIT_MOTION_F") return 0x5B;
        else if(opcodeString=="FOG") return 0x5C;
        else if(opcodeString=="BLOOM") return 0x5D;
        else if(opcodeString=="COLOR_COLLE") return 0x5E;
        else if(opcodeString=="DOF") return 0x5F;
        else if(opcodeString=="CHARA_ALPHA") return 0x60;
        else if(opcodeString=="AOTO_CAP") return 0x61;
        else if(opcodeString=="MAN_CAP") return 0x62;
        else if(opcodeString=="TOON") return 0x63;
        else if(opcodeString=="SHIMMER") return 0x64;
        else if(opcodeString=="ITEM_ALPHA") return 0x65;
        else if(opcodeString=="MOVIE_CUT_CHG") return 0x66;
        else if(opcodeString=="CHARA_LIGHT") return 0x67;
        else if(opcodeString=="STAGE_LIGHT") return 0x68;
        else if(opcodeString=="AGEAGE_CTRL") return 0x69;
        else if(opcodeString=="PSE") return 0x6A;
        else return -1;
    }
    static QString getOpcodeString(int opcodeNumber)
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
            case 0x40: return "MOT_SMOOTH";
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
            case 0x54: return "TARGET_FLAG";
            case 0x55: return "ITEM_ANIM_ATTACH";
            case 0x56: return "SHADOW_RANGE";
            case 0x57: return "HAND_SCALE";
            case 0x58: return "LIGHT_POS";
            case 0x59: return "FACE_TYPE";
            case 0x5A: return "SHADOW_CAST";
            case 0x5B: return "EDIT_MOTION_F";
            case 0x5C: return "FOG";
            case 0x5D: return "BLOOM";
            case 0x5E: return "COLOR_COLLE";
            case 0x5F: return "DOF";
            case 0x60: return "CHARA_ALPHA";
            case 0x61: return "AOTO_CAP";
            case 0x62: return "MAN_CAP";
            case 0x63: return "TOON";
            case 0x64: return "SHIMMER";
            case 0x65: return "ITEM_ALPHA";
            case 0x66: return "MOVIE_CUT_CHG";
            case 0x67: return "CHARA_LIGHT";
            case 0x68: return "STAGE_LIGHT";
            case 0x69: return "AGEAGE_CTRL";
            case 0x6A: return "PSE";
            default: return "UNKNOWN_OPCODE_0x"+QString::number(opcodeNumber, 16);
        }
    }
    static int getOpcodeParamCount(int opcodeNumber)
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
            case 0x0E: return 1;
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
            case 0x51: return 24;
            case 0x52: return 1;
            case 0x53: return 2;
            case 0x54: return 1;
            case 0x55: return 3;
            case 0x56: return 1;
            case 0x57: return 3;
            case 0x58: return 4;
            case 0x59: return 1;
            case 0x5A: return 2;
            case 0x5B: return 6;
            case 0x5C: return 3;
            case 0x5D: return 2;
            case 0x5E: return 3;
            case 0x5F: return 3;
            case 0x60: return 4;
            case 0x61: return 1;
            case 0x62: return 1;
            case 0x63: return 3;
            case 0x64: return 3;
            case 0x65: return 4;
            case 0x66: return 2;
            case 0x67: return 3;
            case 0x68: return 3;
            case 0x69: return 8;
            case 0x6A: return 2;
            default: return -1;
        }
    }
    static void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        datastream.skipRawData(4);
        plaintextedit->clear();
        while(!(file.atEnd()))
        {
            int opc;
            datastream >> opc;
            plaintextedit->appendPlainText(getOpcodeString(opc)+"(");
            for(int i=0; i<getOpcodeParamCount(opc); i++)
            {
                if(i) plaintextedit->insertPlainText(", ");
                int byte;
                datastream >> byte;
                plaintextedit->insertPlainText(QString::number(byte));
            }
            plaintextedit->insertPlainText(");");
        }

        editWidgets.tabedit->setEnabled(false);
    }
    static void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        datastream << 335874337;
        QString line;
        QStringList commandlist;
        commandlist=plaintextedit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
        for(int i=0; i<commandlist.length(); i++)
        {
            QStringList splitcommand=commandlist.at(i).split('(', QString::SkipEmptyParts);
            int opcode=getOpcodeNumber(splitcommand.at(0));
            datastream << opcode;
            QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', QString::SkipEmptyParts);
            int expcount=getOpcodeParamCount(opcode);
            if(!(splitparams.length()==expcount))
            {
                qDebug() << "E: Parameter count mismatch for opcode" << "0x"+QString::number(opcode, 16).toUpper() << "AKA" << splitcommand.at(0) << endl << "Expected:" << expcount << endl << "Got:" << splitparams.length();
                file.close();
                return;
            }
            for(int j=0; j<splitparams.length(); j++)
                datastream << splitparams.at(j).toInt();
        }
    }
};

class DivaScriptOpcode_PDA
{
public:
    static int getOpcodeNumber(QString opcodeString)
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
        else if(opcodeString=="MOT_SMOOTH") return 0x40;
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
        else if(opcodeString=="TARGET_FLAG") return 0x54;
        else if(opcodeString=="ITEM_ANIM_ATTACH") return 0x55;
        else if(opcodeString=="SHADOW_RANGE") return 0x56;
        else if(opcodeString=="HAND_SCALE") return 0x57;
        else if(opcodeString=="LIGHT_POS") return 0x58;
        else if(opcodeString=="FACE_TYPE") return 0x59;
        else if(opcodeString=="SHADOW_CAST") return 0x5A;
        else if(opcodeString=="EDIT_MOTION_F") return 0x5B;
        else if(opcodeString=="FOG") return 0x5C;
        else if(opcodeString=="BLOOM") return 0x5D;
        else if(opcodeString=="COLOR_COLLE") return 0x5E;
        else if(opcodeString=="DOF") return 0x5F;
        else if(opcodeString=="CHARA_ALPHA") return 0x60;
        else if(opcodeString=="AOTO_CAP") return 0x61;
        else if(opcodeString=="MAN_CAP") return 0x62;
        else if(opcodeString=="TOON") return 0x63;
        else if(opcodeString=="SHIMMER") return 0x64;
        else if(opcodeString=="ITEM_ALPHA") return 0x65;
        else if(opcodeString=="MOVIE_CUT_CHG") return 0x66;
        else if(opcodeString=="CHARA_LIGHT") return 0x67;
        else if(opcodeString=="STAGE_LIGHT") return 0x68;
        else if(opcodeString=="AGEAGE_CTRL") return 0x69;
        else if(opcodeString=="PSE") return 0x6A;
        else return -1;
    }
    static QString getOpcodeString(int opcodeNumber)
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
            case 0x40: return "MOT_SMOOTH";
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
            case 0x54: return "TARGET_FLAG";
            case 0x55: return "ITEM_ANIM_ATTACH";
            case 0x56: return "SHADOW_RANGE";
            case 0x57: return "HAND_SCALE";
            case 0x58: return "LIGHT_POS";
            case 0x59: return "FACE_TYPE";
            case 0x5A: return "SHADOW_CAST";
            case 0x5B: return "EDIT_MOTION_F";
            case 0x5C: return "FOG";
            case 0x5D: return "BLOOM";
            case 0x5E: return "COLOR_COLLE";
            case 0x5F: return "DOF";
            case 0x60: return "CHARA_ALPHA";
            case 0x61: return "AOTO_CAP";
            case 0x62: return "MAN_CAP";
            case 0x63: return "TOON";
            case 0x64: return "SHIMMER";
            case 0x65: return "ITEM_ALPHA";
            case 0x66: return "MOVIE_CUT_CHG";
            case 0x67: return "CHARA_LIGHT";
            case 0x68: return "STAGE_LIGHT";
            case 0x69: return "AGEAGE_CTRL";
            case 0x6A: return "PSE";
            default: return "UNKNOWN_OPCODE_0x"+QString::number(opcodeNumber, 16);
        }
    }
    static int getOpcodeParamCount(int opcodeNumber)
    {
        switch(opcodeNumber)
        {
            case 0x00: return 0;
            case 0x01: return 1;
            case 0x02: return 3;
            case 0x03: return 1;
            case 0x04: return 1;
            case 0x05: return 1;
            case 0x06: return 7;
            case 0x07: return 3;
            case 0x08: return 1;
            case 0x09: return 5;
            case 0x0A: return 2;
            case 0x0B: return 1;
            case 0x0C: return 6;
            case 0x0D: return 2;
            case 0x0E: return 1;
            case 0x0F: return 1;
            case 0x10: return 3;
            case 0x11: return 2;
            case 0x12: return 2;
            case 0x13: return 3;
            case 0x14: return 4;
            case 0x15: return 3;
            case 0x16: return 3;
            case 0x17: return 4;
            case 0x18: return 1;
            case 0x19: return 0;
            case 0x1A: return 1;
            case 0x1B: return 2;
            case 0x1C: return 2;
            case 0x1D: return 1;
            case 0x1E: return 2;
            case 0x1F: return 19;
            case 0x20: return 0;
            case 0x21: return 2;
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
            case 0x32: return 1;
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
            case 0x51: return 24;
            case 0x52: return 1;
            case 0x53: return 2;
            case 0x54: return 1;
            case 0x55: return 3;
            case 0x56: return 1;
            case 0x57: return 3;
            case 0x58: return 4;
            case 0x59: return 1;
            case 0x5A: return 2;
            case 0x5B: return 6;
            case 0x5C: return 3;
            case 0x5D: return 2;
            case 0x5E: return 3;
            case 0x5F: return 3;
            case 0x60: return 4;
            case 0x61: return 1;
            case 0x62: return 1;
            case 0x63: return 3;
            case 0x64: return 3;
            case 0x65: return 4;
            case 0x66: return 2;
            case 0x67: return 3;
            case 0x68: return 3;
            case 0x69: return 8;
            case 0x6A: return 2;
            default: return -1;
        }
    }
    static void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        plaintextedit->clear();
        while(!(file.atEnd()))
        {
            int opc;
            datastream >> opc;
            plaintextedit->appendPlainText(getOpcodeString(opc)+"(");
            for(int i=0; i<getOpcodeParamCount(opc); i++)
            {
                if(i) plaintextedit->insertPlainText(", ");
                int byte;
                datastream >> byte;
                plaintextedit->insertPlainText(QString::number(byte));
            }
            plaintextedit->insertPlainText(");");
        }

        editWidgets.tabedit->setEnabled(false);
    }
    static void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        QString line;
        QStringList commandlist;
        commandlist=plaintextedit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
        for(int i=0; i<commandlist.length(); i++)
        {
            QStringList splitcommand=commandlist.at(i).split('(', QString::SkipEmptyParts);
            int opcode=getOpcodeNumber(splitcommand.at(0));
            datastream << opcode;
            QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', QString::SkipEmptyParts);
            int expcount=getOpcodeParamCount(opcode);
            if(!(splitparams.length()==expcount))
            {
                qDebug() << "E: Parameter count mismatch for opcode" << "0x"+QString::number(opcode, 16).toUpper() << "AKA" << splitcommand.at(0) << endl << "Expected:" << expcount << endl << "Got:" << splitparams.length();
                file.close();
                return;
            }
            for(int j=0; j<splitparams.length(); j++)
                datastream << splitparams.at(j).toInt();
        }
    }
};

class DivaScriptOpcode_DIVA
{
public:
    static int getOpcodeNumber(QString opcodeString)
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
        else if(opcodeString=="NEAR_CLIP") return 0x22;
        else if(opcodeString=="CLOTH_WET") return 0x23;
        else return -1;
    }
    static QString getOpcodeString(int opcodeNumber)
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
            case 0x22: return "NEAR_CLIP";
            case 0x23: return "CLOTH_WET";
            default: return "UNKNOWN_OPCODE_0x"+QString::number(opcodeNumber, 16);
        }
    }
    static int getOpcodeParamCount(int opcodeNumber)
    {
        switch(opcodeNumber)
        {
            case 0x00: return 0;
            case 0x01: return 1;
            case 0x02: return 3;
            case 0x03: return 1;
            case 0x04: return 1;
            case 0x05: return 1;
            case 0x06: return 7;
            case 0x07: return 2;
            case 0x08: return 1;
            case 0x09: return 5;
            case 0x0A: return 2;
            case 0x0B: return 1;
            case 0x0C: return 6;
            case 0x0D: return 2;
            case 0x0E: return 1;
            case 0x0F: return 1;
            case 0x10: return 3;
            case 0x11: return 2;
            case 0x12: return 2;
            case 0x13: return 2;
            case 0x14: return 2;
            case 0x15: return 3;
            case 0x16: return 1;
            case 0x17: return 4;
            case 0x18: return 1;
            case 0x19: return 0;
            case 0x1A: return 1;
            case 0x1B: return 2;
            case 0x1C: return 2;
            case 0x1D: return 1;
            case 0x1E: return 2;
            case 0x1F: return 19;
            case 0x20: return 0;
            case 0x21: return 2;
            case 0x22: return 2;
            case 0x23: return 1;
            default: return -1;
        }
    }
    static void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        plaintextedit->clear();
        while(!(file.atEnd()))
        {
            int opc;
            datastream >> opc;
            plaintextedit->appendPlainText(getOpcodeString(opc)+"(");
            for(int i=0; i<getOpcodeParamCount(opc); i++)
            {
                if(i) plaintextedit->insertPlainText(", ");
                int byte;
                datastream >> byte;
                plaintextedit->insertPlainText(QString::number(byte));
            }
            plaintextedit->insertPlainText(");");
        }

        editWidgets.tabedit->setEnabled(false);
    }
    static void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        QString line;
        QStringList commandlist;
        commandlist=plaintextedit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
        for(int i=0; i<commandlist.length(); i++)
        {
            QStringList splitcommand=commandlist.at(i).split('(', QString::SkipEmptyParts);
            int opcode=getOpcodeNumber(splitcommand.at(0));
            datastream << opcode;
            QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', QString::SkipEmptyParts);
            int expcount=getOpcodeParamCount(opcode);
            if(!(splitparams.length()==expcount))
            {
                qDebug() << "E: Parameter count mismatch for opcode" << "0x"+QString::number(opcode, 16).toUpper() << "AKA" << splitcommand.at(0) << endl << "Expected:" << expcount << endl << "Got:" << splitparams.length();
                file.close();
                return;
            }
            for(int j=0; j<splitparams.length(); j++)
                datastream << splitparams.at(j).toInt();
        }
    }
};

class DivaScriptOpcode_DIVA2
{
public:
    static int getOpcodeNumber(QString opcodeString)
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
        else return -1;
    }
    static QString getOpcodeString(int opcodeNumber)
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
            default: return "UNKNOWN_OPCODE_0x"+QString::number(opcodeNumber, 16);
        }
    }
    static int getOpcodeParamCount(int opcodeNumber)
    {
        switch(opcodeNumber)
        {
            case 0x00: return 0;
            case 0x01: return 1;
            case 0x02: return 4;
            case 0x03: return 2;
            case 0x04: return 2;
            case 0x05: return 2;
            case 0x06: return 11;
            case 0x07: return 3;
            case 0x08: return 2;
            case 0x09: return 6;
            case 0x0A: return 2;
            case 0x0B: return 1;
            case 0x0C: return 6;
            case 0x0D: return 2;
            case 0x0E: return 1;
            case 0x0F: return 1;
            case 0x10: return 3;
            case 0x11: return 2;
            case 0x12: return 3;
            case 0x13: return 4;
            case 0x14: return 3;
            case 0x15: return 4;
            case 0x16: return 2;
            case 0x17: return 5;
            case 0x18: return 1;
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
            default: return -1;
        }
    }
    static void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        plaintextedit->clear();
        while(!(file.atEnd()))
        {
            int opc;
            datastream >> opc;
            plaintextedit->appendPlainText(getOpcodeString(opc)+"(");
            for(int i=0; i<getOpcodeParamCount(opc); i++)
            {
                if(i) plaintextedit->insertPlainText(", ");
                int byte;
                datastream >> byte;
                plaintextedit->insertPlainText(QString::number(byte));
            }
            plaintextedit->insertPlainText(");");
        }

        editWidgets.tabedit->setEnabled(false);
    }
    static void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        QString line;
        QStringList commandlist;
        commandlist=plaintextedit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
        for(int i=0; i<commandlist.length(); i++)
        {
            QStringList splitcommand=commandlist.at(i).split('(', QString::SkipEmptyParts);
            int opcode=getOpcodeNumber(splitcommand.at(0));
            datastream << opcode;
            QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', QString::SkipEmptyParts);
            int expcount=getOpcodeParamCount(opcode);
            if(!(splitparams.length()==expcount))
            {
                qDebug() << "E: Parameter count mismatch for opcode" << "0x"+QString::number(opcode, 16).toUpper() << "AKA" << splitcommand.at(0) << endl << "Expected:" << expcount << endl << "Got:" << splitparams.length();
                file.close();
                return;
            }
            for(int j=0; j<splitparams.length(); j++)
                datastream << splitparams.at(j).toInt();
        }
    }
};

class DivaScriptOpcode_DIVA2Edit:DivaScriptOpcode_DIVA2
{
public:
    static void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder)
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
        plaintextedit->clear();

        // DSC
        file.seek(DIVA_SCRIPT_OFFSET+dtoffset);
        for(short s=0; s<max; s++)
        {
            int opc;
            datastream >> opc;
            if(getOpcodeParamCount(opc)==-1) break;
            plaintextedit->appendPlainText(getOpcodeString(opc)+"(");
            for(int i=0; i<getOpcodeParamCount(opc); i++)
            {
                if(i) plaintextedit->insertPlainText(", ");
                int byte;
                datastream >> byte;
                plaintextedit->insertPlainText(QString::number(byte));
            }
            plaintextedit->insertPlainText(");");
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

        editWidgets.tabedit->setEnabled(true);
    }
};

class DivaScriptOpcode_Mirai
{
public:
    static int getOpcodeNumber(QString opcodeString)
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
    static QString getOpcodeString(int opcodeNumber)
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
            default: return "UNKNOWN_OPCODE_0x"+QString::number(opcodeNumber, 16);
        }
    }
    static int getOpcodeParamCount(int opcodeNumber)
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
            case 0x0E: return 1;
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
    static void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(uibyteorder);
        datastream.skipRawData(4);
        plaintextedit->clear();
        while(!(file.atEnd()))
        {
            int opc;
            datastream >> opc;
            plaintextedit->appendPlainText(getOpcodeString(opc)+"(");
            for(int i=0; i<getOpcodeParamCount(opc); i++)
            {
                if(i) plaintextedit->insertPlainText(", ");
                int byte;
                datastream >> byte;
                plaintextedit->insertPlainText(QString::number(byte));
            }
            plaintextedit->insertPlainText(");");
        }

        editWidgets.tabedit->setEnabled(false);
    }
    static void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *plaintextedit, QDataStream::ByteOrder uibyteorder)
    {
        datastream.setByteOrder(QDataStream::ByteOrder::LittleEndian);
        datastream << 302121504;
        datastream.setByteOrder(uibyteorder);
        QString line;
        QStringList commandlist;
        commandlist=plaintextedit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
        for(int i=0; i<commandlist.length(); i++)
        {
            QStringList splitcommand=commandlist.at(i).split('(', QString::SkipEmptyParts);
            int opcode=getOpcodeNumber(splitcommand.at(0));
            datastream << opcode;
            QStringList splitparams=QString(splitcommand.at(1)).remove(')').split(',', QString::SkipEmptyParts);
            int expcount=getOpcodeParamCount(opcode);
            if(!(splitparams.length()==expcount))
            {
                qDebug() << "E: Parameter count mismatch for opcode" << "0x"+QString::number(opcode, 16).toUpper() << "AKA" << splitcommand.at(0) << endl << "Expected:" << expcount << endl << "Got:" << splitparams.length();
                file.close();
                return;
            }
            for(int j=0; j<splitparams.length(); j++)
                datastream << splitparams.at(j).toInt();
        }
    }
};
