/*
Nama		: Rozan Ghosani
NIM			: 18221121	
Tanggal		: 31 Oktober 2022
Topik		: Set, Map, dan Hash
Deskripsi	: Implementasi duplicate.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "duplicate.h"

/*
    Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
        Contoh:
            arrToSet
                <- arr = [1, 1, 3]
                <- arrSize = 3
            -> [1, 3]
*/
Set arrToSet(int* arr, int arrSize)

/*
    Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
    kemudian kembalikan isinya secara menurun

    Penjelasan Parameter:
    Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
    Parameter 2: arrSize, merupakan panjang arr
    Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
        dan elemen-elemennya terurut menurun
    Parameter 4: arrResSize, merupakan panjang arrRes

    Contoh: 
        removeDuplicate
            <- arr = [1, 1, 2, 3]
            <- arrSize = 4
            -> arrRes = [3, 2, 1]
            -> arrResSize = 3
        removeDuplicate
            <- arr = [3, 1, 1]
            <- arrSize = 3
            -> arrRes = [3, 1]
            -> arrResSize = 2
*/
{
	Set S; CreateEmpty(&S);
	for (int i = 0; i < arrSize; i++) {
		Insert(&S, arr[i]);
	}
	return S;
}

void removeDuplicateDesc(int* arr, int arrSize, int* arrRes, int* arrResSize)
{
	int i, j, temp;
	Set Unique; CreateEmpty(&Unique);
    
	for (i = 0; i < arrSize - 1; i++) {
		for (int j = 1; j < arrSize - i; j++ ){
            if (arr[j-1] < arr[j]) { 
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
		}
	}
    
	Unique = arrToSet(arr, arrSize);
	*arrResSize = Unique.Count;
	for (i = 0; i < *arrResSize; i++) {
		arrRes[i] = Unique.Elements[i];
	}    
}