set title 'Asymptotic Growth of Functions'
set xlabel 'n'
set ylabel 'Function Value'
set grid
set key outside
set key outside right
set grid
set terminal qt font 'Arial,10'
set xlabel 'n'
set ylabel 'Function Value (log scale)'
set logscale y

plot 'functions.dat' using 1:2  with lines lw 2 title '1/n',\
'functions.dat' using 1:3  with lines lw 2 title 'log2(n)',\
'functions.dat' using 1:4  with lines lw 2 title '12sqrt(n)',\
'functions.dat' using 1:5  with lines lw 2 title '50n^0.5',\
'functions.dat' using 1:6  with lines lw 2 title 'n^0.51',\
'functions.dat' using 1:7  with lines lw 2 title 'nlog2(n)',\
'functions.dat' using 1:8  with lines lw 2 title '2^32 n',\
'functions.dat' using 1:9  with lines lw 2 title '100n^2+6n',\
'functions.dat' using 1:10 with lines lw 2 title 'n^2-324',\
'functions.dat' using 1:11 with lines lw 2 title '2n^3',\
'functions.dat' using 1:12 with lines lw 2 title 'n^(log2 n)',\
'functions.dat' using 1:13 with lines lw 2 title '3^n'

pause -1
