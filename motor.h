#ifndef MOTOR_H
#define MOTOR_H

// Bibliotecas
#include <Servo.h>

// Variáveis de ambiente
#define T_READER 1000 / portTICK_PERIOD_MS // delay

uint8_t p; //Valor que define a posição para qual o motor deve girar

Servo chooseGate; //Declaração do servo motor
// Hardware

// Funções

void change_position(void *args) // Muda a posição do servo de acordo com a 
{
  chooseGate.attach(9);
  for(;;){

    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    p=get_value(); // Tem acesso ao valor da porta a qual o objeto deve ser destinado
    
    if (p == 0)
    {
        chooseGate.write(0);
        //pass=true;
    }
    else if (p == 1)
    {
        chooseGate.write(90);
        //pass=true;
    }
    else
    {
        chooseGate.write(180);
    }

    //Serial.print("pass: ");
   // Serial.print(pass);
   Serial.println("Passagem Motor");
   
   
   xTaskNotifyGive(LazerHandler);
   vTaskDelay(1000 / portTICK_PERIOD_MS);
    //delay(2000);
  }
}

#endif

// Ajustar Delays para que o tempo de execução seja coerente
// Ajustar também a deadline dele
