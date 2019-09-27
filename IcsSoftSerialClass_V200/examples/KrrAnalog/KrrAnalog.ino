//
//  @file KrrAnalog.ino
//  @brief KRR get Analog sample 
//  @author Kondo Kagaku Co.,Ltd.
//  @date 2018/01/05
//
//  KRR(受信機)に送られてきているアナログデータを取得します。
//  ICSの通信にはSoftwareSerialを使います。
//	アナログデータをもとにID:0のサーボモータを動かします。
//	

#include <IcsSoftSerialClass.h> 

const byte S_RX_PIN = 8;
const byte S_TX_PIN = 9;

const byte EN_PIN = 2;
const long BAUDRATE = 115200;
const int TIMEOUT = 100;

IcsSoftSerialClass krs(S_RX_PIN,S_TX_PIN,EN_PIN,BAUDRATE,TIMEOUT);  //インスタンス＋ENピン(2番ピン)およびUARTの設定、softSerial版

void setup() {
  // put your setup code here, to run once:
   krs.begin();  //サーボモータの通信初期設定
  
}

void loop() {

   int analogData;
   int sendpos;

   analogData = krs.getKrrAnalog(1);        //KRSのPA1に接続されているアナログデータを読み取る
   if(analogData != krs.ICS_FALSE)  		//受信が成功しているか判定
   {
    sendpos = 7500 + ((analogData - 64) * 62);  //
                                            // 受信データ - 64(7bit/2) <= 中央値からどれくらい離れているか計算
                                            //　　　　　　 ;        *62   <= 4000(ポジションは±4000)/64 = 62.5　だが、切り捨てて62
                                            // 7500 + (      ;            ) <= サーボモータの0点からの角度に変換                                            
    krs.setPos(0,sendpos);                  //ID:0に計算した値を送る
   }
   else
   {
    //通信に失敗してた時の処理
    delay(50);   //SoftSerialは失敗する可能性が高いので、待ち時間は短く
   }
  
    delay(10);    //KRR5は10ms以下の応答にはついていけないので待つ
}
