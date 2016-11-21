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
var toolsTable = $("#tools-table");
var toolsTableTemplate = $("#tools-table-template");
var toolsTableBody = $("#tools-table-body");


var showBlock = function (blockToShow) {
    blockToShow.show("slow", function () {})
};

var hideBlock = function (blockToHide, func) {
    blockToHide.hide("slow", function () {
        if ( func instanceof Function) func()
    })
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

var renderRow = function (item) {
    var template = toolsTableTemplate.html();
    Mustache.parse(template);
    return Mustache.render(template, item);
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
        hideBlock(tableBlock, $("tr").remove());
        showTableButton.text("Показать таблицу")
    }
   else {

       var tools = getAllTools();

       tools.list(null, function (results) {
           results.forEach(function (tool) {
               var newRow = renderRow(tool);
               toolsTable.append($(newRow));
           })});

       showBlock(tableBlock);
        showTableButton.text("Скрыть таблицу")
    }
});