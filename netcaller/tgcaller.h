#ifndef TGCALLER_H
#define TGCALLER_H

#include <qprocess.h>



class TgCaller: public QObject
{
    Q_OBJECT
public:
    TgCaller();
    ~TgCaller();
    void procs();     // prepared for starting in thread
    bool processed(); //threads result

private slots:
    void read_procs();
    void error_occured(QProcess::ProcessError error);
    void finished(int icode);
private:
    QProcess *p;
    bool     m_bResult;
};

#endif // TGCALLER_H
