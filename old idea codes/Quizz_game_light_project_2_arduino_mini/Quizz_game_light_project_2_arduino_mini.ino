
#define I1 35
#define I2 32
#define I3 32
#define I4 34
#define I5 36
#define I6 39
#define I7 25
#define I8 26
#define I9 27
#define I10 23
#define bt_reset 19
#define bt_mode 18
#define led_mode_1 15
#define led_mode_2 2
#define led_mode_3 4
#define pin_RX 22
#define pin_TX 21

//configuration
int speaker_sound_delay = 1000;

int state = 0;
int mode = 1;
int first = 0;
int second = 0;
int third = 0;

int pressed = 0;
unsigned long previous_time=0;

struct light{
  int board;  // mini 1 and 2
  String pin;
};

struct button{
  int pin;
};
struct player{
  int button;
  light red; //first
  light orange; //second
  light green;  //third
};

struct light Obuzzer = {1,"O16"};
struct light lights[30] = {{1,"O1"},{1,"O2"},{1,"O3"},{1,"O4"},{1,"O5"},{1,"O6"},{1,"O7"},{1,"O8"},{1,"O9"},{1,"O10"},{1,"O11"},{1,"O12"},{1,"O13"},{1,"O14"},{1,"O15"},{2,"O1"},{2,"O2"},{2,"O3"},{2,"O4"},{2,"O5"},{2,"O6"},{2,"O7"},{2,"O8"},{2,"O9"},{2,"O10"},{2,"O11"},{2,"O12"},{2,"O13"},{2,"O14"},{2,"O15"}};
struct player players[10] = {{I1,lights[0],lights[1],lights[2]},{I2,lights[3],lights[4],lights[5]},{I3,lights[6],lights[7],lights[8]},{I4,lights[9],lights[10],lights[11]},{I5,lights[12],lights[13],lights[14]},{I6,lights[15],lights[16],lights[17]},{I7,lights[18],lights[19],lights[20]},{I8,lights[21],lights[22],lights[23]},{I9,lights[24],lights[25],lights[26]},{I10,lights[27],lights[28],lights[29]}};

void pressed_I1();
void pressed_I2();
void pressed_I3();
void pressed_I4();
void pressed_I5();
void pressed_I6();
void pressed_I7();
void pressed_I8();
void pressed_I9();
void pressed_I10();
void pressed_reset();
void pressed_mode_change();

void setup() {
  // put your setup code here, to run once:
  Serial2.begin(115200,SERIAL_8N1,pin_RX,pin_TX);
  Serial.begin(9600);
  Serial.println("Quiizz Game");
  
  pinMode(players[0].button, INPUT);
  pinMode(players[1].button, INPUT);
  pinMode(players[2].button, INPUT);
  pinMode(players[3].button, INPUT);
  pinMode(players[4].button, INPUT);
  pinMode(players[5].button, INPUT);
  pinMode(players[6].button, INPUT);
  pinMode(players[7].button, INPUT);
  pinMode(players[8].button, INPUT);
  pinMode(players[9].button, INPUT);
  pinMode(players[10].button, INPUT);

	pinMode(bt_reset, INPUT);
  pinMode(bt_mode, INPUT);
  pinMode(led_mode_1, OUTPUT);
  pinMode(led_mode_2, OUTPUT);
  pinMode(led_mode_3, OUTPUT);

	attachInterrupt(players[0].button, pressed_I1,RISING);
	attachInterrupt(players[1].button, pressed_I2,RISING);
	attachInterrupt(players[2].button, pressed_I3,RISING);
	attachInterrupt(players[3].button, pressed_I4,RISING);
	attachInterrupt(players[4].button, pressed_I5,RISING);
	attachInterrupt(players[5].button, pressed_I6,RISING);
	attachInterrupt(players[6].button, pressed_I7,RISING);
	attachInterrupt(players[7].button, pressed_I8,RISING);
	attachInterrupt(players[8].button, pressed_I9,RISING);
	attachInterrupt(players[9].button, pressed_I10,RISING);
	attachInterrupt(players[bt_reset].button, pressed_reset,RISING);
	attachInterrupt(players[bt_mode].button, pressed_mode_change,RISING);

  digitalWrite(led_mode_1,HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mode==3){
    Serial.println("333");
    testing();
  }
  else{
    Serial.println("111 or 222");
    chageLightState();
  }
  if(pressed==1){
    Serial.println(Obuzzer.board+" "+Obuzzer.pin);
    send_data("1 "+Obuzzer.pin);
    send_data("2 "+Obuzzer.pin);
    previous_time = millis();
    pressed=2;
  }
 
}
void send_data(String data){
  Serial2.println(data);
}

