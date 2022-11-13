/*
Nama		: Rozan Ghosani
NIM			: 18221121
Tanggal		: 3 Oktober 2022
Topik		: Mesin
Deskripsi	: Implementasi hitungfrekuensi.h
*/

#include <stdio.h> 
#include "mesinkarakter.h"

int hitungfrekuensi() {
	START();
	int freq = 0;
	while (currentChar != MARK) {
		if ((GetCC() == 't' || GetCC() == 'T') && currentChar != MARK) {
			ADV();
			if ((GetCC() == 'i' || GetCC() == 'I') && currentChar != MARK) {
				ADV();
				if ((GetCC() == 'g' || GetCC() == 'G') && currentChar != MARK) {
					ADV();
					if ((GetCC() == 'a' || GetCC() == 'A') && currentChar != MARK) {
						ADV();
						freq++;
					} else {ADV();}
				} else {ADV();}
			} else {ADV();}
		} else {ADV();}
	}
	return freq;
}
