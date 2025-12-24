from datetime import date

class BirthInfo:
    def __init__(self, birth_date):
        if isinstance(birth_date, date):
            self.birth_date = birth_date
        elif isinstance(birth_date, str):
            try:
                self.birth_date = date.fromisoformat(birth_date)
            except ValueError:
                raise TypeError("Аргумент переданного типа не поддерживается")
        elif isinstance(birth_date, (list, tuple)) and len(birth_date) == 3:
            try:
                self.birth_date = date(birth_date[0], birth_date[1], birth_date[2])
            except ValueError:
                raise TypeError("Аргумент переданного типа не поддерживается")
        else:
            raise TypeError("Аргумент переданного типа не поддерживается")

    @property
    def age(self):
        today = date.today()
        years = today.year - self.birth_date.year
        if (today.month, today.day) < (self.birth_date.month, self.birth_date.day):
            years -= 1
        return years
