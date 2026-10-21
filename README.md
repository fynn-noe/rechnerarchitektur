# rechnerarchitektur

## Aufgabe 1
Implementiere die Funktion addition in der Datei addition.asm, die zwei Zahlen addiert und das Ergebnis zurückgibt. Diese Funktion wird dann mit tests.c aufgerufen und getestet. Die Zahlen, die addiert werden sollen, stehen in den Registern rdi und rsi.

Kompiliere die Dateien wie folgt:
```console
nasm -f elf64 -o addition.o addition.asm
```

```console
gcc -c tests.c -o tests.o
```

```console
gcc -o addition tests.o addition.o
```

Dann kannst du dein Programm mit beliebigen Ganzzahlen testen:

```console
./addition 3 4
```

## Aufgabe 2
Implementiere die triangle in triangle.asm. Die Funktion soll bei Eingabeparametern a und b (a*b)/2 berechnen und ausgeben. Eingabeparameter stehen erneut in rdi und rsi. Ihr könnt die Funktion so testen und kompilieren wie in 1. (es muss nur addition durch triangle ersetzt werden).

## Zusatzaufgabe
Könnt ihr 2 auch implementieren ohne div zu nutzen? 
