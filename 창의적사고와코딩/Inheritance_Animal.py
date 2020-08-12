class Animal:
    def __init__(self, name):
        self.name = name
    def speak(self):
        return '알 수 없음'

class Dog(Animal):
    def speak(self):
        return '멍멍!'

class Cat(Animal):
    def speak(self):
        return '야옹!'


animalList = [Dog('dog1'), Dog('dog2'), Cat('cat1')]

for a in animalList: # a는 Animal을 상속받아 생성된 객체
    print (a.name + ': ' + a.speak()) #a.name, a.speak 사용 가능
