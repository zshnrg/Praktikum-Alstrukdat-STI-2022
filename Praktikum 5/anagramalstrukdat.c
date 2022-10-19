/*
Nama		: Rozan Ghosani
NIM			: 18221121
Tanggal		: 3 Oktober 2022
Topik		: Mesin
Deskripsi	: Implementasi anagramalstrukdat.h
*/

#include <stdio.h> 
#include "anagramalstrukdat.h"
#include "mesinkata.h"
#include "mesinkarakterv2.h"
#include "boolean.h"


/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength (char* string) {
	int len = 0;
	while (string[len] != '\0') {
		len++;
	}
	return len;
}

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command) {
	Word Kata;
	int i = 0;
	for (i = 0; i < stringLength(command); i++) {
		Kata.TabWord[i] = command[i];
	}
	Kata.Length = stringLength(command);
	return Kata;
}

/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2) {
	if (string1.Length != string2.Length) {
		return 0;
	}
	int freq1[26] = {0}, freq2[26] = {0}, i = 0;

	while (string1.TabWord[i] != '\0') {
		freq1[string1.TabWord[i] - 'a']++;
		i++;
	}
	i = 0;
	while (string2.TabWord[i] != '\0') {
		freq2[string2.TabWord[i] - 'a']++;
		i++;
	}
	for (i = 0; i < 26; i++) {
		if (freq1[i] != freq2[i]) {
			return 0;
		}
	}
	return 1;
}

/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat 
    pada argumen frek */
void anagramalstrukdat(int* frek) {
	int count = 0;
	Word alstrukdat = toKata("alstrukdat");

	STARTWORD();
	while (!isEndWord()) {
		if (isAnagram(alstrukdat, currentWord)) {
			count += 1;
		}
		ADVWORD();
	}
	*frek = count;
}
