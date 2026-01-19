import sqlite3

conn = sqlite3.connect("test.db")
cursor = conn.cursor()

user = input("username: ")
pwd = input("password: ")

# ✅ 参数化查询
sql = "SELECT * FROM users WHERE username=? AND password=?"
cursor.execute(sql, (user, pwd))

result = cursor.fetchall()

if result:
    print("Login success")
else:
    print("Login failed")
