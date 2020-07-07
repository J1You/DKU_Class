import time
now=time.time()
thisYear=int(1970+now//(365*24*3600))
print("올해는 %s년입니다"%thisYear)
age=int(input("몇살이신지요? "))

print("2050년에는 %s살 이시군요."%(age+2050-thisYear))
