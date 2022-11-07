#include <stdio.h>
#include "listlinier.h"

int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype el;
    scanf("%d", &el);

    // Masukkan kode program disini

    if (el == 0) {
        PrintInfo(fibonacci);
        return 0;
    } else if (el == 1) {
		scanf("%d", &el);
		InsVLast(&fibonacci, el);
        PrintInfo(fibonacci);
        return 0;
    } else {
		int loop = el;
		for (int i = 0; i < loop; i++) {
			if (i < 2) {
				scanf("%d", &el);
				InsVLast(&fibonacci, el);
			} else {
				int temp1, temp2;
				DelVLast(&fibonacci, &temp1);
				DelVLast(&fibonacci, &temp2);
				InsVLast(&fibonacci, temp2);
				InsVLast(&fibonacci, temp1);
				InsVLast(&fibonacci, temp1 + temp2);
			}
		}
        PrintInfo(fibonacci);
    }

    return 0;
}
