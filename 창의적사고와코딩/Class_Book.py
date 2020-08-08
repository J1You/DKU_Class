class Book:
    def __init__(self, title='', pages=0):
        self.title = title
        self.pages = pages


    def __add__(self, other):
        return self.pages + other.pages

    def __str__(self):
        return self.title

book1 = Book('자료구조', 600)
book2 = Book('C언어', 700)
print(book1+book2)
