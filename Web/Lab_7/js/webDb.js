persistence.store.websql.config(
    persistence,
    'BuildToolsDatabase',
    'Database with build tools',
    5 * 1024 * 1024);

var Tool = persistence.define('Tool', {
    name: "TEXT",
    purpose: "TEXT",
    price: "INT",
    weight: "INT"
});

persistence.schemaSync();

var addNewTool = function(name, purpose, price, weight){
    var tool = new Tool({
        name: name,
        purpose: purpose,
        price: price,
        weight: weight
    });

    persistence.add(tool);

    persistence.transaction(function (tx) {
        persistence.flush(tx, function () {
            console.log("transaction done")
        })
    })
};

var getAllTools = function () {
    return Tool.all();
};

var getToolWithMinimalWeight = function () {
    return Tool.all().order("weight").limit(1);
};

var getToolById = function (id) {
  return Tool.all().filter('id', "=", id)
};

var deleteToolById = function (id) {
    var tools = Tool.all().filter('id', "=", id);

    tools.list(null, function (results) {
        results.forEach(function (tool) {
            persistence.remove(tool);
        });
    });

    persistence.transaction(function (tx) {
        persistence.flush(tx, function () {
            console.log("transaction done")
        })
    })

};