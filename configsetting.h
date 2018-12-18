#ifndef CONFIGSETTING_H
#define CONFIGSETTING_H
#include "cali.h"
#include <QWidget>
#include <GlobalVarible.h>
namespace Ui {
class configSetting;
}

class configSetting : public QWidget
{
    Q_OBJECT

public:
    explicit configSetting(QWidget *parent = 0);
    ~configSetting();

private slots:
    void on_toolButton_5_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

 //  void on_pushButton_6_clicked();
    void fromRootdialog(void);

private:
    Ui::configSetting *ui;
public:
    cali calcf;
public slots:
    void timerUpdate();
    void updateParameterSlot();
    void httpDownstateSlot(int httpstate);
private slots:
    void slot_ScroolWidget(int);
    void on_toolButton_2_clicked();
  // void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_68_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_13_clicked();
    //void on_pushButton_14_clicked();
   // void on_pushButton_15_clicked();
    //void on_pushButton_17_clicked();
    void on_toolButton_3_clicked();
   // void on_pushButton_25_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_28_clicked();
   // void on_pushButton_29_clicked();
    void on_pushButton_30_clicked();
    void on_pushButton_31_clicked();
    void on_pushButton_32_clicked();
    void on_pushButton_33_clicked();
   // void on_pushButton_34_clicked();
    void on_toolButton_6_clicked();
    void on_pushButton_49_clicked();
    void on_pushButton_48_clicked();
    void on_pushButton_47_clicked();
    void on_pushButton_50_clicked();
    void on_pushButton_51_clicked();
    void on_toolButton_4_clicked();
    void on_pushButton_38_clicked();
   // void on_pushButton_37_clicked();
    //void on_pushButton_39_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_41_clicked();
    void on_pushButton_36_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_43_clicked();
    void on_pushButton_69_clicked();
    void on_pushButton_80_clicked();
    void on_pushButton_81_clicked();
    void on_pushButton_82_clicked();
    void on_pushButton_83_clicked();
    void on_pushButton_84_clicked();
    void on_pushButton_85_clicked();
    void on_pushButton_92_clicked();
    void on_pushButton_93_clicked();
    void on_pushButton_94_clicked();
    void on_pushButton_95_clicked();
    void on_pushButton_44_clicked();
    void on_pushButton_35_clicked();
    void on_pushButton_42_clicked();
    void on_comboBox_4_currentIndexChanged(int index);
    void on_comboBox_6_currentIndexChanged(int index);
    void on_comboBox_7_currentIndexChanged(int index);
    //void on_comboBox_5_activated(int index);
    void on_comboBox_5_currentIndexChanged(int index);

    void on_comboBox_8_currentIndexChanged(int index);

    void on_comboBox_11_currentIndexChanged(int index);

    void on_comboBox_12_currentIndexChanged(int index);

    void on_comboBox_9_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_comboBox_10_currentIndexChanged(int index);
    /*void on_radioButton_15_clicked();
    void on_radioButton_12_clicked();

    void on_radioButton_13_clicked();

    void on_radioButton_19_clicked();

    void on_radioButton_18_clicked();

    void on_radioButton_17_clicked();

    void on_radioButton_16_clicked();

    void on_radioButton_20_clicked();

    void on_radioButton_21_clicked();*/

    void on_pushButton_46_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_45_clicked();

   /*void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(int index);*/

    void on_pushButton_54_clicked();

    void on_toolButton_8_clicked();

    void on_pushButton_55_clicked();

    void on_pushButton_56_clicked();

   // void on_horizontalSlider_actionTriggered(int action);

  //  void on_horizontalSlider_valueChanged(int value);

    void on_radioButton_12_toggled(bool checked);

    void on_radioButton_13_toggled(bool checked);

    void on_radioButton_11_toggled(bool checked);

    void on_radioButton_19_toggled(bool checked);

    void on_radioButton_18_toggled(bool checked);

    void on_radioButton_17_toggled(bool checked);

    void on_radioButton_16_toggled(bool checked);

    void on_radioButton_20_toggled(bool checked);

    void on_radioButton_28_toggled(bool checked);

    void on_radioButton_25_toggled(bool checked);

    void on_radioButton_23_toggled(bool checked);

    void on_radioButton_24_toggled(bool checked);

