#define POT_PIN A5 //Analog pin connected to the potentiometer
#define PWM_PIN 5 //Digital PWM enabled pin connected to the base of the power transistor
#define NUMBER_OF_READINGS 100 //Number of readings we are averaging to filter noise in the potentiometer readings

void setup() {
  //Initiate Serial Interface
  Serial.begin(9600);
  Serial.println("Led strip driver.");
  
  //Initiate pin mode
  pinMode(POT_PIN,INPUT);
  pinMode(PWM_PIN,OUTPUT);
}

void loop() {
  int potValue = 0;
  unsigned long total = 0;
  
  //Sum NUMBER_OF_READINGS samples with 1ms delay between readings
  for(int i=0; i<NUMBER_OF_READINGS;i++){
    //The potentiometer sample is divided by 4 because the analog sample 
    //goes up to 1023 and the PWM output goes up to 255
    potValue = analogRead(POT_PIN)/4; 
    total += potValue;
    delay(1);
  }

  //Take ou the average value
  unsigned int average = total/NUMBER_OF_READINGS;
  Serial.println(average);

  //Write average to PWM pin
  analogWrite(PWM_PIN,average);
}

