#ifndef LOADBIG_H
#define LOADBIG_H
#include "cali.h"
#include <stdio.h>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <sys/time.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

class LoadBig : public QObject
{
    Q_OBJECT
public:
    explicit LoadBig(QObject *parent = 0);
public:
    union big_value
    {
        char buffer[4];
        unsigned long  val;
    };
    union big_value bigtemp;

signals:
    
public slots:
    void Biginit();
    void BigSlot();

private:
    QThread Big_thread;
    QTimer BigTimer;

    
};

#endif // LOADBIG_H
