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
        150,         // Empilhamento -- Armazenamento de memória
        NULL,        // Parametros
        1,           // Prioridade
        &ReaderHandler);
   xTaskCreate(
        change_position, // Função
        "Motor",      // Nome
        100,             // Empilhamento -- Armazenamento de memória
        NULL,            // Parametros
        1,               // Prioridade
        &MotorHandler);


      xTaskCreate(
        check_sistem_s1, // Função
        "Passagem 1",     // Nome
        80,            // Empilhamento -- Armazenamento de memória
        NULL,           // Parametros
        1,              // Prioridade
        &LazerSensor1);
      xTaskCreate(
        check_sistem_s2, // Função
        "Passagem 2",     // Nome
        80,            // Empilhamento -- Armazenamento de memória
        NULL,           // Parametros
        1,              // Prioridade
        &LazerSensor2);
       xTaskCreate(
        check_sistem_s3, // Função
        "Passagem 1",     // Nome
        80,            // Empilhamento -- Armazenamento de memória
        NULL,           // Parametros
        1,              // Prioridade
        &LazerSensor3);
        
      xTaskCreate(
        check_table, // Função
        "Mesas",    // Nome
        100,         // Empilhamento -- Armazenamento de memória
        NULL,           // Parametros
        1,           // Prioridade
        &MoveHandler);

        
       xTaskCreate(
        start_interrupt, // Função
        "Mesa 1",        // Nome
        100,             // Empilhamento -- Armazenamento de memória
        NULL,               // Parametros
        1,               // Prioridade
        &InteruptHandler);

/*   

        


 


 

    // Ajustar a task da mesa para que ela rode sem problemas



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
