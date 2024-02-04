//
// Created by Jakob Glück on 30.01.24.
//

//
// ValidateData.cpp
// Implementierung von Funktionen zur Validierung von für Event- und Personendaten
//

#include "ValidateData.h"

/**
 * @brief Überprüft, ob der übergebene Name gültig ist.
 *
 * Diese Funktion prüft, ob der übergebene Name nicht leer ist.
 *
 * @param inputName Der zu überprüfende Name.
 * @return True, wenn der Name alle Bedingungen erfüllt, sonst False.
 */
bool ValidateData::validateName(const std::string& inputName) {
    // Überprüft, ob der Name leer ist.
    if (inputName.empty()) {
        return false;
    }
    // Name ist gültig
    return true;
}

/**
 * @brief Überprüft, ob die übergebene E-Mail-Adresse gültig ist.
 *
 * Diese Funktion prüft, ob die E-Mail-Adresse nicht leer ist und das '@' und '.de' oder '.com' enthält.
 *
 * @param inputEmail Die zu überprüfende E-Mail-Adresse.
 * @return True, wenn die E-Mail-Adresse alle Bedingungen erfüllt, sonst False.
 */
bool ValidateData::validateEmail(const std::string& inputEmail) {
    if (!inputEmail.empty() || inputEmail.find('@') != std::string::npos) {
        if (inputEmail.find(".de") != std::string::npos || inputEmail.find(".com") != std::string::npos) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

/**
 * @brief Überprüft, ob die übergebene Telefonnummer gültig ist.
 *
 * Diese Funktion überprüft die Länge der Telefonnummer und die Zulässigkeit der Zeichen.
 *
 * @param inputPhoneNumber Die zu überprüfende Telefonnummer.
 * @return True, wenn die Telefonnummer alle Bedingungen erfüllt, sonst False.
 */
bool ValidateData::validatePhoneNumber(const std::string& inputPhoneNumber) {
    // Überprüft die Länge der Telefonnummer und die Zulässigkeit der Zeichen.
    if (inputPhoneNumber.size() >= 3 && inputPhoneNumber.size() <= 15) {
        for (char number : inputPhoneNumber) {
            if (!isdigit(number) && number != '+' && number != '(' && number != ')') {
                return false;
            }
        }
    }
    // Die Telefonnummer gilt als gültig.
    return true;
}

/**
 * @brief Überprüft, ob das übergebene Datum gültig ist.
 *
 * Diese Funktion überprüft die Länge, das Format und die Gültigkeit des Datums.
 *
 * @param inputDate Das zu überprüfende Datum im Format "dd.mm.jjjj".
 * @return True, wenn das Datum alle Bedingungen erfüllt, sonst False.
 */
bool ValidateData::validateDate(const std::string& inputDate) {
    // Das aktuelle Datum wird erstellt
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);
    int currentYear = localTime->tm_year + 1900;

    int day, month, year;
    // Überprüft, ob Datum die erlaubte Länge besitzt
    if (inputDate.length() != 10) {
        return false;
    }
    // Überprüft, ob Dots an den richtigen Stellen platziert ist
    if (inputDate[2] != '.' || inputDate[5] != '.') {
        return false;
    }
    // Umwandlung des @param inputDate als Integerwerten in Tag, Monat, Jahr
    day = std::stoi(inputDate.substr(0, 2));
    month = std::stoi(inputDate.substr(3, 2));
    year = std::stoi(inputDate.substr(6, 4));
    // Überprüft, ob Monat und Tag erlaubte Werte enthalten
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    // Überprüfung, ob das eingegebene Jahr in der Vergangenheit liegt
    if (year < currentYear) {
        return false;
    }
    // Überprüfung, ob der eingegebene Monat in der Vergangenheit liegt
    if (year == currentYear && month < localTime->tm_mon + 1) {
        return false;
    }
    // Überprüfung, ob der eingegebene Tag in der Vergangenheit liegt
    if (year == currentYear && month == localTime->tm_mon + 1 && day <= localTime->tm_mday) {
        return false;
    }
    // Datum ist gültig
    return true;
}

/**
 * @brief Überprüft, ob der übergebene Ort gültig ist.
 *
 * Diese Funktion prüft, ob der übergebene Ort nicht leer ist.
 *
 * @param inputLocation Der zu überprüfende Ort.
 * @return True, wenn der Ort alle Bedingungen erfüllt, sonst False.
 */
bool ValidateData::validateLocation(const std::string& inputLocation) {
    // Überprüft, ob Ort leer ist.
    if (inputLocation.empty()) {
        return false;
    }
    // Ort ist gültig
    return true;
}
