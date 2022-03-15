a = input().split()
print(len(a))
b = ""
for i in range (len(a)):
    b+=str(a[i])
    b+=" "
print(b)