//
// Erstellt von Jakob Glück am 15.01.24.
//

#pragma once
#include "Person.h"  // Notwendige Header-Dateien einbinden

/**
 * @brief Die Klasse Event repräsentiert eine Veranstaltung mit Teilnehmern, Ort und Datum.
 */
class Event {
public:
    ////////////////////////////////////////////////////////////////
    //                       Konstruktoren                        //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Standardkonstruktor für die Event-Klasse.
     */
    Event();

    /**
     * @brief Konstruktor für die Event-Klasse mit Parametern.
     *
     * @param participants Vektor von Personen, die an der Veranstaltung teilnehmen.
     * @param location Der Veranstaltungsort.
     * @param date Das Veranstaltungsdatum.
     */
    Event(std::vector<Person>& participants, std::string& location, std::string& date);

    ////////////////////////////////////////////////////////////////
    //                          Setter                            //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Setzt die Teilnehmer der Veranstaltung.
     *
     * @param participants Vektor von Personen, die an der Veranstaltung teilnehmen.
     */
    void setParticipants(std::vector<Person> participants);

    /**
     * @brief Setzt den Veranstaltungsort.
     *
     * @param location Der Veranstaltungsort.
     */
    void setLocation(std::string location);

    /**
     * @brief Setzt das Veranstaltungsdatum.
     *
     * @param date Das Veranstaltungsdatum.
     */
    void setDate(std::string date);

    ////////////////////////////////////////////////////////////////
    //                          Getter                            //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Gibt die Teilnehmer der Veranstaltung zurück.
     * @return Vektor von Personen, die an der Veranstaltung teilnehmen.
     */
    const std::vector<Person> getParticipants();

    /**
     * @brief Gibt den Veranstaltungsort zurück.
     * @return Der Veranstaltungsort.
     */
    const std::string getLocation();

    /**
     * @brief Gibt das Veranstaltungsdatum zurück.
     * @return Das Veranstaltungsdatum.
     */
    const std::string getDate();

    ////////////////////////////////////////////////////////////////
    //                       Öffentliche Funktionen               //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Erstellt und gibt eine Veranstaltung zurück, indem Benutzereingaben überprüft werden.
     * @return Eine Veranstaltung.
     */
    const Event createEvent();

    /**
     * @brief Fügt Teilnehmer zur Veranstaltung hinzu.
     */
    void addParticipants();

    /**
     * @brief Zeigt Informationen über die Veranstaltung in der Konsole an.
     */
    void showEvent();

    /**
     * @brief Zeigt Informationen über die Teilnehmer der Veranstaltung.
     */
    const void showParticipants();

    /**
     * @brief Liest Informationen über die Veranstaltung aus einer Datei.
     * @param inputFile Variable, aus der klassenrelevante Daten extrahiert werden.
     * @return Eine aus der Datei eingelesene Veranstaltung.
     */
    Event readEvent(std::ifstream& inputFile);

    /**
     * @brief Schreibt Informationen über die Veranstaltung in eine Datei.
     * @param outputFile Variable, in die die Werte geschrieben werden.
     */
    void writeEvent(std::ofstream& outputFile);

private:
    ////////////////////////////////////////////////////////////////
    //                    Private Hilfsfunktionen                 //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Fügt eine Person zur Veranstaltung hinzu.
     * @return Zeichen, das angibt, ob eine weitere Person hinzugefügt werden soll oder nicht.
     */
    const char addPersonToEvent();

    ////////////////////////////////////////////////////////////////
    //                       Private Variablen                    //
    ////////////////////////////////////////////////////////////////

    std::vector<Person> participants; /**< Vektor von Personen, die an der Veranstaltung teilnehmen. */
    std::string location; /**< Der Veranstaltungsort. */
    std::string date; /**< Das Veranstaltungsdatum. */
};
