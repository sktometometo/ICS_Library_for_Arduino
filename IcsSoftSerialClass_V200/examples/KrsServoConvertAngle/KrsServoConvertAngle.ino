//
//  @file KrsServoConvertAngle.ino
//  @brief KrsServoConvertAngle sample program
//  @author Kondo Kagaku Co.,Ltd.
//  @date 2018/01/05
//
//  Pos,Deg変換でサーボ動作 
//  整数型で変換したものは90度
//  浮動小数点型で変換したものは-90.0度 に動きます。
//  ICSの通信にはSoftwareSerialを使います。
//

#include <IcsSoftSerialClass.h> 

const byte S_RX_PIN = 8;
const byte S_TX_PIN = 9;

const byte EN_PIN = 2;
const long BAUDRATE = 115200;
const int TIMEOUT = 200;   //softSerialは通信失敗する可能性があるため短めに

IcsSoftSerialClass krs(S_RX_PIN,S_TX_PIN,EN_PIN,BAUDRATE,TIMEOUT);  //インスタンス＋ENピン(2番ピン)およびUARTの設定、softSerial版


void setup() {
  // put your setup code here, to run once:
  krs.begin();  //サーボモータの通信初期設定
}

void loop() {
  int pos_i;
  int pos_f;
  
  //整数型(x100)の場合
  pos_i = krs.degPos100(9000);  //90 x100deg をポジションデータに変換
  krs.setPos(0,pos_i);          //変換したデータをID:0に送る
  delay(500);                   //

  //浮動小数点の場合
  pos_f = krs.degPos(-90.0);  //-90.0deg(float)をポジションデータに変換
  krs.setPos(0,pos_f);                 //変換したデータをID:0に送る
  delay(500);
 
}
