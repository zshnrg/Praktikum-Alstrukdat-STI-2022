/*
Nama		: Rozan Ghosani
NIM			: 18221121
Tanggal		: 26 Oktober 2022
Topik		: Stack
Deskripsi	: Implementasi valid.h
*/

#include <stdio.h>
#include "valid.h"
// infotype stack yang digunakan adalah char


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

	for (int i = 0; i < length; i++) {
		if ((input[i] == '[' || input[i] == '(' || input[i] == '{') && i != length - 1) {
			if (!IsEmpty(valid)) {
				Pop(&valid, &val);
				if (val == ']' || val == '}' || val == ')') {
					Push(&valid, val);
				}
				Push(&valid, input[i]);
			} else {
				Push(&valid, input[i]);
			}
		} else if (!IsEmpty(valid)) {
			Pop(&valid, &val);
			if ((val == '(' && input[i] == ')') || (val == '{' && input[i] == '}') || (val == '[' && input[i] == ']')) {
				Push(&valid, val);
				Push(&valid, input[i]);
			} else if (val == ']' || val == '}' || val == ')'){
				Push(&valid, val);
			}
			val = ' ';
		}
		if (IsFull(valid)) return valid;
	}
	return valid;
}