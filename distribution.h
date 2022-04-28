//#include "definitions.h"

#define MAX_VALUE 3

TaskHandle_t TableSensor1 = NULL;
TaskHandle_t TableSensor2 = NULL;

void verify_container_1(void *args)
{
    if (get_control(0) == MAX_VALUE)
    {
        Serial.println("Moving Table 2");
        reset_control(0);
    }

    vTaskDelete(TableSensor1);
}

void verify_container_2(void *args)
{
    if (get_control(1) == MAX_VALUE)
    {
        Serial.println("Moving Table 2");
        reset_control(1);
    }

    vTaskDelete(TableSensor2);
}

void check_table(void *args)
{
    for (;;)
    {

        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        xTaskCreate(
            verify_container_1, // Função
            "Mesa 1",           // Nome
            80,                 // Empilhamento -- Armazenamento de memória
            NULL,               // Parametros
            1,                  // Prioridade
            &TableSensor1);
        xTaskCreate(
            verify_container_2, // Função
            "Mesa 2",           // Nome
            80,                 // Empilhamento -- Armazenamento de memória
            NULL,               // Parametros
            1,                  // Prioridade
            &TableSensor2);

        set_flagpass(false);
        xTaskNotifyGive(ReaderHandler);
        // Valida sensor
        vTaskDelay(random(1000) / portTICK_PERIOD_MS);
    }
}

// Verificar se o sistema está correto
// Checar a forma de escrever a task para adapta-la ao correto