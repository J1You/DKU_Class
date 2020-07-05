a=int(input("투입한 돈: "))
b=int(input("물건값: "))

c=a-b
d=c//500
n=c%500
e=n//100
n=n%100
f=n//50
n=n%50
g=n//10

print("거스름돈:",c)
print("500원 동전의 개수:",d)
print("100원 동전의 개수:",e)
print("50원 동전의 개수:",f)
print("10원 동전의 개수:",g)
