#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void sortuj(int tab[], int dlugoscTablicy)
{
	int pamietaj;
	int aktualnyIndex;
	int innyIndex;
	for (int i = 1; i<dlugoscTablicy;i++)
	{
		pamietaj = tab[i];
		innyIndex = i;
		while (innyIndex > 0 && pamietaj < tab[innyIndex - 1])
		{
			tab[innyIndex] = tab[innyIndex - 1];
			innyIndex--;
		}
		tab[innyIndex] = pamietaj;
	}
}

int main() {

	cout << "INSERTION SORT" << endl << endl;

	srand(time(0));
	const int n = 100000;
	int dane[n];
	for (int i = 0; i < n; i++)
	{
		dane[i] = rand() % 10000;	//od 0 do 9 999
	}

	//cout << "Przed sortowaniem\n";
	//for (int x : dane)
	//	cout << x << ", ";
	//cout << endl;

	clock_t start = clock();
	sortuj(dane, n);
	clock_t koniec = clock();

	cout << "Po sortowaniu\n";
	for (int x : dane)
		cout << x << ", ";

	cout << "\nCzas trwania programu: " << (koniec - start) / (double)CLOCKS_PER_SEC << 's';
	cout << endl;

}