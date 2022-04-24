
#include "reader.h"
#include "motor.h"
#include "Arduino_FreeRTOS.h"
#include "semphr.h"

int plus = 0;
void setup()
{
    Serial.begin(115200);
    leitor_setup();
}

void loop()
{
}
