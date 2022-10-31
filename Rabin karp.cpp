#include <bits/stdc++.h>
#include<math.h>
using namespace std;


/*void RKP(char T[],char P[],int d,int q)
{
 int n=strlen(T);
 int m=strlen(P);
 double h=(pow(d,m-1))% q;
 int p=0;
 int t=0;

 for(int j=0;j<m-1;j++)
 {
  p=(p*d+P[j])%q;
  t=(t*d+T[j])%q;
 }

int flag =0;
for(int s=0;s=n-m;s++)
{
 if(T[s]==p)
 {
  int j=1;
  while((j<=m)&&(T[s+j]==P[j]))
  {
   j=j+1;
   if(j>=m)
   {
   flag=1;
   cout<<"Pattern found at shift "<<s;
   }
  else
  {
   T[s+1]=((T[s]-T[s+1]+pow(d,m-1))*d+T[1+s+m])%q;
  }
  if(!flag)
  {
      cout<<"Pattern not found";
  }

 }

}

};

int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";

      // A prime number
    int q = 101;

      // Function Call
    RKP( txt,pat,10, q);
    return 0;
}
*/

void rabinKarp(char pattern[], char text[], int q) {
  int m = strlen(pattern);
  int n = strlen(text);
  int d=10;
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;

  // Calculate hash value for pattern and text
  for (i = 0; i < m; i++) {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }

  // Find the match
  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != pattern[j])
          break;

    }

      if (j == m)
        cout << "Pattern is found at position: " << i + 1 << endl;
    }


    else
         cout << "Pattern is  not found ";
  }
}

int main() {
  char text[] = "ABCCDDAEGFQUR";
  char pattern[] = "AEGFQURA";
  int q = 13;
  rabinKarp(pattern, text, q);
}
