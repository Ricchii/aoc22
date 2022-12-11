#include <stdio.h>
#include <string.h>

int top(char stacks[][100], int stack) {
	for(int i=0;i<100;i++) {
		if (stacks[stack][i] == 0) {
			return i-1;
		}
	}
}

void stackprint(char stacks[9][100]) {
	for (int i=0;i<9;i++) {
		int j=0;
		while (stacks[i][j] != 0) {
			printf("%c", stacks[i][j]);
			j++;
		}
		printf("\n");
	}
}

int main() {
	char l[50];
	char stacks[9][100];
	for (int i=0;i<9;i++) {
		memset(stacks[i], 0, 100);
	}

	int ii = 0;
	while ((fgets(l, 50, stdin) != NULL) && (strlen(l) > 2)) {
		for(int i=0;i<9;i++) {
			stacks[i][8-ii] = l[4*i +1];
			if (stacks[i][8-ii] == ' ') {
				stacks[i][8-ii] = 0;
			}
		}
		ii++;
	}
	
	int n,f,t;
	char c;
	stackprint(stacks);
	while (fgets(l, 50, stdin) != NULL) {
		sscanf(l, "move %d from %d to %d", &n, &f, &t);
		//printf("%d %d->%d\n", n, f, t);
		f--;
		t--;
		for (int i=0;i<n;i++) {
			c = stacks[f][top(stacks,f)];
			stacks[f][top(stacks,f)] = 0;
			stacks[t][top(stacks,t)+1] = c;
		}
		//stackprint(stacks);
		//printf("\n");
	}
	for(int i=0;i<9;i++) {
		printf("%c", stacks[i][top(stacks,i)]);
		puts("");
	}
}
