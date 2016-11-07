/**
 * Created by nick on 04.11.16.
 */

var firstInputField = $("#first-input-field");
var secondInputField = $("#second-input-field");
var thirdInputField = $("#third-input-field");
var fourthInputField = $("#fourth-input-field");
var fifthInputField = $("#fifth-input-field");

var firstMagicButton = $("#first-magic-button");
var secondMagicButton = $("#second--magic-button");

var list = $("#unmarked-list");

var getRandomColor = function () {
    var colors = ["#00b3ee", "blue", "green", "orange"];
    return colors[Math.floor(Math.random()*colors.length)];
};

var getRandomFont = function () {
  var fonts = ["Arial", "Verdana", "Courier New", "cursive", "Mathematica1"];
  return fonts[Math.floor(Math.random()*fonts.length)];
};

$(document).ready(function ($) {

    firstMagicButton.on("click", function (e) {
        firstInputField.css("color", getRandomColor());
        firstInputField.css("font-family", getRandomFont());

        thirdInputField.css("color", getRandomColor());
        thirdInputField.css("font-family", getRandomFont());

        fifthInputField.css("color", getRandomColor());
        fifthInputField.css("font-family", getRandomFont());

        var secondFieldValue = secondInputField.val();
        secondInputField.val(fourthInputField.val());
        fourthInputField.val(secondFieldValue);
    });

    secondMagicButton.on("click", function (e) {
        firstMagicButton.css("color", getRandomColor());
        if (list.is(":visible")) {
            list.hide("slow", function () {
            })
        }
        else {
            list.show("slow", function () {

            })
        }

    })

});

