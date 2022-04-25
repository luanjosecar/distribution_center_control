#include "Arduino_FreeRTOS.h"
#include "semphr.h"

SemaphoreHandle_t MutexContext;

volatile uint8_t placer;

void start_table()
{
    placer = 0;
}

void set_value(uint8_t pointer)
{
    placer = pointer;
}

uint8_t get_valeu()
{
    return placer;
}