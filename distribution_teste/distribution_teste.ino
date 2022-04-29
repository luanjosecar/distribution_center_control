/// Modelo de entrada randômico para entrar no sistema

void setup()
{

    randomSeed(analogRead(A0));
    Serial.begin(9600);
}

void loop()
{
    int base = random(3);
    Serial.print("Caixa entrando no sistema");
    digitalWrite(9, HIGH);
    delay(1);
    digitalWrite(9, LOW);
    delay(4000);
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
    delay(3000);
    while (true)
    {
        if (digitalRead(10))
        {
            break;
        }
        delay(10);
    }
}