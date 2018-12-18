#include "cali.h"
//参数设置部分参数
int Unit;                              //P1
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
unsigned char Nbig;
unsigned char b_BigLoading;
float  Full;		                 //实际使用满值
float CalFull;                           //标定用满值
int AD_Zero;
long  Start_Zero;
long  Lastad;
unsigned long  FilterArray[8] ;
long  AdData;
float  LowValue,HighValue;
unsigned long  BigData;
unsigned char Point;                       	 //小数点位置
unsigned char Rati;                		 //分度值
float SjRati;
float Adsum;
float Tare;
float Gross;
long CountGross;
long CountNet;
long CountTare;
char btemp;
float Fengzhi,Baochi;
float Net ;
float sam ;
float  Adload ;
float TempNet;
float Incode;
int  CurData;
float Rri;
float AveNet;
float Ave[32];
float LastAve,TempAve;
bool  b_Zero;
bool b_Net;
int  b_Incode;
int  b_login;
int  KeyNumb;
int  usernumb;
bool  b_Stable;
int  TimDly2;
int quanxian;
int quanxiantemp;
int iniep;
float TempGross;
long  Grosstolong;
long  Counttolong;
long   samtemp;
bool keyflag;
int loginflag;
int beepflag;
uint Totfnc;
uint Totfac;
uint Totfn;
float Totfa;
float LastWt;
int LastTime;
float PrintLq;
uchar b_PrintCompany;//kevin
uchar b_Comr;
uchar b_Ylj;
uchar b_Ydy;
uchar b_Ydy1;
uchar b_Print;
uchar b_Print1;
uchar b_PrintAuto;
uchar b_PrintRetZero;
uchar b_PrintHeader;
uchar b_Save;
uchar b_PrintStable;
uchar Nout;
uchar AutoAcc;
unsigned char b_ykj;
unsigned char TimStab;
unsigned char cnt;
unsigned char b_newad;
//unsigned char b_Stab;
unsigned char b_OL;
//unsigned char b_Comr;
unsigned char control_485;
unsigned char Addr;
unsigned char CodeLength;
uchar QrRidx;
uchar QrRecvBuff[100];//kevin
uchar CodeRecvBuff[100];
uchar QrSendBuff[20];
unsigned char PrintMode;
//unsigned char PrintCode;
unsigned char PrintCodeHeight;
unsigned char PrintCodeType;
unsigned char PrintLableSize;
uchar PrintFontSize;//kevin
uchar PrintFontSize2;
int fd_iouart;
int advalue;
FILE *fp;
float fvalue;
long testi;
QString Qrstr;
QString PrintCompanyName;//kevin
QString CompanyWebsite;
QString CompanyAddr;
QString CompanyTel;
QString CompanyLabel;

QString UserName;
QString UserPassword;
QString USN[10];
QString USP[10];
QString USQ[10];

bool canNotSerzero; //wz  20181029
bool canNotKTare;   //wz  20181029

union ads_value
{
    unsigned char buffer[4];
    unsigned int  val;
};
int fd_ads1232;
int keys_fd;
uchar ZL[4]=													 //
{																	 //
        2,4,10,20															 //
};
cali::cali()
{

}

