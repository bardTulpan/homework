class Product:
    def __init__(self, name, price, weight):
        self.__name = name
        self.__price = price
        self.__weight = weight

    def get_name(self): return self.__name
    def get_price(self): return self.__price
    def get_weight(self): return self.__weight

    def set_price(self, value):
        if value >= 0: self.__price = value

class Buy(Product):
    def __init__(self, name, price, weight, count):
        super().__init__(name, price, weight)
        self.__count = count

    def get_total_price(self):
        return self.get_price() * self.__count

    def get_total_weight(self):
        return self.get_weight() * self.__count

class Check(Buy):
    def print_info(self):
        print(f"Товар: {self.get_name()}")
        print(f"Общая стоимость: {self.get_total_price()}")
