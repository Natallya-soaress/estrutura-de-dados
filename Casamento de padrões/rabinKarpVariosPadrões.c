#include <stdio.h>
#include <string.h>
#include <sys/time.h>

float timedifference_msec(struct timeval t0, struct timeval t1){
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

#define d 256

void search(char pat[], char txt[])
{
  int q = 101;
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; 
	int t = 0; 
	int h = 1;

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
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
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

			if (t < 0)
				t = (t + q);
		}
	}
}

void searchPattens(char pattens[5][10], char txt[]){
  for (int i=0; i<5; i++) {
    printf("Padrão %d: %s \n", i, pattens[i]);
		search(pattens[i], txt);
	}
  
}

int main()
{
	
	char txt[] = "IXIIIAABAACAADAABAABAIXIII";
	char pat[] = "AABA"; 

  char pattens[5][10] = {"AABA",
				"XA",
				"CAA",
				"OOO",
				"IXIII"};
  
searchPattens(pattens, txt);
	
	return 0;
}
