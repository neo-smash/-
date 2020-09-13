#include <SwitchControlLibrary.h>
#include <math.h>

unsigned long hosu=0;
int light=0,down=0;
int day=0,toki=0,shohi=0;
double egg=0;
long count=0,count2=0,seki=1,last=0,dcount=1;

void setup() {
  // put your setup code here, to run once:
pinMode(15,OUTPUT);pinMode(10,OUTPUT);pinMode(9,OUTPUT);
pinMode(8,OUTPUT);pinMode(7,OUTPUT);pinMode(16,OUTPUT);pinMode(14,OUTPUT);  
pinMode(6,INPUT_PULLUP);//決定
pinMode(5,INPUT_PULLUP);//セレクト  
for(int a=0;a<5;a++){
  SwitchControlLibrary().PressButtonL();
  delay(50);
  SwitchControlLibrary().PressButtonR();
  delay(50);
  SwitchControlLibrary().ReleaseButtonL();    
  delay(100);
  SwitchControlLibrary().ReleaseButtonR();
  delay(100);
  } 
Serial.begin(9600);
}

//Aボタンを3回押して離す
void PressA(){
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(100);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(100);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(100);
  }
void maru(){
digitalWrite(15,0);digitalWrite(10,0);digitalWrite(9,1); 
digitalWrite(8,1);digitalWrite(7,1);digitalWrite(16,0);digitalWrite(14,0);  
}
void none(){
digitalWrite(15,1);digitalWrite(10,1);digitalWrite(9,1); 
digitalWrite(8,1);digitalWrite(7,1);digitalWrite(16,1);digitalWrite(14,1);
}
void d0(){
digitalWrite(15,0);digitalWrite(10,0);digitalWrite(9,0); 
digitalWrite(8,0);digitalWrite(7,0);digitalWrite(16,0);digitalWrite(14,1);     
}
void d1(){
digitalWrite(15,1);digitalWrite(10,0);digitalWrite(9,0); 
digitalWrite(8,1);digitalWrite(7,1);digitalWrite(16,1);digitalWrite(14,1);  
}
void d2(){
digitalWrite(15,0);digitalWrite(10,0);digitalWrite(9,1); 
digitalWrite(8,0);digitalWrite(7,0);digitalWrite(16,1);digitalWrite(14,0); 
}
void d3(){
digitalWrite(15,0);digitalWrite(10,0);digitalWrite(9,0); 
digitalWrite(8,0);digitalWrite(7,1);digitalWrite(16,1);digitalWrite(14,0); 
}
void d4(){
digitalWrite(15,1);digitalWrite(10,0);digitalWrite(9,0); 
digitalWrite(8,1);digitalWrite(7,1);digitalWrite(16,0);digitalWrite(14,0);  
}
void d5(){
digitalWrite(15,0);digitalWrite(10,1);digitalWrite(9,0); 
digitalWrite(8,0);digitalWrite(7,1);digitalWrite(16,0);digitalWrite(14,0); 
}
void d6(){
digitalWrite(15,0);digitalWrite(10,1);digitalWrite(9,0); 
digitalWrite(8,0);digitalWrite(7,0);digitalWrite(16,0);digitalWrite(14,0); 
}
void d7(){
digitalWrite(15,0);digitalWrite(10,0);digitalWrite(9,0); 
digitalWrite(8,1);digitalWrite(7,1);digitalWrite(16,0);digitalWrite(14,1);  
}
void d8(){
digitalWrite(15,0);digitalWrite(10,0);digitalWrite(9,0); 
digitalWrite(8,0);digitalWrite(7,0);digitalWrite(16,0);digitalWrite(14,0); 
}
void d9(){
digitalWrite(15,0);digitalWrite(10,0);digitalWrite(9,0); 
digitalWrite(8,0);digitalWrite(7,1);digitalWrite(16,0);digitalWrite(14,0);  
}
int left(void){
  SwitchControlLibrary().MoveLeftStick(0,128);  
}
int right(void){
  SwitchControlLibrary().MoveLeftStick(255,128);
}
int front(void){
  SwitchControlLibrary().MoveLeftStick(128,0);
}
int back(void){
  SwitchControlLibrary().MoveLeftStick(128,255);
}
int center(void){
  SwitchControlLibrary().MoveLeftStick(128,128);
}
int right2(void){
  SwitchControlLibrary().MoveRightStick(255,128);
}
int front2(void){
  SwitchControlLibrary().MoveRightStick(128,0);
}
int center2(void){
  SwitchControlLibrary().MoveRightStick(128,128);
}
int toname(void){
  SwitchControlLibrary().MoveLeftStick(255,0);
}

