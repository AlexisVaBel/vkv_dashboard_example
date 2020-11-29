#include "jsonprocs.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

#include <iostream>

JSONProcs::JSONProcs()
{

}

JSONProcs::~JSONProcs()
{

}

bool JSONProcs::process(QString fileName)
{    
    QByteArray *arr = read_file(fileName);
    if(arr->isEmpty()) return false;

    QByteArray bt = *arr;
    QJsonDocument doc = QJsonDocument::fromJson(bt);


    QJsonArray arroot = doc.array();

    for(auto i = 0; i < arroot.count();++i){
        QJsonObject subObj = arroot.at(i).toObject();
        if(!subObj.isEmpty()){
            for(auto skey: subObj.keys()){
                if(skey.compare("message") == 0){

                    QString str = subObj.value(skey).toString().toLocal8Bit();

                    if(str.contains(QString::fromLocal8Bit("авари"),Qt::CaseInsensitive)){
                        std::cout <<" ==DTP== "<< str.toStdString() << std::endl;
                    }
                    if(str.contains(QString::fromLocal8Bit("похити"),Qt::CaseInsensitive)){
                        std::cout <<" ==STEAL== "<< str.toStdString() << std::endl;
                    }
                    // just for tests
                    if(str.contains(QString::fromLocal8Bit("пожарные"),Qt::CaseInsensitive)){
                        std::cout <<" ==FIREMEN== "<< str.toStdString() << std::endl;
                    }

                }
            }
        }
    }
    delete arr;
    return false;
}

QByteArray* JSONProcs::read_file(QString fileName)
{
    QFile file(fileName);
    QByteArray arrTmp;
    QByteArray *arr = new QByteArray();

    if(!file.exists()) return arr;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return arr;

    do{
        arrTmp = file.read(10);
        if(!arrTmp.isEmpty())arr->push_back(arrTmp);
    }
    while(!arrTmp.isEmpty());


    file.close();
    return arr;
}
