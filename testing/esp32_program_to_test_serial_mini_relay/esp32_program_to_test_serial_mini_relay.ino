void setup() {
  // put your setup code here, to run once:
  Serial2.begin(115200,SERIAL_8N1,22,21);
  Serial2.write(0);
  delay(1000);
  Serial2.write(1);
  Serial2.write(2);
  Serial2.write(3);
  Serial2.write(4);
  Serial2.write(5);
  Serial2.write(6);
  Serial2.write(7);
  Serial2.write(8);
  Serial2.write(9);
  Serial2.write(10);
  Serial2.write(11);
  Serial2.write(12);
  Serial2.write(13);
  Serial2.write(14);
  Serial2.write(15);
  Serial2.write(16);
  Serial2.write(17);
  Serial2.write(18);
  Serial2.write(19);
  Serial2.write(20);
  Serial2.write(21);
  Serial2.write(22);
  Serial2.write(23);
  Serial2.write(24);
  Serial2.write(25);
  Serial2.write(26);
  Serial2.write(27);
  Serial2.write(28);
  Serial2.write(29);
  Serial2.write(30);
  Serial2.write(31);
  Serial2.write(32);
  delay(1000);
  Serial2.write(33); // 32 led off
  delay(1000);
  Serial2.write(32); 
  delay(2000);
  Serial2.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
