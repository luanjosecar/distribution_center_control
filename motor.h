#ifndef MOTOR_H
#define MOTOR_H

// Bibliotecas
#include <Servo.h>

// Variáveis de ambiente
#define T_READER 1000 / portTICK_PERIOD_MS // delay

uint8_t p;
boolean flag;

Servo chooseGate;
// Hardware

// Funções

void change_position(void *args)
{
  chooseGate.attach(MOTOR);
  for(;;){

    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    p=get_value();
    //set_value(2);
   // Serial.print("p:");
   // Serial.println(p);


   uint8_t base = random(3);
            set_value(base);
    
    if (p == 0)
    {
        chooseGate.write(0);
        set_flagpass(true);
        //pass=true;
    }
    else if (p == 1)
    {
        chooseGate.write(90);
        set_flagpass(true);
        //pass=true;
    }
    else
    {
        chooseGate.write(180);
    }

    //Serial.print("pass: ");
   // Serial.print(pass);
   vTaskDelay(1000 / portTICK_PERIOD_MS);
   xTaskNotifyGive(LazerHandler);
    //delay(2000);
  }
}

#endif

// Ajustar Delays para que o tempo de execução seja coerente
// Ajustar também a deadline dele
