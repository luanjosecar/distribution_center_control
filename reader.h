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
            // Pausa o sistema para caso já tenha realizado uma leitura
            ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
            set_flagpass(false);
            set_value(-1);
            Serial.println("Retornando a leitura");
            continue;
        }
        else if (digitalRead(READER_B))
        {
            // Logica de leitura do sistema
            uint8_t base = random(3);
            set_value(base);

            digitalWrite(L_READER, HIGH);
            vTaskDelay(random(1000) / portTICK_PERIOD_MS); // Criar delay de leitura

            digitalWrite(L_READER, LOW);
            set_flagpass(true);
            Serial.print("Leitura Para a árae : ");
            Serial.println(base);
            xTaskNotifyGive(MotorHandler);
        }
        else
        {
            Serial.println("Aguardando leitura");
        }

        vTaskDelay(1000 / portTICK_PERIOD_MS); // Criar delay de leitura
    }
}

#endif

// Ajustar o sistema para ler apenas uma vez o qrcode
