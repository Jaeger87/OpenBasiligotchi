
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
/*
void copiaFaccia(  uint8_t PROGMEM face[][8],uint8_t PROGMEM face2[][8],int sizematrice)
{
  for(int j=0;j<sizematrice;j++)
    for(int i=0;i<8;i++)
      face[j][i]=face2[j][i];

}
*/
void disegnaSuMatrice(const uint8_t  *disegno[][8],int sizematrice)
{

  if(statoDisegno>=sizematrice)
  {
    int indice=statoDisegno-(2*(statoDisegno-sizematrice)+1);
    for(int i=0;i<9;i++)
    {
      matrix.clear();
      matrix.drawBitmap(0, 0, disegno[indice], 8, 8, LED_ON);
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
      matrix.drawBitmap(0, 0, disegno[statoDisegno][i-1], 8, 8, LED_ON);
      matrix.writeDisplay();
     // Write_Max7219(i,disegno[statoDisegno][i-1]);
    }
}








