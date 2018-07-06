function set_data() {
    if($.cookie('first_name')!==undefined) {
        $('#first_name_table').text($.cookie('first_name'));
    }

    if($.cookie('last_name')!==undefined) {
        $('#last_name_table').text($.cookie('last_name'));
    }

    if($.cookie('email')!==undefined) {
        $('#e_mail_table').text($.cookie('email'));
    }

    if($.cookie('phone')!==undefined) {
        $('#phone_number_table').text($.cookie('phone'));
    }

    if($.cookie('gender')!==undefined) {
        $('#gender_table').text($.cookie('gender'));
    }

    if($.cookie('date')!==undefined) {
        $('#bith_date_table').text($.cookie('date'));
    }

    if($.cookie('nationality')!==undefined) {
        $('#nationality_table').text($.cookie('nationality'));
    }

    if($.cookie('responsibilities')!==undefined) {
        $('#responibility_table').text($.cookie('responsibilities'));
    }

    if($.cookie('company')!==undefined) {
        $('#company_table').text($.cookie('company'));
    }

    if($.cookie('position')!==undefined) {
        $('#position_table').text($.cookie('position'));
    }

    if($.cookie('date_from')!==undefined) {
        $('#date_from_table').text($.cookie('date_from'));
    }

    if($.cookie('date_to')!==undefined) {
        $('#date_to_table').text($.cookie('date_to'));
    }

    if($.cookie('prog_lang')!==undefined){
        console.log($.cookie('prog_lang'));
        var date_prog_lang=JSON.parse($.cookie('prog_lang'));
        $('#prog>th').text(date_prog_lang[0]);

    }

    if($.cookie('prog_level')!==undefined){
        console.log($.cookie('prog_level'));
        var date_prog_level=JSON.parse($.cookie('prog_level'));
        $('#prog>td').text(date_prog_level[0]);
    }

    if($.cookie('lang')!==undefined){
        console.log($.cookie('lang'));
        var date_lang=JSON.parse($.cookie('lang'));
    }

    if($.cookie('lang_comprehension')!==undefined){
        console.log($.cookie('lang_comprehension'));
        var date_lang_comprehension=JSON.parse($.cookie('lang_comprehension'));
    }

    if($.cookie('lang_reading')!==undefined){
        console.log($.cookie('lang_reading'));
        var date_lang_reading=JSON.parse($.cookie('lang_reading'));
    }

    if($.cookie('lang_writing')!==undefined){
        console.log($.cookie('lang_writing'));
        var date_lang_writing=JSON.parse($.cookie('lang_writing'));
    }

};