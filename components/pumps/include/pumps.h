#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"


void pumps_init (void);
void pump_control(void);
void nutrient_system_start(void);
void get_sensors_readings(void);


