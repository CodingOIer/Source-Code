import decimal

decimal.setcontext(decimal.Context(prec=int(3e6), Emax=int(3e6), Emin=0))

a = input()
b = input()

x = decimal.Decimal(a)
y = decimal.Decimal(b)

print(x * y)
