//
// Erstellt von Jakob Glück am 15.01.24.
//
// Person.cpp
// Implementierung der Member-Funktionen der Person-Klasse.

#include "Person.h"

/**
 * @brief Standardkonstruktor der Person-Klasse.
 */
Person::Person()= default;

/**
 * @brief Konstruktor der Person-Klasse mit Parameterüberprüfung.
 *
 * @param name Der Name der Person.
 * @param email Die E-Mail der Person.
 * @param phoneNumber Die Telefonnummer der Person.
 * @throw std::invalid_argument, wenn die übergebenen Daten ungültig sind.
 */
Person::Person(std::string& name, std::string& email, std::string& phoneNumber) {
    // Erzeugt eine Instanz der ValidateData-Klasse für die Validierung von Benutzereingaben.
    ValidateData validateData;

    // Überprüft, ob der Name, die E-Mail und die Telefonnummer gültig sind.
    if (validateData.validateName(name) && validateData.validateEmail(email)
        && validateData.validatePhoneNumber(phoneNumber)) {
        // Wenn die Daten gültig sind, setzt die Member-Variablen.
        this->setName(name);
        this->setEmail(email);
        this->setPhoneNumber(phoneNumber);
    } else {
        // Falls die Daten ungültig sind, wird ein Fehler geworfen.
        throw std::invalid_argument("Deine Eingabe ist falsch. Bitte überprüfe die Daten.");
    }
}

/**
 * @brief Setzt den Namen der Person.
 *
 * @param name Der neue Name der Person.
 */
const void Person::setName(std::string name) {
    this->name = name;
}

/**
 * @brief Setzt die E-Mail der Person.
 *
 * @param email Die neue E-Mail der Person.
 */
const void Person::setEmail(std::string email) {
    this->email = email;
}

/**
 * @brief Setzt die Telefonnummer der Person.
 *
 * @param phoneNumber Die neue Telefonnummer der Person.
 */
const void Person::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

/**
 * @brief Gibt den Namen der Person zurück.
 *
 * @return Der Name der Person.
 */
const std::string Person::getName() {
    return this->name;
}

/**
 * @brief Gibt die E-Mail der Person zurück.
 *
 * @return Die E-Mail der Person.
 */
const std::string Person::getEmail() {
    return this->email;
}

/**
 * @brief Gibt die Telefonnummer der Person zurück.
 *
 * @return Die Telefonnummer der Person.
 */
const std::string Person::getPhoneNumber() {
    return this->phoneNumber;
}

/**
 * @brief Erstellt und gibt eine Person zurück, indem Benutzereingaben überprüft werden.
 *
 * @return Eine vollständige Person.
 */
Person Person::createPerson() {
    std::string tempName, tempEmail, tempPhoneNumber;

    // Benutzer wird nach dem Namen gefragt.
    std::cout << "--------------------------------------------------------------"<< std::endl;
    std::cout << "Wie lautet der Name der Person: ";

    // Ignoriert vorherige Eingaben, um sicherzustellen, dass der Name korrekt eingelesen wird.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Liest den Namen als Zeichenkette ein.
    std::getline(std::cin, tempName);

    // Benutzer wird nach der E-Mail gefragt und liest sie ein.
    std::cout << "Wie lautet die Email der Person: ";
    std::cin >> tempEmail;

    // Benutzer wird nach der Telefonnummer gefragt und liest sie ein.
    std::cout << "Wie lautet die Telefonnummer der Person: ";
    std::cin >> tempPhoneNumber;

    // Erzeugt eine Person mit den eingegebenen Daten.
    Person person = Person(tempName, tempEmail, tempPhoneNumber);

    // Gibt person zurück.
    return person;
}

/**
 * @brief Zeigt die Informationen über die Person an der Konsole an.
 */
const void Person::showPerson() {
    // Ausgabe aller Personen-Daten in der Konsole
    std::cout << "Name der Person: " << this->getName() << std::endl;
    std::cout << "Email der Person: " << this->getEmail() << std::endl;
    std::cout << "Phone number der Person: " << this->getPhoneNumber() << std::endl;
    std::cout << "--------------------------------------------------------------"<< std::endl;
}

/**
 * @brief Schreibt die Informationen über die Person in eine Datei.
 *
 * @param outputFile Der Ausgabestrom der Datei.
 */
void Person::writePerson(std::ofstream& outputFile) {
    // Schreibt Name, E-Mail und Telefonnummer in die Datei.
    outputFile << this->getName() << std::endl;
    outputFile << this->getEmail()<< std::endl;
    outputFile << this->getPhoneNumber()<< std::endl;
}

/**
 * @brief Liest die Informationen über die Person aus einer Datei.
 *
 * @param inputFile Der Eingabestrom der Datei.
 * @param tempName Ein temporärer Name zur Verwendung bei der Dateileseoperation.
 */
void Person::readPerson(std::ifstream& inputFile, std::string tempName) {
    std::string tempEmail, tempPhoneNumber;

    // Liest E-Mail und Telefonnummer aus einer Datei.
    std::getline(inputFile, tempEmail);
    std::getline(inputFile, tempPhoneNumber);

    // Setzt den Namen sowie die E-Mail und Telefonnummer der Person.
    this->setName(tempName);
    this->setEmail(tempEmail);
    this->setPhoneNumber(tempPhoneNumber);
}
