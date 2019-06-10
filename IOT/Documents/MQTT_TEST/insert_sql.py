import MySQLdb

mydb = MySQLdb.connect(
  host="localhost",
  user="hoai",
  passwd="1",
  db="IoT"
)

mycursor = mydb.cursor()

sql = """INSERT INTO DHT22_Temperature_Data (SensorID, Date_n_Time, Temperature) VALUES (%s, %s, %s)"""
val = ("Dummy-2", "Highway -101",35)
mycursor.execute(sql, val)

mydb.commit()

print(mycursor.rowcount, "record inserted.")
