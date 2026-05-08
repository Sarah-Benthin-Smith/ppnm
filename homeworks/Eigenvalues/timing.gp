set terminal pdfcairo enhanced font "Times,12" size 10cm,7cm
set output 'fig_timing.pdf'

set xlabel "n (matrix size)"
set ylabel "time"
set grid lw 1 dt 2
set key box

set samples 500   # smoother analytic curve

f(x) = a*x**b
fit f(x) "timing.dat" using 1:2 via a,b

plot "timing.dat" using 1:2 with lines lw 2 lc rgb "#6A0DAD" title "Data", \
     f(x) with lines lw 2 lc rgb "#e67c22" title sprintf("Fit: %.3f x^{%.3f}", a, b)
