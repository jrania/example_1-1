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
    DigitalIn gasDetector(D2);

    DigitalOut alarmLed(LED1);

    gasDetector.mode(PullDown);

    alarmLed = OFF;
    printf("%s\n", "Hello World");
    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
        }
    }
}