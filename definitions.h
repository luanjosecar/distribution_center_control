#include "Arduino_FreeRTOS.h"
#include "semphr.h"
#include "queue.h"
#include "task.h"
#define SIZE 3

// Leituras do sistema

#define READER_B 3
#define PASS_1B 4
#define PASS_2B 5
#define EME_B 2

#define L_READER 8
#define L1_PASS 7
#define L2_PASS 6
#define L_EME 8



SemaphoreHandle_t MutexContext = xSemaphoreCreateMutex();
QueueHandle_t read_base = xQueueCreate(1, sizeof(uint8_t));

TaskHandle_t ReaderHandler = NULL;
TaskHandle_t MotorHandler = NULL;
TaskHandle_t LazerHandler  = NULL;
TaskHandle_t MoveHandler = NULL ;


static volatile uint8_t placer;

static uint8_t controler[SIZE];

void set_value(uint8_t pointer)
{
   xSemaphoreTake(MutexContext, portMAX_DELAY);
    
    placer = pointer;
     xSemaphoreGive(MutexContext);
}

uint8_t get_value()
{
    uint8_t base;
   xSemaphoreTake(MutexContext, portMAX_DELAY);
    base =  placer;
     xSemaphoreGive(MutexContext);
     return base;
}

void add_control(uint8_t place)
{
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    controler[place]++;
    xSemaphoreGive(MutexContext);
}

uint8_t get_control(uint8_t place)
{
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    return controler[place];
    xSemaphoreGive(MutexContext);
}

void reset_control(uint8_t place)
{
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    controler[place] = 0;
    xSemaphoreGive(MutexContext);
}
