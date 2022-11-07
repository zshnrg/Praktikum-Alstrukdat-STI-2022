/* Nama			: Rozan Ghosani
 * NIM			: 18221121
 * Tanggal		: 7 November 2022
 * Topik		: List Linier
 * Deskripsi	: Implementasi
 * */

#include <stdio.h>
#include "listlinier.h"

int main () {
	int N, Q, comm;
	scanf("%d", &N);
	scanf("%d", &Q); 
	
	List cache; CreateEmpty(&cache);
	address dump;
	
	for (int i = 1; i < N + 1; i++) {
		InsVLast(&cache, i);
	}
	
	for (int i = 0; i < Q; i++) {
		scanf("%d", &comm);
		if (Search(cache, comm) != Nil) {
			DelP(&cache, comm);
			InsVFirst(&cache, comm);
			printf("hit ");
			PrintInfo(cache);
			printf("\n");
		} else {
			DelLast(&cache, &dump);
			InsVFirst(&cache, comm);	
			printf("miss ");
			PrintInfo(cache);
			printf("\n");
		}
	}
	return 0;
}
