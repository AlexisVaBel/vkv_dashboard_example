#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <netcaller/tgcaller.h>

#include <flprocs/jsonprocs.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void invoke_netcaller();
    void invoke_processor();

private:
    Ui::MainWindow *ui;
    TgCaller *m_tgcl;
    JSONProcs *m_prcs;

    void init();

};
#endif // MAINWINDOW_H
