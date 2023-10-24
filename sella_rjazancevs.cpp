#include<iostream>
#include<cstdlib>
#include<cstring>
#define N 100

void create_array(int arr[], int size);
void output_array(int arr[], int size);
void sella(int arr[], int size);

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
    cout << endl;

    sella(arr, size);
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

void sella(int arr[], int size)
{
  int step = size / 2; // jeb h
  int buffer;
  int i,j;
  int k = 1;

  int solis = 0;
  int apmaina = 0;
  int salidzinasana = 0;

  output_array(arr, size); cout << " <- Sakuma masivs.\n\n";

  while(step > 0) // pedejais step ir 1
  {
    //cout << "\nStep: " << step << endl << endl;
    for(i = step; i < size; i++)
    {
      buffer = arr[i]; // iegaumet, lai talak nepazaudet, jo sis skaitlis bus aizvietots
      for(j = i; j >= step && arr[j-step] > buffer; j = j - step)
      { //apmaina
        arr[j] = arr[j-step];
        apmaina++;
        cout << "Ap: "; output_array(arr, size); cout << endl;
      } // ieksejais for cikls
      salidzinasana++;
      arr[j] = buffer; // aizvietosana
      cout << "Az: " ; output_array(arr, size); cout << endl;
    } // arejais for cikls
    step /= 2; // samazinat step 2 reizes
    cout << "\n" << k <<") "; output_array(arr, size); cout << endl; // rezultats pec katra sola
    k++;
    solis++;
  }

  cout << "\nSolu skaits: " << solis << endl;
  cout << "Apmainu skaits: " << apmaina << endl;
  cout << "Salidzinasanu skaits: " << salidzinasana << endl;
}
