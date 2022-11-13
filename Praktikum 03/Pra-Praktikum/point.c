/*
Nama		: Rozan Ghosani
NIM			: 18221121
Tanggal		: 18 September 2022
Topik		: Pra-Praktikum 3
Deskripsi	: Implementasi point.h
*/

#include <stdio.h>
#include <math.h>
#include "point.h"
#include "boolean.h"

// Konstruktor membentuk POINT
POINT MakePOINT (float X, float Y) {
/* Membentuk sebuah POINT dari komponen-komponennya */
	// KAMUS
	POINT P;
	// ALGORITMA
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}

// KELOMPOK Interaksi dengan I/O device, BACA/TULIS
void BacaPOINT (POINT * P) {
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
	// KAMUS
	// ALGORITMA
	scanf("%f %f", &Absis(*P), &Ordinat(*P));
}

void TulisPOINT (POINT P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */   
	// KAMUS
	// ALGORITMA
	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

// Kelompok operasi relasional terhadap POINT
boolean EQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
	// KAMUS
	// ALGORITMA
	return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 tidak sama dengan P2 */
	// KAMUS
	// ALGORITMA
	return ! EQ(P1, P2);
}

// Kelompok menentukan di nama P berada
boolean IsOrigin (POINT P) {
/* Menghasilkan true jika P adalah titik origin */
	// KAMUS
	// ALGORITMA
	return (Absis(P) == 0 && Ordinat(P) == 0);
}
	
boolean IsOnSbX (POINT P) {
/* Menghasilkan true jika P terletak Pada sumbu X */
	// KAMUS
	// ALGORITMA
	return Ordinat(P) == 0;
}

boolean IsOnSbY (POINT P) {
/* Menghasilkan true jika P terletak pada sumbu Y */
	// KAMUS
	// ALGORITMA
	return Absis(P) == 0;
}

int Kuadran (POINT P) {
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
	// KAMUS
	int kuadran = 1;
	// ALGORITMA
	if (Absis(P) < 0) {
		if (Ordinat(P) > 0) {
			kuadran++;
		} else {
			kuadran = 3;
		}
	}
	if (Ordinat(P) < 0) {
		kuadran = 4;
	}
	return kuadran;
}

// KELOMPOK OPERASI LAIN TERHADAP TYPE
POINT PlusDelta (POINT P, float deltaX, float deltaY) {
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
	// KAMUS
	// ALGORITMA
	return MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY);
}

void Geser (POINT *P, float deltaX, float deltaY) {
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
	// KAMUS
	// ALGORITMA
	Absis(*P) += deltaX;
	Ordinat(*P) += deltaY;
}

float Jarak0 (POINT P) {
/* Menghitung jarak P ke (0,0) */
	// KAMUS
	// ALGORITMA
	return sqrt(pow(Absis(P),2) + pow(Ordinat(P), 2));
}

float Panjang (POINT P1, POINT P2) {
/* Menghitung panjang garis yang dibentuk P1 dan P2. */
	// KAMUS
	// ALGORITMA
	return sqrt(pow(Absis(P1) - Absis(P2),2) + pow(Ordinat(P1) - Ordinat(P2), 2));
}
