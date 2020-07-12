n = int(input("score 를 입력하세요: "))

if n >= 90:
    print("A학점")
elif n >= 80: # 80 <= s < 90
    print("B학점")
elif n >= 70: # 70 <- s < 80
    print("C학점")
else: # n < 70
    print("D학점")
