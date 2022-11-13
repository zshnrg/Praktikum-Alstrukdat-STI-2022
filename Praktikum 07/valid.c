/*
Nama		: Rozan Ghosani
NIM			: 18221121
Tanggal		: 26 Oktober 2022
Topik		: Stack
Deskripsi	: Implementasi valid.h
*/

#include <stdio.h>
#include "valid.h"

Stack validParantheses(char* input, int length)
/* Proses: Memasukkan parantheses (dari input) yang valid secara berurutan ke dalam Stack */
/* I.S. input adalah string, yang berisi parantheses baik secara acak maupun teratur, dan panjang dari string */
/* Contoh input dan hasil parantheses yang valid:
    1. () 2 -> ()
    2. []) 3 -> []
    3. {[} 3 -> --kosong--
    4. ()[]{} 6 -> ()[]{}
*/
{
	Stack valid;
	infotype val;
	CreateEmpty(&valid);

	for (int i = 0; i < length - 1; i++) {
		if (((input[i] == '[' && input[i+1] == ']') || (input[i] == '(' && input[i+1] == ')') || (input[i] == '{' && input[i+1] == '}'))) {
			Push(&valid, input[i]);
			Push(&valid, input[i + 1]);
		}
		if (IsFull(valid)) return valid;
	}
	return valid;
}