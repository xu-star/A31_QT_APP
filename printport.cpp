#include "printport.h"
#include <GlobalVarible.h>
#include<QDebug>
#include <QTime>
//#include <windows.h>

int char_interval_timeout;
uint RS485_DELAY_US;
const MBVarStruct MBReg[]={
    {					//
                        0,
                        0x20,			//s32/f32
                        1,				//R
                        &Net,
                        0,
                        0,

    },
    {					//
                        2,
                        0x20,			    //s32/f32
                        1,			    //R
                        &Gross,
                        0,
                        0,
    },
    {					//
                        4,
                        0x20,			   //s32/f32
                        0,		       //W/R
                        &Tare,
                        999999,
                        0,
    },
    {					//
                        6,
                        0x0,			//s32
                        1,
                        &Net,
                        0,
                        0,
    },
    {					//
                        8,
                        0x0,			//s32
                        1,
                        &Gross,
                        0,
                        0,
    },
    {					//
                        10,
                        0x0,			//s32
                        0,
                        &Tare,
                        999999,
                        0,
    },

    {					//
                        12,
                        0x10,			//
                        0,
                        &AD_Zero,
                        0,
                        0,
    },

    {					//
                        14,
                        0x00,			//u16
                        0,
                        &Rri,
                        0,
                        0,
    },


    {					//
                        16,
                        0x00,			//u16
                        0,
                        &CalFull,
                        999999,
                        0,
    },

    {					//
                        18,
                        0x35,			//u16
                        0,
                        &Rati,
                        100,
                        1,
    },

    {					//
                        19,
                        0x35,			//u16
                        0,
                        &Point,
                        4,
                        0,
    },

    {					//
                        20,
                        0x35,			//u16
                        0,
                        &OnZero,
                        6,
                        1,
    },

    {					//
                        21,
                        0x35,			//u16
                        0,
                        &ZeroKeyVal,
                        6,
                        1,
    },

    {					//
                        22,
                        0x35,			//u16
                        0,
                        &Zono,
                        6,
                        1,
    },

    {					//
                        23,
                        0x35,			//u16
                        0,
                        &FilterStep,
                        6,
                        1,
    },

    {					//
                        24,
                        0x35,			//u16
                        0,
                        &Unit,
                        3,
                        1,
    },

    {					//
                        25,
                        0x35,			//u16
                        0,
                        &LedLight,
                        7,
                        1,
    },

    {					//
                        26,
                        0x0,			//u16
                        0,
                        &LowValue,
                        999999,
                        0,
    },

    {					//
                        28,
                        0x0,			//u16
                        0,
                        &HighValue,
                        999999,
                        0,
    },

    {					//
                        30,
                        0x35,			//u16
                        0,
                        &Tmode_232,
                        3,
                        0,
    },

    {					//
                        31,
                        0x35,			//u16
                        0,
                        &BaudRate_232,
                        8,
                        0,
    },

    {					//
                        32,
                        0x35,			//u16
                        0,
                        &DataBits_232,
                        8,
                        0,
    },

    {					//
                        33,
                        0x35,			//u16
                        0,
                        &ParityMode_232,
                        2,
                        0,
    },

    {					//
                        34,
                        0x35,			//u16
                        0,
                        &StopBits_232,
                        2,
                        0,
    },

    {					//
                        35,
                        0x35,			//u16
                        0,
                        &Addr,
                        127,
                        1,
    },

    {					//
                        36,
                        0x35,			//u16
                        0,
                        &Tmode_485,
                        2,
                        0,
    },

    {					//
                        37,
                        0x35,			//u16
                        0,
                        &BaudRate_485,
                        8,
                        0,
    },

    {					//
                        38,
                        0x35,			//u16
                        0,
                        &DataBits_485,
                        8,
                        0,
    },

    {					//
                        39,
                        0x35,			//u16
                        0,
                        &ParityMode_485,
                        2,
                        0,
    },

    {					//
                        40,
                        0x35,			//u16
                        0,
                        &StopBits_485,
                        2,
                        0,
    },


    {					//
                        41,
                        0x35,			//u16
                        0,
                        &PrintMode,
                        100,
                        0,
    },

    {					//
                        42,
                        0x00,			//u16
                        0,
                        &PrintLq,
                        999999,
                        0,
    },

    {					//
                        44,
                        0x35,			//u16
                        0,
                        &b_PrintRetZero,
                        1,
                        0,
    },

    {					//
                        45,
                        0x35,			//u16
                        0,
                        &b_PrintStable,
                        1,
                        0,
    },

    {					//
                        46,
                        0x35,			//u16
                        0,
                        &b_Save,
                        2,
                        0,
    },

    {					//
                        47,
                        0x35,			//u16
                        0,
                        &PrintCodeType,
                        2,
                        0,
    },

    {					//
                        48,
                        0x35,			//u16
                        0,
                        &PrintLableSize,
                        1,
                        0,
    },

    {					//
                        49,
                        0x35,			//u16
                        0,
                        &b_PrintAuto,
                        1,
                        0,
    },

    {					//
                        50,
                        0x35,			//u16
                        0,
                        &b_PrintHeader,
                        1,
                        0,
    },


    {					//
                        51,
                        0x01,			//u16
                        1,
                        &PrintCompanyName,
                        0,
                        0,
    },


    {					//
                        100,
                        0x33,			//u16
                        1,
                        &TotfnBusiness,
                        0,
                        0,
    },
    {					//
                        101,
                        0x33,			//u16
                        1,
                        &RecproductNum,
                        0,
                        0,
    },
    {					//
                        102,
                        0x33,			//u16
                        1,
                        &Rec[0].RecCode,
                        0,
                        0,
    },
    {					//
                        103,
                        0x0,			//u16
                        1,
                        &Rec[0].RecproductPrice,
                        0,
                        0,
    },
    {					//
                        105,
                        0x0,			//u16
                        1,
                        &Rec[0].Recweight,
                        0,
                        0,
    },
    {					//
                        107,
                        0x0,			//u16
                        1,
                        &Rec[0].Recmoney,
                        0,
                        0,
    },

    {					//
                        109,
                        0x35,			//u16
                        1,
                        &RecTime.Year,
                        0,
                        0,
    },

    {					//
                        110,
                        0x35,			//u16
                        1,
                        &RecTime.Month,
                        0,
                        0,
    },

    {					//
                        111,
                        0x35,			//u16
                        1,
                        &RecTime.Day,
                        0,
                        0,
    },

    {					//
                        112,
                        0x35,			//u16
                        1,
                        &RecTime.Hour,
                        0,
                        0,
    },

    {					//
                        112,
                        0x35,			//u16
                        1,
                        &RecTime.Minute,
                        0,
                        0,
    },

    {					//
                        113,
                        0x35,			//u16
                        1,
                        &RecTime.Second,
                        0,
                        0,
    },
    {					//
                        114,
                        0x01,			//u16
                        1,
                        &Rec[0].RecproductName,
                        0,
                        0,
    }

};


PrintPort::PrintPort(QWidget *parent):
    QObject(parent)
{
    m_fd=-1;
    m_fd1=-1;
    m_fd2=-1;
    m_fd3=-1;
    rev_buf=new QByteArray();
    send_buf=new QByteArray();
    //calia=new cali;
}
//open
bool PrintPort::openPort(QString portName, uchar baundRate, uchar dataBits,
                         uchar parity, uchar stopBits, uchar flow, int time_out)
{

    if(m_fd!=-1)
    {
        qDebug("is aready opened!");
        return false;
    }
    rev_buf->clear();
    Ridx=0;
    Sidx=0xff;
    send_buf->clear();
    memset(&new_serialArry,0,sizeof new_serialArry);
    m_fd=::open(portName.toLatin1(),O_RDWR|O_NONBLOCK);
    if( m_fd==-1)
    {
        qDebug("serial port  open erro!");

        return false;
    }

    switch(baundRate)
    {

    case 0:
        new_serialArry.c_cflag |=  B600;
        break;
    case 1:
        new_serialArry.c_cflag |=  B1200;
        break;
    case 2:
        new_serialArry.c_cflag |=  B2400;
        break;
    case 3:
        new_serialArry.c_cflag |=  B4800;
        break;
    case 4:
        new_serialArry.c_cflag |=  B9600;
        break;
    case 5:
        new_serialArry.c_cflag |=  B19200;
        break;
    case 6:
        new_serialArry.c_cflag |=  B38400;
        break;
    case 7:
        new_serialArry.c_cflag |=  B57600;
        break;
    case 8:
        new_serialArry.c_cflag |=  B115200;
        break;
    default:
        new_serialArry.c_cflag |=  B9600;
        break;
    }

    switch(dataBits)
    {
    case 3:
        new_serialArry.c_cflag|=CS5;
        break;
    case 2:
        new_serialArry.c_cflag|=CS6;
        break;
    case 1:
        new_serialArry.c_cflag|=CS7;
        break;
    case 0:
        new_serialArry.c_cflag|=CS8;
        break;
    default:
        new_serialArry.c_cflag|=CS8;
        break;
    }

    switch (parity)
    {

    case 0:
        new_serialArry.c_cflag &= (~PARENB);
        break;
    case 2:
        new_serialArry.c_cflag &= (~PARODD);
        new_serialArry.c_cflag |= PARENB;
        break;
    case 1:
        new_serialArry.c_cflag |= (PARODD|PARENB);
        break;
    default:
        break;
    }


    switch(stopBits)
    {
    case 0:
        new_serialArry.c_cflag &=(~CSTOPB);
        break;
    case 1:
        break;
    case 2:
        new_serialArry.c_cflag |=CSTOPB;
        break;
    default:
        new_serialArry.c_cflag &=(~CSTOPB);
        break;
    }

    switch(flow)
    {
    case 0:
        new_serialArry.c_cflag &=(~CRTSCTS);
        new_serialArry.c_iflag &=(~(IXON|IXOFF|IXANY));
        break;
    case 2:
        new_serialArry.c_cflag &=(~CRTSCTS);
        new_serialArry.c_iflag |=(IXON|IXOFF|IXANY);
        break;
    case 1:
        new_serialArry.c_cflag |=~CRTSCTS;
        new_serialArry.c_iflag &=(~(IXON|IXOFF|IXANY));
        break;
    default:
        break;
    }

    new_serialArry.c_oflag=0;
    new_serialArry.c_cc[VTIME]=time_out/100;
    tcflush(m_fd,TCIFLUSH);
    tcsetattr(m_fd,TCSANOW,&new_serialArry);

    //m_notifier= new QSocketNotifier(m_fd,QSocketNotifier::Read,0);
    //connect(m_notifier,SIGNAL(activated(int)),this,SLOT(remoteDateInComing()));

    return true;

}

//232(1)
bool PrintPort::openPort1(QString portName, uchar baundRate, uchar dataBits,
                          uchar parity, uchar stopBits, uchar flow, int time_out)
{

    if(m_fd1!=-1)
    {
        qDebug("is aready opened!");
        return false;
    }

    m_fd1=::open(portName.toLatin1(),O_RDWR|O_NONBLOCK);
    if( m_fd1==-1)
    {
        qDebug("serial port  open erro!");

        return false;
    }


    uart1_init(baundRate,dataBits,parity,stopBits,flow,time_out);

    m_notifier1= new QSocketNotifier(m_fd1,QSocketNotifier::Read,0);
    if(CommType==1)
        connect(m_notifier1,SIGNAL(activated(int)),this,SLOT(RdReturnData()));
    return true;

}

void PrintPort::Uart1Recv()
{
    if(CommType==1)
        connect(m_notifier1,SIGNAL(activated(int)),this,SLOT(RdReturnData()));
    else if(CommType==0)
        disconnect(m_notifier1,SIGNAL(activated(int)),this,SLOT(RdReturnData()));
}

//232(2)
bool PrintPort::openPort2(QString portName, uchar baundRate, uchar dataBits,
                          uchar parity, uchar stopBits, uchar flow, int time_out)
{

    if(m_fd2!=-1)
    {
        qDebug("is aready opened!");
        return false;
    }

    m_fd2=::open(portName.toLatin1(),O_RDWR|O_NONBLOCK);
    if( m_fd2==-1)
    {
        qDebug("serial port  open erro!");

        return false;
    }


    uart2_init(baundRate,dataBits,parity,stopBits,flow,time_out);


    return true;

}
//485 port
bool PrintPort::openPort3(QString portName, uchar baundRate, uchar dataBits,
                          uchar parity, uchar stopBits, uchar flow, int time_out)
{

    if(m_fd3!=-1)
    {
        qDebug("is aready opened!");
        return false;
    }
    
    memset(&new_serialArry3,0,sizeof new_serialArry3);
    m_fd3=::open(portName.toLatin1(),O_RDWR|O_NONBLOCK);
    if( m_fd3==-1)
    {
        qDebug("serial port  open erro!");

        return false;
    }


    uart3_init(baundRate,dataBits,parity,stopBits,flow,time_out);
    m_notifier= new QSocketNotifier(m_fd3,QSocketNotifier::Read,0);
    connect(m_notifier,SIGNAL(activated(int)),this,SLOT(remoteDateInComing()));

    

    return true;

}

bool PrintPort::openPort_Rd(QString portName, uchar baundRate, uchar dataBits,
                            uchar parity, uchar stopBits, uchar flow, int time_out)
{


    if(m_fd1!=-1)
    {
        qDebug("is aready opened!");
        return false;
    }

    m_fd1=::open(portName.toLatin1(),O_RDWR|O_NONBLOCK);
    if( m_fd1==-1)
    {
        qDebug("serial port  open erro!");

        return false;
    }


    uart1_init(baundRate,dataBits,parity,stopBits,flow,time_out);


    
    m_notifier1= new QSocketNotifier(m_fd1,QSocketNotifier::Read,0);
    connect(m_notifier1,SIGNAL(activated(int)),this,SLOT(RdReturnData()));

    

    return true;

}


