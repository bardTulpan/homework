from tkinter import *
from datetime import datetime

def save_results():
    name = name_entry.get()
    age = age_var.get()
    experience = experience_var.get()
    
    selected_genres = []
    if action_var.get(): selected_genres.append("Экшен")
    if strategy_var.get(): selected_genres.append("Стратегия")
    if rpg_var.get(): selected_genres.append("RPG")
    if sports_var.get(): selected_genres.append("Спортивные")
    
    platform = platform_var.get()
    
    comments = comments_text.get("1.0", END).strip()
    

    result = f"""
                Результаты анкетирования:
                Дата: {datetime.now().strftime('%Y-%m-%d %H:%M')}
                Имя: {name}
                Возраст: {age}
                Опыт в играх: {experience}
                Любимые жанры: {', '.join(selected_genres) if selected_genres else 'Не указаны'}
                Предпочитаемая платформа: {platform}
                Дополнительные пожелания: {comments if comments else 'Отсутствуют'}
{'='*50}
"""
    
    with open("game_survey_results.txt", "a", encoding="utf-8") as file:
        file.write(result)
    
    result_label.config(text="Данные сохранены!")

root = Tk()
root.title("Анкета геймера")
root.geometry("500x600")

title_label = Label(root, 
                   text="Анкета про игры",
                   font=("Arial", 14))
title_label.pack(pady=10)

Label(root, text="Имя:").pack()
name_entry = Entry(root, width=30)
name_entry.pack(pady=5)

Label(root, text="Возраст:").pack()
age_var = StringVar(value="18-25")
age_frame = Frame(root)
age_frame.pack()
Radiobutton(age_frame, text="До 18", variable=age_var, value="До 18").pack(side=LEFT)
Radiobutton(age_frame, text="18-25", variable=age_var, value="18-25").pack(side=LEFT)
Radiobutton(age_frame, text="26-35", variable=age_var, value="26-35").pack(side=LEFT)

Label(root, text="Опыт в играх:").pack()
experience_var = StringVar(value="Средний")
experience_frame = Frame(root)
experience_frame.pack()
Radiobutton(experience_frame, text="Новичок", variable=experience_var, value="Новичок").pack(side=LEFT)
Radiobutton(experience_frame, text="Средний", variable=experience_var, value="Средний").pack(side=LEFT)
Radiobutton(experience_frame, text="Опытный", variable=experience_var, value="Опытный").pack(side=LEFT)

Label(root, text="Любимые жанры:").pack()
action_var = BooleanVar()
strategy_var = BooleanVar()
rpg_var = BooleanVar()
sports_var = BooleanVar()

genres_frame = Frame(root)
genres_frame.pack()
Checkbutton(genres_frame, text="Экшен", variable=action_var).grid(row=0, column=0, sticky="w")
Checkbutton(genres_frame, text="Стратегия", variable=strategy_var).grid(row=0, column=1, sticky="w")
Checkbutton(genres_frame, text="RPG", variable=rpg_var).grid(row=1, column=0, sticky="w")
Checkbutton(genres_frame, text="Спортивные", variable=sports_var).grid(row=1, column=1, sticky="w")

Label(root, text="Платформа:").pack()
platform_var = StringVar(value="PC")
platform_frame = Frame(root)
platform_frame.pack()
Radiobutton(platform_frame, text="PC", variable=platform_var, value="PC").pack(side=LEFT)
Radiobutton(platform_frame, text="PlayStation", variable=platform_var, value="PlayStation").pack(side=LEFT)
Radiobutton(platform_frame, text="Xbox", variable=platform_var, value="Xbox").pack(side=LEFT)

Label(root, text="Комментарии:").pack()
comments_text = Text(root, height=3, width=40)
comments_text.pack(pady=5)

submit_btn = Button(root, 
                   text="Сохранить", 
                   command=save_results)
submit_btn.pack(pady=10)

result_label = Label(root, text="")
result_label.pack()

root.mainloop()