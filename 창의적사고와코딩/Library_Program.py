# 도서 대출 프로그램

booklist={'해리포터':5,'반지의 제왕':5,'정의란 무엇인가':5,'피터팬':5,'신데렐라':5}
people={}

class Book:
    
    def __init__ (self,name):
        self.name=name
        
    def NewBook(self,title,num):
        self.title=title
        self.num=num
        if title in booklist:
            booklist[title]+=num
        else:
            booklist[title]=num
    
    def SetBook(self,title):
        self.title=title
        booklist[self.title] += 1
        people[self.name].remove(self.title)
        
    def GetBook(self,title):
        self.title=title
        booklist[self.title] -= 1
        people[self.name].append(self.title)
    

while 1:
        
    name=input("사용자 이름: ")
    if name not in people:
        people[name]=[]
        
    book=Book(name)
    
    n=input("(1. 대출, 2. 반납, 3. 새로운 도서 등록, 4. 나의 대출 현황, 5. 도서 검색, 6. 프로그램 종료)\n입력:")
    if n=='1':
        title=input("대출할 도서 제목: ")
        if title not in booklist:
            print("해당 도서가 존재하지 않습니다. 도서 검색을 해보세요\n")
            continue
        if booklist[title]==0:
            print("해당 도서는 모두 대출중 입니다.\n")
            continue
        
        book.GetBook(title)
        print("대출 완료되었습니다.\n")

    if n=='2':
        title=input("반납할 도서 제목: ")
        
        if title in people[name]:
            book.SetBook(title)
            print("반납 완료되었습니다.\n")
        
        else:
            print("해당 도서를 대출한 기록이 없습니다.\n")
            

    if n=='3':
        if name=='관리자': 
            title=input("새로운 도서 제목: ")
            number=int(input("도서 개수: "))
            book.NewBook(title, number)
            print("도서 등록 완료되었습니다.\n")
        else:
            print("도서 등록 권한이 없습니다.\n")

    if n=='4':
        print("%s님의 도서 대출 현황입니다. "%name)
        print(people[name],"\n")

    if n=='5':
        title=input("검색할 도서 제목: ")
        
        print("검색하신 도서 '%s' 보유개수: %s\n"%(title,booklist.get(title,"없음")))

    if n=='6':
        print("프로그램 종료\n")
        break

    
