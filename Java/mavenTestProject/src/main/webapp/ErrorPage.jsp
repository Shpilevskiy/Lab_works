<%--
  Created by IntelliJ IDEA.
  User: nick
  Date: 13.12.16
  Time: 21:34
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Ooops</title>
    <link rel="stylesheet" href="/static/bower_components/bootstrap/dist/css/bootstrap.css">
    <link rel="stylesheet" href="/static/css/ErrorPage.css">
</head>
<body>

<div class="container">
    <div class="row">
        <div class="col-md-12">
            <div class="jumbotron center">
                <h1>Произошла ошибка
                    <hr>
                    <small>  Наверное, вы что-то сделали не так, но мы все равно вас прощаем</small>
                </h1>
                <br />
                <p>  ${errorText}  </p>
                <p>Нажмите на кнопку, и мы вернемся на гланую страницу, помните, что это всего лишь бета версия и все мы стремимся к лучшему</p>
                <a href="/" class="btn btn-large btn-info"><i class="icon-home icon-white"></i>Верни меня обратно</a>
            </div>
        </div>
    </div>
</div>

<script type="application/javascript" src="/static/bower_components/jquery/dist/jquery.min.js"></script>
<script type="application/javascript" src="/static/bower_components/bootstrap/dist/js/bootstrap.min.js"></script>
</body>
</html>
