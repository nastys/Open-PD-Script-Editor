#include "mainwindow.h"
#include "DSC.cpp"
#include "EditWidgets.h"

#include <QApplication>
#include <QFile>
#include <QDataStream>
#include <QPlainTextEdit>

EditWidgets uiEditWidgetsStub()
{
    EditWidgets editWidgets;
    editWidgets.tabedit=new QTabWidget;
    editWidgets.bartable=new QTableWidget;
    editWidgets.editname=new QLineEdit;
    editWidgets.songname=new QLineEdit;
    editWidgets.songstart=new QSpinBox;
    editWidgets.modulelist=new QListWidget;
    editWidgets.stagelist=new QListWidget;
    editWidgets.motionlist=new QListWidget;
    editWidgets.effectlist=new QListWidget;
    editWidgets.handitemlist=new QListWidget;
    editWidgets.songend=new QSpinBox;
    editWidgets.buttonsfx=new QSpinBox;

    return editWidgets;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(argc>=3)
    {
        QFile input(argv[1]);
        input.open(QIODevice::ReadOnly);
        QDataStream qds(&input);
        QPlainTextEdit *plainTextEdit = new QPlainTextEdit;
        DivaScriptOpcode_FT::readAll(input, qds, plainTextEdit, uiEditWidgetsStub(), QDataStream::LittleEndian);
        input.close();
        QStringList commandlist;
        commandlist=plainTextEdit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
        QFile output(argv[2]);
        output.open(QIODevice::WriteOnly);
        output.resize(0);
        QDataStream qdso(&output);
        for(int i=0; i<commandlist.length(); i++)
            qdso << commandlist.at(i).toLatin1() << '\n';
        output.close();
        exit(0);
    }

    MainWindow w;
    w.show();

    return a.exec();
}
