//2019067429_한승우_B
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;

int freq[30001];
int abc[30001];
int j;
int N;
int total;

typedef struct node
{
	node* leftChild;
	node* rightChild;
	int length;
	double frequency;
}node;

struct cmp {
	bool operator()(const node& u, const node& v) {
		return u.frequency > v.frequency;
	}
};
priority_queue < node, vector<node>, cmp> pq;

node getHuffmanTree() {
	while (!pq.empty()) {
		node* tempNode = new node;
		node* tempNode1 = new node;
		node* tempNode2 = new node;
		*tempNode1 = pq.top();	
		pq.pop();
		*tempNode2 = pq.top();
		pq.pop();
		tempNode->leftChild = tempNode1;
		tempNode->rightChild = tempNode2;
		tempNode->frequency = tempNode1->frequency + tempNode2->frequency;
		pq.push(*tempNode);
		if (pq.size() == 1) {
			break;
		}
	}
	return pq.top();
}

void BFS(node* temproot,int len) {
	node* root1 = new node;
	root1 = temproot;
	root1->length = len;
	if (root1 == NULL) {

	}
	else if (root1->leftChild == NULL && root1->rightChild == NULL) {
		freq[j] = len;
		abc[j] = root1->frequency;
		j++;
		delete[] root1;
	}
	else {
		root1->leftChild->length = len + 1;
		root1->rightChild->length = len + 1;

		BFS(root1->leftChild,root1->leftChild->length);
		BFS(root1->rightChild, root1->rightChild->length);
	}
}

void getHuffmanCode() {
	int tempDouble;
	string tempString = "";
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		node tempNode;
		cin >> tempString;
		cin >> tempDouble;
	
		tempNode.frequency = tempDouble;
		tempNode.leftChild = NULL;
		tempNode.rightChild = NULL;
		pq.push(tempNode);
	}

	cin >> total;

	node root = getHuffmanTree();

	BFS(&root, 0);
	

}

int main(void) {
	getHuffmanCode();

	float a = log2(N);
	int b = ceil(a);

	cout << total * b << "\n";

	int answer = 0;

	for (int i = 0; i < N; i++) {
		answer += freq[i] * abc[i];
	}

	cout << answer;
	

}