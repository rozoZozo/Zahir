#include <Adafruit_LSM6DSOX.h>
#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32.h>

Adafruit_LSM6DSOX sox;

BLEMIDI_CREATE_INSTANCE("Zahir",MIDI);

void setup() {

  Serial.begin(115200);

  if (!sox.begin_I2C()) {
    // if (!sox.begin_SPI(LSM_CS)) {
    // if (!sox.begin_SPI(LSM_CS, LSM_SCK, LSM_MISO, LSM_MOSI)) {
    // Serial.println("Failed to find LSM6DSOX chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("LSM6DSOX Found!");
  delay(500);
  MIDI.begin();
}

void loop() {
  //  /* Get a new normalized sensor event */
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  sox.getEvent(&accel, &gyro, &temp);

  //int notesX_a = map(accel.acceleration.x, -13, 13, 60, 75);
  int CC_X_a = map(accel.acceleration.x, -10, 13, 0, 100);
  int CC_X_g = map(gyro.gyro.x, -8, 8, 0, 100);
  /*
  MIDI.sendNoteOn(notesX_a, 100, 10); // (note, velocity, midi channel)
  delay(100);
  MIDI.sendNoteOff(notesX_a, 0, 10);
  delay(100);
  */
 //delay(50);  
  MIDI.sendControlChange(20, CC_X_a, 1);
  MIDI.sendControlChange(21, CC_X_g, 1);



  delay(30);
}