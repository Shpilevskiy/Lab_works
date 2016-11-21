var newRecordBlock = $("#add-new-record-block");
var addNewRecordButton = $("#add-new-record-button");
var removeInputButton = $("#remove-input-button");
var backFromAddingButton = $("#back-from-adding");
var nameInput = $("#name-input");
var purposeInput = $("#purpose-input");
var priceInput = $("#price-input");
var weightInput = $("#weight-input");
var addingSuccessInfoBlock = $("#success-new-record");
var addingSuccessInoBlockText = $("#new-record-info-text");

var controlBlock = $("#control-buttons-block");
var minWeightBlock = $("#min-weight-block");
var newRecordButton = $("#new-record-button");
var deleteRecordButton = $("#delete-record-button");
var minWeightButton = $("#minimal-weight-button");
var showTableButton = $("#show-table-button");

var tableBlock = $("#table-block");
var toolsTable = $("#tools-table");
var toolsTableTemplate = $("#tools-table-template");
var toolsTableBody = $("#tools-table-body");

var deleteRecordBlock = $("#delete-record-block");
var selectedRecordInfo =$("#selected-block");
var selectedRecordInfoStrong = $("#selected-block-strong");
var selectedRecordInfoText= $("#selected-block-text");
var dropdownList = $("#dropdown-records-id");
var dropdownLiTemplate = $("#dropdown-li-template");
var backFromDeletingButton = $("#back-from-deleting");
var deleteSelectedRecordButton = $("#delete-selected-record");
var selectedIdToDelete;

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

var destroyTable = function () {
    $("tbody").empty();
};

var renderRow = function (item) {
    var template = toolsTableTemplate.html();
    Mustache.parse(template);
    return Mustache.render(template, item);
};

var renderLi = function (item) {
    var template = dropdownLiTemplate.html();
    Mustache.parse(template);
    return Mustache.render(template, item);
};

var renderTable = function () {
    destroyTable();
    var tools = getAllTools();

    tools.list(null, function (results) {
        results.forEach(function (tool) {
            var newRow = renderRow(tool);
            toolsTable.append($(newRow));
        })});
};

var destroyDropdownList = function () {
  dropdownList.empty();
};

var renderDropdownList = function() {
    destroyDropdownList();

    var tools = getAllTools();

    tools.list(null, function (results) {
        results.forEach(function (tool) {
            var newLi = renderLi(tool);
            dropdownList.append($(newLi));
        })});

};

var renderTableWithCustomTools = function (tools) {
    destroyTable();
    tools.list(null, function (results) {
        results.forEach(function (tool) {
            var newRow = renderRow(tool);
            toolsTable.append($(newRow));
        });
    });
};

var clearNewRowInputFields = function () {
    removeStateClasses(nameInput);
    removeStateClasses(purposeInput);
    removeStateClasses(priceInput);
    removeStateClasses(weightInput);
    nameInput.val("");
    purposeInput.val("");
    priceInput.val("");
    weightInput.val("");
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

    var isAllCorrect = true;

    if (!name.trim()) {
        addErrorClass(nameInput);
        isAllCorrect = false;
    }
    else {
        addSuccessClass(nameInput)
    }
    if (!purpose.trim()) {
        addErrorClass(purposeInput);
        isAllCorrect = false;
    }
    else {
        addSuccessClass(purposeInput)
    }
    if (!price.trim()) {
        addErrorClass(priceInput);
        isAllCorrect = false;
    }
    else {
        addSuccessClass(priceInput)
    }
    if (!weight.trim()) {
        addErrorClass(weightInput);
        isAllCorrect = false;
    }
    else {
        addSuccessClass(weightInput)
    }

    if (isAllCorrect) {
        addNewTool(name, purpose, price, weight);
        showBlock(addingSuccessInfoBlock);
        addingSuccessInoBlockText.text("Добавлен новый инструмент с вашими данными: наименование: '" + name + "' назначение: '" + purpose + "' цена: '" + price + "' вес: '" + weight + "'");
        clearNewRowInputFields();
        renderTable();
    }
    else {
        hideBlock(addingSuccessInfoBlock);
    }

});

removeInputButton.on("click", function () {
   clearNewRowInputFields();
});

backFromAddingButton.on("click", function () {
    hideBlock(newRecordBlock);
    showBlock(controlBlock);
});

showTableButton.on("click", function () {
    if(tableBlock.is(':visible')) {
        hideBlock(tableBlock, destroyTable());
        showTableButton.text("Показать таблицу")
    }
   else {
        renderTable();
        showBlock(tableBlock);
        showTableButton.text("Скрыть таблицу")
    }
});

minWeightButton.on("click", function () {

    if (minWeightBlock.is(':visible')) {
        hideBlock(minWeightBlock);
        minWeightButton.text("Инструмент с минимальным весом")
    }
    else {
        minWeightButton.text("Скрыть минимальный вес");
        var newText = "";
        getToolWithMinimalWeight().list(null, function (results) {
            results.forEach(function (tool) {
                newText = "Наименование: " + tool.name + " Назначение: " + tool.purpose + " Вес: " + tool.weight + " Цена: " + tool.price;
                $("#min-weight-block-text").text(newText);
            });
        });
        showBlock(minWeightBlock);
    }
});

deleteRecordButton.on("click", function () {
   hideBlock(controlBlock);
   showBlock(deleteRecordBlock);
   renderDropdownList();
});

backFromDeletingButton.on("click", function () {
   hideBlock(deleteRecordBlock);
   showBlock(controlBlock);
});

var makeDeleteMessageSuccess = function (messageText) {
    selectedRecordInfoStrong.text("Выбранный инструмент: ");
    selectedRecordInfoText.text(messageText);
    selectedRecordInfo.addClass("alert-success");
    selectedRecordInfo.removeClass("alert-danger");
    showBlock(selectedRecordInfo);
};

var makeDeleteMessageDanger = function () {
    selectedRecordInfoStrong.text("Ошибка");
    selectedRecordInfoText.text("выберите запись для удаления");
    selectedRecordInfo.removeClass("alert-success");
    selectedRecordInfo.addClass("alert-danger");
    showBlock(selectedRecordInfo);
};

dropdownList.on("click", "a", function (e) {
    selectedIdToDelete = $(this).text();
    var newText = "";
    getToolById(selectedIdToDelete).list(null, function (results) {
        results.forEach(function (tool) {
            newText = "id: '" + tool.id + "' Наименование: '" + tool.name + "' Назначение: '" + tool.purpose + "' Вес: " + tool.weight + "' Цена: " + tool.price + "'";
            makeDeleteMessageSuccess(newText);
        });
    });
});

deleteSelectedRecordButton.on("click", function () {
    if (selectedIdToDelete == undefined) {
        makeDeleteMessageDanger();
        return;
    }
    deleteToolById(selectedIdToDelete);
    selectedIdToDelete = undefined;
    makeDeleteMessageSuccess("Был успешно удален!");
    renderTable();
    renderDropdownList();
});