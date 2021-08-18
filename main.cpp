#include "mainwindow.h"
#include "DSC.h"
#include "EditWidgets.h"
#include "logger.h"

#include <QApplication>
#include <QFile>
#include <QDataStream>
#include <QPlainTextEdit>
#include <QDebug>

#include "KDMacTouchBar/kdmactouchbar.h"

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
    logger::initlogfile();

    QApplication a(argc, argv);

#ifdef Q_OS_MACOS
    KDMacTouchBar::setAutomaticallyCreateMessageBoxTouchBar(true);
#endif

    if(argc>=3)
    {
        QTextEdit dummyLogEdit;
        dummyLogEdit.document()->setUndoRedoEnabled(false);
        DivaScriptOpcode_FT DSO(&dummyLogEdit);

        QFile input(argv[1]);
        input.open(QIODevice::ReadOnly);
        QDataStream qds(&input);
        QPlainTextEdit *textEdit = new QPlainTextEdit;
        textEdit->document()->setUndoRedoEnabled(false);
        DSO.readAll(input, qds, textEdit, uiEditWidgetsStub(), QDataStream::LittleEndian);
        input.close();
        QStringList commandlist;
        commandlist=textEdit->document()->toPlainText().split(';', Qt::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
        QFile output(argv[2]);
        output.open(QIODevice::WriteOnly);
        output.resize(0);
        QDataStream qdso(&output);
        for(int i=0; i<commandlist.length(); i++)
            qdso << commandlist.at(i).toLatin1() << '\n';
        output.close();

        qDebug() << dummyLogEdit.document()->toPlainText();
        exit(0);
    }

    MainWindow w;
    w.show();

    return a.exec();
}
