#include <stdio.h>
#include <string.h>

const int nstacks = 9;
const int maxcrates = 100;

int main() {
	char stacks[nstacks][maxcrates];
	char l[50];
	int h = 7;
	for (int i=0;i<nstacks;i++)
		memset(stacks[i], '\0', maxcrates);
	while (fgets(l, 50, stdin) != NULL && h >= 0) {
		for (int i=0;i<nstacks;i++) {
			char c = l[4*i+1];
			if (c != ' ') {
				stacks[i][h] = c;
			}
		}
		h--;
	}
	while (strlen(l) > 2) {
		fgets(l, 50, stdin);
	}
	int n,f,t;
	while (fgets(l, 50, stdin) != NULL) {
		sscanf(l, "move %d from %d to %d", &n,&f,&t);
		f--;
		t--;

		int ft,tt;
		ft = strlen(stacks[f])-1;
		tt = strlen(stacks[t])-1;
		
		char c;
		for (int i=0;i<n;i++) {
			c = stacks[f][ft-(n-i-1)];
			stacks[t][tt+i+1] = c;
		}
		for (int i=0;i<n;i++) {
			stacks[f][ft-i] = '\0';
		}
	}
	for (int i=0;i<nstacks;i++) {
		printf("%c", stacks[i][strlen(stacks[i])-1]);
	}
	puts("");
}