cali::~cali()
{

}
/**************************************************
 Description:Initial
 Argument   : none
 Return     : none
**************************************************/
void cali::Initial(void)
{
    // int keys_fd;
    canNotSerzero = false; //wz  20181029
    canNotKTare = false;   //wz  20181029
    fd_ads1232 = open("/dev/ads1232", O_RDWR | O_NONBLOCK);
    if(FilterStep==4)
        ADS1232_SET_SPS80;
    else
        ADS1232_SET_SPS10;
    keys_fd = open("/dev/input/event0",O_RDONLY|O_NONBLOCK);
}
/**************************************************
 Description:RD1232
 Argument   : none
 Return     : none
**************************************************/
long cali::RD1232()
{

    union ads_value ad;
    uchar tempcnt=0;
    cnt=0;
    // ad.val[] = 0;
    //read(fd_ads1232, ad.buffer, 4);
    // read(fd_ads1232, ad.buffer, sizeof(ad.buffer));

    tempcnt = read(fd_ads1232, ad.buffer, sizeof(ad.buffer));
    // printf("------tempcnt ============= ==========%d ----------------------\r\n",tempcnt);
    if(tempcnt<4)
    {
        b_newad=0;
        return Lastad;
    }
    else
        b_newad=1;
    // printf("------read_cnt ============= %d ----------------------\r\n", cnt / 4);

    cnt=tempcnt / 4-1;
    //  printf("------read_cnt = %d ----------------------\r\n", cnt );
    Lastad=ad.val[cnt];
    //      printf("------ad.val[cnt] = %d ----------------------\r\n", ad.val[cnt] );
    return ad.val[cnt];

}
/**************************************************
 Description:AdFilter(
 Argument   : none
 Return     : none
**************************************************/
void cali::AdFilter(void)
{
    uchar i;
    uchar admax,admin,n,admax2,admin2;													     //

    FilterArray[Nout++]=AdData;
    if(Nout>=8)
    {
        Nout=0;
    }
    admax=0;
    admin=0;
    admax2=0;
    admin2=0;
    for(i=1;i<8;i++)
    {
        if(FilterArray[i]>FilterArray[admax]) admax=i;
        if(FilterArray[i]<FilterArray[admin]) admin=i;
    }

    Adsum=0;
    n=0;
    for (i=0; i<8; i++)           //
    {
        if(FilterArray[i]==0) continue;
        if(i==admax||i==admin) continue;
        Adsum=Adsum+FilterArray[i];              //
        n++;
    }                                        //
    if(n)
        CurData=Adsum/n;                                          //
    else
        CurData=AdData;
}
/**************************************************
 Description:AdFilter1
 Argument   : none
 Return     : none
**************************************************/
void cali::AdFilter1(void)
{
    uchar i;
    uchar admax,admin,n,admax2,admin2;													     //

    FilterArray[Nout++]=AdData;
    if(Nout>=6)
    {
        Nout=0;
    }
    admax=0;
    admin=0;
    admax2=0;
    admin2=0;
    for(i=1;i<6;i++)
    {
        if(FilterArray[i]>FilterArray[admax]) admax=i;
        if(FilterArray[i]<FilterArray[admin]) admin=i;
    }

    Adsum=0;
    n=0;
    for (i=0; i<6; i++)           //
    {
        if(FilterArray[i]==0) continue;
        if(i==admax||i==admin) continue;
        Adsum=Adsum+FilterArray[i];              //
        n++;
    }                                        //
    if(n)
        CurData=Adsum/n;                                          //
    else
        CurData=AdData;
}
/**************************************************
 Description:AdFilter2
 Argument   : none
 Return     : none
**************************************************/
void cali::AdFilter2(void)
{
    uchar i;														     //
    long TempLong;													 //

    TempLong = AdData-FilterArray[Nout];						 //得到差值
    if(TempLong>=0)
        TempLong=TempLong;
    else
        TempLong=0-TempLong;
    if(TempLong<30)											 //
    {																 //
        FilterArray[Nout++]=AdData;
        if(Nout>=4)
        {
            Nout=0;
        }
        Adsum=0;
        for(i=0;i<4;i++)									 //
        {														 //
            Adsum+=FilterArray[i];      								 //
        }														 //
        CurData=(Adsum/4);
        //
    }																 //
    else															 //
    {																 //

        for(i=0;i<4;i++)									 //
        {														 //
            FilterArray[i]=AdData;      								 //
        }														 //
        CurData=AdData;												 //

    }
}
/**************************************************
 Description:CalWeigh
 Argument   : none
 Return     : none
**************************************************/
void cali::CalWeigh(void)
{
    float ln,temp,temp2,temp4,temp5;
    long Grtemp;
    char i;
    if(Unit==1)
    {
        Incode=(Rri)*(CurData-AD_Zero);
        Full=CalFull;
    }
    else if(Unit==2)
    {
        Incode=(Rri)*(CurData-AD_Zero)*2.20462;
        if((Rati==2)||(Rati==20))
        {
            Full=CalFull*5/2;
        }
        else
        {
            Full=CalFull*2.0;
        }
    }
    else
    {
        Incode=(Rri)*(CurData-AD_Zero)*1000;
        if((Rati==2)||(Rati==20))
        {
            Full=CalFull*10;
        }
        else
        {
            Full=CalFull*10;
        }
    }
    temp=Incode/10.0;
    QString temp3=QString::number(temp,'f',Point);
    switch(Point)
    {
    case 0:
        //Grtemp=long(temp);
        temp2=temp3.toFloat();
        Grtemp=long(temp2);
        Grtemp=(Grtemp+Rati/2)/Rati*Rati;
        Grosstolong=Grtemp;
        Gross=float(Grtemp);
        break;
    case 1:
        // Grtemp=long(temp*10);
        temp2=temp3.toFloat();
        Grtemp=long(temp2*10);
        Grtemp=(Grtemp+Rati/2)/Rati*Rati;
        Grosstolong=Grtemp;
        Gross=float(Grtemp)/10;
        break;
    case 2:
        // Grtemp=long(temp*100);
        temp2=temp3.toFloat();
        Grtemp=long(temp2*100);
        Grtemp=(Grtemp+Rati/2)/Rati*Rati;
        Grosstolong=Grtemp;
        Gross=float(Grtemp)/100;
        break;
    case 3:
        //Grtemp=long(temp*1000);
        temp2=temp3.toFloat();
        Grtemp=long(temp2*1000);
        Grtemp=(Grtemp+Rati/2)/Rati*Rati;
        Grosstolong=Grtemp;
        Gross=float(Grtemp)/1000;
        break;
    case 4:
        // Grtemp=long(temp*10000);
        temp2=temp3.toFloat();
        Grtemp=long(temp2*10000);
        Grtemp=(Grtemp+Rati/2)/Rati*Rati;
        Grosstolong=Grtemp;
        Gross=float(Grtemp)/10000;
        break;

    default:
        break;
    }


    if(Gross>=0)
        // ln=Gross;
        ln=Grosstolong;
    else
        //ln=0-Gross;
        ln=0-Grosstolong;

    //  ln=Fabs(Gross*2);
    if(ln<Rati)
    {
        b_Zero=1;
        Gross=0;
    }
    else
        b_Zero=0;


    if(sam!=0){
      temp4=(Incode/10.0)/sam;
      CountGross=long(temp4+0.5);
      CountNet=CountGross-CountTare;
    }

    Net=Gross-Tare;


    if(Net<=PrintLq&&Net>=-PrintLq)
    {
        b_Ylj=0;
        b_Ydy=0;
	 b_Ydy1=0;
    }
    /*if(Net<0.5*Rati)
               {
               ZeroPass=1;
               Fengzhi=0;
               AveStep=0;
                }*/
    //  qDebug()<<"TempGross"<<TempGross;//
    //  qDebug()<<"Grosstolong"<<Grosstolong;//
    //if((TempGross>Grosstolong+0.5*Rati)||(TempGross<Grosstolong-0.5*Rati))                                                //如果临时毛重与上次毛重差别在1个分度以上
    if((TempGross>Gross+SjRati)||(TempGross<Gross-SjRati))
    {
        //TimDly2=80*StableTime;
        TimStab=0;
        b_Stable=0;                                                                                      //清除稳定标志
        //清零稳定次数
    }
    else if(TimStab>StableTime*5)
    {
        b_Stable=1;
    }
    if(TimDly2==0)			//100ms取一次与当前的比较
    {
        TimDly2=2;
        TempGross=Gross;
    }


}
/**************************************************
 Description:FreshDisp
 Argument   : none
 Return     : none
**************************************************/
void cali::FreshDisp(void)
{

}


