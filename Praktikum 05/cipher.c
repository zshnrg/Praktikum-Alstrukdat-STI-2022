/*
Nama		: Rozan Ghosani
NIM			: 18221121
Tanggal		: 3 Oktober 2022
Topik		: Mesin
Deskripsi	: Realisasi fungsi cipher
*/

#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakterv2.h"
#include "boolean.h"


int main() {
	int shift, i;
	
	STARTWORD();
	
	shift = currentWord.Length;
	
	while (!isEndWord()) {
		for (i = 0; i < currentWord.Length; i++) {
			printf("%c", ((currentWord.TabWord[i] +	shift - 65) % 26) + 65);
		}
		
		if (EOP) {
			printf(".\n");
		} else {
			printf(" ");
		}
		
		ADVWORD();			
	}
	
	return 0;
}