void loop() {
  // put your main code here, to run repeatedly:
while(1){//モードセレクト
if(dcount==1){d1();}
if(digitalRead(5)==LOW){
  delay(300);
  dcount=dcount+1;
  if(dcount==1){d1();}
  if(dcount==2){d2();}
  if(dcount==3){d3();}
  if(dcount==4){d4();}
  if(dcount==5){d5();}
  if(dcount==6){d6();}
  if(dcount==7){d7();}
  if(dcount==8){d8();}
  if(dcount==9){d9();}
  if(dcount==10){dcount=1;d1();}
}
if(digitalRead(6)==LOW){//決定
  delay(300);
break;  
}
}

while(dcount==1){//時渡り
  
  while(light==0){
    for(int i=0;i<8;i++){
    none();
    delay(100);
    d1();
    delay(100);
    none();
    delay(100);
    }
    while(1){  
    light=1;
    if(digitalRead(5)==LOW){
    delay(300);
    toki+=1;
    if(toki==5){
      toki=0;
    }
    }
    if(digitalRead(6)==LOW){//決定
    delay(300);
    maru();
    delay(500);
    none();
    break;  
    }
    if(toki==0){d0();}
    if(toki==1){d1();}
    if(toki==2){d2();}
    if(toki==3){d3();}
    if(toki==4){d4();}
    }
  }
  Serial.println(toki);
  if(count==0){
  SwitchControlLibrary().PressButtonA(); //巣穴前
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(2000);
  }
  if(toki==0){
    toki=-1;
  }
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(3000);
  
  // 募集開始
  SwitchControlLibrary().PressButtonHome();
  delay(100);
  SwitchControlLibrary().ReleaseButtonHome();
  delay(400);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1200);
  
  // 設定画面
  SwitchControlLibrary().MoveHat(4); // down
  delay(1500);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(500);
  // 時間設定
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(500);
  // 時間の変更
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(100);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(100);
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(200);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(100);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(100);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(100);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(100);
  
  //ホーム画面
  SwitchControlLibrary().PressButtonHome();
  delay(100);
  SwitchControlLibrary().ReleaseButtonHome();
  delay(1000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);

  //皆で挑戦をやめる
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(500);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(2000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(6000);

  day=day+1;
  count=count+1;

  //巣穴の前
  if(day!=31){
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(2000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);
  }
  
  else if(day==31){
    day=0;
  }

  SwitchControlLibrary().PressButtonA(); 
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(2000);
  
  if(count==toki){
    while(1){
      maru();
      if(digitalRead(6)==LOW){//やり直し
      none();
      count=0;
      SwitchControlLibrary().PressButtonHome();
      delay(100);
      SwitchControlLibrary().ReleaseButtonHome();
      delay(1000);
      SwitchControlLibrary().PressButtonX();
      delay(100);
      SwitchControlLibrary().ReleaseButtonX();
      delay(1000);
      SwitchControlLibrary().PressButtonA();//ソフト終了
      delay(100);
      SwitchControlLibrary().ReleaseButtonA();
      delay(6000);

      SwitchControlLibrary().PressButtonA();
      delay(100);
      SwitchControlLibrary().ReleaseButtonA();
      delay(2000);
      
      SwitchControlLibrary().PressButtonA();
      delay(100);
      SwitchControlLibrary().ReleaseButtonA();
      delay(18000);
  
      SwitchControlLibrary().PressButtonA();
      delay(100);
      SwitchControlLibrary().ReleaseButtonA();
      delay(10000);
      break;
      }   
  }
}
}

while(dcount==2){//乱数消費
  while(light==0){
    for(int i=0;i<8;i++){
    none();
    delay(100);
    d2();
    delay(100);
    none();
    delay(100);
    }
    
    for(int i=0;i<6;i++){
    if(i==0){d6();delay(800);none();}if(i==1){d5();delay(800);none();}
    if(i==2){d4();delay(800);none();}if(i==3){d3();delay(800);none();}
    if(i==4){d2();delay(800);none();}if(i==5){d1();delay(800);none();}
    
    d0(); 
    while(1){  
    if(digitalRead(5)==LOW){//選択
    delay(300);
    count+=1;
    if(count==10){
      count=0;
    }
    if(count==0){d0();}if(count==1){d1();}
    if(count==2){d2();}if(count==3){d3();}
    if(count==4){d4();}if(count==5){d5();}
    if(count==6){d6();}if(count==7){d7();}
    if(count==8){d8();}if(count==9){d9();}
    }
    if(digitalRead(6)==LOW){//決定
    delay(300);
    if(i==0){
      seki=seki*100000;
    }
    else{
    seki=seki/10;
    }
    count=count*seki;
    last=last+count;
    count=0;
    break;   
    }
    }
    }
    maru();
    delay(1000);
    none();
    light=1;
  }
  
  SwitchControlLibrary().PressButtonA();
  delay(50);
  SwitchControlLibrary().ReleaseButtonA();
  delay(110);
  
  SwitchControlLibrary().MoveHat(6); // left
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().MoveHat(6); // left
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().MoveHat(6); // left
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  
  SwitchControlLibrary().MoveHat(0); // left
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);

  SwitchControlLibrary().PressButtonA();
  delay(50);
  SwitchControlLibrary().ReleaseButtonA();
  delay(50);
  SwitchControlLibrary().PressButtonA();
  delay(50);
  SwitchControlLibrary().ReleaseButtonA();
  delay(50);
  SwitchControlLibrary().PressButtonA();
  delay(50);
  SwitchControlLibrary().ReleaseButtonA();
  delay(50);
  SwitchControlLibrary().PressButtonA();
  delay(50);
  SwitchControlLibrary().ReleaseButtonA();
  delay(110);
  
  day=day+1;
  
  if(day!=31){
  shohi=shohi+1;
  }
  
  if(day==31){
  day=0;  
  }
  
  if(shohi==last){
    while(1){
    count+=1;
    count=0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    }
  }  
}
while(dcount==3){//レイド配布
  while(light==0){
    count=1;
    for(int i=0;i<8;i++){
    none();
    delay(100);
    d3();
    delay(100);
    none();
    delay(100);
    }
    if(count==1){d1();}
    while(1){
    if(digitalRead(5)==LOW){
    delay(300);
    count+=1;
    if(count==3){
      count=1;
    }
    }
    if(digitalRead(6)==LOW){//決定
    delay(300);
    maru();
    delay(500);
    none();
    break;  
    }
    if(count==1){d1();}
    if(count==2){d2();}  
    }
    light=1;
 }
while(count==1){//個人配布用
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1500);
  
 while(1){
  if(digitalRead(6)==LOW){
    delay(800);
  break;
 }
 }
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(100);
  
  while(1){//皆で挑戦の次
    if(digitalRead(6)==LOW){
      delay(800);
    break;
  }
  }
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(500);
  
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(800);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(800);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(800);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();//レイドスタート
  delay(45000);
  
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(500);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(500);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);

  SwitchControlLibrary().PressButtonHome();
  delay(100);
  SwitchControlLibrary().ReleaseButtonHome();
  delay(1000);
  SwitchControlLibrary().PressButtonX();
  delay(100);
  SwitchControlLibrary().ReleaseButtonX();
  delay(1000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(10000);

  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(2000);
  
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(18000);
  
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(10000);
}

