// Events.cpp
// Implementierung der Member-Funktionen der Events-Klasse.

#include "Events.h"

/**
 * @brief Konstruktor der Events-Klasse.
 * Ruft das Hauptmenü für Veranstaltungen auf.
 */
Events::Events() {
    this->menuEvents();
}

/**
 * @brief Fragt den Benutzer, ob das Menü fortgesetzt werden soll.
 *
 * @return 'Y' für Ja, 'N' für Nein.
 */
char Events::continueMenue() {
    char continueMenu;
    std::cout << "Soll das Menü fortgesetzt werden? (Y/N): ";
    std::cin >> continueMenu;
    // Stellt sicher, dass die Eingabe immer Großbuchstaben sind.
    continueMenu = std::toupper(continueMenu);

    // Überprüft, ob die Eingabe gültig ist.
    if (continueMenu == 'Y' || continueMenu == 'N') {
        //Eingabe ist gültig
        return continueMenu;
    }
    else {
        //Eingabe ist falsch. Die Funktion wird neu aufgerufen.
        std::cout << "Falsche Eingabe" << std::endl;
        return this->continueMenue();
    }
}

/**
 * @brief Ruft das Hauptmenü für Veranstaltungen auf und verarbeitet die Benutzereingaben.
 */
void Events::menuEvents() {
    char menuSelection;
    char continueMenu = 'Y';
    std::cout << "--------------------------------------------------------------"<< std::endl;
    std::cout << "Herzlich Willkommen zu Ihrem Veranstaltungsplaner" << std::endl;
    do {
        menuSelection = this->menuSelection();

        switch (menuSelection) {
            case 'A':
                this->addEvents();
                break;
            case 'B':
                this->addParticipantsToEvent();
                break;
            case 'C':
                this->showAllEvents();
                break;
            case 'D':
                this->showSearchedEvent();
                break;
            case 'E':
                this->showEventsWithParticipants();
                break;
            case 'F':
                this->writeContactTracing();
                break;
            case 'G':
                this->writeEvents();
                break;
            case 'H':
                this->readData();
                break;
            default:
                std::cout << "Ungültige Eingabe. Bitte wählen Sie A, B, C, D, E, F, G oder H." << std::endl;
        }
        continueMenu = this->continueMenue();
    } while (continueMenu == 'Y');
    std::cout << "Der Veranstaltungsplaner schließt sich." << std::endl;
}

/**
 * @brief Zeigt dem Benutzer die Interaktionsmöglichkeiten im Hauptmenü und gibt die Auswahl des Benutzers zurück.
 *
 * @return Die Auswahl des Benutzers.
 */
const char Events::menuSelection() {
    char choice;
    std::cout << "--------------------------------------------------------------"<< std::endl;
    std::cout << "Sie haben folgende Interaktionsmöglichkeiten: " << std::endl;
    std::cout << "A: Ein Event anlegen." << std::endl;
    std::cout << "B: Einen Teilnehmer zu einem bestehenden Event hinzufügen." << std::endl;
    std::cout << "C: Alle bisherigen Events anzeigen." << std::endl;
    std::cout << "D: Nach einem bestimmten Event suchen und die Teilnehmer anzeigen." << std::endl;
    std::cout << "E: Die Events mit Teilnehmeranzahl ausgeben." << std::endl;
    std::cout << "F: Die Kontaktnachverfolgung." << std::endl;
    std::cout << "G: Alle Events in eine Datei schreiben." << std::endl;
    std::cout << "H: Testdaten einlesen." << std::endl;
    std::cout << "Ihre Eingabe: ";
    std::cin >> choice;
    return choice;
}

/**
 * @brief Setzt die Liste der Events.
 *
 * @param events Die Liste enthält alle Events.
 */
void Events::setEvents(std::vector<Event> events) {
    this->events = events;
}

/**
 * @brief Gibt die Liste der Events zurück.
 *
 * @return Die Liste der Events.
 */
const std::vector<Event> Events::getEvents() {
    return this->events;
}

/**
 * @brief Zeigt alle Events in der Konsole an.
 */
void Events::showAllEvents() {
    // Ausgabe, wenn keine Events in der Klassenvariablen vorliegt.
    if (this->events.empty()) {
        std::cout << "Es sind noch keine Events im Planer"<< std::endl;
    }

    // Durchläuft alle Events und zeigt sie mit showEvent() in der Konsole an.
    for (Event& event : this->events) {
        event.showEvent();
    }
}

/**
 * @brief Zeigt Events mit der Teilnehmeranzahl in der Konsole an.
 */
