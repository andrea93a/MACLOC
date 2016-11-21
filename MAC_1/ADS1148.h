/*
* SPI Settings
*/
#define SPI_SPEED_KHZ 20                                                         // SPI clock speed in kHz

/*
* Input output ports definition
*/
#define START D1                                                                 // Start pin of the ADS1148
#define RESET D0                                                                 // Reset pin of the ADS1148
#define DRDY D2                                                                  // Data Ready pin of the ADS1148 (active low)
#define SCLK A3                                                                  // Serial clock of SPI interface
#define DIN A5                                                                   // MOSI: Master Output Slave Input (ADS1148 data input)
#define DOUT A4                                                                  // MISO: Master Input Slave Output (ADS1148 data output)
#define CS A2                                                                    // Chip selection (active low)
#define LED D7                                                                   // Led Blue

 //Time Constants
 #define t_cssc 1                                                                // t_cssc: Delay time, first SCLK rising edge after CS falling edge (min. = 10 ns)
 #define t_2sclk 1                                                               // t_2sclk: twice the period of SCLK (2 us). (min. = 488 ns)

 //Commands
 #define RESET_CMD 0x06                                                          // Reset Command: Resets the Device
 #define SDATC 0x16                                                              // SDATC: Stop Data Continuos mode
 #define SYNC 0x04                                                               // Synchronization Command: Resets the ADC digital filter and starts a new conversion
 #define RDATA 0x12                                                              // RDATA (0001 001x): loads the most recent conversion result into the output register (I considered x=0)
 #define NOP 0xFF                                                                // NOP: no operation command
 #define SYSOCAL 0x60                                                            // SYSOCAL: system offset calibration of the selected input (connect to zero input when calibrating)
 #define SYSGCAL 0x61                                                            // SYSGCAL: system gain calibration of the selected input (connect to full scale input when calibrating)
 #define SELFOCAL 0x62                                                           // SELFOCAL: self system ofset calibration (device internally shorts the input e performs calibration)
 #define WREG 0x40                                                               // WREG (0x4r): write register from register number r (second byte 0xn where n = number of reg to write -1) following bytes are data to write
 #define RREG 0x20                                                               // RREG (0x2r): read register from register number r (second byte 0xn where n = number of reg to read -1) following bytes are data read

 //Configuration Registers Addresses
 #define MUX0_CONT 0x00                                                          // MUX Control Register 0 (address 00h)
 #define VBIAS 0x01                                                              // Bias Voltage Register (address 01h)
 #define MUX1_CONT 0x02                                                          // MUX Control Register 1 (address 02h)
 #define SYS_CONT 0x03                                                           // System Control Register (address 03h)
 #define OFC0 0x04                                                               // Offset control rtegister
 #define OFC1 0x05                                                               // Offset control rtegister
 #define OFC2 0x06                                                               // Offset control rtegister
 #define FSC0 0x07                                                               // Ful scale ontrol rtegister
 #define FSC1 0x08                                                               // Ful scale ontrol rtegister
 #define FSC2 0x09                                                               // Ful scale ontrol rtegister

 // Multiplexer Control Register 0 (00h)
 #define BCS_OFF 0b00000000                                                      // Burn-out Detect Current Source Off (default)
 #define BCS_05 0b00000001                                                       // Burn-out current source on, 0.5 ?A
 #define BCS_2 0b00000010                                                        // Burn-out current source on, 2.0 ?A
 #define BCS_10 0b00000011                                                       // Burn-out current source on, 10.0 ?A
 #define MUXP_AIN0 0b00000000                                                    // Selects Ain 0 as Positive input channel(default)
 #define MUXP_AIN1 0b00001000                                                    // Selects Ain 1 as Positive input channel
 #define MUXP_AIN2 0b00010000                                                    // Selects Ain 2 as Positive input channel
 #define MUXP_AIN3 0b00011000                                                    // Selects Ain 3 as Positive input channel
 #define MUXP_AIN4 0b00100000                                                    // Selects Ain 4 as Positive input channel
 #define MUXP_AIN5 0b00101000                                                    // Selects Ain 5 as Positive input channel
 #define MUXP_AIN6 0b00110000                                                    // Selects Ain 6 as Positive input channel
 #define MUXN_AIN7 0b00111000                                                    // Selects Ain 7 as Positive input channel
 #define MUXN_AIN0 0b00000000                                                    // Selects Ain 0 as Negative input channel
 #define MUXN_AIN1 0b00000001                                                    // Selects Ain 1 as Negative input channel(default)
 #define MUXN_AIN2 0b00000010                                                    // Selects Ain 2 as Negative input channel
 #define MUXN_AIN3 0b00000011                                                    // Selects Ain 3 as Negative input channel
 #define MUXN_AIN4 0b00000100                                                    // Selects Ain 4 as Negative input channel
 #define MUXN_AIN5 0b00000101                                                    // Selects Ain 5 as Negative input channel
 #define MUXN_AIN6 0b00000110                                                    // Selects Ain 6 as Negative input channel
 #define MUXN_AIN7 0b00000111                                                    // Selects Ain 7 as Negative input channel

  // Bias Voltage Register (01h)
  #define VBIAS_ALL_OFF 0b00000000                                                // None Bias voltage is enabled (default)
  #define VBIAS0_ON 0b00000001                                                    // A bias voltage of mid-supply (AVDD + AVSS) / 2 is applied to Ain 0
  #define VBIAS1_ON 0b00000010                                                    // A bias voltage of mid-supply (AVDD + AVSS) / 2 is applied to Ain 1
  #define VBIAS2_ON 0b00000100                                                    // A bias voltage of mid-supply (AVDD + AVSS) / 2 is applied to Ain 2
  #define VBIAS3_ON 0b00001000                                                    // A bias voltage of mid-supply (AVDD + AVSS) / 2 is applied to Ain 3
  #define VBIAS4_ON 0b00010000                                                    // A bias voltage of mid-supply (AVDD + AVSS) / 2 is applied to Ain 4
  #define VBIAS5_ON 0b00100000                                                    // A bias voltage of mid-supply (AVDD + AVSS) / 2 is applied to Ain 5
  #define VBIAS6_ON 0b01000000                                                    // A bias voltage of mid-supply (AVDD + AVSS) / 2 is applied to Ain 6
  #define VBIAS7_ON 0b10000000                                                    // A bias voltage of mid-supply (AVDD + AVSS) / 2 is applied to Ain 7

 // Multiplexer Control Register 1 (02h)
 #define INT_VREF_OFF 0b00000000                                                 // Internal reference voltage is always OFF
 #define INT_VREF_ON 0b00100000                                                  // Internal reference voltage is always ON
 #define VREF_IN_PN0 0b00000000                                                  // Reference Voltage Input: REFP0 and REFN0 reference inputs selected (default)
 #define VREF_IN_PN1 0b00001000                                                  // Reference Voltage Input: REFP1 and REFN1 reference inputs selected
 #define VREF_IN_INT 0b00010000                                                  // Reference Voltage Input: Internal Reference selected
 #define VREF_IN_INT_PN0 0b00011000                                              // Reference Voltage Input: Internal Reference selected and connected to REF0
 #define MUXCAL_NORMAL 0b00000000                                                // Normal operation (default)
 #define MUXCAL_OFFSET 0b00000001                                                // Offset calibration. The analog inputs are disconnected and AINP and AINN are internally connected to mid-supply (AVDD + AVSS)/2
 #define MUXCAL_GAIN 0b00000010                                                  // Gain calibration. The analog inputs are connected to the voltage reference
 #define MUXCAL_TEMP 0b00000011                                                  // Temperature measurement. The inputs are connected to a diode circuit that produces a voltage proportional to the ambient temperature
 #define MUXCAL_RF1MON 0b00000100                                                // REF1 monitor. The analog inputs are disconnected and Ain_P and Ain_N are internally connected to (V(REFP1) ? V(REFN1))/4
 #define MUXCAL_RF0MON 0b00000101                                                // REF0 monitor. The analog inputs are disconnected and Ain_P and Ain_N are internally connected to (V(REFP0) ? V(REFN0))/4
 #define MUXCAL_AVMON 0b00000110                                                 // Analog supply monitor. The analog inputs are disconnected and Ain_P and Ain_N are internally connected to (AVDD ? AVSS)/4
 #define MUXCAL_DVMON 0b00000111                                                 // Digital supply monitor. The analog inputs are disconnected and Ain_P and Ain_N are internally connected to (DVDD ? DGND)/4

 // System Control Register (03h)
 #define PGA_1 0b00000000                                                        // Programmable Gain Amplifier, Gain Setting = 1 (default)
 #define PGA_2 0b00010000                                                        // Programmable Gain Amplifier, Gain Setting = 2
 #define PGA_4 0b00100000                                                        // Programmable Gain Amplifier, Gain Setting = 4
 #define PGA_8 0b00110000                                                        // Programmable Gain Amplifier, Gain Setting = 8
 #define PGA_16 0b01000000                                                       // Programmable Gain Amplifier, Gain Setting = 16
 #define PGA_32 0b01010000                                                       // Programmable Gain Amplifier, Gain Setting = 32
 #define PGA_64 0b01100000                                                       // Programmable Gain Amplifier, Gain Setting = 64
 #define PGA_128 0b01110000                                                      // Programmable Gain Amplifier, Gain Setting = 18
 #define SPS_5 0b00000000                                                        // Sampling Rate setting = 5 SPS (default)
 #define SPS_10 0b00000001                                                       // Sampling Rate setting = 10 SPS
 #define SPS_20 0b00000010                                                       // Sampling Rate setting = 20 SPS
 #define SPS_40 0b00000011                                                       // Sampling Rate setting = 40 SPS
 #define SPS_80 0b00000100                                                       // Sampling Rate setting = 80 SPS
 #define SPS_160 0b00000101                                                      // Sampling Rate setting = 160 SPS
 #define SPS_320 0b00000110                                                      // Sampling Rate setting = 320 SPS
 #define SPS_640 0b00000111                                                      // Sampling Rate setting = 640 SPS
 #define SPS_1000 0b00001000                                                     // Sampling Rate setting = 1000 SPS
 #define SPS_2000 0b00001001                                                     // Sampling Rate setting = 2000 SPS

 // Miscellaneous
 #define OUT 0
 #define IN 1

void init_SPI();
void init_ADC();
int16_t read_ADC_once();
void send_command_ADC(uint8_t cmd);
void setup_ADC();
void tranfer_SPI_ADC(void* tx,void* rx, uint8_t l);
