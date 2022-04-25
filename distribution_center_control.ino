#include "definitions.h"
#include "reader.h"
#include "motor.h"

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

    vTaskStartScheduler();
}

void loop()
{
}
