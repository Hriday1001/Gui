String message, ft1, ft2, rt, lt, dt1, dt2, cl;
int f1, f2, d1, d2, r, l, c;
int prevf1, prevf2, prevr, prevl, prevd1, prevd2, prevc;
#include <Servo.h>
Servo fthruster1;
Servo fthruster2;
Servo rthruster;
Servo lthruster;
Servo dthruster1;
Servo dthruster2;
Servo claw;

void setup() {
  // put your setup code here, to run once:
 prevf1 = 1500;
 prevf2 = 1500;
 prevd1 = 1500;
 prevd2 = 1500;
 prevr = 1500;
 prevl = 1500;
 prevc = 100;    
 Serial.begin(9600);
 Serial1.begin(9600);
 pinMode(25, OUTPUT); 
 digitalWrite(25, LOW);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 //pinMode(22, OUTPUT);
 //pinMode(46, OUTPUT);
 fthruster1.attach(3); //surge
 fthruster1.writeMicroseconds(1500);
 fthruster2.attach(5); //surge
 fthruster2.writeMicroseconds(1500);
 rthruster.attach(8);
 rthruster.writeMicroseconds(1500);
 lthruster.attach(4);
 dthruster1.attach(10);
 dthruster2.attach(9);
 lthruster.writeMicroseconds(1500);
 dthruster1.writeMicroseconds(1500);
 dthruster2.writeMicroseconds(1500);
 claw.attach(6);
 claw.write(90);
 delay(8000);
}

void decode()
{
 message=Serial1.readStringUntil('/');
 ft1 = message.substring(0,4);
 ft2 = message.substring(4,8);
 rt = message.substring(8,12);
 lt = message.substring(12,16);
 dt1 = message.substring(16, 20);
 dt2 = message.substring(20, 24);
 cl = message.substring(24, 27);
}

void write()
{
 Serial.print("The incoming String :"); 
 Serial.println(message);
 
 f1= ft1.toInt();
 //Serial.print("Surge Value :");
 
 if(f1<=1700 && f1>=1300)
 {
   prevf1 = f1;
   fthruster1.writeMicroseconds(f1*10 + 1000);
 }
 else 
 {
   ft1 = prevf1;
   fthruster1.writeMicroseconds(f1*10 + 1000);
 }
 f2= ft2.toInt();
 //Serial.print("Surge Value :");
 
 if(f2<=1700 && f2>=1300)
 {
   prevf2 = f2;
   fthruster2.writeMicroseconds(f2*10 + 1000);
 }
 else 
 {
   f2 = prevf2;
   fthruster2.writeMicroseconds(f2*10 + 1000);
 }
 //Serial.println(f);
// if(claw1_status == "Y")
 //{
 //  Serial.print("Claw 1 :");
 //  Serial.println("Opening");
 //  digitalWrite(6, HIGH);
 //  digitalWrite(7,LOW);
// }
 //else if(claw1_status == "N")
// {
 //  Serial.print("Claw 1 :");
 //  Serial.println("Closing");
 //  digitalWrite(6, LOW);
 //  digitalWrite(7,HIGH);
 //}

// i=depth.toInt();
// if(i>=1500 && i<=1700)
// {
//   previ = i;
//   Serial.print("Depth Thruster value  :");
//   Serial.println(i);
//   dthruster1.writeMicroseconds(i);
//   dthruster2.writeMicroseconds(i);
// }
// else 
// {
//   i = previ;
//   Serial.print("Depth Thruster value  :");
//   Serial.println(i);
//   dthruster1.writeMicroseconds(i);
//   dthruster2.writeMicroseconds(i);
// }
 
// if(claw2_status == "Y")
// {
//   Serial.print("Claw 2 :");
//   Serial.println("Opening");
// }
// else if(claw2_status == "N")
// {
//   Serial.print("Claw 2 :");
//   Serial.println("Closing");  
// }
 
// n=yaw1.toInt();
// o=yaw2.toInt();
r = rt.toInt();
 //Serial.print("Surge Value :");
 
 if(r<=1700 && r>=1300)
 {
   prevr = r;
   rthruster.writeMicroseconds(r*10 + 1000);
 }
 else 
 {
   r = prevr;
   rthruster.writeMicroseconds(r*10 + 1000);
 } 
 l = lt.toInt();
 //Serial.print("Surge Value :");
 
 if(l<=1700 && l>=1300)
 {
   prevl = l;
   lthruster.writeMicroseconds(l*10 + 1000);
 }
 else 
 {
   l = prevl;
   lthruster.writeMicroseconds(l*10 + 1000);
 }
 d1= dt1.toInt();
 //Serial.print("Surge Value :");
 
 if(d1<=1700 && d1>=1300)
 {
   prevd1 = d1;
   dthruster1.writeMicroseconds(d1*10 + 1000);
 }
 else 
 {
   d1 = prevd1;
   dthruster1.writeMicroseconds(d1*10 + 1000);
 }
 d2= dt2.toInt();
 //Serial.print("Surge Value :");
 
 if(d2<=1700 && d2>=1300)
 {
   prevd2 = d2;
   dthruster2.writeMicroseconds(d2*10 + 1000);
 }
 else 
 {
   d2 = prevd2;
   dthruster2.writeMicroseconds(d2*10 + 1000);
 }
 c= cl.toInt();
 //Serial.print("Surge Value :");
 
 if(c<=235 && c>=190)
 {
   prevc = c;
   claw.write(c - 100);
 }
 else 
 {
   c = prevc;
   claw.write(c - 100);
 } 
  // rthruster.writeMicroseconds(n*10+1000);
  // lthruster.writeMicroseconds(o*10+1000);
 
}
void loop() {
 if (Serial1.available()>0)
 {
   decode();
   write();
   Serial.println(" ");
   Serial.flush();
 }
}
