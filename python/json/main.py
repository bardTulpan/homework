import json

def create_json_file():
    print("Создание файла с пользователями")
    
    users = []
    
    while True:
        user_id = input("Введите ID пользователя: ")
        name = input("Введите имя: ")
        email = input("Введите email: ")
        age = int(input("Введите возраст: "))
        
        user = {
            "id": user_id,
            "name": name,
            "email": email,
            "age": age
        }
        
        users.append(user)
        
        more = input("Добавить еще пользователя? (да/нет): ")
        if more.lower() != 'да':
            break
    
    filename = input("Введите имя файла: ") + ".json"
    
    with open(filename, 'w') as f:
        json.dump(users, f)
    
    print(f"Файл {filename} создан")

def read_json_file():
    filename = input("Введите имя файла: ") + ".json"
    
    try:
        with open(filename, 'r') as f:
            users = json.load(f)
        
        print("\nИнформация о пользователе:")
        for user in users:
            print(f"ID: {user['id']}")
            print(f"Имя: {user['name']}")
            print(f"Email: {user['email']}")
            print(f"Возраст: {user['age']}")
            print("_______________________")
            
    except:
        print("Ошибка: файл не найден")

def main():
    while True:
        print("\n1. Создать файл")
        print("2. Прочитать файл")
        print("3. Выход")
        
        choice = input("Выберите действие: ")
        
        if choice == '1':
            create_json_file()
        elif choice == '2':
            read_json_file()
        elif choice == '3':
            break
        else:
            print("Неверный выбор")

if __name__ == "__main__":
    main()