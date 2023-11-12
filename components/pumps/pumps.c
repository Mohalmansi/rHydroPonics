#include "pumps.h"
extern int tds;
extern int ph;

/*
 * configuration of pumps function
 * pH Acid --> pin 18
 * pH base --> pin 19
 * solution A --> pin 23
 * solution B --> pin 32
 * solution C --> pin 33
 */


void get_sensors_readings(void)
{
	tds=190;
	ph=6;
}
void pumps_init(void)
{

	gpio_set_direction(GPIO_NUM_18,GPIO_MODE_OUTPUT);
	gpio_set_direction(GPIO_NUM_19,GPIO_MODE_OUTPUT);
	gpio_set_direction(GPIO_NUM_23,GPIO_MODE_OUTPUT);
	gpio_set_direction(GPIO_NUM_32,GPIO_MODE_OUTPUT);
	gpio_set_direction(GPIO_NUM_33,GPIO_MODE_OUTPUT);
}

/*
 * after getting the readings in global variable (ph , tds)
 * we will control the pumps accordingly
 */



void pump_control(void)
{
	// ph levels
	if (ph<7 && tds<200)
	{
		gpio_set_level(GPIO_NUM_19,1);
		vTaskDelay(100);
		gpio_set_level(GPIO_NUM_23,1);
		vTaskDelay(100);
		gpio_set_level(GPIO_NUM_32,1);
		vTaskDelay(100);
		gpio_set_level(GPIO_NUM_33,1);
		vTaskDelay(100);


	}
	else if(ph>7)
	{
		gpio_set_level(GPIO_NUM_18,1);

	}
	else
	{
		gpio_set_level(GPIO_NUM_18,0);
		gpio_set_level(GPIO_NUM_19,0);

	}
	//tds levels
	if (tds<200)
	{
		gpio_set_level(GPIO_NUM_23,1);
		vTaskDelay(100);
		gpio_set_level(GPIO_NUM_32,1);
		vTaskDelay(100);
		gpio_set_level(GPIO_NUM_33,1);
		vTaskDelay(100);

	}
	else if (tds>200)
	{

	gpio_set_level(GPIO_NUM_23,0);
	gpio_set_level(GPIO_NUM_32,0);
	gpio_set_level(GPIO_NUM_33,0);

	}
}
/*
 * now combining all the functions to call it as a main function in the application main.c
 */
void nutrient_system_start(void)
{
	get_sensors_readings();
	pumps_init();
	pump_control();
}




