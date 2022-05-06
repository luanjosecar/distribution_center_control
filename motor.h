#ifndef MOTOR_H
#define MOTOR_H

// Bibliotecas
#include <Servo.h>

uint8_t p;

Servo chooseGate;

void change_position(void *args)
{
  chooseGate.attach(MOTOR);
  for (;;)
  {

    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    p = get_value();

    if (p == 0)
    {
      chooseGate.write(0);
    }
    else if (p == 1)
    {
      chooseGate.write(90);
    }
    else
    {
      chooseGate.write(180);
    }

    Serial.println("Passagem Motor");
    Serial.println("Aguardando resposta dos sensores");
    Serial.print("Porta de leitura pelo motor : ");
    Serial.println(p);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

#endif
