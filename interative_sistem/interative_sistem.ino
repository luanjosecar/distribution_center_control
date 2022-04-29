
void print_menu()
{
    Serial.println("------------------------------------");
    Serial.println("Escolha uma das opções para o sistema");
    Serial.println("    1          2         3      9(interupt) ");
    Serial.println("------------------------------------");
}

void setup()
{

    Serial.begin(9600);
}

void loop()
{
    delay(3000);
    Serial.println("Caixa entrando no sistema");
    digitalWrite(9, HIGH);
    delay(1);
    digitalWrite(9, LOW);
    delay(4000);
    print_menu();
    int base;
    while (Serial.available()== 0)
    {}
        base = Serial.parseInt();
    if (base == 0)
    {
        Serial.print("Ativando sensor da área 1");
        digitalWrite(8, HIGH);
        delay(10);
        digitalWrite(8, LOW);
    }
    if (base == 1)
    {
        Serial.print("Ativando sensor da área 2");
        digitalWrite(7, HIGH);
        delay(10);
        digitalWrite(7, LOW);
    }
    if (base == 2)
    {
        Serial.print("Ativando sensor da área 3");
        digitalWrite(6, HIGH);
        delay(10);
        digitalWrite(6, LOW);
    }
    if(base == 9) {
      Serial.println("Iniciando interupção");
      
      while(base != 0){
        Serial.println("Digite 0 para finaliza-la");
          while (Serial.available()== 0)
          {}
          
          base = Serial.parseInt();
      }
      Serial.println("Reiniciando o Sistema");
    }
    delay(3000);
    while (true)
    {
        if (digitalRead(10))
        {
            break;
        }
        delay(10);
    }

    Serial.println("------------------------------------");
}
