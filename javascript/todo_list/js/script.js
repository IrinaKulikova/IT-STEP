(function () {

    let listTask = [];
    let keys = "myTasks";
    let ul = document.querySelector("ul");

    function Task(text, checkedTask) {
        this.text = text;
        this.checkedTask = checkedTask;
    }

    let event = new Event("click");

    function Load(e) {
        let dataLocalStorage = localStorage[keys];
        if (dataLocalStorage !== null && dataLocalStorage !== undefined) {
            listTask = JSON.parse(dataLocalStorage);
            for (let i = 0; i < listTask.length; i++) {
                let li = createNewLi(listTask[i].text);
                if (listTask[i].checkedTask) {
                    let check = li.firstChild.firstChild;
                    check.setAttribute("checked", "true");
                    li.firstChild.lastChild.style.opacity=0.5;
                }
                ul.append(li);
            }
        }
    };

    window.addEventListener("load", Load);

    function createNewLi(newTask) {
        let newLabel = document.createElement("label");
        let newCheckBox = document.createElement("input");
        newCheckBox.type = "checkbox";
        newCheckBox.onclick = clickCheckBoxFunction;
        newLabel.append(newCheckBox);
        let newTextTaskP = document.createElement("p");
        newTextTaskP.style.opacity = 1.0;
        let newTextTask = document.createTextNode(newTask);
        newTextTaskP.append(newTextTask);
        newLabel.append(newTextTaskP);
        let del = document.createElement("button");
        let textDel = document.createTextNode("x");
        del.appendChild(textDel);
        del.onclick = removeThis;
        let li = document.createElement("li");
        li.appendChild(newLabel);
        li.appendChild(del);
        return li;
    }
    
    //обработка события клика по чекбоксу
    function clickCheckBoxFunction(event) {
        this.nextSibling.style.opacity = (this.nextSibling.style.opacity == 1.0) ? 0.5 : 1.0;
        SaveTasks();
    }

    //подписываемся на событие клика по чекбоксу
    let add = document.querySelector("button");
    add.addEventListener('click', () => {
        let newTask = document.querySelector("input");
        if (newTask.value != "") {
            let li = createNewLi(newTask.value);
            newTask.value = "";
            ul.append(li);
            li.style.paddingLeft = "8px";
            let maxPadding = 60;
            let step = 6;
            var delay = 10;

            function moveAdd() {
                if (parseInt(li.style.paddingLeft) < maxPadding) {
                    li.style.paddingLeft = parseInt(li.style.paddingLeft) + 2 + "px";
                    setTimeout(moveAdd, delay);
                } else {
                    li.style.paddingLeft = "0px";
                }
            }
            moveAdd();
            let myNewTask = new Task(li.firstChild.lastChild.innerHTML, false);
            listTask.push(myNewTask);
            SaveTasks();
        }
    });

    //функция сохранения задачь в истории
    function SaveTasks() {
        localStorage.clear();
        if (ul.children.length > 0) {
            listTask.length=0;
            for (let i = 0; i < ul.children.length; i++) {
                let li = ul.children[i];
                let myTast = new Task(li.firstChild.lastChild.innerHTML, li.firstChild.firstChild.checked);
                listTask.push(myTast);
            }
            let datas = JSON.stringify(listTask);
            localStorage[keys] = datas;
        }
    }

    //удаление текущей задачи
    function removeThis() {
        let li = this.parentElement;
        let ul = li.parentElement;
        li.style.opacity = 0.5;
        var delay = 200;
        let countMax = 6;
        let count = 0;

        function blink() {
            if (Number(li.style.opacity) == 0) {
                li.style.opacity = 0.5;
            } else {
                li.style.opacity = 0;
            }
            if (count < countMax) {
                setTimeout(blink, delay);
                count++;
            } else {
                ul.removeChild(li);
                SaveTasks();
            }
        }
        blink();
    }

    //удаление всех задач
    let deleteAll = document.querySelector("button:last-child");
    deleteAll.onclick = function () {
        localStorage.clear();
        while (ul.children.length > 0) {
            ul.removeChild(ul.firstElementChild);
        }
    }

})();
