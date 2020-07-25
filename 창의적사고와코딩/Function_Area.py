def calculate_area(radious):
    global area
    area=3.14 * r**2
    return area

area=0
r=float(input("원의 반지름: "))
calculate_area(r)
print(area)
