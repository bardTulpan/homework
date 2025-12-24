from abc import ABC, abstractmethod

class Date(ABC):
    def __init__(self, year, month, day):
        self.year = year
        self.month = month
        self.day = day

    @abstractmethod
    def format(self):
        pass

    def iso_format(self):
        m = str(self.month).zfill(2)
        d = str(self.day).zfill(2)
        return f"{self.year}-{m}-{d}"

class USADate(Date):
    def format(self):
        m = str(self.month).zfill(2)
        d = str(self.day).zfill(2)
        return f"{m}-{d}-{self.year}"

class ItalianDate(Date):
    def format(self):
        m = str(self.month).zfill(2)
        d = str(self.day).zfill(2)
        return f"{d}/{m}/{self.year}"

def main():
    d1 = USADate(2023, 1, 5)
    d2 = ItalianDate(2023, 1, 5)

    print("USA:", d1.format(), "| ISO:", d1.iso_format())
    print("Italy:", d2.format(), "| ISO:", d2.iso_format())

if __name__ == "__main__":
    main()
