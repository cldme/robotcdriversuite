#pragma config(Sensor, S1,     HTSMUX,              sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * hitechnic-protoboard.h provides an API for the HiTechnic Protoboard.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 25 November 2009
 * version 0.2
 */

#include "hitechnic-sensormux.h"
#include "hitechnic-protoboard.h"

// The sensor is connected to the first port
// of the SMUX which is connected to the NXT port S1.
// To access that sensor, we must use msensor_S1_1.  If the sensor
// were connected to 3rd port of the SMUX connected to the NXT port S4,
// we would use msensor_S4_3

// Give the sensor a nice easy to use name
const tMUXSensor HTPB = msensor_S1_1;

task main() {
  byte inputs = 0;

  displayCenteredTextLine(0, "HiTechnic");
  displayCenteredBigTextLine(1, "Proto");
  displayCenteredTextLine(3, "Test 1");
  displayCenteredTextLine(5, "Connect SMUX to");
  displayCenteredTextLine(6, "S1 and HTPB to");
  displayCenteredTextLine(7, "SMUX Port 1");
  sleep(2000);

  playSound(soundBeepBeep);
  while(bSoundActive) sleep(1);

  eraseDisplay();

  while(true) {
    // Fetch the state of the digital IO pins.  When not explicitly
    // configured as input or output, they will default to input.
    inputs = HTPBreadIO(HTPB, 0x3F);
    displayTextLine(4, "D: 0x%x", (short)inputs);
    sleep(10);
  }
}
