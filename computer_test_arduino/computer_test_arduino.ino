//test the register
//version 1 - output numbers to the bus
//will start executing immediately - later activate start button

//register control pins
#define CLOCK_PIN  21    //clock pin
#define ENABLE_PIN  22   //enable pin - write putput to bus
#define LOAD_PIN  23     //load pin - load contents from bus

//application control pins
#define RUN_TEST 24     //run the selected test (need to figure out test select method)



//bus pins
const char BUS_PIN[] = {12,13,14,15};


void setup() {
  // put your setup code here, to run once:
  pinMode(CLOCK_PIN,OUTPUT);
  pinMode(ENABLE_PIN,OUTPUT);
  pinMode(LOAD_PIN,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(RUN_TEST), onRunTest, FALLING);

  Serial.begin(57600);

}

void loop() {
  // put your main code here, to run repeatedly:
}

void pulse_clock() {
  //a single pulse to the clock
  digitalWrite(CLOCK_PIN,HIGH);
  delay(1000);
  digitalWrite(CLOCK_PIN,LOW);
}

void write_word(int v) {
  //output a word to the bus and pulse the clock
  for (int n=0; n < sizeof(BUS_PIN) ; n += 1){
    digitalWrite(BUS_PIN[n],v && n);  
  }

  pulse_clock();
}

int read_word() {
  //load the current values of the bus into the BUS[] array
  int val = 0;    //the value that will be returned
  for (int n=0; n < 2^sizeof(BUS_PIN); n++) {
      int bit = digitalRead(BUS_PIN[n] ? 1 : 0);
      
  }
  return val;
}

void onRunTest (){
  //execute the test.

  //this version outputs numbers to the bus
  for (int v=0; v < 2^sizeof(BUS_PIN); v++) {
      write_word(v);      //output the bits in the word to the bus. 
      //There's a 1 second delay for the clock pulse, so no further delay needed
    
  }

  
}
