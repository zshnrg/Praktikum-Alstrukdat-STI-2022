/*
Nama		: Rozan Ghosani
NIM			: 18221121
Tanggal		: 18 September 2022
Topik		: Pra-Praktikum 3
Deskripsi	: Implementasi panjangstring.h
*/

#include <stdio.h>
#include "panjangstring.h"

int panjangString(char*p) {
// menerima argumen pointer kepada karakter pertama dari sebuah string yang panjangnya tidak diketahui
// dan memberikan output berupa panjang string tersebut, dengan batasan string input memiliki karakter
// '\0' pada akhir string
	// KAMUS
	int length = 0;
	// ALGORITMA
	while (*p != '\0') {
		length++; p++;
	}
	return length;
}
