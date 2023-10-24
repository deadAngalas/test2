#include<iostream>
#include<cstdlib>
#define N 100

void create_array(int arr[], int size);
void output_array(int arr[], int size);
void seikers(int arr[], int size);

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

    seikers(arr, size);
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

void seikers(int arr[], int size)
{
  // uzlabotie burbuli, jo gan no kreisas, gan no labas iet kartosanas
  int L = 0, R = size-1; // masiva robezas (izmeri), lai sakartotu gan no kreisas, gan no labas puses
  int i, j, buffer;
  //bool isSorted;

  while(L <= R) // strada lidz bridim, kad masivs nebus sakartots
  {
    //isSorted = true; // nozime, ka masivs ir sakartots
    cout << endl; output_array(arr, size); cout << endl;
    for (i = L; i < R; i++) // kartosana no kreisas puses lidz labas robezas
    {
      if (arr[i] > arr[i+1]) // apmaina
      {
        //isSorted = false; // ja bija apmainas, tad nozime, ka masivs vel ir nesakartots un parbuda to velreiz
        // ja apmainu nebija, tad nozime ka sakartots (abas for ciklos)
        buffer = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = buffer;
        output_array(arr, size); cout << endl;
      }
    }
    R--; // parbidam labo robezu, lai nakamaja reizi nenemt pedejo skaitli (kas ir vislielakais), jo tas uzreiz ir sakartots

    for (j = R; j > L; j--) // kartosana no labas puses lidz kreisas robezas
    {
      if (arr[j] < arr[j-1]) // apmaina
      {
        //isSorted = false;
        buffer = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = buffer;
        output_array(arr, size); cout << endl;
      }
    }
    L++; // parbidam kreiso robezu, lai nakamaja reizi nenemt pirmo skitlis (kas ir vismazakais), jo tas izreiz ir sava vieta
    cout << "\nSolis [" << L <<"]: " ; output_array(arr, size); cout << endl;
    // ja nedarit ierobezojumu ar bool, tad algortims starda lidz bridim, kad L<=R, kas ir ilgak, bet ar bool, nevar izvadit starp rezultatus
  }
}
