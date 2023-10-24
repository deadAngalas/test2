#include<iostream>
#include<cstdlib>
#define N 100

void create_array(int arr[], int size);
void output_array(int arr[], int size);
int interpolacija(int arr[], int size, int x);

using namespace std;

int main()
{
  int arr[N];
  int size, x;
  int result; // for interpolacijas funkcijas returnam

  char f;
  do
  {
    cout << "\nEnter array size: "; cin >> size;
    cout << "\n";
    create_array(arr, size);
    cout << "\nArray content: " << endl;
    output_array(arr, size);

    cout << "\n\nWhat number need to find? x = "; cin >> x;

    result = interpolacija(arr, size, x); // iegusim kaut kadu rezultatu
    if (result != -1) cout << "There IS your number!\n\n"; // ja tas ir vai mid vai L (indeksi), tad atrada skaitli
    else cout << "There is NO your number!\n\n"; // ja return -1, masivaa mekl. skaitli nav

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
// DOES NOT WORK with L<=R... vienmer kaut kada kluda, ja ievadit datus, kurie nepiemieroti
// jo sanak mid ir tads, kura nav masiva
/*
void interpolacija(int arr[], int size, int x)
{
  int L = 0, R = size-1;
  int mid;

  while(L <= R)
  {
    mid = L+(R-L)*(x-arr[L])/(arr[R]-arr[L]);
    if (arr[mid] > x) R = mid - 1;
    else if (arr[mid] < x) L = mid + 1;
    else
    {
      cout << "There IS your number!\n\n";
      break;
    }
  }
  if (L > R) cout << "There is NO your number!\n\n";
}
*/

int interpolacija(int arr[], int size, int x)
{
  // masivam jabut sakartotam, citadi nestrada algoritms
  int L = 0, R = size-1;
  /*
  definejam kreiso robezu, kas ir 1 elements - index[0]
  un labo rebozu, kas ir pedejais elements - masiva izmers-1 - index[size-1]
  */
  int mid;
  /*
  meklesena tiek veidota no garuma starp meklejamo skaitli un elementa pasreizejo vertibu
  (arr[R]-arr[L]) - starpiba starp vislielako skaitli un mazako skaitli, diapozonaa kad tiek veidota parbaude
  L+(R-L) - garums starp robezam
  (x-arr[L]) - starpiba starp mekl. skaitli un elementa kreiso robezu
  */
  while(arr[L] < x && arr[R] >= x)
  {
    /*
    cikls parbauda meklesanas apgabalu un stada kamer tur ir mekl. skaitlis
    arr[L] < x   -   bez = zimes, jo mes ieklausim to meklesanaa, formulaa bus kluda,
    piemeram, mas[] = {2}
    mid = 0+(0-0)*(2-2)/(2-2) -- ta ka dalit uz 2 nevar ir kluda
    tas ir aizsardziba no ta, ka masiva var but 1 skaitlis
    ar maksimalo skaitli tadas problemas nav.
    */
    mid = L+(R-L)*(x-arr[L])/(arr[R]-arr[L]);

    if(arr[mid] > x) R = mid - 1; // ja skaitlis[mid] ir lielaks neka mekl. skaitlis, tad nav jegas skatit vel lielakus skaitlus,
    // tad parplano labo robezu. Ja arr[mid] nav lielaks, tad:
    else if (arr[mid] < x) L = mid + 1; // ja skaitlis[mid] ir mazaks mekl. skaitlis, nav jegas skatit vel mazakus skaitlus,
    // parplano kreiso robezi.
    else return mid; // ja arr[mid] nav lielaks par mekl.sk. un nav mazaks par mekl.sk., tad arr[mid] == x
  }
    if (arr[L] == x) return L; // ja gadojuma masiva bus 1 skaitlis, vins iznaks no cikla (tas janozime ka masivaa tas skaitli nav, no nosacijuma), bet
    // ciklveks ievada x = meklejamais skaitlis, kurs tur ir.
    else return -1; // jebkuras citas gadojimas, ja cikls nestrada, nozime, ka skaitli tur nav
}
