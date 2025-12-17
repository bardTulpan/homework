class Bachelor:
    def __init__(self, firstName, lastName, group, averageMark):
        self.firstName = firstName
        self.lastName = lastName
        self.group = group
        self.averageMark = averageMark

    def getScholarship(self):
        if self.averageMark == 5:
            return 10000
        elif self.averageMark > 3:
            return 5000
        return 0

class Undergraduate(Bachelor):
    def __init__(self, firstName, lastName, group, averageMark, scienceWork):
        super().__init__(firstName, lastName, group, averageMark)
        self.scienceWork = scienceWork

    def getScholarship(self):
        if self.averageMark == 5:
            return 15000
        elif self.averageMark > 3:
            return 7500
        return 0

students = [
    Bachelor("Иван", "Иванов", "101", 5),
    Undergraduate("Анна", "Петрова", "201", 5, "Математика")
]

for s in students:
    print(f"{s.lastName}: {s.getScholarship()} руб")
