class Negator:
    @staticmethod
    def neg(arg):
        if isinstance(arg, bool):
            return not arg
        elif isinstance(arg, (int, float)):
            return -arg
        else:
            raise TypeError("Аргумент переданного типа не поддерживается")
