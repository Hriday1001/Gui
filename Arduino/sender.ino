#define MASTER_EN   8                 // connected to RS485 Enable pin
#define SWITCH      3                 // Declare LED pin
String message ;
int ft1;
int ft2;
int rt;
int lt;
int dt1;
int dt2;
int cl;

void setup() {
  pinMode(SWITCH , INPUT_PULLUP);     // Declare LED pin as output
  pinMode(MASTER_EN , OUTPUT);        // Declare Enable pin as output
  Serial.begin(9600);                 // set serial communication baudrate 
  digitalWrite(MASTER_EN , HIGH);      // Make Enable pin low, Receiving mode ON
}

void loop() {
    delay(1000);                        // Debouncing for switch
   // digitalWrite(MASTER_EN , HIGH);     // Make Enable pin high to send Data
    delay(5);                           // required minimum delay of 5ms
    
    
    
    if (Serial.available()>0)
    {
      message=Serial.readStringUntil('/');
      ft1 = (message.substring(0,4)).toInt();
      ft2 = (message.substring(4,8)).toInt();
      rt = (message.substring(8,12)).toInt();
      lt = (message.substring(12,16)).toInt();
      dt1 = (message.substring(16,20)).toInt();
      dt2 = (message.substring(20,24)).toInt();
      cl = (message.substring(24,27)).toInt();
      // ft1 = (ft1/10 - 100)
      // ft2 = (ft2/10 - 100)
      // rt = (rt/10 - 100)
      // lt = (lt/10 - 100)
      // dt1 = (dt1/10 - 100)
      // dt2 = (dt2/10 - 100);
      // cl = (cl+100);      
    }
  


    
    Serial.println(String(ft1)+'/'+String(ft2)+'/'+String(rt)+'/'+String(lt)+'/'+String(dt1)+'/'+String(dt2)+'/'+String(cl)+'/');     // Send String serially, End String with *
  //  Serial.flush();                     // wait for transmission of data
  //  digitalWrite(MASTER_EN , LOW);      // Receiving mode ON
  
  
  }
