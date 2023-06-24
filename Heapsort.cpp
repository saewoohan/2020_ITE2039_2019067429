// 2019067429_ÇÑ½Â¿ì_12838


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <iostream>

using namespace std;

int N, k;

typedef struct HeapStruct

{

	int Capacity;

	int Size;

	int* Elements;

}HeapStruct;

typedef struct HeapStruct* PriorityQueue;





void Insert(int X, PriorityQueue H) {

	int i;

	for (i = ++H->Size; H->Elements[i / 2] <= X; i /= 2) {

		if (i == 1) {

			break;

		}

		H->Elements[i] = H->Elements[i / 2];

	}


	H->Elements[i] = X;

}

void MAX_HEAPIFY(int X, PriorityQueue H) {
	for (int i = 1; i <= H->Size / 2;) {
		if (H->Elements[i] >= H->Elements[2 * i] && H->Elements[i] >= H->Elements[2 * i + 1]) {
			break;
		}

		if (H->Elements[2 * i] > H->Elements[2 * i + 1]) {
			int x = H->Elements[i];
			H->Elements[i] = H->Elements[2 * i];
			H->Elements[2 * i] = x;
			i = i * 2;
		}
		else {
			int x = H->Elements[i];
			H->Elements[i] = H->Elements[2 * i + 1];
			H->Elements[2 * i + 1] = x;
			i = i * 2 + 1;
		}
	}
}

int pop(PriorityQueue H) {

	int X = H->Elements[1];
	H->Elements[1] = H->Elements[H->Size];

	H->Size--;



	MAX_HEAPIFY(H->Elements[1], H);

	return X;
}


void Print(PriorityQueue H) {
	for (int i = 1; i <= H->Size; i++) {
		cout << H->Elements[i] << " ";
	}
}





int main() {


	PriorityQueue H = (PriorityQueue)malloc(sizeof(HeapStruct));

	H->Size = 0;

	cin >> N >> k;

	H->Capacity = N;

	H->Elements = (int*)malloc(sizeof(int) * (H->Capacity + 1));

	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		Insert(num, H);
	}

	for (int i = 0; i < k; i++) {

		cout << pop(H) << " ";

	}

	cout << "\n";


	Print(H);

	free(H->Elements);

	free(H);

}