set terminal svg enhanced size 600,480

# # # # # # # # # # Lake Superior
set title "Ice Concentration Trend for Lake Superior"
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set output "lake1.png"
set terminal pngcairo size 1000,600
set datafile separator ","  

plot '2022-2023gnu.csv' using ( ($2 >= 323 && $2 <= 365) ? $2 - 322 : ($2 + 43) ):3 with lines lc rgb "blue" title '2022-23', \
	 '2021-2022gnu.csv' using ( ($2 >= 330 && $2 <= 365) ? $2 - 329 : ($2 + 36) ):3 with lines lc rgb "red" title '2021-22', \
     '2023-2024gnu.csv' using ( ($2 >= 329 && $2 <= 365) ? $2 - 328 : ($2 + 37) ):3 with lines lc rgb "green" title '2023-24'
    
# # # # # # # # # # Lake Michigan

set title "Ice Concentration Trend for Lake Michigan"
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set output "lake2.png"
set terminal pngcairo size 1000,600
set datafile separator ","  

plot '2022-2023gnu.csv' using ( ($2 >= 323 && $2 <= 365) ? $2 - 322 : ($2 + 43) ):4 with lines lc rgb "blue" title '2022-23', \
   	 '2021-2022gnu.csv' using ( ($2 >= 330 && $2 <= 365) ? $2 - 329 : ($2 + 36) ):4 with lines lc rgb "red" title '2021-22', \
     '2023-2024gnu.csv' using ( ($2 >= 329 && $2 <= 365) ? $2 - 328 : ($2 + 37) ):4 with lines lc rgb "green" title '2023-24'




# # # # # # # # # # Lake Huron

set title "Ice Concentration Trend for Lake Huron"
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set output "lake3.png"
set terminal pngcairo size 1000,600
set datafile separator ","  




plot '2022-2023gnu.csv' using ( ($2 >= 323 && $2 <= 365) ? $2 - 322 : ($2 + 43) ):5 with lines lc rgb "blue" title '2022-23', \
	 '2021-2022gnu.csv' using ( ($2 >= 330 && $2 <= 365) ? $2 - 329 : ($2 + 36) ):5 with lines lc rgb "red" title '2021-22', \
     '2023-2024gnu.csv' using ( ($2 >= 329 && $2 <= 365) ? $2 - 328 : ($2 + 37) ):5 with lines lc rgb "green" title '2023-24'




# # # # # # # # # # Lake Erie

set title "Ice Concentration Trend for Lake Ontario"
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set output "lake4.png"
set terminal pngcairo size 1000,600
set datafile separator ","  

plot '2022-2023gnu.csv' using ( ($2 >= 323 && $2 <= 365) ? $2 - 322 : ($2 + 43) ):6 with lines lc rgb "blue" title '2022-23', \
	 '2021-2022gnu.csv' using ( ($2 >= 330 && $2 <= 365) ? $2 - 329 : ($2 + 36) ):6 with lines lc rgb "red" title '2021-22', \
     '2023-2024gnu.csv' using ( ($2 >= 329 && $2 <= 365) ? $2 - 328 : ($2 + 37) ):6 with lines lc rgb "green" title '2023-24'
    


# # # # # # # # # # Lake Ontario

set title "Ice Concentration Trend for Lake Huron"
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set output "lake5.png"
set terminal pngcairo size 1000,600
set datafile separator ","  

plot '2022-2023gnu.csv' using ( ($2 >= 323 && $2 <= 365) ? $2 - 322 : ($2 + 43) ):7 with lines lc rgb "blue" title '2022-23', \
	 '2021-2022gnu.csv' using ( ($2 >= 330 && $2 <= 365) ? $2 - 329 : ($2 + 36) ):7 with lines lc rgb "red" title '2021-22', \
     '2023-2024gnu.csv' using ( ($2 >= 329 && $2 <= 365) ? $2 - 328 : ($2 + 37) ):7 with lines lc rgb "green" title '2023-24'
    
    
# # # # # # # # # # Lake St.Clair

set title "Ice Concentration Trend for Lake St. Clair"
set xlabel "Day"
set ylabel "Ice Concentration (%)"
set output "lake6.png"
set terminal pngcairo size 1000,600
set datafile separator ","  

plot '2022-2023gnu.csv' using ( ($2 >= 323 && $2 <= 365) ? $2 - 322 : ($2 + 43) ):8 with lines lc rgb "blue" title '2022-23', \
	 '2021-2022gnu.csv' using ( ($2 >= 330 && $2 <= 365) ? $2 - 329 : ($2 + 36) ):8 with lines lc rgb "red" title '2021-22', \
     '2023-2024gnu.csv' using ( ($2 >= 329 && $2 <= 365) ? $2 - 328 : ($2 + 37) ):8 with lines lc rgb "green" title '2023-24'
