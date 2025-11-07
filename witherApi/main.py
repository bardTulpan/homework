
import requests

API_KEY = "fc1e39b85ff6b83957c733adb0e65cf8"
URL = "http://api.openweathermap.org/data/2.5/weather"

def main():
    print("Программа для получения погоды")
    
    while True:
        location = input("Введите населенный пункт: ")
        if not location:
            break
            
        try:
            params = {
                'q': location,
                'appid': API_KEY,
                'units': 'metric',
                'lang': 'ru'
            }
            
            response = requests.get(URL, params=params)
            weather_data = response.json()
            
            if weather_data['cod'] == 200:
                print(f"Погода для {location}:")
                print(f"Температура: {weather_data['main']['temp']}°C")
                print(f"Состояние: {weather_data['weather'][0]['description']}")
                print(f"Влажность: {weather_data['main']['humidity']}%")
                print(f"Скорость ветра: {weather_data['wind']['speed']} м/с")
            else:
                print("Населенный пункт не найден")
                
        except:
            print("Ошибка получения данных")

if __name__ == "__main__":
    main()
