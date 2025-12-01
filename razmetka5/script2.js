const photoTitles = document.querySelectorAll('.photo-title');

const photoDisplay = document.getElementById('photo-display');

function showPhoto(event) {
    const fileName = event.currentTarget.getAttribute('data-photo');
    
    const img = document.createElement('img');

    img.src = fileName;
    img.alt = 'Отображаемая фотография';

    photoDisplay.appendChild(img);
}


function hidePhoto() {
    photoDisplay.innerHTML = '';
}


for (let i = 0; i < photoTitles.length; i++) {
    const title = photoTitles[i]; 
    
    title.addEventListener('mousedown', showPhoto);
    title.addEventListener('mouseup', hidePhoto);
    title.addEventListener('mouseleave', hidePhoto);
}