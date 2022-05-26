import math
n=int(input())
 
l=1
r=10**5000
while l<r:
    c=(l+r+1)//2
    if c*c>n:
        r=c-1
    else:
        l=c
kol=l
 
n-=kol*kol
 
if n==0:
    print(1)
elif n<=kol+1: 
    print(n) 
else: 
    print(kol+1 - (n-kol-1))
 
 
 
