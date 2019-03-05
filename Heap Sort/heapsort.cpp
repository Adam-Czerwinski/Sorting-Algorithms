#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void validateMaxHeap(int dane[], int heapSize, int parentIndex);

void sort(int dane[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)	// n/2 - 1		#ostatni rodzic
	{
		validateMaxHeap(dane, n, i);
	}
	
	for (int i = n - 1; i > 0; i--)
	{
		int temp = dane[0];
		dane[0] = dane[i];
		dane[i] = temp;
		n--;
		validateMaxHeap(dane, n, 0);
	}
}

void validateMaxHeap(int dane[], int heapSize, int parentIndex) {
	int maxIndex = parentIndex;
	int leftChild = 2 * parentIndex + 1;
	int rightChild = 2 * parentIndex + 2;

	if (leftChild<heapSize && dane[leftChild] > dane[maxIndex])
	{
		maxIndex = leftChild;
	}
	if (rightChild<heapSize && dane[rightChild] > dane[maxIndex])
	{
		maxIndex = rightChild;
	}

	if (maxIndex != parentIndex)
	{
		int temp = dane[maxIndex];
		dane[maxIndex] = dane[parentIndex];
		dane[parentIndex] = temp;
		validateMaxHeap(dane, heapSize, maxIndex);
	}
}

int main() {

	srand(time(0));

	cout << "INSERTION SORT" << endl << endl;

	const int rozmiar_tablicy = 100000;
	int dane[rozmiar_tablicy];
	for (int i = 0; i < rozmiar_tablicy; i++)
		dane[i] = rand() % 1000000;	//od 0 do 9999
	clock_t start = clock();
	sort(dane, rozmiar_tablicy);
	clock_t koniec = clock();
/*
	for (auto x : dane)
		cout << x << endl;*/
	cout << "\nCzas trwania programu: " << (koniec - start) / (double)CLOCKS_PER_SEC << 's';
	cout << endl;
	return 0;
}