void trigger_light(struct player player_temp, String color){
  if(color=="green"){
    send_data(player_temp.green.board + " " +player_temp.green.pin);
  }
  else if(color=="orange"){
    send_data(player_temp.orange.board + " " +player_temp.orange.pin);
  }
  else if(color=="red"){
    send_data(player_temp.red.board + " " +player_temp.red.pin);
  }
  else if (color=="all"){
    send_data(player_temp.green.board + " " +player_temp.green.pin);
    send_data(player_temp.orange.board + " " +player_temp.orange.pin);
    send_data(player_temp.red.board + " " +player_temp.red.pin);
  }
}

void chageLightState(){
  if (mode==1){
    if (first!=0){
      trigger_light(players[--first],"green");
      first==0;
    }
    if(second!=0){
      trigger_light(players[--second],"orange");
      second==0;
    }
    if(third!=0){
      trigger_light(players[--third],"red");
      third==0;
    }
  }
  else if(mode==2){
    if (first!=0){
      trigger_light(players[--first],"green");
      first==0;
    }
  }
}

void testing(){
  if(digitalRead(I1)==HIGH){
    while(digitalRead(I1)==HIGH);
    trigger_light(players[0],"all");
  }
  if(digitalRead(I2)==HIGH){
    while(digitalRead(I2)==HIGH);
    trigger_light(players[1],"all");
  }
  if(digitalRead(I3)==HIGH){
    while(digitalRead(I3)==HIGH);
    trigger_light(players[2],"all");
  }
  if(digitalRead(I4)==HIGH){
    while(digitalRead(I4)==HIGH);
    trigger_light(players[3],"all");
  }
  if(digitalRead(I5)==HIGH){
    while(digitalRead(I5)==HIGH);
    trigger_light(players[4],"all");
  }
  if(digitalRead(I6)==HIGH){
    while(digitalRead(I6)==HIGH);
    trigger_light(players[5],"all");
  }
  if(digitalRead(I7)==HIGH){
    while(digitalRead(I7)==HIGH);
    trigger_light(players[6],"all");
  }
  if(digitalRead(I8)==HIGH){
    while(digitalRead(I8)==HIGH);
    trigger_light(players[7],"all");
  }
  if(digitalRead(I9)==HIGH){
    while(digitalRead(I9)==HIGH);
    trigger_light(players[8],"all");
  }
  if(digitalRead(I10)==HIGH){
    while(digitalRead(I10)==HIGH);
    trigger_light(players[9],"all");
  }
}

//interept pins
void IRAM_ATTR pressed_reset(){
  state=0;
  first==0;
  second=0;
  third=0;
  send_data("ALL OFF");
  Serial.println("reset");
}
void IRAM_ATTR pressed_mode_change(){
  Serial.println("mode");
    if(mode==1){
      mode=2;
      digitalWrite(led_mode_1,LOW);
      digitalWrite(led_mode_2,HIGH);
      Serial.println("mode 2");
    }
    else if(mode==2){
      mode=3;
      digitalWrite(led_mode_2,LOW);
      digitalWrite(led_mode_3,HIGH);
      Serial.println("mode 3");
    }
    else{
      mode=1;
      digitalWrite(led_mode_3,LOW);
      digitalWrite(led_mode_1,HIGH);
      Serial.println("mode 1");
    }
}

void IRAM_ATTR setLightState(int bt_number){
  pressed=1;
  if(bt_number!=first && bt_number!=second && bt_number!=third){
    if (state==0){
      first = bt_number;
      state=1;
    }
    else if(state==1){
      second = bt_number;
      state=2;
    }
    else if(state==2){
      third = bt_number;
      state=3;
    }
  }
}

void IRAM_ATTR pressed_I1(){
  setLightState(1);
}
void IRAM_ATTR pressed_I2(){
 setLightState(2);
}
void IRAM_ATTR pressed_I3(){
 setLightState(3);
}
void IRAM_ATTR pressed_I4(){
 setLightState(4);
}
void IRAM_ATTR pressed_I5(){
 setLightState(5);
}
void IRAM_ATTR pressed_I6(){
 setLightState(6);
}
void IRAM_ATTR pressed_I7(){
 setLightState(7);
}
void IRAM_ATTR pressed_I8(){
 setLightState(8);
}
void IRAM_ATTR pressed_I9(){
 setLightState(9);
}
void IRAM_ATTR pressed_I10(){
 setLightState(10);
}




 


