(function () {

    ///конструктор объекта товар
    function Good(id, name, category, price, count) {
        this.id = id || "no_id";
        this.name = name;
        this.category = category;
        if (price !== undefined) {
            this.price = parseFloat(price) || 0;
        } else {
            this.price = 0;
        }

        if (count !== undefined) {
            this.count = parseInt(count) || 0;
        } else {
            this.count = 0;
        }
    }

    //индекс редактируемого товара
    let number = -1;

    ///массив товаров
    let Goods = [];

    //ключ к данным в dataLocalStorage
    let keygoods = "ListGoods";

    //ссылка на последнюю ячейку
    let trLast = document.querySelector("tr:last-child");

    //ссылка на таблицу
    let table = document.querySelector("table");

    //ссылка на tbody
    let tbody = document.querySelector("tbody");

    //обработка события загрузки страницы
    let functionLoad = function (e) {
        //localStorage.clear();
        let dataLocalStorage = localStorage[keygoods];
        if (dataLocalStorage !== null && dataLocalStorage !== undefined) {
            Goods = JSON.parse(dataLocalStorage);
            for (let i = 0; i < Goods.length; i++) {
                let tr = trLast.cloneNode(true);
                let td0 = tr.children[0];
                td0.firstChild.textContent = Goods[i].id;
                let td1 = tr.children[1];
                td1.firstChild.textContent = Goods[i].name;
                let td2 = tr.children[2];
                td2.firstChild.textContent = Goods[i].category;
                let td3 = tr.children[3];
                td3.firstChild.textContent = Goods[i].price;
                let td4 = tr.children[4];
                td4.firstChild.textContent = Goods[i].count;
                CreateLinks(tr, true);
                tbody.insertBefore(tr, trLast);
            }
        }
    }

    //подписываемся на событие загрузки страницы
    window.addEventListener('load', functionLoad);

    //функция привязывает необходимое событие и задаёт название кнопки редактирования и сохранения данных
    function TypeEdit(notEmpty, edit, text) {
        if (notEmpty) {
            text = "Редактировать";
            edit.onclick = functionEdit;
        } else {
            text = "Сохранить";
            edit.onclick = functionSave;
        }
        edit.innerHTML = text;
    }

    //функция создает кнопи в указанной ячейки
    function CreateLinks(newTr, notEmpty) {

        if (newTr !== null && newTr !== undefined) {

            let Edit = document.createElement("a");
            Edit.setAttribute("href", "");

            TypeEdit(notEmpty, Edit);

            let Delete = document.createElement("a");
            Delete.setAttribute("href", "");
            let text = "Удалить";
            Delete.addEventListener('click', functionDelete);
            Delete.append(document.createTextNode(text));

            newTr.children[newTr.children.length - 1].append(Edit);
            newTr.children[newTr.children.length - 1].append(document.createTextNode("\n\n"));
            newTr.children[newTr.children.length - 1].append(Delete);
        }
    }

    //обработка нажатия на кнопку сохранить
    let functionSave = function (e) {
        e.preventDefault();
        let tr = e.target.parentElement.parentElement;
        let td0 = tr.children[0];
        let td1 = tr.children[1];
        let td2 = tr.children[2];
        let td3 = tr.children[3];
        let td4 = tr.children[4];

        let good = new Good(
            td0.firstChild.textContent,
            td1.firstChild.textContent,
            td2.firstChild.textContent,
            td3.firstChild.textContent,
            td4.firstChild.textContent, );

        if (number > 0) {
            Goods[number - 1] = good;
        } else {
            Goods.push(good);
        }

        for (var i = 0; i < tr.children.length - 1; i++) {
            tr.children[i].removeAttribute('contenteditable');
        }

        TypeEdit(true, e.target);
        SaveTable();
        number = -1;
    }

    function SaveTable() {
        let datas = JSON.stringify(Goods);
        localStorage[keygoods] = datas;
    }

    function getIndex(currentTr) {
        for (let i = 0; i < tbody.children.length; i++) {
            if (currentTr == tbody.children[i]) {
                return i;
            }
        }
        return -1;
    }

    //обработка нажатия на кнопку редактировать
    let functionEdit = function (e) {
        e.preventDefault();
        let tr = e.target.parentElement.parentElement;
        for (var i = 0; i < tr.children.length - 1; i++) {
            tr.children[i].setAttribute('contenteditable', 'true');
        }
        e.target.innerHTML = "Сохранить";
        e.target.onclick = functionSave;
        number = getIndex(e.target.parentElement.parentElement);
    }

    //обработка нажатия на кнопку удалить
    let functionDelete = function (e) {
        e.preventDefault();
        number = getIndex(e.target.parentElement.parentElement);
        if (number > 0) {
            Goods.splice(number - 1, 1);
        }
        tbody.removeChild(e.target.parentElement.parentElement);
        SaveTable();
    }

    //обработка события двойного клика по таблице
    let tdDlClick = function (e) {
        if (e.target.parentElement == trLast) {
            let tr = trLast.cloneNode(true);
            for (var i = 0; i < tr.children.length - 1; i++) {
                tr.children[i].setAttribute('contenteditable', 'true');
            }
            trLast.parentElement.insertBefore(tr, trLast);
            CreateLinks(tr, false);
        }
    }

    //подписываем таблицу на двойной клик
    table.addEventListener('dblclick', tdDlClick);

})();
