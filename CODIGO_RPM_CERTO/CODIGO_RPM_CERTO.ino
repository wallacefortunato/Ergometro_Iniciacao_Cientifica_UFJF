#define PI 3.1415926535897932384626433832795

int hallsensor = 49;                // Hall sensor at pin 49
volatile byte counter;
unsigned int rpm;
unsigned long passedtime;
long now = millis();
long start = millis ();
double potency;
int temp ;
float bodymass, distance, ray, diameter;

void isr()
 {
   //Each rotation, this interrupt function is run twice, so take that into consideration for
   //calculating RPM
   //Update count
   
      counter++;
 }
void setup()
 {Serial.begin(9600);

   //Intiates Serial communications
   attachInterrupt(0, isr, RISING); //Interrupts are called on Rise of Input
   pinMode(hallsensor, INPUT); //Sets hallsensor as input

   now = 0;
   start = 0;
   potency = 0;
   temp = 0;
   bodymass = 0;
   // ray= x;
   // diameter = x;
   counter = 0;
   rpm = 0;
   passedtime = 0; //Initialise the values
 }
 void loop()
 {
   //Serial.print("Digite a massa corporal do atleta: ");
   bodymass = Serial.read();
   delay(1000);//Update RPM every second
   detachInterrupt(0); //Interrupts are disabled
   rpm = 60*1000/(millis() - passedtime)*counter;
   passedtime = millis();
   counter = 0;

   Serial.print("RPM=");
   Serial.println(rpm); //Print out result to monitor
   attachInterrupt(0, isr, RISING);   //Restart the interrupt processing

   distance= rpm*diameter*PI;

   potency = (bodymass*distance*distance*distance)/(temp*temp*temp);

   

   

  }
