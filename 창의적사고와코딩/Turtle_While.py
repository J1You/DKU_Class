import turtle
t=turtle.Turtle("turtle")
a=int(input("몇각형을 그리시겠습니까?: "))
i=0
while i<a:
    t.fd(100)
    t.lt(360/a)
    i=i+1
