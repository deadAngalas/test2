#include<iostream>
#include<cstdlib>
#include<ctime>
#define N 100

using namespace std;

void arr_create(int arr[], int size);
void arr_output(int arr[], int size);
void search_barjers(int arr[], int size, int x);

int main()
{
  int size, x;

  char f;
  do
  {
    cout << "\nEnter array size: "; cin >> size;
    cout << "\n";

    int arr[size++]; // palielinam masivu izmeru par 1 slotu, lai nakotne ierakstitu tur barjeru (meklejamo skaitli), kas pec tam dod zinu, ka tas ir masiva beigas

    arr_create(arr, size);
    cout << "Array content: ";
    arr_output(arr, size);
    cout << "\n\nWhat number need to find: "; cin >> x;

    search_barjers(arr, size, x);
    cout << "Countinue? y/n: "; cin >> f;
  } while(f == 'y' || f == 'Y');

  cin.get();
  system("pause>nul");
  return 0;
}

void arr_create(int arr[], int size)
{
  srand(time(NULL));
  for (int i = 0; i < size-1; i++)
  {
    arr[i] = rand()&21; // ierakstam skaitlus, bet par 1 elementu mazak, jo 1 slots ir rezervets, lai ierakstitu barjeru
    // ja ievaditais size = 3, arr[4] = {3,6,1,' '} un 1 briva vieta
  }
}

void arr_output(int arr[], int size)
{
  for (int j = 0; j < size-1; j++)
  {
    cout << arr[j] << " "; // izvade ari par 1 vienu elementu mazak, jo tagad tur ir tuksums, preteja gadijuma izvadas mulkibas
  }
}

void search_barjers(int arr[], int size, int x)
{
  int k;
  arr[size-1] = x; // japievieno barjeru, lai zinatu, kur masivs beidzas, tas vajag, lai tiktu vala no masivu beigas parbaudes
  // ievaiditais size = 3, faktiskais size = 4; arr[4-1] => arr[3], elements ar indeksu 3, tas ir 4 elements, kas ir tukss, aizvietam ar x
  for (k = 0; arr[k] != x; k++);
  // strada lidz bridim, kad nebus atrasts meklejamais skaitlis. Ir divi varianti:
  // 1) cikls atrada musu barjeru, tas nozime, ka masiva nav meklejamo skaitli
  // 2) cikls atrada skaitli pirms berjera, kas nozime, ka ir ists skaitlis
  // no sim variantiem ir atkarigs (k), ja atrada barjeru, tad k vienads ar masiva ievadito izmeru vai faktisko izmeru -1
  // ja k ir mazaks par ievadito izmeru vai faktisko izmeru -1, nozime, ka masiva ir meklejamais skaitlis
  if (size-1 == k)
  {
    cout << "\nThere is no your number!\n\n";
  }
  else
  {
    cout << "\nThere is your number!\n\n";
  }
}
