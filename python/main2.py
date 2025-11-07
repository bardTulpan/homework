from tkinter import *

class TestSystem:
    def __init__(self, window):
        self.window = window
        self.window.title("IT Тестирование")
        self.window.geometry("600x500")
        
        self.questions = [
            {
                'text': 'Что означает аббревиатура HTML?',
                'options': [
                    'HyperText Markup Language',
                    'HighTech Modern Language', 
                    'HyperTransfer Markup Language',
                    'Home Tool Markup Language'
                ],
                'correct': [0]
            },
            {
                'text': 'Какие из этих языков являются языками программирования?',
                'options': [
                    'Python',
                    'HTML',
                    'CSS', 
                    'JavaScript'
                ],
                'correct': [0, 3]
            },
            {
                'text': 'Что такое переменная в программировании?',
                'options': [
                    'Константное значение',
                    'Именованная область памяти для хранения данных',
                    'Тип данных',
                    'Функция'
                ],
                'correct': [1]
            },
            {
                'text': 'Какие из этих технологий используются для фронтенд-разработки?',
                'options': [
                    'React',
                    'Django',
                    'Vue.js', 
                    'Spring'
                ],
                'correct': [0, 2]
            },
            {
                'text': 'Какой оператор используется для сравнения по значению и типу в JavaScript?',
                'options': [
                    '=',
                    '==',
                    '===',
                    '!='
                ],
                'correct': [2]
            }
        ]
        
        self.current_index = 0
        self.score = 0
        self.answer_vars = []
        
        self.create_interface()
        self.show_question()
    
    def create_interface(self):
        self.question_label = Label(self.window, text="", font=("Arial", 14, "bold"), wraplength=550)
        self.question_label.pack(pady=20)
        
        self.options_frame = Frame(self.window)
        self.options_frame.pack(pady=10, fill="both", expand=True)
        
        self.submit_btn = Button(self.window, text="Ответить", command=self.check_answer, 
                                font=("Arial", 12), bg="lightblue", padx=20)
        self.submit_btn.pack(pady=20)
        
        self.result_label = Label(self.window, text="", font=("Arial", 12))
        self.result_label.pack(pady=10)
    
    def show_question(self):
        for widget in self.options_frame.winfo_children():
            widget.destroy()
        
        self.answer_vars = []
        
        if self.current_index < len(self.questions):
            question_data = self.questions[self.current_index]
            
            self.question_label.config(text=f"Вопрос {self.current_index + 1}/{len(self.questions)}:\n{question_data['text']}")
            
            for i, option in enumerate(question_data['options']):
                var = BooleanVar()
                self.answer_vars.append(var)
                
                checkbox = Checkbutton(self.options_frame, 
                                     text=option, 
                                     variable=var,
                                     font=("Arial", 12),
                                     wraplength=500,
                                     anchor="w",
                                     padx=10,
                                     pady=5)
                checkbox.pack(anchor="w", pady=5, fill="x")
    
    def check_answer(self):
        if self.current_index >= len(self.questions):
            return
        
        question_data = self.questions[self.current_index]
        user_choices = []
        
        for i, var in enumerate(self.answer_vars):
            if var.get():
                user_choices.append(i)
        
        if set(user_choices) == set(question_data['correct']):
            self.score += 1
        
        self.current_index += 1
        
        if self.current_index < len(self.questions):
            self.show_question()
        else:
            self.show_results()
    
    def show_results(self):
        self.question_label.pack_forget()
        self.options_frame.pack_forget()
        self.submit_btn.pack_forget()
        
        percentage = (self.score / len(self.questions)) * 100
        
        if percentage >= 85:
            grade = "Отлично"
        elif percentage >= 70:
            grade = "Хорошо"
        elif percentage >= 60:
            grade = "Удовлетворительно"
        else:
            grade = "Неудовлетворительно"
        
        result_text = f"Тестирование завершено!\n\n"
        result_text += f"Правильных ответов: {self.score} из {len(self.questions)}\n"
        result_text += f"Процент выполнения: {percentage:.1f}%\n"
        result_text += f"Оценка: {grade}"
        
        self.result_label.config(text=result_text, font=("Arial", 14, "bold"), fg="blue")

if __name__ == "__main__":
    root = Tk()
    app = TestSystem(root)
    root.mainloop()