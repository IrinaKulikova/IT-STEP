(function () {

    //набор картинок
    let arrImg = [];

    //элемент в дереве
    let img;

    //таймер
    let timer;

    //интервал таймера
    let interval = 3000;

    //событие загрузки странички
    function Load(e) {
        img = document.createElement("img");
        img.alt = "image";

        let url1 = "https://orig00.deviantart.net/9d7a/f/2012/079/9/f/waterfall_by_rav89-d4tdms1.jpg";
        let url2 = "https://orig00.deviantart.net/5e2d/f/2013/009/8/7/undead_castle_by_rav89-d5npu41.jpg";
        let url3 = "https://orig00.deviantart.net/b5f3/f/2012/329/1/b/foggy_hills_by_rav89-d5m4dwd.jpg";
        let url4 = "https://img00.deviantart.net/fca7/i/2015/033/b/6/space_by_rav89-d8gfv70.jpg";
        let url5 = "https://img00.deviantart.net/292e/i/2013/088/b/1/caastle_by_rav89-d5zol39.jpg";
        let url6 = "https://orig00.deviantart.net/141d/f/2013/077/8/f/dragon_stone_by_rav89-d5ygsr6.jpg"

        arrImg.push(url1);
        arrImg.push(url2);
        arrImg.push(url3);
        arrImg.push(url4);
        arrImg.push(url5);
        arrImg.push(url6);

        //добавляем картинку на страничку
        img = document.createElement("img");
        img.alt = "image";
        img.setAttribute("src", url1);
        let slide = document.querySelector("section");
        slide.append(img);

    };

    //подписываемся на событие загрузки странички
    window.addEventListener('load', Load);

    let eventSlideShow = new Event('click');

    function startSlideShow() {
        next[0].dispatchEvent(eventSlideShow);
    }

    function Play(e) {

        let input = document.querySelector("input");
        let inputInterval = parseInt(input.value);
        if (isFinite(inputInterval) && inputInterval !== 0) {
            interval = inputInterval * 1000;
        }
        timer = setTimeout(startSlideShow, interval);
        console.log(timer);
    }

    function Pause(e) {
        if (timer !== null && timer !== undefined) {
            clearInterval(timer);
            timer = null;
        }
    }

    function Next(e) {
        let stop = false;
        if (timer !== null && timer !== undefined) {
            Pause();
            stop = true;
        }
        let currentImg = arrImg.indexOf(img.src);
        if (currentImg < arrImg.length - 1) {
            img.setAttribute("src", arrImg[currentImg + 1]);
        } else {
            img.setAttribute("src", arrImg[0]);
        }
        if (stop) {
            Play();
        }
    }

    function Previous(e) {
        let stop = false;
        if (timer !== null && timer !== undefined) {
            Pause();
            stop = true;
        }
        let currentImg = arrImg.indexOf(img.src);
        if (currentImg > 1) {
            img.setAttribute("src", arrImg[currentImg - 1]);
        } else {
            img.setAttribute("src", arrImg[arrImg.length - 1]);
        }
        if (stop) {
            Play();
        }
    }

    let play = document.querySelector(" nav > button:nth-child(4)");
    play.addEventListener('click', Play);
    let pause = document.querySelector("nav > button:nth-child(5)");
    pause.addEventListener('click', Pause);
    let previous = document.getElementsByClassName("previous");
    previous[0].addEventListener('click', Previous);
    let next = document.getElementsByClassName("next");
    next[0].addEventListener('click', Next);
})();
