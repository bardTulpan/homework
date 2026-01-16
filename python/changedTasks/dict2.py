def main():
    n = int(input())
    
    prava = {}
    
    for i in range(n):
        data = input().split()
        file_name = data[0]
        operations = data[1:]
        prava[file_name] = operations
    
    m = int(input())
    
    commands = {
        'read': 'R',
        'write': 'W', 
        'execute': 'X'
    }
    
    for i in range(m):
        zapros = input().split()
        operation = zapros[0]
        file_name = zapros[1]
        
        need_operation = commands[operation]
        
        if need_operation in prava[file_name]:
            print("OK")
        else:
            print("Access denied")

if __name__ == "__main__":
    main()