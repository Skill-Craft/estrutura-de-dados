class Map:
    def __init__(self, func, iterator):
        self.__iterator = iterator
        self.__func = func

    def __iter__(self):
        self.__n = 0
        return self

    def __next__(self):
        if self.__n == len(self.__iterator):
            raise StopIteration
        ret = self.__func(self.__iterator[self.__n])
        self.__n += 1
        return ret
    

a = [i for i in range(10)]
f = lambda x: 2*x

print(list(Map(f,a)))