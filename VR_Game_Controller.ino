/*
  KEY_LEFT_CTRL
  KEY_LEFT_SHIFT
  KEY_LEFT_ALT
  KEY_LEFT_GUI 
  KEY_RIGHT_CTRL
  KEY_RIGHT_SHIFT 
  KEY_RIGHT_ALT 
  KEY_RIGHT_GUI 

  KEY_UP_ARROW * 4
  KEY_DOWN_ARROW * 4
  KEY_LEFT_ARROW 
  KEY_RIGHT_ARROW 
  KEY_BACKSPACE 
  KEY_TAB
  KEY_RETURN * 5
  KEY_ESC 
  KEY_INSERT
  KEY_PRTSC
  KEY_DELETE
  KEY_PAGE_UP
  KEY_PAGE_DOWN
  KEY_HOME
  KEY_END
  KEY_CAPS_LOCK
  KEY_F1
  KEY_F2 
  KEY_F3 
  KEY_F4
  KEY_F5
  KEY_F6
  KEY_F7
  KEY_F8
  KEY_F9 
  KEY_F10
  KEY_F11
  KEY_F12
  KEY_F13
  KEY_F14
  KEY_F15
  KEY_F16
  KEY_F17
  KEY_F18
  KEY_F19
  KEY_F20
  KEY_F21
  KEY_F22
  KEY_F23
  KEY_F24

  KEY_NUM_0
  KEY_NUM_1
  KEY_NUM_2
  KEY_NUM_3
  KEY_NUM_4
  KEY_NUM_5
  KEY_NUM_6
  KEY_NUM_7
  KEY_NUM_8
  KEY_NUM_9
  KEY_NUM_SLASH
  KEY_NUM_ASTERISK
  KEY_NUM_MINUS
  KEY_NUM_PLUS
  KEY_NUM_ENTER
  KEY_NUM_PERIOD
*/
#include <BleKeyboard.h>
BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
  pinMode(2,OUTPUT);
  pinMode(15,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(18,INPUT);
  pinMode(19,INPUT);

}

void loop() {
      if(bleKeyboard.isConnected()) {
        digitalWrite(2,HIGH);
      }
      else {
        digitalWrite(2,LOW);
      }

  int x= analogRead(4);
  Serial.print(x);
  int y= analogRead(15);
  Serial.print("   ");
  Serial.print(y);
  Serial.print("   ");

    //   if(y<=100){
    // bleKeyboard.press(KEY_DOWN_ARROW );
    // // bleKeyboard.releaseAll();
    // // delay(5);
    //   }

    //   else if(y>=4000){
    // bleKeyboard.press(KEY_UP_ARROW );
    // // bleKeyboard.releaseAll();
    // // delay(5);
    //   }

      // else {
      // bleKeyboard.releaseAll();
      // }

   if(x<=100){
   bleKeyboard.press(KEY_UP_ARROW );
   // bleKeyboard.releaseAll();
    // // delay(500);
    }

    else if(x>=4000 ){
    bleKeyboard.press(KEY_DOWN_ARROW );
    // bleKeyboard.releaseAll();
    // delay(500);
      }

      else {
      bleKeyboard.releaseAll();
      }

    int F5= digitalRead(5);
    Serial.println (F5);
       if (F5 == LOW){
    bleKeyboard.write(KEY_RETURN);
    delay(50);
    //bleKeyboard.releaseAll();
      }

    // digitalRead(18);
    // if (18 == HIGH){
    // bleKeyboard.write(KEY_ESC);
    // bleKeyboard.releaseAll();
    // delay(500);
    //   }

    // digitalRead(19);
    // if (19 == HIGH){
    // bleKeyboard.write(KEY_RETURN);
    // bleKeyboard.releaseAll();
    // delay(500);
    //   }


}