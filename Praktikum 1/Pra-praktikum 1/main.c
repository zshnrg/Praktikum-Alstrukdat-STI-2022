/*
Nama     : Rozan Ghosani
NIM      : 18221121

Tanggal  : 4 September 2022
Topik    : Pra-praktikum 1
Deskripsi: Menerima masukkan detik dan mengeluarkan keluaran dalam format jam, menit, dan detik. 
*/

#include <stdio.h>

int main() {
	//KAMUS
	int time;
	//ALGORITMA
	scanf("%d", &time);
	printf("%d detik = %d jam %d menit %d detik\n", time, time/3600, (time%3600)/60, (time%60));
	return 0;
}