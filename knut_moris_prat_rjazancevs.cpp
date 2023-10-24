#include <iostream>
#include <cstdlib>
#include <cstring>
#define N 100

using namespace std;

void knut_moris_prat(char TEXT[], char SEARCH[], int d[]);
void prefiks(char SEARCH[], int m, int d[]);

int main()
{
  char TEXT[] = "abcdfsdfsdabcdea";
  char SEARCH[] = "abcdabcdea";
  //              -1 0 -1 0 2
  // (ab) number of repetition -1 * number of letters in repetition
  // (2-1)*2 = 2
  int m = strlen(SEARCH);
  int d[m];

  if(strlen(TEXT) < strlen(SEARCH))
  {
    cout << "ERROR! TEKSTA GARUMS IR MAZAKS NEKA PARAUGA!" << endl;
  }
  else
  {
    prefiks(SEARCH, m, d);
    knut_moris_prat(TEXT, SEARCH, d);
  }

  return 0;
}

void knut_moris_prat(char TEXT[], char SEARCH[], int d[])
{
  int n = strlen(TEXT);
  int m = strlen(SEARCH);

  //cout << "n = " << n << endl;
  //cout << "m = " << m << endl;

  int i = 0, j = 0;

  while(i < n && j < m)
  {
    //cout << "i = " << i << endl;
    //cout << "j = " << j << endl;
    cout << endl;

    if(i < n && j < m)
    {
      if(j >= 0 && TEXT[i]!=SEARCH[j])
      {
        j = d[j];
      }
      else
      {
        i = i + 1;
        j = j + 1;
      }
    }
  }
  cout << "pedejais j = " << j << endl << endl;
  if(j == m)
  {
    cout << "FOUNDED!" << endl;
  }
  else cout << "NOT FOUNDED!" << endl;
}

void prefiks(char SEARCH[], int m, int d[])
{
  int j = 0;
  int k = -1;
  d[0] = -1;

  while(j < (m-1)) // strada kamer j nebus pedejais indekss
  {
    //cout << "j = " << j << endl;
    //cout << "k = " << k << endl;
    //cout << endl;

    while(k >= 0 && SEARCH[j] != SEARCH[k])
    {
      k = d[k];
    }

    j+=1;
    k+=1;

    if(SEARCH[j] == SEARCH[k])
    {
      d[j] = d[k];
    }
    else
    {
      d[j] = k;
    }
  }

  // prefiksa izvads
  for(int i = 0; i < m; i++)
  {
    cout << d[i] << " ";
  }

  cout << endl;
  //cout << SEARCH << endl;
  //cout << endl;
}