/**************************************************
 Description:SetZero
 Argument   : none
 Return     : none
**************************************************/
void cali::SetZero(unsigned char ch)
{
    float ln,temp1,temp2;															 //
    float ft;
    long temp;

   // if(b_Net&&!b_Incode)return;
    if(b_Net)return;
   if(Unit==1)ft=(CurData-Start_Zero)*Rri/10.0;
    else if(Unit==2)
        ft=(CurData-Start_Zero)*Rri*2.20462/10.0;
    else
         ft=(Rri)*(CurData-Start_Zero)*100;//
   QString temp3=QString::number(ft,'f',Point);
   switch(Point)
   {
   case 0:
       //Grtemp=long(temp);
       temp2=temp3.toFloat();
       temp=long(temp2);
       temp=(temp+Rati/2)/Rati*Rati;
       temp1=float(temp);
       break;
   case 1:
       // Grtemp=long(temp*10);
       temp2=temp3.toFloat();
       temp=long(temp2*10);
       temp=(temp+Rati/2)/Rati*Rati;
       temp1=float(temp)/10;
       break;
   case 2:
       // Grtemp=long(temp*100);
       temp2=temp3.toFloat();
       temp=long(temp2*100);
       temp=(temp+Rati/2)/Rati*Rati;
       temp1=float(temp)/100;
       break;
   case 3:
       //Grtemp=long(temp*1000);
       temp2=temp3.toFloat();
       temp=long(temp2*1000);
       temp=(temp+Rati/2)/Rati*Rati;
       temp1=float(temp)/1000;
       break;
   case 4:
       // Grtemp=long(temp*10000);
       temp2=temp3.toFloat();
       temp=long(temp2*10000);
       temp=(temp+Rati/2)/Rati*Rati;
       temp1=float(temp)/10000;
       break;

   default:
       break;
   }
    if(temp1>0)
        ln=temp1;
    else
        ln=-temp1;
    switch(ch)                                                          //置零范围
    {																 //
    case 6:                                                          //0，不置零
        break;                                                      //
    case 1:                                                          //1，2%
    case 2:                                                          //2，4%
    case 3:                                                          //3，10%
    case 4:                                                          //4，20%
        if(ln<=CalFull*ZL[ch-1]*0.01)                                  //
        {
            qDebug()<<"ln==============================="<<ln;//
            qDebug()<<"CalFull*ZL[ch-1]*0.01=============================="<<CalFull*ZL[ch-1]*0.01;//
            AD_Zero=CurData; 										 //
        }                                                       //
        else 														 //
        {
            canNotSerzero = true;
            QMessageBox::warning(NULL, "警告", "超出置零范围", QMessageBox::Yes, QMessageBox::Yes);											 //
        }                                    					 //
        break;                                                      //
    default:                                                         //>4，100%
        AD_Zero=CurData;                                            //
        break;                                                      //
    }
}
/**************************************************
 Description:KeyScan(
 Argument   : none
 Return     : none
**************************************************/
unsigned char cali::KeyScan(void)
{

    //  int keys_fd;
    //char ret [2];
    struct input_event t;
    // keys_fd = open("/dev/input/event0",O_RDONLY);
    if (read(keys_fd, &t, sizeof(t)) == sizeof(t))

    {
        if (t.type == EV_KEY)
        {
            // if (t.value == 0 || t.value == 1)
            if (t.value == 1)
            {
                keyflag=true;
                qDebug() <<"keyflag22222222222222222222================"<<keyflag;
                printf("key %d %s \n",t.code,(t.value)?"Pressed":"Released");
                KeyNumb=t.code;
                beep_start;
            }
        }
    }
    //   printf("key %d %s \n",t.code,(t.value)?"Pressed":"Released");
    // close(keys_fd);
}
/**************************************************
 Description:tare
 Argument   : none
 Return     : none
**************************************************/
void cali::KTare(void)
{
    if(!b_Stable||Gross<0)
    {
        canNotKTare = true;
        return;					 //	增加毛重小于零不能除皮功能
    }
    if(b_Zero)
    {
        b_Net=0;
        Tare=0;
        CountTare=0;
    }                                                                 //
    else                                                                //
    {
        b_Net=1;                                                         //
        Tare=Gross;
        CountTare=CountGross;
    }
}
/**************************************************
 Description: 参数初始化，第一次写EEPROM时调用
 Argument   : none
 Return     : none
**************************************************/
void cali:: ArgIni(void)
{
    AD_Zero=562088;
    Rri=0.44;
    Point=3;
    AccNum=0;
    Rati=1;
    WeightTot=0;
    CalFull=10.000;
    Tare=0;
    CountTare=0;
    HighValue=0;
    LowValue=0;
    sam=0;
    ///PSet
    ////////////////////////////////////////////////////////////////////
    Unit=1;                                //P1
    FuncSelect=1;                          //P2
    BaudRate=1;                            //P3
    Output232value=1;                      //P4
    Output232type=5;                       //P5
    OffTime=1;                    	       //P6省电时间选择
    Zono=2;                                //P7零点跟踪
    ZeroKeyVal=2;                          //P8置零范围
    OnZero=4;                              //P9
    FilterStep=3;                          //P10
    StableTime=1;                          //P11
    StableRange=2;                         //P12稳定范围
    FreshTime=2;                           //P13
    LedLight=7;                            //P14
    iniep=30;                              //initail flag

    //////////////////////////////////////////////////////////////////////
}
/**************************************************
 Description: ZTrace()
 Argument   : none
 Return     : none
**************************************************/
void cali::ZTrace(unsigned char ch)                                                        //
{                                                                    //
    float ft2,ft,ln,Ratitemp;
    long temp;
    float temp1,temp2;//															 //
    if(!b_Stable)                                                        //不稳不进行判零和零位追踪
    {																 //                                                        //清零零点跟踪计数
        return;                                                         //
    }
    if(Unit==1)ft=(CurData-Start_Zero)*Rri/10.0;
     else if(Unit==2)
         ft=(CurData-Start_Zero)*Rri*2.20462/10.0;
     else
          ft=(Rri)*(CurData-Start_Zero)*100;//
    QString temp3=QString::number(ft,'f',Point);
    switch(Point)
    {
    case 0:
        //Grtemp=long(temp);
        temp2=temp3.toFloat();
        temp=long(temp2);
        temp=(temp+Rati/2)/Rati*Rati;
        temp1=float(temp);
        break;
    case 1:
        // Grtemp=long(temp*10);
        temp2=temp3.toFloat();
        temp=long(temp2*10);
        temp=(temp+Rati/2)/Rati*Rati;
        temp1=float(temp)/10;
        break;
    case 2:
        // Grtemp=long(temp*100);
        temp2=temp3.toFloat();
        temp=long(temp2*100);
        temp=(temp+Rati/2)/Rati*Rati;
        temp1=float(temp)/100;
        break;
    case 3:
        //Grtemp=long(temp*1000);
        temp2=temp3.toFloat();
        temp=long(temp2*1000);
        temp=(temp+Rati/2)/Rati*Rati;
        temp1=float(temp)/1000;
        break;
    case 4:
        // Grtemp=long(temp*10000);
        temp2=temp3.toFloat();
        temp=long(temp2*10000);
        temp=(temp+Rati/2)/Rati*Rati;
        temp1=float(temp)/10000;
        break;

    default:
        break;
    }							 //
    if(temp1<0)
        ln=0-temp1;
    else
        ln=0+temp1;
    if(ln>CalFull*0.02)return;											 //	跟踪范围：4%以内

    if(Gross>0)                                                       //4*Incode
        ft=Grosstolong;                                                       //
    else                                                               //
        ft=-Grosstolong;

    if(Zono==6)return;                                                 //零位跟踪范围是8，不跟踪
    if(ft<=Zono*Rati)                                               //零位跟踪依据
        // if(ln<=Zono*SjRati)
    {
       // if(ft>0.5*SjRati/Rati)												 //
            if(CurData>AD_Zero)
            AD_Zero++;									         //
        else if(CurData<AD_Zero) //if(ft<-0.5*SjRati/Rati)										 //
            AD_Zero--;	        								 //
        //
    }                                                                //
}
/**************************************************
 Description: StartZero()
 Argument   : none
 Return     : none
**************************************************/
void cali::StartZero(unsigned char ch)                                     //
{
    //unsigned long ln;
    float ft;
    if(b_Net)return;                                                    //
    if(Gross>0)
        ft=Gross;
    else
        ft=0-Gross;
    qDebug()<<"ft==============================="<<ft;//
    qDebug()<<"CalFull*ZL[ch-1]*0.01=============================="<<CalFull*ZL[ch-1]*0.01;//
    //ln=(ulng)((ft+Rati/2)/Rati*Rati);
    switch(ch)                                                          //置零范围
    {
    case 6:                                                      //0，不置零
        //       AD_Zero=0;
        break;                                                      //
    case 1:                                                          //1，2%
    case 2:                                                          //2，4%
    case 3:                                                          //3，10%
    case 4:                                                          //4，20%
        if(ft<=CalFull*ZL[ch-1]*0.01)                               //
        {
            AD_Zero=CurData;                                        //
        }
        else                                                        //
        {
            //  QMessageBox::warning(NULL, "警告", "超出置零范围", QMessageBox::Yes, QMessageBox::Yes);
        }
        //
        break;                                                      //
    default:                                                     //>4，100%
        AD_Zero=CurData;                                            //
        break;                                                      //
    }
}

