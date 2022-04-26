//#include "definitions.h"

#define MAX_VALUE 3

void check_table(void *args)
{
    uint8_t params;
    params = (uint8_t *)args;

    if (get_control(params) == MAX_VALUE)
    {
        Serial.println("Moving Table");
        reset_control(params);
    }
}
