require 'csv'
require 'open3'

data = CSV.read("data.csv", {:col_sep => "\t"})
data.collect! { |item| item[4].to_f} # extract a field value and parse to float
data.shift # removes the header

gnuplot_commands = <<"End"
set terminal png
set output "plot.png"
set xrange [0:#{data.size}]
plot "-" with points
End
data.each_with_index do |y, x|
    gnuplot_commands << x.to_s + " " + y.to_s + "\n"
end
gnuplot_commands << "e\n"

image, s = Open3.capture2(
"gnuplot",
:stdin_data=>gnuplot_commands, :binmode=>true)
