class Vehicle:
    def __init__(self, name):
        self.name = name
        
    def drive(self):
        raise NotImplementedError("이것은 추상메소드입니다. ")

    def stop(self):
        raise NotImplementedError("이것은 추상메소드입니다. ")

class Car(Vehicle):
    def drive(self):
        return '승용차를 운전합니다. '

    def stop(self):
        return '승용차를 정지합니다. '


class Truck(Vehicle):
    def drive(self):
        return '트럭을 운전합니다. '

    def stop(self):
        return '트럭을 정지합니다. '

cars = [Truck('truck1'), Truck('truck2'), Car('car1')]

for car in cars:
    print( car.name + ':' + car.drive())
