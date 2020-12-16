'''
Rahul is playing a game known as skipping stones. In this game, in order to reach the end he can either jump past 1 stone or 2 stones at a time. 
He enjoyed playing the game but wonders in how many ways can he reach to the Nth step. Please help Rahul in finding the answer to this problem.

Input Format:
The first line containing Q, denoting the number of queries to answered.
Each of the next Qi, lines denote the value of Nth stone.

Output:
Print Q lines, each containing the value of ith query on a single line. If the answer is greater than 32 bit integer output it modulo 10^9+7.

Constraints:
1 <= Q <= 1000
The value of N in each query can go upto 1000.


Example:
Input:
2
1
4
Output:
1
5
'''
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
