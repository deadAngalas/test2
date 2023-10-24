#include<iostream>
#include<cstdlib>
#include<cstring>
#define N 100

void create_array(int arr[], int size);
void output_array(int arr[], int size);
void select_sort(int arr[], int size);

void select_sort_test(int arr[], int size, int L, int R);
void ierobezojums(int &L, int &R);

using namespace std;

int main()
{

  int arr[N];
  int size;
  int L, R;

  char f;
  do
  {
    cout << "\nEnter array size: "; cin >> size;
    cout << "\n";
    create_array(arr, size);

    select_sort(arr, size);
    //ierobezojums(L, R);
    //select_sort_test(arr, size, L, R);
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

void select_sort(int arr[], int size)
{
  int minEl_idx; // minimala elementa index
  int buffer;
  int i, j;
  int k = 1;

  int salidzinasanas = 0;
  int apmainu_skaits = 0;
  int solu_skaits = 0;

  cout << endl << "Sakuma masivs: " ; output_array(arr, size); cout << endl;

  for(i = 0; i < size - 1; i++) // size - 1 = last element    !ja bus mazak, tad algoritms var nesakartot lidz galam
  {
    minEl_idx = i; // sakuma minimalais elements ir pats pirmais elements - nakamajos solos, tas bus 2,3,4,5,... elements
    for(j = i + 1; j < size; j++) // iet caur unsorted masivu (sakot no masivs[j] - otrais elements), nenemot tos skaitlis, kurie jau ir sava vieta (mazakie)
    { // j ir kā poziciju radītājs, neredzu jegas atceret kads vispar bija sis skaitlis, vienkarsi, kur tas atrodas
      if(arr[j] < arr[minEl_idx]) // mekle vismazako skaitli
      minEl_idx = j; // ja atrada vel mazako skaitli [j], tad jauns minimalais elements ir sis skaitlis
      salidzinasanas++;
    }
    // kad pabeidza meklet mazako skaitli, notiek apmaina
    if(arr[i] > arr[minEl_idx]) // notiek apmaina tikai tad, kad elements no kreisas ir lielaks par minimalo - ir jega mainit vai ne
    { // arr[i] ir elements masiva un ja tas ir lielaks (3) neka atrastais minimalais elements (1), tad notiek apmaina
      buffer = arr[i];
      arr[i] = arr[minEl_idx];
      arr[minEl_idx] = buffer;
      apmainu_skaits++;
    }
    solu_skaits++;
    cout << k << ") ";
    k++;
    output_array(arr, size); cout << "\n";
  }
  cout << "\nSalidzinasanu skaits: " << salidzinasanas << endl;
  cout << "Apmainu skaits: " << apmainu_skaits << endl;
  cout << "Solu skaits: " << solu_skaits << endl;
}

void select_sort_test(int arr[], int size, int L, int R)
{
  int minEl_idx; // minimala elementa index
  int buffer;
  int i, j;

  int salidzinasanas = 0;
  int apmainu_skaits = 0;
  int solu_skaits = 0;

  cout << endl << "Sakuma masivs: " ; output_array(arr, size); cout << endl;

  for(i = 0; i < size - 1; i++)
  {
    minEl_idx = L - 1;
    for(j = L; j >= L && j < R; j++)
    {
      if(arr[j] < arr[minEl_idx])
      minEl_idx = j;
    }
    if(arr[j] > arr[minEl_idx])
    {
      buffer = arr[L-1];
      arr[L-1] = arr[minEl_idx];
      arr[minEl_idx] = buffer;
    }
    L++;
    cout << "ppp" << endl;
    output_array(arr, size); cout << "\n";
  }
}

// min masīva elementa indeksa meklēšana ierobežotā apgabalā
// ka es saprotu, lietotajs var izveleties kadu dalu no masiva karot...
void ierobezojums(int &L, int &R)
{
  cout << "\nKreisa robeza (elements numurs): "; cin >> L;
  cout << "Laba robeza (elementa numurs, <= size): "; cin >> R;
}
