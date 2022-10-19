/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 19 September 2022
Topik       : Praktikum 3: ADT, Pointer, Array Dinamik
Deskripsi   : Implementasi garis.h
*/

#include <stdio.h>
#include <math.h>
#include "garis.h"
#include "point.h"
#include "boolean.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS(POINT P1, POINT P2, GARIS *L) {
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
    // KAMUS
    // ALGORITMA
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS(GARIS *L) {
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat
   membentuk GARIS yang valid
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan:
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
    // KAMUS
    POINT P1, P2;
    // ALGORITMA
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    while (EQ(P1, P2)) {
		printf("Garis tidak valid\n");
		BacaPOINT(&P1);
		BacaPOINT(&P2);
	}
    MakeGARIS(P1, P2, L);
}

void TulisGARIS(GARIS L) {
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))"
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
/* Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma. */
	printf("("); TulisPOINT(PAwal(L)); printf(","); TulisPOINT(PAkhir(L)); printf(")");
}


/* *** Kelompok operasi garis *** */
float PanjangGARIS(GARIS L) {
/* Menghitung panjang garis L : berikan rumusnya */
	// KAMUS
	// ALGORITMA
	return Panjang(PAwal(L),PAkhir(L));
	// d = ((x2-x1)^2+(y2-y1)^2)^0.5
}

float Gradien(GARIS L) {
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
	// KAMUS
	// ALGORITMA
	return (Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAwal(L)));
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus(GARIS L1, GARIS L2) {
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
	// KAMUS
	// ALGORITMA
	return (Gradien(L1) * Gradien(L2) == (-1));
}

boolean IsSejajar(GARIS L1, GARIS L2) {
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
	// KAMUS
	// ALGORITMA
	return (Gradien(L1) == Gradien(L2));
}
