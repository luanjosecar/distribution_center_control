

void print_data(boolean eme)
{
    if (!eme)
    {
        Serial.print(27, BYTE);
        Serial.print(F("\n\t\t---------------------\n\n"));
        Serial.print(F("\n\t\t -- Leitura :"));
        Serial.print(get_value());
        Serial.print(F("\n\t\t -- Base1 :"));
        Serial.print(get_control(0));
        Serial.print(F(" -- Base2 :"));
        Serial.print(get_control(1));
        Serial.print(F("\n\t\t---------------------\n\n"));
    }
    else
    {
        Serial.print(27, BYTE);
        Serial.print(F("\n\t\t---------------------\n\n"));
        Serial.print(F("\n\t\t -- EMERGENCIA ATIVADA ------"));
        Serial.print(F("\n\t\t---------------------\n\n"));
    }
}
