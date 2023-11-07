#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"





void app_main(void)
{
		gpio_set_direction(GPIO_NUM_2,GPIO_MODE_OUTPUT);
    while (1)
    {
       gpio_set_level(GPIO_NUM_2,1);
       vTaskDelay(100);
       gpio_set_level(GPIO_NUM_2,0);
       vTaskDelay(100);



    }
}
