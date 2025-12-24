class Father:
    def __init__(self, mood='neutral'):
        self.mood = mood

    def greet(self):
        return "Hello!"

    def be_strict(self):
        self.mood = 'strict'

class Mother:
    def __init__(self, mood='neutral'):
        self.mood = mood

    def greet(self):
        return "Hi, honey!"

    def be_kind(self):
        self.mood = 'kind'

class Daughter(Mother, Father):
    def __init__(self, mood='neutral'):
        super().__init__(mood)

class Son(Father, Mother):
    def __init__(self, mood='neutral'):
        super().__init__(mood)

def main():
    d = Daughter()
    print(f"Daughter greet: {d.greet()}")
    d.be_kind()
    print(f"Daughter mood (kind): {d.mood}")
    d.be_strict()
    print(f"Daughter mood (strict): {d.mood}")

    print("-" * 10)

    s = Son()
    print(f"Son greet: {s.greet()}")
    s.be_kind()
    print(f"Son mood (kind): {s.mood}")
    s.be_strict()
    print(f"Son mood (strict): {s.mood}")
if __name__ == "__main__":
    main()
