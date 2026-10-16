#===========================================================
# Plot Fibonacci numbers for Analysis Exercise 0.
# Writes directly to pdf files. Change display
# to on-screen by calling with:
# 
#    gnuplot -e "on_screen=1" fibonacci_project.gp
#
#===========================================================

# Output on screen?
if (exists("on_screen")){
 print "plotting on screen";
}
else{
 print "plotting directly to pdf";
}


# Switch to pdf output
if (!exists("on_screen")){
   set term pdf enhanced
   set output ".dummy.pdf"
}


# Set label for x axis and change font size to 20 (keeping the font itself)
set xlabel "n" font ",20"

# Set label for y axis and change font size to 20 (keeping the font itself)
# Apply offset otherwise label overlaps with numbers.
set ylabel "Fibonacci number" font ",20" offset -3

# Change font size for axis numbers to 20 (keeping the font itself)
set tics font ", 20"

# Change font size for legend to 15 (keeping the font itself)
set key font ",15"

# Offset in the order left, right, top, bottom
set offset graph 0.1, graph 0.1, graph 0.3, graph 0.0

# Shift left margin of plot so the axis label doesn't fall off the plotting area
set lmargin 12


# First plot
plot "fibonacci.dat" u 1:2  w linesp pt 7 ps 1 title "Fibonacci sequence by iteration"
if (!exists("on_screen")){
   set output "fibonacci.pdf"
   replot
   set output ".dummy.pdf"
}
else{
   pause -1 "done 1"
}

# Second plot
replot "fibonacci.dat" u 1:3  w linesp pt 19 ps 2 title "Explicit expression for Fibonacci number"
if (!exists("on_screen")){
   set output "fibonacci_validation.pdf"
   replot
   set output ".dummy.pdf"
}
else{
   pause -1 "done 2"
}

# Cleanup
if (!exists("on_screen")){
   system "rm .dummy.pdf"
}