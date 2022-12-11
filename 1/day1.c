#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	long int elves[1000];
	int i = 0;
	char s[50];
	while (fgets(s, 50, stdin) != NULL) {
		//printf("%d\n", (int)strlen(s));
		if (strlen(s) > 2) {
			elves[i] += atol(s);
		} else {
			i++;
		}
	}
	int e = i;
	//printf("%d\n", e);
	int elf, elf2, elf3;
	elf = elf2 = elf3 = 0;
	for(i=0; i<=e; i++) {
		if (elves[i] >= elves[elf]) {
			elf3 = elf2;
			elf2 = elf;
			elf = i;
		}else if(elves[i] >= elves[elf2]) {
			elf3 = elf2;
			elf2 = i;
		}else if(elves[i] >= elves[elf3]) {
			elf3 = i;
		}
	}
	printf("%ld\n", elves[elf]);
	//printf("%ld, %ld, %ld\n", elves[elf], elves[elf2], elves[elf3]);
	printf("%ld\n", (elves[elf] + elves[elf2] + elves[elf3]));
}
