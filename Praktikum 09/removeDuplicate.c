#include "listlinier.h"

List removeDuplicate(List l) {
	if (!IsEmpty(l)) {
		List Hasil; CreateEmpty(&Hasil);
		List l1; CreateEmpty(&l1);
		
		infotype val;
		DelVFirst(&l, &val);
		while (Search(l, val) != Nil) {
			DelP(&l, val);
		}
		InsVFirst(&l1, val);
		
		List l2; CreateEmpty(&l2);
		l2 = removeDuplicate(l);
	
		Konkat1(&l1, &l2, &Hasil);
		return Hasil;
	} else {
		return l;
	}
}

/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/
