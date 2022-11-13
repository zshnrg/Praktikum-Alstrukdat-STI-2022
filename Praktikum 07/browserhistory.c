/*
Nama		: Rozan Ghosani
NIM			: 18221121
Tanggal		: 24 Oktober 2022
Topik		: Stack
Deskripsi	: Implementasi browserhistory.h
*/

#include <stdio.h>
#include "browserhistory.h"

void browserHistoryVisit(Stack *openedTab, Stack *history, char *url)
/**
 * Menambahkan url ke openedTab
 * I.S. openedTab mungkin kosong, tabel penampung elemen stack TIDAK penuh
 * F.S. url menjadi TOP yang baru, TOP bertambah 1, history kosong
 */
{
	Push(openedTab, url);
	browserHistoryFree(history);
}
 

char *currentUrl(Stack *openedTab)
/**
 * Mengembalikan url yang sedang dibuka
 * I.S. openedTab tidak mungkin kosong
 * F.S. url adalah nilai elemen TOP yang lama
 */
{
	return InfoTop(*openedTab);
}


char *browserHistoryBack(Stack *openedTab, Stack *history, int steps)
/**
 * Mengembalikan url yang sedang dibuka setelah kembali ke sebelumnya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP berkurang 1
 */
{
	if (IsEmpty(*openedTab)) return NULL;
	for (int i = 0; i < steps; i++) {
		Push(history, InfoTop(*openedTab));
		infotype temp; Pop(openedTab, &temp);
	}
	return InfoTop(*openedTab);
}

char *browserHistoryForward(Stack *openedTab, Stack *history, int steps)
/**
 * Mengembalikan url yang sedang dibuka setelah maju ke depannya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP bertambah 1
 */
{
	if (IsEmpty(*history)) return NULL;
	for (int i = 0; i < steps; i++) {
		Push(openedTab, InfoTop(*history));
		infotype temp; Pop(history, &temp);
	}
	return InfoTop(*openedTab);
}

void browserHistoryFree(Stack *history)
/**
 * Mengosongkan history
 * I.S. history tidak mungkin kosong
 * F.S. history kosong
 */
{
	while (!IsEmpty(*history)) {
		Pop(history, &InfoTop(*history));
	}
}
