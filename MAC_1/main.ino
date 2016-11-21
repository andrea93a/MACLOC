/* MACLOC DAC
* Read value from wheastone bridge
*
*/

#include "ADS1148.h"

#define V_REF 3300
#define RES 120
#define BRIDGE_F 2
#define GAUGE_F 2
#define PGA 64                                                                  // set this value on ADS1148.cpp in function setup_ADC()

unsigned long time_in, tReset;
bool led=0;
float vExt = 3.3;

void setup()
{
WiFi.off();

Serial.begin(9600);
Serial.println("Starting......");

init_SPI();

init_ADC();

setup_ADC();                                                                     // View function definition for setup settings

pinMode(D3, INPUT);

}

void loop()
{
digitalWrite(D7, led);
led = !led;

/* Hardware zeroing
* Set offset to zero of the selected port when button is presser
*/

if(digitalRead(D3) == HIGH)
{
  send_command_ADC(SYSOCAL);
}

int16_t rx = read_ADC_once();

double dv = (float)rx/((1<<15) - 1)*V_REF/1000/PGA;

double dr_r = dv*4/vExt/BRIDGE_F;

double um = dr_r/GAUGE_F*1000000;

/*Serial.print("Data received: ");*/
Serial.println(um);

}