//232(1)
void PrintPort::uart1_init(uchar baundRate,uchar dataBits,uchar parity,
                           uchar stopBits, uchar flow ,int time_out)
{
    memset(&new_serialArry1,0,sizeof new_serialArry1);

    switch(baundRate)
    {

    case 0:
        new_serialArry1.c_cflag |=  B600;
        break;
    case 1:
        new_serialArry1.c_cflag |=  B1200;
        break;
    case 2:
        new_serialArry1.c_cflag |=  B2400;
        break;
    case 3:
        new_serialArry1.c_cflag |=  B4800;
        break;
    case 4:
        new_serialArry1.c_cflag |=  B9600;
        break;
    case 5:
        new_serialArry1.c_cflag |=  B19200;
        break;
    case 6:
        new_serialArry1.c_cflag |=  B38400;
        break;
    case 7:
        new_serialArry1.c_cflag |=  B57600;
        break;
    case 8:
        new_serialArry1.c_cflag |=  B115200;
        break;
    default:
        new_serialArry1.c_cflag |=  B9600;
        break;
    }

    switch(dataBits)
    {
    case 3:
        new_serialArry1.c_cflag|=CS5;
        break;
    case 2:
        new_serialArry1.c_cflag|=CS6;
        break;
    case 1:
        new_serialArry1.c_cflag|=CS7;
        break;
    case 0:
        new_serialArry1.c_cflag|=CS8;
        break;
    default:
        new_serialArry1.c_cflag|=CS8;
        break;
    }

    switch (parity)
    {

    case 0:
        new_serialArry1.c_cflag &= (~PARENB);
        break;
    case 2:
        new_serialArry1.c_cflag &= (~PARODD);
        new_serialArry1.c_cflag |= PARENB;
        break;
    case 1:
        new_serialArry1.c_cflag |= (PARODD|PARENB);
        break;
    default:
        break;
    }


    switch(stopBits)
    {
    case 0:
        new_serialArry1.c_cflag &=(~CSTOPB);
        break;
    case 1:
        break;
    case 2:
        new_serialArry1.c_cflag |=CSTOPB;
        break;
    default:
        new_serialArry1.c_cflag &=(~CSTOPB);
        break;
    }

    switch(flow)
    {
    case 0:
        new_serialArry1.c_cflag &=(~CRTSCTS);
        new_serialArry1.c_iflag &=(~(IXON|IXOFF|IXANY));
        break;
    case 2:
        new_serialArry1.c_cflag &=(~CRTSCTS);
        new_serialArry1.c_iflag |=(IXON|IXOFF|IXANY);
        break;
    case 1:
        new_serialArry1.c_cflag |=~CRTSCTS;
        new_serialArry1.c_iflag &=(~(IXON|IXOFF|IXANY));
        break;
    default:
        break;
    }

    new_serialArry1.c_oflag=0;
    new_serialArry1.c_cc[VTIME]=time_out/100;
    tcflush(m_fd1,TCIFLUSH);
    tcsetattr(m_fd1,TCSANOW,&new_serialArry1);

}


//232(2)
void PrintPort::uart2_init(uchar baundRate,uchar dataBits,uchar parity,
                           uchar stopBits, uchar flow ,int time_out)
{
    memset(&new_serialArry2,0,sizeof new_serialArry2);

    switch(baundRate)
    {

    case 0:
        new_serialArry2.c_cflag |=  B600;
        break;
    case 1:
        new_serialArry2.c_cflag |=  B1200;
        break;
    case 2:
        new_serialArry2.c_cflag |=  B2400;
        break;
    case 3:
        new_serialArry2.c_cflag |=  B4800;
        break;
    case 4:
        new_serialArry2.c_cflag |=  B9600;
        break;
    case 5:
        new_serialArry2.c_cflag |=  B19200;
        break;
    case 6:
        new_serialArry2.c_cflag |=  B38400;
        break;
    case 7:
        new_serialArry2.c_cflag |=  B57600;
        break;
    case 8:
        new_serialArry2.c_cflag |=  B115200;
        break;
    default:
        new_serialArry2.c_cflag |=  B9600;
        break;
    }

    switch(dataBits)
    {
    case 3:
        new_serialArry2.c_cflag|=CS5;
        break;
    case 2:
        new_serialArry2.c_cflag|=CS6;
        break;
    case 1:
        new_serialArry2.c_cflag|=CS7;
        break;
    case 0:
        new_serialArry2.c_cflag|=CS8;
        break;
    default:
        new_serialArry2.c_cflag|=CS8;
        break;
    }

    switch (parity)
    {

    case 0:
        new_serialArry2.c_cflag &= (~PARENB);
        break;
    case 2:
        new_serialArry2.c_cflag &= (~PARODD);
        new_serialArry2.c_cflag |= PARENB;
        break;
    case 1:
        new_serialArry2.c_cflag |= (PARODD|PARENB);
        break;
    default:
        break;
    }


    switch(stopBits)
    {
    case 0:
        new_serialArry2.c_cflag &=(~CSTOPB);
        break;
    case 1:
        break;
    case 2:
        new_serialArry2.c_cflag |=CSTOPB;
        break;
    default:
        new_serialArry2.c_cflag &=(~CSTOPB);
        break;
    }

    switch(flow)
    {
    case 0:
        new_serialArry2.c_cflag &=(~CRTSCTS);
        new_serialArry2.c_iflag &=(~(IXON|IXOFF|IXANY));
        break;
    case 2:
        new_serialArry2.c_cflag &=(~CRTSCTS);
        new_serialArry2.c_iflag |=(IXON|IXOFF|IXANY);
        break;
    case 1:
        new_serialArry2.c_cflag |=~CRTSCTS;
        new_serialArry2.c_iflag &=(~(IXON|IXOFF|IXANY));
        break;
    default:
        break;
    }

    new_serialArry2.c_oflag=0;
    new_serialArry2.c_cc[VTIME]=time_out/100;
    tcflush(m_fd2,TCIFLUSH);
    tcsetattr(m_fd2,TCSANOW,&new_serialArry2);

}


//485 PORT
void PrintPort::uart3_init(uchar baundRate,uchar dataBits,uchar parity,
                           uchar stopBits, uchar flow ,int time_out)
{
    memset(&new_serialArry3,0,sizeof new_serialArry3);

    switch(baundRate)
    {
    
    case 0:
        new_serialArry3.c_cflag |=  B600;
        RS485_DELAY_US  = 20000;
        //char_interval_timeout = TO_B600;
        break;
    case 1:
        new_serialArry3.c_cflag |=  B1200;
        RS485_DELAY_US = 10000;
        //char_interval_timeout = TO_B1200;
        break;
    case 2:
        new_serialArry3.c_cflag |=  B2400;
        //char_interval_timeout = TO_B2400;
        RS485_DELAY_US = 5000;
        break;
    case 3:
        new_serialArry3.c_cflag |=  B4800;
        //char_interval_timeout = TO_B4800;
        RS485_DELAY_US = 2500;
        break;
    case 4:
        new_serialArry3.c_cflag |=  B9600;
        RS485_DELAY_US = 1250;
        //char_interval_timeout = TO_B9600;
        break;
    case 5:
        new_serialArry3.c_cflag |=  B19200;
        //char_interval_timeout = TO_B19200;
        RS485_DELAY_US = 625;
        break;
    case 6:
        new_serialArry3.c_cflag |=  B38400;
        //char_interval_timeout = TO_B38400;
        RS485_DELAY_US = 313;
        break;
    case 7:
        new_serialArry3.c_cflag |=  B57600;
        RS485_DELAY_US = 209;
        //char_interval_timeout = TO_B57600;
        break;
    case 8:
        new_serialArry3.c_cflag |=  B115200;
        //char_interval_timeout = TO_B115200;
        RS485_DELAY_US = 87;
        break;
    default:
        new_serialArry3.c_cflag |=  B9600;
        RS485_DELAY_US = 1250;
        //char_interval_timeout = TO_B9600;
        break;
    }

    switch(dataBits)
    {
    case 3:
        new_serialArry3.c_cflag|=CS5;
        break;
    case 2:
        new_serialArry3.c_cflag|=CS6;
        break;
    case 1:
        new_serialArry3.c_cflag|=CS7;
        break;
    case 0:
        new_serialArry3.c_cflag|=CS8;
        break;
    default:
        new_serialArry3.c_cflag|=CS8;
        break;
    }

    switch (parity)
    {

    case 0:
        new_serialArry3.c_cflag &= (~PARENB);
        break;
    case 2:
        new_serialArry3.c_cflag &= (~PARODD);
        new_serialArry3.c_cflag |= PARENB;
        break;
    case 1:
        new_serialArry3.c_cflag |= (PARODD|PARENB);
        break;
    default:
        break;
    }


    switch(stopBits)
    {
    case 0:
        new_serialArry3.c_cflag &=(~CSTOPB);
        break;
    case 1:
        break;
    case 2:
        new_serialArry3.c_cflag |=CSTOPB;
        break;
    default:
        new_serialArry3.c_cflag &=(~CSTOPB);
        break;
    }

    switch(flow)
    {
    case 0:
        new_serialArry3.c_cflag &=(~CRTSCTS);
        new_serialArry3.c_iflag &=(~(IXON|IXOFF|IXANY));
        break;
    case 2:
        new_serialArry3.c_cflag &=(~CRTSCTS);
        new_serialArry3.c_iflag |=(IXON|IXOFF|IXANY);
        break;
    case 1:
        new_serialArry3.c_cflag |=~CRTSCTS;
        new_serialArry3.c_iflag &=(~(IXON|IXOFF|IXANY));
        break;
    default:
        break;
    }

    new_serialArry3.c_oflag=0;
    new_serialArry3.c_cc[VTIME]=time_out/100;
    tcflush(m_fd3,TCIFLUSH);
    tcsetattr(m_fd3,TCSANOW,&new_serialArry3);

}

void PrintPort::remoteDateInComing1()
{
    unsigned char c;
    int i;
    int data_avail = TRUE;
    int read_stat;
    //int rxchar = PORT_FAILURE;
    fd_set rfds;
    QString str;
    struct timeval tv;
    int n=0;

    qDebug() << "333" << endl;
    ::read(m_fd2,&c,1);
    if(c==0x02)
        Ridx2=0;
    else if(c==0x03)
    {
        for(i=0;i<Ridx2;i++)
        {
            QrRecvBuff[i]=RecvBuff2[i];
            Qrstr[i]=RecvBuff2[i];
            qDebug() << "QrRecvBuff=" <<QrRecvBuff[i]<< endl;

        }
        // str = QString(QLatin1String(QrRecvBuff));
        qDebug() << "Qrstr=" <<Qrstr<< endl;

        QrRidx=Ridx2;
        qDebug() << "QrRidx=" <<QrRidx<< endl;
        Ridx2=0;
        emit hasdata();
        b_Comr=1;
    }
    else
    {
        RecvBuff2[Ridx2]=c;                                           //
        Ridx2++;                                                     //
        if(Ridx2>46)Ridx2=19;
    }

    if(Ridx2>0)
    {




    }
}


void PrintPort::remoteDateInComing()
{
    int receive_length;
    //if(b_Comr)return;
    receive_length=receive_response( RecvBuff3,m_fd3,4);
    if(receive_length)
    {
        Ridx3=receive_length;

        printf("receive_length=%d\n    ", receive_length);
        b_Comr=1;
        emit hasdata();
    }


}

void PrintPort::RdReturnData()
{
    int receive_length;
    int i;
    //if(b_Comr)return;
    memset(CodeRecvBuff,0,99);
    receive_length=receive_response( RecvBuff1,m_fd1,8);
    if(receive_length)
    {
        Ridx1=receive_length;
        CodeLength=receive_length;
        QString str="";
        for(i=0;i<Ridx1;i++)
        {
            CodeRecvBuff[i]=RecvBuff1[i];
            qDebug() << "CodeRecvBuff=" <<CodeRecvBuff[i]<< endl;
            if (i<Ridx1-1)
            {
                str+=CodeRecvBuff[i];
            }

        }
        printf("receive_length=%d\n    ", receive_length);
        QRcodeTemp="";

        //string str+=QString::number(buf[i]);
        //std::string str = (char*)CodeRecvBuff;
        QRcodeTemp = str;
        qDebug()<<"QRcodeTemp+++++++++++++++++++++=="<<QRcodeTemp;
        if ((QRcodeTemp.length()==18)&&(QRcodeTemp.at(0)=='1')&&((QRcodeTemp.at(1)=='0')||(QRcodeTemp.at(1)=='1')||
                                                                 (QRcodeTemp.at(1)=='2')||(QRcodeTemp.at(1)=='3')||
                                                                 (QRcodeTemp.at(1)=='4')||(QRcodeTemp.at(1)=='5')
                                                                 ))
        {
            QRcodeType = 1;//?????
        }
        else if (((QRcodeTemp.length()==16)||(QRcodeTemp.length()==17)||(QRcodeTemp.length()==18)||(QRcodeTemp.length()==19)||
                 (QRcodeTemp.length()==20)||(QRcodeTemp.length()==21)||(QRcodeTemp.length()==22)||(QRcodeTemp.length()==23)||
                  (QRcodeTemp.length()==24))&&(((QRcodeTemp.at(0)=='2')&&(QRcodeTemp.at(1)=='5'))||((QRcodeTemp.at(0)=='3')&&(QRcodeTemp.at(1)=='0'))
                                               ||((QRcodeTemp.at(0)=='2')&&(QRcodeTemp.at(1)=='6'))||((QRcodeTemp.at(0)=='2')&&(QRcodeTemp.at(1)=='7'))
                                               ||((QRcodeTemp.at(0)=='2')&&(QRcodeTemp.at(1)=='8'))||((QRcodeTemp.at(0)=='2')&&(QRcodeTemp.at(1)=='9'))))
        {
            QRcodeType = 2;//??????
        }
        else
        {
            QRcodeType = 0;//???
        }
        emit hasCodeData();
    }
}
bool PrintPort::uart3_close()
{
    mutex_r3.lock();

    if(m_fd3!=-1)
    {
        disconnect(m_notifier,SIGNAL(activated(int)),this,SLOT(remoteDateInComing()));
        delete m_notifier;
        m_fd3=-1;
        mutex_r3.unlock();
        return true;
    }
    mutex_r3.unlock();
    return false;
}

/***********************************************************************

    receive_response( array_for_data )

   Function to monitor for the reply from the modbus slave.
   This function blocks for timeout seconds if there is no reply.

   Returns:	Total number of characters received.
***********************************************************************/

