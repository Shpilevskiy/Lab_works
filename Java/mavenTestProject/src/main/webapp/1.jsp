<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>

<head>
    <meta charset="UTF-8">
    <title>Lab 7</title>

    <link rel="stylesheet" href="/static/bower_components/bootstrap/dist/css/bootstrap.css">
    <link rel="stylesheet" href="/static/css/index.css">
</head>
<body>

<div class="container">
    <div class="info-header">
        <h1 class="info-title"> Лабораторная работа №5-6</h1>
        <p class="lead info-description">Пример работы с Java servlets, jstl, etc.</p>
    </div>

    <hr>

    <div class="row">


        <!--add new item block-->
        <div class="col-md-12">
            <form name="newItemForm" method="post" action="stationery">
                <div class="col-md-6">
                    <div class="control-group input-group-lg">
                        <input class="form-control" type="text" name="type" placeholder="Наименование">
                    </div>
                    <hr>
                    <div class="control-group input-group-lg">
                        <input class="form-control" type="text" name="purpose" placeholder="Назначение">
                    </div>
                </div>
                <div class="col-md-6">
                    <div class="control-group input-group-lg">
                        <input class="form-control"  type="text" name="material" placeholder="Материал">
                    </div>
                    <hr>
                    <div class="control-group input-group-lg">
                        <input class="form-control"  type="text" name="country" placeholder="Страна">
                    </div>
                </div>
                <div class="col-md-6">
                    <hr>
                    <div class="control-group input-group-lg">
                        <input class="form-control" name="firm"  type="text" placeholder="Фирма">
                    </div>
                </div>
                <div class="col-md-6">
                    <hr>
                    <div class="input-group input-group-lg">
                        <input class="form-control" name="price"  type="number" placeholder="Стоимость">
                        <span class="input-group-addon">$</span>
                    </div>
                </div>
                <div class="col-md-12">
                    <button class="btn btn-success add-new-element-button center-block">Добавить новую запись</button>
                </div>
            </form>
        </div>

        <%--control buttons--%>
        <div class="col-md-12">

            <hr>

            <div class="col-md-3">
                <div class="control-button-wrapper">
                    <a href="/search" type="button" class="btn btn-primary control-button">Найти записи</a>
                </div>
            </div>

            <div class="col-md-3">
                <div class="control-button-wrapper">
                    <a href="/delete" type="button" class="btn btn-danger control-button">Удалить запись</a>
                </div>
            </div>

            <div class="col-md-3">
                <div class="control-button-wrapper">
                    <a href="/edit" type="button" class="btn btn-warning control-button">Изменить запись</a>
                </div>
            </div>

            <div class="col-md-3">
                <div class="control-button-wrapper">
                    <a href="/generate" type="button" class="btn btn-info control-button">Сгенерировать 10 записей</a>
                </div>
            </div>

        </div>

        <div id="table-block" class="col-md-12">
            <hr>
            <div class="table-responsive">
                <table id="tools-table" class="table table-striped">
                    <thead>
                    <tr>
                        <th>id</th>
                        <th>Наименование</th>
                        <th>Назначение</th>
                        <th>Материал</th>
                        <th>Страна</th>
                        <th>Фирма</th>
                        <th>Цена</th>
                    </tr>
                    </thead>

                    <tbody id="tools-table-body">
                    <c:if test="${requestScope.stationeryList.size() > 0}">
                        <c:forEach items="${requestScope.stationeryList}" var="stationery" varStatus="theCount">
                            <tr>
                                <td><c:out value="${theCount.index}" /></td>
                                <td><c:out value="${stationery.getType()}" /></td>
                                <td><c:out value="${stationery.getPurpose()}" /></td>
                                <td><c:out value="${stationery.getMaterial()}" /></td>
                                <td><c:out value="${stationery.getСountry()}" /></td>
                                <td><c:out value="${stationery.getFirm()}" /></td>
                                <td><c:out value="${stationery.getPrice()}" />$</td>
                            </tr>
                        </c:forEach>
                    </c:if>
                    </tbody>
                </table>

            </div>
        </div>

    </div>

</div>

<script type="application/javascript" src="/static/bower_components/jquery/dist/jquery.min.js"></script>
<script type="application/javascript" src="/static/bower_components/bootstrap/dist/js/bootstrap.min.js"></script>
</body>
</html>