document.addEventListener('DOMContentLoaded', function() {
    const listContainer = document.getElementById('dynamic-list');
    const addItemBtn = document.getElementById('add-item-btn');
    const toggleThemeBtn = document.getElementById('toggle-theme-btn');
    const listTitle = document.getElementById('list-title');
    const emptyMessage = document.getElementById('empty-message');
    const body = document.body;
    
    let isDarkTheme = false;
    
    function addListItem() {
        const itemText = prompt('Введите пункт списка:');
        
        if (itemText === null || itemText.trim() === '') {
            return;
        }
        
        emptyMessage.style.display = 'none';
        
        const listItem = document.createElement('li');
        listItem.className = 'list-item';
        listItem.textContent = itemText;
        
        listContainer.appendChild(listItem);
    }
    
    function toggleTheme() {
        isDarkTheme = !isDarkTheme;
        
        if (isDarkTheme) {
            body.classList.add('dark-theme');
            toggleThemeBtn.textContent = 'Светлая тема';
        } else {
            body.classList.remove('dark-theme');
            toggleThemeBtn.textContent = 'Темная тема';
        }
    }
    
    addItemBtn.addEventListener('click', addListItem);
    toggleThemeBtn.addEventListener('click', toggleTheme);
    listTitle.addEventListener('click', toggleTheme);
});