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
      disegnaSuMatrice(entusiasta,sizematrice,LED_GREEN);
      break;
    }
  case FELICE:
    {
      int sizematrice = (sizeof(felice) / sizeof(unsigned char))/8;
      disegnaSuMatrice(felice,sizematrice,LED_GREEN);
      break;
    }
  case QUASIFELICE:
    {
      int sizematrice = (sizeof(quasifelice) / sizeof(unsigned char))/8;
      disegnaSuMatrice(quasifelice,sizematrice,LED_YELLOW);
      break;
    }
  case NORMALE:
    {
      int sizematrice = (sizeof(normale) / sizeof(unsigned char))/8;
      disegnaSuMatrice(normale,sizematrice,LED_YELLOW);
      break;
    }
  case TRISTE:
    {
      int sizematrice = (sizeof(triste) / sizeof(unsigned char))/8;
      disegnaSuMatrice(triste,sizematrice,LED_RED);
      break;
    }
  case INCAZZATO:
    {
      int sizematrice = (sizeof(incazzato) / sizeof(unsigned char))/8;
      disegnaSuMatrice(incazzato,sizematrice,LED_RED);
      break;
    }
  }

}

//print in the matrix

void disegnaSuMatrice( const uint8_t  disegno[][8],int sizematrice, uint16_t colore)
{

  if(statoDisegno>=sizematrice)
  {
    int indice=statoDisegno-(2*(statoDisegno-sizematrice)+1);//this line is very important, from the variable statoDisegno can make the animation
    for(int i=0;i<9;i++)
    {
      matrix.clear();
      matrix.drawBitmap(0, 0, disegno[indice], 8, 8, colore);
      matrix.writeDisplay();
     // Write_Max7219(i,disegno[indice][i-1]);


    }
    if(indice==0)
      statoDisegno=0;
  }
  else

      for(int i=0;i<9;i++)
    {
      matrix.clear();
      matrix.drawBitmap(0, 0, disegno[statoDisegno], 8, 8, colore);
      matrix.writeDisplay();
     // Write_Max7219(i,disegno[statoDisegno][i-1]);
    }
}








