long y = 0;
unsigned char data[5000];
char dataBuffer[500];
const boolean key[17][4] = {{0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}};
int inByte;
int i = 0;
int a;
boolean flag = 1;
boolean binaryNum[4] = {0, 0, 0, 0};

int tempdata[2];
int z=0;

int hexnum;
boolean binaryIn[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

boolean readflag = 1;
int dataNum;
int dataLength;
int res = 0;
int last;


void getBinary(int num)
{
  binaryNum[0] = key[num][0];
  binaryNum[1] = key[num][1];
  binaryNum[2] = key[num][2];
  binaryNum[3] = key[num][3];
}
int getdecimal(boolean value[12])
{
  int result = 0;
  //for (i=0;i<12;i++)

  result += (value[0]) * 1;
  result += (value[1]) * 2;
  result += (value[2]) * 4;
  result += (value[3]) * 8;
  result += (value[4]) * 16;
  result += (value[5]) * 32;
  result += (value[6]) * 64;
  result += (value[7]) * 128;
  result += (value[8]) * 256;
  result += (value[9]) * 512;
  result += (value[10]) * 1024;
  result += (value[11]) * 2048;

  return result;
}

int hextoint(byte num) {
  if (num == 'a')
    return 10;
  else if (num == 'b')
    return 11;
  else if (num == 'c')
    return 12;
  else if (num == 'd')
    return 13;
  else if (num == 'e')
    return 14;
  else if (num == 'f')
    return 15;
  else
    return int(num-48);
}

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(36, INPUT_PULLUP);
  pinMode(37, OUTPUT);
  //pinMode(3, INPUT);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);

  //pinMode(40, OUTPUT);
  
  for (int z = 24; z < 36; z++)
    pinMode(z, INPUT);
  digitalWrite(37, 0);
  //attachInterrupt(0, analyae, FALLING);
  attachInterrupt(digitalPinToInterrupt(2), ISR0, FALLING);
  attachInterrupt(digitalPinToInterrupt(18), ISR1, FALLING);
  attachInterrupt(digitalPinToInterrupt(19), ISR2, FALLING);
  Serial.begin(9600);
  Serial.println("ROM Emulator by Bolan Xu 2023");
  Serial.println("Please Enter Data for each address.\nEnter 99 to Exit.");
  while (flag) 
  {
    delay(5);
    
    while (Serial.available() > 0)
    {
      dataLength = Serial.readBytes(dataBuffer, 500);
      //Serial.print("Data Length: ");
      //.println(dataLength);
      
      for(i=0;i<dataLength;i++)
      {
        //if (dataBuffer[i]==',')
        //{
         
         //z=0;
         tempdata[z] = int(dataBuffer[i]);
         z++;
         if(z>1)
         {
            z=0;
            data[y]=(tempdata[0]*10)+tempdata[1]-16;
            Serial.print("Address ");
            Serial.print(y);
            Serial.print("H : ");
            Serial.println(data[y]);
            y++;
            //Serial.print();
            
            //tempdata[z] = int(dataBuffer[i]);
         }
        //}
        //data[i]=hexnum;
        
      }
      flag=0;
    }
  }
  last = y;
  y = 0;
  Serial.println("Done Entering Data...");
  //Serial.println(data[0]);
  //Serial.println(data[1]);
  //Serial.println(data[2]);
  //Serial.println(data[3]);
  //Serial.println(data[4]);
  //Serial.println("Done.");
  Serial.println("The data will also show on Pins 4-7.");

}
void loop() {
  if (digitalRead(36) == 1)
  {
    // put your main code here, to run repeatedly:
    //while(digitalRead(3)){
    //  delay(5);
    //}
    //digitalWrite(4,key[data[i]][0]);
    //digitalWrite(5,key[data[i]][1]);
    //digitalWrite(6,key[data[i]][2]);
    //digitalWrite(7,key[data[i]][3]);


    Serial.print('\n');
    //digitalWrite(3, 1);
    //delay(10);
   //if (digitalRead(3) == 1);
    //{ //digitalWrite(36, 0);
      y++;
      Serial.print("Address ");
      Serial.print(y);
      Serial.print("D : ");
      Serial.print(data[y]);
      Serial.print("   In Binary: ");
      dataNum = data[y];
      getBinary(dataNum);
      for (a = 0; a < 4; a++)
      {
        Serial.print(binaryNum[3 - a]);
        digitalWrite(4 + a, binaryNum[3 - a]);
      }
      //      digitalWrite(37,1);
      //      delay(1000);
      //      digitalWrite(37,0);
   // }
    digitalWrite(37, 1);
    delay(100);
    digitalWrite(37, 0);
    while (digitalRead(36) == 1);
    //digitalWrite(36, 1);
    if (y == last)
    {
      Serial.println("Done display.");
      //done();
      y = 0;
    }
   //} 
  }
}

