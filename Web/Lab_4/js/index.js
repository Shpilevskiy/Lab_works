var submitButton = $("#submit-button");
var checkboxGroup = $("#checkbox-group");
var textGroup = $("#text-group");
var emailGroup = $("#email-group");

var showError = function (group) {
    group.addClass("has-error")
};

var hideError = function (group) {
  group.removeClass("has-error");
};

var getAgeInfo = function () {
    var age = $("input:radio:checked");
    return age[0].value;
};

var getCriterionInfo = function () {
    return $("input:checkbox:checked");
};

var getQuality = function () {
    return $("select#quality-label").val();
};

var getResponse = function () {
    return $("textarea#response-text").val();
};

var getEmailAddress = function () {
    return $("#input-mail").val();
};

var validateFields = function(criterions, response, email) {
    var isAllCorrect = true;
    if (criterions[0] == undefined) {
        showError(checkboxGroup);
        isAllCorrect = false;
    }   else hideError(checkboxGroup);

    if (response.length > 150 || response.length == 0) {
        showError(textGroup);
        isAllCorrect = false;
    }    else hideError(textGroup);

    if (email.length > 20 || email.length == 0) {
        showError(emailGroup);
        isAllCorrect = false;
    }   else hideError(emailGroup);

    return isAllCorrect
};

submitButton.click(function () {
    var age = getAgeInfo();
    var criterions = getCriterionInfo();
    var quality = getQuality();
    var response = getResponse();
    var email = getEmailAddress();

    if (!validateFields(criterions, response, email)) return;
    var criterionsList = criterions.map(function (i, item) {
        if (typeof(item.value) == "string")
        return item.value;
    });
    console.log(criterionsList);
});