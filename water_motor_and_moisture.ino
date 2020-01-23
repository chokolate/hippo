/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
int vals[4];
void insert(int new_val){
int i;
for (i=0; i<3; i++){
  vals[i] = vals[i+1];
  
}
vals[3]=new_val;

}

int avg(){
int i;
int sum=0;
for (i=0; i<4; i++){
  sum = vals[i]+sum;  
}
return sum/4;
}

int is_error(int lastValue){
  if ((lastValue + 1) > avg()){
    return 1;
  }
  return 0;
}


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  insert(500);
  insert(500);
  insert(500);
  insert(500);
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}


// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  
  int sensorValue = analogRead(A0);
  

  // print out the value you read:
  Serial.println(sensorValue);
  delay(100); 
  
if (sensorValue <500){

analogWrite(7, 0);
delay(3000);
}
else{  
analogWrite (7, 255);
delay(500);
int err = is_error(sensorValue);
digitalWrite(LED_BUILTIN, err);
}

insert(sensorValue);




 /*  while (sensorValue = [1022:300]){
    if (sensorVal
    fadeAmount--;
    }
    else {
      fadeAmount++;
    }
    //digitalWrite(LED_BUILTIN, HIGH);
    analogWrite(LED_BUILTIN, brightness);  
  }
  else{
    analogWrite(LED_BUILTIN, brightness);
  }
  */
  
  // delay in between reads for stability
}
