#ifndef JSONPROCS_H
#define JSONPROCS_H

#include <QObject>

class JSONProcs
{
public:
    JSONProcs();
    ~JSONProcs();
    bool process(QString fileName="./channel_messages.json");
private:
    QByteArray* read_file(QString fileName="");

    // next need some objects - presenting points of subindexes
    int i_dtp_cnt;
    int i_steal_cnt;
    int i_camera_cnt;

};

#endif // JSONPROCS_H
