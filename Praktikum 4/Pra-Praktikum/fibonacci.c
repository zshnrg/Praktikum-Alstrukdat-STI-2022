/*
 * Nama			: Rozan Ghosani
 * NIM			: 18221121
 * Tanggal 		: 23 September 2022
 * Topik		: Pra-Praktikum 3: Array dan ADT List 
 * Deskripsi	: Impelemntasi fibonacci.h
*/

#include <stdio.h>
#include "fibonacci.h"

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci ke argumen result
// Contoh:
// n = 5
// Nilai argumen result = 8
void fibonacci1(int n, int *result) {
	// KAMUS
	long long int temp[3] = {1,0,0}, i;
	// ALGORITMA
	for (i = 0; i <= n; i++) {
		temp[2]=temp[0]+temp[1]; *result = temp[2];
		temp[0] = temp[1]; temp[1] = temp[2];
	}
}

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci
int fibonacci2(int n) {
	// KAMUS
	int result;
	// ALGORITMA
	fibonacci1(n, &result);
	return result;
}

// Menerima argument sebuah integer n
// Output adalah argumen result yang bertipe pointer int digunakan sebagai array
// Tuliskan semua nilai deret fibonacci dari 0 - n ke argumen result
// n = 5
// result = [1, 1, 2, 3, 5, 8]
void fibonacci3(int n, int *result) {
	// KAMUS
	int i;
	// ALGORITMA
	for (i = 0; i <= n; i++) {
		*result = fibonacci2(i);
		result++;
	}
}
