#include <iostream>
#include <cstdlib>
#include <cstring>
#define N 100

using namespace std;

void boyerMoore(char TEXT[], char SEARCH[]);

int main()
{
  char TEXT[] = "This is text";
  char SEARCH[] = "s is";
  //               1321
  boyerMoore(TEXT, SEARCH);
}

void boyerMoore(char TEXT[], char SEARCH[])
{
  int m = strlen(SEARCH); // 3
  int n = strlen(TEXT); // 10
  int nob[N]; // nobides masivs

  int i,j;
  int k = 1; // nobides skaitlu raditajs

 // NOBIDES MASIVA VEIDOSANA ----------------------------------------
  for(i = m-1; i >= 0; i--)
  {
    if(i == m-1)
    {
      nob[i] = k;
      k++;
    }
    else
    {
      bool isSimilar = false;
      for(j = i; j <= m-2 && isSimilar != true; j++)
      {
        if(SEARCH[i] == SEARCH[j+1])
        {
          //cout << "SEARCH[j]" << SEARCH[j] << endl;
          //cout << "SEARCH[j+1]" << SEARCH[j+1] << endl;
          nob[i] = nob[j+1];
          k++;
          isSimilar = true;
        }
      }
      if(isSimilar == false)
      {
        nob[i] = k;
        k++;
      }
    }
  }

// masiva izvads

  for(j = 0; j < m; j++)
  {
    cout << nob[j];
  }
  cout << endl;

// -----------------------------------------------------------------
  int s = 0;
  bool isFounded = false;
  // 0 <= 7
  while(s <= n-m && isFounded != true)
  {
    j = m-1; // 2                    s = 0
    cout << "s = " << s << endl;
    cout << "pered ciklom j = " << j << endl;
    //cout << "SEARCH[j] = " << SEARCH[j] << endl; // o
    //cout << "TEXT[s+j] = " << TEXT[s+j] << endl; // l
    while(j >= 0 && SEARCH[j] == TEXT[s+j])
    {
      cout << "SEARCH[j] = " << SEARCH[j] << endl; // o
      cout << "TEXT[s+j] = " << TEXT[s+j] << endl; // l
      j--;
    }
    // j = 2
    //cout << "\n\nj = " << j << endl;
    //cout << "SEARCH[j] = " << SEARCH[j] << endl;
    //cout << "TEXT[s+j] = " << TEXT[s+j] << endl;
    //isFounded = true;

    if(j < 0) // если все символы совпали, значит нашли
    {
      cout << "\nFOUNDED!" << endl;
      isFounded = true;
    }
    else // так как j != -1 (все совпали) идет свдиг
    {
      //cout << "nob[s+j] = " << nob[j] << endl;
      //s = s + max(1, nob[j]); // 1 это минимальный сдвиг, если не совпали 1 буквы
      s = s + nob[j];
    }
  }
  if(isFounded == false) cout << "\nNOT FOUNDED!" << endl;
}
