#------------------------------------------
#--- Author: Pradeep Singh
#--- Date: 20th January 2017
#--- Version: 1.0
#--- Python Ver: 2.7
#--- Details At: https://iotbytes.wordpress.com/store-mqtt-data-from-sensors-into-sql-database/
#------------------------------------------


import json
import sqlite3
import MySQLdb


#===============================================================
# Database Manager Class

class DatabaseManager:
	def __init__(self):
		print "Hoaitv ENTER _INIT_"
		self.conn =  MySQLdb.connect (host = "localhost",
                         user = "hoai",
                         passwd = "1",
						 db = "IoT"
						)
		self.conn1 =  MySQLdb.connect (host = "localhost",
                         user = "hoai",
                         passwd = "1",
						 db = "mydatabase"
						)
		print "Hoaitv pass self.conn"
		#self.conn.execute('PRAGMA foreign_keys = ON')
		print "Hoaitv pass self.conn.execute"
		self.conn.commit()
		self.conn1.commit()
		print "Hoaitv pass self.conn.commit()"
		self.cur = self.conn.cursor()
		self.cur1 = self.conn1.cursor()
		print "Hoaitv OUT _INIT_"
		
	def add_del_update_db_record(self, sql_query, args=()):
		print "Hoaitv ENTER add_del_update_db_record"
		print(sql_query)
		print(args)		
		sql = """INSERT INTO customers (name, address) VALUES (%s, %s)"""
		val = ("HOAITV_John", "Highway 22")
		self.cur1.execute(sql, val)
		self.conn1.commit()
		print "Hoaitv BEFORE self.cur.execute(sql_query, args)"
		self.cur.execute(sql_query, args)
		print "Hoaitv PASS self.cur.execute(sql_query, args)"
		self.conn.commit()
		print "Hoaitv PASS self.conn.commit()"
		self.cur.close()
		self.conn.close()
		self.cur1.close()
		self.conn1.close()
		return

#===============================================================
# Functions to push Sensor Data into Database

# Function to save Temperature to DB Table
def DHT22_Temp_Data_Handler(jsonData):
	#Parse Data 
	print "Hoaitv ENTER DHT22_Temp_Data_Handler"

		#Push into DB Table
	

	json_Dict = json.loads(jsonData)
	SensorID = json_Dict['Sensor_ID']
	Data_and_Time = json_Dict['Date']
	Temperature = json_Dict['Temperature']
	print json_Dict
	print "Hoaitv Show value SensorID = " + SensorID
	print "Hoaitv Show value  Data_and_Time =" + Data_and_Time
	print "Hoaitv BEFOR SHOW VALUE TEMPERATURE"	
	# instance
	dbObj = DatabaseManager()
	print "Hoaitv PASSED dbObj = DatabaseManager"
	sql_command = """INSERT INTO DHT22_Temperature_Data (SensorID, Date_n_Time, Temperature) values (%s, %s,%s)"""
	dbObj.add_del_update_db_record(sql_command ,[SensorID, Data_and_Time, Temperature])
	print "Hoaitv PASSED dbObj = dbObj.add_del_update_db_record"

	del dbObj
	print "Inserted Temperature Data into Database."
	print "Hoaitv finished inserted Temperature"

# Function to save Humidity to DB Table
def DHT22_Humidity_Data_Handler(jsonData):
	#Parse Data 
	print "Hoaitv ENTER DHT22_Humidity_Data_Handler"

	json_Dict = json.loads(jsonData)
	SensorID = json_Dict['Sensor_ID']
	Data_and_Time = json_Dict['Date']
	Humidity = json_Dict['Humidity']	
	#Push into DB Table
	dbObj = DatabaseManager()
	sql_command = """INSERT INTO DHT22_Humidity_Data (SensorID, Date_n_Time, Humidity) values  (%s, %s,%s)"""
	dbObj.add_del_update_db_record(sql_command,[SensorID, Data_and_Time, Humidity])
	del dbObj
	print "Inserted Humidity Data into Database."
	print "Hoaitv finished inserted Humidity"


#===============================================================
# Master Function to Select DB Funtion based on MQTT Topic

def sensor_Data_Handler(Topic, jsonData):
	print "Hoaitv ENTER sensor_Data_Handler"
	if Topic == "Home/BedRoom/DHT22/Temperature":
		print "Hoaitv BEFORE inserted Temperature"
		DHT22_Temp_Data_Handler(jsonData)
	elif Topic == "Home/BedRoom/DHT22/Humidity":
		DHT22_Humidity_Data_Handler(jsonData)	

#===============================================================
