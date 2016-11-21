var newRecordBlock = $("#add-new-record-block");
var addNewRecordButton = $("#add-new-record-button");
var removeInputButton = $("#remove-input-button");
var backFromAddingButton = $("#back-from-adding");
var nameInput = $("#name-input");
var purposeInput = $("#purpose-input");
var priceInput = $("#price-input");
var weightInput = $("#weight-input");

var controlBlock = $("#control-buttons-block");
var newRecordButton = $("#new-record-button");
var deleteRecordButton = $("#delete-record-button");
var minWeightButton = $("#minimal-weight-button");
var showTableButton = $("#show-table-button");

var tableBlock = $("#table-block");



var showBlock = function (blockToShow) {
    blockToShow.show("slow", function () {})
};

var hideBlock = function (blockToHide) {
    blockToHide.hide("slow", function () {})
};

var addErrorClass = function (field) {
    field.parent().removeClass("has-success");
    field.parent().addClass("has-error")
};

var addSuccessClass = function (field) {
    field.parent().removeClass("has-error");
    field.parent().addClass("has-success");
};

var removeStateClasses = function (field) {
    field.parent().removeClass("has-error");
    field.parent().removeClass("has-success");
};

newRecordButton.on("click", function () {
    hideBlock(controlBlock);
    showBlock(newRecordBlock);
});

addNewRecordButton.on("click", function () {
    var name = nameInput.val();
    var purpose = purposeInput.val();
    var price = priceInput.val();
    var weight = weightInput.val();

    if (!name.trim()) {
        addErrorClass(nameInput)
    }
    else {
        addSuccessClass(nameInput)
    }
    if (!purpose.trim()) {
        addErrorClass(purposeInput);
    }
    else {
        addSuccessClass(purposeInput)
    }
    if (!price.trim()) {
        addErrorClass(priceInput);
    }
    else {
        addSuccessClass(priceInput)
    }
    if (!weight.trim()) {
        addErrorClass(weightInput);
    }
    else {
        addSuccessClass(weightInput)
    }

});

removeInputButton.on("click", function () {
    removeStateClasses(nameInput);
    removeStateClasses(purposeInput);
    removeStateClasses(priceInput);
    removeStateClasses(weightInput);
    nameInput.val("");
    purposeInput.val("");
    priceInput.val("");
    weightInput.val("");
});

backFromAddingButton.on("click", function () {
    hideBlock(newRecordBlock);
    showBlock(controlBlock);
});

showTableButton.on("click", function () {
    if(tableBlock.is(':visible')) {
        hideBlock(tableBlock);
        showTableButton.text("Показать таблицу")
    }
   else {
       showBlock(tableBlock);
        showTableButton.text("Скрыть таблицу")
    }
});