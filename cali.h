#ifndef CALI_H
#define CALI_H
#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QTextCodec>
//#include "configsetting.h"
/***************************/
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <assert.h>
#include <linux/videodev2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/signal.h>
#include <linux/watchdog.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>
#include <assert.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <termios.h>
#include <errno.h>
#include <linux/input.h>
#include <linux/types.h>
#include <errno.h>
#include <GlobalVarible.h>
#include <math.h>

#define I2C_RETRIES 0x0701
#define I2C_TIMEOUT 0x0702
#define I2C_RDWR 0x0707
// not include READ/WRITE bit
#define I2C_ADDR 0x52
//#define    uchar   unsigned char
//#define    uint    unsigned int
//#define    ulng    unsigned long
#define ADS1232_SET_SPS80		ioctl(fd_ads1232, 0, 1)
#define ADS1232_SET_SPS10		ioctl(fd_ads1232, 0, 0)
#define beep_start		ioctl(fd_iouart, 0, 0)
#define filename0 "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"
#define filename1 "/sys/bus/iio/devices/iio:device0/in_voltage1_raw"
#define filename2 "/sys/bus/iio/devices/iio:device0/in_voltage2_raw"
#define filename3 "/sys/bus/iio/devices/iio:device0/in_voltage3_raw"
#define filename4 "/sys/bus/iio/devices/iio:device0/in_voltage4_raw"
#define filename5 "/sys/bus/iio/devices/iio:device0/in_voltage5_raw"
#define filename6 "/sys/bus/iio/devices/iio:device0/in_voltage6_raw"
#define filename7 "/sys/bus/iio/devices/iio:device0/in_voltage7_raw"
#define filename8 "/sys/bus/iio/devices/iio:device0/in_voltage8_raw"
#define filename9 "/sys/bus/iio/devices/iio:device0/in_voltage9_raw"
#define filename10 "/sys/bus/iio/devices/iio:device0/in_voltage10_raw"
#define filename11 "/sys/bus/iio/devices/iio:device0/in_voltage11_raw"
/***************************/
//参数设置部分参数
extern int Unit;                              //unit
extern unsigned char FuncSelect;                        //function
extern unsigned char BaudRate;                    	    //audRate
extern unsigned char Output232value;                    //P4
extern unsigned char Output232type;                     //P5
extern unsigned char OffTime;                    	    //P6省电时间选择
extern unsigned char Zono;                              //P7 零点跟踪
extern unsigned char ZeroKeyVal;                        //P8置零范围
extern unsigned char OnZero;                            //P9
extern unsigned char FilterStep;                        //P10
extern unsigned char StableTime;                        //P11
extern unsigned char StableRange;                       //P12稳定范围
extern unsigned char FreshTime;                         //P13
extern unsigned char LedLight;                          //P14
extern unsigned long  WeightTot;                        //总累计值
extern unsigned int  AccNum;                            //累计数量
extern unsigned char Nbig;
extern unsigned char b_BigLoading;
extern float  Full;		                        //实际使用满值
extern float  CalFull;                          //标定用满值
extern int AD_Zero;
extern long  Start_Zero;
extern long  Lastad;
extern unsigned long  FilterArray[] ;
extern long  AdData;
extern float  LowValue,HighValue;
extern unsigned long  BigData;
extern unsigned char Point;                       	 //小数点位置
extern unsigned char Rati;                		 //分度值
extern float SjRati;
extern float Adsum;
extern float Tare;
extern float Gross;
extern long CountGross;
extern long CountNet;
extern long CountTare;
extern float sam ;
extern char btemp;
extern float Fengzhi,Baochi;
extern float  Net ;
extern float  Adload ;
extern float TempNet;
extern float Incode;
extern int  CurData;
extern float Rri;
extern float AveNet;
extern float Ave[32];
extern float LastAve,TempAve;
extern int fd_ads1232;
extern int keys_fd;
extern bool  b_Zero;
extern bool b_Net;
extern bool  b_Stable;
extern int  b_Incode;
extern int  b_login;
extern int  KeyNumb;
extern int  usernumb;
extern int  TimDly2;
extern int  quanxian;
extern int  quanxiantemp;
extern int  iniep;
extern float TempGross;
extern long  Grosstolong;
extern long  Counttolong;
extern long   samtemp;
extern uchar Nout;
extern QString UserName;
extern QString UserPassword;
extern QString USN[10];
extern QString USP[10];
extern QString USQ[10];

extern int advalue;
extern FILE *fp;
extern float fvalue;
extern int loginflag;
extern int beepflag;
extern bool keyflag;
extern long testi;
extern int fd_iouart;
extern unsigned char cnt;
extern unsigned char b_newad;
extern unsigned char TimStab;
extern unsigned char b_ykj;

extern bool canNotSerzero; //wz  20181029
extern bool canNotKTare;   //wz  20181029

class cali
{
private:
public:
    cali();
    ~cali();
public:
struct i2c_msg
    {
        unsigned short addr;
        unsigned short flags;
#define I2C_M_TEN 0x0010
#define I2C_M_RD 0x0001
        unsigned short len;
        unsigned char *buf;
    };
    struct i2c_rdwr_ioctl_data
    {
        struct i2c_msg *msgs;
        int nmsgs;
    };
   /*  union ads_value
       {
           unsigned char buffer[4];
           unsigned int  val;
       };*/
    union ads_value
    {
        unsigned char buffer[256];
        unsigned long  val[64];
    };
 union v
    {
        float dw;
        unsigned long dm;
        float df;
        struct
        {
            unsigned char hi;
            unsigned char hi1;
            unsigned char lo1;
            unsigned char lo;
        } w;
    }float4char;
public:
   void Initial(void);
   long RD1232(void);
   void AdFilter(void);
   void AdFilter1(void);
   void AdFilter2(void);
   void CalWeigh(void);
   void FreshDisp(void);
   void SetZero(unsigned char ch);
   void StartZero(unsigned char ch);
   unsigned char KeyScan(void);
   void KTare(void);
   void ArgIni(void);
   void ArgSave(void);
     void ArgSave1(void);
   void ArgRead(void);
     void ArgRead1(void);
   void ZTrace(unsigned char ch);
   void BtRead(void);
   void Load_Big(void);



};


#endif // CALI_H
