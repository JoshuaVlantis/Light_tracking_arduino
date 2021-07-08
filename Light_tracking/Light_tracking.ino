  #include <Servo.h>
  
  Servo myservo;
  Servo myservo2;
  

  //Ints for changing the servo pos
  int pos           = 0;
  int i             = 90;
  int ii            = 90;
  
  //Raw Data pins 
  int sensorPin     = A0; 
  int sensorPin2    = A1;
  int sensorPin3    = A2; 
  int sensorPin4    = A3;
  
  //Call data ints
  int sensorValue   = 0;
  int sensorValue2  = 0;
  int sensorValue3  = 0;
  int sensorValue4  = 0; 

  int runonce       = 1;
    


  int lowlight;

  void setup() 
{
      Serial.begin(9600); 
      myservo.attach(9) ;
      myservo2.attach(8);
}
  void loop() 
    {

      

      
      sensorValue   =   analogRead(sensorPin) ;
      sensorValue2  =   analogRead(sensorPin2);
      sensorValue3  =   analogRead(sensorPin3);
      sensorValue4  =   analogRead(sensorPin4);



      //Scaling the light values for left and right movement
      int sens1 = sensorValue   / 100;
      int sens2 = sensorValue2  / 100;
      int sens3 = sensorValue3  / 100;
      int sens4 = sensorValue4  / 100;

      int alllights = (sens1 + sens2 + sens3 + sens4);
      int allav     = (alllights / 1);

      int lightstate;
      



//Checks if the room lighting isnt too dim if the room is too dim the servos will switch off      
      while  (allav > 15)
        {
          lightstate = 1;
        }

      while  (allav < 15)
        {
          lightstate = 0;
          ii  = 90;
          i   = 90;
          runonce = 0;
        }
Serial.println(allav);

      



    while ((sens1 > sens2) && (i < 180))
      {
        myservo.write(i);
        delay (30);
        i++;
       
      }

    while ((sens1 < sens2) && (i > 0))
      {
        myservo.write(i);
        delay (30);
        i--;
        
      }


    while ((sens3 < sens4) && (ii < 150))
      {
        myservo2.write(ii);
        delay (30);
        ii++;
        
      }

     while ((sens3 > sens4) && (ii > 30))
      {
        myservo2.write(ii);
        delay (30);
        ii--;
        
      }

}
