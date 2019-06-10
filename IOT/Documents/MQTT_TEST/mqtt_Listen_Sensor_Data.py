#------------------------------------------
#--- Author: Pradeep Singh
#--- Date: 20th January 2017
#--- Version: 1.0
#--- Python Ver: 2.7
#--- Details At: https://iotbytes.wordpress.com/store-mqtt-data-from-sensors-into-sql-database/
#------------------------------------------

import paho.mqtt.client as mqtt
from store_Sensor_Data_to_DB import sensor_Data_Handler

# MQTT Settings 
MQTT_Broker = "localhost"
MQTT_Port = 1883
Keep_Alive_Interval = 45
MQTT_Topic = "Home/BedRoom/#"

print "ENTER LISTEN SENSOR."

#Subscribe to all Sensors at Base Topic

def on_connect(client, userdata, flags, rc):
	print "HoaiTV_Call when ENTER ON_CONNECT"
#	print("Connected with result code "+str(rc))
	if rc==0:
			print("Connected with result code "+str(rc))
			client.subscribe(MQTT_Topic,0)
	else:
        	print("Bad connection Returned code=",rc)


#Save Data into DB Table
def on_message(mosq, obj, msg):
	print "Call when ENTER ON_MESSAGE"
	# This is the Master Call for saving MQTT Data into DB
	# For details of "sensor_Data_Handler" function please refer "sensor_data_to_db.py"
	print "MQTT Data Received..."
	print "MQTT Topic: " + msg.topic  
	print "Data: " + msg.payload
	sensor_Data_Handler(msg.topic, msg.payload)

def on_subscribe(mosq, obj, mid, granted_qos):
    pass


mqttc = mqtt.Client()
# Assign event callbacks

mqttc.on_connect = on_connect

mqttc.on_message = on_message



# Connect
try:
	mqttc.connect(MQTT_Broker, 1883,45)
	print "CONNECTED"
except:
	print "connection failed"
# Continue the network loop
mqttc.loop_forever()
