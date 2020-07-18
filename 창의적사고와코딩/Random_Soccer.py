import random

options =["왼쪽", "중앙", "오른쪽"]
c_choice = random.choice(options)
u_choice = input("어디를 공격하시겠어요?(왼쪽, 중앙, 오른쪽) ")

if c_choice == u_choice:
    print("사용자는 %s를 공격하였고, 컴퓨터는 %s를 막아 수비에 성공하였습니다." %(u_choice, c_choice))
else:
    print("사용자는 %s를 공격하였고, 컴퓨터는 %s를 막아 패널티킥을 성공하였습니다." %(u_choice, c_choice))
