//
//  @file KrsServoMasterSlave.ino
//  @brief KRS Servo Master Slave sample program
//  @author Kondo Kagaku Co.,Ltd.
//  @date 2018/01/05
//
//  ID:1のサーボモータの角度を読み取りID:0のサーボモータに読み取った角度を渡します
//  (ID1の動きをID0が真似をします)
//  ICSの通信にはSoftwareSerialを使います。
//


#include <IcsSoftSerialClass.h> 

const byte S_RX_PIN = 8;
const byte S_TX_PIN = 9;

const byte EN_PIN = 2;
const long BAUDRATE = 115200;
const int TIMEOUT = 50;   //softSerialは通信失敗する可能性があるため短めに

IcsSoftSerialClass krs(S_RX_PIN,S_TX_PIN,EN_PIN,BAUDRATE,TIMEOUT);  //インスタンス＋ENピン(2番ピン)およびUARTの設定、softSerial版

void setup() {
  // put your setup code here, to run once:
   krs.begin();  //サーボモータの通信初期設定
}

void loop() {

  int id1Pos;
  
  id1Pos = krs.setFree(1);  //ID1のデータをFreeで読み取ります
  krs.setPos(0,id1Pos); //ID0にID1で受け取ったポジションデータを書き込みます

  id1Pos = krs.getPos(1);  //ID1のデータを角度取得コマンドで受け取ります(ICS3.6のみ)
  krs.setPos(0,id1Pos); //ID0にID1で受け取ったポジションデータを書き込みます

  

}
