#include<iostream>
#include<cstdlib>
#include<cstring>
#define N 100

void naiva(char T[], char S[]);

using namespace std;

int main()
{

	char T[N];
	char S[N];

	cout << "Enter string: " << endl;
	gets(T);
	cout << "Enter what need to find: " << endl;
	gets(S);
	cout << endl;
  naiva(T,S);

  cin.get();
  system("pause>nul");
  return 0;
}

void naiva(char T[], char S[])
{
	int n = 0, m = 0;
	//for(int i = 0; T[i] != '\0'; i++) n++;
	//for(int j = 0; S[j] != '\0'; j++) m++;
	n = strlen(T);
	m = strlen(S);
	//cout << "n = " << n << endl;
	//cout << "m = " << m << endl;

	int i,j;
	/*
	for(i = 0; i <= n-m && j!=m; i+=1)
	{
		for(j = 0; j < m; j+=1)
		{
			if(S[j]!=T[i+j]) break;
		}
	}
	if(j == m) cout << "FOUND";
	else cout << "NOT FOUND";
	*/
	for(i = 0; i <= n-m && j!=m; i += 1)// i kustas tad, kad nav sakritibas
	{
		for(j = 0; j < m && S[j]==T[i+j]; j += 1) // j mainas tikai tad, kad bija atrasts pirmais pareiz burts un iet talak ja burti sakrit
		{
			if(S[j]==T[i+j]);
		}
	}
	if(j == m) cout << "\nFOUND!";
	else cout << "\nNOT FOUND!";
}
