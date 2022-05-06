#define READER 9
#define L1 8
#define L2 7 
#define L3 6 
#define EME 5
#define ACTIVATE 10


int base;
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
    digitalWrite(READER, HIGH);
    delay(10);
    digitalWrite(READER, LOW);
    delay(4000);
    print_menu();
    
    base = -1;
    while (Serial.available()== 0)
    {}
    while (Serial.available()== 0)
    {
    base = Serial.parseInt();
    }
    if (base == 1)
    {
        Serial.println("Ativando sensor da área 0");
        digitalWrite(L1, HIGH);
        delay(10);
        digitalWrite(L1, LOW);
    }
    if (base == 2)
    {
        Serial.println("Ativando sensor da área 1");
        digitalWrite(L2, HIGH);
        delay(10);
        digitalWrite(L2, LOW);
    }
    if (base == 3)
    {
        Serial.print("Ativando sensor da área 2");
        digitalWrite(L3, HIGH);
        delay(10);
        digitalWrite(L3, LOW);
    }
    if(base == 9) {
      Serial.println("Iniciando interupção");
        digitalWrite(EME, HIGH);
        delay(200);
        digitalWrite(EME, LOW);
      while(base != 8){
        Serial.println("Digite 8 para finaliza-la");
          while (Serial.available()== 0)
          {}
          base = Serial.parseInt();
      }
      Serial.println("Reiniciando o Sistema");
      
    }
    
    while (true)
    {
        if (digitalRead(ACTIVATE))
        {
            break;
        }
        if(base == 8){
          break;
        }
        delay(10);
    }

    Serial.println("------------------------------------");
}
