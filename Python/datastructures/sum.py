class Accumulator:
    def __init__(self, iterator, func= lambda x: x):
        self.__iterator = iterator
        self.__func = func
        self.__sum = 0

    def __iter__(self):
        self.__n = 0
        return self
    
    def __next__(self):
        if self.__n == len(self.__iterator):
            raise StopIteration
        self.__sum += self.__func(self.__iterator[self.__n])
        self.__n +=1
        return self.__sum
    

def Sum(iterator, func=lambda x:x):
    acc = Accumulator(iterator, func)
    return list(acc)[-1]
    


a = [i for i in range(11)]
print(Sum(a))

