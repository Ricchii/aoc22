#include <stdio.h>
#include <string.h>

int main() {
	char c1['z'+1];
	char c2['z'+1];
	char s[100];
	char dupes[1000];
	int di = 0;

	char gp[3]['z'+1];
	int gpi = 0;
	char gpd[100];
	int gpdi = 0;
	for (int i=0;i<3;i++){
		memset(gp[i], 0, 'z'+1);
	}

	while (fgets(s, 100, stdin) != NULL) {
		int l = (int) strlen(s);
		memset(c1, 0, 'z'+1);
		memset(c2, 0, 'z'+1);
		for(int i=0;i<l/2;i++) {
			c1[s[i]]=1;
			c2[s[(l/2)+i]]=1;
		}
		for(int i=0;i<'z'+1;i++) {
			if (c1[i] && c2[i]) {
				dupes[di]=i;
				di++;
			}
		}

		for(int i=0;i<l-1;i++) {
			gp[gpi][s[i]]=1;
		}
		if (gpi==2) {
			for(int i=0;i<'z'+1;i++) {
				if (gp[0][i] && gp[1][i] && gp[2][i]) {
					gpd[gpdi] = i;
					gpdi++;
				}
			}
			gpi = -1;
			for (int i=0;i<3;i++){
				memset(gp[i], 0, 'z'+1);
			}
		}
		gpi++;
	}

	int ans = 0;
	for(int i=0;i<di;i++) {
		if(dupes[i] >= 'a' && dupes[i] <= 'z') {
			ans += dupes[i]-'a'+1; }
		else {  ans += dupes[i]-'A'+27;
		}
	}

	int ans2 = 0;
	for(int i=0;i<gpdi;i++) {
		if(gpd[i] >= 'a' && gpd[i] <= 'z') {
			ans2 += gpd[i]-'a'+1; }
		else {  ans2 += gpd[i]-'A'+27;
		}
	}

	printf("%d\n%d\n", ans, ans2);
}
