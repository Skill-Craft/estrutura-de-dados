class Map:
    def __init__(self, func, iterator):
        self.__iterator = iter(iterator)
        self.__func = func

    def __iter__(self):
        return self

    def __next__(self):
        ret = self.__func(next(self.__iterator))
        return ret
    

a = [i for i in range(10)]
f = lambda x: 2*x

print(list(Map(f,a)))