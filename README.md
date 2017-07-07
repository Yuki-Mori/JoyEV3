# JoyEV3

Joystickを使用してEV3を動かすシステムのEV3側。

## 基本設計
Joystickの情報はPCなどからBluetoothで送られてくるので、このデータを処理してロボットを動かす。<br>
動かすロボットはETロボコン2017の[HackEV](http://www.etrobo.jp/2017/gaiyou/intro.php)を想定