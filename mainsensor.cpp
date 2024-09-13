#include <iostream>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main() {
    int i2cAddress = 0x18; // Adresse I2C par défaut du MCP9808
    int fd = wiringPiI2CSetup(i2cAddress); // Initialisation de l'I2C

    if (fd == -1) {
        std::cerr << "Erreur : Impossible d'initialiser l'I2C." << std::endl;
        return 1;
    }

    while(1) {
    // Lecture de la température depuis le registre 0x05
    int tempRaw = wiringPiI2CReadReg16(fd, 0x05);
    if (tempRaw == -1) {
        std::cerr << "Erreur : Impossible de lire la température." << std::endl;
        return 1;
    }

    // Conversion des données brutes en température Celsius
    tempRaw = ((tempRaw & 0xFF) << 8) | ((tempRaw >> 8) & 0xFF); // Inversion des octets pour corriger l'endianness
    float tempC = tempRaw & 0x0FFF;
    tempC /= 16.0;
    if (tempRaw & 0x1000) {
        tempC -= 256;
    }

    std::cout << "Température : " << tempC << " °C" << std::endl;

    }
    return 0;
    
    
  
}