void Events::showEventsWithParticipants() {
    if(this->events.empty()){
        std::cout << "Es sind noch keine Events im Planer"<< std::endl;
    }
    else{
        std::cout << "--------------------------------------------------------------"<< std::endl;
        std::cout << "Eventdaten mit Teilnehmerzahl" << std::endl;
        std::cout << "--------------------------------------------------------------"<< std::endl;

        // Durchläuft alle Events und gibt Ort, Datum und Teilnehmeranzahl aus.
        for ( Event& event : this->events) {
            std::cout << "Ort des Events: " << event.getLocation() << std::endl;
            std::cout << "Datum des Events: " << event.getDate() << std::endl;
            std::cout << "Anzahl an Teilnehmern: " << event.getParticipants().size() << std::endl;
            std::cout << "--------------------------------------------------------------"<< std::endl;
        }
    }
}

/**
 * @brief Zeigt ein bestimmtes Event nach Ort oder Datum an, je nach Auswahl des Benutzers.
 */
void Events::showSearchedEvent() {
    char searchChoice = this->searchChoice();

    if (searchChoice == '1' || searchChoice == '2') {
        std::string searchInput;
        std::cout << "--------------------------------------------------------------"<< std::endl;

        if (searchChoice == '1') {
            std::cout << "Gib bitte den Ort an: ";
        }
        else {
            std::cout << "Gib bitte das Datum an: ";
        }

        std::cin >> searchInput;

        // Sucht nach Events und zeigt sie an, falls vorhanden.
        std::vector<Event*> foundEvents = (searchChoice == '1') ?
                findEventThrewLocation(searchInput) : findEventThrewDate(searchInput);

        if (foundEvents.empty()) {
            std::cout << "Keine Events gefunden."<< std::endl;
        }
        else {
            std::cout << "--------------------------------------------------------------"<< std::endl;
            for (Event*& event : foundEvents) {
                event->showEvent();
            }
        }
    }
    else {
        std::cout << "Ungültige Auswahl."<< std::endl;
    }
}

/**
 * @brief Fügt ein neues Event zur Liste der Events hinzu.
 */
void Events::addEvents() {
    std::cout << "--------------------------------------------------------------"<< std::endl;
    std::cout << "Welches Event möchtest du hinzufügen?"<< std::endl;

    // Erstellt ein neues Event und fügt es zur Liste hinzu.
    Event event = Event();
    Event tempEvent = event.createEvent();
    this->events.push_back(tempEvent);
}

/**
 * @brief Fragt den Benutzer, wie er nach einem Event suchen möchte (nach Ort oder Datum).
 *
 * @return Die Auswahl des Benutzers.
 */
const char Events::searchChoice() {
    char chosenEvent;
    std::cout << "--------------------------------------------------------------"<< std::endl;
    std::cout << "Wie möchten Sie das Event suchen: "<< std::endl;
    std::cout << "[1] Ort" << std::endl;
    std::cout << "[2] Datum (dd.mm.jjjj)"<< std::endl;
    std::cout << "Ihre Eingabe: ";

    // Ignoriert vorherige Eingaben, um sicherzustellen, dass die Eingabe korrekt eingelesen wird.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> chosenEvent;

    // Überprüft, ob die Eingabe gültig ist.
    if (chosenEvent == '1' || chosenEvent == '2') {
        return chosenEvent;
    }
    else {
        std::cout << "Falsche Eingabe" << std::endl;
        return this->searchChoice();
    }
}

/**
 * @brief Fügt Teilnehmer zu einem bestimmten Event hinzu.
 */
void Events::addParticipantsToSingleEvent(Event* event) {
    event->showEvent();
    char choice;
    std::cout << "Möchtest du zu diesem Event eine Person hinzufügen (Y/N)? ";
    std::cin >> choice;

    // Fügt Teilnehmer hinzu, wenn der Benutzer dies wünscht.
    if (choice == 'Y') {
        event->addParticipants();
    }
}

/**
 * @brief Fragt den Benutzer nach Ort oder Datum, um Teilnehmer zu einem Event hinzuzufügen.
 */
