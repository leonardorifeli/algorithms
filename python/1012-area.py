A, B, C = raw_input().split(" ")
A = float(A)
B = float(B)
C = float(C)
PI = 3.14159

TRI = (A*C) / 2
CIR = (C ** 2)*PI
TRA = ((A+B)*C) / 2
QUA = B*B
RET = A*B

print "TRIANGULO: %.3lf" % (TRI)
print "CIRCULO: %.3lf" % (CIR)
print "TRAPEZIO: %.3lf" % (TRA)
print "QUADRADO: %.3lf" % (QUA)
print "RETANGULO: %.3lf" % (RET)