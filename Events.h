//
// Erstellt von Jakob Glück am 22.01.24.
//
#pragma once
#include "Event.h"  // Notwendige Header-Dateien einbinden

/**
 * @brief Die Klasse Events verwaltet eine Liste von Veranstaltungen.
 */
class Events {
public:
    ////////////////////////////////////////////////////////////////
    //                       Konstruktoren                        //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Standardkonstruktor für die Events-Klasse.
     */
    Events();

    ////////////////////////////////////////////////////////////////
    //                          Setter                            //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Setzt die Veranstaltungen für die Events-Klasse.
     *
     * @param events Vektor von Veranstaltungen.
     */
    void setEvents(std::vector<Event> events);

    ////////////////////////////////////////////////////////////////
    //                          Getter                            //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Gibt die Veranstaltungen zurück.
     * @return Vektor von Veranstaltungen.
     */
    const std::vector<Event> getEvents();

    ////////////////////////////////////////////////////////////////
    //                       Öffentliche Funktionen               //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Zeigt das Menü für Events an und behandelt die Auswahl.
     */
    void menuEvents();

    /**
     * @brief Zeigt alle Veranstaltungen an.
     */
    void showAllEvents();

    /**
     * @brief Zeigt Veranstaltungen mit Teilnehmern an.
     */
    void showEventsWithParticipants();

    /**
     * @brief Zeigt eine gesuchte Veranstaltung an.
     */
    void showSearchedEvent();

    /**
     * @brief Fügt neue Veranstaltungen hinzu.
     */
    void addEvents();

    /**
     * @brief Fügt Teilnehmer zu einer Veranstaltung hinzu.
     */
    void addParticipantsToEvent();

    /**
     * @brief Liest Beispieldatensatz ein.
     */
    void readData();

    /**
     * @brief Schreibt alle Personen auf die mit einer infizierten Person in Kontakt waren.
     */
    void writeContactTracing();

    /**
     * @brief Schreibt Veranstaltungsdaten.
     */
    void writeEvents();

private:
    ////////////////////////////////////////////////////////////////
    //                    Private Hilfsfunktionen                 //
    ////////////////////////////////////////////////////////////////

    /**
     * @brief Gibt die Auswahl für die Suche zurück.
     * @return Zeichen, das die Auswahl für die Suche repräsentiert.
     */
    const char searchChoice();

    /**
     * @brief Gibt die Auswahl für das Menü zurück.
     * @return Zeichen, das die Menüauswahl repräsentiert.
     */
    const char menuSelection();

    /**
     * @brief Gibt an, ob das Menü fortgesetzt werden soll.
     * @return Zeichen, das angibt, ob das Menü fortgesetzt werden soll oder nicht.
     */
    char continueMenue();

    /**
     * @brief Sucht nach Veranstaltungen anhand des Datums.
     * @param chosenEvent Das gewünschte Datum.
     * @return Vektor von Veranstaltungen, die das Datum enthalten.
     */
    std::vector<Event*> findEventThrewDate(const std::string& chosenEvent);

    /**
     * @brief Sucht nach Veranstaltungen anhand des Ortes.
     * @param chosenEvent Der zu gewünschte Ort.
     * @return Vektor von Veranstaltungen, die den Ort enthalten.
     */
    std::vector<Event*> findEventThrewLocation(const std::string& chosenEvent);

    /**
     * @brief Fügt Teilnehmer zu einer einzelnen Veranstaltung hinzu.
     * @param event Die ausgewählte Veranstaltung, zu der eine Person hinzugefügt werden soll.
     */
    void addParticipantsToSingleEvent(Event* event);

    ////////////////////////////////////////////////////////////////
    //                       Private Variablen                    //
    ////////////////////////////////////////////////////////////////

    std::vector<Event> events; /**< Vektor von Veranstaltungen. */
};