int PrintPort::receive_response(  unsigned char *received_string, int ttyfd, uchar baundRate )
{

    int rxchar = PORT_FAILURE;
    int data_avail = FALSE;
    int bytes_received = 0;
    int read_stat;

    int timeout = 1;			/* 1 second */



    fd_set rfds;

    struct timeval tv;

    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    FD_ZERO( &rfds );
    FD_SET( ttyfd, &rfds );





    //data_avail = select( FD_SETSIZE, &rfds, NULL, NULL, &tv );
    data_avail = select(ttyfd+1, &rfds, NULL, NULL, &tv);

    if( !data_avail )
    {
        bytes_received = 0;
        //fprintf( stderr, "Comms time out\n" );
    }

    switch(baundRate)
    {
    
    case 0:
        
        char_interval_timeout = TO_B600;
        break;
    case 1:

        char_interval_timeout = TO_B1200;
        break;
    case 2:
        
        char_interval_timeout = TO_B2400;

        break;
    case 3:
        
        char_interval_timeout = TO_B4800;

        break;
    case 4:

        char_interval_timeout = TO_B9600;
        break;
    case 5:
        
        char_interval_timeout = TO_B19200;

        break;
    case 6:

        char_interval_timeout = TO_B38400;

        break;
    case 7:
        
        char_interval_timeout = TO_B57600;
        break;
    case 8:
        
        char_interval_timeout = TO_B115200;

        break;
    default:
        
        char_interval_timeout = TO_B9600;

        break;
    }
    tv.tv_sec = 0;
    tv.tv_usec = char_interval_timeout;

    FD_ZERO( &rfds );
    FD_SET( ttyfd, &rfds );

    while( data_avail )
    {

        /* if no character at the buffer wait char_interval_timeout */
        /* before accepting end of response			    */

        if( select( FD_SETSIZE, &rfds, NULL, NULL, &tv ) )
        {
            read_stat = ::read( ttyfd, &rxchar, 1 );

            if( read_stat < 0 )
            {
                bytes_received = PORT_FAILURE;
                data_avail = FALSE;
            }
            else
            {
                rxchar = rxchar & 0xFF;
                received_string[ bytes_received ++ ] = rxchar;
                printf("RecvBuff[%d]=%x    ", (bytes_received-1), rxchar);
                //printf("%d\n", (bytes_received-1));
                //printf("%x\n", rxchar);
            }


            if( bytes_received >= MAX_RESPONSE_LENGTH )
            {
                bytes_received = PORT_FAILURE;
                data_avail = FALSE;
            }

            /* display the hex code of each character received */
            //fprintf( stderr, "<%0.2X>", rxchar );


        }
        else
        {
            data_avail = FALSE;
        }

    }


    /*#ifdef DEBUG
    fprintf( stderr, "\n" );
#endif*/

    /*if( bytes_received > 2 )
    {
        bytes_received -= 2;
    }*/


    return( bytes_received );
}



//close
/*bool PrintPort::close()
{
    mutex_r.lock();

    if(m_fd!=-1)
    {
        disconnect(m_notifier,SIGNAL(activated(int)),this,SLOT(remoteDateInComing()));
        delete m_notifier;
        m_fd=-1;
        mutex_r.unlock();
        return true;
    }
    mutex_r.unlock();
    return false;
}*/
//recive data
/*void PrintPort::remoteDateInComing()
{

   // unsigned char c[1024];
    if(b_Comr||(control_485==1))return;
    int n= ::read(m_fd,&RecvBuff,256);
    
    mutex_r.lock();
    for(int i=0;i<n;i++)
    {
        rev_buf->append(RecvBuff[i]);

    }
    mutex_r.unlock();
    Ridx=n;
    b_Comr=1;
    emit hasdata();


}*/
//write data

void PrintPort::printwriteLP180()
{
    b_Print1=1;
    if(b_PrintStable)
    {
        if(!b_Stable)
        {
            b_Print1=0;
            return;
        }
    }
    b_Print1=0;

    /*if(b_Save==1)
        {
        b_Print1=0;
        return;
        }*/
    if((b_PrintRetZero&&!b_Ydy1)||(!b_PrintRetZero))
    {

        if(m_fd2!=-1)
        {
            qDebug() << "180" << endl;
            Print_initialLP180();
            PrintAccLP180();
            ::write(m_fd2, Init_GapLP180,10);
            b_Ydy1=1;
        }


        b_Print1=0;
    }
    // return sendByteArray;
}
void PrintPort::printwrite()//zw
{
    b_Print=1;
    if(b_PrintStable)
    {
        if(!b_Stable)
        {
            b_Print=0;
            return;
        }
    }
    //unsigned char ucTNumb;
    //unsigned char SendBuff[100];
    //QByteArray sendByteArray;
    //ucTNumb = loadZMComuData(&SendBuff[0]);
    uchar i;
    QTime current_time = QTime::currentTime();
    QDate current_date= QDate::currentDate();
    QDateTime time = QDateTime::currentDateTime();
    

    RecTimeLimit.Year   = (current_date.year())%100;
    RecTimeLimit.Month  = current_date.month();
    RecTimeLimit.Day= current_date.day();

    RecTimeLimit.Hour= current_time.hour();
    RecTimeLimit.Minute= current_time.minute();
    RecTimeLimit.Second= current_time.second();
    if(b_Save)

    {
        if((b_PrintRetZero&&!b_Ylj)||(!b_PrintRetZero))

        {
            if(sam==0)
            {
                Totfa+=Net;
                Totfn++;
                b_Ylj=1;
                LastWt=Net;
                LastTime=time.toTime_t();
                QString Wt="baseinfo/Wt";
                QString WtTime="baseinfo/WtTime";
                Wt+=QString::number(Totfn);
                WtTime+=QString::number(Totfn);
                QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
                configIniRead->setValue("baseinfo/Totfa",Totfa);
                configIniRead->setValue("baseinfo/Totfn",Totfn);
                configIniRead->setValue("baseinfo/LastWt",LastWt);
                configIniRead->setValue("baseinfo/LastTime",LastTime);
                configIniRead->setValue(Wt,LastWt);
                configIniRead->setValue(WtTime,LastTime);
                delete configIniRead;
            }
            else
            {
                Totfac+=CountNet;
                Totfnc++;
                b_Ylj=1;

                QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
                configIniRead->setValue("baseinfo/Totfac",Totfac);
                configIniRead->setValue("baseinfo/Totfnc",Totfnc);
                delete configIniRead;
            }

        }
    }

    if(b_Save==1)
    {
        b_Print=0;
        return;
    }
    if((b_PrintRetZero&&!b_Ydy)||(!b_PrintRetZero))
    {
        PIN_PB25_H;
        usleep(1000000);
        //mutex_r.lock();
        //int ret;
        //ret=0;
        if(m_fd!=-1)
        {

            Print_initial2();
            PrintAcc();
            b_Ydy=1;
        }

        //mutex_r.unlock();
        for(i=0;i<3;i++)
            usleep(2000000);
        PIN_PB25_L;
        b_Print=0;
    }
    // return sendByteArray;
}


void PrintPort::printwrite2()
{
    //unsigned char ucTNumb;
    //unsigned char SendBuff[100];
    //QByteArray sendByteArray;
    //ucTNumb = loadZMComuData(&SendBuff[0]);
    uchar i;
    int j;
    b_Print=1;
    PIN_PB25_H;
    usleep(1000000);
    mutex_r.lock();
    int ret;
    //ret=0;
    
    if(m_fd!=-1)
    {
        //Print_initial2();
        PrintBusiness1();
    }

    mutex_r.unlock();
    if(productCashNum==0)
        j=3;
    else
        j=3+productCashNum;
    for(i=0;i<j;i++)
        usleep(2000000);
    PIN_PB25_L;
    b_Print=0;

    // return sendByteArray;
}


void PrintPort::Print_initial2(void)  
{


    ::write(m_fd, Init_Printer,10);  //
    if(PrintLableSize==1)

    {
        ::write(m_fd, Init_Potency,3);  //
    }
    //msleep(10);		   													 //
    //::write(m_fd, Enter_key,2);  //
    //msleep(10);
}

void PrintPort::Print_initialLP180(void)  
{


    ::write(m_fd2, Init_PrinterLP180,4);  //

    ::write(m_fd2, Init_LabelLP180,10);  //

    ::write(m_fd2, Init_WidthLP180,4);

    ::write(m_fd2, Init_PositionLP180,4);
}

void PrintPort::Print_initial(void)  
{

}


void PrintPort::Print_StringLP180(const char str[],unsigned char n)               //
{unsigned char i;                                                    //

    //
    for(i=0;i<n;i++) SendBuff2[i]=str[i];								 //
    //
    //SendBuff[i]=0xff;												 //
    // Sidx=0;                                                           //
    ::write(m_fd2, SendBuff2,n);  //												 //
}
///////////////////////////////////////////////////////////////////////
//                   //
///////////////////////////////////////////////////////////////////////

void PrintPort::Print_String(const char str[],unsigned char n)               //
{unsigned char i;                                                    //

    //
    for(i=0;i<n;i++) SendBuff[i]=str[i];								 //
    //
    //SendBuff[i]=0xff;												 //
    // Sidx=0;                                                           //
    ::write(m_fd, SendBuff,n);  //												 //
}


void PrintPort::Print_String1LP180(QString str)               //
{//unsigned char i;                                                    //

    //QString  str;
    const char*  ch;
    std::string st=str.toStdString();
    ch=st.c_str();
    //QByteArray ba = str.toLatin1(); // must
    //ch=ba.data();													 //
    //
    ::write(m_fd2, ch,strlen(ch));  //												 //
}
void PrintPort::Print_String1(QString str)               //
{//unsigned char i;                                                    //

    //QString  str;
    const char*  ch;
    std::string st=str.toStdString();
    ch=st.c_str();
    //QByteArray ba = str.toLatin1(); // must
    //ch=ba.data();													 //
    //
    ::write(m_fd, ch,strlen(ch));  //												 //
}

uchar PrintPort::QstringLength(QString str)

{
    uchar n;
    const char*  ch;
    std::string st=str.toStdString();
    ch=st.c_str();
    n=strlen(ch);
    return n;
}
void PrintPort::Print_String3(QString str,uchar n)

{
    uchar i;
    const char*  ch;
    std::string st=str.toStdString();
    ch=st.c_str();
    //QByteArray ba = str.toLatin1(); // must
    //ch=ba.data();													 //
    if(strlen(ch)<=n)
    {
        for(i=0;i<(n-strlen(ch));i++)
            str+=" ";
        std::string st=str.toStdString();
        ch=st.c_str();
        ::write(m_fd, ch,n);  //
    }

}
/*void PrintPort::Print_String1(QString str)               //
{unsigned char i;                                                    //

            //QString  str;
char*  ch;
QByteArray ba = str.toLatin1(); // must
ch=ba.data();													 //
                                            //

  ::write(m_fd, ch,strlen(ch));  //
   qDebug() <<"ch"<<ch;//
 }	*/



void PrintPort::Print_String2(float ft)               //
{//unsigned char i;                                                    //
    QString data = QString("%1").arg(ft);
    //QString  str;
    Print_String1(data);								 //
}


void PrintPort::Print_Send0LP180(unsigned char ch,uchar n)                                   //
{																	 //
    uchar i;														 //
    for(i=0;i<n;i++)
        SendBuff2[i]=ch;													 //
    //SendBuff[1]=0xff;													 //
    ::write(m_fd2, SendBuff2,n); 											 //
}	
///////////////////////////////////////////////////////////////////////
//                                     //
///////////////////////////////////////////////////////////////////////
void PrintPort::Print_Send0(unsigned char ch,uchar n)                                   //
{																	 //
    uchar i;														 //
    for(i=0;i<n;i++)
        SendBuff[i]=ch;													 //
    //SendBuff[1]=0xff;													 //
    ::write(m_fd, SendBuff,n); 											 //
}																	 //

void PrintPort::PrintBusiness()	
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    qDebug() << "printbusiness" << endl;
    PrintCompany();
    ::write(m_fd, Init_Printer,7);  //
    // Print_initial2();
    //
    //::write(m_fd, Enter_key,2);  //
    Print_String("商品    单价  净重   金额     ",30);
    Print_Send0(0x0A,1);
    Print_String("=========================          ",24);
    //Print_String("商品       ",8);
    Print_Send0(0x0A,1);
    for(int i = 0; i < productCashNum; i++)
    {
        //productInforCash[i].productCash.productPrice

        Print_String1(productInforCash[i].productCash.productName);
        //Print_Send0(0x20);
        Print_Send0(0x20,4);
        Print_String2(productInforCash[i].productCash.productPrice);
        //Print_Send0(0x20);
        Print_Send0(0x20,4);

        Print_String2(productInforCash[i].weight);
        //Print_Send0(0x20);
        Print_Send0(0x20,4);

        Print_String2(productInforCash[i].money);
        //Print_Send0(0x20);
        Print_Send0(0x20,4);
        // qDebug() <<"a"<<productInfor[i].productCode;
        qDebug() <<"b"<<productInforCash[i].productCash.productName;
        qDebug() <<"c"<<productInforCash[i].productCash.productPrice;
        //qDebug() <<"d"<<productInfor[i].productOrigin;
        //qDebug() <<"productInfor[i].productDescribe"<<productInfor[i].productDescribe;
        qDebug() << "333" << endl;
        Print_Send0(0x0A,1);
    }
    Print_String("=========================          ",24);
    Print_Send0(0x0A,1);
    Print_String("总金额 :    ",12);
    Print_String2(totalmoney_print);
    totalmoney_print=0;
    // ::write(m_fd, Enter_key,2); //
    Print_Send0(0x0A,1);
    qDebug()<<"PrintLableSize"<<PrintLableSize;
    //usleep(100);
    if(PrintLableSize==0)

        ::write(m_fd, Enter_key1,2);
    else
        Print_Send0(0x0A,2);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese

}


