#------------------------------------------
#--- Author: Pradeep Singh
#--- Date: 20th January 2017
#--- Version: 1.0
#--- Python Ver: 2.7
#--- Details At: https://iotbytes.wordpress.com/store-mqtt-data-from-sensors-into-sql-database/
#------------------------------------------
import sqlite3
import MySQLdb

# SQLite DB Name

conn = MySQLdb.connect (host = "localhost",
                         user = "hoai",
                         passwd = "1",
						 db = "IoT"
						)

curs = conn.cursor()

# SQLite DB Table Schema

sql_command = """DROP TABLE IF EXISTS DHT22_Humidity_Data; """

curs.execute(sql_command)

sql_command = """
CREATE TABLE DHT22_Humidity_Data ( 
id INTEGER PRIMARY KEY AUTO_INCREMENT, 
SensorID VARCHAR(20), 
Date_n_Time VARCHAR(100),
Humidity FLOAT);"""
curs.execute(sql_command)


sql_command = """DROP TABLE IF EXISTS DHT22_Temperature_Data;"""
curs.execute(sql_command)

sql_command = """
CREATE TABLE  DHT22_Temperature_Data( 
id INTEGER PRIMARY KEY AUTO_INCREMENT, 
SensorID VARCHAR(20), 
Date_n_Time VARCHAR(100),
Temperature FLOAT);"""

curs.execute(sql_command)
#curs.executescript(TableSchema)

#Close DB
curs.close()
conn.close()
