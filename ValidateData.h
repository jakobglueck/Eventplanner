//
// Created by Jakob Glück on 30.01.24.
//

#pragma once
#include "include.h"

/**
 * @brief Die Klasse ValidateData enthält Funktionen zur Validierung von Benutzerdaten.
 */
class ValidateData {
public:
    ////////////////////////////////////////////////////////////////
    //                          Public-Funktionen                 //
    ////////////////////////////////////////////////////////////////

    /**
    * @brief Überprüft, ob der übergebene Name gültig ist.
    *
    * @param inputName - Der zu überprüfende Name.
    * @return True, wenn der Name gültig ist, sonst False.
    */
    bool validateName(const std::string& inputName);

    /**
    * @brief Überprüft, ob die übergebene E-Mail-Adresse gültig ist.
    *
    * @param inputEmail - Die zu überprüfende E-Mail-Adresse.
    * @return True, wenn die E-Mail-Adresse gültig ist, sonst False.
    */
    bool validateEmail(const std::string& inputEmail);

    /**
    * @brief Überprüft, ob die übergebene Telefonnummer gültig ist.
    *
    * @param inputPhoneNumber - Die zu überprüfende Telefonnummer.
    * @return True, wenn die Telefonnummer gültig ist, sonst False.
    */
    bool validatePhoneNumber(const std::string& inputPhoneNumber);

    /**
     * @brief Überprüft, ob der übergebene Ort gültig ist.
     *
     * @param location - Der zu überprüfende Ort.
     * @return True, wenn der Ort gültig ist, sonst False.
     */
    bool validateLocation(const std::string& location);

    /**
    * @brief Überprüft, ob das übergebene Datum gültig ist.
    *
    * @param date - Das zu überprüfende Datum liegt in Form von "TT.MM.JJJJ" vor.
    * @return True, wenn das Datum gültig ist, sonst False.
    */
    bool validateDate(const std::string& date);
};
