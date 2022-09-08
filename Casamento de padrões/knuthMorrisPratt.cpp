#include <string>
#include <sys/time.h>
#include <vector>
using namespace std;

float timedifference_msec(struct timeval t0, struct timeval t1){
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

vector<int> pi(string s){
  vector<int> p(s.size());
  for(int i=1, j=0; i< s.size(); i++){
    while(j > 0 and s[j] != s[i])
      j = p[j-1];
    if(s[j] == s[i])
      j++;
  }
  return p;
}

vector<int> matching(string t, string s){
  vector<int> p= pi(s+'$'), match;
  for(int i=0, j=0; i <t.size(); i++){
    while(j > 0 and s[j] != t[i])
      j = p[j-1];
    if(s[j] == t[i])
      j++;
    if(j == s.size())
      match.push_back(i-j+1);
  }
  return match;
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

  string pat = "AAAAAAAAAAAAAAAAA"; 

  gettimeofday(&t0, 0);
  matching(vet, pat);
  gettimeofday(&t1, 0);

  elapsed = timedifference_msec(t0, t1);

  printf("Code executed in %f milliseconds.\n", elapsed);

  return 0;
}
