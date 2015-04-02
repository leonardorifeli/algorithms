#!/usr/bin/env ruby

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

    def initialize
        puts "This algorithm is for calculate the equation: ax²+bx+c=0 | a != 0;"
    end

    def setValueA(value)
        @valueA = value
    end

    def setValueB(value)
        @valueB = value
    end

    def setValueC(value)
        @valueC = value
    end

    def calculatorDifference
        result = (@valueB*@valueB)-(4*@valueA*@valueC)
        @difference = result
    end

    def calculatorValuesX
        # x = ((-b)+-(Vdifferent))/2*a

        if @difference >= 0
            difference = Math.sqrt(@difference)

            primaryResult = ((-(@valueB))+(difference))/(2*@valueA)
            puts "Primary square root: #{primaryResult}"

            secundaryResult = ((-(@valueB))-(difference))/(2*@valueA)
            puts "Secundary square root: #{secundaryResult}"
        else
            puts "This difference doesn`t exist in real numbers. Im stoped.!!!!! hahahaha"
        end
    end

    def result
        equation = "#{@valueA}x²+#{@valueB}x+#{@valueC}=0"
        puts "Result of equation: #{equation}"
    end

end

equation = CalculatorEquation.new

puts "A) Please, key press the value of (a) the equation ax²+bx+c:"
a = gets
equation.setValueA(Integer(a))

puts "B) Please, key press the value of (b) the equation ax²+bx+c:"
b = gets
equation.setValueB(Integer(b))

puts "C) Please, key press the value of (c) the equation ax²+bx+c:"
c = gets
equation.setValueC(Integer(c))

equation.calculatorDifference()
equation.result()
equation.calculatorValuesX()
