int quangtro = A0; //Thiết đặt chân analog đọc quang trở
void setup() 
{
  // Khởi tạo cộng Serial 9600
  Serial.begin(9600);
}

void loop() 
{
  int giatriQuangtro = analogRead(quangtro);// đọc giá trị quang trở
  delay(1000);
  Serial.println("Giá tri quang tro = "); // Xuất giá trị ra Serial Monitor
  Serial.println(giatriQuangtro); // Xuất giá trị ra Serial Monitor
  Serial.println("\n"); // Xuất giá trị ra Serial Monitor
}
