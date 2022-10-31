// The longest common subsequence in C++

#include <iostream>
#include <string.h>
using namespace std;

void Algo(char *Text, char *Pattern, int m, int n) {
  int table[m + 1][n + 1];


  // Building the matrix in bottom-up way
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        table[i][j] = 0;
      else if (Text[i - 1] == Pattern[j - 1])
        table[i][j] = table[i - 1][j - 1] + 1;
      else
        table[i][j] = max(table[i - 1][j], table[i][j - 1]);
    }
  }

  int index = table[m][n];
  char Algo[index + 1];
  Algo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (Text[i - 1] == Pattern[j - 1]) {
      Algo[index - 1] = Text[i - 1];
      i--;
      j--;
      index--;
    }

    else if (table[i - 1][j] > table[i][j - 1])
      i--;
    else
      j--;
  }

  // Printing the sub sequences
  cout << "Text : " << Text << "\nPattern : " << Pattern << "\nLongest Common Subsequence is : " << Algo << "\n";
}

int main() {
  char Text[] = "ACADBEFGIJ";
  char Pattern[] = "CBDAFI";
  int m = strlen(Text);
  int n = strlen(Pattern);

  Algo(Text, Pattern, m, n);
}
