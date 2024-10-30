  // Завантажуємо JSON з перекладами
  function loadTranslations(language) {
    fetch('lang.json')
        .then(response => response.json())
        .then(data => {
            // Застосування перекладів
            document.getElementById('title_lang').innerText = data[language].title;
            document.getElementById('select_color_lang').innerText = data[language].select_color;
            document.getElementById('red_lang').innerText = data[language].red;
            document.getElementById('yellow_lang').innerText = data[language].yellow;
            document.getElementById('green_lang').innerText = data[language].green;
            document.getElementById('blue_lang').innerText = data[language].blue;

            document.getElementById('light_fire_lang').innerText = data[language].light_fire;
            document.getElementById('light_ocean_lang').innerText = data[language].light_ocean;
            document.getElementById('light_strips_lang').innerText = data[language].light_strips;
            document.getElementById('light_temperature_lang').innerText = data[language].light_temperature;

            document.getElementById('sound_fire_lang').innerText = data[language].sound_fire;
            document.getElementById('sound_birds_lang').innerText = data[language].sound_birds;
            document.getElementById('sound_sea_lang').innerText = data[language].sound_sea;
            document.getElementById('sound_rain_lang').innerText = data[language].sound_rain;
            document.getElementById('sound_crickets_lang').innerText = data[language].sound_crickets;
            document.getElementById('sound_chikens_lang').innerText = data[language].sound_chikens;
            document.getElementById('sound_train_lang').innerText = data[language].sound_train;
            document.getElementById('sound_frogs_lang').innerText = data[language].sound_frogs;

            document.getElementById('speed_low_lang').innerText = data[language].speed_low;
            document.getElementById('speed_medium_lang').innerText = data[language].speed_medium;
            document.getElementById('speed_high_lang').innerText = data[language].speed_high;

            document.getElementById('bright_low_lang').innerText = data[language].bright_low;
            document.getElementById('bright_medium_lang').innerText = data[language].bright_medium;
            document.getElementById('bright_high_lang').innerText = data[language].bright_high;
            
            document.getElementById('light_type_lang').innerText = data[language].light_type;
            document.getElementById('change_sound_lang').innerText = data[language].change_sound;
            document.getElementById('light_speed_lang').innerText = data[language].light_speed;
            document.getElementById('light_intensity_lang').innerText = data[language].light_intensity;

            document.getElementById('copiright_lang').innerText = data[language].copiright;

            document.getElementById('your_language_lang').innerText = data[language].your_language;

        });
}

// Функція для зміни мови
function changeLanguage(language) {
    loadTranslations(language);  // Зміна мови на сторінці

    // Надсилання запиту для збереження вибору мови на контролері
    const url = language === 'en' ? '/lang_en' : '/lang_uk';
    fetch(url)
        .then(response => {
            if (response.ok) {
                console.log('Language saved successfully!');
            } else {
                console.error('Failed to save language');
            }
        })
        .catch(error => console.error('Error:', error));
}

// Отримуємо мову браузера користувача
var userLang = navigator.language || navigator.userLanguage;
var langBrowser = userLang.startsWith('uk') || userLang.startsWith('ru') ? 'uk' : 'en'; // Вибираємо українську або англійську

// Завантажуємо переклади для потрібної мови
window.onload = function() {
    var langParam = document.getElementById('lang').innerText
    if (langParam == "0") {
        loadTranslations(langBrowser);
        langParam = langBrowser;
    } else {
        loadTranslations(langParam);
    }

    // Зробити активним відповідний елемент у селекторі мови
    document.getElementById("language_switch").value = langParam;
}
 
 // Функція для надсилання AJAX-запиту
 function sendRequest(endpoint) {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/" + endpoint, true); // Надсилаємо GET-запит на відповідний ендпойнт
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status == 200) {
            // Можна додати код для обробки відповіді від сервера
            console.log(endpoint + " selected");
        }
    };
    xhr.send(); // Надсилаємо запит
}