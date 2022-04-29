

void start_interrupt(void *args)
{

    for (;;)
    {
       if (digitalRead(EME_B) or get_eme_status())
            {
              xSemaphoreTake(MutexContext, portMAX_DELAY);
              for(;;){
                
                digitalWrite(L_EME, HIGH);
                vTaskDelay(500 / portTICK_PERIOD_MS); // Criar delay de leitura

                digitalWrite(L_EME, LOW);
                vTaskDelay(500 / portTICK_PERIOD_MS); // Criar delay de leitura  
                Serial.println("Interupt ativo");
                if (digitalRead(EME_B)){
                  Serial.println("Exiting interrupt");
                  
                  vTaskDelay(1000 / portTICK_PERIOD_MS);
                  break;
                  }
                
                }
                Serial.print("Starting motor for reset");
                xSemaphoreGive(MutexContext);
                set_eme_status(false);
                xTaskNotifyGive(MotorHandler);
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                xTaskNotifyGive(MoveHandler);
            }
        }
    
}
