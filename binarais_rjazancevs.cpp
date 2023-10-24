#include<iostream>
#include<cstdlib>
#define N 100

void create_array(int arr[], int size);
void output_array(int arr[], int size);
void binarais(int arr[], int size, int x);

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
    cout << "\nArray content: " << endl;
    output_array(arr, size);

    cout << "\n\nWhat number need to find? x = "; cin >> x;
    binarais(arr, size, x);

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

void binarais(int arr[], int size, int x)
{
  // masivam jabut sakartotam, citadi nestrada algoritms
  int L = 0, R = size-1;
  /*
  definejam kreiso robezu, kas ir 1 elements - index[0]
  un labo rebozu, kas ir pedejais elements - masiva izmers-1 - index[size-1]
  */
  int mid = (L+R)/2; // definejam masiva centru, kas ir kreiso un labo robeza summa, dalot ar 2
                     // ja summa ir nepara skaitlis (piem.: 4,5) tiks panemts vesels skaitlis, ta ka INT
  while(L <= R && arr[mid]!= x)
  /*
  strada lidz bridim, kad centralais elements nebus vienads ar meklejamo skaitli,
  jo tas var but pasais pirmais skaitlis, varam trapit.
  Un lidz bridim kamer kreisa robaza ir mazaka vai vienada ar labo robezu
  */
  {
    // masiva piemers {2,4,6,8,10}
    //  L = 0; R = 4; mid = 2
    if(arr[mid] < x) L = mid + 1;
    /*
    ja centralais elements ir mazaks par meklejamo skaitli (6<10), nozime, ka japarplano kreiso
    robezu, jo taja puse nevar but mekl. skaitli, jo tur ir vel mazaki skaitli.
    jauna krisa robeza nav vienada ar skaitliem, kurie ir mazaki par centralo un nav vienada ar
    centralo skaitli, jo tas tiek parbaudits cikla sakuma.
    */
    else R = mid - 1;
    /*
    ja centralais elements ir lielaks par mekl. skaitli (6>2), nozime, ka japarplano labo robezu,
    jo labaja puse ir vel lielakie skaitli.
    jauna robeza nav vienada ar skaitliem, kurie ir labaja puse un nav vienada ar centralo skaitli,
    kas tiek parbaudits pasa sakuma.
    */
    mid = (L+R)/2; // definejam jauno centralo skaitli ar jaunam robezam
  }
  /*
  kad cikls pabeidza darbu iespejami 2 varianti:
  1) masiva centralais elements tiek vienads ar mekl. skaitli un kreisa robeza ir mazaka par labo,
  tad skaitlis ir atrasts.
  2) kreisa robeza ir lielaka par labo, tad mekl. skaitlis nav atrasts
  */
  if(arr[mid] == x)
  {
    cout << "There IS your number!\n\n";
  }
  else
  {
    cout << "There is NO your number!\n\n";
  }
}