while(count==2){//他人配布用
  SwitchControlLibrary().PressButtonY();
  delay(100);
  SwitchControlLibrary().ReleaseButtonY();
  delay(3000);
  SwitchControlLibrary().PressButtonPlus();
  delay(100);
  SwitchControlLibrary().ReleaseButtonPlus();
  delay(13000);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(2000);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(5000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(4000);
  SwitchControlLibrary().PressButtonPlus();
  delay(100);
  SwitchControlLibrary().ReleaseButtonPlus();
  delay(1000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);
  SwitchControlLibrary().PressButtonPlus();
  delay(100);
  SwitchControlLibrary().ReleaseButtonPlus();
  delay(2000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);
  
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);
  
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(181000);//レイド待ち
  
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(500);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(800);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(800);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(800);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(800);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();//レイドスタート
  delay(10000);
  
  SwitchControlLibrary().PressButtonHome();
  delay(100);
  SwitchControlLibrary().ReleaseButtonHome();
  delay(1000);
  SwitchControlLibrary().PressButtonX();
  delay(100);
  SwitchControlLibrary().ReleaseButtonX();
  delay(1000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(10000);

  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(2000);
  
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(18000);
  
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(10000);
}
}

while(dcount==4){//自動レイドバトル
  while(light==0){
    for(int i=0;i<8;i++){
    none();
    delay(100);
    d4();
    delay(100);
    none();
    delay(100);
    }
    light=1;
  }
  while(1){
  front2();
  SwitchControlLibrary().MoveHat(6); // left
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(100);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);
  }
}

