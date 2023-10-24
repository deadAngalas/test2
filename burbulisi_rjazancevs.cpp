#include<iostream>
#include<cstdlib>
#include<algorithm>
#define N 100

void create_array(int arr[], int size);
void output_array(int arr[], int size);
void burbulisi(int arr[], int size);
void burbulisi_obratnij(int arr[], int size);

using namespace std;

int main()
{

  int arr[N];
  int size;

  char f;
  do
  {
    cout << "\nEnter array size: "; cin >> size;
    cout << "\n";
    create_array(arr, size);
    //cout << "\nArray content: " << endl;
    //output_array(arr, size);

    burbulisi(arr, size);
    cout << "\n\n";
    output_array(arr, size);
    cout << "\n\n";

    cout << "Countinue? y/n: "; cin >> f;
  } while(f == 'y' || f == 'Y');

  cin.get();
  system("pause>nul");
  return 0;
}

void create_array(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << "Arr [" << i << "] element = ";
    cin >> arr[i];
  }
}

void output_array(int arr[], int size)
{
  for (int j = 0; j < size; j++)
  {
    cout << arr[j] << " ";
  }
}
//swap(arr[j], arr[j+1]);

void burbulisi(int arr[], int size)
{
  int buffer; // buffer lai saglabatu skaitli
  int i, j;
  bool isSorted;
  int apmainas = 0, salidzinasanas = 0, solus = 0;

  for(i = 0; isSorted == false; i++)
  // 1. cikls strada lidz bridim, kad masivs nebus sakartots
  {
    isSorted = true; // nozime, ka masivs ir sakartots
    for(j = 0; j < size-1-i; j++)
    // 2. cikls iet cauri rindai
    {
      if(arr[j] > arr[j+1]) // parbaude ja 1 elements ir vairak par 2, tad maina tas vietam
      {
        isSorted = false; // masivs nav sakartots
        // ja 2. cikla bija gan viena apmaina, tad japarbauda masivu velreiz 1. cikla
        buffer = arr[j]; // atceram 1 elemntu
        arr[j] = arr[j+1]; // aizvietam 1 elementu ar 2
        arr[j+1] = buffer; // 2 elementu aizvietam ar 1, kuru saglbajam bufera
        //apmainas++;
        output_array(arr, size); cout << "\n";
      }
      //salidzinasanas++;
    }
    cout << "\n";
    output_array(arr, size); cout << "\n";
    //solus++;
  }

  //cout << "\n\nApmainus skaits: " << apmainas;
  //cout << "\n\nSalidzinasanu skaits: " << salidzinasanas;
  //cout << "\n\nSolus: " << solus;

}
/*
void burbulisi_obratnij(int arr[], int size)
{
  int buffer;
  int i, j, k = 0;
  int apmainas = 0, salidzinasanas = 0, solus = 0;

  for(i = size; i > 0; i--)
  {
    for(j = size; j > 0 + 1 + k; j--)
    {
      if(arr[j-1] < arr[j-2])
      {
        buffer = arr[j-1];
        arr[j-1] = arr[j-2];
        arr[j-2] = buffer;
      }
    }
    k++;
  }
}
*/

void burbulisi_obratnij(int arr[], int size)
{
  int buffer;
  int i, j, k = 0;
  bool isSorted;
  int apmainas = 0, salidzinasanas = 0, solus = 0;

  while(isSorted == false)
  {
    isSorted = true;
    for(j = size; j > 0 + 1 + k; j--)
    {
      if(arr[j-1] < arr[j-2])
      {
        isSorted = false;
        buffer = arr[j-1];
        arr[j-1] = arr[j-2];
        arr[j-2] = buffer;
      }
    }
    k++;
  }
}
