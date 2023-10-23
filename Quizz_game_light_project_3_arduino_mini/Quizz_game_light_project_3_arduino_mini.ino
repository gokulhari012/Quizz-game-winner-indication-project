
//#define I1 35
//#define I2 32
//#define I3 33 /// need to confirm
//#define I4 34
//#define I5 36
//#define I6 39
//#define I7 25
//#define I8 26
//#define I9 27
//#define I10 23
//#define bt_reset 19
//#define bt_mode 18

#define I1 18
#define I2 19
#define I3 23
#define I4 27
#define I5 26
#define I6 25
#define I7 39
#define I8 36
#define I9 34
#define I10 33
#define bt_reset 32
#define bt_mode 35

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
int light_set_for_first = 0;
int light_set_for_second = 0;
int light_set_for_third = 0;
int reset_flag = 0;

int pressed = 0;
unsigned long previous_time=0;

struct player{
  int button;
  int red; //first
  int orange; //second
  int green;  //third
};

int Obuzzer_on = 32;
int Obuzzer_off = 33; 
struct player players[10] = {{I1,1,2,3},{I2,4,5,6},{I3,7,8,9},{I4,10,11,12},{I5,13,14,15},{I6,16,17,18},{I7,19,20,21},{I8,22,23,24},{I9,25,26,27},{I10,28,29,30}};

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
	attachInterrupt(bt_reset, pressed_reset,RISING);
	attachInterrupt(bt_mode, pressed_mode_change,RISING);

  digitalWrite(led_mode_1,HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mode==3){
    Serial.println("333");
    testing();
  }
  else{
    chageLightState();
  }
  if(pressed==1){
    Serial.println();
    send_data(Obuzzer_on);
    previous_time = millis();
    pressed=2;
  }
  else if(pressed==2 && previous_time+speaker_sound_delay < millis()){
    send_data(Obuzzer_off);
    pressed=0;
  }
  if(reset_flag==1){
    send_data(0);
    reset_flag = 0;
  } 
}

void send_data(int data){
  Serial2.write(data);
}

void chageLightState(){
  if (mode==1){
    if (first!=0 && light_set_for_first==0){
      send_data(players[first-1].green);
      light_set_for_first=1;
    }
    if(second!=0 && light_set_for_second==0){
      send_data(players[second-1].orange);
      light_set_for_second=1;
    }
    if(third!=0 && light_set_for_third==0){
      send_data(players[third-1].red);
      light_set_for_third=1;
    }
  }
  else if(mode==2){
    if (first!=0 && light_set_for_first==0){
      send_data(players[first-1].green);
      light_set_for_first=1;
    }
  }
}

//For testing in mode 3
void trigger_all_light(struct player player_temp){
  send_data(player_temp.green);
  delay(500);
  send_data(player_temp.orange);
  delay(500);
  send_data(player_temp.red);
}

void testing(){
  if(digitalRead(I1)==HIGH){
    while(digitalRead(I1)==HIGH);
    trigger_all_light(players[0]);
  }
  if(digitalRead(I2)==HIGH){
    while(digitalRead(I2)==HIGH);
    trigger_all_light(players[1]);
  }
  if(digitalRead(I3)==HIGH){
    while(digitalRead(I3)==HIGH);
    trigger_all_light(players[2]);
  }
  if(digitalRead(I4)==HIGH){
    while(digitalRead(I4)==HIGH);
    trigger_all_light(players[3]);
  }
  if(digitalRead(I5)==HIGH){
    while(digitalRead(I5)==HIGH);
    trigger_all_light(players[4]);
  }
  if(digitalRead(I6)==HIGH){
    while(digitalRead(I6)==HIGH);
    trigger_all_light(players[5]);
  }
  if(digitalRead(I7)==HIGH){
    while(digitalRead(I7)==HIGH);
    trigger_all_light(players[6]);
  }
  if(digitalRead(I8)==HIGH){
    while(digitalRead(I8)==HIGH);
    trigger_all_light(players[7]);
  }
  if(digitalRead(I9)==HIGH){
    while(digitalRead(I9)==HIGH);
    trigger_all_light(players[8]);
  }
  if(digitalRead(I10)==HIGH){
    while(digitalRead(I10)==HIGH);
    trigger_all_light(players[9]);
  }
}

//interept pins
void IRAM_ATTR pressed_reset(){
  state=0;
  first=0;
  second=0;
  third=0;
  light_set_for_first=0;
  light_set_for_second=0;
  light_set_for_third=0;
  reset_flag=1;
}
void IRAM_ATTR pressed_mode_change(){
    if(mode==1){
      mode=2;
      digitalWrite(led_mode_1,LOW);
      digitalWrite(led_mode_2,HIGH);
    }
    else if(mode==2){
      mode=3;
      digitalWrite(led_mode_2,LOW);
      digitalWrite(led_mode_3,HIGH);
    }
    else{
      mode=1;
      digitalWrite(led_mode_3,LOW);
      digitalWrite(led_mode_1,HIGH);
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




 


