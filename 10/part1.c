#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int cycle = 1;
	char l[20];
	char op[5];
	int n;
	int x = 1;
	int sum = 0;
	char crt[6][40];
	for(int i=0;i<6;i++){for(int j=0;j<40;j++){crt[i][j]='.';}}

	while (fgets(l, 20, stdin) != NULL && cycle <= 240) {
		sscanf(l, "%s", &op[0]);
		int cn;
		if (strcmp(op, "noop") == 0) {cn = 0;}
		if (strcmp(op, "addx") == 0) {
			cn = 1;
			sscanf(&l[5], "%d", &n);
		}

		for (;cn>=0;cn--) {
			// ""during""
			if ((cycle-20)%40 == 0 && cycle <= 220) {
				//printf("%d,%d\n", cycle, x);
				sum += cycle*x;
			}
			if (x >= -1 || x <= 40) {
				int r = (cycle-1)/40;
				int c = (cycle-1)%40;
				if (abs(x-c)<=1) {
					crt[r][c]='#';
				}
			}
			cycle++;
		}
		// ""after""
		if (strcmp(op, "addx") == 0) {
			x += n;
		}
	}
	printf("%d\n", sum);
	for(int i=0;i<6;i++){for(int j=0;j<40;j++){printf("%c",crt[i][j]);}puts("");}
}
