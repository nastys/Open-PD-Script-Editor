#ifndef DSC_H
#define DSC_H

#include <QString>
#include <QFile>
#include <QPlainTextEdit>
#include <QTableWidget>
#include <QDataStream>
#include <QTextCodec>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextEdit>
#include <QListWidget>
#include "mainwindow.h"
#include "debug.h"

class DivaScriptOpcode
{
protected:
    QJsonDocument jsondb;
    QJsonObject jsonob;
    QStringList jsonkeys;
    QTextEdit* logEdit;

public:
    DivaScriptOpcode(QTextEdit* logEdit);
    virtual QString gameStr() {return "";};
    int getOpcodeNumber(QString opcodeString);
    QString getOpcodeString(int opcodeNumber);
    int getOpcodeParamCount(int opcodeNumber);
    void fillCommandListWidget(QListWidget* qlw);
    void logger(QString log);
    virtual void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode = false){logger("No format.");};
    virtual void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder){logger("No format.");};
};

class DivaScriptOpcode_F : public DivaScriptOpcode
{
public:
    using DivaScriptOpcode::DivaScriptOpcode;
    QString gameStr() override {return "f";};
    void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode = false) override;
    void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder) override;
};

class DivaScriptOpcode_F2 : public DivaScriptOpcode
{
public:
    using DivaScriptOpcode::DivaScriptOpcode;
    QString gameStr() override {return "F2";};
    void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode = false) override;
    void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder) override;
};

class DivaScriptOpcode_X : public DivaScriptOpcode
{
public:
    using DivaScriptOpcode::DivaScriptOpcode;
    QString gameStr() override {return "X";};
    void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode = false) override;
    void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder) override;
};

class DivaScriptOpcode_FT : public DivaScriptOpcode
{
public:
    using DivaScriptOpcode::DivaScriptOpcode;
    QString gameStr() override {return "FT";};
    void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode = false) override;
    void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder) override;
};

class DivaScriptOpcode_PDA : public DivaScriptOpcode
{
public:
    using DivaScriptOpcode::DivaScriptOpcode;
    QString gameStr() override {return "A12";};
    void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode = false) override;
    void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder) override;
};

class DivaScriptOpcode_DIVA : public DivaScriptOpcode
{
public:
    using DivaScriptOpcode::DivaScriptOpcode;
    QString gameStr() override {return "PSP1";};
    void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode = false) override;
    void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder) override;
};

class DivaScriptOpcode_DIVA2 : public DivaScriptOpcode
{
public:
    using DivaScriptOpcode::DivaScriptOpcode;
    QString gameStr() override {return "PSP2";};
    void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode = false) override;
    void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder) override;
};

class DivaScriptOpcode_DIVA2Edit : public DivaScriptOpcode_DIVA2
{
public:
    using DivaScriptOpcode_DIVA2::DivaScriptOpcode_DIVA2;
    void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode = false) override;
};

class DivaScriptOpcode_Mirai : public DivaScriptOpcode
{
public:
    using DivaScriptOpcode::DivaScriptOpcode;
    int getOpcodeNumber(QString opcodeString);
    QString getOpcodeString(int opcodeNumber);
    int getOpcodeParamCount(int opcodeNumber);
    void readAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, EditWidgets editWidgets, QDataStream::ByteOrder uibyteorder, bool testmode = false) override;
    void writeAll(QFile &file, QDataStream &datastream, QPlainTextEdit *textedit, QDataStream::ByteOrder uibyteorder) override;
};

DivaScriptOpcode *formatSelection(int dscfmt, QTextEdit* logEdit);

void mergeDsc(QStringList &mergelist, QPlainTextEdit *dest, QPlainTextEdit *import, bool &isLoading, QTextEdit *logEdit);

#endif // DSC_H
