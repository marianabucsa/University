$(document).ready(function () {
    $(".leftlist").dblclick(function () {
        $(".leftlist option:selected").remove().appendTo(".rightlist");
    })

    $(".rightlist").dblclick(function () {
        $(".rightlist option:selected").remove().appendTo(".leftlist");
    })
});