

void start_interrupt(void *args)
{

    for (;;)
    {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        xSemaphoreTake(MutexContext, portMAX_DELAY);
        for (;;)
        {
            if (digitalRead(EME_B))
            {
                xSemaphoreGive(MutexContext);
                set_value(2);
                xTaskNotifyGive(MotorHandler);
                break;
            }
            else
            {
                digitalWrite(L_EME, HIGH);
                vTaskDelay(500 / portTICK_PERIOD_MS); // Criar delay de leitura

                digitalWrite(L_EME, LOW);
                vTaskDelay(500 / portTICK_PERIOD_MS); // Criar delay de leitura
            }
        }
    }
}
