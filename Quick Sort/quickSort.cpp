#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
static const int ile = 100000;

void zamiana(int tablica[], int x, int y) {
	int temp = tablica[x];
	tablica[x] = tablica[y];
	tablica[y] = temp;
}

int wybierzPivot(int tablica[], int poczatekTablicy, int koniecTablicy)
{
	int srodek = poczatekTablicy + (koniecTablicy - poczatekTablicy) / 2;
	int pivot = tablica[srodek];
	zamiana(tablica, srodek, koniecTablicy);
	return pivot;
}

int partycjonowanieTablicy(int tablica[], int poczatekTablicy, int koniecTablicy)
{
	int pivot = wybierzPivot(tablica, poczatekTablicy, koniecTablicy);
	int granica = poczatekTablicy - 1;
	int i = poczatekTablicy;

	while (i < koniecTablicy)
	{
		if (tablica[i] < pivot) {
			granica++;
			if (granica != i)
				zamiana(tablica, granica, i);

		}
		i++;
	}
	return granica;
}

void quickSort(int tablica[], int poczatekTablicy, int koniecTablicy) {

	if (poczatekTablicy >= koniecTablicy)
		return;

	int granica = partycjonowanieTablicy(tablica, poczatekTablicy, koniecTablicy);

	granica++;
	if (granica != koniecTablicy)
		zamiana(tablica, granica, koniecTablicy);

	if (granica - poczatekTablicy < granica - koniecTablicy)
	{
		//lewy podproblem
		quickSort(tablica, poczatekTablicy, granica - 1);
		//prawy podproblem
		quickSort(tablica, granica + 1, koniecTablicy);
	}
	else
	{
		//prawy podproblem
		quickSort(tablica, granica + 1, koniecTablicy);
		//lewy podproblem
		quickSort(tablica, poczatekTablicy, granica - 1);
	}
}

void sortuj(int tablica[], int dlugosc) {
	quickSort(tablica, 0, dlugosc - 1);
}

int main() {

	cout << "QUICK SORT" << endl << endl;

	srand(time(0));
	int dane[ile];
	for (int i = 0; i < ile; i++)
	{
		dane[i] = rand() % 10000;	//od 0 do 9 999
	}

	/*cout << "Przed sortowaniem";
	for (int x : dane)
		cout << x << ", ";
	cout << endl;*/

	clock_t start = clock();
	sortuj(dane, ile);
	clock_t koniec = clock();

	/*cout << "Po sortowaniu\n";
	for (int x : dane)
		cout << x << ", ";*/

	cout << "Czas trwania programu: " << (koniec - start) / (double)CLOCKS_PER_SEC << 's';
	cout << endl;

	return 0;
}