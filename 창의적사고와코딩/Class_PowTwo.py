class PowTwo():
    
    def __init__(self,max1=0):
        self.max=max1
        self.n=0
        
    def __iter__(self):
        return self
    
    def __next__(self):
        if self.n <= self.max:
            result = 2**self.n
            self.n+=1
            return result
        else:
            raise StopIteration
