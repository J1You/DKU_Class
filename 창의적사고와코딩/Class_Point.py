class Point:
        def __init__(self, x =0, y =0):
                self.x = x
                self.y = y
                
        #Point 객체 끼리 + 연산을 정의
        def __add__(self, other):
            x = self.x + other.x
            y = self.y + other.y
            return Point(x,y)

    #Pont 객체를 문자열로 표현하여 반환
        def __str__(self):
            return 'Point('+str(self.x)+', '+str(self.y)+')'
            #return '({}, {})'.format(self.x, self.y)

p1 = Point(1, 2)
p2 = Point(3, 4)
print(p1+p2)
