#include "buzzer.h"

buzzer::buzzer(QObject *parent) :
    QObject(parent)
{
    this->moveToThread(&m_thread);
    m_thread.start();
}

void buzzer::buzzerthreadstart()
{
    qDebug() <<"buzzer123 thread start!!";


    fd_buzzer  = open("/dev/input/event2", O_RDONLY| O_NONBLOCK );
    if (fd_buzzer  < 0)
    {

        perror("open err");
        exit(1);
    }
    buzzerscan();
}



void buzzer::buzzerscan()
{
    unsigned char c[128];
    int n;
    int i;
    i=0;

    while(0)
    {
        n=read(fd_buzzer,c,128);
        if(n)
        {
            if(n==(-1))
            {
                if(beepflag==1)
                {
                 qDebug() <<"beepflagbeepflag================="<<beepflag;
                 beepflag=0;
                  i=0;
                }
                else
                {
                i=0;
                continue;
                }

            }
            qDebug() << "n=" <<n<< endl;
            i++;
            if(i==1)   PIN_PC10_H;
        }
        usleep(100000);
        PIN_PC10_L;
    }
}
hello world!
111
222
333