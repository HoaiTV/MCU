import MySQLdb

mydb = MySQLdb.connect(
  host="localhost",
  user="hoai",
  passwd="1",
  db="mydatabase"
)

mycursor = mydb.cursor()

mycursor.execute("SELECT name, address FROM customers")

myresult = mycursor.fetchall()

for x in myresult:
  print(x)
