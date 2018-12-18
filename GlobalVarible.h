#ifndef GLOBALVARIBLE_H
#define GLOBALVARIBLE_H

#include <QReadWriteLock>
#include <QQueue>
#include <QVector>
#include <QMetaType>
#include <QDebug>
#include <QList>
#include <QTextStream>
#include <QStringList>
#include <vector>
#include <QVector>
#include <algorithm>
#include <QtAlgorithms>
#include <QProcess>
#include <QTimer>
#include <QMutex>
#include <unistd.h>
#include "QSettings"
#include <QTableView>
#include <QStandardItem>
#include "cali.h"
#include "about.h"
#include "mysqlsheet.h"
#include "dataexport.h"
#define    ulng    unsigned long
#define    s32     signed long
//#define    uint    unsigned int
#define arm
#define GPIO_TO_PIN(bank, gpio) (32 * (bank-1) + (gpio))
#define	PIN_PB25	GPIO_TO_PIN(2, 25)	//print
#define	PIN_PB24	GPIO_TO_PIN(2, 24)	//RS485
#define	PIN_PA31	GPIO_TO_PIN(1, 31)	//USB
#define	PIN_PA30	GPIO_TO_PIN(1, 30)	//LCD
#define	PIN_PC10	GPIO_TO_PIN(3, 10)	//蜂鸣器
#define	PIN_PC10	GPIO_TO_PIN(3, 10)	//
#define	PIN_PD6	    GPIO_TO_PIN(4,  6)	//AD
#define PIN_PC8     GPIO_TO_PIN(3, 8)
#define PIN_PC29     GPIO_TO_PIN(3, 29)
#define PIN_PB25_H		::ioctl(fd_gpio, HIGH, PIN_PB25)
#define PIN_PB25_L		::ioctl(fd_gpio, LOW, PIN_PB25)

#define PIN_PB24_H		::ioctl(fd_gpio, HIGH, PIN_PB24)
#define PIN_PB24_L		::ioctl(fd_gpio, LOW, PIN_PB24)

#define PIN_PA30_H		ioctl(fd_gpio, HIGH, PIN_PA30)
#define PIN_PA30_L		ioctl(fd_gpio, LOW, PIN_PA30)

#define PIN_PC10_H		ioctl(fd_gpio, HIGH, PIN_PC10)
#define PIN_PC10_L		ioctl(fd_gpio, LOW, PIN_PC10)

#define PIN_PD6_H		ioctl(fd_gpio, HIGH, PIN_PD6)
#define PIN_PD6_L		ioctl(fd_gpio, LOW, PIN_PD6)

#define PIN_PC29_H		ioctl(fd_gpio, HIGH, PIN_PC29)
#define PIN_PC29_L		ioctl(fd_gpio, LOW, PIN_PC29)


#define	HIGH	1
#define	LOW		0

//#define OBO_TIMER_INTERVAL 200

/*enum BaudRateType
{  
    BAUD600,
    BAUD1200, 
    BAUD2400,
    BAUD4800,
    BAUD9600,  
    BAUD19200,
    BAUD38400,   
    BAUD57600,
    BAUD115200

};
enum Comm232Type
{  
    MODE_CONTINUE,
    MODE_STABLE,
    MODE_CLOSE
};
enum Comm485Type
{
    MODE_MODBUS,
    MODE_CLOSE485

};

enum DataBitsType
{
    DATA_8,
    DATA_7,
    DATA_6,
    DATA_5
};

enum ParityType
{
    PAR_NONE,
    PAR_ODD,
    PAR_EVEN,
    PAR_MARK,               //WINDOWS ONLY
    PAR_SPACE
};

enum StopBitsType
{
    STOP_1,
    STOP_1_5,               //WINDOWS ONLY
    STOP_2
};

enum FlowType
{
    FLOW_OFF,
    FLOW_HARDWARE,
    FLOW_XONXOFF
};*/
typedef  struct
{
    int productCode;
    QString productName;
    QString productOrigin;
    float productPrice;
    QString productDescribe;
}PRODUCT_INFO;
extern PRODUCT_INFO currentproductInfor;
extern PRODUCT_INFO productInfor[20];
extern int productNum;
extern int tempProductNumIndex;
extern float currentWeight;
extern int productCashNum;
typedef  struct
{
    PRODUCT_INFO productCash;
    float weight;
    float money;
}PRODUCT_INFOCash;
extern PRODUCT_INFOCash productInforCash[20];
extern float total_money;
extern float totalmoney_print;
extern int operatorID;
extern unsigned char InsertRecordTimes;

