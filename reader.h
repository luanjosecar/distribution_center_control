#ifndef READER_H
#define READER_H

// Bibliotecas
#include "definitions.h"
// Variáveis de ambiente
#define T_READER 1000 / portTICK_PERIOD_MS

// Hardware

#define READER_PIN 7
#define WARN_LED 9

// Funções

void blink_led(int response)
{
    int mock_reader = random(100)*100;

    digitalWrite(READER_PIN, HIGH);
    Serial.println(mock_reader); // Print para validar tempo de impressão
    vTaskDelay(mock_reader / portTICK_PERIOD_MS); // Criar delay de leitura
    digitalWrite(READER_PIN, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay para validação apenas
}

void leitor_area(void *args)
{
    xSemaphoreTake(MutexContext, portMAX_DELAY);
    int base = random(4);
    set_value(base);
    blink_led(base);

    xSemaphoreGive(MutexContext);
}


#endif
