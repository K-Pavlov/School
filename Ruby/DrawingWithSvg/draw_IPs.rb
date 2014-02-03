require_relative "IPs/CSVToGraph"

my_drawer = CsvToGraph.new "IPs/SomeIps.csv", "IPs.svg", 500, 350 
my_drawer.draw_everything
