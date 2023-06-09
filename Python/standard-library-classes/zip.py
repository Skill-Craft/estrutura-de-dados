from typing import Iterable

class Zip:
    def __init__(self, *iterators, length_check=False):
        assert all(isinstance(iterator, Iterable) for iterator in iterators)
        self.iterators = [iter(iterator)for iterator in iterators]
        self.min = min(len(iterator) for iterator in iterators)
        self.length_check = length_check

    def __iter__(self):
        self.n = 0
        return self

    def __next__(self):
        if self.n == self.min and not self.length_check:
            raise StopIteration
        elif self.length_check and self.n == self.min:
            raise TypeError
        ret =  tuple(next(iterator) for iterator in self.iterators)
        self.n += 1
        return tuple(ret)
    
a = [i for i in range(10)]
b = [i*2 for i in range(11)]
c = [i**2 for i in range(20)]

print(list(Zip(a, b, c)))