class IPAddress:
    def __init__(self, ipaddress):
        if isinstance(ipaddress, str):
            parts = ipaddress.split(".")
        elif isinstance(ipaddress, (list, tuple)):
            parts = ipaddress
        else:
            raise ValueError("Некорректный IP")

        if len(parts) != 4:
            raise ValueError("Некорректный IP")

        nums = []
        for part in parts:
            num = int(part)
            if not 0 <= num <= 255:
                raise ValueError("Некорректный IP")
            nums.append(num)

        self.ip = nums

    def __repr__(self):
        return f"IPAddress('{self}')"

    def __str__(self):
        return ".".join(map(str, self.ip))


ip1 = IPAddress("192.168.1.1")
ip2 = IPAddress([10, 0, 0, 1])

print(ip1)     
print(repr(ip1))

print(ip2)
print(repr(ip2))
