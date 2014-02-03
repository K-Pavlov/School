require_relative "bar_char_td/chart_drawer.rb"

d = Drawer.new "chart.svg", 500,500
d.start

chart_drawer = ChartDrawer.new d
array_of_values = CSV.read("bar_char_td/data.csv")

chart_drawer.columns_chart array_of_values

d.finish