typedef struct 
{

int RecCode;
QString RecproductName;
float RecproductPrice;
float Recweight;
float Recmoney;


}Record;

typedef struct
{
uchar Year;
uchar Month;
uchar Day;
uchar Hour;
uchar Minute;
uchar Second;
}Time;

typedef struct
{
//uchar Year;
//uchar Month;
//uchar Day;
QString StartTime;
QString EndTime;
QString productName;
QString userID;
int numCount;
float AccWeight;
}Report;

typedef struct 
{
int SqlCode;
QString SqlproductName;
float SqlproductPrice;
float Sqlweight;
//float Recmoney;
QString SqlTime;
}SqlRecord;//kevin

extern SqlRecord Sql;
extern Report RecDaily;
extern Report RecMonth;
extern Report RecAll;
extern Report RecProduct;
extern Report RecUser;
extern Time RecTimeLimit;
extern Time RecTime;
extern int RecproductNum;
extern float Rectotal_money;
extern Record Rec[20];
extern uint TotfnBusiness;
extern uint Totfn;
extern float Totfa;//kevin
extern uint Totfnc;
extern uint Totfac;
extern float PrintLq;
extern float LastWt;
extern int LastTime;

extern int Unit;
extern unsigned char PrintMode;
extern unsigned char PrintCodeHeight;
extern unsigned char PrintCodeType;
extern unsigned char PrintFontSize;
extern unsigned char PrintFontSize2;
extern unsigned char PrintLableSize;

extern unsigned char Year;                                                    //
extern  unsigned char Month;                                                   //
extern unsigned char Day;                                                     //
extern unsigned char Hour;                                                    //
extern unsigned char Minute;                                                  //
extern unsigned char Second;
extern unsigned char Decp;

//extern uchar b_Net;
extern uchar b_PrintCompany;
extern uchar b_Comr;
extern uchar b_PrintAuto;
extern uchar b_PrintRetZero;
extern uchar b_PrintHeader;
extern uchar b_Save;
extern uchar b_PrintStable;
//extern unsigned char b_Stab;
extern unsigned char b_OL;
extern unsigned char b_Ydy;
extern unsigned char b_Ydy1;

extern unsigned char b_Print;
extern unsigned char b_Print1;
extern unsigned char b_Ylj;//kevin
extern unsigned char control_485;
extern unsigned char Addr;
extern unsigned char AutoAcc;//kevin
extern unsigned char CodeLength;
extern uchar QrRidx;
extern uchar QrRecvBuff[100];//kevin
extern uchar CodeRecvBuff[100];
extern uchar QrSendBuff[20];
extern QString Qrstr;//二维码数据
extern QString PrintCompanyName;
extern QString CompanyWebsite;
extern QString CompanyTel;
extern QString CompanyAddr;
extern QString CompanyLabel;

extern int fd_gpio;
//comm
extern uchar CommType;
extern uchar  CommType232;
extern uchar  Tmode_232;
extern uchar  Tmode_485;
//extern uchar BaudRate_232;
extern uchar BaudRate_232,BaudRate_485;
extern uchar DataBits_232,DataBits_485;
extern uchar  ParityMode_232,ParityMode_485;
extern uchar StopBits_232,StopBits_485;
//FlowType Flow
typedef struct insert_data
{
    QString data_model[17];
}DATA_STRUCT;

extern QString ServerIp;
extern int ServerPort;

extern QString UDPServerIp;
extern int UDPServerPort;
extern QByteArray SendtoTCPUDP;
extern QString LocalIp;

extern QString A31Version;
extern QString A31SN;
extern QString interface;
extern QString TokenData;
extern uchar httpDownstate;
extern int StartPosition;
extern int DocLength;
extern QString QRcodeTemp;
extern bool QRcodeFlag;
extern bool OrderBusiness;
extern int PatternOfPayment;
extern QString Auth_Code;
extern int QRcodeType;
Q_DECLARE_METATYPE(DATA_STRUCT)

#endif  // GLOBALVARIBLE_H


