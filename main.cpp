/**

Prueba
* @file main.cpp
* @author Sandoval, Raña
* @date 16/03/2023
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

    DigitalIn gasDetector(D2); //Definición del objeto gasDetector como clase DigitalIn

    DigitalOut alarmLed(LED1); //Definición del objeto alarmLed como clase DigitalOut

    gasDetector.mode(PullDown); //Dentro de la clase DigitalIn se encuentra la función mode
                                //Que modifica el pin físico como PulllDown
    bool mensajeEnviado = false;

    alarmLed = OFF;
    printf("%s\n", "Hello World");
    while (true) {
        if ( gasDetector == ON ) { //En la clase DigitalIn está definido el operador int
                                    //que se compara con ON. El operador int devuelve el resultado
                                    //de la función read() que lee el estado físico del pin
            alarmLed = ON;  // Se utiliza una sobrecarga para alarmLed que llama a la función write
                            // que modifica el estado del pin físico
            if(mensajeEnviado == false){
                printf("%s\n", "Se detectó gas y se encendió la alarma");
                mensajeEnviado = true;
            }
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
            if(mensajeEnviado == true){
                printf("%s\n", "Se dejó de detectar gas y se apagó la alarma");
                mensajeEnviado = false;
            }
            
        }
    }
}