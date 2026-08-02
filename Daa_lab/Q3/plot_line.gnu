set terminal png size 900,600
set output "bubble_line.png"

set title "Bubble Sort Comparison"
set xlabel "Array Size"
set ylabel "Number of Comparisons"

set grid

plot "bubble_data.dat" using 1:2 with linespoints lw 2 title "Early Stop", \
     "bubble_data.dat" using 1:3 with linespoints lw 2 title "Normal Bubble"