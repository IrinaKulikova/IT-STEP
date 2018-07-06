$("#remove_prog_lang").click(function (e) {
    e.preventDefault();
    $new_div = $("#parent_prog_lang>div:last-of-type");
    if($new_div.hasClass("clone")){
        $new_div.remove();
    }
});

$("#add_prog_lang").click(function (e) {
    e.preventDefault();
    $new_div = $("#parent_prog_lang > div:first-of-type").clone()
        .removeAttr("id").addClass("mt-4").addClass("clone")
        .appendTo($("#parent_prog_lang"));
    $new_div.find("input").val("");
});

$("#remove_lang").click(function (e) {
    e.preventDefault();
    $new_div = $("#parent_lang>div:last-of-type");
    if($new_div.hasClass("clone")){
        $new_div.remove();
    }
});

$("#add_lang").click(function (e) {
    e.preventDefault();
    $new_div = $("#lang_skills").clone()
        .removeAttr("id").addClass("mt-4").addClass("clone")
        .appendTo($("#parent_lang"));
    $new_div.find("input").val("");
});