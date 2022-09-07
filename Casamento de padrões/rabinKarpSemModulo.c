#include <stdio.h>
#include <string.h>
#include <sys/time.h>

float timedifference_msec(struct timeval t0, struct timeval t1){
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

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

int main(){

  struct timeval t0;
  struct timeval t1;
	float elapsed;
  char vet[10000];

  /*
  for(int i=0; i < 10000; i++)
   vet[i] = 'A' + (char)(rand()%26); 

  char pat[] = "AFHIJLESAACJKSLI"; */
  
  
  for(int i=0; i < 10000; i++)
    vet[i] = 'A';

	char pat[] = "AAAAAAAAAAAAAAAA"; 

  gettimeofday(&t0, 0);
  search(vet, pat);
  gettimeofday(&t1, 0);

  elapsed = timedifference_msec(t0, t1);

  printf("Code executed in %f milliseconds.\n", elapsed);

  return 0;
}
