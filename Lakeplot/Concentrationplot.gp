# # # # # # # # # # # # # # # # # # # #
set datafile separator ","
set title "Daily Ice Concentration % 2023 & 2024"
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set key outside
set grid
set terminal pngcairo size 1000,600
set output "combined_ice_plot.png"

# Note: "every ::1" skips the header row.
plot "cleaned_termproject.csv" every ::1 using 10:3 with lines linecolor rgb "red" lw 2 title "SUP", \
     "cleaned_termproject.csv" every ::1 using 10:4 with lines linecolor rgb "blue" lw 2 title "MICH", \
     "cleaned_termproject.csv" every ::1 using 10:5 with lines linecolor rgb "green" lw 2 title "HUR", \
     "cleaned_termproject.csv" every ::1 using 10:6 with lines linecolor rgb "magenta" lw 2 title "ERIE", \
     "cleaned_termproject.csv" every ::1 using 10:7 with lines linecolor rgb "cyan" lw 2 title "ONT", \
     "cleaned_termproject.csv" every ::1 using 10:8 with lines linecolor rgb "orange" lw 2 title "STC"

unset output
reset

# # # # # # # # # # # # # # # # # # # #

# # # # # # # # # # Superior Plot
set datafile separator ","
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set terminal pngcairo size 1000,600
set output "superior.png"
set title "Ice Coverage: Superior"
plot "cleaned_termproject.csv" every ::1 using 10:3 with lines linecolor rgb "red" lw 2 title "Superior"
unset output
reset

# # # # # # # # # # Michigan Plot
set datafile separator ","
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set terminal pngcairo size 1000,600
set output "michigan.png"
set title "Ice Coverage: Michigan"
plot "cleaned_termproject.csv" every ::1 using 10:4 with lines linecolor rgb "blue" lw 2 title "Michigan"
unset output
reset

# # # # # # # # # # Huron Plot
set datafile separator ","
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set terminal pngcairo size 1000,600
set output "huron.png"
set title "Ice Coverage: Huron"
plot "cleaned_termproject.csv" every ::1 using 10:5 with lines linecolor rgb "green" lw 2 title "Huron"
unset output
reset

# # # # # # # # # # Erie Plot
set datafile separator ","
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set terminal pngcairo size 1000,600
set output "erie.png"
set title "Ice Coverage: Erie"
plot "cleaned_termproject.csv" every ::1 using 10:6 with lines linecolor rgb "magenta" lw 2 title "Erie"
unset output
reset

# # # # # # # # # #Ontario Plot
set datafile separator ","
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set terminal pngcairo size 1000,600
set output "ontario.png"
set title "Ice Coverage: Ontario"
plot "cleaned_termproject.csv" every ::1 using 10:7 with lines linecolor rgb "cyan" lw 2 title "Ontario"
unset output
reset

# # # # # # # # # #St Clair Plot
set datafile separator ","
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set terminal pngcairo size 1000,600
set output "stclair.png"
set title "Ice Coverage: St Clair"
plot "cleaned_termproject.csv" every ::1 using 10:8 with lines linecolor rgb "orange" lw 2 title "St Clair"
unset output
reset
