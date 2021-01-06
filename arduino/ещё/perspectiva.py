print("Привет, я простой эхо-бот, скажи простой пример и я его решу")
print("Введите пустую строку и мы закончим!")

def number(n):
    if   (n=='0'):
        return 0
    elif (n=='1'):
        return 1
    elif (n=='2'):
        return 2
    elif (n=='3'):
        return 3 
    elif (n=='4'):
        return 4 
    elif (n=='5'):
        return 5 
    elif (n=='6'):
        return 6
    elif (n=='7'):
        return 7
    elif (n=='8'):
        return 8
    elif (n=='9'):
        return 9
    else:
        return -1
    
def sumbol(i):
    if (i=='*' or i=='/' or i=='+' or i=='-' or i=='^'):
        return 1
    else:
        return 0

while (1):
    S = input("введите пример: ")
    if (S==""):
        break;
    else:
        i = 0
        flag = 1
        flag_a = 0
        flag_b = 0
        a = 0
        b = 0
        S = str(S)
        S = list(S)
        S.append(' ')
        S.append(' ')
        S.append(' ')
        S.append('|')
        S.append('|')
        while(number(S[i])==-1 and S[i]!='-' and i+1<len(S)):
            i += 1
        if (i<len(S)):
            if (S[i]=='-'):
                flag = -1
                i += 1
            while(number(S[i])!=-1):
                a = a*10 + number(S[i])
                i += 1
                flag_a = 1
            a *= flag
            #print (a)
            while(number(S[i])==-1 and (not sumbol(S[i])) and i+1<len(S)):
                i += 1
            if (i+1<len(S) and sumbol(S[i])):
                znak = S[i]
                i += 1
                #print(znak)
                b = 0
                while(number(S[i])==-1 and S[i]!='-' and i+1<len(S)):
                    i += 1
                if (i<len(S)):
                    if (S[i]=='-'):
                        flag = -1
                        i += 1
                    while(number(S[i])!=-1):
                        b = b*10 + number(S[i])
                        i += 1
                        flag_b = 1
                    b *= flag
                    #print (b)
                    if (flag_a and flag_b):
                        if   (znak=='+'):
                            print("ваш ответ:", a+b)
                        elif (znak=='-'):
                            print("ваш ответ:", a-b)
                        elif (znak=='*'):
                            print("ваш ответ:", a*b)
                        elif (znak=='/'):
                            if (b==0):
                                print("я не умею делить на 0 :(")
                            else:
                                print("ваш ответ:", a/b)
                        elif (znak=='^'):
                            print("ваш ответ:", a**b)
                        else:
                            print("я не понимаю вашего примера :(")
                    else:
                        print("я не понимаю вашего примера :(")
            else:
                print("я не понимаю вашего примера :(")
        else:
            print("я не понимаю вашего примера :(")
            
    
print("Пока :)")