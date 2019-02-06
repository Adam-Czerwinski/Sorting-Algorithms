#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
static const int ile = 100000;
static int dodatkowaTablica[ile];

void merge(int tablica[], int indexLewy, int srodek, int indexPrawy) {

	//przepisanie tablicy
	for (int i = indexLewy; i <= indexPrawy; i++) {
		dodatkowaTablica[i] = tablica[i];
	}

	int finger1 = indexLewy;
	int finger2 = srodek + 1;
	int current = indexLewy;
	while (finger1 <= srodek && finger2 <= indexPrawy) {
		if (dodatkowaTablica[finger1] <= dodatkowaTablica[finger2])
		{
			tablica[current] = dodatkowaTablica[finger1];
			finger1++;
		}
		else {
			tablica[current] = dodatkowaTablica[finger2];
			finger2++;
		}
		current++;
	}
	while (finger1 <= srodek) {
		tablica[current] = dodatkowaTablica[finger1];
		current++;
		finger1++;
	}

}

void mergeSort(int tablica[], int indexLewy, int indexPrawy) {
	if (indexLewy < indexPrawy)
	{
		//wtedy wiecej niz 1 element
		int srodek = (indexLewy + indexPrawy) / 2;
		mergeSort(tablica, indexLewy, srodek);
		mergeSort(tablica, srodek + 1, indexPrawy);
		merge(tablica, indexLewy, srodek, indexPrawy);
	}
}

void sortuj(int tablica[], int dlugosc) {
	mergeSort(tablica, 0, dlugosc - 1);
}

int main() {

	cout << "MERGE SORT" << endl << endl;

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