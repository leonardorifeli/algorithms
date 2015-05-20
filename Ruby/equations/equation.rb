require 'sinatra'
require 'google_chart'

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
        @valueA = a.to_i
        @valueB = b.to_i
        @valueC = c.to_i
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

            @primaryResult = ((-(@valueB))+(difference))/(2*@valueA)

            @secundaryResult = ((-(@valueB))-(difference))/(2*@valueA)

            ["Primary square root: #{@primaryResult}", "Secundary square root: #{@secundaryResult}"]
        else
            error = "This difference doesn`t exist in real numbers."
            [error]
        end
    end

    def differente
        @difference
    end

    def getA
        @valueA
    end

    def getB
        @valueB
    end

    def getC
        @valueC
    end

    def getPrimaryResult
        @primaryResult
    end

    def getSecundaryResult
        @secundaryResult
    end

    def calculate
        self.calculatorDifference
        self.calculatorValuesX
    end

end

get '/equation' do
    if params[:a].to_i == 0
        "Please, the value of (a) is != 0"
    else

        equation = CalculatorEquation.new params[:a], params[:b], params[:c]

        equationResolution = equation.calculate


        "Calculated: #{equationResolution}"

    end

end
