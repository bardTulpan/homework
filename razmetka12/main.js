const LENGTH_OF_TABLE = 6
const HEIGHT_OF_TABLE = 6

const data = {
    "Машины": {
        "Легковые": ["Corolla", "Pajero"],
        "Грузовые": ["Камаз", "Белаз"]
    },
    "Самолёты": {
        "Пассажирские": [],
        "Грузовые": []
    },
    "Мотоциклы": {
        "Гоночные" : ["Yamaha", "Honda"],
        "Для путешествий" : ["Honda Gold", "Юпитер"]
    }
};

function createList(obj) {
    const ul = document.createElement("ul");

    for (let key in obj) {
        const li = document.createElement("li");
        li.textContent = key;

        const value = obj[key];

        if (Array.isArray(value)) {
            if (value.length > 0) {
                const childUl = document.createElement("ul");
                value.forEach(item => {
                    const childLi = document.createElement("li");
                    childLi.textContent = item;
                    childUl.appendChild(childLi);
                });
                li.appendChild(childUl);
            }
        }

        else if (typeof value === "object" && value !== null) {
            if (Object.keys(value).length > 0) {
                const childList = createList(value);
                li.appendChild(childList);
            }
        }

        ul.appendChild(li);
    }

    return ul;
}

const listContainer = document.getElementById("listContainer");
listContainer.appendChild(createList(data));


listContainer.addEventListener("click", function (event) {
    const li = event.target;
    const childUl = li.querySelector("ul");

    if (childUl) {
        childUl.classList.toggle("hidden");
    }
});





const tableContainer = document.getElementById("tableContainer");

function createTable(rows, cols) {
    const table = document.createElement("table");

    for (let r = 0; r < rows; r++) {
        const tr = document.createElement("tr");

        for (let c = 0; c < cols; c++) {
            const td = document.createElement("td");
            td.textContent = `${r + 1}:${c + 1}`;

            td.addEventListener("click", () => {
                td.style.background = getRandomColor();
            });

            tr.appendChild(td);
        }

        table.appendChild(tr);
    }

    return table;
}

function getRandomColor() {
    const r = Math.floor(Math.random() * 256);
    const g = Math.floor(Math.random() * 256);
    const b = Math.floor(Math.random() * 256);
    return `rgb(${r}, ${g}, ${b})`;
}

tableContainer.appendChild(createTable(LENGTH_OF_TABLE, HEIGHT_OF_TABLE));
