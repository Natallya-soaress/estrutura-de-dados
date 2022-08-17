#include <stdio.h>
#include <string.h>

void ForcaBruta(char T[], char P[]){ 
    long i , j , k;
    int n = strlen(T);
    int m = strlen(P);
    for (i = 1; i <= (n - m + 1); i++){ 
        k=i; j=1;
        while(T[k-1]==P[j-1]&&j<=m){ 
            j++;k++;
        }
        if (j > m){
            printf("Casamento na posicao%3ld\n", i-1);
        }
    }
 } 

int main(){

    char txt[] = "AABAACAADAABAABA";
	char pat[] = "AABA";
    
    ForcaBruta(txt, pat);

    return 0;
}