/**

Prueba
* @file main.cpp
* @author Sandoval, Raña
* @date 23/03/2023
* @brief Testear una entrada y una salida digital del NUCLEO-F429ZI
* @details Hay dos carpetas 
* En Build, está el archivo mbed_config.h donde están definidas las constantes que usa mbed. 
* En mbed-os, están las librerías de mbed
* Luego, hay 6 archivos:
*       .gitignore es un archivo que indica a Git que archivos o carpetas ignorar
*       .mbed indica el modelo del dispositivo a trabajar
*       arm_book_lib.h Es una librería armada por el libro para trabajar con los ejemplos
*       compile_commands.json es un archivo json con los comandos para compilar
*       main.cpp archivo principal del proyecto en c++ 
*       mbed-os.lib link a mbed OS

*/

#include "mbed.h"
#include "arm_book_lib.h"

bool mensajeEnviado = false;

/**
* @brief    Monitorea el sensor de gas. Si lee un 1 enciende un LED
*           Antes de iniciar imprime el mensaje "Hello World"
* @param    Ninguno
* @return   Ninguno
*/

int main()
{

    /**
    * @brief    Definición del objeto gasDetector como clase DigitalIn
    * @param    D2
    * @details  gasDetector se define como un objeto de la clase DigitalIn a la que se le
    *           envía como parámetro D2 que define la dirección de memoria 0x5F en la libreria
    *           mbed-os>targets>TARGET_STM>TARGET_STM32F4>TARGET_NUCLEO_F439ZI>PinNames.h
    *           El constructor de la clase DigitalIn llama a la función gpio_init_in() que
    *           ascocia la dirección de memoria 0x5F con una estructura gpio_t y la configura
    *           como pin de entrada.
    */
    DigitalIn gasDetector(D2);

    /**
    * @brief    Definición del objeto alarmLed como clase DigitalOut
    * @param    LED1
    * @details  El procedimiento es equivalente al realizado para gasDetector pero con la clase
    *           DigitalOut. Se declara alarmLed como un objeto de la clase DigitalOut pasando
    *           LED1 como argumento, cuya dirección de memoria es 0x10.
    *           El constructor de la case llama a la función gpio_init_out() que inicializa el pin
    *           como pin de salida.
    */
    DigitalOut alarmLed(LED1);

    /**
    * @brief    Se llama al método mode() de la clase DigitalOut para configurar el pin de salida
    *           asociado al objeto alarmLed como PullDown.
    * @param PullDown
    */
    gasDetector.mode(PullDown); 

    alarmLed = OFF;
    printf("%s\n", "Hello World");
    while (true) {

        /**
        * @brief    El loop while(true) utiliza los operadores de sobrecarga definidos en las clases
        *           DigitalIn y DigitalOut.
        * @details  En la clase DigitalIn se define el operador int que permite comparar el estado
        *           del objeto con enteros. En la clase DigitalOut, además del operador int se define
        *           el operador "=" que modifica el estado del pin al igualar el objeto a un 1 o un 0.
        */
        if ( gasDetector == ON ) {  // Se copara el pin gasDetector con ON = 1
            alarmLed = ON;  // Se utiliza una sobrecarga para alarmLed que llama a la función write()
                            // que modifica el estado del pin físico a 1.
            if(mensajeEnviado == false){
                printf("%s\n", "Se detectó gas y se encendió la alarma");
                mensajeEnviado = true;
            }
        }
        
        if ( gasDetector == OFF ) { // Se copara el pin gasDetector con OFF = 0
            alarmLed = OFF; // Se utiliza una sobrecarga para alarmLed que llama a la función write()
                            // que modifica el estado del pin físico a 0.
            if(mensajeEnviado == true){
                printf("%s\n", "Se dejó de detectar gas y se apagó la alarma");
                mensajeEnviado = false;
            }
            
        }
    }
}