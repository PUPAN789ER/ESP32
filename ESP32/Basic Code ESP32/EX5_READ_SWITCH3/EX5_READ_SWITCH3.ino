int LEDPIN = 4;
int SWPIN = 18;
boolean state = 0;                          //กำหนดค่าตัวแปร state เท่ากับ 0 เป็นค่าเร่มต้น (สถานะปิด)
boolean oldState;                           //กำหนดค่าตัวแปรเป็นตัวเลข 0 กับ 1
boolean data;                               //กำหนดค่าตัวแปรเป็นตัวเลข 0 กับ 1

void setup() {

  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);                  //กำหนดขาดิจิตอล LEDPIN เป็นขาเอาท์พุท (LED)
  pinMode(SWPIN, INPUT_PULLUP);             //กำหนดขาดิจิตอล SWPIN เป็นขาอ่านข้อมูลการกดสวิตซ์ 
}

void loop() {
  data = digitalRead(SWPIN);                //อ่านค่าข้อมูลขาดิจิตอล SWPIN ในรูปแบบตัวเลข 0 และ 1 (0 คือการกดสวิตซ์)
  
  if (data == 0 and oldState == 1) {        //ถ้ามีการกดสวิตซ์ มีค่าที่อ่านได้เท่ากับ 0 และมีการกดเพียงครั้งเดียว มีค่าที่อ่านได้ก่อนหน้าเท่ากับ 1
    delay (10);                             //รอ 10 มิลลิวินาที เพื่อป้องกันการอ่านค่าผิดพลาด ที่เกิดขั้นในระหว่างการเกิดผิวหน้าสัมผัสตอนกดสวิตย์
      if (digitalRead(SWPIN) == 0) {        //อ่านค่าข้อมูลขาดิจิตอล SWPIN อีกครั้งถ้าพบว่าค่ายังเท่ากับ 0 แสดงว่ามีการกดสวิตซ์จริง
        Serial.print("SW current state: "); //แสดงข้อความในคอนโซล
        Serial.println(!state);             //แสดงสถานะ state ในคอนโซล
        state = !state;                     //กำหนดตัวแปร state ให้มีค่าตรงข้ามกับค่าปัจจุบัน (0 คือปิดไฟ และ 1 คือเปิดไฟ)
        digitalWrite(LEDPIN, state);        //เปิด ปิด LED ตามสถานะที่อ่านได้
      }
  }
  oldState = data;                          //กำหนดตัวแปร oldState เท่ากับค่าที่อ่านได้จากข้อมูลการกดสวิตซ์ปัจจุบัน 
}

