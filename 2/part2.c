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
						score += lose+scisors;
						break;
					case 'Y':
						score += draw+rock;
						break;
					case 'Z':
						score += win+paper;
						break;
				}
				break;
			case 'B':
				switch (m) {
					case 'X':
						score += lose+rock;
						break;
					case 'Y':
						score += draw+paper;
						break;
					case 'Z':
						score += win+scisors;
						break;
				}
				break;
			case 'C':
				switch (m) {
					case 'X':
						score += lose+paper;
						break;
					case 'Y':
						score += draw+scisors;
						break;
					case 'Z':
						score += win+rock;
						break;
				}
				break;
		}
	}
	printf("%d\n", score);
}

