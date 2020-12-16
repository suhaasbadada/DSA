def findStep(n) : 
    res=[0]*(n+2) 
    res[0] = 1
    res[1] = 1
    res[2] = 2
    for i in range(2, n + 1) : 
        res[i] = res[i - 1] + res[i - 2] 
      
    return res[n] 

modulo=10**9+7

t=int(input())
for i in range(t):
    steps=int(input())
    print(findStep(steps)%modulo)
