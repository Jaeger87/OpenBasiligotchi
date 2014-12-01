/*

void costruisciEntusiasta(const uint8_t *face[][8])
{


  static const uint8_t PROGMEM face2[2][8]={
    {
      B00000000,
      B01100110,
      B01100110,
      B00000000,
      B00000000,
      B11111111,
      B01111110,
      B00111100    }
    ,
    //smile sorridente giu


    {
      B01100110,
      B01100110,
      B00000000,
      B00000000,
      B11111111,
      B01111110,
      B00111100,
      B00000000    }
    ,


  };


  int sizematrice = (sizeof(face2) / sizeof(unsigned char))/8;
  copiaFaccia(face,face2,sizematrice);
}

void costruisciFelice(const uint8_t * face[][8])
{
  static const uint8_t PROGMEM face2[3][8]={
    {
      B00000000,
      B00000000,
      B01100110,
      B01100110,
      B00000000,
      B00000000,
      B01000010,
      B00111100                                                                            }
    ,
    //smile sorridente giu


    {
      B00000000,
      B01100110,
      B01100110,
      B00000000,
      B00000000,
      B01000010,
      B00111100,
      B00000000                                                                            }
    ,
    //smile sorridente normale



    {
      B01100110,
      B01100110,
      B00000000,
      B00000000,
      B01000010,
      B00111100,
      B00000000,
      B00000000                                                                            }
  };
  //smile sorridente su
  int sizematrice = (sizeof(face2) / sizeof(unsigned char))/8;
  copiaFaccia(face,face2,sizematrice);

}


void costruisciQuasiFelice( const uint8_t * face[][8])
{
  static const uint8_t PROGMEM face2[1][8]={
    {
      B00000000,
      B00000000,
      B01100110,
      B01100110,
      B00000000,
      B00000000,
      B01111110,
      B00000000                            }
  };
  //smile normale normale


  int sizematrice = (sizeof(face2) / sizeof(unsigned char))/8;
  copiaFaccia(face,face2,sizematrice);

}

void costruisciNormale( const uint8_t * face[][8])
{

  static const uint8_t PROGMEM face2[2][8]={
    {
      B00000000,
      B01100110,
      B01100110,
      B00000000,
      B00100000,
      B00010000,
      B00001000,
      B00000100                                    }
    ,
    //smile obliquo dx


    {
      B00000000,
      B01100110,
      B01100110,
      B00000000,
      B00000100,
      B00001000,
      B00010000,
      B00100000                                    }
  };
  //smile obliquo sx

  int sizematrice = (sizeof(face2) / sizeof(unsigned char))/8;
  copiaFaccia(face,face2,sizematrice);
}

void costruisciTriste(const uint8_t * face[][8])
{

  static const uint8_t PROGMEM face2[1][8]={
    {
      B00000000,
      B00000000,
      B01100110,
      B01100110,
      B00000000,
      B00111100,
      B01000010,
      B00000000                        }
  };
  //smile triste normale
  int sizematrice = (sizeof(face2) / sizeof(unsigned char))/8;
  copiaFaccia(face,face2,sizematrice);
}

void costruisciIncazzato(const uint8_t * face[][8])
{



  static const uint8_t PROGMEM face2[3][8]={ 
    {
      B00000000,
      B00000000,
      B00000000,
      B01100110,
      B01100110,
      B00000000,
      B00111100,
      B01000010                                    }
    ,
    //smile triste giu

    {
      B00000000,
      B00000000,
      B01100110,
      B01100110,
      B00000000,
      B00111100,
      B01000010,
      B00000000                                    }
    ,
    //smile triste normale


    {
      B00000000,
      B01100110,
      B01100110,
      B00000000,
      B00000000,
      B00111100,
      B01000010,
      B00000000                                    }
  };

  //smile triste su
  int sizematrice = (sizeof(face2) / sizeof(unsigned char))/8;
  copiaFaccia(face,face2,sizematrice);
}





*/








