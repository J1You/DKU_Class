import random

guess = -1
tries = 0
ans = random.randint(1,100)

print("1부터 100사이의 숫자를 맞추시오")

while True:
    guess =int(input("숫자를 입력하시오: "))
    tries=tries+1
    if guess<answer:
        print("낮음!")
    else:
        print("높음!")
    tries=tries+1

print("축하합니다. 정답은 %s 시도횟수 = %s"%(ans,tries))
