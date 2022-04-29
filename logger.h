

void print_data(void *args) //Log para acompanhamento da execução das tarefas
{
  for(;;){
        Serial.write(27);
        Serial.print(F("\n\t\t---------------------\n\n"));
        Serial.print(F("\n\t\t -- Leitura :"));
        Serial.print(get_value());
        Serial.print(F("\n\t\t -- Base1 :"));
        Serial.print(get_control(0));
        Serial.print(F(" -- Base2 :"));
        Serial.print(get_control(1));
        Serial.print(F("\n\t\t -- Fase :"));
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Criar delay de leitura
  }     
}
