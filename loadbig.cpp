#include "loadbig.h"

LoadBig::LoadBig(QObject *parent) :
    QObject(parent)
{
    this->moveToThread(&Big_thread);
    fd_iouart = open("/dev/io-uart", O_RDWR | O_NONBLOCK);

    qDebug() <<"BigThread thread start!!";
    Big_thread.start();

}
void LoadBig::Biginit()
{
    connect(&BigTimer, SIGNAL(timeout()), this, SLOT(BigSlot()));
    BigTimer.start(50);
}
void LoadBig::BigSlot()
{
    if(b_BigLoading==0)
    {
        bigtemp.val=BigData;
        write(fd_iouart, bigtemp.buffer, 4);
    }
}



