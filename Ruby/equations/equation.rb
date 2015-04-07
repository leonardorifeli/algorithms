require 'sinatra'
require "gnuplot"

# @author leonardorifeli@gmail.com - leonardorifeli.com
# More informations forum.leonardorifeli.com

class CalculatorEquation

    # value of A in equation ax²+bx+c
    attr_accessor :valueA

    # value of B in equation ax²+bx+c
    attr_accessor :valueB

    # value of C in equation ax²+bx+c
    attr_accessor :valueC

    # value of delta
    attr_accessor :difference

    # value of primary result of X in equation ax²+bx+c
    attr_accessor :primaryResultX

    # value of secundary result of X in equation ax²+bx+c
    attr_accessor :secundaryResultX

    def initialize(a, b, c)
        @valueA = a
        @valueB = b
        @valueC = c
    end

    def calculatorDifference
        # difference = bˆ2-4.a.c
        result = (@valueB*@valueB)-(4*@valueA*@valueC)
        @difference = result
    end

    def calculatorValuesX
        # x = ((-b)+-(Vdifferent))/2*a

        if @difference >= 0
            difference = Math.sqrt(@difference)

            primaryResult = ((-(@valueB))+(difference))/(2*@valueA)

            secundaryResult = ((-(@valueB))-(difference))/(2*@valueA)

            ["Primary square root: #{primaryResult}", "Secundary square root: #{secundaryResult}"]
        else
            error = "This difference doesn`t exist in real numbers."
            [error]
        end
    end

    def calculate
        self.calculatorDifference
        self.calculatorValuesX
    end

end

get '/equation' do

    Gnuplot.open do |gp|
        Gnuplot::Plot.new( gp ) do |plot|

            plot.title  "Array Plot Example"
            plot.ylabel "x^2"
            plot.xlabel "x"

            x = (0..50).collect { |v| v.to_f }
            y = x.collect { |v| v ** 2 }

            plot.data << Gnuplot::DataSet.new( [x, y] ) do |ds|
                ds.with = "linespoints"
                ds.notitle
            end
        end
    end
    
    a = params[:a].to_i
    b = params[:b].to_i
    c = params[:c].to_i

    if a == 0
        "Please, the value of (a) is != 0"
    else
        calculate = "Calculating the equation #{a}x²+#{b}x+#{c}=0"

        equation = CalculatorEquation.new a, b, c

        "#{calculate}: <br/> #{equation.calculate}"
    end

end
