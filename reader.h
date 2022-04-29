#ifndef READER_H
#define READER_H

// Funções
//
void leitor_area(void *args)
{

    for (;;)
    {
      bool base = get_flagpass();
       if (get_flagpass())
       {
           Serial.print("Area de interrupt");
                // Beggin interrupt
                //xTaskNotifyGive(InteruptHandler);
                //Serial.println("interupção ativada");
       }
        else if (digitalRead(READER_B))
        {


            uint8_t base = random(3);
            set_value(base);

            digitalWrite(L_READER, HIGH);
            vTaskDelay(random(1000) / portTICK_PERIOD_MS); // Criar delay de leitura

            digitalWrite(L_READER, LOW);
            set_flagpass(true);
            Serial.print("Leitura Para a área : ");
            Serial.println(base);
        }
        
        xTaskNotifyGive(MotorHandler);
        
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Criar delay de leitura
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
          
      //print_data(false,"Leitura Terminada");                                         // ulTaskNotifyTake( pdTRUE, portMAX_DELAY );
    }
}

#endif

// Ajustar o sistema para ler apenas uma vez o qrcode
