#ifndef READER_H
#define READER_H

// Bibliotecas

// Variáveis de ambiente
#define T_READER 1000 / portTICK_PERIOD_MS

// Hardware

#define READER_PIN 2

// Funções

void leitor_area()
{

    int base = random(4);
    Serial.print(base);
    Serial.print('\n');
}

#endif
