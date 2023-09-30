# SWO3-Übungen - WS 2023/24 - Übung 2

## 1. Sortieren ganzer Zahlen (src/sort/)

Bauen Sie das folgende C-Codefragment zu einem voll funktionsfähigen C-Programm aus.

```c
#define MAX 100

void MergeSort(int a[], int n) {
  /* code to sort a[0].. a[n - 1] using merge sort */
}

int main(int argc, char *argv[]) {
  int n, a[MAX];
  /* code to read a maximum of MAX values from argv to a and
     to set n to the actual number of values in a*/
  /* code to display unsorted array a */
  MergeSort(a, n);
  /* code to display sorted array a */
  return 0;
}

```

## 2. Mini-Sudoku Solver & Generator (src/sudoku/)

![Sucoku](/doc/sudoku.PNG)

Mit Hilfe des Backtracking-Verfahrens lassen sich auch viele Spiele oder
Puzzles automatisiert lösen. Mit diesem einfachen Trick kann eine
„Brute-Force“-Suche so verbessert werden, dass Lösungen in vernünftiger
Zeit gefunden werden können. Beim klassischen Sudoku gibt es
$9^{9\cdot9} = 2\cdot10^{77}$ verschiedenen Konfigurationen, also
fast so viele wie Atome im Universum ($10^{80}$), davon sind aber nur
knapp $7\cdot10^{21}$ gültig. Wenn dazu noch zwischen 16 und 32 Positionen  
vorgegeben werden, reduziert sich die Anzahl weiter, sodass in vielen Fällen
eine Lösung in kurzer Zeit gefunden werden kann. Folgende Bedingungen müssen
erfüllt sein, damit eine Belegung gültig ist:

* In jeder Zeile dürfen die Zahlen 1 bis 9 jeweils nur einmal vorkommen.
* In jeder Spalte dürfen die Zahlen 1 bis 9 jeweils nur einmal vorkommen.
* In jedem 3×3-Teilfeld dürfen die Zahlen 1 bis 9 jeweils nur einmal vorkommen.

Entwickeln Sie eine Menge von C-Funktionen um mit Sudoku-Problemen experimentieren
zu können. Wählen Sie eine geeignete Repräsentation in der Sie verschiedenen
Belegungen testen können und entwickeln Sie eine Funktion zum Lösen eines eventuell
schon vorbelegten Feldes.

**a.** Definieren Sie eine geeignete Datenstruktur und etwaige Zugriffsfunktionen
um einzelne Positionen per Koordinaten zu setzen und zu lesen, sowie eine
Möglichkeit die aktuelle Belegung übersichtlich auszugeben, z.B. als
ASCII-Graphik:

```c
 ------------ ------------ ------------
|  2  ..  .. |  4  ..  .. | ..  ..   7 |
| ..  ..  .. | ..   7  .. |  9  ..  .. |
| ..  ..  .. | ..  ..  .. |  4  ..  .. |
 ------------ ------------ ------------
| ..  ..   1 | ..  ..  .. | ..  ..  .. |
| ..  ..  .. |  9  ..   8 | ..   4  .. |
| ..  ..  .. | ..  ..   6 |  2  ..  .. |
 ------------ ------------ ------------
| ..  ..  .. | ..   2   1 |  3  ..  .. |
| ..  ..  .. | ..   9  .. | ..  ..  .. |
|  5  ..   9 | ..  ..  .. |  7   8  .. |
 ------------ ------------ ------------
```

**b.** Als nächstes entwickeln Sie die Funktionalität um für ein Spielfeld zu
überprüfen ob es (noch) gültig ist, bzw. gültig werden kann, wobei diese
Prüfung auch leere Stellen berücksichtigen soll. Obige Beispiele sollen daher als gültig klassifiziert werden auch wenn sie noch nicht vollständig sind. Dabei soll also insbesondere geprüft werden, ob Zahlen in den jeweiligen Gruppen (Zeilen, Spalten, Teilfelder) mehrfach vorkommen.

**c.** Nun können Sie diese Funktionalität verwenden um einen Solver im
Backtracking-Verfahren zu entwickeln. Versuchen Sie dabei so bald wie
möglich bei ungültigen Teilbelegungen abzubrechen. Achten Sie außerdem
darauf, dass vorbelegte Positionen nicht durchprobiert werden dürfen. Sie
können dabei immer einen Zeiger auf den aktuellen Stand weitergeben bei dem
Sie die Positionen rekursiv und die Zahlen schrittweise durchprobieren.
Vergessen Sie am Ende nicht die Belegung der Position wieder zurückzunehmen,
falls es damit keine gültigen Lösungen gab.

**d.** Schreiben Sie eine weitere Funktion mit Hilfe der Funktion aus Aufgabe (b) die ein Feld „zufällig“ mit 10 bis 20 Zahlen so initialisiert, dass es sich um  eine noch gültige Situation handelt. Die generierten Spielfelder müssen zwar gültig aber weder eindeutig lösbar noch überhaupt lösbar sein.

### Hinweise

* Eine einfache Betrachtungsweise ist das gesamte Spielfeld als zusammenhängendes
Feld zu sehen und mit Hilfe von Zugriffsfunktionen darauf Zeilen und Spalten zu
emulieren. Dabei kann z.B. auch die Zahl Null für ein unbelegtes Feld stehen.

* Die Größe des Feldes definieren Sie dabei am besten als Konstanten. Gerade
in der initialen Phase kann es sinnvoll sein z.B. auch mit kleineren Felder
zu experimentieren. Dabei ist es möglicherweise hilfreich als kleinste Einheit
jeweils die Seitenlänge eines Subfeldes als Basis zu nehmen, z.B.:

  ```c
  #define SUB_BOARD_SIZE 3
  #define BOARD_SIZE (SUB_BOARD_SIZE*SUB_BOARD_SIZE)
  ```

* Wenn alle Feldgrößen konstant bleiben, müssen Sie keine zusätzlichen Feldlängen
als Parameter übergeben.

* Zufällige Zahlen können mit Hilfe der Funktion `rand()` erhalten werden. Um den
richtigen Wertebereich zu verwenden kann die Modulo-Funktion verwendet werden.
So kann z.B. eine Zufällige Zahl zwischen 1 und `BOARD_SIZE` (jeweils inklusive)
erzeugt werden:

  ```c
  int nr = rand() % BOARD_SIZE + 1;
  ```

  Am Anfang des Hauptprogramms kann dann der Zufallszahlengenerator mit der
  aktuellen Uhrzeit initialisiert werden, damit nicht immer die gleiche Folge von
  Zufallszahlen generiert wird:

  ```c
  #include <stdlib.h>
  #include <time.h>
  …
  srand(time(NULL));
  ```

* Sie können Online-Sudoku-Solver verwenden um Ihre Lösungen zu verifizieren,
wie z.B. [http://www.sudokuwiki.org/sudoku.htm](http://www.sudokuwiki.org/sudoku.htm).
