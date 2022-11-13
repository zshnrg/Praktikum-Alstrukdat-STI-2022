/*
 * Nama			: Rozan Ghosani
 * NIM			: 18221121
 * Tanggal 		: 23 September 2022
 * Topik		: Pra-Praktikum 3: Array dan ADT List 
 * Deskripsi	: Impelemntasi array.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt *T) {
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
	// KAMUS
	// ALGORITMA
	(*T).Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
	// KAMUS
	// ALGORITMA
	return T.Neff;
}

int MaxNbEl (TabInt T) {
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
	// KAMUS
	// ALGORITMA
	return IdxMax - IdxMin;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
	// KAMUS
	// ALGORITMA
	return IdxMin;
}

IdxType GetLastIdx (TabInt T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
	// KAMUS
	// ALGORITMA
	return NbElmt(T);
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabInt T, IdxType i) {
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
	// KAMUS
	// ALGORITMA
	return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout) {
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
	// KAMUS
	IdxType i;
	// ALGORITMA
	for (i = 1; i <= NbElmt(Tin); i++) {
		SetEl(Tout, i, GetElmt(Tin,i));
	}
	SetNeff(Tout,NbElmt(Tin));
}

void SetEl (TabInt *T, IdxType i, ElType v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
	// KAMUS
	// ALGORITMA
	(*T).TI[i] = v;
	if (i > GetLastIdx(*T)) {
		(*T).Neff++;
	}
}

void SetNeff (TabInt *T, IdxType N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
	// KAMUS
	// ALGORITMA
	(*T).Neff = N;
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i) {
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
	// KAMUS
	// ALGORITMA
	return (i >= IdxMin && i <= IdxMax); 
}

boolean IsIdxEff (TabInt T, IdxType i) {
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
	// KAMUS
	// ALGORITMA
	return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T) {
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
	// KAMUS
	// ALGORITMA
	return NbElmt(T) == 0;
}

boolean IsFull (TabInt T) {
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	// KAMUS
	// ALGORITMA
	return NbElmt(T) == (IdxMax - IdxMin);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabInt T) {
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
	// KAMUS
	IdxType i;
	// ALGORITMA
	if (!IsEmpty(T)) {
		for (i = GetFirstIdx(T); i <= NbElmt(T); i++) {
			printf("%d:%d\n", i, GetElmt(T,i));
		}
	} else {
		printf("Tabel kosong\n");
	}
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2) {
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
	// KAMUS
	IdxType i;
	// ALGORITMA
	for (i = 1; i <= NbElmt(T1); i++) {
		T1.TI[i] += T2.TI[i];
	}
	return T1;
}

TabInt MinusTab (TabInt T1, TabInt T2) {
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */
	// KAMUS
	IdxType i;
	// ALGORITMA
	for (i = 1; i <= NbElmt(T1); i++) {
		T1.TI[i] -= T2.TI[i];
	}
	return T1;
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
	// KAMUS
	IdxType i;
	ElType max;
	// ALGORITMA
	max = GetElmt(T, 1);
	for (i = 1; i <= NbElmt(T); i++) {
		if (GetElmt(T,i) > max) {
			max = GetElmt(T,i);
		}
	}
	return max;
}

ElType ValMin (TabInt T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
	// KAMUS
	IdxType i;
	ElType min;
	// ALGORITMA
	min = GetElmt(T, 1);
	for (i = 1; i <= NbElmt(T); i++) {
		if (GetElmt(T,i) < min) {
			min = GetElmt(T,i);
		}
	}
	return min;
}

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
	// KAMUS
	IdxType i = 1;
	// ALGORITMA
	while (GetElmt(T,i) != ValMax(T) && i <= NbElmt(T)) {
		i++;
	}
	return i;
}

IdxType IdxMinTab (TabInt T) {
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
	// KAMUS
	IdxType i = 1;
	// ALGORITMA
	while (GetElmt(T,i) != ValMin(T) && i <= NbElmt(T)) {
		i++;
	}
	return i;
}
