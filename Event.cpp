// Event.cpp
// Implementierung der Member-Funktionen der Event-Klasse.

#include "Event.h"

/**
 * @brief Standardkonstruktor der Event-Klasse.
 */
Event::Event() = default;

/**
 * @brief Konstruktor der Event-Klasse mit Parameterüberprüfung.
 *
 * @param participants Die Teilnehmer der Veranstaltung.
 * @param location Der Veranstaltungsort.
 * @param date Das Veranstaltungsdatum.
 * @throw std::invalid_argument, wenn die übergebenen Daten ungültig sind.
 */
Event::Event(std::vector<Person>& participants, std::string& location, std::string& date) {
    ValidateData validateData;

    // Überprüft, ob der Veranstaltungsort und das Datum gültig sind.
    if (validateData.validateLocation(location) && validateData.validateDate(date)) {
        this->setDate(date);
        this->setLocation(location);
        this->setParticipants(participants);
    } else {
        // Falls die Daten ungültig sind, wird ein Fehler geworfen.
        throw std::invalid_argument("Die Eingabe der Daten ist falsch.");
    }
}

/**
 * @brief Setzt die Teilnehmer der Veranstaltung.
 *
 * @param participants Die Teilnehmer der Veranstaltung.
 */
void Event::setParticipants(std::vector<Person> participants) {
    this->participants = participants;
}

/**
 * @brief Setzt das Datum der Veranstaltung.
 *
 * @param date Das Veranstaltungsdatum.
 */
void Event::setDate(std::string date) {
    this->date = date;
}

/**
 * @brief Setzt den Veranstaltungsort.
 *
 * @param location Der Veranstaltungsort.
 */
void Event::setLocation(std::string location) {
    this->location = location;
}

/**
 * @brief Gibt das Veranstaltungsdatum zurück.
 *
 * @return Das Veranstaltungsdatum.
 */
const std::string Event::getDate() {
    return this->date;
}

/**
 * @brief Gibt den Veranstaltungsort zurück.
 *
 * @return Der Veranstaltungsort.
 */
const std::string Event::getLocation() {
    return this->location;
}

/**
 * @brief Gibt die Teilnehmer der Veranstaltung zurück.
 *
 * @return Die Teilnehmer der Veranstaltung.
 */
const std::vector<Person> Event::getParticipants() {
    return this->participants;
}

/**
 * @brief Fragt den Benutzer, ob er eine Person zur Veranstaltung hinzufügen möchte.
 *
 * @return 'Y' für Ja, 'N' für Nein.
 * @throw std::invalid_argument, wenn die Eingabe ungültig ist.
 */
const char Event::addPersonToEvent() {
    char tempChoice;
    std::cout << "--------------------------------------------------------------"<< std::endl;
    std::cout << "Möchtest du eine Person zur Veranstaltung hinzufügen? -> Ja [Y] und Nein [N]: ";
    std::cin >> tempChoice;

    // Überprüft, ob die Eingabe gültig ist.
    if (tempChoice == 'Y' || tempChoice == 'N') {
        return tempChoice;
    } else {
        // Wirft eine Ausnahme, wenn die Eingabe ungültig ist.
        throw std::invalid_argument("Ungültige Eingabe. Bitte gib 'Y' für Ja oder 'N' für Nein ein.");
    }
}

/**
 * @brief Erstellt eine Veranstaltung und gibt sie zurück, indem Benutzereingaben überprüft werden.
 *
 * @return Die erstellte Veranstaltung.
 */
