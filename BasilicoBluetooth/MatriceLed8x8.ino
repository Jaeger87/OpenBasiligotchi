// this choice what smile to print to the matrix
void scegliFaccia()
{
  if(statoUmore!=vecchioStatoUmore)
    statoDisegno=0;
  else
    statoDisegno++;

  switch (statoUmore)
  {
  case ENTUSIASTA:
    {
      int sizematrice = (sizeof(entusiasta) / sizeof(unsigned char))/8;
      disegnaSuMatrice(entusiasta,sizematrice);
      break;
    }
  case FELICE:
    {
      int sizematrice = (sizeof(felice) / sizeof(unsigned char))/8;
      disegnaSuMatrice(felice,sizematrice);
      break;
    }
  case QUASIFELICE:
    {
      int sizematrice = (sizeof(quasifelice) / sizeof(unsigned char))/8;
      disegnaSuMatrice(quasifelice,sizematrice);
      break;
    }
  case NORMALE:
    {
      int sizematrice = (sizeof(normale) / sizeof(unsigned char))/8;
      disegnaSuMatrice(normale,sizematrice);
      break;
    }
  case TRISTE:
    {
      int sizematrice = (sizeof(triste) / sizeof(unsigned char))/8;
      disegnaSuMatrice(triste,sizematrice);
      break;
    }
  case INCAZZATO:
    {
      int sizematrice = (sizeof(incazzato) / sizeof(unsigned char))/8;
      disegnaSuMatrice(incazzato,sizematrice);
      break;
    }
  }

}

//print in the matrix

void disegnaSuMatrice( const uint8_t  disegno[][8],int sizematrice)
{

  if(statoDisegno>=sizematrice)
  {
    int indice=statoDisegno-(2*(statoDisegno-sizematrice)+1);  //this line is very important, from the variable statoDisegno can make the animation
    for(int i=0;i<9;i++)
    {
      clearMatrix();
      drawImmagine(disegno[indice]);
      matrix.write();
     // Write_Max7219(i,disegno[indice][i-1]);
    }
    if(indice==0)
      statoDisegno=0;
  }
  else
      for(int i=0;i<9;i++)
    {

      clearMatrix();
      drawImmagine(disegno[statoDisegno]);
      matrix.write();
    }
     // Write_Max7219(i,disegno[statoDisegno][i-1]);
}

void clearMatrix()
{
  for(int y=0;y<8;y++)
    for(int x=0;x<8;x++)
      matrix.drawPixel(x, y, LOW); 

}


void drawImmagine(const uint8_t *disegno)
{
      int16_t i, j, byteWidth = (8 + 7) / 8;

  for(j=0; j<8; j++) {
    for(i=0; i<8; i++ ) {
      if(pgm_read_byte(disegno + j * byteWidth + i / 8) & (128 >> (i & 7))) {
	matrix.drawPixel(i, j, HIGH);

      }
    }
  }
}
    


