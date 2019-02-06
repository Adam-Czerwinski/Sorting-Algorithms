#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

////WSKAZNIKAMI
//void sortuj(int* poczatek, int* koniec) {
//	
//	int dlugosc = koniec - poczatek;
//	int ileIteracji = 0;
//	bool czyZamiania = false;
//	int temp;
//	for (int n=0;n< dlugosc-1;n++, ileIteracji++)
//	{
//		for (int* i = poczatek; i < koniec - 1 - ileIteracji; i++)
//		{
//			if (*i > *(i + 1))
//			{
//				czyZamiania = true;
//				temp = *i;
//				*i = *(i + 1);
//				*(i + 1) = temp;
//			}
//		}
//		if (!czyZamiania)
//			break;
//		else czyZamiania = false;
//	}
//}

void sortuj(int tab[], int dlugoscTablicy)
{
	int ileIteracji = 0;
	bool czyZamiania = false;
	int temp;
	for (int n = 0; n < dlugoscTablicy - 1; n++, ileIteracji++)
	{
		for (int i = 0; i < dlugoscTablicy - 1 - ileIteracji; i++)
			if (tab[i] > tab[i + 1])
			{
				czyZamiania = true;
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}

		if (!czyZamiania)
			break;
		else czyZamiania = false;
	}
}

int main() {

	cout << "BUBBLE SORT" << endl << endl;

	srand(time(0));
	const int n = 100000;
	int dane[n];
	for (int i = 0; i < n; i++)
	{
		dane[i] = rand() % 10000;	//od 0 do 9 999
	}

	/*cout << "Przed sortowaniem";
	for (int x : dane)
		cout << x << ", ";
	cout << endl;*/

	clock_t start = clock();
	sortuj(dane, n);
	clock_t koniec = clock();

	/*cout << "Po sortowaniu\n";
	for (int x : dane)
		cout << x << ", ";*/

	cout << "Czas trwania programu: " << (koniec - start) / (double)CLOCKS_PER_SEC << 's';
	cout << endl;

	return 0;
}