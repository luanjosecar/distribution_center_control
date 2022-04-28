// Biblioteca para variaveis de ambientes e funções globais
#include "Arduino_FreeRTOS.h"
#include "semphr.h"
#include "queue.h"
#include "task.h"

#define SIZE 2
#define MAX_VALUE 3

// Leituras do sistema

#define READER_B 3 // Sensor de leitura do local
#define PASS_1B 4  // Sensor lazer 1
#define PASS_2B 5  // Sensor lazer 2
#define PASS_3B 9  // Sensor lazer 3
#define EME_B 2    // Butão de emergência

#define L_READER 8 // Led do leitor de local
#define L1_PASS 7  // Led do lazer 1
#define L2_PASS 6  // Led do lazer 2
#define L3_PASS 10 // Led do Lazer 3
#define L_EME 8    // Led da emergência
#define MOTOR 11   // Motor

SemaphoreHandle_t MutexContext = xSemaphoreCreateMutex();
QueueHandle_t read_base = xQueueCreate(1, sizeof(uint8_t));

TaskHandle_t ReaderHandler = NULL;
TaskHandle_t MotorHandler = NULL;
TaskHandle_t LazerHandler = NULL;
TaskHandle_t MoveHandler = NULL;
TaskHandle_t InteruptHandler = NULL;

static volatile uint8_t placer;
static volatile bool is_processing;
static volatile uint8_t controler[SIZE];
static volatile boolean pass;

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
    base = placer;
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

void set_flagpass(boolean flag)
{
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    pass = flag;
    xSemaphoreGive(MutexContext);
}

boolean get_flagpass()
{
    boolean flag;
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    flag = pass;
    xSemaphoreGive(MutexContext);
    return pass;
}
// Adicionar funções para a variavel de controle booleana
// PASS