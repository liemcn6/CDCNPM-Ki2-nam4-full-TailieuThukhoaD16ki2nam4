
byte row[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

byte chuHex[][8] = {
  {0xFF, 0x03, 0x01, 0xED, 0xED, 0x01, 0x03, 0xFF}, //A
  {0xFF, 0x01, 0x01, 0x6D, 0x6D, 0x01, 0x93, 0xFF}, //B
  {0xFF, 0x83, 0x01, 0x7D, 0x7D, 0x39, 0xBB, 0xFF}, //C
  {0xFF, 0x01, 0x01, 0x7D, 0x7D, 0x01, 0x83, 0xFF}, //D
  {0xFF, 0x01, 0x01, 0x6D, 0x6D, 0x6D, 0x7D, 0xFF}, //E
  {0xFF, 0x01, 0x01, 0xED, 0xED, 0xED, 0xFD, 0xFF}, //F
  {0xFF, 0x83, 0x01, 0x7D, 0x5D, 0x19, 0x9B, 0xFF}, //G
  {0xFF, 0x01, 0x01, 0xEF, 0xEF, 0x01, 0x01, 0xFF}, //H
  {0xFF, 0xFF, 0x7D, 0x01, 0x01, 0x7D, 0xFF, 0xFF}, //I
  {0xFF, 0x9F, 0x9F, 0x7D, 0x01, 0x81, 0xFD, 0xFF}, //J
  {0xFF, 0x01, 0x01, 0xC7, 0x93, 0x39, 0x7D, 0xFF}, //K
  {0xFF, 0x01, 0x01, 0x7F, 0x7F, 0x7F, 0x7F, 0xFF}, //L
  {0xFF, 0x01, 0x01, 0xF3, 0xE7, 0xF3, 0x01, 0x01}, //M
  {0xFF, 0x01, 0x01, 0xF3, 0xE7, 0xCF, 0x01, 0x01}, //N
  {0xFF, 0x83, 0x01, 0x7D, 0x7D, 0x01, 0x83, 0xFF}, //O
  {0xFF, 0x01, 0x01, 0xDD, 0xDD, 0xC1, 0xE3, 0xFF}, //P
  {0xFF, 0xC3, 0x81, 0xBD, 0x9D, 0x01, 0x43, 0xFF}, //Q
  {0xFF, 0x01, 0x01, 0xCD, 0x8D, 0x21, 0x73, 0xFF}, //R
  {0xFF, 0xB3, 0x21, 0x6D, 0x6D, 0x09, 0x9B, 0xFF}, //S
  {0xFF, 0xF9, 0xFD, 0x01, 0x01, 0xFD, 0xF9, 0xFF}, //T
  {0xFF, 0x81, 0x01, 0x7F, 0x7F, 0x01, 0x01, 0xFF}, //U
  {0xFF, 0xC1, 0x81, 0x3F, 0x3F, 0x81, 0xC1, 0xFF}, //V
  {0xFF, 0x01, 0x01, 0x9F, 0xCF, 0x9F, 0x01, 0x01}, //W
  {0xFF, 0x39, 0x11, 0xC7, 0xEF, 0xC7, 0x11, 0x39}, //X
  {0xFF, 0xF1, 0xE1, 0x0F, 0x0F, 0xE1, 0xF1, 0xFF}, //Y
  {0xFF, 0x3D, 0x1D, 0x4D, 0x65, 0x71, 0x79, 0xFF}, //Z
  {0xFF, 0x7F, 0x77, 0x01, 0x01, 0x7F, 0x7F, 0xFF}, //1
  {0xFF, 0x3B, 0x19, 0x5D, 0x6D, 0x61, 0x73, 0xFF}, //2
  {0xFF, 0xBB, 0x39, 0x6D, 0x6D, 0x01, 0x93, 0xFF}, //3
  {0xFF, 0xCF, 0xD7, 0xDB, 0x01, 0x01, 0xDF, 0xFF}, //4
  {0xFF, 0xB1, 0x31, 0x75, 0x75, 0x05, 0x8D, 0xFF}, //5
  {0xFF, 0x83, 0x01, 0x6D, 0x6D, 0x09, 0x9B, 0xFF}, //6
  {0xFF, 0xF9, 0xF9, 0x1D, 0x05, 0xE1, 0xF9, 0xFF}, //7
  {0xFF, 0x93, 0x01, 0x6D, 0x6D, 0x01, 0x93, 0xFF}, //8
  {0xFF, 0xB3, 0x21, 0x6D, 0x6D, 0x01, 0x83, 0xFF}, //9
  {0xFF, 0x83, 0x01, 0x6D, 0x75, 0x01, 0x83, 0xFF}, //0
  {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, //space
};

String hienthi = "B";
void setup() {

  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  
  for (int q = 0; q < hienthi.length(); q++)
  {
    for (int h = 0; h < 8; h++)
    {
        for (int i = 0; i < 8; i++)
        {
          digitalWrite(11, LOW);
          shiftOut(12, 13, MSBFIRST, row[i]);
          shiftOut(9, 10, MSBFIRST, chuHex[hienthi.charAt(q) - 'A'][h]);
          digitalWrite(11, HIGH);
        }
      
    }
  }
}
