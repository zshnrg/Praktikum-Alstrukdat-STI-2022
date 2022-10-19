/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 3 Oktober 2022
Topik       : Mesin Abstrak
Deskripsi   : Implementasi mesinkata.h
*/

#include <stdio.h>
#include "mesinkata.h"
#include "boolean.h"
#include "mesinkarakterv2.h"

Word currentWord;
boolean EndWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while ((currentChar == BLANK) && (currentChar != MARK)) {
        ADV();
    }
}

void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    }
    else {
        EndWord = false;
        ADVWORD();
    }
}

void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((currentChar != BLANK) && (currentChar != MARK)) {
        if (i < NMax) {
            currentWord.TabWord[i] = currentChar;
            i++;     
        }
        ADV();
    }
    currentWord.Length = i;
}