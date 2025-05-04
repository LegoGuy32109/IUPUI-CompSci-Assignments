
from bottle import default_app, route, post, get, template

@route('/')
def menu():
    return template("index.html")

@route('/bmicalc')
def basicForm():
    return template("form.html")

@post('/result')
def convert():
    return template("result.html")


application = default_app()