const Event Event::createEvent() {
    std::string tempLocation, tempDate;

    // Benutzer wird nach dem Veranstaltungsort gefragt.
    std::cout << "--------------------------------------------------------------"<< std::endl;
    std::cout << "Wo soll deine Veranstaltung stattfinden: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, tempLocation);

    // Benutzer wird nach dem Veranstaltungsdatum gefragt.
    std::cout << "Wann soll deine Veranstaltung stattfinden: ";
    std::cin >> tempDate;

    char choice;
    do {
        choice = this->addPersonToEvent();

        // Fügt eine Person zur Veranstaltung hinzu, wenn der Benutzer 'Y' ausgewählt hat.
        if (choice == 'Y') {
            this->addParticipants();
        }
    } while (choice != 'N');

    std::cout << "--------------------------------------------------------------"<< std::endl;
    std::cout << "Du hast alle Personen zu deiner Veranstaltung hinzugefügt." << std::endl;
    std::cout << "--------------------------------------------------------------"<< std::endl;

    Event event = Event(this->participants, tempLocation, tempDate);
    return event;
}

/**
 * @brief Fügt eine Person zur Veranstaltung hinzu.
 */
void Event::addParticipants() {
    // Erzeugt eine temporäre Person und fügt sie der Liste der Teilnehmer hinzu.
    Person addedPerson = Person();
    Person tempPerson = addedPerson.createPerson();
    this->participants.push_back(tempPerson);
}

/**
 * @brief Zeigt Informationen über die Veranstaltung in der Konsole an.
 */
void Event::showEvent() {
    std::cout << "--------------------------------------------------------------"<< std::endl;
    std::cout << "Allgemeine Eventdaten" << std::endl;
    std::cout << "--------------------------------------------------------------"<< std::endl;
    std::cout << "Ort des Events: " << this->getLocation()<< std::endl;
    std::cout << "Datum des Events: " << this->getDate() << std::endl;
    std::cout << "--------------------------------------------------------------"<< std::endl;
    std::cout << "Teilnehmer" << std::endl;
    std::cout << "--------------------------------------------------------------"<< std::endl;

    // Zeigt Informationen über alle Teilnehmer der Veranstaltung.
    this->showParticipants();
}

/**
 * @brief Zeigt Informationen über die Teilnehmer der Veranstaltung in der Konsole an.
 */
const void Event::showParticipants() {
    // Durchläuft alle Teilnehmer und ruft die Funktion showPerson() auf, um deren Informationen anzuzeigen.
    for ( Person& person : this->participants) {
        person.showPerson();
    }
}

/**
 * @brief Schreibt die Informationen über die Veranstaltung in eine Datei.
 *
 * @param outputFile Der Ausgabestrom der Datei.
 */
void Event::writeEvent(std::ofstream& outputFile) {
    // Schreibt Ort und Datum der Veranstaltung in die Datei.
    outputFile << this->getLocation() << std::endl;
    outputFile << this->getDate() << std::endl;

    // Schreibt Informationen über jeden Teilnehmer der Veranstaltung in die Datei.
    for ( Person& person : this->participants) {
        person.writePerson(outputFile);
    }

    // Fügt eine leere Zeile als Trennung zwischen verschiedenen Veranstaltungen hinzu.
    outputFile << "" << std::endl;
}

/**
 * @brief Liest die Informationen über die Veranstaltung aus einer Datei.
 *
 * @param inputFile Der Eingabestrom der Datei.
 * @return Die eingelesene Veranstaltung.
 */
Event Event::readEvent(std::ifstream& inputFile) {
    std::string tempLocation, tempDate;
    std::vector<Person> tempPersons;
    Event event;
    bool eventStop = true;

    // Liest Ort und Datum der Veranstaltung aus der Datei.
    std::getline(inputFile, tempLocation);
    std::getline(inputFile, tempDate);

    event.setLocation(tempLocation);
    event.setDate(tempDate);

    // Liest Informationen über jeden Teilnehmer der Veranstaltung aus der Datei.
    while (eventStop) {
        std::string tempName;
        std::getline(inputFile, tempName);

        if (!tempName.empty()) {
            Person person;
            person.readPerson(inputFile, tempName);
            tempPersons.push_back(person);
        } else {
            // Beendet die Schleife, wenn eine leere Zeile erreicht ist.
            eventStop = false;
        }
    }

    // Setzt die Teilnehmer der Veranstaltung.
    event.setParticipants(tempPersons);
    return event;
}
