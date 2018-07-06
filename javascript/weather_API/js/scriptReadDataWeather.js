(function () {
    
    let xhr = new XMLHttpRequest();
 function addCityWeather(url) {

        xhr.open("GET", url, true);
        xhr.overrideMimeType("application/json");
        xhr.send();
        let success = 200;
        let statusDone = 4;
        let weather;

        xhr.onreadystatechange = function (e) {
            if (xhr.readyState === statusDone && xhr.status == success) {
                weather = xhr.responseText;
                weather = JSON.parse(xhr.responseText);
                //console.dir(weather);
                createElements(weather);
            }
        };

    }

    function createElements(weather) {

        if (weather === undefined || weather === null) {
            return;
        }

        let section = document.createElement("section");
        document.body.append(section);

        let data = document.createElement("div");
        data.setAttribute("id", "dataWeater");
        let name = document.createElement("p");
        name.innerHTML = weather.name.toUpperCase();
        section.append(name);

        let coords = document.createElement("p");
        coords.style.textAlign="center";
        coords.style.marginTop="-8px";
        coords.style.fontSize="12px";
        coords.style.color="black";
        coords.innerHTML = `coords:  ${weather.coord.lat},  ${weather.coord.lon}`;
        data.append(coords);
        
        let discriptionWeater = document.createElement("p");
        discriptionWeater.innerHTML = `${weather.weather[0].description }`;
        discriptionWeater.style.fontSize="30px";
        discriptionWeater.style.marginTop="8px";
        data.append(discriptionWeater);
        
        let icon = document.createElement("img");
        icon.setAttribute("alt", "icon");
        let nameIcon = "http://openweathermap.org/img/w/" + weather.weather[0].icon + ".png";
        icon.setAttribute("src", nameIcon);
        data.append(icon);

        const tempCelvinZero = 273.15;
        let temperatureP = document.createElement("p");
        temperatureP.innerHTML = `temperature: ${ (weather.main.temp-tempCelvinZero).toFixed(1)} C`;
        data.append(temperatureP);

        const coefficient = 0.750063755419211;
        let pressureP = document.createElement("p");
        pressureP.innerHTML = `atmospheric pressure: ${ parseInt(weather.main.pressure*coefficient)} mm m`;
        data.append(pressureP);

       
        let windSpeed = document.createElement("p");
        windSpeed.innerHTML = `wind speed: ${weather.wind.speed } m/s`;
        data.append(windSpeed);

        let humidity = document.createElement("p");
        humidity.innerHTML = `humidity: ${weather.main.humidity} %`;
        data.append(humidity);


        section.append(data);
    }
    
    let url1 = "http://api.openweathermap.org/data/2.5/weather?APPID=7b5cbb6bb21d0fc862c3b47a3b967ddf&lat=48.28&lon=35.1";
   
    addCityWeather(url1); 

})();
