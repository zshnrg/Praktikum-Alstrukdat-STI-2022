/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 3 Oktober 2022
Topik       : Mesin Abstrak
Deskripsi   : Implementasi mesinkarakter.h
*/

#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START()
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yanug ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
{
    pita = stdin;
    ADV();
}

void ADV()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
{
    retval = fscanf(pita,"%c",&currentChar);
    if (EOP) {
        fclose(pita);
    } 
}


char GetCC()
/* Mengirimkan currentChar */
{
    return currentChar;
}

boolean IsEOP()
/* Mengirimkan true jika currentChar = MARK */
{
    return currentChar == MARK;
}