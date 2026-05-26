set terminal pdfcairo enhanced color font "Times,12" size 6in,4in
set output "higgs.pdf"

set xlabel "Energy E [GeV]"
set ylabel "Signal"
set title "Higgs Breit-Wigner fit"

set grid

plot \
    "higgsdata.txt" using 1:2:3 with yerrorbars lc rgb '#d77f21' title "data", \
    "higgs_fit.dat" using 1:2 with lines lw 2 lc rgb '#6a0dad'  title "fit"