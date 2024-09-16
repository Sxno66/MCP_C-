#include "Sensor.h"
#include <iostream>

/**
 * @brief Constructeur par défaut de la classe Sensor.
 * 
 * Initialise l'attribut temp à 0.0 et affiche un message indiquant que le
 * constructeur par défaut a été appelé.
 */
Sensor::Sensor() : temp(0.0f) {
    std::cout << "Constructeur par défaut appelé" << std::endl;
}

/**
 * @brief Constructeur avec paramètre de la classe Sensor.
 * 
 * Ce constructeur initialise l'attribut temp à 0.0 et affiche l'adresse
 * fournie lors de l'appel. Il pourrait également être utilisé pour initialiser
 * un capteur avec une adresse I2C donnée.
 * 
 * @param adrTemp Adresse I2C du capteur.
 */
Sensor::Sensor(int adrTemp) : temp(0.0f) {
    std::cout << "Constructeur avec adresse " << adrTemp << " appelé" << std::endl;
  
}

/**
 * @brief Destructeur de la classe Sensor.
 * 
 * Affiche un message indiquant que le destructeur a été appelé.
 */
Sensor::~Sensor() {
    std::cout << "Destructeur appelé" << std::endl;
}

/**
 * @brief Méthode pour lire la température.
 * 
 * Cette méthode simule la lecture de la température en générant une valeur
 * aléatoire entre 20.0°C et 30.0°C. La température est ensuite stockée
 * dans l'attribut temp et affichée.
 */
void Sensor::lireTemp() {

    temp = 20.0f + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 10.0f;
    std::cout << "Température lue : " << temp << "°C" << std::endl;
}

/**
 * @brief Méthode pour afficher la température.
 * 
 * Affiche la température actuelle stockée dans l'attribut temp.
 */
void Sensor::affTemp() {
    std::cout << "La température actuelle est : " << temp << "°C" << std::endl;
}
