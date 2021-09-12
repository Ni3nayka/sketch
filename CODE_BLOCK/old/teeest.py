
def f(a):
    if (a>10): return
    print(a)
    f(a+1)
    f(a+2)

def summa(a,b):
    return a + b

qwerty = summa(2,5)
print(qwerty)