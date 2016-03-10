sy Line Follower Robot -DIYhacking.com Arvind Sanjeev

Quick and easy line following robot using an IR reflectance
array.Connect Vcc and Gnd to the Pololu QTR-8A sensor from 
the arduino. Connect the pins 1,2,3,4 to arduino's analog
pins 0,1,2,3.
If the average of the 3 values of the sensors on the left is
greater than the average of those on the right, then the robot
moves left and vice versa.
NOTE : The values in the code for analog voltages would have 
to be modified if you are not using the Pololu QTR-8A reflectance
array sensor. Use trial and error to find out max and min 
values for your own IR array sensor.
 
 */
#include <Servo.h> 

Servo left;
Servo right; 

int mid = 0;
int mn = 0;
int mx = 0;

void setup() {
  left.attach(10); //left servo motor
  right.attach(11); //right servo motor
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  
  
  right.write(90);//stop signal
  left.write(90);//stop signal
  
  
  for(int j=0; j<=5; j++) { //Calibrating the sensor, finding max and 
                            //min reflectance values.  
    val = analogRead(j);
    if(val >= mx)
      mx = val;
    if(val <= mn)
      mn = val;
  
  }
    delay(1);
  }

  mid = ((mx + mn)/2);

  right.write(90);
  left.write(90);
  }

void loop(){

  int s0 = 0;
  int s1 = 0;
  int s2 = 0;
  int s3 = 0;
  int s4 = 0;
  int s5 = 0;

  s0 = analogRead(4);//Signal pin 1 on the board
  s1 = analogRead(5);//Signal pin 2 on the board
  s2 = analogRead(6);//Signal pin 3 on the board
  s3 = analogRead(7);//Signal pin 4 on the board


Serial.print("Mid: ");
Serial.print(mid); 
Serial.print(" ");
Serial.print(s0); 
Serial.print(" ");
Serial.print(s1); 
Serial.print(" ");
Serial.print(s2); 
Serial.print(" ");
Serial.print(s3); 
Serial.print(" ");
Serial.println();

right.write(180);//Move forward
left.write(0);//Move forward

delay(1);

if((((s0+s1)/2)>(((s2+s3)/2)+240)))//Move right
{
right.write(130);//180
left.write(90);//90
Serial.print(" RIGHT");
delay(abs((((s2+s3)/2)-((s0+s1)/2))/2));
}

if((((s0+s1)/2)<(((s2+s3)/2)-240)))//Move left
{
right.write(40);//90
left.write(0);//0
Serial.print(" LEFT");
delay(abs((((s2+s3)/2)-((s0+s1)/2))/2));
}

if((s0 > mid)&&(s3 > mid))//Stop if all the sensors give low 
{                         //reflectance values
right.write(90);
left.write(90);
Serial.print(" STOP");

for(int k=0; k<50; k++)
{
digitalWrite(13, HIGH);
delay(100);
digitalWrite(13, LOW);
delay(100);
}
delay(5000);
}


}

