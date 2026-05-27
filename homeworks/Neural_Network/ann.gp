set terminal pdfcairo enhanced color font "Times,12" size 6in,4in
set output "annA.pdf"

set xlabel "x"
set ylabel "y"
set title "Artificial Neural Network assignment A"

set grid

plot \
'ann.data' using 1:2 with lines lw 3 lc rgb '#d77f21' title 'true', \
'ann.data' using 1:3 with lines lw 2 lc rgb '#6a0dad' dt 2 title 'ann'

set terminal pdfcairo enhanced color font "Times,12" size 6in,4in
set output "annB.pdf"

set xlabel "x"
set ylabel "y"
set title "Artificial Neural Network assignment B"

set grid

plot \
'ann_opgB.data' using 1:2 with lines lw 3 lc rgb '#d77f21' title 'true', \
'ann_opgB.data' using 1:3 with lines lw 2 lc rgb '#6a0dad' dt 2 title 'ann', \
'ann_opgB.data' using 1:4 with lines lw 3 lc rgb '#d721c2' title 'first derivative (ann)', \
'ann_opgB.data' using 1:5 with lines lw 3 lc rgb '#c80c0c' title 'second derivative (ann)', \
'ann_opgB.data' using 1:6 with lines lw 3 lc rgb '#940565' title 'integrant (ann)'