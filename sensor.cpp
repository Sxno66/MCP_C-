#include "Sensor.h"
#include <iostream>

// Constructeur par défaut
Sensor::Sensor() : temp(0.0f) {
    std::cout << "Constructeur par défaut appelé" << std::endl;
}

// Constructeur avec paramètre
Sensor::Sensor(int adrTemp) : temp(0.0f) {
    std::cout << "Constructeur avec adresse " << adrTemp << " appelé" << std::endl;
    // Ici, vous pourriez initialiser le capteur avec l'adresse fournie
}

// Destructeur
Sensor::~Sensor() {
    std::cout << "Destructeur appelé" << std::endl;
}

// Méthode pour lire la température
void Sensor::lireTemp() {
  
   
    temp = 20.0f + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 10.0f;
    std::cout << "Température lue : " << temp << "°C" << std::endl;
}

// Méthode pour afficher la température
void Sensor::affTemp()  {
    std::cout << "La température actuelle est : " << temp << "°C" << std::endl;
}





