/**
 * Created by nick on 24.10.16.
 */
var multiSelect = document.getElementById("LabMultiSelect");
var inputField = document.getElementById("newElementInput");

localStorage.clear();

var addDataToLocalStorage = function (value) {
    localStorage.setItem(String(localStorage.length), JSON.stringify({
        "id": String(localStorage.length + 1),
        "value": value
    }))
};

var deleteOnButtonClick = function () {
    var options = multiSelect && multiSelect.options;
    var opt;

    for (var i=0, iLen=options.length; i<iLen; i++) {
        opt = options[i];

        if (opt.selected) {
            addDataToLocalStorage(opt.text);
            opt.remove(0);
            break;
        }
    }
};

var addNewElementButtonClick = function () {
    var newElement = inputField.value;
    multiSelect.insertBefore(new Option(newElement,newElement),multiSelect[2]);
};