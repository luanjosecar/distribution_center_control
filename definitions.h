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
#define L_EME 13   // Led da emergência
#define MOTOR 11   // Motor
#define RELEASE 12 // Libera o sistema

#define T_READER 1000 / portTICK_PERIOD_MS // delay

SemaphoreHandle_t MutexContext = xSemaphoreCreateMutex();

TaskHandle_t ReaderHandler = NULL;   // Tarefa do leitor de QrCode
TaskHandle_t MotorHandler = NULL;    // Tarefa para giro do motor
TaskHandle_t MoveHandler = NULL;     // Tarefa de troca das caixas
TaskHandle_t InteruptHandler = NULL; // Tarefa de Interrupção

TaskHandle_t LazerSensor1 = NULL; // Task do sensor lase 1
TaskHandle_t LazerSensor2 = NULL; // Task do sensor lase 2
TaskHandle_t LazerSensor3 = NULL; // Task do sensor lase 3

static volatile uint8_t placer; // Número que define o destino da caixa (A,B ou C)
static volatile bool pass;      // Objeto alcançou o final do ciclo
static volatile bool eme_state; // Estado da emergência
static volatile uint8_t mesa_1; // Contador do número de objetos da mesa 1
static volatile uint8_t mesa_2; // Contador do número de objetos da mesa 2

// Define o valor lido no objeto a ser transportado
void stat_variables()
{
    mesa_1 = 0;
    mesa_2 = 0;
    placer = -1;
    pass = false;
    eme_state = false;
}

// Aidiciona um objeto a mesa 1
void add_mesa1()
{
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    mesa_1++;
    xSemaphoreGive(MutexContext);
}
// Pega o número de objetos na mesa 1
uint8_t get_mesa1()
{
    uint8_t base;
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    base = mesa_1;
    xSemaphoreGive(MutexContext);
    return base;
}

// Reseta os valores da mesa de transporte 1
void reset_mesa_1()
{
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    mesa_1 = 0;
    xSemaphoreGive(MutexContext);
}

// Adiciona um objeto a mesa 2
void add_mesa2()
{
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    mesa_2++;
    xSemaphoreGive(MutexContext);
}

// Pega o número de objetos da mesa 2
uint8_t get_mesa2()
{
    uint8_t base;
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    base = mesa_2;
    xSemaphoreGive(MutexContext);
    return base;
}
// Reseta o valor da mesa 2
void reset_mesa_2()
{
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    mesa_2 = 0;
    xSemaphoreGive(MutexContext);
}

// Define o valor do caminho no qual o objeto ira seguir
void set_value(uint8_t pointer)
{
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    placer = pointer;
    xSemaphoreGive(MutexContext);
}

// Pega o valor do caminho do objeto
uint8_t get_value()
{
    uint8_t base;
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    base = placer;
    xSemaphoreGive(MutexContext);
    return base;
}

// Define se o sistema já foi observado
void set_flagpass(bool flag)
{
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    pass = flag;
    xSemaphoreGive(MutexContext);
}

// Retorna o valor para o sistema já retornado
bool get_flagpass()
{
    boolean flag;
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    flag = pass;
    xSemaphoreGive(MutexContext);
    return flag;
}

// Define o estado da emergÊncia
void set_eme_status(bool state)
{

    xSemaphoreTake(MutexContext, portMAX_DELAY);
    eme_state = state;
    xSemaphoreGive(MutexContext);
}

// Busca o estado da emergencia
bool get_eme_status()
{
    boolean flag;
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    flag = eme_state;
    xSemaphoreGive(MutexContext);
    return flag;
}
