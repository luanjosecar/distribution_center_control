
// Task para criacao do interrupt
void start_interrupt(void *args)
{

    for (;;)
    {
        if(digitalRead(EME_B)){
          set_eme_status(true);
        }
        if (get_eme_status())
        {
            xSemaphoreTake(MutexContext, portMAX_DELAY);
            for (;;)
            {
                // Cria sinal com o led
                Serial.println("Interupt ativo"); 
                digitalWrite(L_EME, HIGH);
                vTaskDelay(500 / portTICK_PERIOD_MS);

                digitalWrite(L_EME, LOW);
                vTaskDelay(500 / portTICK_PERIOD_MS);
                
                
                if (digitalRead(EME_B))
                {
                    Serial.println("Exiting interrupt");

                    vTaskDelay(1000 / portTICK_PERIOD_MS);
                    break;
                }
            }
            // REtorna ao ponto da mesa de entrada
            Serial.print("Starting motor for reset");
            xSemaphoreGive(MutexContext);
            set_eme_status(false);
            xTaskNotifyGive(MotorHandler);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            xTaskNotifyGive(MoveHandler);
        }
    }
}