void PrintPort::PrintBusiness1()	
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    qDebug() << "printbusiness" << endl;

    QDateTime dateTime;
    QString dateTime_str = dateTime.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    uchar pUnit[2];
    int l;
    //QString temp="";
    // CompanyTel="021-67282800";
    switch(Unit)                                                     //单位
    {																 //
    /*case 0: pUnit[0]='k';
         pUnit[1]='g';
              break;*/                                                 //
    case 1: pUnit[0]='k';
        pUnit[1]='g';                                              //g
        break;                                                 //
    case 2: pUnit[0]='l';
        pUnit[1]='b';                                           //t
        break;                                                 //
    case 3: pUnit[0]=0x20;
        pUnit[1]='g';                                             //lb
        break;                                                 //
    default:pUnit[0]='k';
        pUnit[1]='g';                                             //kg
        break;													 //
    }
    //PrintCompany();
    ::write(m_fd, Init_Printer,10);  //

    ::write(m_fd, Init_Potency,3);  //
    ::write(m_fd, Init_Middle,3);
    Print_String1(PrintCompanyName);
    Print_Send0(0x0d,1);

    ::write(m_fd, Init_Printer,10);  //
    ::write(m_fd, Init_Potency,3);  //
    ::write(m_fd, Init_Left,3);
    Print_String("时间:",5);
    Print_String1(dateTime_str);
    Print_Send0(0x0A,1);
    Print_String("电话:",5);
    Print_String1(CompanyTel);
    Print_Send0(0x0A,1);
    Print_String("==== ==== ==== ==== ====  ====        ",24);
    Print_Send0(0x0A,1);
    ::write(m_fd, Init_Table,7);  //
    Print_Send0(0x09,1);
    Print_String("商品",4);
    Print_Send0(0x09,1);
    Print_String("净重",4);
    Print_Send0(0x28,1);
    ::write(m_fd,  pUnit,2);  //
    Print_Send0(0x29,1);
    Print_Send0(0x09,1);
    Print_String("单价",4);
    Print_Send0(0x09,1);  //
    Print_String("金额(元)",8);
    //Print_Send0(0x09,1);  //
    Print_Send0(0x0A,1);


    for(int i = 0; i < productCashNum; i++)
    {
        //productInforCash[i].productCash.productPrice
        ::write(m_fd, Init_Table,7);  //
        Print_Send0(0x09,1);
        Print_String1(productInforCash[i].productCash.productName);
        //Print_Send0(0x20);
        Print_Send0(0x09,1);
        Print_String2(productInforCash[i].productCash.productPrice);
        //Print_Send0(0x20);
        Print_Send0(0x09,1);

        Print_String2(productInforCash[i].weight);
        //Print_Send0(0x20);
        Print_Send0(0x09,1);

        Print_String2(productInforCash[i].money);
        //Print_Send0(0x20);
        // Print_Send0(0x20,4);
        // qDebug() <<"a"<<productInfor[i].productCode;
        qDebug() <<"b"<<productInforCash[i].productCash.productName;
        qDebug() <<"c"<<productInforCash[i].productCash.productPrice;
        //qDebug() <<"d"<<productInfor[i].productOrigin;
        //qDebug() <<"productInfor[i].productDescribe"<<productInfor[i].productDescribe;
        qDebug() << "333" << endl;
        Print_Send0(0x0A,1);
    }
    ::write(m_fd, Init_Printer,10);  //
    ::write(m_fd, Init_Potency,3);  //
    Print_String("==== ==== ==== ==== ====  ====        ",24);
    Print_Send0(0x0A,1);
    // ::write(m_fd, Init_Printer2,7);  //
    Print_String("总金额 :    ",7);
    Print_String2(totalmoney_print);
    Print_String("(元)",4);
    Print_Send0(0x0A,1);
    Print_String("谢谢惠顾，欢迎再次光临!   ",24);
    // totalmoney_print=0;
    // ::write(m_fd, Enter_key,2); //
    Print_Send0(0x0A,2);
    //qDebug()<<"PrintLableSize"<<PrintLableSize;
    //usleep(100);
    ::write(m_fd, Init_Middle,3);
    ::write(m_fd, Init_Qr1,3);
    /*l=strlen(Yaohua)+2;
    qDebug()<<"l="<<l;
    Print_Send0(l,1);
    Print_Send0(0,3);
       ::write(m_fd, Yaohua,strlen(Yaohua)); */
    l=QstringLength(CompanyWebsite)+2;
    qDebug()<<"l="<<l;
    Print_Send0(l,1);
    Print_Send0(0,3);
    Print_String1(CompanyWebsite);
    //::write(m_fd, Enter_key,2);
    Print_Send0(0x0A,3);

    Print_Send0(0x0A,2);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese

}

///////////////////////////////////////////////////////////////////////
//                                                        //
///////////////////////////////////////////////////////////////////////
void PrintPort::PrintCompany()
{
    Print_initial2();
    //msleep(10);		   													 //
    //::write(m_fd, Enter_key,2);  //
    //Print_Send0(0x0A,1);
    //msleep(10);

    ::write(m_fd, Init_Middle,3);
    Print_String1(PrintCompanyName);
    Print_Send0(0x0D,1);



}

void PrintPort::PrintUserReport()
{
    uchar i;
    b_Print=1;
    PIN_PB25_H;
    usleep(1000000);
    

    

    uchar pUnit[2];
    QString temp="";

    switch(Unit)                                                     //单位
    {																 //
    /*case 0: pUnit[0]='k';
         pUnit[1]='g';
              break;*/                                                 //
    case 1: pUnit[0]='k';
        pUnit[1]='g';                                              //g
        break;                                                 //
    case 2: pUnit[0]='l';
        pUnit[1]='b';                                           //t
        break;                                                 //
    case 3: pUnit[0]=0x20;
        pUnit[1]='g';                                             //lb
        break;                                                 //
    default:pUnit[0]='k';
        pUnit[1]='g';                                             //kg
        break;													 //
    }
    Print_initial2();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    Print_Send0(0x20,8);
    ::write(m_fd,  "操作员报表          ",14);  //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "操作员:          ",8);  //
    Print_String1(RecUser.userID);									 // 									 //
    Print_Send0(0x0A,1);


    ::write(m_fd,  "笔数:           ",8);  //
    temp=QString::number(RecUser.numCount);									 //
    Print_String1(temp);
    Print_Send0(0x0A,1);

    ::write(m_fd,  "总重:       ",8);  //
    Print_String2( RecUser.AccWeight);
    ::write(m_fd,  pUnit,2);  //
    // ::write(m_fd, Enter_key,2);
    Print_Send0(0x0A,1);

    if(PrintLableSize==0)
    {
        ::write(m_fd, Enter_key1,2);
        if(b_PrintHeader)
        {
            ::write(m_fd, Init_Printer2,10);  //
            ::write(m_fd, Init_Middle,3);
            Print_String1(PrintCompanyName);
            Print_Send0(0x0D,1);

        }
    }
    else
        Print_Send0(0x0A,2);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese

    for(i=0;i<3;i++)
        usleep(2000000);
    PIN_PB25_L;
    b_Print=0;


}
void PrintPort::PrintSqlSheet()
{
    uchar i;
    b_Print=1;
    PIN_PB25_H;
    usleep(1000000);
    

    

    uchar pUnit[2];
    QString temp="";

    switch(Unit)                                                     //单位
    {																 //
    /*case 0: pUnit[0]='k';
         pUnit[1]='g';
              break;*/                                                 //
    case 1: pUnit[0]='k';
        pUnit[1]='g';                                              //g
        break;                                                 //
    case 2: pUnit[0]='l';
        pUnit[1]='b';                                           //t
        break;                                                 //
    case 3: pUnit[0]=0x20;
        pUnit[1]='g';                                             //lb
        break;                                                 //
    default:pUnit[0]='k';
        pUnit[1]='g';                                             //kg
        break;													 //
    }
    Print_initial2();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    Print_Send0(0x20,8);
    ::write(m_fd,  "产品报表明细       ",14);  //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "代码:           ",8);  //
    temp=QString::number(Sql.SqlCode);									 //
    Print_String1(temp);
    Print_Send0(0x0A,1);

    ::write(m_fd,  "名称:          ",8);  //
    Print_String1(Sql.SqlproductName);									 // 									 //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "价格:          ",8);  //
    Print_String2(Sql.SqlproductPrice);									 // 									 //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "重量:          ",8);  //
    Print_String2(Sql.Sqlweight);									 // 									 //
    Print_Send0(0x0A,1);


    // ::write(m_fd,  "总量:       ",8);  //
    Print_String1(Sql.SqlTime);
    //::write(m_fd,  pUnit,2);  //
    // ::write(m_fd, Enter_key,2);
    Print_Send0(0x0A,1);

    if(PrintLableSize==0)
    {
        ::write(m_fd, Enter_key1,2);
        if(b_PrintHeader)
        {
            ::write(m_fd, Init_Printer2,10);  //
            ::write(m_fd, Init_Middle,3);
            Print_String1(PrintCompanyName);
            Print_Send0(0x0D,1);
        }
    }
    else
        Print_Send0(0x0A,2);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese

    for(i=0;i<3;i++)
        usleep(2000000);
    PIN_PB25_L;
    b_Print=0;

}

void PrintPort::PrintUserSeniorReport()
{
    uchar i;
    b_Print=1;
    PIN_PB25_H;
    usleep(1000000);
    

    

    uchar pUnit[2];
    QString temp="";

    switch(Unit)                                                     //单位
    {																 //
    /*case 0: pUnit[0]='k';
         pUnit[1]='g';
              break;*/                                                 //
    case 1: pUnit[0]='k';
        pUnit[1]='g';                                              //g
        break;                                                 //
    case 2: pUnit[0]='l';
        pUnit[1]='b';                                           //t
        break;                                                 //
    case 3: pUnit[0]=0x20;
        pUnit[1]='g';                                             //lb
        break;                                                 //
    default:pUnit[0]='k';
        pUnit[1]='g';                                             //kg
        break;													 //
    }
    Print_initial2();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    Print_Send0(0x20,8);
    ::write(m_fd,  "操作员报表          ",14);  //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "操作员:          ",8);  //
    Print_String1(RecUser.userID);									 // 									 //
    Print_Send0(0x0A,1);


    ::write(m_fd,  "开始:           ",5);  //

    Print_String1(RecUser.StartTime);									 // 									 //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "结束:           ",5);  //
    Print_String1(RecUser.EndTime);									 // 									 //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "笔数:           ",8);  //
    temp=QString::number(RecUser.numCount);									 //
    Print_String1(temp);
    Print_Send0(0x0A,1);

    ::write(m_fd,  "总重:       ",8);  //
    Print_String2( RecUser.AccWeight);
    ::write(m_fd,  pUnit,2);  //
    // ::write(m_fd, Enter_key,2);
    Print_Send0(0x0A,1);

    if(PrintLableSize==0)
    {
        ::write(m_fd, Enter_key1,2);
        if(b_PrintHeader)
        {
            ::write(m_fd, Init_Printer2,10);  //
            ::write(m_fd, Init_Middle,3);
            Print_String1(PrintCompanyName);
            Print_Send0(0x0D,1);
        }
    }
    else
        Print_Send0(0x0A,2);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese

    for(i=0;i<3;i++)
        usleep(2000000);
    PIN_PB25_L;
    b_Print=0;

}


void PrintPort::PrintProductReport()
{
    uchar i;
    b_Print=1;
    PIN_PB25_H;
    usleep(1000000);
    

    

    uchar pUnit[2];
    QString temp="";

    switch(Unit)                                                     //单位
    {																 //
    /*case 0: pUnit[0]='k';
         pUnit[1]='g';
              break;*/                                                 //
    case 1: pUnit[0]='k';
        pUnit[1]='g';                                              //g
        break;                                                 //
    case 2: pUnit[0]='l';
        pUnit[1]='b';                                           //t
        break;                                                 //
    case 3: pUnit[0]=0x20;
        pUnit[1]='g';                                             //lb
        break;                                                 //
    default:pUnit[0]='k';
        pUnit[1]='g';                                             //kg
        break;													 //
    }
    Print_initial2();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    Print_Send0(0x20,8);
    ::write(m_fd,  "货品报表          ",14);  //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "货品:          ",8);  //
    Print_String1(RecProduct.productName);									 // 									 //
    Print_Send0(0x0A,1);


    ::write(m_fd,  "笔数:           ",8);  //
    temp=QString::number(RecProduct.numCount);									 //
    Print_String1(temp);
    Print_Send0(0x0A,1);

    ::write(m_fd,  "总重:       ",8);  //
    Print_String2( RecProduct.AccWeight);
    ::write(m_fd,  pUnit,2);  //
    // ::write(m_fd, Enter_key,2);
    Print_Send0(0x0A,1);

    if(PrintLableSize==0)
    {
        ::write(m_fd, Enter_key1,2);
        if(b_PrintHeader)
        {
            ::write(m_fd, Init_Printer2,10);  //
            ::write(m_fd, Init_Middle,3);
            Print_String1(PrintCompanyName);
            Print_Send0(0x0D,1);
        }
    }
    else
        Print_Send0(0x0A,2);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese

    for(i=0;i<3;i++)
        usleep(2000000);
    PIN_PB25_L;
    b_Print=0;

}

void PrintPort::PrintProductSeniorReport()
{
    uchar i;
    b_Print=1;
    PIN_PB25_H;
    usleep(1000000);
    

    

    uchar pUnit[2];
    QString temp="";

    switch(Unit)                                                     //单位
    {																 //
    /*case 0: pUnit[0]='k';
         pUnit[1]='g';
              break;*/                                                 //
    case 1: pUnit[0]='k';
        pUnit[1]='g';                                              //g
        break;                                                 //
    case 2: pUnit[0]='l';
        pUnit[1]='b';                                           //t
        break;                                                 //
    case 3: pUnit[0]=0x20;
        pUnit[1]='g';                                             //lb
        break;                                                 //
    default:pUnit[0]='k';
        pUnit[1]='g';                                             //kg
        break;													 //
    }
    Print_initial2();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    Print_Send0(0x20,8);
    ::write(m_fd,  "货品报表          ",14);  //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "货品:          ",8);  //
    Print_String1(RecProduct.productName);									 // 									 //
    Print_Send0(0x0A,1);


    ::write(m_fd,  "开始:           ",5);  //

    Print_String1(RecProduct.StartTime);									 // 									 //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "结束:           ",5);  //
    Print_String1(RecProduct.EndTime);									 // 									 //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "笔数:           ",8);  //
    temp=QString::number(RecProduct.numCount);									 //
    Print_String1(temp);
    Print_Send0(0x0A,1);

    ::write(m_fd,  "总重:       ",8);  //
    Print_String2( RecProduct.AccWeight);
    ::write(m_fd,  pUnit,2);  //
    // ::write(m_fd, Enter_key,2);
    Print_Send0(0x0A,1);

    if(PrintLableSize==0)
    {
        ::write(m_fd, Enter_key1,2);
        if(b_PrintHeader)
        {
            ::write(m_fd, Init_Printer2,10);  //
            ::write(m_fd, Init_Middle,3);
            Print_String1(PrintCompanyName);
            Print_Send0(0x0D,1);
        }
    }
    else
        Print_Send0(0x0A,2);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese

    for(i=0;i<3;i++)
        usleep(2000000);
    PIN_PB25_L;
    b_Print=0;
}

