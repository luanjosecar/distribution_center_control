#include "definitions.h"
#include "reader.h"
#include "motor.h"

TaskHandle_t ReaderHandler;

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
        100,         // Empilhamento
        NULL,        // Parametros
        1,           // Prioridade
        &ReaderHandler);

    vTaskStartScheduler();
}

void loop()
{
}
