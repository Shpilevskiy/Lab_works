var resultsTable = $('#results-table');

var getObjectsFromLocalStorage = function () {
    for ( var i = 0, len = localStorage.length; i < len; ++i ) {
        var item = JSON.parse(localStorage.getItem( localStorage.key( i )));
        console.log(item);
        var newRow = renderRow(item);
        resultsTable.append($(newRow));
    }
};

var renderRow = function (item) {
    var template = $("#result-row-template").html();
    Mustache.parse(template);
    return Mustache.render(template, item);
};

getObjectsFromLocalStorage();