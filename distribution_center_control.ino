#include "definitions.h"
#include "logger.h"
#include "interrupt_case.h"
#include "reader.h"
#include "lazer_sensor.h"
#include "distribution.h"
#include "motor.h"

void setup()
{
    randomSeed(analogRead(A0)); // Criar números realmente aleatórios

    Serial.begin(115200);
    stat_variables();
    if (MutexContext == NULL)
    {
        Serial.print("Erro ao criar o Mutex \n");
    }

    xTaskCreate(
        leitor_area, // Função
        "Leitor",    // Nome
        100,         // Empilhamento -- Armazenamento de memória
        NULL,        // Parametros
        1,           // Prioridade
        &ReaderHandler);

   xTaskCreate(
        change_position, // Função
        "Leitor 2",      // Nome
        100,             // Empilhamento -- Armazenamento de memória
        NULL,            // Parametros
        1,               // Prioridade
        &MotorHandler);
        
      xTaskCreate(
        validate_lazer, // Função
        "Leitor 1",     // Nome
        100,            // Empilhamento -- Armazenamento de memória
        NULL,           // Parametros
        1,              // Prioridade
        &LazerHandler);
/*    


 

    // Ajustar a task da mesa para que ela rode sem problemas

    xTaskCreate(
        check_table, // Função
        "Mesa 1",    // Nome
        100,         // Empilhamento -- Armazenamento de memória
        0,           // Parametros
        1,           // Prioridade
        &MoveHandler);

    xTaskCreate(
        start_interrupt, // Função
        "Mesa 1",        // Nome
        100,             // Empilhamento -- Armazenamento de memória
        0,               // Parametros
        2,               // Prioridade
        &InteruptHandler);
*/
/*
    xTaskCreate(
        print_data, // Função
        "Logger",    // Nome
        80,         // Empilhamento -- Armazenamento de memória
        NULL,        // Parametros
        0,           // Prioridade
        NULL);
*/
    // Criar interupção
    vTaskStartScheduler();
}

void loop()
{
}
