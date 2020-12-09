binomial braucht z.B. für n=34, k=15 15.886s
binomial_fast funktioniert für n>12 nicht mehr (falsche Ergebnisse), was vermutlich daran liegt, dass 13!>2^32,
die Zahl also nicht mehr in 32-Bit dargestellt werden kann, binomial funktioniert aber immer noch
binomial_fast ist für n<12 oft schneller als binomial, aber nicht immer.