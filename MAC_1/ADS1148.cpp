#include "application.h"

#include "ADS1148.h"

/*
* Function to initialize the SPI comunication
*/
void init_SPI()
{
  SPI.begin(SPI_MODE_MASTER);
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockSpeed(SPI_SPEED_KHZ, KHZ);
  SPI.setDataMode(SPI_MODE1);
}

void init_ADC()
{
  //initialize input output ports
  pinMode(LED, OUTPUT);
  pinMode(DRDY, INPUT);
  pinMode(CS, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(START, OUTPUT);
  digitalWrite(LED, HIGH);
  digitalWrite(CS, HIGH);                                                       // Active low in trasmission
  digitalWrite(START, HIGH);                                                    // Held high for data conversion
  digitalWrite(RESET, HIGH);                                                    // Active low (need to be HIGH)
  delay(2000);
}

int16_t read_ADC_once()
{
  uint8_t tx_buffer[2] = {NOP};
  uint8_t rx_buffer[2]={0};
  uint8_t length = 2;
  tranfer_SPI_ADC(&tx_buffer,&rx_buffer,length);
  uint16_t rx = rx_buffer[0];
  rx = rx << 8;
  rx = rx + rx_buffer[1];
  int16_t res;
  if ((rx & (1<<15)) != 0)
  {
    res = -(~rx + 1);
  }
  else
  {
    res = rx;
  }
  return res;
}

void send_command_ADC(uint8_t cmd)
{
  int length = 1;
  tranfer_SPI_ADC(&cmd,NULL,length);
  if(cmd == RESET_CMD)
  {
    delay(0.6);
  }
}

void setup_ADC()
{

  int length = 6;
  uint8_t tx_buffer[6] = {WREG|MUX0_CONT,0x03,MUXP_AIN2|MUXN_AIN3,VBIAS_ALL_OFF,INT_VREF_OFF|VREF_IN_PN0|MUXCAL_NORMAL,PGA_64|SPS_20};
  tranfer_SPI_ADC(&tx_buffer,NULL,length);

}

void tranfer_SPI_ADC(void* tx,void* rx, uint8_t l)
{
  unsigned long time_in = millis();
  while(digitalRead(DRDY) && (millis()-time_in)<1000)
  {}
  digitalWrite(CS, LOW);
  delayMicroseconds(t_cssc);
  SPI.transfer(tx, rx, l, NULL);
  digitalWrite(CS, HIGH);
}
