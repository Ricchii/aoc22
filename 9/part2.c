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

void movehead(char d, int* x, int* y) {
	if (d == 'U') {*y += 1;}
	if (d == 'D') {*y -= 1;}
	if (d == 'L') {*x -= 1;}
	if (d == 'R') {*x += 1;}
}

void follow(int* hx, int* hy, int* tx, int* ty) {
	int dx = *hx - *tx;
	int dy = *hy - *ty;
	if (abs(dx) + abs(dy) > 2 || abs(dy)>1 || abs(dx)>1) {
		if(dx != 0) {dx = dx/abs(dx);}
		if(dy != 0) {dy = dy/abs(dy);}
		*tx += dx;
		*ty += dy;
	}
}

int main() {
	int knots = 10; //2 for part 1, 10 for part 2.
	int rope[knots][2];
	for(int i=0;i<knots;i++){rope[i][0]=0;rope[i][1]=0;}
	char d;
	int n;
	struct posl* pl = malloc(sizeof(struct posl));
	pl->next = NULL;
	pl->pos[0] = rope[1][0];
	pl->pos[1] = rope[1][1];
	char l[5];
	while(fgets(l, 5, stdin) != NULL) {
		sscanf(l, "%c %d", &d, &n);
		for (int i=0;i<n;i++) {
			movehead(d, &(rope[0][0]), &(rope[0][1]));
			for(int i=1;i<knots;i++) {
				follow(&(rope[i-1][0]), &(rope[i-1][1]), &(rope[i][0]), &(rope[i][1]));
			}
			struct posl* newp = malloc(sizeof(struct posl));
			newp->pos[0] = rope[knots-1][0];
			newp->pos[1] = rope[knots-1][1];
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
		//printf("|%d,%d\n",p->pos[0],p->pos[1]);
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
	//for(int j=0;j<i;j++) {printf("%d,%d\n",pa[j][0],pa[j][1]);}
	printf("%d\n", i);
}

