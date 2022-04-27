#ifndef READER_H
#define READER_H

// Bibliotecas

// Variáveis de ambiente

// Hardware

// Funções

void leitor_area(void *args)
{

    for (;;)
    {
        if (digitalRead(READER_B))
        {
            uint8_t base = random(3);
            set_value(base);

            digitalWrite(L_READER, HIGH);

            // Serial.println(response); // Print para validar tempo de impressão

            vTaskDelay(random(1000) / portTICK_PERIOD_MS); // Criar delay de leitura

            digitalWrite(L_READER, LOW);
        }
        xTaskNotifyGive(LazerHandler);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Criar delay de leitura
                                               // ulTaskNotifyTake( pdTRUE, portMAX_DELAY );
    }
}

#endif
