#include <stdio.h>
#include <string.h>
#include <sys/time.h>

float timedifference_msec(struct timeval t0, struct timeval t1){
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void ForcaBruta(char T[], char P[]){

    long i , j , k;
    int n = strlen(T);
    int m = strlen(P);

    for (i = 1; i <= (n - m + 1); i++){ 
        k=i; j=1;
        while(T[k-1] == P[j-1] && j <= m){ 
            j++;k++;
        }
        if (j > m){
            printf("Casamento na posicao%3ld\n", i-1);
        }
    }
 } 

int main(){

    struct timeval t0;
  	struct timeval t1;
	float elapsed;

	/*
	char txt[] = "AAAAAAAAAAAAAAAA";
	char pat[] = "AAAA"; */

    
    char txt[] = "AABAACAADAABAABA";
	char pat[] = "AABA"; 

    gettimeofday(&t0, 0);
  	ForcaBruta(txt, pat);
  	gettimeofday(&t1, 0);

  	elapsed = timedifference_msec(t0, t1);

  	printf("Code executed in %f milliseconds.\n", elapsed);

    return 0;
}