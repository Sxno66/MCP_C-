/**
 * @file main.cpp
 * @brief Lecture de la température à partir d'un capteur MCP9808 via I2C.
 * 
 * Ce programme utilise les bibliothèques WiringPi et WiringPiI2C pour communiquer avec un
 * capteur de température MCP9808 sur le bus I2C. Il lit en boucle la température et l'affiche
 * en Celsius toutes les 2 secondes.
 */

#include <iostream>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <chrono>
#include <thread>

/**
 * @brief Point d'entrée du programme.
 * 
 * Ce programme configure le bus I2C, lit la température depuis le capteur MCP9808
 * et l'affiche en continu avec une pause de 2 secondes entre chaque lecture.
 * 
 * @return int Retourne 0 en cas de succès, 1 en cas d'erreur d'initialisation ou de lecture.
 */
int main() {
    int i2cAddress = 0x18; /**< @brief Adresse I2C par défaut du capteur MCP9808. */
    int fd = wiringPiI2CSetup(i2cAddress); /**< @brief Initialisation de la communication I2C avec le MCP9808. */

   
    if (fd == -1) {
        std::cerr << "Erreur : Impossible d'initialiser l'I2C." << std::endl;
        return 1;
    }

    while(1) {
        /**
         * @brief Lecture de la température brute depuis le registre 0x05 du MCP9808.
         * @details Le registre 0x05 contient la température en format 16 bits.
         */
        int tempRaw = wiringPiI2CReadReg16(fd, 0x05);
        
     
        if (tempRaw == -1) {
            std::cerr << "Erreur : Impossible de lire la température." << std::endl;
            return 1;
        }

        /**
         * @brief Conversion des données brutes en température Celsius.
         * @details Les données sont initialement en format big-endian, donc les octets sont
         * inversés. Ensuite, les 12 bits de température sont extraits et divisés par 16
         * pour obtenir la température en Celsius.
         */
        tempRaw = ((tempRaw & 0xFF) << 8) | ((tempRaw >> 8) & 0xFF); /**< @brief Inversion des octets pour l'endianness. */
        float tempC = tempRaw & 0x0FFF; /**< @brief Extraction des 12 bits de température. */
        tempC /= 16.0; /**< @brief Conversion de la température en degrés Celsius. */
        
       
        if (tempRaw & 0x1000) {
            tempC -= 256;
        }

        
        std::cout << "Température : " << tempC << " °C" << std::endl;

        /**
         * @brief Pause de 2 secondes avant la prochaine lecture.
         */
        std::chrono::milliseconds timespan(2000); /** Délai de 2 secondes entre les lectures. */
        std::this_thread::sleep_for(timespan);
    }

    return 0;
}
