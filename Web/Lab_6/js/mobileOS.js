/**
 * Created by nick on 07.11.16.
 */

var letsStartButton = $("#let-start-button");
var topInfoBlock = $("#top-info-block");

var mainBlock = $("#main-block");

var androidMoreInfoButton = $("#android-more-info-button");
var androidInfoBlock = $("#android-info-block");

var iosMoreInfoButton = $("#ios-more-info-button");
var iosInfoBlock = $("#ios-info-block");

var windowsMoreInfoButton = $("#windows-more-info-button");
var windowsInfoBlock = $("#windows-info-block");

var liftButton = $("#lift-button");




var showBlock = function (blockToShow) {
    blockToShow.show("slow", function () {})
};

var liftToBlock = function (target, ms) {
    $('html, body').animate({
        scrollTop: target.offset().top
    }, ms);
};

letsStartButton.on("click", function () {
    showBlock(topInfoBlock)
});

androidMoreInfoButton.on("click", function () {
    if (!androidInfoBlock.is(':visible')) {
        $.getJSON("json/android.json", function (data) {
            console.log(data.texts[0].span);
            $("#android-h2").append(data.texts[0].h2 + "<span class="+ "text-muted" + "> " + data.texts[0].span + " </span>");
            $("#android-text").text(data.texts[1].lead)
        });
    }

    showBlock(mainBlock);
    showBlock(androidInfoBlock);

    liftToBlock(androidInfoBlock, 1700);
});

iosMoreInfoButton.on("click", function () {
    if (!iosInfoBlock.is(':visible')) {
        $.getJSON("json/ios.json", function (data) {
            console.log(data.texts[0].span);
            $("#ios-h2").append(data.texts[0].h2 + "<span class="+ "text-muted" + "> " + data.texts[0].span + " </span>");
            $("#ios-text").text(data.texts[1].lead)
        });
    }

    showBlock(mainBlock);
    showBlock(iosInfoBlock);

    liftToBlock(iosInfoBlock, 1700);
});

windowsMoreInfoButton.on("click", function () {
    if (!windowsInfoBlock.is(':visible')) {
        $.getJSON("json/windows.json", function (data) {
            console.log(data.texts[0].span);
            $("#windows-h2").append(data.texts[0].h2 + "<span class="+ "text-muted" + "> " + data.texts[0].span + " </span>");
            $("#windows-text").text(data.texts[1].lead)
        });
    }

    showBlock(mainBlock);
    showBlock(windowsInfoBlock);

    liftToBlock(windowsInfoBlock, 1700);
});

liftButton.on("click", function () {
    liftToBlock($("body"), 1200);
});