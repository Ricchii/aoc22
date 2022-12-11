#include <stdio.h>
#include <string.h>

int uniq(char* s, int n) {
	for (int i=0;i<n-1;i++) {
		if (strchr(&s[i+1], s[i]) != NULL) {
			return 0;
		}
	}
	return 1;
}

int main() {
	char s[5000];
	fgets(s, 5000, stdin);
	int p1,p2;
	p1 = p2 = 0;
	for(int i=0;i<(strlen(s)-4);i++) {
		char ss[5]; ss[4]='\0';
		strncpy(ss, &s[i], 4);
		if (uniq(ss, 4) && p1==0 ) {
			p1 = i+4;
			printf("%d\n",p1);
		}
		char sss[15]; sss[14]='\0';
		strncpy(sss, &s[i], 14);
		if (uniq(sss, 14) && p2==0) {
			p2 = i+14;
			printf("%d\n",p2);
		}
	}
}
