set terminal pngcairo size 900,600
set output 'coin_probability.png'
set title 'Fair vs Biased Coin Toss Simulation'
set xlabel 'Number of Tosses'
set ylabel 'Estimated Probability of Head'
set grid
set logscale x
set xtics ('100' 100,'500' 500,'1000' 1000,'5000' 5000,'10000' 10000)
set yrange [0.4:0.8]
set arrow from 100,0.5 to 10000,0.5 nohead dt 2
set arrow from 100,0.7 to 10000,0.7 nohead dt 2
plot 'results.dat' using 1:2 with linespoints lw 2 pt 7 title 'Fair Coin',\
     'results.dat' using 1:3 with linespoints lw 2 pt 5 title 'Biased Coin'