void ISR0()
{
  delay(1700);
  if (digitalRead(2) == 0)
  {

    Serial.print(binaryIn[0] = digitalRead(24));
    Serial.print(binaryIn[1] = digitalRead(25));
    Serial.print(binaryIn[2] = digitalRead(26));
    Serial.print(binaryIn[3] = digitalRead(27));
    //Serial.print(binaryIn1[0] = digitalRead(28));
    //Serial.print(binaryIn1[1] = digitalRead(29));
    //Serial.print(binaryIn1[2] = digitalRead(30));
    //Serial.print(binaryIn1[3] = digitalRead(31));
    //Serial.print(binaryIn2[0] = digitalRead(32));
    //Serial.print(binaryIn2[1] = digitalRead(33));
    //Serial.print(binaryIn2[2] = digitalRead(34));
    //Serial.print(binaryIn2[3] = digitalRead(35));

    y = getdecimal(binaryIn);


    Serial.print("\nChanged Address to ");
    Serial.println(y);
    Serial.print("Address ");
    Serial.print(y);
    Serial.print("D : ");
    Serial.print(data[y]);
    Serial.print("   In Binary: ");
    dataNum = data[y];
    getBinary(dataNum);
    for (a = 0; a < 4; a++)
    {
      Serial.print(binaryNum[3 - a]);
      digitalWrite(4 + a, binaryNum[3 - a]);
    }

    Serial.print('\n');
  }
}
void ISR1()
{
  delay(100);
  if (digitalRead(18) == 0)
  {

    //Serial.print(binaryIn[0] = digitalRead(24));
    //Serial.print(binaryIn[1] = digitalRead(25));
    //Serial.print(binaryIn[2] = digitalRead(26));
    //Serial.print(binaryIn[3] = digitalRead(27));
    Serial.print(binaryIn[4] = digitalRead(28));
    Serial.print(binaryIn[5] = digitalRead(29));
    Serial.print(binaryIn[6] = digitalRead(30));
    Serial.print(binaryIn[7] = digitalRead(31));
    //Serial.print(binaryIn2[0] = digitalRead(32));
    //Serial.print(binaryIn2[1] = digitalRead(33));
    //Serial.print(binaryIn2[2] = digitalRead(34));
    //Serial.print(binaryIn2[3] = digitalRead(35));

    y = getdecimal(binaryIn);


    Serial.print("\nChanged Address to ");
    Serial.println(y);
    Serial.print("Address ");
    Serial.print(y);
    Serial.print("D : ");
    Serial.print(data[y]);
    Serial.print("   In Binary: ");
    dataNum = data[y];
    getBinary(dataNum);
    for (a = 0; a < 4; a++)
    {
      Serial.print(binaryNum[3 - a]);
      digitalWrite(4 + a, binaryNum[3 - a]);
    }

    Serial.print('\n');
  }
}
void ISR2()
{
  delay(100);
  if (digitalRead(19) == 0)
  {

    //Serial.print(binaryIn[0] = digitalRead(24));
    //Serial.print(binaryIn[1] = digitalRead(25));
    //Serial.print(binaryIn[2] = digitalRead(26));
    //Serial.print(binaryIn[3] = digitalRead(27));
    //Serial.print(binaryIn1[0] = digitalRead(28));
    //Serial.print(binaryIn1[1] = digitalRead(29));
    //Serial.print(binaryIn1[2] = digitalRead(30));
    //Serial.print(binaryIn1[3] = digitalRead(31));
    Serial.print(binaryIn[8] = digitalRead(32));
    Serial.print(binaryIn[9] = digitalRead(33));
    Serial.print(binaryIn[10] = digitalRead(34));
    Serial.print(binaryIn[11] = digitalRead(35));

    y = getdecimal(binaryIn);


    Serial.print("\nChanged Address to ");
    Serial.println(y);
    Serial.print("Address ");
    Serial.print(y);
    Serial.print("D : ");
    Serial.print(data[y]);
    Serial.print("   In Binary: ");
    dataNum = data[y];
    getBinary(dataNum);
    for (a = 0; a < 4; a++)
    {
      Serial.print(binaryNum[3 - a]);
      digitalWrite(4 + a, binaryNum[3 - a]);
    }

    Serial.print('\n');
  }
}
