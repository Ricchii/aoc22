#include <stdio.h>

const int rock = 1;
const int paper = 2;
const int scisors = 3;
const int lose = 0;
const int draw = 3;
const int win = 6;

int main() {
	int score = 0;
	char s[5];
	char e, m;
	while (fgets(s, 5, stdin) != NULL) {
		e = s[0];
		m = s[2];
		switch (e) {
			case 'A':
				switch (m) {
					case 'X':
						score += rock+draw;
						break;
					case 'Y':
						score += paper+win;
						break;
					case 'Z':
						score += scisors+lose;
						break;
				}
				break;
			case 'B':
				switch (m) {
					case 'X':
						score += rock+lose;
						break;
					case 'Y':
						score += paper+draw;
						break;
					case 'Z':
						score += scisors+win;
						break;
				}
				break;
			case 'C':
				switch (m) {
					case 'X':
						score += rock+win;
						break;
					case 'Y':
						score += paper+lose;
						break;
					case 'Z':
						score += scisors+draw;
						break;
				}
				break;
		}
	}
	printf("%d\n", score);
}