void PrintPort::PrintAllReport()
{
    uchar i;
    b_Print=1;
    PIN_PB25_H;
    usleep(1000000);
    

    

    uchar pUnit[2];
    QString temp="";

    switch(Unit)                                                     //单位
    {																 //
    /*case 0: pUnit[0]='k';
         pUnit[1]='g';
              break;*/                                                 //
    case 1: pUnit[0]='k';
        pUnit[1]='g';                                              //g
        break;                                                 //
    case 2: pUnit[0]='l';
        pUnit[1]='b';                                           //t
        break;                                                 //
    case 3: pUnit[0]=0x20;
        pUnit[1]='g';                                             //lb
        break;                                                 //
    default:pUnit[0]='k';
        pUnit[1]='g';                                             //kg
        break;													 //
    }
    Print_initial2();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    Print_Send0(0x20,8);
    ::write(m_fd,  "产品报表          ",14);  //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "开始:           ",5);  //

    Print_String1(RecAll.StartTime);									 // 									 //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "结束:           ",5);  //
    Print_String1(RecAll.EndTime);									 // 									 //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "笔数:           ",8);  //
    temp=QString::number(RecAll.numCount);									 //
    Print_String1(temp);
    Print_Send0(0x0A,1);

    ::write(m_fd,  "总重:       ",8);  //
    Print_String2( RecAll.AccWeight);
    ::write(m_fd,  pUnit,2);  //
    // ::write(m_fd, Enter_key,2);
    Print_Send0(0x0A,1);

    if(PrintLableSize==0)
    {
        ::write(m_fd, Enter_key1,2);
        if(b_PrintHeader)
        {
            ::write(m_fd, Init_Printer2,10);  //
            ::write(m_fd, Init_Middle,3);
            Print_String1(PrintCompanyName);
            Print_Send0(0x0D,1);
        }
    }
    else
        Print_Send0(0x0A,2);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese

    for(i=0;i<3;i++)
        usleep(2000000);
    PIN_PB25_L;
    b_Print=0;
}

void PrintPort::PrintMonthReport()
{
    uchar i;
    b_Print=1;
    PIN_PB25_H;
    usleep(1000000);
    

    

    uchar pUnit[2];
    QString temp="";

    switch(Unit)                                                     //单位
    {																 //
    /*case 0: pUnit[0]='k';
         pUnit[1]='g';
              break;*/                                                 //
    case 1: pUnit[0]='k';
        pUnit[1]='g';                                              //g
        break;                                                 //
    case 2: pUnit[0]='l';
        pUnit[1]='b';                                           //t
        break;                                                 //
    case 3: pUnit[0]=0x20;
        pUnit[1]='g';                                             //lb
        break;                                                 //
    default:pUnit[0]='k';
        pUnit[1]='g';                                             //kg
        break;													 //
    }
    Print_initial2();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    Print_Send0(0x20,8);
    ::write(m_fd,  "月报表          ",14);  //
    Print_Send0(0x0A,1);

    ::write(m_fd,  "年月:           ",8);  //
    Print_String1(RecMonth.StartTime);		 											 // 									 //
    Print_Send0(0x0A,1);


    ::write(m_fd,  "笔数:           ",8);  //
    temp=QString::number(RecMonth.numCount);									 //
    Print_String1(temp);
    Print_Send0(0x0A,1);

    ::write(m_fd,  "总重:       ",8);  //
    Print_String2( RecMonth.AccWeight);
    ::write(m_fd,  pUnit,2);  //
    // ::write(m_fd, Enter_key,2);
    Print_Send0(0x0A,1);

    if(PrintLableSize==0)
    {
        ::write(m_fd, Enter_key1,2);
        if(b_PrintHeader)
        {
            ::write(m_fd, Init_Printer2,10);  //
            ::write(m_fd, Init_Middle,3);
            Print_String1(PrintCompanyName);
            Print_Send0(0x0D,1);
        }
    }
    else
        Print_Send0(0x0A,2);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese

    for(i=0;i<3;i++)
        usleep(2000000);
    PIN_PB25_L;
    b_Print=0;
}



void PrintPort::PrintDailyReport()
{


    uchar i;
    b_Print=1;
    PIN_PB25_H;
    usleep(1000000);
    

    

    uchar pUnit[2];
    QString temp="";

    switch(Unit)                                                     //单位
    {																 //
    /*case 0: pUnit[0]='k';
         pUnit[1]='g';
              break;*/                                                 //
    case 1: pUnit[0]='k';
        pUnit[1]='g';                                              //g
        break;                                                 //
    case 2: pUnit[0]='l';
        pUnit[1]='b';                                           //t
        break;                                                 //
    case 3: pUnit[0]=0x20;
        pUnit[1]='g';                                             //lb
        break;                                                 //
    default:pUnit[0]='k';
        pUnit[1]='g';                                             //kg
        break;													 //
    }
    Print_initial2();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    Print_Send0(0x20,8);
    ::write(m_fd,  "日报表          ",14);  //
    Print_Send0(0x0A,1);

    Print_String1(RecDaily.StartTime);												 // 									 //
    Print_Send0(0x0A,1);


    ::write(m_fd,  "笔数:           ",8);  //
    temp=QString::number(RecDaily.numCount);									 //
    Print_String1(temp);
    Print_Send0(0x0A,1);

    ::write(m_fd,  "总重:       ",8);  //
    Print_String2( RecDaily.AccWeight);
    ::write(m_fd,  pUnit,2);  //
    // ::write(m_fd, Enter_key,2);
    Print_Send0(0x0A,1);

    if(PrintLableSize==0)
    {
        ::write(m_fd, Enter_key1,2);
        if(b_PrintHeader)
        {
            ::write(m_fd, Init_Printer2,10);  //
            ::write(m_fd, Init_Middle,3);
            Print_String1(PrintCompanyName);
            Print_Send0(0x0D,1);
        }
    }
    else
        Print_Send0(0x0A,2);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese

    for(i=0;i<3;i++)
        usleep(2000000);
    PIN_PB25_L;
    b_Print=0;
}

void PrintPort::PrintAccLP180()
{
    uchar pUnit[2];
    uchar l;
    QString temp="";
    QString temp1="";
    QString temp2="";
    //uchar h,m,s;//
    /*if ((BaudRate2!=1))
        {												             //
        Error(81);													 //err p
        return;														 //
        }
    8*/
    switch(Unit)                                                     //单位
    {																 //
    /*case 0: pUnit[0]='k';
         pUnit[1]='g';
              break;*/                                                 //
    case 1: pUnit[0]='k';
        pUnit[1]='g';                                              //g
        break;                                                 //
    case 2: pUnit[0]='l';
        pUnit[1]='b';                                           //t
        break;                                                 //
    case 3: pUnit[0]=0x20;
        pUnit[1]='g';                                             //lb
        break;                                                 //
    default:pUnit[0]='k';
        pUnit[1]='g';                                             //kg
        break;													 //
    }  															 //
    //
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    /* QTime current_time = QTime::currentTime();
                    QDate current_date= QDate::currentDate();
                    QDateTime time = QDateTime::currentDateTime();


    Year   = (current_date.year())%100;										 //

                Month  = current_date.month();										 //
                Day    = current_date.day();										 //



            Hour   = current_time.hour();										 //
                 Minute = current_time.minute();										 //
            Second = current_time.second();*/






    Print_16to10LP180(RecTimeLimit.Year);											 //
    Print_StringLP180("-",1);											 //
    Print_16to10LP180(RecTimeLimit.Month);											 //
    Print_StringLP180("-",1);											 //
    Print_16to10LP180(RecTimeLimit.Day);											 //
    //Print_String("-",1);											 //
    //Print_Send0(0x0A,1);												 //
    Print_StringLP180("           ",4);																		 //
    //Print_String("时间:         ",8);										 //
    // Print_16to10(Hour);											 //
    Print_16to10LP180(RecTimeLimit.Hour);

    Print_StringLP180(":",1);												 //
    Print_16to10LP180(RecTimeLimit.Minute);										 //

    Print_StringLP180(":",1);												 //
    Print_16to10LP180(RecTimeLimit.Second);										 //
    //Print_Send0LP180(0x0D,1);
    Print_Send0LP180(0x0A,1);
    //

    ::write(m_fd2,  "代码:           ",8);  //
    temp2=QString::number(currentproductInfor.productCode);									 //
    Print_String1LP180(temp2);
    //Print_Send0LP180(0x0D,1);
    Print_Send0LP180(0x0A,1);


    ::write(m_fd2,  "产品:       ",8);  //
    Print_String1LP180( currentproductInfor.productName);
    // ::write(m_fd, Enter_key,2);
    Print_Send0LP180(0x0A,1);

    temp=QString::number(Net,'f',Point);
    ::write(m_fd2,  "净重:       ",8);  //
    Print_String1LP180(temp);
    // PrintFloat(Net);										 //
    ::write(m_fd2,  pUnit,2);  //
    //::write(m_fd, Enter_key,2);
    //  Print_Send0LP180(0x0D,1);
    Print_Send0LP180(0x0A,1);



    //Print_Send0LP180(0x0D,1);
    Print_Send0LP180(0x0A,2);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese
}
///////////////////////////////////////////////////////////////////////
//                                                        //
///////////////////////////////////////////////////////////////////////
void PrintPort::PrintAcc()		//kevin	zw											 //
{																	 //
    uchar pUnit[2];
    uchar l;
    QString temp="";
    QString temp1="";
    QString temp2="";
    //uchar h,m,s;//
    /*if ((BaudRate2!=1))
        {												             //
        Error(81);													 //err p
        return;														 //
        }
    8*/
    switch(Unit)                                                     //单位
    {																 //
    /*case 0: pUnit[0]='k';
         pUnit[1]='g';
              break;*/                                                 //
    case 1: pUnit[0]='k';
        pUnit[1]='g';                                              //g
        break;                                                 //
    case 2: pUnit[0]='l';
        pUnit[1]='b';                                           //t
        break;                                                 //
    case 3: pUnit[0]=0x20;
        pUnit[1]='g';                                             //lb
        break;                                                 //
    default:pUnit[0]='k';
        pUnit[1]='g';                                             //kg
        break;													 //
    }  															 //
    //
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    /* QTime current_time = QTime::currentTime();
                    QDate current_date= QDate::currentDate();
                    QDateTime time = QDateTime::currentDateTime();


    Year   = (current_date.year())%100;										 //

                Month  = current_date.month();										 //
                Day    = current_date.day();										 //



            Hour   = current_time.hour();										 //
                 Minute = current_time.minute();										 //
            Second = current_time.second();*/




    if((PrintMode==0)||(PrintMode==7)||(PrintMode==8)||(PrintMode==9))
    {

        Print_16to10(RecTimeLimit.Year);											 //
        Print_String("-",1);											 //
        Print_16to10(RecTimeLimit.Month);											 //
        Print_String("-",1);											 //
        Print_16to10(RecTimeLimit.Day);											 //
        //Print_String("-",1);											 //
        //Print_Send0(0x0A,1);												 //
        Print_String("           ",4);																		 //
        //Print_String("时间:         ",8);										 //
        // Print_16to10(Hour);											 //
        Print_16to10(RecTimeLimit.Hour);

        Print_String(":",1);												 //
        Print_16to10(RecTimeLimit.Minute);										 //

        Print_String(":",1);												 //
        Print_16to10(RecTimeLimit.Second);										 //

        Print_Send0(0x0A,1);
        //

        ::write(m_fd,  "代码:           ",8);  //
        temp2=QString::number(currentproductInfor.productCode);									 //
        Print_String1(temp2);
        Print_Send0(0x0A,1);


        ::write(m_fd,  "产品:       ",8);  //
        Print_String1( currentproductInfor.productName);
        // ::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);

        temp=QString::number(Net,'f',Point);
        ::write(m_fd,  "净重:       ",8);  //
        Print_String1(temp);
        // PrintFloat(Net);										 //
        ::write(m_fd,  pUnit,2);  //
        //::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);


    }
    if(PrintMode==1)
    {
        Print_16to10(RecTimeLimit.Year);											 //
        Print_String("-",1);											 //
        Print_16to10(RecTimeLimit.Month);											 //
        Print_String("-",1);											 //
        Print_16to10(RecTimeLimit.Day);											 //
        //Print_String("-",1);											 //
        //Print_Send0(0x0A,1);												 //
        Print_String("           ",4);																		 //
        //Print_String("时间:         ",8);										 //
        // Print_16to10(Hour);											 //
        Print_16to10(RecTimeLimit.Hour);

        Print_String(":",1);												 //
        Print_16to10(RecTimeLimit.Minute);										 //

        Print_String(":",1);												 //
        Print_16to10(RecTimeLimit.Second);										 //

        Print_Send0(0x0A,1);
        //

        ::write(m_fd,  "代码:           ",8);  //
        temp2=QString::number(currentproductInfor.productCode);									 //
        Print_String1(temp2);
        Print_Send0(0x0A,1);

        ::write(m_fd,  "产品:       ",8);  //
        Print_String1( currentproductInfor.productName);
        // ::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);

        temp=QString::number(Net,'f',Point);
        ::write(m_fd,  "净重:       ",8);  //
        Print_String1(temp);
        // PrintFloat(Net);										 //
        ::write(m_fd,  pUnit,2);  //
        //::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);

        temp=QString::number(Net,'f',Point);

        l=QstringLength(temp);
        qDebug()<<"l="<<l;


        if(PrintCodeType==0)
        {

            ::write(m_fd, Code39,12);  //
            Print_Send0(l,1);
            Print_String1(temp);
        }
        else if(PrintCodeType==1)
        {
            ::write(m_fd, Code93,12);  //
            Print_Send0(l,1);
            Print_String1(temp);

        }
        else   if(PrintCodeType==2)
        {

            ::write(m_fd, Code128,12);  //
            Print_Send0(l,1);
            Print_String1(temp);
            //Print_Send0(0x0A,1);
            // Print_String("           ",4);
            // Print_String1(temp);
        }
        Print_Send0(0x0A,1);


    }
    if(PrintMode==2)
    {



        temp=QString::number(Net,'f',Point);

        l=QstringLength(temp);
        qDebug()<<"l="<<l;


        if(PrintCodeType==0)
        {

            ::write(m_fd, Code39,12);  //
            Print_Send0(l,1);
            Print_String1(temp);
        }
        else if(PrintCodeType==1)
        {
            ::write(m_fd, Code93,12);  //
            Print_Send0(l,1);
            Print_String1(temp);

        }
        else   if(PrintCodeType==2)
        {

            ::write(m_fd, Code128,12);  //
            Print_Send0(l,1);
            Print_String1(temp);
            // Print_Send0(0x0A,1);
            // Print_String("           ",4);
            //Print_String1(temp);
        }

        Print_Send0(0x0A,1);
    }

    if(PrintMode==3)
    {
        if(b_PrintCompany&&!b_PrintHeader)     PrintCompany();

        ::write(m_fd, Init_Middle,3);
        ::write(m_fd, Init_Qr1,3);

        l=QstringLength(CompanyWebsite)+2;
        qDebug()<<"l="<<l;
        Print_Send0(l,1);
        Print_Send0(0,3);
        Print_String1(CompanyWebsite);

        Print_Send0(0x0A,1);

    }

    if(PrintMode==4)
    {
        Print_16to10(RecTimeLimit.Year);											 //
        Print_String("-",1);											 //
        Print_16to10(RecTimeLimit.Month);											 //
        Print_String("-",1);											 //
        Print_16to10(RecTimeLimit.Day);											 //
        //Print_String("-",1);											 //
        //Print_Send0(0x0A,1);												 //
        Print_String("           ",4);																		 //
        //Print_String("时间:         ",8);										 //
        // Print_16to10(Hour);											 //
        Print_16to10(RecTimeLimit.Hour);

        Print_String(":",1);												 //
        Print_16to10(RecTimeLimit.Minute);										 //

        Print_String(":",1);												 //
        Print_16to10(RecTimeLimit.Second);										 //

        Print_Send0(0x0A,1);

        ::write(m_fd,  "代码:           ",8);  //
        temp2=QString::number(currentproductInfor.productCode);									 //
        Print_String1(temp2);

        //Print_16to10(1);
        //::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);


        ::write(m_fd,  "产品:       ",8);  //
        Print_String1( currentproductInfor.productName);
        // ::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);

        ::write(m_fd,  "单价:       ",8);  //
        Print_String2( currentproductInfor.productPrice);
        // ::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);

        ::write(m_fd,  "产地:       ",8);  //
        Print_String1( currentproductInfor.productOrigin);
        // ::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);

        ::write(m_fd,  "备注:       ",8);  //
        Print_String1( currentproductInfor.productDescribe);
        // ::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);

        temp=QString::number(Net,'f',Point);
        ::write(m_fd,  "净重:       ",8);  //
        Print_String1(temp);
        // PrintFloat(Net);										 //
        ::write(m_fd,  pUnit,2);  //
        //::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);

        ::write(m_fd,  "皮重:       ",8);  //
        temp1=QString::number(Tare,'f',Point);									 //
        Print_String1(temp1);
        ::write(m_fd,  pUnit,2);  //
        // ::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);

    }

    if(PrintMode==5)
    {

        Print_16to10(RecTimeLimit.Year);											 //
        Print_String("-",1);											 //
        Print_16to10(RecTimeLimit.Month);											 //
        Print_String("-",1);											 //
        Print_16to10(RecTimeLimit.Day);											 //
        //Print_String("-",1);											 //
        Print_Send0(0x0A,1);												 //
        //Print_String("           ",4);																		 //
        //Print_String("时间:         ",8);										 //
        // Print_16to10(Hour);											 //
        Print_16to10(RecTimeLimit.Hour);

        Print_String(":",1);												 //
        Print_16to10(RecTimeLimit.Minute);										 //

        Print_String(":",1);												 //
        Print_16to10(RecTimeLimit.Second);										 //

        Print_Send0(0x0A,1);
        //




        temp=QString::number(Net,'f',Point);
        ::write(m_fd,  "净重:       ",8);  //
        Print_String1(temp);
        // PrintFloat(Net);										 //
        ::write(m_fd,  pUnit,2);  //
        //::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);

        ::write(m_fd,  "皮重:       ",8);  //
        temp1=QString::number(Tare,'f',Point);									 //
        Print_String1(temp1);
        ::write(m_fd,  pUnit,2);  //
        // ::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);

    }

    if(PrintMode==6)
    {

        Print_16to10(RecTimeLimit.Year);											 //
        Print_String("-",1);											 //
        Print_16to10(RecTimeLimit.Month);											 //
        Print_String("-",1);											 //
        Print_16to10(RecTimeLimit.Day);											 //
        //Print_String("-",1);											 //
        //Print_Send0(0x0A,1);												 //
        Print_String("           ",4);																		 //
        //Print_String("时间:         ",8);										 //
        // Print_16to10(Hour);											 //
        Print_16to10(RecTimeLimit.Hour);

        Print_String(":",1);												 //
        Print_16to10(RecTimeLimit.Minute);										 //

        Print_String(":",1);												 //
        Print_16to10(RecTimeLimit.Second);										 //

        Print_Send0(0x0A,1);
        //




        temp=QString::number(Net,'f',Point);
        ::write(m_fd,  "净重:       ",8);  //
        Print_String1(temp);
        // PrintFloat(Net);										 //
        ::write(m_fd,  pUnit,2);  //
        //::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);


        ::write(m_fd,  "累计次数:       ",9);  //
        temp2=QString::number(Totfn);									 //
        Print_String1(temp2);
        Print_Send0(0x0A,1);

        temp=QString::number(Totfa,'f',Point);
        ::write(m_fd,  "累计重量:       ",9);  //
        Print_String1(temp);
        // PrintFloat(Net);										 //
        ::write(m_fd,  pUnit,2);  //
        //::write(m_fd, Enter_key,2);
        Print_Send0(0x0A,1);

    }



    if(PrintLableSize==0)
    {
        ::write(m_fd, Enter_key1,2);
        if(b_PrintHeader&&(PrintMode!=4))
        {
            if(PrintMode!=1)
            {
                ::write(m_fd, Init_Printer2,10);  //
                ::write(m_fd, Init_Middle,3);
                Print_String1(PrintCompanyName);
                Print_Send0(0x0D,1);
            }
            else
            {
                ::write(m_fd, Init_Printer2,10);  //
                ::write(m_fd, Init_Middle,3);
                Print_String1(PrintCompanyName);
                Print_Send0(0x0D,1);
            }
        }
    }
    else
        Print_Send0(0x0A,2);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese


}
///////////////////////////////////////////////////////////////////////
//                                                      //
///////////////////////////////////////////////////////////////////////
void PrintPort::PrintFloat(float ft)		//kevin									 //
{																	 //
    ulng ln;														 //
    uchar i,k;														 //
    /*if ((BaudRate2!=1)) {												 //
        //b_Erp=1;													 //
        return;														 //
        }		*/													 //
    while(Sidx!=0xff)
    {
    }																	 //
    //	if(Sidx!=0xff)return;
    if(ft>0)                                                             //
        ln=ft+0.5;                                                       //
    else                                                               //
        ln=0.5-ft;                                                       //
    if(ln>999999)ln=999999;                                            //
    if(ft>-0.5)                                                        //
        SendBuff[0]=' ';                                         //
    else                                                               //
        SendBuff[0]='-';											 //
    //
    i=7;																 //
    SendBuff[i]=ln%10+'0';										 //
    ln=ln/10;													 //
    i--;														 //
    if(Point==1)												 //
    {														 //
        SendBuff[i]='.';										 //
        i--;													 //
    }														 //
    SendBuff[i]=ln%10+'0';										 //
    ln=ln/10;													 //
    i--;														 //
    if(Point==2)												 //
    {SendBuff[i]='.';										 //
        i--;													 //
    }														 //
    SendBuff[i]=ln%10+'0';										 //
    ln=ln/10;													 //
    i--;														 //
    if(Point==3)												 //
    {SendBuff[i]='.';										 //
        i--;													 //
    }														 //
    SendBuff[i]=ln%10+'0';										 //
    ln=ln/10;													 //
    i--;														 //
    if(Point==4)												 //
    {SendBuff[i]='.';										 //
        i--;													 //
    }															 //
    SendBuff[i]=ln%10+'0';										 //
    ln=ln/10;													 //
    i--;														 //
    //
    SendBuff[i]=ln%10+'0';										 //
    ln=ln/10;													 //
    i--;														 //
    if(Point==0)												 //
    {															 //
        SendBuff[i]=ln%10+'0';									 //
    }															 //
    k=1;														 //
    while(SendBuff[k]==0x30&&k<(6-Point))SendBuff[k++]=0x20;	 //
    ::write(m_fd, SendBuff,8);  //kevin
    //
    //
}

