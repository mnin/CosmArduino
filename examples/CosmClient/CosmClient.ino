#include <SPI.h>
#include <Ethernet.h>
#include <Cosm.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x10, 0x8f};
char apiKey[] = "MAbhqpGHqP6kovzK2kS1asGewxCZHE_wt3Xyc7Ym8Cc";
long feedId = 46455;
char datastreamId[] = "0";

CosmClient client = CosmClient(apiKey);

void setup()
{
  client.connectWithMac(mac);
}

void loop()
{
  // read the sensor
  double sensorReading = 1.75;//analogRead(A0);

  // send to the Cosm client
  client.updateFeed(feedId, datastreamId, sensorReading);
}
