#include <Servo.h>


Servo handServo;  //Servo 1
Servo boxServo;   //Servo 2

int switchStatus = 0, action = 1, randNumber = 0;

const int ledPin = 13;         //LED pin
const int frontSwitchPin = 2;  //switch pin
const int handServoPin = 5;    //pin of Servo 1
const int boxServoPin = 6;     //pin of Servo 2

///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);                  //set LED pin as output
  digitalWrite(ledPin, HIGH);               //and high

  handServo.attach(handServoPin);           //定义舵机信号引脚
  boxServo.attach(boxServoPin);
  
  handServo.write(200);                     //Set initial state of two servo
  boxServo.write(70);
  //randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  switchStatus = digitalRead(frontSwitchPin); //读取开关状态

  if (switchStatus == LOW) {
    //若开关被按下

    if (action == 1)
    {
      Serial.println("Action 1");           //1, (open(20), hand(20), 1s, hand(20), close(20)) normal
      Serial.println(switchStatus);
      for (int i = 70; i <= 120; i++)		//open box
      {
        boxServo.write(i);
        delay(20);	//determin speed
      }
      for (int i = 180; i >= 35; i--)		//take hand off
      {
        handServo.write(i);
        delay(20);
      }
      delay(1000);	//stop 1 second
      
	  handServo.write(26);					//hand out
      delay(200);
      
	  for (int i = 26; i <= 180; i++)
      {
        handServo.write(i);
        delay(20);
      }
      for (int i = 110; i >= 70; i--)
      {
        boxServo.write(i);
        delay(20);
      }
      action++;



    }


    else if (action == 2)
    {
      Serial.println("Action 2");         //2,(open(6), 0.5, hand(++), 0.5s, hand(--), 0.5, close(--), 1.5s, open(6), 3s, close(--)) angry with hesi
      Serial.println(switchStatus);
      for (int i = 70; i <= 110; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(550);
	  
      handServo.write(26);
      delay(550);
	  
      handServo.write(180);
      delay(550);
	  
      boxServo.write(70);
      delay(1500);
	  
      for (int i = 70; i <= 110; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(3000);
      boxServo.write(70);
      action++;
    }

    else if (action == 3)
    {
      Serial.println("Action 3");         //3, (open(6), 1s, close(--), 2s, open(6), hand(++), 0.5s, hand(--), 0.5, close(--))
      Serial.println(switchStatus);
      for (int i = 70; i <= 110; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(1000);
	  
      boxServo.write(70);
      delay(2000);
	  
      for (int i = 70; i <= 110; i++) {
        boxServo.write(i);
        delay(6);
      }
	  
      handServo.write(26);
      delay(550);
	  
      handServo.write(180);
      delay(500);
	  
      boxServo.write(70);
      action++;
    }

    else if (action == 4)
    {
      Serial.println("Action 4");         //4,(open(20), hand(20), 2s, hand(++), 0.2s, hand(--), 0.4s, close(--))
      Serial.println(switchStatus);
      for (int i = 70; i <= 110; i++)
      {
        boxServo.write(i);
        delay(20);
      }
	  
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(20);
      }
	  delay(2000);
      
	  handServo.write(26);
      delay(200);
      
	  handServo.write(180);
      delay(400);
	  
      boxServo.write(70);
      action++;
    }

    else if (action == 5)
    {
      Serial.println("Action 5");       //第五种 
      Serial.println(switchStatus);
      for (int i = 70; i <= 110; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(2000);
	  
      handServo.write(65);
      delay(550);
	  
      handServo.write(40);
      delay(200);
	  
      handServo.write(65);
      delay(200);
      
	  handServo.write(40);
      delay(200);
      
	  handServo.write(65);
      delay(200);
      
	  handServo.write(40);
      delay(200);
      
	  handServo.write(65);
      delay(200);
      
	  handServo.write(40);
      delay(200);
      
	  handServo.write(65);
      delay(200);
      
	  handServo.write(40);
      delay(200);
      
	  handServo.write(65);
      delay(2000);
      
	  handServo.write(26);
      delay(400);
      
	  handServo.write(180);
      delay(400);
      
	  boxServo.write(70);
      action++;
    }

    else if (action == 6)
    {
      Serial.println("Action 6");
      Serial.println(switchStatus);
      //第六种 生气
      for (int i = 70; i < 110; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      delay(1000);
      for (int i = 0; i < 12; i++)
      {
        for (int j = 70; j <= 110; j++) {
          boxServo.write(j);
          delay(6);
        }
        delay(200);
      }
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(30);
      }
      handServo.write(26);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      delay(1500);
      for (int i = 70; i <= 110; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(3000);
      boxServo.write(80);
      action++;
    }

    else if (action == 7)
    {
      Serial.println("Action 7");      //第七种暴力关盒子
      Serial.println(switchStatus);
      for (int i = 70; i <= 110; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(400);
      handServo.write(26);
      delay(1000);
      for (int i = 0; i < 6; i++)
      {
        for (int j = 70; j <= 110; j++) {
          boxServo.write(j);
          delay(6);
        }
        delay(200);
      }
      delay(500);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action++;
    }

    else if (action == 8)
    {
      Serial.println("Action 8");      //第八种 关上开关然后抗议
      Serial.println(switchStatus);
      for (int i = 70; i <= 110; i++) {
        boxServo.write(i);
        delay(6);
      }
      handServo.write(26);
      delay(2000);
      for (int i = 0; i < 7; i++)
      {
        handServo.write(75);
        delay(100);
        handServo.write(40);
        delay(100);
      }
      delay(500);
      handServo.write(180);
      delay(1000);
      boxServo.write(70);
      action++;
    }

    else if (action == 9)
    {
      Serial.println("Action 9");      //第九种 非常生气 慢慢慢慢地关上开关
      Serial.println(switchStatus);
      for (int i = 70; i <= 105; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(2000);
      boxServo.write(110);
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(40);
      }
      delay(500);
      handServo.write(26);
      delay(200);
      for (int i = 26; i <= 180; i++)
      {
        handServo.write(i);
        delay(40);
      }
      boxServo.write(70);
      delay(2000);
      boxServo.write(100);
      delay(3000);
      boxServo.write(70);
      action++;
    }


    else if (action == 10)
    {
      Serial.println("Action 10");      //第十种 慢慢 然后迅速关开关
      Serial.println(switchStatus);
      for (int i = 70; i <= 105; i++)
      {
        boxServo.write(i);
        delay(100);
      }
      delay(1000);
      for (int i = 0; i < 10; i++)
      {
        for (int j = 70; j <= 100; j++) {
          boxServo.write(j);
          delay(6);
        }
        delay(100);
      }
      boxServo.write(110);
      delay(100);
      handServo.write(26);
      delay(650);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action++;
    }

    else if (action == 11)
    {
      Serial.println("Action 11");      //第十一种 暴力+1懒得解释了
      Serial.println(switchStatus);
      for (int i = 70; i <= 110; i++) {
        boxServo.write(i);
        delay(6);
      }
      handServo.write(26);
      delay(2000);
      for (int i = 0; i < 3; i++)
      {
        handServo.write(65);
        delay(200);
        handServo.write(40);
        delay(200);
      }
      delay(1500);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      delay(1500);
      for (int i = 70; i <= 110; i++) {
        boxServo.write(i);
        delay(6);
      }
      handServo.write(26);
      delay(3000);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action++;
    }

    else if (action == 12)
    {
      Serial.println("Action 12");      //第十二种
      Serial.println(switchStatus);
      for (int i = 70; i <= 110; i++)
      {
        boxServo.write(i);
        delay(50);
      }
      delay(1000);
      for (int i = 180; i >= 26; i--)
      {
        handServo.write(i);
        delay(50);
      }
      delay(2000);
      handServo.write(26);
      delay(200);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action++;
    }

    else if (action == 13)
    {
      Serial.println("Action 13");      //
      Serial.println(switchStatus);
      for (int i = 70; i <= 110; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(2000);
      for (int i = 180; i >= 60; i--)
      {
        handServo.write(i);
        delay(40);
      }
      for (int i = 0; i < 3; i++)
      {
        handServo.write(60);
        delay(200);
        handServo.write(40);
        delay(800);
      }
      handServo.write(26);
      delay(2000);
      handServo.write(180);
      delay(500);
      boxServo.write(70);
      action++;
    }

    else if (action == 14)
    {
      Serial.println("Action 14");     //
      Serial.println(switchStatus);
      for (int i = 70; i <= 105; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(4000);
      boxServo.write(110);
      handServo.write(26);
      delay(650);
      handServo.write(180);
      delay(500);
      boxServo.write(100);
      delay(4000);
      boxServo.write(70);
      action++;
    }

    else if (action == 15)
    {
      Serial.println("Action 15");    //第十五种 
      Serial.println(switchStatus);
      for (int i = 70; i <= 105; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(1000);
      for (int i = 0; i < 3; i++)
      {
        for (int j = 70; j <= 105; j++) {
          boxServo.write(j);
          delay(50);
        }
        for (int j = 105; j >= 70; j--)
        {
          boxServo.write(j);
          delay(50);
        }
      }
      for (int j = 70; j <= 110; j++) {
        boxServo.write(j);
        delay(50);
      }
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(40);
      }
      delay(1000);
      handServo.write(26);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action = 1;
    }
  }
}
