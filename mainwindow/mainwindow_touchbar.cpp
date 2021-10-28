#include "mainwindow.h"

void MainWindow::touchBar_main()
{
#ifdef Q_OS_MACOS
    touchBar->clear();

    QIcon openIcon(QStringLiteral(":/icons/icons8/color/icons/icons8/color/icons8-apri-cartella-96.png"));
    QAction *openAction = new QAction(openIcon, tr(""));
    touchBar->addAction(openAction);
    connect(openAction, &QAction::triggered, this, &MainWindow::on_actionOpen_DSC_triggered);

    QIcon saveIcon(QStringLiteral(":/icons/icons8/color/icons/icons8/color/icons8-salva-96.png"));
    QAction *saveAction = new QAction(saveIcon, tr(""));
    touchBar->addAction(saveAction);
    connect(saveAction, &QAction::triggered, this, &MainWindow::on_actionSave_DSC_triggered);

    QIcon undoIcon(QStringLiteral(":/icons/icons8/color/icons/icons8/color/icons8-annulla-96.png"));
    QAction *undoAction = new QAction(undoIcon, tr(""));
    touchBar->addAction(undoAction);
    connect(undoAction, &QAction::triggered, this, &MainWindow::on_actionUndo_triggered);

    QIcon redoIcon(QStringLiteral(":/icons/icons8/color/icons/icons8/color/icons8-ripeti-96.png"));
    QAction *redoAction = new QAction(redoIcon, tr(""));
    touchBar->addAction(redoAction);
    connect(redoAction, &QAction::triggered, this, &MainWindow::on_actionRedo_triggered);

    QIcon findIcon(QStringLiteral(":/icons/icons8/color/icons/icons8/color/icons8-trova-e-sostituisci-96.png"));
    QAction *findAction = new QAction(findIcon, tr(""));
    touchBar->addAction(findAction);
    connect(findAction, &QAction::triggered, this, &MainWindow::on_actionFind_and_replace_triggered);

    QIcon addIcon(QStringLiteral(":/icons/icons8/color/icons/icons8/color/icons8-aggiungi-96.png"));
    QAction *addAction = new QAction(addIcon, tr(""));
    touchBar->addAction(addAction);
    connect(addAction, &QAction::triggered, this, &MainWindow::on_actionAdd_command_triggered);

    QIcon removeIcon(QStringLiteral(":/icons/icons8/color/icons/icons8/color/icons8-rimuovi-96.png"));
    QAction *removeAction = new QAction(removeIcon, tr(""));
    removeAction->setEnabled(false);
    touchBar->addAction(removeAction);
    connect(removeAction, &QAction::triggered, this, &MainWindow::on_actionRemove_command_triggered);

    touchBar->addSeparator();

    QAction *toolsAction = new QAction(tr("Tools"));
    touchBar->addAction(toolsAction);
    connect(toolsAction, &QAction::triggered, this, &MainWindow::touchBar_tools);
#endif
}

void MainWindow::touchBar_tools()
{
#ifdef Q_OS_MACOS
    touchBar->clear();

    QAction *mainAction = new QAction(tr("Back"));
    touchBar->addAction(mainAction);
    connect(mainAction, &QAction::triggered, this, &MainWindow::touchBar_main);

    touchBar->addSeparator();
    touchBar->addSeparator();

    QAction *timeToolAction = new QAction(tr("Time"));
    touchBar->addAction(timeToolAction);
    connect(timeToolAction, &QAction::triggered, this, &MainWindow::on_actionTime_triggered);

    touchBar->addSeparator();

    touchBar->addAction(wrapAction);
    connect(wrapAction, &QAction::triggered, this, &MainWindow::toggleWrap);
#endif
}
