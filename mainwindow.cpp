#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),m_tgcl(new TgCaller()),m_prcs(new JSONProcs())
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_tgcl;
}

void MainWindow::invoke_netcaller()
{
    m_tgcl->procs();
}

void MainWindow::invoke_processor()
{
    m_prcs->process();
}

void MainWindow::init()
{

    m_tgcl->procs();// need to push to QThread

    if(m_tgcl->processed()){
        //ui lbl ok
        m_prcs->process();
    }
}

