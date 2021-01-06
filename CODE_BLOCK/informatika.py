from arduino_function import *
if (arduino_function_version()!="1.2"):
    print("arduino_function have more version!!!")
'''
# №3
nk = 2
no = 90

def etag(n):
    return int((n-1)/8)+1

print(etag(91))

while (no>0):
    nk = 97 - no
    if (etag(nk)==2*no):
        print(no, nk)
    no -= 1
'''

'''
# №4
mas = [1,1,1]

def test(a,b,c):
    if (a==b==c):
        return 0
    if (a*10+b + a*10+c + b*10+c + b*10+a + c*10+a + c*10+b==220):
        return 1
    else:
        return 0

while (mas[0]<10):
    mas[1] = 1
    while (mas[1]<10):
        mas[2] = 1
        while (mas[2]<10):
            if (test(mas[0], mas[1], mas[2])):
                print(mas, sum(mas))
            mas[2] += 1
        mas[1] += 1
    mas[0] += 1
'''

'''
# №5
#((1/(2b+2c)+1/(2a+2c)+1/(2b+2a))/(1/a+b+c))/(a/(2b+2c)+b/(2a+2c)+c/(2b+2a))
mas = [0.01,0.01,0.01]

def test(a,b,c):
    if (abs(a/(2*b+2*c)+b/(2*a+2*c)+c/(2*b+2*a)-1)<0.0000000000001):
        return 1
    else:
        return 0

def test2(a,b,c):
    print((1/(2*b+2*c)+1/(2*a+2*c)+1/(2*b+2*a))/(1/a+b+c))

while (mas[0]<1):
    mas[1] = 0.01
    while (mas[1]<1):
        mas[2] = 0.01
        while (mas[2]<1):
            if (test(mas[0], mas[1], mas[2])):
                #print(mas, sum(mas))
                test2(mas[0], mas[1], mas[2])
            mas[2] += 0.01
        mas[1] += 0.01
    mas[0] += 0.01
'''

# №5
    
i = 5
rez = [1,15]
while (i<=2015):
    #print(rez[0],"/",rez[1],"+",1,"/(",i,"*",(i+2),")")
    rez = fraction(rez[0],rez[1],1,i*(i+2))
    i += 2
#print(rez[0],"/",rez[1],"+",1,"/(",i,"*",(i+2),")")
print(rez)


end_program_time()