///////////////////////////////////////////////////////////////////////
//                                                   //
///////////////////////////////////////////////////////////////////////
void PrintPort::Print_Int(unsigned int n)                                       //
{unsigned int i;                                                     //

    if(n>9999)                                                         //
        i=9999;                                                          //
    else                                                               //
        i=n;                                                             //
    SendBuff[0]=0x30+i/1000;											 //
    i=i%1000;                                                          //
    SendBuff[1]=0x30+i/100;                                            //
    i=i%100;                                                           //
    SendBuff[2]=0x30+i/10;                                             //
    i=i%10;                                                            //
    SendBuff[3]=0x30+i;												 //
    //
    SendBuff[4]=0xff;													 //
    ::write(m_fd, SendBuff,4);											 //
}

void PrintPort::Print_16to10LP180(unsigned char n)  
{
    unsigned char i;                                                    //
    /* if ((Baud!=4)) {													 //
        b_Erp=1;													 //
        return;														 //
        }                                                            //
  while(Sidx!=0xff)
    {
    }																	 //
    if(Sidx!=0xff)return;*/
    if(n>99)                                                            //
        i=99;                                                            //
    else                                                                //
        i=n;                                                             //
    SendBuff2[0]=0x30+i/10;												 //
    SendBuff2[1]=0x30+i%10;                                              //
    ::write(m_fd2, SendBuff2,2);															 //

}

///////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////
void PrintPort::Print_16to10(unsigned char n)                                   //
{unsigned char i;                                                    //
    /* if ((Baud!=4)) {													 //
        b_Erp=1;													 //
        return;														 //
        }                                                            //
  while(Sidx!=0xff)
    {
    }																	 //
    if(Sidx!=0xff)return;*/
    if(n>99)                                                            //
        i=99;                                                            //
    else                                                                //
        i=n;                                                             //
    SendBuff[0]=0x30+i/10;												 //
    SendBuff[1]=0x30+i%10;                                              //
    ::write(m_fd, SendBuff,2);															 //
    //SendBuff[2]=0xff;													 //
    /*Sidx=0;                                                     		 //
  TI=1;																 //
 while(Sidx!=0xff)
    {
    }																	 //

 Print_Delay();*/														 //
} 																	 //


void PrintPort::Price2UartData(float ft)
{
    qDebug() << "rs232" << endl;
    QString data = QString("%1").arg(ft);
    //uchar length;
    //Print_String1(data);
    const char*  ch;
    std::string st=data.toStdString();
    ch=st.c_str();
    //length=2+strlen(ch);
    QrSendBuff[0]=0x02;
    for(int j=0;j<7-strlen(ch);j++)
        QrSendBuff[j+1]=0x30;
    for(int i=0;i<strlen(ch);i++)
        QrSendBuff[8-strlen(ch)+i]=ch[i];
    QrSendBuff[8]=0x03;
    :: write(m_fd2,&QrSendBuff,9);

}

void PrintPort::LoadUart1Com()
{
    unsigned char ucTNumb;
    
    //QByteArray sendByteArray;

    ucTNumb = loadZMComuData(&SendBuff1[0]);

    //mutex_r2.lock();
    int ret;
    //ret=0;
    if(m_fd1!=-1)
    {

        //  qDebug() << "loaduart1" << endl;
        ret= :: write(m_fd1,&SendBuff1,ucTNumb);


    }

    //mutex_r2.unlock();



}



void PrintPort::LoadRdCom()
{
    
    SendBuff1[0]=0x99;
    //  ucTNumb = loadZMComuData(&SendBuff1[0]);

    //mutex_r2.lock();
    int ret;
    //ret=0;
    if(m_fd1!=-1)
    {

        //  qDebug() << "loaduart1" << endl;
        ret= :: write(m_fd1,&SendBuff1,1);


    }

    //mutex_r2.unlock();



}


void PrintPort::LoadUart2Com()
{
    unsigned char ucTNumb;
    
    //QByteArray sendByteArray;
    switch(CommType232)
    {
    case 0:
        ucTNumb = loadZMComuData(&SendBuff2[0]);
        break;
    case 1:
        ucTNumb = loadA7ComuData(&SendBuff2[0]);
        break;
    default:
        ucTNumb = loadZMComuData(&SendBuff2[0]);
        break;
    }

    mutex_r2.lock();
    int ret;
    //ret=0;
    if(m_fd2!=-1)
    {
        if(Tmode_232==0)
        {
            //  qDebug() << "loaduart2" << endl;
            ret= :: write(m_fd2,&SendBuff2,ucTNumb);
        }//
        if(Tmode_232==1&&b_Stable)
        {
            //qDebug() << "loaduart2 stab" << endl;
            ret= :: write(m_fd2,&SendBuff2,ucTNumb);
        }
    }

    mutex_r2.unlock();



}


void PrintPort::LoadUart3Com()
{
    //qDebug() << "loaduart3" << endl;
    if(Tmode_485==0)
        UartModBus(Ridx3,RecvBuff3,SendBuff3);




}

/******************************************************************************
* 名称   : loadA7ComuData
* 描述   : D2连续通讯方式装载
* 输入   : 装载的地址，参数
* 输出   : 需要发送的个数
******************************************************************************/
uchar PrintPort::loadA7ComuData(uchar * pucBuff)
{
    float slWeight;
    ulng ln;
    slWeight = Net;
    pucBuff[0] = '=';
    ln =Hextof(slWeight );
    //hex2UartData(ln, pucBuff+1, 6, Dec&0x07);
    //hex2UartData(ln, pucBuff+1, 6, (Decp|0x80));//wangzhen
    hex2UartData(ln, pucBuff+1, 6, Point);   //wangzhen  add
    pucBuff[7] = (slWeight<-0.5*Rati)? '-' : '0';
    return 8;

}

/******************************************************************************

*          
******************************************************************************/
unsigned char PrintPort::loadZMComuData(unsigned char * pucBuff)
{
    float slWeight;
    unsigned char i;
    jzStateCheck(pucBuff, 0x01);
    pucBuff[2] = ',';
    jzStateCheck(pucBuff + 3, 0x02);
    pucBuff[5] = ',';
    slWeight = b_Net ? (Net) : (Gross);
    pucBuff[6] = (slWeight < 0) ? '-' : '+';
    slWeight =Hextof(slWeight );
    if (Point== 0)
    {
        pucBuff[7] = 0x20;
        hex2UartData(slWeight, pucBuff + 8, 6, 0x80);
    }
    else
    {
        hex2UartData(slWeight, pucBuff + 7, 7, (Point | 0x80));
    }
    for (i = 0;i <= 4 - Point;i++)
    {
        if ((pucBuff[7 + i] == 0x20) || (pucBuff[7 + i] == 0x30))
        {
            pucBuff[7 + i] = 0x20;
            continue;
        }
        else
        {
            break;
        }
    }
    jzStateCheck(pucBuff + 14, 0x03);
    pucBuff[16] = 0x0d;
    pucBuff[17] = 0x0a;
    return 18;
}


