/*
 * Nama			: Rozan Ghosani
 * NIM			: 18221121
 * Tanggal 		: 23 September 2022
 * Topik		: Pra-Praktikum 3: Array dan ADT List 
 * Deskripsi	: Impelemntasi list.h
*/

#include <stdio.h>
#include "list.h"

List MakeList() {
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
	// KAMUS
	List L;
	IdxType i;
	// ALGORITMA
	for (i = 0; i < MaxEl; i++) {
		L.A[i] = Mark;
	}
	return L;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L) {
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
	// KAMUS
	// ALGORITMA
	return (L.A[0] == Mark);
}

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i) {
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */
	// KAMUS
	// ALGORITMA
	return L.A[i];
}

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
	(*L).A[i] = v;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
	// KAMUS
	IdxType length = 0;
	// ALGORITMA
	while ((Get(L, length) != Mark) && (length < MaxEl)) {
		length++;
	}
	return length;
}

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L) {
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
	// KAMUS
	// ALGORITMA
	return 0;
}

IdxType LastIdx(List L) {
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
	// KAMUS
	// ALGORITMA
	return (Length(L) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i) {
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
	// KAMUS
	// ALGORITMA
	return ((i >= 0) && (i < MaxEl));
}

boolean IsIdxEff (List L, IdxType i) {
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
	// KAMUS
	// ALGORITMA
	return ((i >= FirstIdx(L)) && (i <= LastIdx(L)));
}

/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X) {
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
	// KAMUS
	IdxType i = 0;
	// ALGORITMA
	while ((L.A[i] != X) && (IsIdxEff(L, i))) {
		i++;
	}
	return (L.A[i] == X);
}

void InsertFirst(List *L, ElType X) {
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
	// KAMUS
	IdxType i;
	// ALGORITMA
	InsertAt(L, X, 0);
}

void InsertAt(List *L, ElType X, IdxType i) {
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
	// KAMUS
	IdxType j;
	// ALGORITMA
	if (Length(*L) < MaxEl) {
		for (j = LastIdx(*L); j >= i; j--) {
			(*L).A[j + 1] = (*L).A[j];
		}
		(*L).A[i] = X;
	}
}

void InsertLast(List *L, ElType X) {
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
	InsertAt(L, X, Length(*L));
}

void DeleteFirst(List *L) {
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
	DeleteAt(L, 0);
}

void DeleteAt(List *L, IdxType i) {
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
	// KAMUS
	IdxType j;
	// ALGORTIMA
	for (j = i; j < LastIdx(*L); j++) {
		(*L).A[j]=(*L).A[j+1];
	}
	(*L).A[LastIdx(*L)] = Mark;
}

void DeleteLast(List *L) {
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
	DeleteAt(L, LastIdx(*L));
}

List Concat(List L1, List L2) {
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
	// KAMUS
	IdxType i;
	// ALGORITMA
	for (i = 0; i < Length(L2); i++) {
		InsertLast(&L1, L2.A[i]);
	}
	return L1;
}