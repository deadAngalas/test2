#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void rabina_karpa(char TEXT[], char SEARCH[]);

int main()
{
  //char TEXT[] = "helloworld";
  //char SEARCH[] = "wor";
  char TEXT[] = "476117";
  char SEARCH[] = "11";
  rabina_karpa(TEXT, SEARCH);
}

void rabina_karpa(char TEXT[], char SEARCH[])
{
    int v = 0;
    int w = 0;
    int i = 0;
    int m = strlen(SEARCH); // 2
    int n = strlen(TEXT); // 6

    while(i < m)
    {
      v += (int)SEARCH[i];
      w += (int)TEXT[i];
      i++;
    }

    i = m; // 2
    int q, k;
    bool isFound = false;

    while(i <= n && isFound == false)
    {
      cout << "\ni = " << i << endl;
      cout << "w = " << w << endl;
        if(w == v)
        {
            // naiva
            for(q = 0; q <= n-m && k!=m; q += 1)
          	{
          		for(k = 0; k < m && SEARCH[k] == TEXT[q+k]; k += 1)
          		{
          			if(SEARCH[k] == TEXT[q+k]);
          		}
          	}
          	if(k == m)
            {
              cout << "\n\tFOUND!";
              isFound = true;
            }
        }
        else
        {
          w = ((w-TEXT[i-m]) + TEXT[i]);
          i++;
        }
    }
    if (isFound == false) cout << "\n\tNOT FOUND!";
}
