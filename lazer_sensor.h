
void check_sistem(void *args)
{
    uint8_t params;
    params = (uint8_t *)args;
    vTaskDelay(500 / portTICK_PERIOD_MS);
    if (params== get_value())
    {
        vTaskDelay(10 / portTICK_PERIOD_MS);
        add_control(params);
        Serial.print("Adicionado Area ");
        Serial.println(params);
    }
    
}
