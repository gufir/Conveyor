#define STEP_PIN 25
#define DIR_PIN 26
#define ENA_PIN 27
#define relay1 2
#define relay2 4

void setup() {
  Serial.begin(115200);
  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);  
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENA_PIN, OUTPUT);  
}

void loop() {
  
  forward(6400,ENA_PIN, DIR_PIN, STEP_PIN);// Maju 5000 step
  reverse(6400,ENA_PIN, DIR_PIN, STEP_PIN); // Maju 5000 step
}

void forward(int steps, int ENA, int DIR, int STEP){
  int i;
  digitalWrite(ENA,LOW);//ENABLE IS ACTIVE LOW
  digitalWrite(DIR,HIGH);//SET DIRECTION FWD 
  for(i=0;i<steps;i++){
    digitalWrite(STEP,HIGH);
    delay(STEPTIME);
    digitalWrite(STEP,LOW);
    delay(STEPTIME);
  }
  digitalWrite(ENA,HIGH);//DISABLE STEPPER
}

void reverse(int steps, int ENA, int DIR, int STEP){
  int i;
  digitalWrite(ENA,LOW);
  digitalWrite(DIR,LOW); //SET DIR REVERSE
  for(i=0;i<steps;i++){
    digitalWrite(STEP,HIGH);
    delay(STEPTIME);
    digitalWrite(STEP,LOW);
    delay(STEPTIME);
  }
  digitalWrite(ENA,HIGH);//DISABLE STEPPER
}

void lamp1_on(){
  Serial.write(relay1, HIGH);
  delay(1000);
}

void lamp1_off() {
  Serial.write(relay1, LOW);
  delay(1000);  
}

void lamp2_on() {
  Serial.write(relay2, HIGH);
  delay(1000);
}

void lamp2_off() {
  Serial.write(relay2, LOW);
  delay(1000); 
}
