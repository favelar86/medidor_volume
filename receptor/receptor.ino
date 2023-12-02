#include <VirtualWire.h>             
 
#define Size 2
byte RX_buffer[Size];

String sr;
 
void setup()
{
  Serial.begin(9600);
 
  vw_set_rx_pin(2); 
  vw_setup(4000); 
  vw_rx_start();    
}
 
void loop()
{
  uint8_t messageLength = Size;

  if (vw_get_message(RX_buffer, &messageLength))
  {

    int receivedDistance = word(RX_buffer[1], RX_buffer[0]);
    sr = receivedDistance;

    Serial.println(sr);
  }
 
}