#include <stdio.h>
#include <string.h>

int main() {
	char l[200];
	fgets(l, 200, stdin);
	int gs = strlen(l)-1;
	int grid[gs][gs];
	int vis[gs][gs];
	for(int i=0;i<gs;i++) {
		for(int j=0;j<gs;j++) {
			vis[i][j]=0;
		}
	}
	for(int i=0;i<gs;i++) {
		grid[0][i] = l[i]-'0';
	}
	int li=1;
	while (fgets(l, 200, stdin) != NULL) {
		for(int i=0;i<gs;i++) {
			grid[li][i] = l[i]-'0';
		}
		li++;
	}
	int fl,ft,fr,fb;
	for (int i=0;i<gs;i++) {
		fl = ft = fr = fb = -1;
		for(int j=0;j<gs;j++) {
			if (grid[i][j] > fl) {
				vis[i][j] = 1;
				fl = grid[i][j];
			}
			if (grid[j][i] > ft) {
				vis[j][i] = 1;
				ft = grid[j][i];
			}
			if (grid[i][gs-j-1] > fr) {
				vis[i][gs-j-1] = 1;
				fr = grid[i][gs-j-1];
			}
			if (grid[gs-j-1][i] > fb) {
				vis[gs-j-1][i] = 1;
				fb = grid[gs-j-1][i];
			}
		}
	}
	int sum = 0;
	for(int i=0;i<gs;i++) {
		for(int j=0;j<gs;j++) {
			sum += vis[i][j];
		}
	}
	printf("%d\n", sum);
	int ss=0;
	for(int i=1;i<gs-1;i++) {
		for(int j=1;j<gs-1;j++) {
			int h,u,d,l,r;
			h = grid[i][j];
			l=j-1;
			r=j+1;
			u=i-1;
			d=i+1;
			while (l>0 && grid[i][l] < h) {
				l--;
			}
			while (r<gs-1 && grid[i][r] < h) {
				r++;
			}
			while (u>0 && grid[u][j] < h) {
				u--;
			}
			while (d<gs-1 && grid[d][j] < h) {
				d++;
			}
			int nss = (j-l)*(r-j)*(i-u)*(d-i);
			if (nss > ss) {
				ss = nss;
			}
		}
	}
	printf("%d\n",ss);
}
