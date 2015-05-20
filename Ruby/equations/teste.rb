require 'rubygems'
require 'google_chart'

# Pie Chart
GoogleChart::PieChart.new('320x200', "Pie Chart",false) do |pc|
    pc.data "Apples", 40
    pc.data "Banana", 20
    pc.data "Peach", 30
    pc.data "Orange", 60
    #puts "\nPie Chart"
    #puts pc.to_url

    # Pie Chart with no labels
    pc.show_labels = false
    #puts "\nPie Chart (with no labels)"
    #puts pc.to_url
end

# Line Chart
GoogleChart::LineChart.new('320x200', "Line Chart", false) do |lc|
    lc.data "Trend 1", [5,4,3,1,3,5,6], '0000ff'
    lc.show_legend = true
    lc.data "Trend 2", [1,2,3,4,5,6], '00ff00'
    lc.data "Trend 3", [6,5,4,3,2,1], 'ff0000'
    lc.axis :y, :range => [0,6], :color => 'ff00ff', :font_size => 16, :alignment => :center
    lc.axis :x, :range => [0,6], :color => '00ffff', :font_size => 16, :alignment => :center
    lc.grid :x_step => 100.0/6.0, :y_step => 100.0/6.0, :length_segment => 1, :length_blank => 0
    #puts "\nLine Chart"
    puts lc.to_url
end

# Bar Chart
GoogleChart::BarChart.new('800x200', "Bar Chart", :vertical, false) do |bc|
    bc.data "Trend 1", [5,4,3,1,3,5], '0000ff'
    bc.data "Trend 2", [1,2,3,4,5,6], 'ff0000'
    bc.data "Trend 3", [6,5,4,4,5,6], '00ff00'
    #puts "\nBar Chart"
    #puts bc.to_url
end

# Line XY Chart
line_chart_xy = GoogleChart::LineChart.new('320x200', "Line XY Chart", true) do |lcxy|
    lcxy.data "Trend 1", [[1,1], [2,2], [3,3], [4,4]], '0000ff'
    lcxy.data "Trend 2", [[4,5], [2,2], [1,1], [3,4]], '00ff00'
    #puts "\nLine XY Chart (inside a block)"
    #puts lcxy.to_url
end

# Venn Diagram
# Supply three vd.data statements of label, size, color for circles A, B, C
# Then, an :intersections with four values:
# the first value specifies the area of A intersecting B
# the second value specifies the area of B intersecting C
# the third value specifies the area of C intersecting A
# the fourth value specifies the area of A intersecting B intersecting C
GoogleChart::VennDiagram.new("320x200", 'Venn Diagram') do |vd|
    vd.data "Blue", 100, '0000ff'
    vd.data "Green", 80, '00ff00'
    vd.data "Red",   60, 'ff0000'
    vd.intersections 30,30,30,10
    #puts "\nVenn Diagram"
    #puts vd.to_url
end

# Scatter Chart
GoogleChart::ScatterChart.new('320x200',"Scatter Chart") do |sc|
    sc.data "Scatter Set", [[1,1,], [2,2], [3,3], [4,4]]
    sc.max_value [5,5] # Setting the max value
    sc.axis :x, :range => [0,5]
    sc.axis :y, :range => [0,5], :labels => [0,1,2,3,4,5]
    sc.point_sizes [10,15,30,55] # Optional
    #puts "\nScatter Chart"
    #puts sc.to_url
end

GoogleChart::LineChart.new('320x200', "Line Chart", false) do |lc|
    lc.data "Trend 1", [5,4,3,1,3,5,6], '0000ff'
    lc.show_legend = true
    lc.data "Trend 2", [1,2,3,4,5,6], '00ff00'
    lc.data "Trend 3", [6,5,4,3,2,1], 'ff0000'
    lc.axis :y, :range => [0,6], :color => 'ff00ff', :font_size => 16, :alignment => :center
    lc.axis :x, :range => [0,6], :color => '00ffff', :font_size => 16, :alignment => :center
    lc.grid :x_step => 100.0/6.0, :y_step => 100.0/6.0, :length_segment => 1, :length_blank => 0
    #puts "\nLine Chart"
end

# Solid fill
line_chart_xy.fill(:background, :solid, {:color => 'fff2cc'})
line_chart_xy.fill(:chart, :solid, {:color => 'ffcccc'})
#puts "\nLine Chart with Solid Fill"
#puts line_chart_xy.to_url

# Gradient fill
line_chart_xy.fill :background, :gradient, :angle => 0,  :color => [['76A4FB',1],['ffffff',0]]
line_chart_xy.fill :chart, :gradient, :angle => 0, :color => [['76A4FB',1], ['ffffff',0]]
#puts "\nLine Chart with Gradient Fill"
#puts line_chart_xy.to_url

# Stripes Fill
line_chart_xy.fill :chart, :stripes, :angle => 90, :color => [['76A4FB',0.2], ['ffffff',0.2]]
#puts "\nLine Chart with Stripes Fill"
#puts line_chart_xy.to_url

#puts "\nLine Chart with range markers and shape markers"
GoogleChart::LineChart.new('320x200', "Line Chart", false) do |lc|
    lc.title_color = 'ff00ff'
    lc.data "Trend 1", [5,4,3,1,3,5,6], '0000ff'
    lc.data "Trend 2", [1,2,3,4,5,6], '00ff00'
    lc.data "Trend 3", [6,5,4,3,2,1], 'ff0000'
    lc.max_value 10 # Setting max value for simple line chart
    lc.range_marker :horizontal, :color => 'E5ECF9', :start_point => 0.1, :end_point => 0.5
    lc.range_marker :vertical, :color => 'a0bae9', :start_point => 0.1, :end_point => 0.5
    # Draw an arrow shape marker against lowest value in dataset
    lc.shape_marker :arrow, :color => '000000', :data_set_index => 0, :data_point_index => 3, :pixel_size => 10
    #puts lc.to_url
end
