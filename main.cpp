/**
* @file main.cpp
* @author Sandoval, Raña
* @date 23/03/2023
* @section TP 2 B
* @brief Analizar el código propuesto por la cátedra, detallando las estructuras
*       características de C++. La propuesta es reemplazar el código para que el
*       lenguaje utilizado sea C.
*/

//=====[Librerias]=============================================================
#include "mbed.h"
#include "arm_book_lib.h"

//=====[Funcion Main]==========================================================
/**
*   @brief  Monitorea el sensor de gas. Si lee un 1 enciende un LED
*           Antes de iniciar imprime el mensaje "Hello World"
*   @param  Ninguno
*   @return Ninguno
*/

int main()
{
    /**
    * Se inicializan dos estructuras gpio_t: gasDetector y alarmLed. Cada una
    * corresponde a un pin de entrada/salida del NUCLEO.
    * La guncion gpio_init_in() inicializa el pin D2 como entrada, asociandolo
    * con gasDetector. La funcion gpio_init_out_ex() inicializa el pin LED1
    * asociándolo con alarmLed y configurándolo como Pull Dowm.
    */
    gpio_t gasDetector;
    gpio_init_in(&gasDetector, D2);

    gpio_t alarmLed;
    gpio_init_out_ex(&alarmLed, LED1, PullDown);

    /**
    * El loop while(true) testea los estados de gasDetector con la función gpio_red()
    * que devuelve un 1 o un 0. En cada caso, escribe un 1 o un 0 en alarmLed con la
    * función gpio_write().
    */
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