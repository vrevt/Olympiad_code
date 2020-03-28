from itertools import combinations as comb
from sys import exit
 
 
def answer(ans=0):
	if ans:
		print("YES")
		print(ans)
	else:
		print("NO")
	exit()
 
 
def good(tpl):
	x=tpl[0]
	y=tpl[1]
	z=tpl[2]
	if x<y+z and y<x+z and z<x+y:
		return True
	else:
		return False
 
 
 
 
z=input()
z=input()
z=z.split(' ')
i=0
while i<len(z):
	z[i]=int(z[i])
	i+=1
z.sort()
 
 
i=len(z)-6
while i>=0:
	qq=z[i:i+6]
	q=list(comb(qq,3))
	l=0
	r=len(q)-1
	while l<r:
		if good(q[l]) and good(q[r]):
			answer(sum(qq))
		l+=1
		r-=1
	i-=1
 
 
p1=0
i=len(z)-3
while i>=0:
	q=z[i:i+3]
	if good(q):
		p1=i
		break
	i-=1
 
 
if p1:
	p2=0
	i-=3
	while i>=0:
		q=z[i:i+3]
		if good(q):
			p2=i
			break
		i-=1
 
	if p2:
		answer(sum(z[p1:p1+3])+sum(z[p2:p2+3]))
	else:
		answer()
else:
	answer()
 
