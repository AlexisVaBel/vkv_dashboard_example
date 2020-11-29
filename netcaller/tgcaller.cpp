#include "tgcaller.h"

#include <QProcess>
#include <iostream>


TgCaller::TgCaller()
{

}

TgCaller::~TgCaller()
{
    p->deleteLater();
}

// TODO location of pyth script shouldn`t be hardcoded
void TgCaller::procs()
{
    p = new QProcess();
    QStringList params;

    params << "./pypy/main.py";
    p->start("python3", params);
    connect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(read_procs()));
    connect(p, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(error_occured(QProcess::ProcessError)));
    connect(p, SIGNAL(finished(int)), this, SLOT(finished(int)));
    p->waitForFinished(5000);// testing 5 seconds
    p->kill();

}

bool TgCaller::processed()
{
    return m_bResult;
}

// TODO phone number is constant, shouldn`t be hardcoded
// searching is also hardcoded, need to fix
void TgCaller::read_procs()
{
    QString strCall = p->readLine();
    std::cout << strCall.toStdString() << std::endl;


    if(strCall.contains("Please enter your phone")){
        p->write("+7923647530");
        p->write("\0");
        p->waitForBytesWritten(500);
    }
    if(strCall.contains("Введите ссылку на канал или чат")){
        // отпроцессим "Происшествия Барнаул"
        p->write("https://t.me/incident22");
        p->write("\0");
        p->waitForBytesWritten(500);
    }
}

void TgCaller::error_occured(QProcess::ProcessError error)
{
    std::cout << " error " << error << std::endl;
}

void TgCaller::finished(int icode)
{
    std::cout << " finished with code " << icode << std::endl;
}
