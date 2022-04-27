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


// Verificar se o sistema está correto
// Checar a forma de escrever a task para adapta-la ao correto