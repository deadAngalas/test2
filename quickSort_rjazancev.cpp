#include<iostream>
#include<cstdlib>
#include<cstring>
#define N 100

void create_array(int arr[], int size);
void output_array(int arr[], int size);
void quick(int arr[], int first, int last, int size);

using namespace std;

int main()
{

  int arr[N];
  int size;

  char f;
  do
  {
    cout << "\nEnter array size: "; cin >> size;
    cout << endl;
    create_array(arr, size);

    int first = 0, last = size - 1; // pirmaja un pedeja elemnta indeksi

    cout << "\n\nUnsorted array: \n";
    output_array(arr, size);
    quick(arr, first, last, size);
    cout << "\n\nSorted array: " << endl;
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

void quick(int arr[], int first, int last, int size)
{
  if(first < last) // ja first < last nozime, ka masivs nav sakartots un jastrada talak
  // ja first == last, tad nozime ka masiva ir tikai 1 elements, tadad nevajag turpinat
  {
    int L = first; // pirmais elements masiva    0
    int R = last; // pedejais elements masiva    6
    int pivot = arr[(L + R) / 2]; // centralais elements masiva

    // sakuma masivs: 4 9 7 (6) 2 3 8
    do
    {
      //apskatita masiva kreisa dala un meklejam tos skaitlus, kuriem jabut labaja dala (tie, kas vairaki par pivot)
      while(arr[L] < pivot) // ja elements ir mazaks par centralo, tad viss ir ok un iejam pie nakosa elementa
      {
        L++; // L = 1
      }
      //apskatita masiva laba dala un meklejam tos skaitlus, kuriem jabut kreisaja dala (tie, kas mazaki par pivot)
      while(arr[R] > pivot) // ja elements ir vairak par centralo, tad viss ir ok un iejam talak pie nakosa elementa no labas puses
      {
        R--; // R = 5
      }
      //apmaina starp kreiso un labo pusi
      if(L <= R) // lai apmaina notika tikai, tad kad elementi darbojas tikai sava masiva dala   | - stop
      // 4 9 7 | (6) 2 3 8
      {
        int buf = arr[L];
        arr[L] = arr[R];
        arr[R] = buf;
        // old: 4 9 7 (6) 2 3 8
        // new: 4 3 7 (6) 2 9 8
        //          L     R
		cout << "\nL = " << L << endl;
		cout << "R = " << R << endl;
		cout << "Centr el:" <<  pivot << endl;
        L++; // L = 2
        R--; // R = 4
        cout << "\nApmaina: \t"; output_array(arr, size);
      }
      // 2 < 4 -> cikls strada
      // 7 < 6 -> No -> L = 2
      // 2 > 6 -> No -> R = 4
      // 2 <= 4 -> Yes -> new: 4 3 2 (6) 7 9 8
      // L = 3, R = 3                RL

      // 3 < 3 -> cikls nestrada - STOP
    } while(L < R); // strada kamer nebus atrasts centralais elements (nav jegas <=, jo centralais elements jau ir sava vieta, jo labaja puse ir lielaki, kreisaja ir mazaki)
      // rekursivas funkcijas
      // 4 3 2 (6) 7 9 8
      quick(arr, first, R, size); // first = 0, R = 3  -> sis masivs bus velreiz kartots   4 3 2 (6)
      quick(arr, L, last, size); // L = 4, last = 6 - > sis masivs bus velreiz kartots  (6) 7 9 8
  } return; // izeja no visam ieprieks izsaucitam funkcijam
}