    void on_radioButton_26_toggled(bool checked);

    void on_radioButton_27_toggled(bool checked);

    void on_radioButton_36_toggled(bool checked);

    void on_radioButton_37_toggled(bool checked);

    void on_radioButton_33_toggled(bool checked);

    void on_radioButton_31_toggled(bool checked);

    void on_radioButton_32_toggled(bool checked);

    void on_radioButton_35_toggled(bool checked);

    void on_radioButton_44_toggled(bool checked);

    void on_radioButton_41_toggled(bool checked);

    void on_radioButton_39_toggled(bool checked);

    void on_radioButton_40_toggled(bool checked);

    void on_radioButton_42_toggled(bool checked);

    void on_radioButton_43_toggled(bool checked);

    void on_lineEdit_10_textChanged(const QString &arg1);


    void on_radioButton_46_toggled(bool checked);

    void on_radioButton_49_toggled(bool checked);

    void on_radioButton_48_toggled(bool checked);

    void on_radioButton_47_toggled(bool checked);

    void on_radioButton_38_toggled(bool checked);

    void on_radioButton_29_toggled(bool checked);

    void on_radioButton_30_toggled(bool checked);

    void on_radioButton_34_toggled(bool checked);

    void on_radioButton_21_toggled(bool checked);

    void on_radioButton_54_toggled(bool checked);

    void on_radioButton_55_toggled(bool checked);

    void on_radioButton_56_toggled(bool checked);

    void on_radioButton_60_toggled(bool checked);

    void on_radioButton_58_toggled(bool checked);

    void on_radioButton_57_toggled(bool checked);

    void on_radioButton_61_toggled(bool checked);

    void on_radioButton_59_toggled(bool checked);

    void on_radioButton_62_toggled(bool checked);

    void on_pushButton_18_clicked();

    void on_pushButton_57_clicked();

    void on_pushButton_58_clicked();

    void on_pushButton_59_clicked();

    void on_pushButton_60_clicked();

    void on_pushButton_61_clicked();

    void on_pushButton_62_clicked();

    void on_pushButton_63_clicked();

    void on_radioButton_73_toggled(bool checked);

    void on_radioButton_74_toggled(bool checked);

    void on_radioButton_69_toggled(bool checked);

    void on_radioButton_70_toggled(bool checked);

    void on_radioButton_71_toggled(bool checked);

    void on_radioButton_72_toggled(bool checked);

    void on_lineEdit_12_textChanged(const QString &arg1);

    void on_radioButton_66_toggled(bool checked);

    void on_radioButton_67_toggled(bool checked);

    //void on_radioButton_68_toggled(bool checked);

    void on_radioButton_64_toggled(bool checked);

    void on_radioButton_65_toggled(bool checked);

    void on_textEdit_2_textChanged();

    void on_textEdit_5_textChanged();
    void on_radioButton_68_toggled(bool checked);

    void on_textEdit_3_textChanged();

    void on_textEdit_4_textChanged();

    void on_textEdit_6_textChanged();

    void on_pushButton_64_clicked();

    void on_radioButton_75_toggled(bool checked);

    void on_radioButton_76_toggled(bool checked);

    void on_pushButton_19_clicked();

    void on_radioButton_77_toggled(bool checked);

    void on_comboBox_14_currentIndexChanged(int index);

    void on_pushButton_65_clicked();

    void on_comboBox_15_currentIndexChanged(int index);

    void on_pushButton_66_clicked();


    void on_radioButton_78_toggled(bool checked);

    void on_radioButton_79_toggled(bool checked);

public:
    void ConfigSave(void);
signals:
    void BaudRateChangeFor232(void);
    void BaudRateChangeFor485(void);
    void ParityChangeFor232(void);
    void ParityChangeFor485(void);
    void DataBitsChangeFor232(void);
    void DataBitsChangeFor485(void);
    void StopBitsChangeFor232(void);
    void StopBitsChangeFor485(void);
    void TmodeChangeFor232(void);
    void CommTypeChange(void);
    //void TmodeChangeFor485(void);
    void sendTONetwork(void);
    void printnetsignal();
    void adspeedsignal(void);
    void syncParameterSignal(void);
    void updateApplicationSignal(void);
};

#endif // CONFIGSETTING_H
