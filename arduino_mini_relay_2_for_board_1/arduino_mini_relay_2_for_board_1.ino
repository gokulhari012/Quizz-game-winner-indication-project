#define O1 2
#define O2 3
#define O3 4
#define O4 5
#define O5 6
#define O6 7
#define O7 8
#define O8 9
#define O9 A3
#define O10 A2
#define O11 A1
#define O12 A0
#define O13 13
#define O14 12
#define O15 11
#define O16 10

void setup() {
  // put your setup code here, to run once:
  pinMode(O1,OUTPUT);
  pinMode(O2,OUTPUT);
  pinMode(O3,OUTPUT);
  pinMode(O4,OUTPUT);
  pinMode(O5,OUTPUT);
  pinMode(O6,OUTPUT);
  pinMode(O7,OUTPUT);
  pinMode(O8,OUTPUT);
  pinMode(O9,OUTPUT);
  pinMode(O10,OUTPUT);
  pinMode(O11,OUTPUT);
  pinMode(O12,OUTPUT);
  pinMode(O13,OUTPUT);
  pinMode(O14,OUTPUT);
  pinMode(O15,OUTPUT);
  pinMode(O16,OUTPUT);
  digitalWrite(O1,HIGH);
  digitalWrite(O2,HIGH);
  digitalWrite(O3,HIGH);
  digitalWrite(O4,HIGH);
  digitalWrite(O5,HIGH);
  digitalWrite(O6,HIGH);
  digitalWrite(O7,HIGH);
  digitalWrite(O8,HIGH);
  digitalWrite(O9,HIGH);
  digitalWrite(O10,HIGH);
  digitalWrite(O11,HIGH);
  digitalWrite(O12,HIGH);
  digitalWrite(O13,HIGH);
  digitalWrite(O14,HIGH);
  digitalWrite(O15,HIGH);
  digitalWrite(O16,HIGH);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    int data = Serial.read();
    switch(data){
      case 1:
        digitalWrite(O1,LOW);
        break;
      case 2:
        digitalWrite(O2,LOW);
        break;
      case 3:
        digitalWrite(O3,LOW);
        break;
      case 4:
        digitalWrite(O4,LOW);
        break;
      case 5:
        digitalWrite(O5,LOW);
        break;
      case 6:
        digitalWrite(O6,LOW);
        break;
      case 7:
        digitalWrite(O7,LOW);
        break;
      case 8:
        digitalWrite(O8,LOW);
        break;
      case 9:
        digitalWrite(O9,LOW);
        break;
      case 10:
        digitalWrite(O10,LOW);
        break;
      case 11:
        digitalWrite(O11,LOW);
        break;
      case 12:
        digitalWrite(O12,LOW);
        break;
      case 13:
        digitalWrite(O13,LOW);
        break;
      case 14:
        digitalWrite(O14,LOW);
        break;
      case 15:
        digitalWrite(O15,LOW);
        break;
      case 16:
        digitalWrite(O16,LOW);
        break;
      case 0:
        digitalWrite(O1,HIGH);
        digitalWrite(O2,HIGH);
        digitalWrite(O3,HIGH);
        digitalWrite(O4,HIGH);
        digitalWrite(O5,HIGH);
        digitalWrite(O6,HIGH);
        digitalWrite(O7,HIGH);
        digitalWrite(O8,HIGH);
        digitalWrite(O9,HIGH);
        digitalWrite(O10,HIGH);
        digitalWrite(O11,HIGH);
        digitalWrite(O12,HIGH);
        digitalWrite(O13,HIGH);
        digitalWrite(O14,HIGH);
        digitalWrite(O15,HIGH);
        digitalWrite(O16,HIGH);
        break;
    }
  }
}
