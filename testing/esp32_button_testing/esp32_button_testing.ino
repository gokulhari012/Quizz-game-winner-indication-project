void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(35,INPUT);
  pinMode(32,INPUT);
  pinMode(33,INPUT);
  pinMode(34,INPUT);
  pinMode(36,INPUT);
  pinMode(39,INPUT);
  pinMode(25,INPUT);
  pinMode(26,INPUT);
  pinMode(27,INPUT);
  pinMode(23,INPUT);
  pinMode(19,INPUT);
  pinMode(18,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(35)==HIGH)Serial.println("35");  
  if(digitalRead(32)==HIGH)Serial.println("32");  
  if(digitalRead(33)==HIGH)Serial.println("33");  
  if(digitalRead(34)==HIGH)Serial.println("34");  
  if(digitalRead(36)==HIGH)Serial.println("36");  
  if(digitalRead(39)==HIGH)Serial.println("39");  
  if(digitalRead(25)==HIGH)Serial.println("25");  
  if(digitalRead(26)==HIGH)Serial.println("26");  
  if(digitalRead(27)==HIGH)Serial.println("27");  
  if(digitalRead(23)==HIGH)Serial.println("23");  
  if(digitalRead(19)==HIGH)Serial.println("19");  
  if(digitalRead(18)==HIGH)Serial.println("18");   
}
