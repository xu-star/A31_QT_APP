#ifndef CALI_H
#define CALI_H
#include <QMainWindow>
#include <QTimer>
#include <QString>
#include "passwordpanel.h"
#include <QTextCodec>
//#include "configsetting.h"
/***************************/
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
//#define    uchar   unsigned char
//#define    uint    unsigned int
//#define    ulng    unsigned long
#define ADS1232_SET_SPS80		ioctl(fd_ads1232, 0, 1)
#define ADS1232_SET_SPS10		ioctl(fd_ads1232, 0, 0)
/***************************/


class cali
{
private:
public:
    cali();
    ~cali();
public:
//参数设置部分参数
    unsigned char Unit;                              //P1
    unsigned char FuncSelect;                        //P2
    unsigned char BaudRate;                    	 //P3波特率
    unsigned char Output232value;                    //P4
    unsigned char Output232type;                     //P5
    unsigned char OffTime;                    	 //P6省电时间选择
    unsigned char Zono;                              //P7 零点跟踪
    unsigned char ZeroKeyVal;                        //P8置零范围
    unsigned char OnZero;                            //P9
    unsigned char FilterStep;                        //P10
    unsigned char StableTime;                        //P11
    unsigned char StableRange;                       //P12稳定范围
    unsigned char FreshTime;                         //P13
    unsigned char LedLight;                          //P14
    unsigned long  WeightTot;                         //总累计值
    unsigned int  AccNum;                            //累计数量
    unsigned long  Full;		                 //实际使用满值
    unsigned long  CalFull;                           //标定用满值
    long  AD_Zero;
    long  Start_Zero;
    unsigned long  FilterArray[] ;
    long  AdData;
    unsigned long  LowValue,HighValue;
    unsigned long  BigData;
    unsigned char Point;                       	 //小数点位置
    unsigned char Rati;                		 //分度值
    float Adsum;
    float Tare;
    float Gross;
    float TempGross;
    float Fengzhi,Baochi;
    float Net ;
    float TempNet;
    float Incode;
    long  CurData;
    float Rri;
    float AveNet;
    float Ave[32];
    float LastAve,TempAve;
      union ads_value
       {
           unsigned char buffer[4];
           unsigned int  val;
       };
    int fd_ads1232;
public:
   void Initial(void);
   long RD1232(void);
   void AdFilter(void);
   void CalWeigh(void);
   void FreshDisp(void);

};


#endif // CALI_H
