#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct posl{
	int pos[2];
	struct posl* next;
};

int cont(int pa[][2], int p[], int size) {
	for (int i=0;i<size;i++) {
		if (pa[i][0] == p[0] && pa[i][1] == p[1]) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int hpos[2] = {0, 0};
	int tpos[2] = {0, 0};
	char d;
	int n;
	struct posl* pl = malloc(sizeof(struct posl));
	pl->next = NULL;
	pl->pos[0] = tpos[0];
	pl->pos[1] = tpos[1];
	char l[5];
	while(fgets(l, 5, stdin) != NULL) {
		sscanf(l, "%c %d", &d, &n);
		for (int i=0;i<n;i++) {
			if (d == 'U') {hpos[1] += 1;}
			if (d == 'D') {hpos[1] -= 1;}
			if (d == 'L') {hpos[0] -= 1;}
			if (d == 'R') {hpos[0] += 1;}
			int dx = hpos[0]-tpos[0];
			int dy = hpos[1]-tpos[1];
			//printf("%d,%d | ",dx,dy);
			if (abs(dx) + abs(dy) > 2 || abs(dy)>1 || abs(dx)>1) {
				if(dx != 0) {dx = dx/abs(dx);}
				if(dy != 0) {dy = dy/abs(dy);}
				tpos[0] += dx;
				tpos[1] += dy;
			}
			printf("%d,%d | ",hpos[0],hpos[1]);
			printf("%d,%d\n",tpos[0],tpos[1]);
			struct posl* newp = malloc(sizeof(struct posl));
			newp->pos[0] = tpos[0];
			newp->pos[1] = tpos[1];
			newp->next = pl;
			pl = newp;
		}
	}
	puts("\n");
	int size = 1;
	for(struct posl* p=pl;p->next != NULL;p=p->next) {size++;}
	int pa[size][2];
	pa[0][0]=pl->pos[0];
	pa[0][1]=pl->pos[1];
	int i=1;
	struct posl* p=pl->next;
	for(;p->next != NULL;p=p->next) {
		printf("|%d,%d\n",p->pos[0],p->pos[1]);
		if (!cont(pa, p->pos, i)) {
			pa[i][0] = p->pos[0];
			pa[i][1] = p->pos[1];
			i++;
		}
	}
	if (!cont(pa, p->pos, i)) {
		pa[i][0] = p->pos[0];
		pa[i][1] = p->pos[1];
		i++;
	}
	for(int j=0;j<i;j++) {printf("%d,%d\n",pa[j][0],pa[j][1]);}
	printf("%d\n", i);
}

