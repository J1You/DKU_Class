def cal_1(r):
    area=3.14 * r**2
    return area

def get_sum(start, end):
    sum1=0
    for i in range(start,end+1):
        sum1=sum1+i
    return sum1

#x=get_sum(0,10)
#print("10까지의 누적합은 %s입니다")

s=int(input("누적합을 구할 시작값: "))
e=int(input("누적합을 구할 종료값: "))

a=get_sum(s,e)
print("%s부터 %s까지의 누적합은 %s입니다" %(s,e,a))

