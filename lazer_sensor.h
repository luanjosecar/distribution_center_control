
TaskHandle_t LazerSensor1 = NULL;
TaskHandle_t LazerSensor2 = NULL;

void check_sistem_s1(void *args)
{
    uint8_t param;

        
        param = get_value();
        Serial.println(param);
        if (digitalRead(PASS_1B))
        {
          if(param == 0){
              add_control(param);
              Serial.print("Adicionado Area ");
              Serial.println(L1_PASS);
              digitalWrite(L1_PASS, HIGH);
              vTaskDelay(random(1000) / portTICK_PERIOD_MS);
              digitalWrite(L1_PASS, LOW);
            }
          
           
        }
        
        vTaskDelete(LazerSensor1);
   
}

void check_sistem_s2(void *args)
{
    uint8_t param;
        
        param = get_value();
        if (digitalRead(PASS_2B))
        {
          if(param == 1){
              add_control(param);
              Serial.print("Adicionado Area ");
              Serial.println(L2_PASS);
              digitalWrite(L2_PASS, HIGH);
              vTaskDelay(random(1000) / portTICK_PERIOD_MS);
              digitalWrite(L2_PASS, LOW);
            }
        }

        vTaskDelete(LazerSensor2);
   
}


void validate_lazer(void *args){
for(;;){

  ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    xTaskCreate(
        check_sistem_s1, // Função
        "Leitor 1",   // Nome
        80,          // Empilhamento -- Armazenamento de memória
        NULL,            // Parametros
        1,            // Prioridade
        &LazerSensor1);
    xTaskCreate(
        check_sistem_s2, // Função
        "Leitor 1",   // Nome
        80,          // Empilhamento -- Armazenamento de memória
        NULL,            // Parametros
        1,            // Prioridade
        &LazerSensor2);
        vTaskDelay(random(1000) / portTICK_PERIOD_MS);
        xTaskNotifyGive(ReaderHandler);
}
}

/*
void check_sistem_s2(void *args)
{
    uint8_t param;
    for (;;)
    {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        param = get_value();
        if (digitalRead(PASS_1B))
        {
          if(param == 0){
              add_control(param);
              Serial.print("Adicionado Area ");
              Serial.println(L1_PASS);
              digitalWrite(L1_PASS, HIGH);
              vTaskDelay(random(1000) / portTICK_PERIOD_MS);
              digitalWrite(L1_PASS, LOW);
            }
          
          
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        xTaskNotifyGive(ReaderHandler);
    }
   
}*/
