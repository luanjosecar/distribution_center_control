#ifndef READER_H
#define READER_H

// Bibliotecas

// Variáveis de ambiente
#define T_READER 1000 / portTICK_PERIOD_MS

// Hardware

#define READER_PIN 2
#define WARN_LED 9

// Funções

void leitor_area(void *args)
{

    int base = random(4);
    Serial.print(base);
}

void blink_led(int response)
{
    int mock_reader = random(1000 / portTICK_PERIOD_MS)
}

void leitor_setup()
{

    xTaskCreate(
        leitor_area, // Função
        NULL,        // Nome
        100,         // Empilhamento
        NULL,        // Parametros
        1,           // Prioridade
        NULL);
}

#endif
