set terminal pdfcairo enhanced color font "Times,12" size 6in,4in
set output "annA.pdf"

set xlabel "x"
set ylabel "y"
set title "Artificial Neural Network assignment A"

set grid

plot \
'ann.data' using 1:2 with lines lc rgb '#d77f21' title 'true', \
'ann.data' using 1:3 with lines lc rgb '#6a0dad' title 'ann'