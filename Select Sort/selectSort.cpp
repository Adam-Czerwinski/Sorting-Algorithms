#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void sortuj(int dane[], int dlugoscTablicy) {

	int index;
	int temp;
	for (int i = 0; i < dlugoscTablicy - 1; i++)
	{
		index = i;
		for (int j = i+1; j < dlugoscTablicy; j++)
			if (dane[j] < dane[index])
				index = j;

		if (i != index)
		{
			temp = dane[i];
			dane[i] = dane[index];
			dane[index] = temp;
		}
	}

}

int main() {

	cout << "SELECT SORT" << endl << endl;

	srand(time(0));
	const int n = 100000;
	int dane[n];
	for (int i = 0; i < n; i++)
	{
		dane[i] = rand() % 10000;	//od 0 do 9 999
	}

	/*cout << "Przed sortowaniem\n";
	for (int x : dane)
		cout << x << ", ";
	cout << endl;*/

	clock_t start = clock();
	sortuj(dane, n);
	clock_t koniec = clock();
	cout << "Koniec sortowania" << endl;

	cout << "Po sortowaniu\n";
	for (int x : dane)
		cout << x << ", ";

	cout << "Czas trwania programu: " << (koniec-start) / (double)CLOCKS_PER_SEC << 's';
	cout << endl;

	return 0;
}