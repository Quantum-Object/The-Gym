import math

c=0
for i in range(1,1000):
    s=str(i)
    c+=s.count('9')
print (c)
c=0
for i in range(3,0,-1):
    c+=i*math.comb(3,i)*(9)**(3-i)
print(c)
#  so to count 1 what do we do?
# we have 1xx or  x1x or xx1 but this have and yes 
# so sum=(3C1)*(9)^2 + 2*(3C2)(9) + 3*3C3 