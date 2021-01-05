# Zettel 6, IPI
Anton, Johannes, Maxi
bei Kamal
## Aufgabe 1
### a
det(A) = 10000 in float-Berechnung, nicht exakt
det(A) = 10000.0001 in double exakt
det(B) = 1 in float, exakt
det(B) = 0.9999999999999999 in double, nicht exakt

### b
es steht für verschiedene Werte n die Differenz von (a+b)+c und a+(b+c). Gilt die Assoziativität dann ist die Differenz gleich 0.
Wichtig ist, dass die pow-Funktion die standardmäßig Doubles ausgibt zu einer Float gecasted wird. Ansonsten würde man der Aufgabenstellung nicht gerecht werden.
#### Ausgabe bei basis=10
1 -3.799796104431152e-07
2 -1.52587890625e-05
3 2.343754749745131e-05
4 0
5 9.999999747378752e-06
6 0
7 1.000000011686097e-07
8 0
9 9.999999717180685e-10
10 0
11 9.999999960041972e-12
12 0
13 9.9999998245167e-14
14 0
überall wo ungleich 0 nicht assoziativ, also für alle ungeraden n sowie n=2
Das liegt daran, dass Zahlen zur Basis 10 nicht immer eine endliche Binärdarstellung haben und deshalb gerundet werden.
#### Ausgabe bei basis=2:
1 0
2 0
3 0
4 0
5 0
6 0
7 0
8 0
9 0
10 0
11 0
12 0
13 0.0001220703125 -> nicht assoziativ
14 0
Grundsätzlich sollte die Assoziativität zur Basis 2 immer gegeben sein. wir gehen davon aus, dass bei der Umwandlung von double zu float ein Rundungsfehler geschah.
## Aufgabe 2
Format:
Berechnung mit Float / Differenz Float zu Exp
Berechnung mit Double / Differenz Double zu Exp
n = 1
0.05999994277954102 -0.001836602341784843
0.05999999865889549 -0.001836546462430366
n = 12
0.06167769432067871 -0.0001588508006471478
0.06167781044776244 -0.000158734673563421
n = 365
0.06183362007141113 -2.925049914725975e-06
0.06183130925409341 -5.235867232444846e-06
n = 8760
0.06133055686950684 -0.0005059882518190228
0.06183632693731167 -2.18184014189049e-07
n = 525600
0.06466090679168701 0.002824361670361153
0.06183654148338324 -3.63794261382111e-09
n = 31536000
0 -0.06183654512132586
0.06183654320035159 -1.920974268543318e-09

Bei exakter Rechnung wäre zu erwarten, dass die Differenzen im Grenzwert n->oo gegen 0 gehen. Ursache für die Abweichungen ist, dass kleine Abweichungen gerundet werden (weil nicht jede Zahl eine endliche Binärdarstellung hat bzw. weil eine Float nur eine begrenzte Anzahl von Stellen darstellen kann).
