#ifndef MOTOR_H
#define MOTOR_H

// Bibliotecas
#include <Servo.h>

// Variáveis de ambiente
#define T_READER 1000 / portTICK_PERIOD_MS // delay

uint8_t p;

Servo chooseGate;
// Hardware

// Funções

void change_position(void *args)
{
  chooseGate.attach(MOTOR);
  long time_var = 0;
  long timer;
  uint8_t base = 0;
  for (;;)
  {

    // ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    p = get_value();
    // set_value(2);
    // Serial.print("p:");
    // Serial.println(p);
    if (p != base)
    {
      vTaskDelay(random(500, 1000) / portTICK_PERIOD_MS);
    }
    if (p == 0)
    {
      chooseGate.write(0);
      // pass=true;
    }
    else if (p == 1)
    {
      chooseGate.write(90);
      // pass=true;
    }
    else
    {
      chooseGate.write(180);
    }

    vTaskDelay(1000 / portTICK_PERIOD_MS);
    timer = millis();
    Serial.println(timer - time_var);
    time_var += timer - time_var;
    // xTaskNotifyGive(LazerHandler);
    // delay(2000);
  }
}

#endif

// Ajustar Delays para que o tempo de execução seja coerente
// Ajustar também a deadline dele
