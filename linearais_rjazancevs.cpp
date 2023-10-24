#include<iostream>
#include<cstdlib>
#include<ctime>
#define N 100

void create_array(int arr[], int size);
void output_array(int arr[], int size);
void search_linearais(int arr[], int size, int x);

using namespace std;

int main()
{
  int arr[N];
  int size, x;

  char f;
  do
  {
    cout << "\nEnter array size: "; cin >> size;
    cout << "\n";

    create_array(arr, size);
    cout << "Array content: ";
    output_array(arr, size);
    cout << "\n\nWhat number need to find: "; cin >> x;

    search_linearais(arr, size, x);

    cout << "Countinue? y/n: "; cin >> f;
  } while(f == 'y' || f == 'Y');

  cin.get();
  system("pause>nul");
  return 0;
}

void create_array(int arr[], int size)
{
  srand(time(NULL));

  for (int i = 0; i < size; i++)
  {
    arr[i] = rand()%21;
  }
}

void output_array(int arr[], int size)
{
  for (int j = 0; j < size; j++)
  {
    cout << arr[j] << " ";
  }
}
void search_linearais(int arr[], int size, int x)
{
  int k; // indeksa skaititajs
  for (k = 0; k < size && arr[k]!= x; k++);
  // cikls strada lidz bridim, kad meklejamais skaitlis nav atrasts UN indeks ir mazaks par izmeru
  // lai cikls pabeidza darbu, viens no nosacijumiem jabut aplamam

  // kad cikls beidzas stradat, ir 2 iespejamie varianti:
  // 1) masiva nav meklejamo skaitli => tas nozime, ka cikls nodarbojas lidz pasam beigam un indeks (k) ir tads pats, ka masiva izmers (size).
  // parbaudijums: cout << k; pec cikla, ja nav mekl. skaitli;
  // 2) masiva ir meklejamais skaitlis => tas nozime, ka cikls beidza darbu agrak, jo arr[k] == meklajamais skaitlis, tapec indeks bus mazaks.
  if (size == k)
  {
    cout << "\nThere is no your number!\n\n";
  }
  else
  {
    cout << "\nThere is your number!\n\n";
  }
}