/******************************************************************************

******************************************************************************/
void PrintPort::jzStateCheck(unsigned char * pucBuff, unsigned char ucData)
{    
    switch (ucData)
    {
    case 0x01:
        if (b_OL)
        {
            pucBuff[0] = 'O';
            pucBuff[1] = 'L';
        }
        else if (b_Stable)
        {
            pucBuff[0] = 'S';
            pucBuff[1] = 'T';
        }
        else
        {
            pucBuff[0] = 'U';
            pucBuff[1] = 'S';
        }
        break;

    case 0x02:
        if (b_Net)
        {
            pucBuff[0] = 'N';
            pucBuff[1] = 'T';
        }
        else
        {
            pucBuff[0] = 'G';
            pucBuff[1] = 'S';
        }
        break;

    case 0x03:
        if (Unit == 2)
        {
            pucBuff[0] = 'g';
            pucBuff[1] = ' ';
        }
        else if(Unit==1)
        {
            pucBuff[0] = 'k';
            pucBuff[1] = 'g';
        }
        else
        {
            pucBuff[0] = 'l';
            pucBuff[1] = 'b';
        }

    default:
        break;
    }
}


/******************************************************************************

******************************************************************************/
void PrintPort::hex2UartData(float slHex, unsigned char * puBuff, unsigned char ucNumb, unsigned char ucPara)
{
    unsigned char * pucTemp;
    unsigned char i;
    unsigned long ln;
    
    if (slHex < 0)
    {
        ln = -slHex;
    }
    else
    {
        ln = slHex;
    }
    if ((ucPara & 0x0F) == 0)
    {
        ucPara |= 0x0F;
    }
    
    for (i = 0; i < ucNumb; i++)
    {
        pucTemp = (ucPara & 0x80) ? puBuff + ucNumb - i - 1 : puBuff + i;
        
        if (i == (ucPara & 0x0F))
        {
            *pucTemp = '.';
        }
        else
        {
            *pucTemp = ln % 10 + '0';
            ln /= 10;
        }
    }
}

/***********************************************************

*************************************************************/
unsigned char PrintPort::UartModBus(unsigned int ucRNumb,unsigned char* pucRBuff,unsigned char* pucTBuff)
{
    unsigned int    ch1,ch2,ch3,ch16,j;
    unsigned char	*ptr1,ch,ucTNumb=0;
    ch3=ucRNumb;
    ptr1=&pucRBuff[0];
    //qDebug() << "load" << endl;

    if(ucRNumb < 4)  goto MBStart;				//
    if(*ptr1 !=Addr) goto MBStart;				//
    j=ucRNumb-2;
    ch1 = CRC16(&pucRBuff[0],j);				//
    ch16 = pucRBuff[j+1];
    ch2 = pucRBuff[j]+ch16*256;
    if(ch2!=ch1)
    {
        goto MBStart;
    }
    else
    {
        ch=*(ptr1+1);	                    //
        if(ch3>3){
            ch1=*(ptr1+2);
            ch1 = 256*ch1 + *(ptr1+3);		//
        }
        else{
            ch1=0;
        }
        if(ch3>5){
            ch2=*(ptr1+4);
            ch2 = 256*ch2 + *(ptr1+5);	  //
        }
        else{
            ch2=0;
        }
        switch(ch){

        case 2:									//***读离散量输入***
            if((ch2 < 1)||(ch2 > 4)){
                ucTNumb=MBfycm(ch,3,pucTBuff); 					//发异常码
                break;
            }
            if((ch1 + ch2) > 4){
                ucTNumb=MBfycm(ch,3,pucTBuff); 					//发异常码
                break;
            }
            ucTNumb=MBsrlsl(ch1,ch2,pucTBuff);
            break;

        case 3:									//
            if((ch2 < 1)||(ch2 > 125)){
                ucTNumb=MBfycm(ch,3,pucTBuff);	//
                break;
            }
            if((ch1 + ch2) > 402){				//
                ucTNumb=MBfycm(ch,2,pucTBuff);	//
                break;
            }
            ucTNumb=MBdujcq(ch,ch1,ch2,pucTBuff);
            break;

        case 4:									//***读输入寄存器***
            if((ch2 < 1)||(ch2 > 125)){
                ucTNumb=MBfycm(ch,3,pucTBuff);					//发异常码
                break;
            }
            if((ch1 + ch2) > 69){				                //
                ucTNumb=MBfycm(ch,2,pucTBuff);					//发异常码
                break;
            }//zw
            /*if((ch1 + ch2) > 61){				                //
                ucTNumb=MBfycm(ch,2,pucTBuff);					//发异常码
                break;
            }*/
            ucTNumb=MBdujcq(ch,ch1,ch2,pucTBuff);
            break;

        case 5:
            if((ch2 != 0xff00)&&(ch2 != 0x0000)){
                ucTNumb=MBfycm(ch,3,pucTBuff);					//发异常码
                break;
            }
            if(ch1<3)
            {
                ucTNumb=MBxdgxq1(ch1,ch2,pucTBuff);
            }
            else
            {
                ucTNumb=MBfycm(ch,5,pucTBuff);					//发异常码
                break;
            }
            break;

        case 6://zw

            ucTNumb=MBxdgjcq(ch1,ch2,pucTBuff);
            break;
        case 16://zw


            ucTNumb=MBxdojcq( ch1, ch2,ptr1+6,pucTBuff);
            break;
        case 20:					                        //读文件记录（称重记录，设备说明）
            ucTNumb=MBduwj(ch1,ch2,ptr1+6,pucTBuff);
            break;

        }

    }
    if(ucTNumb!=0)
    {
        Sidx3=0;
        //qDebug() << "load485" << endl;
        control_485=1;
        //ioctl(gpio, 1, 9);
        PIN_PB24_H;
        ::write(m_fd3, pucTBuff, ucTNumb);
        //fsync(fd);
        //UART_Write(UART0,&pucTBuff[0],ucTNumb);
        usleep(RS485_DELAY_US*(ucTNumb+1));
        b_Comr=0;
        // RS485RC=0;
        Sidx3=0xff;
        Ridx3=0;
        control_485=0;
        PIN_PB24_L;
        //ioctl(gpio, 0, 9);
        return 0;
    }
    else
    {
        goto MBStart;
    }
MBStart:
    {

        // qDebug() << "loadstart" << endl;
        b_Comr=0;                                                   //
        //RS485RC=0;
        Ridx3=0;
        PIN_PB24_L;
        control_485=0;
        Sidx3=0xff;
        return 1;
    }

}




/***********************************************************

*************************************************************/
unsigned int PrintPort::CRC16(unsigned char *puchMsg, unsigned int usDataLen)
{

    unsigned char *ptr ;
    unsigned int Len ;
    unsigned char uchCRCHi = 0xFF ;
    unsigned char uchCRCLo = 0xFF ;
    unsigned char uIndex ;
    Len=usDataLen;
    ptr=puchMsg;
    while (Len--)
    {
        uIndex = uchCRCHi ^ *ptr++ ;
        uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex] ;
        uchCRCLo = auchCRCLo[uIndex] ;
    }
    //  if(MBCRC == 0)return (uchCRCHi << 8 | uchCRCLo) ;
    //	else
    return (uchCRCLo << 8 | uchCRCHi) ;
}



unsigned char PrintPort::MBfycm(unsigned char gnm,unsigned char ycm,unsigned char *TxBuffer)
{
    unsigned int jyh=0;
    TxBuffer[0] = Addr;
    TxBuffer[1] = gnm | 0x80;
    TxBuffer[2] = ycm;
    jyh = CRC16(&TxBuffer[0],3);
    TxBuffer[3] = jyh % 256;
    TxBuffer[4] = jyh / 256;
    return 5;
}

/***********************************************************
函数名称：void MBxdgxq1(uint chr1,uint chr2,uchar *TxBuffer)
功能描述：写单个线圈
返   回：
*************************************************************/
uchar PrintPort::MBxdgxq1(uint chr1,uint chr2,uchar *TxBuffer)
{
    uint i,j;
    uint jyh;
    uchar ucTNumb=0;
    i = chr1;
    j = chr2;
    if(chr1<3)
    {
        if(chr1==0)
        {
            if(chr2==0xff00)
            {
                calia.SetZero(ZeroKeyVal);
                if(b_Net)
                {
                    ucTNumb=MBfycm(5,2,TxBuffer);
                    return ucTNumb;
                }
            }
        }
        else if(chr1==1)
        {

            if(chr2==0xff00)
            {
                if(!b_Stable||Gross<-(0.5*Rati))
                {
                    ucTNumb=MBfycm(5,2,TxBuffer);

                    return ucTNumb;
                }
                calia.KTare();
            }
        }
    }


    TxBuffer[0] = Addr;									//填充发送缓冲区
    TxBuffer[1] = 0x05;
    TxBuffer[2] = i / 256;
    TxBuffer[3] = i % 256;
    TxBuffer[4] = j / 256;
    TxBuffer[5] = j % 256;
    jyh = CRC16(&TxBuffer[0],6);
    TxBuffer[6] = jyh % 256;
    TxBuffer[7] = jyh / 256;
    ucTNumb = 8;
    return ucTNumb;
}



/***********************************************************
函数名称：void MBsrlsl(u16 chr1,u16 chr2)
功能描述：读输入离散量，与C606强相关
入口参数：u16 chr1:起始地址
    u16 chr2:读取数量
返   回：
*************************************************************/
uchar PrintPort::MBsrlsl(uint chr1,uint chr2,uchar *TxBuffer)
{
    uint i,j;
    uchar m,n=1;
    uchar dat[2],ucTNumb=0;
    uint jyh=0,dat1=0,dat2=0;;
    i = chr1;
    j = chr2;
    if((i+j<4)){
        dat1|=(b_Stable);
        dat1|=(b_Zero<<1);
        dat1|=(b_Net<<2);
        dat1 >>= i;
        for(m=0;m<j;m++){					//计算屏蔽码
            dat2 <<= 1;
            dat2=dat2+1;
        }
        dat1 &= dat2;
        dat[0] = dat1 & 0xff;
        dat[1] = dat1>>8 & 0xff;
        if(j>8)n=2;
    }else{
        ucTNumb=MBfycm(0x01,4,TxBuffer);						//发异常码
        return ucTNumb;
    }

    TxBuffer[0] = Addr;				//填充发送缓冲区
    TxBuffer[1] = 0x02;
    TxBuffer[2] = n;
    for(m=0;m<n;m++){
        TxBuffer[m+3] = dat[m];
    }
    jyh = CRC16(&TxBuffer[0],n+3);
    TxBuffer[n+3] = jyh % 256;
    TxBuffer[n+4] = jyh / 256;
    ucTNumb = n+5;				//数据长度
    return ucTNumb;
}


unsigned char PrintPort::MBxdgjcq(unsigned int chr1,unsigned int chr2,uchar *TxBuffer)
{
    MBVarStruct *MBRptr;						//寄存器表指针
    void *ptr;
    uint i,j;
    uchar k,ucTNumb=0;
    uint jyh=0;

    i = chr1;
    j = chr2;
    k = MBjcjcq(chr1);


    if(k == 0xff){
MBerr:
        ucTNumb=MBfycm(6,4,TxBuffer);							//变量地址不准确
        return ucTNumb;
    }


    MBRptr = (MBVarStruct *)&MBReg[k];
    k = MBRptr->MBTp;							//变量类型
    ptr = (void*)MBRptr->MBPtr;					//变量指针
    switch(k){
    case 0x33:								//16位整数
        if((j < MBRptr->MBMin)||
                (j > MBRptr->MBMax))goto MBerr;
        *(uint*)ptr = j;
        break;
    case 0x35:								//8位整数
        if((j < MBRptr->MBMin)||
                (j > MBRptr->MBMax))goto MBerr;
        *(uchar*)ptr = (uchar)(j & 0xff);
        break;
    default:
        ucTNumb=MBfycm(6,4,TxBuffer);						//发异常码
        return ucTNumb;
    }
    if(MBRptr->MBXz == 1)
    {
        // qDebug()<<"2"<<endl;
        goto MBerr;

    }
    /*else if(MBRptr->MBXz == 2)
    {
            if(b_NotCal)
            goto MBerr;
    }*/
    calia.ArgSave();
    SaveData();
    ptr = &TxBuffer;
    TxBuffer[0] = Addr;
    TxBuffer[1] = 06;
    TxBuffer[2] = i / 256;
    TxBuffer[3] = i % 256;
    TxBuffer[4] = j / 256;						//长度
    TxBuffer[5] = j % 256;
    jyh = CRC16(&TxBuffer[0],6);
    TxBuffer[6] = jyh % 256;
    TxBuffer[7] = jyh / 256;
    ucTNumb = 8;							//数据包长度
    return 	ucTNumb;
    //qDebug()<<"ucTNumb"<<ucTNumb;
}


/***********************************************************
函数名称：uchar MBduwj(u16 ch1,u16 ch2,u8 *ptr);
功能描述：读文件记录
入口参数：u16 ch1:
    u16 ch2:
    u8 *ptr:
返   回：无
*************************************************************/
uchar PrintPort::MBduwj(uint ch1, uint ch2,uchar *ptr,uchar *TxBuffer)
{
    uchar *ptr1;
    uint i,j,k,jyh;
    uchar ucTNumb=0;
    uchar n;
    union bh32
    {
        float datf32;
        ulng datu32;
        long dats32;
        uchar datu8[4];
    }dat32;
    
    ptr1 = (uchar *)ptr;
    if((ch1 != 0x0706)||(ch2!=1)){
        ucTNumb=MBfycm(20,4,TxBuffer);					                        //发异常码
        return ucTNumb;
    }
    i = *ptr1++*256;					                    //记录号
    i += *ptr1++;
    j = *ptr1++*256;					                    //记录数量
    j += *ptr1;
    ptr1 = TxBuffer;
    *ptr1++ = Addr;
    *ptr1++ = 20;					                        //功能号
    if(ch2 == 1){					                        //----文件1----
        if(i == 0){					                        //读最后一条记录
            if(b_Save){
                *ptr1++ = 12;				                //存储模式2，数据总长度
                *ptr1++ = 11;				                //子请求1长度
                *ptr1++ = 6;				                //引用类型
                i = Totfn;
                *ptr1++ = i / 256;			                //序号
                *ptr1++ = i % 256;
                dat32.datu32 = LastTime;		            //时间
                *ptr1++ = dat32.datu8[3];
                *ptr1++ = dat32.datu8[2];
                *ptr1++ = dat32.datu8[1];
                *ptr1++ = dat32.datu8[0];
                dat32.datf32 = LastWt;			            //重量
                *ptr1++ = dat32.datu8[3];
                *ptr1++ = dat32.datu8[2];
                *ptr1++ = dat32.datu8[1];
                *ptr1++ = dat32.datu8[0];
            }
        }else{						                        //读存储的记录
            if(i > Totfn)goto MBerr;
            if(b_Save){
                k=10;
            }
            if((k * j) > 245)goto MBerr;
            *ptr1++ = k * j + 2;
            *ptr1++ = k * j + 1;
            *ptr1++ = 6;				                    //引用类型
            while((i < (Totfn + 1))&&(j > 0)){
                n = MBLoadRec(i,ptr1);		            //读存储数据
                ptr1 += n;
                j--;
                i++;
            }
        }
    }else{
MBerr:
        ucTNumb=MBfycm(20,4,TxBuffer);						                    //发异常码
        return ucTNumb;
    }
    i = ptr1 - TxBuffer;				                    //求数据长度
    jyh = CRC16(&TxBuffer[0],i);
    *ptr1++ = jyh % 256;
    *ptr1++ = jyh / 256;
    ucTNumb=i+2;
    return 	ucTNumb;
}