while(dcount==5){//BP
  while(light==0){
    for(int i=0;i<8;i++){
    none();
    delay(100);
    d5();
    delay(100);
    none();
    delay(100);
    }
    light=1;
  }
  SwitchControlLibrary().PressButtonZL();
  delay(100);
  SwitchControlLibrary().ReleaseButtonZL();
  delay(3000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1500);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1500);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(1500);
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(1500);
  SwitchControlLibrary().PressButtonZL();
  delay(100);
  SwitchControlLibrary().ReleaseButtonZL();
  delay(3000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1500);
  SwitchControlLibrary().PressButtonZL();
  delay(100);
  SwitchControlLibrary().ReleaseButtonZL();
  delay(3000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1500);
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(1500);
  SwitchControlLibrary().PressButtonZL();
  delay(100);
  SwitchControlLibrary().ReleaseButtonZL();
  delay(3000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1500);
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(1500);
  SwitchControlLibrary().PressButtonZL();
  delay(100);
  SwitchControlLibrary().ReleaseButtonZL();
  delay(1500);
  SwitchControlLibrary().PressButtonL();
  delay(100);
  SwitchControlLibrary().ReleaseButtonL();
  delay(1500);
  SwitchControlLibrary().PressButtonL();
  delay(100);
  SwitchControlLibrary().ReleaseButtonL();
  delay(1500);  
}

