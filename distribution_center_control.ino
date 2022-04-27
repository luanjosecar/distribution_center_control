#include "definitions.h"
#include "reader.h"
#include "lazer_sensor.h"
//#include "distribution.h"
//#include "motor.h"



void setup()
{
    randomSeed(analogRead(A0)); // Criar números realmente aleatórios

    Serial.begin(115200);
   
    if (MutexContext == NULL)
    {
        Serial.print("Erro ao criar o Mutex \n");
    }

    xTaskCreate(
        leitor_area, // Função
        "Leitor",    // Nome
        150,         // Empilhamento -- Armazenamento de memória
        NULL,        // Parametros
        1,           // Prioridade
        &ReaderHandler);

    xTaskCreate(
        validate_lazer, // Função
        "Leitor 1",   // Nome
        200,          // Empilhamento -- Armazenamento de memória
        NULL,            // Parametros
        1,            // Prioridade
        &LazerHandler);
/*
    xTaskCreate(
        check_sistem, // Função
        "Leitor 2",   // Nome
        100,          // Empilhamento -- Armazenamento de memória
        0,            // Parametros
        2,            // Prioridade
        NULL);
    
    xTaskCreate(
        check_table, // Função
        "Mesa 1",   // Nome
        100,          // Empilhamento -- Armazenamento de memória
        0,            // Parametros
        1,            // Prioridade
        NULL);
*/
    vTaskStartScheduler();
}

void loop()
{
}
