class User:
    def __init__(self, name, age):
        if not (isinstance(name, str) and name.isalpha()):
            raise ValueError("Некорректное имя")
        if not (isinstance(age, int) and 0 <= age <= 110):
            raise ValueError("Некорректный возраст")
        self.__name = name
        self._age = age

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, new_name):
        if not (isinstance(new_name, str) and new_name.isalpha()):
            raise ValueError("Некорректное имя")
        self.__name = new_name

    @property
    def age(self):
        return self._age

    @age.setter
    def age(self, new_age):
        if not (isinstance(new_age, int) and 0 <= new_age <= 110):
            raise ValueError("Некорректный возраст")
        self._age = new_age

    def get_name(self):
        return self.name

    def set_name(self, new_name):
        self.name = new_name

    def get_age(self):
        return self.age

    def set_age(self, new_age):
        self.age = new_age
