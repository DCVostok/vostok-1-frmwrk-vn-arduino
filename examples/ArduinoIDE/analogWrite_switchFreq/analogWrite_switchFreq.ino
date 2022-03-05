
void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  pinMode(3,OUTPUT);

  //freq variants 
  //E_ANALOG_WRITE_FREQ_54_Hz
  //E_ANALOG_WRITE_FREQ_508_Hz
  //E_ANALOG_WRITE_FREQ_1K_Hz
  //E_ANALOG_WRITE_FREQ_97K_Hz
  //E_ANALOG_WRITE_FREQ_49K_Hz
  //E_ANALOG_WRITE_FREQ_24K_Hz
  //E_ANALOG_WRITE_FREQ_12K_Hz
  //E_ANALOG_WRITE_FREQ_6K_Hz
  //E_ANALOG_WRITE_FREQ_3K_Hz
  //E_ANALOG_WRITE_FREQ_10K_Hz
  //E_ANALOG_WRITE_FREQ_8K_Hz
  //E_ANALOG_WRITE_FREQ_7K_Hz
  analogWriteFrequency(E_ANALOG_WRITE_FREQ_97K_Hz);
  
}
int16_t i  = 0 ;
int8_t vect = 5;
void loop() {
  analogWrite(3,i);
  analogWrite(5,i);
  analogWrite(6,i);
  analogWrite(9,i);
  analogWrite(10,i);
  analogWrite(11,i);
  delay(10);
  i += vect;
  Serial.println(i);
  if(i > 254 || i <= 0){
     vect *= -1;
  }
}
