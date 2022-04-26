#include "definitions.h"
#include "reader.h"
#include "lazer_sensor.h"
//#include "distribution.h"
//#include "motor.h"

TaskHandle_t ReaderHandler;
TaskHandle_t MotorHandler;
TaskHandle_t LazerHandler;
TaskHandle_t MoveHandler;

void setup()
{

    Serial.begin(115200);
    MutexContext = xSemaphoreCreateMutex();
    if (MutexContext == NULL)
    {
        Serial.print("Erro ao criar o Mutex \n");
    }

    xTaskCreate(
        leitor_area, // Função
        "Leitor",    // Nome
        100,         // Empilhamento -- Armazenamento de memória
        NULL,        // Parametros
        1,           // Prioridade
        &ReaderHandler);

    xTaskCreate(
        check_sistem, // Função
        "Leitor 1",   // Nome
        100,          // Empilhamento -- Armazenamento de memória
        1,            // Parametros
        2,            // Prioridade
        NULL);

    xTaskCreate(
        check_sistem, // Função
        "Leitor 2",   // Nome
        100,          // Empilhamento -- Armazenamento de memória
        0,            // Parametros
        2,            // Prioridade
        NULL);
    /*
    xTaskCreate(
        check_table, // Função
        "Mesa 1",   // Nome
        100,          // Empilhamento -- Armazenamento de memória
        0,            // Parametros
        1,            // Prioridade
        NULL);
*/
    vTaskStartScheduler();
}

void loop()
{
}
