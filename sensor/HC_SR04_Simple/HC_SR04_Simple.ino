#include <VirtualWire.h>
#include <Ultrasonic.h>

#define Size 2

#define pino_trigger 12
#define pino_echo 11

Ultrasonic ultrasonic(pino_trigger, pino_echo);

byte TX_buffer[Size];

void setup () {
  Serial.begin(9600);

  vw_set_tx_pin(2); 
  vw_setup(4000); 
}

void loop () {

  int cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  delay(1000);

  TX_buffer[0] = lowByte(cmMsec);
  TX_buffer[1] = highByte(cmMsec);

  vw_send(TX_buffer, Size);
  vw_wait_tx();

}