while(dcount==6){//自動孵化
  while(light==0){
    count2=1;
    count=1;
    for(int i=0;i<8;i++){
    none();
    delay(100);
    d6();
    delay(100);
    none();
    delay(100);
    }
    if(count2==1){d1();}
    while(1){//孵化ボックス数選択
    if(digitalRead(5)==LOW){
    delay(300);
    count2+=1;
    if(count2==10){
      count2=1;
    }
    }
    if(digitalRead(6)==LOW){//決定
    delay(300);
    maru();
    delay(500);
    none();
    break;  
    }
    if(count2==1){d1();last=6;} 
    if(count2==2){d2();last=12;}  if(count2==3){d3();last=18;} 
    if(count2==4){d4();last=24;} if(count2==5){d5();last=60;} 
    if(count2==6){d6();last=90;} if(count2==7){d7();last=120;}
    if(count2==8){d8();last=150;} if(count2==9){d9();last=186;} 
    }
    if(count==1){d1();}
    while(1){//孵化サイクル選択
    if(digitalRead(5)==LOW){
    delay(300);
    count+=1;
    if(count==9){
      count=1;
    }
    }
    if(digitalRead(6)==LOW){//決定
    delay(300);
    maru();
    delay(500);
    none();
    break;  
    }
    if(count==1){d1();hosu=18000UL;} if(count==2){d2();hosu=35000UL;}//孵化サイクル1280,2560 
    if(count==3){d3();hosu=55000UL;} if(count==4){d4();hosu=65000UL;} //孵化サイクル3840,5120
    if(count==5){d5();hosu=86000UL;} if(count==6){d6();hosu=97000UL;} //孵化サイクル6400,7680
    if(count==7){d7();hosu=116000UL;} if(count==8){d8();hosu=129000UL;} //孵化サイクル10240
    }
    light=1;
  }
  
  for(int tama=0;tama<5;tama++){//チャリ乗りとポケモンにカーソル   
  SwitchControlLibrary().PressButtonX();
  delay(100);
  SwitchControlLibrary().ReleaseButtonX();
  delay(1000);
  SwitchControlLibrary().PressButtonPlus();
  delay(100);
  SwitchControlLibrary().ReleaseButtonPlus();
  delay(3000);
  //地図画面
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1500);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(3100);
  //育て屋前

  SwitchControlLibrary().PressButtonPlus();//自転車なし
  delay(100);
  SwitchControlLibrary().ReleaseButtonPlus();
  delay(1000);
  
  back();
  delay(1000);
  center(); 
  delay(100);
  left();
  delay(200);
  center();
  delay(100);
  
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1500);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1500);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();//卵もらう
  delay(4000);
  SwitchControlLibrary().PressButtonA();//卵もらう待ちが長い
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(2500);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(2000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(2000);
  
  //マップ開き
  SwitchControlLibrary().PressButtonX();
  delay(100);
  SwitchControlLibrary().ReleaseButtonX();
  delay(1000);
  SwitchControlLibrary().PressButtonPlus();
  delay(100);
  SwitchControlLibrary().ReleaseButtonPlus();
  delay(3000);
  
  //地図画面
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(3100);
  
  SwitchControlLibrary().PressButtonPlus();//自転車装備
  delay(100);
  SwitchControlLibrary().ReleaseButtonPlus();
  delay(1000);
  
  //孵化作業開始
  right();
  delay(2300);
  center();
  delay(100);
  left();
  right2();
  delay(hosu);
  center();
  delay(100);
  center2();
  delay(100);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();//産まれ待機時間約17秒
  delay(20000);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(4000);//戻るまで約4秒 
  if(count==1 or count==2 ){
  left();
  right2();
  delay(20000UL);
  center();
  delay(100);
  center2();
  delay(100);
  }
}
  //預ける
  SwitchControlLibrary().PressButtonX();
  delay(100);
  SwitchControlLibrary().ReleaseButtonX();
  delay(500);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(2500);
  SwitchControlLibrary().PressButtonR();
  delay(100);
  SwitchControlLibrary().ReleaseButtonR();
  delay(2500);

  //ボックス画面
  SwitchControlLibrary().MoveHat(6); // left
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(400);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(400);
  SwitchControlLibrary().PressButtonY();
  delay(100);
  SwitchControlLibrary().ReleaseButtonY();
  delay(400);
  SwitchControlLibrary().PressButtonY();
  delay(100);
  SwitchControlLibrary().ReleaseButtonY();
  delay(400);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(400);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(400);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(400);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(400);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(400);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(400);
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(400);
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(400);
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(400);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(400);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(400);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(400);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(400);
  
  egg=egg+1;
 
  if(fmod(egg,6)==0){
  SwitchControlLibrary().PressButtonR();
  delay(100);
  SwitchControlLibrary().ReleaseButtonR();
  delay(1000);  
  }
  
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(2000);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(2000);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(3000); 
  
  while(egg==last){//eggが6で1ボックス ホームボタン長押しでスリープ　
  SwitchControlLibrary().PressButtonHome();
  delay(2000);
  SwitchControlLibrary().ReleaseButtonHome();
  delay(500);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(500);
  while(1){
    egg+=1;
    egg=0;
  }
  }
}
while(dcount==7){//ボックス逃し
  while(light==0){
    last=1;
    count2=1;
    for(int i=0;i<8;i++){
    none();
    delay(100);
    d7();
    delay(100);
    none();
    delay(100);
    }
    while(1){
    if(count2==1){d1();}
    if(digitalRead(5)==LOW){
    delay(300);
    count2+=1;
    if(count2==10){
      count2=1;
    }
    }
    if(digitalRead(6)==LOW){//決定
    delay(300);
    maru();
    delay(500);
    none();
    break;  
    }
    if(count2==1){d1();last=1;}
    if(count2==2){d2();last=2;}if(count2==3){d3();last=3;}
    if(count2==4){d4();last=4;}if(count2==5){d5();last=10;}
    if(count2==6){d6();last=15;}if(count2==7){d7();last=20;}
    if(count2==8){d8();last=25;}if(count2==9){d9();last=31;}
    }
    light=1;
  }
for(int i=0;i<12;i++){
  
  while(count==last){
  maru();
  delay(500);
  none();
  delay(500);  
  }
  
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(250);
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(250);
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(250);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(600);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1500);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(400);

  if(i<5){ 
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(250);
  }
  
  if(i>5 and i!=11){
  SwitchControlLibrary().MoveHat(6); // left
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(250);
  }
  
  if(i==5 or i==11){
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(250);
  down=down+1;
  Serial.println(down);
  }
  
  if(down==5){
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(250);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(250); 
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(250);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(250); 
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(250); 
  down=0;
  count+=1;
  break;
}
}
  
}

