#include "definitions.h"
#include "interrupt_case.h"
#include "reader.h"
#include "lazer_sensor.h"
#include "distribution.h"
#include "motor.h"

void setup()
{
  randomSeed(analogRead(A0)); // Criar números realmente aleatórios

  // seta variavel de testes
  int teste = 0;
  Serial.begin(115200);
  stat_variables();
  if (MutexContext == NULL)
  {
    Serial.print("Erro ao criar o Mutex \n");
  }

  switch (teste)
  {
  case 0:
    xTaskCreate(
        leitor_area, // Função
        "Leitor",    // Nome
        200,         // Empilhamento -- Armazenamento de memória
        NULL,        // Parametros
        1,           // Prioridade
        &ReaderHandler);
    break;

  case 1:
    xTaskCreate(
        change_position, // Função
        "Motor",         // Nome
        100,             // Empilhamento -- Armazenamento de memória
        NULL,            // Parametros
        1,               // Prioridade
        &MotorHandler);

    break;
  case 2:
    xTaskCreate(
        check_sistem_s1, // Função
        "Passagem 1",    // Nome
        80,              // Empilhamento -- Armazenamento de memória
        NULL,            // Parametros
        1,               // Prioridade
        &LazerSensor1);

    xTaskCreate(
        check_sistem_s2, // Função
        "Passagem 2",    // Nome
        80,              // Empilhamento -- Armazenamento de memória
        NULL,            // Parametros
        1,               // Prioridade
        &LazerSensor2);
    xTaskCreate(
        check_sistem_s3, // Função
        "Passagem 1",    // Nome
        80,              // Empilhamento -- Armazenamento de memória
        NULL,            // Parametros
        1,               // Prioridade
        &LazerSensor3);
    break;

  case 3:
    xTaskCreate(
        check_table, // Função
        "Mesas",     // Nome
        100,         // Empilhamento -- Armazenamento de memória
        NULL,        // Parametros
        1,           // Prioridade
        &MoveHandler);
    break;

  case 4:
    xTaskCreate(
        start_interrupt, // Função
        "Mesa 1",        // Nome
        100,             // Empilhamento -- Armazenamento de memória
        NULL,            // Parametros
        1,               // Prioridade
        &InteruptHandler);

    break;
  default:
    break;
  }

  vTaskStartScheduler();
}

void loop()
{
}
