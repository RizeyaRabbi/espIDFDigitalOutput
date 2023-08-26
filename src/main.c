#include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define led 2

void app_main(void)
{
    ESP_ERROR_CHECK(gpio_set_direction(led, GPIO_MODE_OUTPUT));
    while (1)
    {
        ESP_ERROR_CHECK(gpio_set_level(led, 1));
        ESP_LOGI("Led", "Turned ON");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        ESP_ERROR_CHECK(gpio_set_level(led, 0));
        ESP_LOGI("Led", "Turned OFF");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}