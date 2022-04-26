#ifndef READER_H
#define READER_H

// Bibliotecas

// Variáveis de ambiente
#define T_READER 1000 / portTICK_PERIOD_MS

// Hardware

#define READER_PIN 7
#define WARN_LED 9

// Funções

void blink_led(uint8_t response)
{
    uint16_t mock_reader = random(100) * 100;

    digitalWrite(READER_PIN, HIGH);

    Serial.println(response); // Print para validar tempo de impressão

    vTaskDelay(mock_reader / portTICK_PERIOD_MS); // Criar delay de leitura

    digitalWrite(READER_PIN, LOW);
    
    vTaskDelay(mock_reader / portTICK_PERIOD_MS); // Criar delay de leitura

}

void leitor_area(void *args)
{
    //xSemaphoreTake(MutexContext, portMAX_DELAY);
    randomSeed(analogRead(A0));
    uint8_t base = random(3);
    set_value(base);
    blink_led(base);

    //xSemaphoreGive(MutexContext);
}

#endif
