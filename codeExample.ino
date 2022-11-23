//a few libraries are needed
#include <Adafruit_LSM6DSOX.h> //this is exclusively for the sensor I use, you'll probably have to find your own if you decide to go for a different one
#include <BLEMIDI_Transport.h> //BLEmidi is the tech used to transmit midi data over bluetooth. You need this
#include <hardware/BLEMIDI_ESP32.h> //this is BLE for esp32s. You can use an other MCU, but you have to check wether it's capable of bluetooth networking

Adafruit_LSM6DSOX sox;

BLEMIDI_CREATE_INSTANCE("Zahir",MIDI); //this creates a midi instance : it's the thing that'll appear in your bluetooth devices list

void setup() {

  Serial.begin(115200); //in case you want to monitor certain values

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
  MIDI.begin(); //there you go!
}

void loop() {
  //  /* Get a new normalized sensor event */
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  sox.getEvent(&accel, &gyro, &temp);

  //the map function is very handy, it 'maps' a range of values onto another. You can finetune this
  int CC_X_a = map(accel.acceleration.x, -10, 13, 0, 100); 
  int CC_X_g = map(gyro.gyro.x, -8, 8, 0, 100);
  
  MIDI.sendControlChange(20, CC_X_a, 1); //send MIDI message of the mapped value of acceleration on x axis
  MIDI.sendControlChange(21, CC_X_g, 1); //send MIDI message of the mapped value of x rotation speed



  delay(30); //this eases the MCU's workload. It granularises the changes of value, but many DAWs have a value smoothing option.
}
