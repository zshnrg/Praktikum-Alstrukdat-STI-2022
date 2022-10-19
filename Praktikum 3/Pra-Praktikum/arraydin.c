/*
Nama		: Rozan Ghosani
NIM			: 18221121
Tanggal		: 18 September 2022
Topik		: Pra-Praktikum 3
Deskripsi	: Implementasi panjangstring.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

ArrayDin MakeArrayDin() {
	// KAMUS
	ArrayDin arr;
	// ALGORITMA
	arr.A = (ElType*) malloc(InitialSize * sizeof(ElType));
	arr.Capacity = InitialSize;
	arr.Neff = 0;
	return arr;
}


void DeallocateArrayDin(ArrayDin *array) {
	// KAMUS
	// ALGORITMA
	free(array->A);
	array->Neff = 0;
}

boolean IsEmpty(ArrayDin array) {
	// KAMUS
	// ALGORITMA
	return (array.Neff == 0);
}

int Length(ArrayDin array) {
	// KAMUS
	// ALGORITMA
	return array.Neff;
}


ElType Get(ArrayDin array, IdxType i) {
	return array.A[i];
}

int GetCapacity(ArrayDin array) {
	// KAMUS
	// ALGORITMA
	return array.Capacity;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i) {
	// KAMUS
	ElType* temparr = (ElType*)malloc((*array).Capacity*sizeof(ElType));
	IdxType j;
	// ALGORITMA
	if ((*array).Neff < (*array). Capacity) {
		for (j = (*array).Neff; j > i; j--) {
			(*array).A[j] = (*array).A[j-1];
		}
		(*array).A[i] = el;
		(*array).Neff++;
	} else {
		for (j = 0; j < (*array).Capacity; j++) {
			temparr[j] = (*array).A[j];
		}
		free(array->A);
		(*array).A = (ElType*)malloc((*array).Capacity*2*sizeof(ElType));
		for (j = 0; j < i; j++) {
			(*array).A[j] = temparr[j];
		}
		(*array).A[i] = el;
		for (j = i; i <= (*array).Capacity; j++) {
			(*array).A[j+1] = temparr[j];
		}
		free(temparr); (*array).Neff++; (*array).Capacity *= 2;
	}
}
	
void DeleteAt(ArrayDin *array, IdxType i) {
	// KAMUS
	IdxType j=0;
	// ALGORITMA
	(*array).Neff--;
	for (j = i; j <= (*array).Neff; j++) {
		(*array).A[j] = (*array).A[j+1];
	}
}
