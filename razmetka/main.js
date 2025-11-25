// В браузере всё, вроде, правильно работает
// Задача 1
const N = parseInt(prompt("Введите число N:"));
for (let i = 1; i * i <= N; i++) {
    console.log(i * i);
}

// Задача 2
const a = parseInt(prompt("Введите число a:"));
const b = parseInt(prompt("Введите число b:"));
let sum = 0;
let count = 0;
for (let i = a; i <= b; i++) {
    if (i % 3 === 0) {
        sum += i;
        count++;
    }
}
console.log(count > 0 ? sum / count : 0);

// Задача 3
const num = parseInt(prompt("Введите натуральное число N:"));
let n = num;
while (n > 1 && n % 2 === 0) {
    n /= 2;
}
console.log(n === 1 ? "YES" : "NO");

function camelize(str) {
    return str.split('-').map((word, index) => 
        index === 0 ? word : word.charAt(0).toUpperCase() + word.slice(1)
    ).join('');
}

console.log(camelize("background-color"));
console.log(camelize("list-style-image"));
console.log(camelize("-webkit-transition"));