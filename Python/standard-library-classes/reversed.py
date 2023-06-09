from typing import Iterable
class Reversed:
    def __init__(self, it: Iterable):
        self.iter = iter(it)

    def __iter__(self):
        return self
    
    def __next__(self):
        pass