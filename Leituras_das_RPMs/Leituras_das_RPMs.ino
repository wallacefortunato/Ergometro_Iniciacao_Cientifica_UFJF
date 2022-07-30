// Ler em RPM e converter em RPM média
const int numleituras = 10;
int leituras[numleituras];
unsigned long media = 0;
int index = 0;
unsigned long total; 

volatile int rpmcont = 0;
unsigned long rpm = 0;
unsigned long lastmillis = 0;

void setup(){
 Serial.begin(9600); 
 attachInterrupt(0, rpm_fan, FALLING);
}

void loop(){
 
  
 if (millis() - lastmillis >= 1000){  
 
 detachInterrupt(0);   
 total = 0;  
 leituras [index] = rpmcont * 60;  
 
 for (int x=0; x<=9; x++){
   total = total + leituras[x];
 }
 
 media = total / numleituras;
 rpm = media;
 
 rpmcont = 0; //restart
 index++;
 if(index >= numleituras){
  index=0; 
 } 
 
 
if (millis() > 11000){ 

 Serial.print(" RPM = ");
 Serial.println(rpm);
}
 
 lastmillis = millis(); // Atualiza lastmillis
  attachInterrupt(0, rpm_fan, FALLING); 
  }
}


void rpm_fan(){ 
  rpmcount++;
}
