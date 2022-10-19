/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 19 September 2022
Topik       : Praktikum 3: ADT, Pointer, Array Dinamik
Deskripsi   : Implementasi jumlahkonsonanvostr.h
*/

#include <stdio.h>
#include "jumlahkonsonanvokal.h"

// Parameter pertama merupakan strimat
// Parameter kedua merupakan jumlah huruf konsonan
// Parameter ketiga merupakan jumlah huruf vostr

int isAlphabet (char c) {
	// KAMUS
	// ALGORITMA
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int isVowel (char c) {
	// KAMUS
	// ALGORITMA
	if (c=='a' || c=='i' || c=='u' || c=='e' || c=='o' || c=='A' || c=='I' || c=='U' || c=='E' || c=='O') {
		return 1;
	} else {
		return 0;
	}
}

void jumlahKonsonanVokal(char* str, int* k, int* v) {
	// KAMUS
	// ALGORITMA
	while (*str != '\0') {
		if (isVowel(*str)) {
			(*v)++;
		} else if (isAlphabet(*str)) {
			(*k)++;
		}
		str++;
	}
}