while(dcount==8){//羽、IDくじ
  while(light==0){
    count=1;
    for(int i=0;i<8;i++){
    none();
    delay(100);
    d8();
    delay(100);
    none();
    delay(100);
    }
    if(count==1){d1();}
    while(1){
    if(digitalRead(5)==LOW){
    delay(300);
    count+=1;
    if(count==3){
      count=1;
    }
    }
    if(digitalRead(6)==LOW){//決定
    delay(300);
    maru();
    delay(500);
    none();
    break;  
    }
    if(count==1){d1();}
    if(count==2){d2();}  
    light=1;
    } 
  }
  while(count==1){
  SwitchControlLibrary().MoveLeftStick(254,134);
  delay(3050);
  SwitchControlLibrary().MoveLeftStick(128,128);
  delay(500);
  PressA(); //Aを3回押す

// 2つ目
  SwitchControlLibrary().MoveLeftStick(255,80);
  delay(1900);
  SwitchControlLibrary().MoveLeftStick(128,128);
  delay(500);
  PressA();

// 3つ目
  SwitchControlLibrary().MoveLeftStick(254,155);
  delay(1550);
  SwitchControlLibrary().MoveLeftStick(128,128);
  delay(500);
  PressA();

// 4つ目
  SwitchControlLibrary().MoveLeftStick(255,167);
  delay(1330);
  SwitchControlLibrary().MoveLeftStick(128,128);
  delay(500);
  PressA();

// 5つ目
  SwitchControlLibrary().MoveLeftStick(255,35);
  delay(820);
  SwitchControlLibrary().MoveLeftStick(128,128);
  delay(500);
  PressA();

// 6つ目
  SwitchControlLibrary().MoveLeftStick(255,152);
  delay(2651);
  SwitchControlLibrary().MoveLeftStick(128,128);
  delay(500);
  PressA();

// 7つ目
  SwitchControlLibrary().MoveLeftStick(255,60);
  delay(1792);
  SwitchControlLibrary().MoveLeftStick(128,128);
  delay(500);
  PressA();

// 8つ目
  SwitchControlLibrary().MoveLeftStick(255,205);
  delay(1900);
  SwitchControlLibrary().MoveLeftStick(128,128);
  delay(500);
  PressA();

// 9つ目
  SwitchControlLibrary().MoveLeftStick(255,80);
  delay(1885);
  SwitchControlLibrary().MoveLeftStick(128,128);
  delay(500);
  PressA();

// 10つ目
  SwitchControlLibrary().MoveLeftStick(255,205);
  delay(975);
  SwitchControlLibrary().MoveLeftStick(128,128);
  delay(500);
  PressA();
  delay(300);

//時間変更
  SwitchControlLibrary().PressButtonHome();
  delay(100);
  SwitchControlLibrary().ReleaseButtonHome();
  delay(400);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(75);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(75);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(75);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(75);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(75);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(850);
  // 設定画面
  SwitchControlLibrary().MoveHat(4); // down
  delay(1300);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().MoveHat(4); // down
  delay(50);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(260);
  // 時間設定
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(300);
  // 時間の変更　進める
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(110);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(50);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(50);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(50);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(125);

  SwitchControlLibrary().PressButtonHome();
  delay(100);
  SwitchControlLibrary().ReleaseButtonHome();
  delay(750);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);

  SwitchControlLibrary().PressButtonX();
  delay(100);
  SwitchControlLibrary().ReleaseButtonX();
  delay(500);
  
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(2500);

  SwitchControlLibrary().MoveLeftStick(255,0);
  delay(50);
  SwitchControlLibrary().MoveLeftStick(128,128);
  delay(300);

  SwitchControlLibrary().PressButtonA();
  delay(200);
  SwitchControlLibrary().ReleaseButtonA();
  delay(300);
  SwitchControlLibrary().PressButtonA();
  delay(200);
  SwitchControlLibrary().ReleaseButtonA();
  delay(3500);
}

