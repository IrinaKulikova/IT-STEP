 $(function () {

     $.translate = function (text, inputLang, ouputLang, callback) {
         var url = 'https://translation.googleapis.com/language/translate/v2';
         $.get(url, {
             q: text,
             source: inputLang,
             target: ouputLang,
             key: 'AIzaSyCbQaZKjBMMNjk_NpKHV6_z1lQ8s4gnSjI'
         }, (data) => {
             callback(data);
             console.log(data);
         });
     };

     $("#go").click(function () {
         let inputLang = "en";
         let outputLang = "ru";
         if ($("select option:selected").text() == "на английский") {
             inputLang = "ru";
             outputLang = "en";
         }
         $.translate($("input").first().val(), inputLang, outputLang, (data) => {
             console.log(data);
             document.getElementById("#result").innerHTML = data.data.translations[0].translatedText;

             if (!$("#checkbox").is(':checked') == "false") {
                 $("input").first().val("");
             }
         });
     });

     console.log($("input").first());
     let event = new Event("click");

     $("input").first().keypress(function () {
         console.log($("#checkbox").is(':checked'));
         if ($("#checkbox").is(':checked')) {
             document.getElementById("go").dispatchEvent(event);
         }
     });
 });
