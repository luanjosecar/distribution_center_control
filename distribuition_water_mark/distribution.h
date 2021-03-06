//#include "definitions.h"

TaskHandle_t TableSensor1 = NULL;
TaskHandle_t TableSensor2 = NULL;

static volatile long timer;
static volatile long time_var;
void verify_container_1(void *args)
{
    time_var = millis();
    uint8_t base = get_mesa1();
    uint8_t basea = random(4);
    Serial.print(base);
    Serial.print(" ");
    // Serial.println(" Leu mesa 1");
    if (basea == 3)
    {
        // Serial.println("Moving Table 1");
        reset_mesa_1();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    timer = millis();
    Serial.println(timer - time_var);

    vTaskDelay(500 / portTICK_PERIOD_MS);
    vTaskDelete(TableSensor1);
}

void verify_container_2(void *args)
{

    uint8_t base = get_mesa2();
    // Serial.print(base);
    // Serial.println(" Leu mesa 2");
    base = random(4);
    if (base == 3)
    {
        // Serial.println("Moving Table 2");
        reset_mesa_2();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    vTaskDelete(TableSensor2);
}

void check_table(void *args)
{
    for (;;)
    {

        // ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

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

        // Serial.println("Passaram os carregamentos");

        set_value(-1);

        // Serial.println("Liberando leitor");

        digitalWrite(RELEASE, HIGH);
        vTaskDelay(10 / portTICK_PERIOD_MS);
        digitalWrite(RELEASE, LOW);

        xTaskNotifyGive(ReaderHandler);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

// Verificar se o sistema está correto
// Checar a forma de escrever a task para adapta-la ao correto
