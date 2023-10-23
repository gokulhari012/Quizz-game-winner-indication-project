#include "Arduino.h"
#include "PCF8574.h" 
#define I1 36
#define I2 39
#define I3 34
#define I4 35
#define I5 32
#define I6 33
#define I7 25
#define I8 26
#define I9 27
#define I10 23
#define bt_reset 19
#define bt_mode 18
#define SCL 22
#define SDA 21
#define S_1 17 //DIP switch 1
#define S_2 16 //DIP switch 2
#define S_3 4  //DIP switch 3
#define Obuzzer 13

#define PCF1_add 0x39
#define PCF2_add 0x39
#define PCF3_add 0x39
#define PCF4_add 0x39

PCF8574 PCF1(PCF1_add);
PCF8574 PCF2(PCF2_add);
PCF8574 PCF3(PCF3_add);
PCF8574 PCF4(PCF4_add);

int state = 0;
int mode = 0;
int first = 0;
int second = 0;
int third = 0;

struct light{
  PCF8574 pcf_obj;
  int pin;
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

struct lights[32] = {{PCF1,0},{PCF1,1},{PCF1,2},{PCF1,3},{PCF1,4},{PCF1,5},{PCF1,6},{PCF1,7},{PCF2,0},{PCF2,1},{PCF2,2},{PCF2,3},{PCF2,4},{PCF2,5},{PCF2,6},{PCF2,7},{PCF3,0},{PCF3,1},{PCF3,2},{PCF3,3},{PCF3,4},{PCF3,5},{PCF3,6},{PCF3,7},{PCF4,0},{PCF4,1},{PCF4,2},{PCF4,3},{PCF4,4},{PCF4,5},{PCF4,6},{PCF4,7}};
struct player players[10] = {{I1,light[0],light[1],light[2]},{I2,light[3],light[4],light[5]},{I3,light[6],light[7],light[8]},{I4,light[9],light[10],light[11]},{I5,light[12],light[13],light[14]},{I6,light[15],light[16],light[17]},{I7,light[18],light[19],light[20]},{I8,light[21],light[22],light[23]},{I9,light[24],light[25],light[26]},{I10,light[27],light[28],light[29]}};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Quiizz Game");
  
  for(int i=0;i<players.size();i++){
      pinMode(players[i].button, INPUT_PULLDOWN);
  }
	
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

  light[30].pcf_obj.write(light[30].pin,1);
  
  PCF1.begin(SDA,SCL);
  PCF2.begin(SDA,SCL);
  PCF3.begin(SDA,SCL);
  PCF4.begin(SDA,SCL);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void IRAM_ATTR pressed_reset(){
  state=0
  if (first!=0){
    first--;
    players[first].red.pcf_obj.write(players[first].red.pin, 0);
    first==0
  }
  if (second!=0){
    second--;
    players[second].orange.pcf_obj.write(players[second].orange.pin, 0);
    second=0;
  }
  if (third!=0){
    third--;
    players[third].green.pcf_obj.write(players[third].green.pin, 0);
    third=0
  }
  //PCF_39.write8(value); // value is 0 or 1. it will erase all the lights
}
void IRAM_ATTR pressed_mode_change(){
    if(mode==0){
      mode=1
      light[31].pcf_obj.write(light[31].pin,1);
      light[30].pcf_obj.write(light[30].pin,0);
    }
    else{
      mode=0
      light[30].pcf_obj.write(light[30].pin,1);
      light[31].pcf_obj.write(light[31].pin,0);
    }
}
void IRAM_ATTR pressed_I1(){
  chageLightState(1);
}
void IRAM_ATTR pressed_I2(){
 chageLightState(2);
}
void IRAM_ATTR pressed_I3(){
 chageLightState(3);
}
void IRAM_ATTR pressed_I4(){
 chageLightState(4);
}
void IRAM_ATTR pressed_I5(){
 chageLightState(5);
}
void IRAM_ATTR pressed_I6(){
 chageLightState(6);
}
void IRAM_ATTR pressed_I7(){
 chageLightState(7);
}
void IRAM_ATTR pressed_I8(){
 chageLightState(8);
}
void IRAM_ATTR pressed_I9(){
 chageLightState(9);
}
void IRAM_ATTR pressed_I10(){
 chageLightState(10);
}

void IRAM_ATTR chageLightState(int bt_number){
  if(bt_nuumber){
    if (state==0){
      if (mode==0){
        state=1;
      }
      else{
        state=3;
      }
      first = bt_number;
      bt_number--;
      players[bt_number].red.pcf_obj.write(players[bt_number].red.pin, 1);
    }
    else if(state==1){
      state=2;
      second = bt_number;
      bt_number--;
      players[bt_number].orange.pcf_obj.write(players[bt_number].orange.pin, 1);
    }
    else if(state==2){
      state=3;
      third = bt_number;
      bt_number--;
      players[bt_number].green.pcf_obj.write(players[bt_number].green.pin, 1);
    }
  }
}
 


