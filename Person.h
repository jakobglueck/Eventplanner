//
// Created by Jakob Glück on 15.01.24.
//

#pragma once
#include "include.h"
#include "ValidateData.h"

/**
 * @brief Die Klasse Person repräsentiert eine Person mit Namen, E-Mail und Telefonnummer.
 */
class Person {
public:
    ////////////////////////////////////////////////////////////////
    //                       Konstruktoren                        //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Standardkonstruktor für die Person-Klasse.
     */
    Person();

    /**
     * @brief Konstruktor für die Person-Klasse mit Parametern.
     *
     * @param name Der Name der Person.
     * @param email Die E-Mail der Person.
     * @param phoneNumber Die Telefonnummer der Person.
     */
    Person(std::string& name, std::string& email, std::string& phoneNumber);

    ////////////////////////////////////////////////////////////////
    //                          Setter                            //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Setzt den Namen der Person.
     *
     * @param name Der neue Name der Person.
     */
    const void setName(std::string name);

    /**
     * @brief Setzt die E-Mail der Person.
     *
     * @param email Die neue E-Mail der Person.
     */
    const void setEmail(std::string email);

    /**
     * @brief Setzt die Telefonnummer der Person.
     *
     * @param phoneNumber Die neue Telefonnummer der Person.
     */
    const void setPhoneNumber(std::string phoneNumber);

    ////////////////////////////////////////////////////////////////
    //                          Getter                            //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Gibt den Namen der Person zurück.
     * @return Der Name der Person.
     */
    const std::string getName();

    /**
     * @brief Gibt die E-Mail der Person zurück.
     * @return Die E-Mail der Person.
     */
    const std::string getEmail();

    /**
     * @brief Gibt die Telefonnummer der Person zurück.
     * @return Die Telefonnummer der Person.
     */
    const std::string getPhoneNumber();

    ////////////////////////////////////////////////////////////////
    //                          Public-Funktionen                 //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Erstellt und gibt eine Person zurück, indem Benutzereingaben überprüft werden.
     * @return Eine Person.
     */
    Person createPerson();

    /**
     * @brief Zeigt Informationen über die Person in der Konsole an.
     */
    const void showPerson();

    /**
     * @brief Liest die Informationen über die Person aus einer Datei.
     * @param inputFile Variable aus der die klassenrelvenaten Daten gezogen werden.
     * @param tempName Ein temporärer Name der Person die eingelesen werden soll.
     */
    void readPerson(std::ifstream& inputFile, std::string tempName);

    /**
     * @brief Schreibt die Informationen über die Person in eine Datei.
     * @param outputFile Variable in die die Werte geschrieben werden.
     */
    void writePerson(std::ofstream& outputFile);

private:
    ////////////////////////////////////////////////////////////////
    //                          Klassenvariablen                  //
    ////////////////////////////////////////////////////////////////

    std::string name; /**< Der Name der Person. */
    std::string email; /**< Die E-Mail der Person. */
    std::string phoneNumber; /**< Die Telefonnummer der Person. */
};
