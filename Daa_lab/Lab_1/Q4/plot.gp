set terminal qt

set title "Tower of Hanoi"
set xlabel "Number of Disks"
set ylabel "Number of Moves"

set grid

set style data linespoints

plot "moves.dat" using 1:2 title "Moves = 2^n - 1"

pause -1