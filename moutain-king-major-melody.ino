#define B3 247
#define BS3 254.5
#define C4 262
#define CS4 277
#define D4 294
#define DS4 311
#define E4 330
#define ES4 339.5
#define F4 349
#define FS4 370
#define G4 392
#define GS4 415
#define A4 440
#define AS4 466
#define B4 494
#define REST 0 

int tempo = 120;
int buzzerpin = 3;

// Melody array is note, duration, note, ...
// durations number of beats

float Melody[] = {

B3, 0.5, CS4, 0.5, DS4, 0.5, E4, 0.5, FS4, 0.5, DS4, 0.5, FS4, 1, ES4, 0.5, CS4, 0.5, ES4, 1, E4, 0.5, BS3, 0.5, E4, 1, B3, 0.5, CS4, 0.5, DS4, 0.5, E4, 0.5, FS4, 0.5, DS4, 0.5, FS4, 0.5, B4, 0.5,AS4, 0.5, FS4, 0.5, DS4, 0.5, FS4, 0.5, AS4, 2,B3, 0.5, CS4, 0.5, DS4, 0.5, E4, 0.5, FS4, 0.5, DS4, 0.5, FS4, 1,ES4, 0.5, CS4, 0.5, ES4, 1, E4, 0.5, BS3, 0.5, E4, 1, B3, 0.5, CS4, 0.5, DS4, 0.5, E4, 0.5, FS4, 0.5, DS4, 0.5, FS4, 0.5, B4, 0.5,AS4, 0.5, FS4, 0.5, DS4, 0.5, FS4, 0.5, AS4, 2,
  
};
// sizeof() gives bytes where an int is comprised of 2 bytes
// so number of notes will be sizeof()/4 since we divide by bytes and account for half the array being durations
int notes = sizeof(Melody) / 4;

float beat = (60000)/tempo;
float duration = 0;


void setup() {
  // single loop of the array
  Serial.begin(9600);
  int note=0;
  while(note< notes *2){
    int pitch = Melody[note];
    duration = beat * Melody[note +1];
    tone(buzzerpin, pitch, duration);
    delay(duration);
    noTone(buzzerpin);
    note = note + 2;
    Serial.println(Melody[note]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
