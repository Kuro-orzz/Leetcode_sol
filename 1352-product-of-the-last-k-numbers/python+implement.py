class ProductOfNumbers:
    def __init__(self):
        self.a = [0]
        self.zero = 0

    def add(self, num: int) -> None:
        if self.a[-1] == 0:
            self.a.append(num)
        else:
            x = self.a[-1] * num
            self.a.append(x)
        if self.a[-1] == 0:
            self.zero = len(self.a)-1

    def getProduct(self, k: int) -> int:
        if len(self.a)-1-k < self.zero:
            return 0
        return self.a[-1] // max(self.a[-1-k], 1)


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)