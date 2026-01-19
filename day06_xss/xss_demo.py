import html

user_input = input("请输入内容：")
safe_input = html.escape(user_input)
html_page = f"""
<html>
<body>
请输入内容：
{safe_input}
</body>
</html>
"""
print(html_page)
