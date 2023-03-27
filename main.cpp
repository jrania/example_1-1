/**
* @file main.cpp
* @author Sandoval, Raña
* @date 16/03/2023
* @brief Testear una entrada y una salida digital del NUCLEO-F429ZI
*/

#include "mbed.h"
#include "arm_book_lib.h"

/**
* @brief Monitorea el sensor de gas. Si lee un 1 enciende un LED
*       Antes de iniciar imprime el mensaje "Hello World"
*/

int main()
{
    /**
    * @brief Declarar las variables correspondientes a un pin digital de entrada (gasDetector)
    *       y a un pin digital de salida (alarmLed).
    * @param D2 
    **/
    gpio_t gasDetector;
    gpio_init_in(&gasDetector, D2);

    gpio_t alarmLed;
    gpio_init_out_ex(&alarmLed, LED1, PullDown);


    gpio_write(&alarmLed, OFF);
    printf("%s\n", "Hello World");
    while (true) {
        if ( gpio_read(&gasDetector) == ON ) {
            gpio_write(&alarmLed, ON);
        }
        
        if ( gpio_read(&gasDetector) == OFF ) {
            gpio_write(&alarmLed, OFF);
        }
    }
}