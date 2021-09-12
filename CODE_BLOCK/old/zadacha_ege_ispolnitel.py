S = ""

for i in range (2019):
    S += str(1)
for i in range (2119):
    S += str(3)
    
while "11" in S:
    S = S.replace("11", "2", 1)
    S = S.replace("22", "3", 1)
    S = S.replace("33", "1", 1)
    
print(S)