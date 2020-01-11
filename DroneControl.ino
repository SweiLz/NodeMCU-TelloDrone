// Author: Liews Wuttipat (wuttipat.cho@anman.co.th , sweilz.w@gmail.com)
// Date: 6 Nov 2019
// Version: 1.02
// Copyright (c) 2018, Anman Technology Co.,Ltd.

#include "Drone.h"
//#define DEBUG

Drone drone;

String _response;

void setup()
{
  Serial.begin(115200);
  //  drone.init();
  //  delay(2000);

  //  drone.takeoff();
  //  drone.up(30);
  //  delay(3000);
  //  drone.down(30);
  //  delay(3000);
  //  drone.left(30);
  //  delay(3000);
  //  drone.right(30);
  //  delay(3000);
  //  drone.forward(30);
  //  delay(3000);
  //  drone.back(30);
  //  delay(3000);
  //  drone.rot_cw(90);
  //  delay(3000);
  //  drone.rot_ccw(90);
  //  delay(3000);
  //  drone.land();
  //  delay(5000);

}
void loop()
{
  if (Serial.available())
  {
    _response = "";
    _response = Serial.readStringUntil('\n');
    _response.trim();
    Serial.println(">>INPUT: " + _response);
    if (!_response.startsWith("?[") || !_response.endsWith("#"))
      return;

    //    Serial.println(">>FINE: " + _response);
    int _case = _response.substring(_response.indexOf('[') + 1, _response.indexOf(']')).toInt();
    int _oper = _response.substring(_response.indexOf(']') + 1, _response.indexOf('#')).toInt();

    //    Serial.print("CASE: ");
    //    Serial.print(_case);
    //    Serial.print(" OPER: ");
    //    Serial.println(_oper);

    switch (_case)
    {
      case 1:
        Serial.println("Case: 0x01, Takeoff");
        drone.takeoff();
        break;
      case 2:
        Serial.println("Case: 0x02, Langing");
        drone.land();
        break;
      case 3:
        Serial.print("Case: 0x03, Up ");
        Serial.print(_oper);
        Serial.println("cm");
        drone.up(_oper);
        break;
      case 4:
        Serial.print("Case: 0x04, Down ");
        Serial.print(_oper);
        Serial.println("cm");
        drone.down(_oper);
        break;
      case 5:
        Serial.print("Case: 0x05, Left ");
        Serial.print(_oper);
        Serial.println("cm");
        drone.left(_oper);
        break;
      case 6:
        Serial.print("Case: 0x06, Right ");
        Serial.print(_oper);
        Serial.println("cm");
        drone.right(_oper);
        break;
      case 7:
        Serial.print("Case: 0x07, Forward ");
        Serial.print(_oper);
        Serial.println("cm");
        drone.forward(_oper);
        break;
      case 8:
        Serial.print("Case: 0x08, Backward ");
        Serial.print(_oper);
        Serial.println("cm");
        drone.back(_oper);
        break;
      case 9:
        Serial.print("Case: 0x09, Rotate CW ");
        Serial.print(_oper);
        Serial.println("deg");
        drone.rot_cw(_oper);
        break;
      case 10:
        Serial.print("Case: 0x0A, Rotate CCW ");
        Serial.print(_oper);
        Serial.println("deg");
        drone.rot_ccw(_oper);
        break;
      case 16:
        Serial.print("Case: 0x10, Battery is ");
        drone.getBattery();
        Serial.print(drone.bettery);
        Serial.println("%");
        break;
    }
  }
}
