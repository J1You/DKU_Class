import random

time = random.randint(1, 24)
print("안녕하세요! 지금 시각은 " + str(time) + "시 입니다.")
#print("안녕하세요! 지금 시각은 %s시 입니다." %time)
sunny = random.choice([True, False])

if sunny : # if (sunny ==True)
    print ("현재 날씨가 화창합니다. ")
else:
    print ("현재 날씨가 화창하지 않습니다. ")

#종달새가 노래를 할 것인지를 판단.

if time >= 6 and time < 9 and sunny: # 6 <= time < 9 and sunny
     print("종달새가 노래를 한다. 지지배배지지배배")
else :
    print("종달새가 노래를 하지 않는다.")
