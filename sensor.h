#ifndef SENSOR_H
#define SENSOR_H

using namespace std;

/**
 * @brief Classe représentant un capteur de température.
 * 
 * La classe Sensor permet de lire et d'afficher la température d'un capteur. Elle propose
 * un constructeur par défaut, un constructeur avec une adresse de capteur, et un destructeur.
 */
class Sensor
{  
public:
    /**
     * @brief Constructeur par défaut de la classe Sensor.
     * 
     * Ce constructeur initialise l'attribut `Temp` à 0.0 et prépare l'objet Sensor.
     */
    Sensor();

    /**
     * @brief Constructeur avec paramètre.
     * 
     * Ce constructeur prend en paramètre une adresse du capteur, typiquement une adresse I2C,
     * pour initialiser un capteur à une adresse spécifique.
     * 
     * @param adrTemp Adresse du capteur (ex. adresse I2C).
     */
    Sensor(int adrTemp);

    /**
     * @brief Destructeur de la classe Sensor.
     * 
     * Libère les ressources utilisées par l'objet Sensor.
     */
    ~Sensor();

    /**
     * @brief Méthode pour lire la température.
     * 
     * Simule la lecture de la température depuis un capteur et met à jour l'attribut `Temp`.
     */
    void lireTemp();

    /**
     * @brief Méthode pour afficher la température.
     * 
     * Affiche la valeur actuelle de la température stockée dans `Temp`.
     */
    void affTemp();

private:
    float Temp; /**< @brief Stocke la température lue par le capteur. */
};

#endif
