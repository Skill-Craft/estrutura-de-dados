class Filter:
    def __init__(self, func, iterator):
        self.func = func
        self.iterator = iterator
        self.new = []
        # self.min = min(len(iterator for iterator in iterators))

    def __iter__(self):
        self.n = 0
        return self
    
    def __next__(self):
        while True:
            self.n+=1
            if self.n > len(self.iterator):
                raise StopIteration
            if self.func(d:=self.iterator[self.n-1]):
                self.new.append(d)
                return d

    def __list__(self):
        return self.new

a = [i%2 for i in range(6)]
f = Filter(lambda x: bool(x), a)
print(list(f))