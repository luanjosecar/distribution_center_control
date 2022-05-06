
void check_sistem_s1(void *args)
{
    uint8_t param;
    for (;;)
    {
        param = get_value();
        if (digitalRead(PASS_1B))
        {
            if (param == 0)
            {
                Serial.print("Adicionado Area 0");
                digitalWrite(L1_PASS, HIGH);
                add_mesa1();
                vTaskDelay(random(500) / portTICK_PERIOD_MS);
                digitalWrite(L1_PASS, LOW);
            }
            else
            {
                // Interupção do sistema
                Serial.println("Interupção causada por erro no leitor 0");
                set_eme_status(true);
            }

            xTaskNotifyGive(MoveHandler);
            vTaskDelay(2000 / portTICK_PERIOD_MS);
        }
        // Serial.print(" Aguardando Leitor 1 ");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void check_sistem_s2(void *args)
{
    uint8_t param;
    for (;;)
    {
        param = get_value();
        if (digitalRead(PASS_2B))
        {
            if (param == 1)
            {
                Serial.print("Adicionado Area 1");
                digitalWrite(L2_PASS, HIGH);
                add_mesa2();
                vTaskDelay(random(500) / portTICK_PERIOD_MS);
                digitalWrite(L2_PASS, LOW);
            }
            else
            {
                // Interupção do sistema

                Serial.println("Interupção causada por erro no leitor 1");
                set_eme_status(true);
            }

            xTaskNotifyGive(MoveHandler);
            vTaskDelay(2000 / portTICK_PERIOD_MS);
        }
        // Serial.print(" Aguardando Leitor 2 ");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void check_sistem_s3(void *args)
{
    uint8_t param;
    for (;;)
    {
        param = get_value();
        if (digitalRead(PASS_3B))
        {
            if (param == 2)
            {
                Serial.print("Passando para área de retorno ");
                digitalWrite(L3_PASS, HIGH);
                vTaskDelay(random(500) / portTICK_PERIOD_MS);
                digitalWrite(L3_PASS, LOW);
            }
            else
            {

                Serial.println("Interupção causada por erro no leitor 2");
                set_eme_status(true);
            }

            xTaskNotifyGive(MoveHandler);
            vTaskDelay(2000 / portTICK_PERIOD_MS);
        }
        // Serial.print(" Aguardando Leitor 3 ");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
