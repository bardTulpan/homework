class Counter:
    def __init__(self, start=0):
        self.value = start

    def inc(self, num=1):
        self.value += num

    def dec(self, num=1):
        self.value -= num
        if self.value < 0:
            self.value = 0

class NonDecCounter(Counter):
    def dec(self, num=1):
        pass

class LimitedCounter(Counter):
    def __init__(self, start=0, limit=10):
        super().__init__(start)
        self.limit = limit

    def inc(self, num=1):
        self.value += num
        if self.value > self.limit:
            self.value = self.limit

c = Counter(5)
c.dec(10)
print(c.value}) 

lc = LimitedCounter(5, 15)
lc.inc(100)
print(lc.value}) 
