const wrapper = document.createElement("div");
document.body.appendChild(wrapper);

wrapper.classList.add("theme-light");

const title = document.createElement("h2");
title.textContent = "Мой динамический список";
wrapper.appendChild(title);

const description = document.createElement("p");
description.textContent = "Ниже элементы списка";
wrapper.appendChild(description);

const list = document.createElement("ul");
wrapper.appendChild(list);

while (true) {
    const itemText = prompt("Введите пункт списка (пустая строка - окончание ввода):");

    if (!itemText) break; 
    const li = document.createElement("li");
    li.textContent = itemText;
    li.classList.add("list-item"); 
    list.appendChild(li);
}

const btn = document.createElement("button");
btn.textContent = "Сменить тему";
btn.classList.add("theme-button");
wrapper.appendChild(btn);

btn.addEventListener("click", () => {
    wrapper.classList.toggle("theme-light");
    wrapper.classList.toggle("theme-dark");
});
