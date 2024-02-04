#  Event-Management-Programm
Dieses C++-Programm bietet eine einfache Möglichkeit zur Verwaltung von Veranstaltungen und Teilnehmern.
Es ermöglicht:
+  Hinzufügen von Events
+  Hinzufügen von Teilnehmern zu einem bereits bestehenden Event
+  Anzeigen von allen Events mit teilnehmenden Personen
+  Anzeigen aller Events mit der Teilnehmerzahl 
+  Suchen nach einem Event durch den Ort oder das Datum
+  Kontaktnachverfolgung 
+  Schreiben von den Events in eine Datei
+  Einlesen von Testevents aus einer Datei 

##  Inhaltsverzeichnis
+ Dateistruktur
+ Klassen
+ Nutzung
+ Dateiein- und -ausgabe
+ Menüführung
+ Kontaktnachverfolgung
+ Testdaten
##  Dateistruktur
Event.cpp, Event.h: Implementierung der Event-Klasse zur Darstellung von Veranstaltungen.
Events.cpp, Events.h: Implementierung der Events-Klasse zur Verwaltung von Eventlisten.
Person.cpp, Person.h: Implementierung der Person-Klasse zur Verwaltung von Teilnehmerdaten.
ValidateData.cpp, ValidateData.h: Implementierung der ValidateData-Klasse zur Validierung der eingegeben Event- und Personen-Daten.

##  Klassen
### Events-Klasse
Die Events-Klasse verwaltet eine Liste von Veranstaltungen und bietet eine Menü für Benutzerinteraktionen.

### Event-Klasse
Die Event-Klasse repräsentiert eine Veranstaltung und bietet Methoden zur Verwaltung von Veranstaltungsinformationen.

### Person-Klasse
Die Personen-KLasse enthält alle Teilnehmerinforamtionen und bietet Methoden um diese Zu Erzeugen oder zu verwalten.

### ValidateData-Klasse
Die ValidateData-Klasse kontrolliert Eingabewerte der Personen- und Event-Daten und liefert Wahrheitswerte um deren Gültigkeit zurück.

##  Nutzung

Kompilieren Sie die Dateien mit einem C++-Compiler Ihrer Wahl.
Ausführung: g++ -std=c++11 main.cpp Person.cpp ValidateData.cpp Event.cpp Events.cpp

Führen Sie das kompilierte Programm aus:
./a.out

##  Dateiein- und -ausgabe
Das Programm unterstützt das Schreiben und Lesen von Veranstaltungsdaten in und aus Dateien. Informationen zu Events werden in Dateien gespeichert, und Testdaten können aus einer vorgegebenen Datei eingelesen werden.

##  Menüführung
Die Events-Klasse bietet eine benutzerfreundliche Menüführung für die Verwaltung von Veranstaltungen. Benutzer können Events hinzufügen, Teilnehmer zu Events hinzufügen, alle Events anzeigen und mehr.

##  Kontaktnachverfolgung
Das Programm ermöglicht die Kontaktnachverfolgung, indem es E-Mail-Adressen von Teilnehmern, die einer erkrankten Person begegnet sind, in eine Datei schreibt.

##  Testdaten
Das Programm kann Testdaten aus einer vorgegebenen Datei einlesen (TextData.txt), um die Liste der Veranstaltungen zu initialisieren.

Hinweis:
Dieses Programm enthält möglicherweise Referenzen auf Klassen (Person, ValidateData), die nicht bereitgestellt wurden. Diese Klassen sollten gemäß den Anforderungen implementiert werden.