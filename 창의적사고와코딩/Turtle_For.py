import turtle
t=turtle.Turtle("turtle")

a=int(input("몇각형을 그리시겠습니까?: "))

for i in range(a): #range(0,n,1)
    t.fd(100)
    t.lt(360/a)
