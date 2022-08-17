#include <stdio.h>
#include <string.h>

#define d 256

void search(char pat[], char txt[])
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; 
	int t = 0; 
	int h = 1;

	for (i = 0; i < M - 1; i++)
		h = (h * d);

	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]);
		t = (d * t + txt[i]);
	}

	for (i = 0; i <= N - M; i++) {

		if (p == t) {
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j])
					break;
			}

			if (j == M)
				printf("Casamento encontrado na posicao %d \n", i);
		}

		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]);
		}
	}
}

int main()
{
	char txt[] = "AABAACAADAABAABA";
	char pat[] = "AABA";
        
	search(pat, txt);
	return 0;
}
