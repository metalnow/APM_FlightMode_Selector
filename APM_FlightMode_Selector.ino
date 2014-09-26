#include <SoftPWM.h>

byte seven_seg_digits_percent[10][7] = { { 34,34,34,34,34,34,0 },  // = 0
                                 { 0,34,34,0,0,0,0 },  // = 1
                                 { 34,34,0,34,34,0,34 },  // = 2
                                 { 34,34,34,34,0,0,34 },  // = 3
                                 { 0,34,34,0,0,34,34 },  // = 4
                                 { 34,0,34,34,0,34,34 },  // = 5
                                 { 34,0,34,34,34,34,34 },  // = 6
                                 { 34,34,34,0,0,0,0 },  // = 7
                                 { 34,34,34,34,34,34,34 },  // = 8
                                 { 34,34,34,0,0,34,34 }   // = 9
                             };

int APM_Mode_1_Pin = 2;
int APM_Mode_2_Pin = 3;
int APM_Mode_3_Pin = 4;
int APM_Mode_4_Pin = 5;
int APM_Mode_5_Pin = 6;
int APM_Mode_6_Pin = 7;

int Mode_1 = map(0, 0, 5, 0, 100);
int Mode_2 = map(1, 0, 5, 0, 100);
int Mode_3 = map(2, 0, 5, 0, 100);
int Mode_4 = map(3, 0, 5, 0, 100);
int Mode_5 = map(4, 0, 5, 0, 100);
int Mode_6 = map(5, 0, 5, 0, 100);

int Seven_Seg_Led_a_Pin = A5;
int Seven_Seg_Led_b_Pin = A4;
int Seven_Seg_Led_c_Pin = A3;
int Seven_Seg_Led_d_Pin = A2;
int Seven_Seg_Led_e_Pin = A1;
int Seven_Seg_Led_f_Pin = A0;
int Seven_Seg_Led_g_Pin = 12;

int Mode_Output = 11;

float LED_Voltage = 1.7;

int Output_Voltage = (int)( ( 1.7 / 5.0 ) * 100.0 );

void setup()
{
  pinMode(APM_Mode_1_Pin, INPUT);
  pinMode(APM_Mode_2_Pin, INPUT);
  pinMode(APM_Mode_3_Pin, INPUT);
  pinMode(APM_Mode_4_Pin, INPUT);
  pinMode(APM_Mode_5_Pin, INPUT);
  pinMode(APM_Mode_6_Pin, INPUT);

  pinMode(Seven_Seg_Led_a_Pin, OUTPUT);
  pinMode(Seven_Seg_Led_b_Pin, OUTPUT);
  pinMode(Seven_Seg_Led_c_Pin, OUTPUT);
  pinMode(Seven_Seg_Led_d_Pin, OUTPUT);
  pinMode(Seven_Seg_Led_e_Pin, OUTPUT);
  pinMode(Seven_Seg_Led_f_Pin, OUTPUT);
  pinMode(Seven_Seg_Led_g_Pin, OUTPUT);

  pinMode(Mode_Output, OUTPUT);
  
  SoftPWMBegin();
  
  SoftPWMSet(Seven_Seg_Led_a_Pin, 0);
  SoftPWMSetFadeTime(Seven_Seg_Led_a_Pin, 300, 300);  
  SoftPWMSet(Seven_Seg_Led_b_Pin, 0);
  SoftPWMSetFadeTime(Seven_Seg_Led_b_Pin, 300, 300);
  SoftPWMSet(Seven_Seg_Led_c_Pin, 0);
  SoftPWMSetFadeTime(Seven_Seg_Led_c_Pin, 300, 300);
  SoftPWMSet(Seven_Seg_Led_d_Pin, 0);
  SoftPWMSetFadeTime(Seven_Seg_Led_d_Pin, 300, 300);
  SoftPWMSet(Seven_Seg_Led_e_Pin, 0);
  SoftPWMSetFadeTime(Seven_Seg_Led_e_Pin, 300, 300);
  SoftPWMSet(Seven_Seg_Led_f_Pin, 0);
  SoftPWMSetFadeTime(Seven_Seg_Led_f_Pin, 300, 300);
  SoftPWMSet(Seven_Seg_Led_g_Pin, 0);
  SoftPWMSetFadeTime(Seven_Seg_Led_g_Pin, 300, 300);

  SoftPWMSet(Mode_Output, 0);
  SoftPWMSetFadeTime(Mode_Output, 0, 0);
  
}

int sensorVal = 0;
int mode = 0;
void loop()
{
  sensorVal = digitalRead(APM_Mode_1_Pin);
  if ( sensorVal == HIGH )
  {
    sevenSegWrite(1);
    SoftPWMSetPercent(Mode_Output, Mode_1);    
  }

  sensorVal = digitalRead(APM_Mode_2_Pin);
  if ( sensorVal == HIGH )
  {
    sevenSegWrite(2);
    SoftPWMSetPercent(Mode_Output, Mode_2);    
  }
  sensorVal = digitalRead(APM_Mode_3_Pin);
  if ( sensorVal == HIGH )
  {
    sevenSegWrite(3);
    SoftPWMSetPercent(Mode_Output, Mode_3);    
  }
  sensorVal = digitalRead(APM_Mode_4_Pin);
  if ( sensorVal == HIGH )
  {
    sevenSegWrite(4);
    SoftPWMSetPercent(Mode_Output, Mode_4);    
  }
  sensorVal = digitalRead(APM_Mode_5_Pin);
  if ( sensorVal == HIGH )
  {
    sevenSegWrite(5);
    SoftPWMSetPercent(Mode_Output, Mode_5);    
  }
  sensorVal = digitalRead(APM_Mode_6_Pin);
  if ( sensorVal == HIGH )
  {
    sevenSegWrite(6);
    SoftPWMSetPercent(Mode_Output, Mode_6);    
  }
    
}

void sevenSegWrite(byte digit) 
{
  SoftPWMSetPercent(Seven_Seg_Led_a_Pin, seven_seg_digits_percent[digit][0]);
  SoftPWMSetPercent(Seven_Seg_Led_b_Pin, seven_seg_digits_percent[digit][1]);
  SoftPWMSetPercent(Seven_Seg_Led_c_Pin, seven_seg_digits_percent[digit][2]);
  SoftPWMSetPercent(Seven_Seg_Led_d_Pin, seven_seg_digits_percent[digit][3]);
  SoftPWMSetPercent(Seven_Seg_Led_e_Pin, seven_seg_digits_percent[digit][4]);
  SoftPWMSetPercent(Seven_Seg_Led_f_Pin, seven_seg_digits_percent[digit][5]);
  SoftPWMSetPercent(Seven_Seg_Led_g_Pin, seven_seg_digits_percent[digit][6]);
}