/**************************************************
 Description: 写EEPROM时调用
 Argument   : none
 Return     : none
**************************************************/
void cali::ArgSave1(void)
{
    int fd,ret,temp;
    char buf[8];
    // char *bufw;

    fd = open("/sys/bus/i2c/devices/1-0050/eeprom", O_RDWR);//打开文件  /sys/bus/i2c/devices/1-0050/eeprom
    if (fd < 0)
    {
        printf("####i2c test device open failed####/n");

    }
    float4char.dw=Rri;
    buf[0]=float4char.w.hi;
    buf[1]=float4char.w.hi1;
    buf[2]=float4char.w.lo1;
    buf[3]=float4char.w.lo;
    float4char.dm=AD_Zero;
    buf[4]=float4char.w.hi;
    buf[5]=float4char.w.hi1;
    buf[6]=float4char.w.lo1;
    buf[7]=float4char.w.lo;


    lseek(fd, 0x00, SEEK_SET); //定位地址，地址是0x400
    /*  if ((size = write(fd, bufw, len)) < 0)//写入数据
             {
                 printf("write error\n");
                 return -1;
             }*/
    write(fd, buf, 8);
    printf("writeok\n");


    close(fd);
}
/**************************************************
 Description: 读EEPROM时调用
 Argument   : none
 Return     : none
**************************************************/
void cali:: ArgRead1()
{
    int fd,ret,temp;
    char buf[8];
    struct i2c_rdwr_ioctl_data e2prom_data;
    fd = open("/sys/bus/i2c/devices/1-0050/eeprom", O_RDWR);//打开文件  /sys/bus/i2c/devices/1-0050/eeprom
    if (fd < 0)
    {
        printf("####i2c test device open failed####/n");

    }
    buf[0]=0xFF;
    buf[1]=0xFF;
    buf[2]=0xFF;
    buf[3]=0xFF;
    buf[4]=0xFF;
    buf[5]=0xFF;
    buf[6]=0xFF;
    buf[7]=0xFF;

    lseek(fd, 0x00, SEEK_SET);//准备读，首先定位地址，因为前面写入的时候更新了当前文件偏移量，所以这边需要重新定位到0x400.
    read(fd, buf, 8);



    float4char.w.hi= buf[0];
    float4char.w.hi1=buf[1];
    float4char.w.lo1=buf[2];
    float4char.w.lo= buf[3];
    Rri=float4char.dw;
    qDebug()<<"Rri"<<Rri;//
    float4char.w.hi=buf[4];
    float4char.w.hi1=buf[5];
    float4char.w.lo1=buf[6];
    float4char.w.lo= buf[7];
    AD_Zero=float4char.dm;
    qDebug()<<"AD_Zero"<<AD_Zero;//


    close(fd);

}
/**************************************************
 Description: 写EEPROM时调用
 Argument   : none
 Return     : none
**************************************************/
void cali::ArgSave(void)
{
    int fd,ret,temp;
    char buf[33];
    // char *bufw;

    fd = open("/sys/bus/i2c/devices/1-0052/eeprom", O_RDWR);//打开文件  /sys/bus/i2c/devices/1-0050/eeprom
    if (fd < 0)
    {
        printf("####i2c test device open failed####/n");

    }
    buf[0]=Unit;
    buf[1]=FuncSelect;
    buf[2]=BaudRate;
    buf[3]=Output232value;
    buf[4]=Output232type;
    buf[5]=OffTime;
    buf[6]=Zono;
    buf[7]=ZeroKeyVal;
    buf[8]=OnZero;
    buf[9]=FilterStep;
    buf[10]=StableTime;
    buf[11]=StableRange;
    buf[12]=FreshTime;
    buf[13]=LedLight;
    float4char.dw=HighValue;
    buf[14]=float4char.w.hi;
    buf[15]=float4char.w.hi1;
    buf[16]=float4char.w.lo1;
    buf[17]=float4char.w.lo;
    float4char.dw=LowValue;
    buf[18]=float4char.w.hi;
    buf[19]=float4char.w.hi1;
    buf[20]=float4char.w.lo1;
    buf[21]=float4char.w.lo;
    buf[22]=Rati;
    buf[23]=Point;
    float4char.dw=CalFull;
    buf[24]=float4char.w.hi;
    buf[25]=float4char.w.hi1;
    buf[26]=float4char.w.lo1;
    buf[27]=float4char.w.lo;
    float4char.dw=sam;
    buf[28]=float4char.w.hi;
    buf[29]=float4char.w.hi1;
    buf[30]=float4char.w.lo1;
    buf[31]=float4char.w.lo;
    buf[32]=iniep;

    lseek(fd, 0x00, SEEK_SET); //定位地址，地址是0x400
    /*  if ((size = write(fd, bufw, len)) < 0)//写入数据
             {
                 printf("write error\n");
                 return -1;
             }*/
    write(fd, buf, 33);
    printf("writeok\n");
    temp=Rati;
    switch(Point)
    {
    case 0:
        SjRati=float(temp);
        break;
    case 1:
        SjRati=float(temp)*0.1;
        break;
    case 2:
        SjRati=float(temp)*0.01;
        break;
    case 3:
        SjRati=float(temp)*0.001;
        break;
    case 4:
        SjRati=float(temp)*0.0001;
        break;
    default:
        SjRati=float(temp);
        break;
    }


    close(fd);
}
/**************************************************
 Description: 读EEPROM时调用
 Argument   : none
 Return     : none
**************************************************/
void cali:: ArgRead()
{
    int fd,ret,temp;
    char buf[33];
    struct i2c_rdwr_ioctl_data e2prom_data;
    fd = open("/sys/bus/i2c/devices/1-0052/eeprom", O_RDWR);//打开文件  /sys/bus/i2c/devices/1-0050/eeprom
    if (fd < 0)
    {
        printf("####i2c test device open failed####/n");

    }
    buf[0]=0xFF;
    buf[1]=0xFF;
    buf[2]=0xFF;
    buf[3]=0xFF;
    buf[4]=0xFF;
    buf[5]=0xFF;
    buf[6]=0xFF;
    buf[7]=0xFF;
    buf[8]=0xFF;
    buf[9]=0xFF;
    buf[10]=0xFF;
    buf[11]=0xFF;
    buf[12]=0xFF;
    buf[13]=0xFF;
    buf[14]=0xFF;
    buf[15]=0xFF;
    buf[16]=0xFF;
    buf[17]=0xFF;
    buf[18]=0xFF;
    buf[19]=0xFF;
    buf[20]=0xFF;
    buf[21]=0xFF;
    buf[22]=0xFF;
    buf[23]=0xFF;
    buf[24]=0xFF;
    buf[25]=0xFF;
    buf[26]=0xFF;
    buf[27]=0xFF;
    buf[28]=0xFF;
    buf[29]=0xFF;
    buf[30]=0xFF;
    buf[31]=0xFF;
    buf[32]=0xFF;


    lseek(fd, 0x00, SEEK_SET);//准备读，首先定位地址，因为前面写入的时候更新了当前文件偏移量，所以这边需要重新定位到0x400.
    read(fd, buf, 33);
    /*  if ((size = read(fd, buf, 37)) < 0)//读数据
        {
            printf("readerror\n");
            return -1;
        }
        printf("readok\n");*/
    // printf("buf = %s \r\n", buf);

    Unit=buf[0];                                //P1
    qDebug()<<"Unit"<<Unit;//
    if(Unit>3)Unit=1;
    FuncSelect=buf[1];                          //P2
    qDebug()<<"FuncSelect"<<FuncSelect;//
    if(FuncSelect>3)FuncSelect=1;
    BaudRate=buf[2];                            //P3
    qDebug()<<"BaudRate"<<BaudRate;//
    if(BaudRate>3)BaudRate=1;
    Output232value=buf[3];                      //P4
    qDebug()<<"Output232value"<<Output232value;//
    if(Output232value>3)Output232value=1;
    Output232type=buf[4];                       //P5
    qDebug()<<"Output232type"<<Output232type;//
    if(Output232type>3)Output232type=1;
    OffTime=buf[5];                    	       //P6省电时间选择
    qDebug()<<"OffTime"<<OffTime;//
    if(OffTime>3)OffTime=1;
    Zono=buf[6];                                //P7零点跟踪
    qDebug()<<"Zono"<<Zono;//
    if(Zono>6)Zono=1;
    ZeroKeyVal=buf[7];                          //P8置零范围
    qDebug()<<"ZeroKeyVal"<<ZeroKeyVal;//
    if(ZeroKeyVal>6)ZeroKeyVal=1;
    OnZero=buf[8];                              //P9
    qDebug()<<"OnZero"<<OnZero;//
    if(OnZero>6)OnZero=1;
    FilterStep=buf[9];                          //P10
    qDebug()<<"FilterStep"<<FilterStep;//
    if(FilterStep>4)FilterStep=1;
    StableTime=buf[10];                         //P11
    qDebug()<<"StableTime"<<StableTime;//
    if(StableTime>6)StableTime=1;
    StableRange=buf[11];                         //P12稳定范围
    qDebug()<<"StableRange"<<StableRange;//
    if(StableRange>6)StableRange=1;
    FreshTime=buf[12];                           //P13
    qDebug()<<"FreshTime"<<FreshTime;//
    if(FreshTime>6)FreshTime=1;
    LedLight=buf[13];
    qDebug()<<"LedLight"<<LedLight;//
    if(LedLight>7)LedLight=1;
    qDebug()<<"HighValue"<<HighValue;
    float4char.w.hi= buf[14];
    float4char.w.hi1=buf[15];
    float4char.w.lo1=buf[16];
    float4char.w.lo= buf[17];
    HighValue=float4char.dw;
    qDebug()<<"HighValue"<<HighValue;//
    float4char.w.hi=buf[18];
    float4char.w.hi1=buf[19];
    float4char.w.lo1=buf[20];
    float4char.w.lo= buf[21];
    LowValue=float4char.dw;
    qDebug()<<"LowValue"<<LowValue;//
    Rati=buf[22];
    qDebug()<<"Rati"<<Rati;//
    Point=buf[23];
    qDebug()<<"Point"<<Point;//
    temp=Rati;
    switch(Point)
    {
    case 0:
        SjRati=float(temp);
        break;
    case 1:
        SjRati=float(temp)*0.1;
        break;
    case 2:
        SjRati=float(temp)*0.01;
        break;
    case 3:
        SjRati=float(temp)*0.001;
        break;
    case 4:
        SjRati=float(temp)*0.0001;
        break;
    default:
        SjRati=float(temp);
        break;
    }
    qDebug()<<"SjRati"<<SjRati;//
    float4char.w.hi= buf[24];
    float4char.w.hi1=buf[25];
    float4char.w.lo1=buf[26];
    float4char.w.lo= buf[27];
    CalFull=float4char.dw;
    qDebug()<<"CalFull"<<CalFull;//
    float4char.w.hi= buf[28];
    float4char.w.hi1=buf[29];
    float4char.w.lo1=buf[30];
    float4char.w.lo= buf[31];
    sam=float4char.dw;
    qDebug()<<"sam"<<sam;//
    iniep=buf[32];
    qDebug()<<"iniep"<<iniep;//
    close(fd);

}
/**************************************************
 Description: 电压检测时调用
 Argument   : none
 Return     : none
**************************************************/
void cali:: BtRead(void)
{



    // FILE *fp;
    char adbuf[20];
    fp = fopen(filename4, "rt");
    fread(adbuf, 1, sizeof(adbuf), fp);

    fclose(fp);
    sscanf(adbuf, "%d", &advalue);
    fvalue =0.8 * advalue;

   // printf("AIN4 = %.2f mV\n", fvalue);
   // qDebug()<<"fvalue"<<fvalue;//

}
/**************************************************
 Description: 加载大屏幕发送数据
 Argument   : none
 Return     : none
**************************************************/
void cali:: Load_Big(void)
{
    char bt;
    unsigned long ln;                                                //
    //   if(Nbig!=0)return;                                               //
    b_BigLoading=1;                                                  //置大屏幕数据正在装载标志（此时不可发送大屏幕数据）
    // Nbig=50;                                                         //
    //if(Net>=(Full+9*Rati))return;                                  //超载不发送数据
    if(Grosstolong<0)                                                //
    {                                                                //
        bt=1;                                                        //
        ln=0-Grosstolong;                                            //
    }                                                                //
    else                                                             //
    {                                                                //
        bt=0;                                                        //
        ln=Grosstolong;                                              //
    }                                                                //
    BigData=(ulng)Point<<1;                                              //小数点位置
    if(bt)BigData=BigData|0x10;                                      //重量符号
    if(b_Net)BigData=BigData|0x20;                                      //毛/净重
    BigData=BigData|((ln&0x30000)>>9);                                  //G16,G17
    BigData=BigData|((ln&0x0ff00)<<4);                                  //G8~G15
    BigData=BigData|((ln&0x000ff)<<23);                                 //G0~G7
    BigData=BigData|0x80200400;                                         //停止位,最后的标志位
    b_BigLoading=0;
    //  qDebug() <<"Grosstolong==================="<<Grosstolong;
    //  qDebug() <<"BigData==================="<<BigData;
}