void Events::addParticipantsToEvent() {
    char searchChoice = this->searchChoice();
    std::string searchInput;
    std::cout << "--------------------------------------------------------------"<< std::endl;

    if (searchChoice == '1') {
        std::cout << "Gib bitte den Ort an: ";
    }
    else {
        std::cout << "Gib bitte das Datum an: ";
    }

    // Ignoriert vorherige Eingaben, um sicherzustellen, dass die Eingabe korrekt eingelesen wird.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, searchInput);

    // Sucht nach Events und fügt Teilnehmer hinzu, falls vorhanden.
    std::vector<Event*> foundEvents = (searchChoice == '1') ?
            this->findEventThrewLocation(searchInput) : this->findEventThrewDate(searchInput);
    if (foundEvents.empty()) {
        std::cout << "Kein Event gefunden." << std::endl;
    }
    else {
        for (Event*& event : foundEvents) {
            this->addParticipantsToSingleEvent(event);
        }
    }
    std::cout << "--------------------------------------------------------------"<< std::endl;
}

/**
 * @brief Schreibt die E-Mail-Adressen von Teilnehmern, die einem erkrankten Teilnehmer begegnet sind, in eine Datei.
 */
void Events::writeContactTracing() {
    if(this->events.empty()){
        std::cout << "Es sind noch keine Events im Planer"<< std::endl;
    }
    else{
        std::string infectedPersonName;
        std::cout << "--------------------------------------------------------------"<< std::endl;
        std::cout << "Welche Person ist erkrankt?: ";

        // Ignoriert vorherige Eingaben, um sicherzustellen, dass die Eingabe korrekt eingelesen wird.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, infectedPersonName);

        // Name der Datei, in der die Kontaktverfolgung gespeichert wird.
        std::string filePath = "contactTracing.txt";
        std::ofstream outputFile(filePath);

        if (outputFile.is_open()) {
            std::set<std::string> processedContacts;

            // Durchläuft alle Events und Teilnehmer, um Kontaktpersonen zu finden.
            for (Event& event : this->events) {
                for (Person participant : event.getParticipants()) {
                    if (participant.getName() == infectedPersonName) {
                        if (processedContacts.find(participant.getEmail()) == processedContacts.end()) {
                            outputFile << participant.getEmail() << std::endl;
                            processedContacts.insert(participant.getEmail());
                        }
                        for (Person contactPerson : event.getParticipants()) {
                            if (contactPerson.getName() != infectedPersonName &&
                                processedContacts.find(contactPerson.getEmail()) == processedContacts.end()) {
                                outputFile << contactPerson.getEmail() << std::endl;
                                processedContacts.insert(contactPerson.getEmail());
                            }
                        }
                    }
                }
            }
            outputFile.close();
            std::cout << "Kontaktpersonen erfolgreich gespeichert." << std::endl;
            std::cout << "--------------------------------------------------------------"<< std::endl;
        }
    }
}

/**
 * @brief Sucht nach Events anhand des Datums.
 *
 * @param chosenEvent Das gesuchte Datum.
 * @return Vektor von Zeigern auf die gefundenen Events.
 */
std::vector<Event*> Events::findEventThrewDate(const std::string& chosenEvent) {
    std::vector<Event*> foundEvents;

    // Durchläuft alle Events und fügt gefundene Events zum Vektor hinzu.
    for (Event& event : this->events) {
        if (chosenEvent == event.getDate()) {
            foundEvents.push_back(&event);
        }
    }
    return foundEvents;
}

/**
 * @brief Sucht nach Events anhand des Ortes.
 *
 * @param chosenEvent Der gesuchte Ort.
 * @return Vektor von Zeigern auf die gefundenen Events.
 */
std::vector<Event*> Events::findEventThrewLocation(const std::string& chosenEvent) {
    std::vector<Event*> foundEvents;

    // Durchläuft alle Events und fügt gefundene Events zum Vektor hinzu.
    for (Event& event : this->events) {
        if (chosenEvent == event.getLocation()) {
            foundEvents.push_back(&event);
        }
    }
    return foundEvents;
}

/**
 * @brief Schreibt alle Events in eine Datei.
 */
void Events::writeEvents() {
    if (this->events.empty()) {
        std::cout << "Es sind noch keine Events im Planer." << std::endl;
    }
    else {
        std::string path;
        std::cout << "Wie soll deine Datei heißen: ";
        std::cin >> path;
        std::ofstream outputFile(path);

        // Durchläuft alle Events und schreibt sie in die Datei.
        for (Event& event : this->events) {
            event.writeEvent(outputFile);
        }
    }
}

/**
 * @brief Liest Testdaten aus einer Datei ein.
 */
void Events::readData() {
    std::vector<Event> tempEvents;
    // Pfad zu den Beispieldaten
    std::string path = "TextData.txt";
    std::ifstream inputFile(path);

    //
    while (!inputFile.eof()) {
        Event event;
        tempEvents.push_back(event.readEvent(inputFile));
    }
    this->setEvents(tempEvents);
}
