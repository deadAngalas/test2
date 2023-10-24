#include<iostream>
#include<cstdlib>
#include<cstring>
#define N 100

void create_array(int arr[], int size);
void output_array(int arr[], int size);
void insert_sort_v1(int arr[], int size);
void insert_sort_v2(int arr[], int size);
void insert_sort_v3(int arr[], int size);

void fja_min_pirmEl(int arr[], int size, int &minEl, int &pirmais);

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


    insert_sort_v2(arr, size);
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
  for (int k = 0; k < size; k++)
  {
    cout << arr[k] << " ";
  }
}

void insert_sort_v1(int arr[], int size)
{
  int i,j;
  int buffer;

  int salidzinasanas = 0;
  int apmainu_skaits = 0;
  int solu_skaits = 0;

  cout << endl; output_array(arr, size); cout << " <- Sakuma masivs" << endl << endl;

  for(i = 1; i < size; i++)
  {
    for(j = i; j > 0; j--)
    {
      if(arr[j-1] > arr[j])
      {
        buffer = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = buffer;
        apmainu_skaits++;
        output_array(arr, size); cout << endl;
      }
      salidzinasanas++;
    }
    solu_skaits++;
    output_array(arr, size); cout << endl;
  }

  cout << "\nSalidzinasanu skaits: " << salidzinasanas << endl;
  cout << "Apmainu skaits: " << apmainu_skaits << endl;
  cout << "Solu skaits: " << solu_skaits << endl;
}

void insert_sort_v2(int arr[], int size)
{
  int i,j;
  int buffer;
  bool isSorted = false;
  int k = 1;

  int apmainu_skaits = 0; // gan solu gan salidzanas vienadu skaits
  int solu_skaits = 0;
  int salidzinasanas = 0;

  cout << endl; output_array(arr, size); cout << " <- Sakuma masivs" << endl << endl;
  // LAI STRĀDATU, KAD 1. ELEMENTS IR MAZĀKS PAR 2. ELEMENTU, TAD NEVAJAG NOSACĪJUMS isSorted == false
  for(i = 1; i < size && isSorted == false; i++) // iet pa visu masivu un stada lidz beigam vai kad nebus sakartots
  { // var sakt gan no 0, gan no 1, tikai otraja cikla jamaina gan j, gan indeksus
    isSorted = true; // nozime, ka masivs ir sakartots
    // pirmais elements no sakuma tiek skaitits ka sakartotais, tapec sak no 2 elementa
    for(j = i; j > 0 && arr[j-1] > arr[j]; j--) // tiek panemts 1 elements nesakartota masiva un tiek salidzinats ar sakartots masivu pirmo elementu no labas puses
    // lidz tam momentam, kad tas nebus sava vieta.
    // ja elements ir no sakartotaja ir vairak par nakamo, tad jamaina ar vietam
    {
        isSorted = false; // ja bija gan 1 apmaina, nozime, ka masivs nav sakartots, ja ne, tad masivs ir sakartots
        // apmaina
        buffer = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = buffer;
        apmainu_skaits++;
        output_array(arr, size); cout << endl;
    }
    salidzinasanas++;
    solu_skaits++;
    cout << k << ") " << endl; // vieglak saprast kur ir solis
    k++;
    output_array(arr, size); cout << endl;
  }

  cout << "\nApmainu skaits: " << apmainu_skaits << endl;
  cout << "Solu skaits: " << solu_skaits << endl;
  cout << "Salidzinasanas skaits: " << salidzinasanas << endl;
}
/*
void insert_sort_v3(int arr[], int size)
{
  int i,j;
  int buffer;
  int minEl, pirmais;

  cout << endl; output_array(arr, size); cout << " <- Sakuma masivs" << endl << endl;

  fja_min_pirmEl(arr, size, minEl, pirmais);

  for(i = 1; i < size; i++)
  {
    for(j = i; arr[j-1] > arr[j]; j--)
    {
        buffer = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = buffer;
        output_array(arr, size); cout << endl;
    }
    output_array(arr, size); cout << endl;
  }

  int L = 0, R = size - 1;
  int mid = (L+R)/2;

  while(arr[mid] > pirmais)
  {
    if(arr[mid] < pirmais) L = mid;
    else break;
    mid = (L+R)/2;
  }
  arr[0] = arr[L-1];
  arr[L-1] = pirmais;
}
*/
void fja_min_pirmEl(int arr[], int size, int &minEl, int &pirmais)
{
  int i;
  pirmais = arr[0];
  for(i = 1; i < size; i++)
  {
    if(arr[i] < arr[i-1])
    {
      minEl = arr[i];
    }
  }
  minEl -= 1;
  arr[0] = minEl;
}
