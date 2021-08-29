# 대실 예약 프로그램

import time
today=time.localtime()

room1=[i for i in range(max(today.tm_hour+1,9),24)]
people_s={}
people_e={}

while (1):
    
    a=input("(1. 예약하기, 2. 예약취소 3: 예약 가능시간 확인하기, 4: 남은 이용시간 확인하기, 5: 프로그램 종료)\n입력: ")
    
    if a=='1':
        print("%d월 %d일 운영시간은 9시 부터 24시 입니다.\n"%(today.tm_mon,today.tm_mday))
        
        name=input("예약자 이름: ")
        starttime=int(input("이용 시작 시간: "))
        endtime=int(input("이용 종료 시간: "))
        if(starttime<today.tm_hour+1 or endtime>24):
            print("예약가능한 시간이 아닙니다.\n")
            continue
        
        usingtime=[i for i in range (starttime,endtime)]
        false=0
        for t in usingtime:
            if t not in room1:
                false=1
                break
        
        if false ==0:
            for j in usingtime:
                room1.remove(j)
            people_s[name]=starttime
            people_e[name]=endtime
            print("%s님, %d시 - %d시 예약 완료되었습니다.\n"% (name,starttime,endtime))
        else:
            print("해당시간은 예약 차있습니다. 예약 가능 시간을 확인하세요.")
            print(room1,"\n"
                  )
            
    if a=='2':
        n=input("예약자 이름: ")
        if n in people_s:
            for i in range (people_s[n],people_e[n]):
                room1.append(i)
            room1.sort()
            print("%d - %d 시 예약이 취소되었습니다.\n"%(people_s[n],people_e[n]))
            del people_s[n]
            del people_e[n]
            
        else:
            print("이미 취소되었거나 예약이 존재하지 않습니다.\n")
            
    if a=='3':
        print("예약 가능한 시간입니다.")
        print(room1,"\n")
        
    if a=='4':
        now=time.localtime()
        n=input("예약자 이름: ")
        if n not in people_e:
            print("확인된 예약이 없습니다.\n")
            continue
        
        if now.tm_hour>=people_e[n]:
            print("예약시간이 종료되었습니다.\n")
        elif now.tm_hour<people_s[n]:
            print("아직 예약시간이 되지 않았습니다.\n")
            
        else:
            print("예약확인: %d시 - %d시"%(people_s[n],people_e[n]))
            if now.tm_min==0:
                print("남은 이용시간: %2d시간 00분\n"%(people_e[n]-now.tm_hour))
            else:
                print("남은 이용시간: %2d시간 %2s분\n"%(people[n]-1-now.tm_hour, 60-now.tm_min))
                
    if a=='5':
        print("프로그램 종료합니다.")
        break
        
        
        
    
