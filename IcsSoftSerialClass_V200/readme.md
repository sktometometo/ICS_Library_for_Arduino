
# IcsSoftSerialClass for Arduino
---

Overview
近藤科学製ICS機器をArduinoのSoftSerialから動かすためのライブラリです。  
This library is for connecting a Kondo Kagaku ICS device from an Arudino Software serial port.

## Description
近藤科学製サーボモータや受信機等ICS機器をArduinoで動かすためのライブラリです。  
This library is for connecting a Kondo Kagaku servo motor, receiver or other ICS device using Arudino.

サーボモータの位置制御(ポジション)コマンドやストレッチ等のパラメータ変更がArduinoからできるようになります。
 It enables servo motor position commands and parameter changes like for “stretch” to be performed from Arudino.

受信機(KRR)に接続することで、送信機(KRC)からのデータも取得できます。
By connecting to a receiver (KRR), data can also be acquired from a transmitter (KRC).

Arduinoからは Software Serialを用いて通信をします。
Communications can be performed from Arudino using a Software serial port.

## Requirement
- Arduino Meag
Not all pins on the Mega and Mega 2560 support change interrupts, so only the following can be used for RX: 10, 11, 12, 13, 14, 15, 50, 51, 52, 53, A8 (62), A9 (63), A10 (64), A11 (65), A12 (66), A13 (67), A14 (68), A15 (69).

- Arduino Uno
Not all pins on the Leonardo and Micro support change interrupts, so only the following can be used for RX: 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

※	reference to (<https://www.arduino.cc/en/Reference/SoftwareSerial>)

## Usage
ArduinoからアクセスできるIcsSoftSerialClassを使うにはIcsClassのIcsBaceClassをリンクできるようにしてください。
To use IcsHardSerialClass, which can be accessed from Arudino, make sure IcsClass’s IcsBaseClass can be linked.

また、 KoCustomSoftSerialもリンクしてください。
Also make sure to link KoCustomSoftSerial.

他のマイコンを使いたい場合は、IcsBaceClassを派生させると便利です。
To use IcsHardSerialClass, which can be accessed from Arudino, make sure IcsClass’s IcsBaseClass can be linked.

詳しい使い方については、配布フォルダのマニュアルをご覧ください。
For details, refer to the manual in the folder provided.

## Licence
Copyright 2018 Kondo Kagaku co.,ltd.
[MIT](http://opensource.org/licenses/mit-license.php)
see to MIT_Licence.txt
or
Copyright 2018 Kondo Kagaku co.,ltd.
[LGPL 3.0](https://www.gnu.org/licenses/lgpl-3.0.html)
see to lgpl-3.0.txt
(use to KoCustomSoftSerial)

## Author
近藤科学株式会社
Kondo Kagaku co.,ltd.
T.Nobuhara
近藤科学ホームページ:(<http://kondo-robot.com/>)
