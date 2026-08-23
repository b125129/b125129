set terminal png size 900,600
set output "comparison.png"

set title "Duplicate Detection Algorithms"
set xlabel "Number of Elements (n)"
set ylabel "Number of Steps"

set grid
set key left top

plot "steps.dat" using 1:2 with linespoints lw 2 title "Brute Force O(n^2)", \
     "steps.dat" using 1:3 with linespoints lw 2 title "Sorting O(n log n)"