#include "Arduino_FreeRTOS.h"
#include "semphr.h"
SemaphoreHandle_t MutexContext;

#define SIZE 3
static uint8_t placer;

static uint8_t controler[SIZE];

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

void set_control(uint8_t place)
{
    controler[place]++;
}

uint8_t get_control(uint8_t place)
{
    return controler[place];
}

void reset_control(uint8_t place)
{
    controler[place] = 0;
}