uchar PrintPort::MBLoadRec(uint ch1,uchar *ptr)
{
    uchar *ptr1;
    uint i;
    union bh32
    {
        float datf32;
        ulng datu32;
        long dats32;
        uchar datu8[4];
    }dat32;
    ptr1 = ptr;
    i = ch1;
    *ptr1++ = i / 256;
    *ptr1++ = i % 256;
    if(i>0)i--;
    QString Wt="baseinfo/Wt";
    QString WtTime="baseinfo/WtTime";
    Wt+=QString::number(ch1);
    WtTime+=QString::number(ch1);



    if(b_Save)
    {

        QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
        dat32.datu32=configIniRead->value(WtTime).toInt();
        *ptr1++ = dat32.datu8[3];
        *ptr1++ = dat32.datu8[2];
        *ptr1++ = dat32.datu8[1];
        *ptr1++ = dat32.datu8[0];
        dat32.datf32=configIniRead->value(Wt).toFloat();

        *ptr1++ = dat32.datu8[3];
        *ptr1++ = dat32.datu8[2];
        *ptr1++ = dat32.datu8[1];
        *ptr1++ = dat32.datu8[0];
        delete configIniRead;
        return 10;

    }

}


/***********************************************************
函数名称：void MBxdojcq(u16 chr1,u16 chr2,(void *)ptr)
功能描述：写多个寄存器
入口参数：u16 chr1:起始地址
    u16 chr2:写数量
    (void *)ptr:写入数据指针
返   回：无
*************************************************************/
uchar PrintPort::MBxdojcq(uint chr1,uint chr2,void *ptr,uchar *TxBuffer)
{
    MBVarStruct  *MBRptr;
    union bh32
    {
        float datf32;
        ulng datu32;
        s32 dats32;
        uchar datu8[4];
    }dat32;
    union bh16
    {
        uint datu16;
        uchar datu8[2];
    }dat16;
    uint i,j;
    uchar m,n,p;
    uchar *ptr1;
    uchar ii=0,ucTNumb=0;													//错误计数
    uint jyh=0;

    i = chr1;													//地址
    j = chr2;													//数量
    ptr1 = (uchar *)ptr;
    m = *ptr1++;
    if(m != (2 * j)){											//数据长度不符
        ucTNumb=MBfycm(0x10,4,TxBuffer);										//发异常码

        return ucTNumb;
    }
    while(m > 0){												//依次写寄存器
        n = MBjcjcq(i);											//搜索寄存器
        if(n == 0xff){
            if(ii == 0)goto MBerr;								//如果第1个寄存器不存在，出错
            else break;
        }
        ii++;
        MBRptr = (MBVarStruct *)&MBReg[n];
        if(MBRptr->MBXz == 1)								//只读或计量相关参数而标定开关未打开
        {
MBerr:
            ucTNumb=MBfycm(0x10,4,TxBuffer);										//发异常码
            return ucTNumb;
        }
        /*if(MBRptr->MBXz == 2)
        {
            if(b_NotCal)
            goto MBerr;
        }*/

        n = MBRptr->MBTp;										//变量类型
        ptr = (void*)MBRptr->MBPtr;								//变量指针
        switch(n){
        case 0x00:											//f32/f32
            if(m < 4){
                m = 0;
                break;
            }
            m -= 4;
            i += 2;
            for(p=0;p<4;p++){								//读变量数据
                dat32.datu8[3 - p] = *ptr1++;
            }
            //dat32.datf32=Hextof(dat32.datf32);
            if((dat32.datf32 < MBRptr->MBMin)||
                    (dat32.datf32 > MBRptr->MBMax))goto MBerr;
            *(float*)MBRptr->MBPtr = dat32.datf32; 			//保存变量
            break;
        case 0x10:											//s32/f32
            if(m < 4){
                m = 0;
                break;
            }
            m -= 4;
            i += 2;
            for(p=0;p<4;p++){								//读变量数据
                dat32.datu8[3 - p] = *ptr1++;
            }
            //dat32.datu32=HextoU(dat32.datu32);
            if((dat32.datu32 < MBRptr->MBMin)||
                    (dat32.datu32 > MBRptr->MBMax))goto MBerr;
            *(ulng*)MBRptr->MBPtr = (ulng)(dat32.datu32); //保存变量
            break;

        case 0x20:											//s32/f32
            if(m < 4){
                m = 0;
                break;
            }
            m -= 4;
            i += 2;
            for(p=0;p<4;p++){								//读变量数据
                dat32.datu8[3 - p] = *ptr1++;
            }
            dat32.datf32=HexUtof(dat32.datu32);
            if((dat32.datf32 < MBRptr->MBMin)||
                    (dat32.datf32 > MBRptr->MBMax))goto MBerr;
            *(float*)MBRptr->MBPtr = (float)(dat32.datf32); //保存变量
            break;
        case 0x33:											//16位整数
            if(m < 2){
                m = 0;
                break;
            }
            m -= 2;
            i++;
            for(p=0;p<2;p++){								//读变量数据
                dat16.datu8[1 - p] = *ptr1++;
            }
            if((dat16.datu16 < MBRptr->MBMin)||
                    (dat16.datu16 > MBRptr->MBMax))goto MBerr;
            *(uint*)MBRptr->MBPtr = dat16.datu16; 			//保存变量
            break;
        case 0x35:											//8位整数
            if(m < 2){
                m = 0;
                break;
            }
            m -= 2;
            i++;
            for(p=0;p<2;p++){								//读变量数据
                dat16.datu8[1 - p] = *ptr1++;
            }
            if((dat16.datu16 < MBRptr->MBMin)||
                    (dat16.datu16 > MBRptr->MBMax))goto MBerr;
            *(uchar*)MBRptr->MBPtr = dat16.datu8[0]; 			//保存变量
            break;
        default:
            ucTNumb=MBfycm(0x10,4,TxBuffer);									//发异常码
            return ucTNumb;
        }
    }


    calia.ArgSave();
    SaveData();



    j = i - chr1;												//数量
    i = chr1;													//地址
    TxBuffer[0] = Addr;										//填充发送缓冲区
    TxBuffer[1] = 0x10;
    TxBuffer[2] = i / 256;
    TxBuffer[3] = i % 256;
    TxBuffer[4] = j / 256;										//长度
    TxBuffer[5] = j % 256;
    jyh = CRC16(&TxBuffer[0],6);
    TxBuffer[6] = jyh % 256;
    TxBuffer[7] = jyh / 256;
    ucTNumb = 8;
    return ucTNumb;												//数据长度
}

void PrintPort::SaveData(void)
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/Tmode232",Tmode_232);
    configIniRead->setValue("baseinfo/CommType",CommType);
    configIniRead->setValue("baseinfo/CommType232",CommType232);
    configIniRead->setValue("baseinfo/BaudRate232",BaudRate_232);
    configIniRead->setValue("baseinfo/DataBits232",DataBits_232);
    configIniRead->setValue("baseinfo/StopBits232",StopBits_232);
    configIniRead->setValue("baseinfo/Parity232",ParityMode_232);
    configIniRead->setValue("baseinfo/Tmode485",Tmode_485);
    configIniRead->setValue("baseinfo/BaudRate485",BaudRate_485);
    configIniRead->setValue("baseinfo/DataBits485",DataBits_485);
    configIniRead->setValue("baseinfo/StopBits485",StopBits_485);
    configIniRead->setValue("baseinfo/Parity485",ParityMode_485);
    configIniRead->setValue("baseinfo/Addr",Addr);
    
    configIniRead->setValue("baseinfo/PrintLq",PrintLq);
    configIniRead->setValue("baseinfo/b_Save",b_Save);
    configIniRead->setValue("baseinfo/b_PrintHeader",b_PrintHeader);
    configIniRead->setValue("baseinfo/,PrintCodeType",PrintCodeType);
    configIniRead->setValue("baseinfo/b_PrintStable",b_PrintStable);
    configIniRead->setValue("baseinfo/b_PrintRetZero",b_PrintRetZero);
    configIniRead->setValue("baseinfo/PrintLableSize",PrintLableSize);
    configIniRead->setValue("baseinfo/PrintMode",PrintMode);
    
    delete configIniRead;
} 
unsigned char PrintPort::MBdujcq(unsigned char ml,unsigned int chr1,unsigned int chr2,unsigned char *TxBuffer)
{
    MBVarStruct *MBRptr;
    float datf;
    uchar *ptr;
    uint i,j,p;
    uchar k,m,ucTNumb=0;
    uchar n;
    uint jyh=0;
    union bh32
    {
        float datf32;
        ulng datu32;
        long datl32;
        s32 dats32;
        uchar datu8[4];
    }dat32;
    union bh16
    {
        uint datu16;
        uchar datu8[2];
    }dat16;

    /*union qstr
        {
        QString QStr10;
        uchar datu8[10];
        }datqstr10;*/

    i = chr2;
    k = MBjcjcq(chr1);
    if(k == 0xff){
        ucTNumb=MBfycm(ml,4,TxBuffer);			//
        return ucTNumb;
    }
    MBRptr = (MBVarStruct *)&MBReg[k];
    p = MBRptr->MBAdr;
    ptr = (uchar *)&TxBuffer[0];
    *ptr++ = Addr;
    *ptr++ = ml;
    ptr++;										//
    j = 0;										//
    while(i > 0){
        k = MBRptr->MBTp;						//
        switch(k)
        {
        case 0x00:							//浮点数，发送浮点数
            dat32.datf32 =*(float*)(MBRptr->MBPtr);
            //dat32.datf32 =fToHexf(dat32.datf32);
            for(m=0;m<4;m++){
                *ptr++ = dat32.datu8[3 - m];
            }
            if(i < 2) i = 0;
            else i -= 2;
            j += 4;
            p += 2;
            break;
        case 0x10:							//32位整数
            dat32.datl32=*(long*)(MBRptr->MBPtr);
            for(m=0;m<4;m++){
                *ptr++ = dat32.datu8[3 - m];
            }
            if(i < 2) i = 0;
            else i -= 2;
            j += 4;
            p += 2;
            break;

        case 0x20:							//
            datf =*(float*)(MBRptr->MBPtr);
            datf =Hextof(datf);
            dat32.dats32 = (int)datf;            //wagnzhen add
            /*datf =*(float*)(MBRptr->MBPtr);
        datf =fToHexf(datf);
        if(datf >= 0) dat32.dats32 = (s32)(datf + 0.5);
                    else dat32.dats32 = (s32)(datf - 0.5);*/
            for(m=0;m<4;m++){
                *ptr++ = dat32.datu8[3 - m];
            }
            if(i < 2) i = 0;
            else i -= 2;
            j += 4;
            p += 2;
            break;
        case 0x35:							//u8
            *ptr++ = 0;
            *ptr++ = *(uchar*)MBRptr->MBPtr;
            i--;
            j += 2;
            p++;
            break;
        case 0x33:							//u16
            dat16.datu16 = *(uint*)MBRptr->MBPtr;
            *ptr++ = dat16.datu8[1];
            *ptr++ = dat16.datu8[0];
            i--;
            j += 2;
            p++;
            break;

        case 0x01:
            QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
            QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
            QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
            const char*  ch;
            std::string st=(*(QString *)MBRptr->MBPtr).toStdString();
            ch=st.c_str();
            n=(*(QString *)MBRptr->MBPtr).toLocal8Bit().length();
            qDebug() << "length" <<n <<endl;
            for(m=0;m<n;m++)
                //*ptr++=(uchar)(*(QString *)MBRptr->MBPtr)[m];
                *ptr++=*ch++;
            for(m=0;m<10-n;m++)
                *ptr++=0;
            i-=5;

            j+=10;
            p+=5;
            QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
            QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
            QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese

        }
        MBRptr++;
        if(p != MBRptr->MBAdr) i=0;				//
    }
    TxBuffer[2] = j;
    jyh = CRC16(TxBuffer,j + 3);
    TxBuffer[j+3] = jyh % 256;
    TxBuffer[j+4] = jyh / 256;
    ucTNumb = j+5;						//
    return ucTNumb;

}


/***********************************************************

*************************************************************/
float PrintPort::fToHexf(float ft)
{
    ulng ulHex=1;
    uchar k,i;
    float ln;
    k=Point;
    for(i=0;i<k;i++)
    {
        ulHex=ulHex*10;
    }
    ln=(float)ft/ulHex ;
    return ln;
}

/***********************************************************
函数名称：void Hextof
功能描述：浮点数转整形
返   回：无
*************************************************************/
float PrintPort::Hextof(float ft)
{
    ulng ulHex=1;
    uchar k,i;
    float ln;
    k=Point;
    for(i=0;i<k;i++)
    {
        ulHex=ulHex*10;
    }
    ln=ft*ulHex ;

    return ln;
}


/***********************************************************
函数名称：void HexUtof
功能描述：长整形转浮点数
返   回：无
*************************************************************/
float PrintPort::HexUtof(long ft)
{
    float ulHex=1.0;
    uchar k,i;
    float ln;
    k=Point;
    for(i=0;i<k;i++)
    {
        ulHex=ulHex*10.0;
    }
    ln=(float)((float)ft/ulHex) ;
    qDebug()<<"ln"<<ln<<endl;
    return ln;
}
/***********************************************************

*************************************************************/
uchar PrintPort::MBjcjcq(uint chr)
{
    MBVarStruct *MBRptr;						//
    uint i;
    uchar k=0;

    MBRptr = (MBVarStruct *)&MBReg[0];
    i = chr;
    while(MBRptr->MBAdr < i+1){
        if(i == MBRptr->MBAdr){
            return(k);
        }
        MBRptr++;
        k++;
    }
    //qDebug()<<"1"<<endl;
    return (0xff);

}


