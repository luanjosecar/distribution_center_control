
TaskHandle_t LazerSensor1 = NULL; //Detecta o laser que identifica a passagem do primeiro laser
TaskHandle_t LazerSensor2 = NULL; //Detecta o laser que identifica a passagem do segundo laser
TaskHandle_t LazerSensor3 = NULL; //Detecta o laser que identifica a passagem do terceiro laser

void check_sistem_s1(void *args) //Checa a passagem do objeto pela primeira mesa
{
    uint8_t param;

    param = get_value(); 
    
    if (digitalRead(PASS_1B)) //Sensor 1 ligado
    {
        if (param == 0) // Se o objeto for referente a esta caixa
        {
            add_control(param);  //Adiciona um valor ao contador de itens da caixa
            Serial.print("Adicionado Area ");
            Serial.println(L1_PASS);
            digitalWrite(L1_PASS, HIGH); //Energisa led que representa sensor da primeira caixa
            vTaskDelay(random(1000) / portTICK_PERIOD_MS); //Segura por um instante de tempo o Led aceso
            digitalWrite(L1_PASS, LOW); //Desliga  led
        }
        else //Objeto foi para a caixa errada e uma interrupção é acionada
        {
            // Acionar um interupt
            //xTaskNotifyGive(InteruptHandler);
        }
    }

    vTaskDelete(LazerSensor1); //Remove da lista de tarefas
}

void check_sistem_s2(void *args) //Checa a passagem do objeto pela segunda mesa
{
    uint8_t param;

    param = get_value();
    if (digitalRead(PASS_2B)) //Sensor 2 ligado
    {
        if (param == 1) //Se o objeto detectado for referente à segunda mesa
        {
            add_control(param); //Adiciona um valor ao contador de itens da caixa
            Serial.print("Adicionado Area ");
            Serial.println(L2_PASS);
            digitalWrite(L2_PASS, HIGH); //Energisa led que representa a segunda caixa
            vTaskDelay(random(1000) / portTICK_PERIOD_MS); //Segura por um instante de tempo o Led aceso
            digitalWrite(L2_PASS, LOW); //Desliga  led
        }
        else //Objeto foi para a caixa errada e uma interrupção é acionada
        {
            // Interupção do sistema
            //xTaskNotifyGive(InteruptHandler);
        }
    }

    vTaskDelete(LazerSensor2);//Remove da lista de tarefas
}

void check_sistem_s3(void *args) //Checa a passagem do objeto pela terceira mesa
{
    uint8_t param;

    param = get_value();
    
    if (digitalRead(PASS_3B)) //Sensor 3 ligado
    {
        if (param == 0)
        {
            add_control(param);  //Adiciona um valor ao contador de itens da caixa
            Serial.print("Adicionado Area ");
            Serial.println(L3_PASS);
            digitalWrite(L3_PASS, HIGH); //Energisa led que representa a terceira caixa
            vTaskDelay(random(1000) / portTICK_PERIOD_MS); //Segura por um instante de tempo o Led aceso
            digitalWrite(L3_PASS, LOW);//Desliga  led
        }
        else //Objeto foi para a caixa errada e uma interrupção é acionada
        {
            //xTaskNotifyGive(InteruptHandler);
        }
    }

    vTaskDelete(LazerSensor3);//Remove da lista de tarefas
}

void validate_lazer(void *args)
{
    for (;;) //Loop para leitura constante dos sensores
    {

        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        xTaskCreate(
            check_sistem_s1, // Função
            "Leitor 1",      // Nome
            80,              // Empilhamento -- Armazenamento de memória
            NULL,            // Parametros
            1,               // Prioridade
            &LazerSensor1);
        xTaskCreate(
            check_sistem_s2, // Função
            "Leitor 1",      // Nome
            80,              // Empilhamento -- Armazenamento de memória
            NULL,            // Parametros
            1,               // Prioridade
            &LazerSensor2);
        xTaskCreate(
            check_sistem_s3, // Função
            "Leitor 1",      // Nome
            80,              // Empilhamento -- Armazenamento de memória
            NULL,            // Parametros
            1,               // Prioridade
            &LazerSensor3);
        vTaskDelay(random(1000) / portTICK_PERIOD_MS);

        set_flagpass(false);
        xTaskNotifyGive(MoveHandler);
    }
}