while(count==2){
 SwitchControlLibrary().PressButtonHome();
  delay(100);
  SwitchControlLibrary().ReleaseButtonHome();
  delay(400);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1200);
  // 設定画面
  SwitchControlLibrary().MoveHat(4); // down
  delay(1500);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(500);
  // 時間設定
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(70);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(500);
  // 時間の変更
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().MoveHat(2); // right
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(50);
  SwitchControlLibrary().MoveHat(0); // up
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(100);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(50);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(50);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(50);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(200);
  
  day=day+1;
  
  SwitchControlLibrary().PressButtonHome();
  delay(100);
  SwitchControlLibrary().ReleaseButtonHome();
  delay(500);
  
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(800);

  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(400);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(400);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(400);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(400);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(400);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(400);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(400);
  
  if(day!=31){
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(600);
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(600);
  SwitchControlLibrary().MoveHat(4); // down
  delay(100);
  SwitchControlLibrary().MoveHat(8); // center
  delay(600);
  SwitchControlLibrary().PressButtonA();//1
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(800);
  SwitchControlLibrary().PressButtonB();//2
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(600);
  SwitchControlLibrary().PressButtonB();//3
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(600);
  SwitchControlLibrary().PressButtonB();//4
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(600);
  SwitchControlLibrary().PressButtonA();//5レポート
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1400);
  SwitchControlLibrary().PressButtonB();//6
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(500);
  SwitchControlLibrary().PressButtonB();//7
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(1100);
  SwitchControlLibrary().PressButtonB();//8
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(500);
  SwitchControlLibrary().PressButtonB();//9
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(500);
  SwitchControlLibrary().PressButtonB();//10
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(500);
  SwitchControlLibrary().PressButtonB();//11
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(2600);
  
  SwitchControlLibrary().PressButtonB();//12
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(500);
  SwitchControlLibrary().PressButtonB();//13
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(500);
  SwitchControlLibrary().PressButtonB();//14
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(500);
  SwitchControlLibrary().PressButtonB();//15
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(500);
  SwitchControlLibrary().PressButtonB();//16
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(500);//o

  SwitchControlLibrary().PressButtonB();//17
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(1500);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(400);
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(400);
}
 if(day==31){
    day=0;
  }
} 
}

while(dcount==9){
   while(light==0){
    count=1;
    for(int i=0;i<8;i++){
    none();
    delay(100);
    d9();
    delay(100);
    none();
    delay(100);
    }
    if(count==1){d1();}
    while(1){
    if(digitalRead(5)==LOW){
    delay(300);
    count+=1;
    if(count==3){
      count=1;
    }
    }
    if(digitalRead(6)==LOW){//決定
    delay(300);
    maru();
    delay(500);
    none();
    break;  
    }
    if(count==1){d1();}
    if(count==2){d2();}  
    }
    light=1;
  }
  
while(count==1){//穴掘り
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(100);   
}

while(count==2){//トーナメント
  toname(); 
  for(int i=0;i<10;i++){
  SwitchControlLibrary().PressButtonA();
  delay(100);
  SwitchControlLibrary().ReleaseButtonA();
  delay(1000);  
  }
  SwitchControlLibrary().PressButtonB();
  delay(100);
  SwitchControlLibrary().ReleaseButtonB();
  delay(1000); 
}
}
}
