#include <stdio.h>

int contains(int s1, int e1, int s2, int e2) {
	return s1 <= s2 && e1 >= e2;
}

int overlaps(int s1, int e1, int s2, int e2) {
	return (s1 <= s2 && e1 >= s2) || (s2 <= s1 && e2 >= s1);
}

int main() {
	int r1s,r1e,r2s,r2e;
	int sum = 0;
	int sum2 = 0;
	while (scanf("%d-%d,%d-%d", &r1s,&r1e,&r2s,&r2e) != EOF) {
		sum += (contains(r1s,r1e,r2s,r2e)||contains(r2s,r2e,r1s,r1e));
		sum2 += overlaps(r1s,r1e,r2s,r2e);
	}
	printf("%d\n%d\n", sum, sum2);
}
