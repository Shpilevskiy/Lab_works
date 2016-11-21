var list = document.getElementById("deleted-items-list");

var getObjectsFromLocalStorage = function () {
    var results = [];
    for ( var i = 0, len = localStorage.length; i < len; ++i ) {
        var item = JSON.parse(localStorage.getItem( localStorage.key( i )));
        results.push(item.value);
    }
    return results
};

var generateList = function () {
    var elements = getObjectsFromLocalStorage();
    elements.forEach(function (item, i, arr) {
        addNewElementToList(item)
    })
};

addNewElementToList = function (text) {
    var li = document.createElement("li");
    li.appendChild(document.createTextNode(text));
    list.appendChild(li)
};

generateList();