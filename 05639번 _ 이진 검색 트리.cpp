#include <iostream>
#include <cstdio>

using namespace std;

typedef struct Node
{
	Node* left;
	Node* right;

	int data;
} NODE;

Node* createNode(int data)
{
	Node* newNode = new Node;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;

	return newNode;
}

void insertNode(Node* root, Node* newnode)
{
	if (newnode->data < root->data)
	{
		if (root->left != NULL) insertNode(root->left, newnode);
		else root->left = newnode;
	}
	else if (newnode->data > root->data)
	{
		if (root->right != NULL) insertNode(root->right, newnode);
		else root->right = newnode;
	}
}

void postOrder(Node* root)
{
	if (root->left != NULL) postOrder(root->left);
	if (root->right != NULL) postOrder(root->right);
	cout << root->data << endl;
}

int main(void)
{
	int seq[10000];

	int i = 0;
	while (scanf("%d", &seq[i]) != EOF)
		i++;

	Node* root = createNode(seq[0]);
	for (int n = 1; n < i; n++)
		insertNode(root, createNode(seq[n]));

	postOrder(root);

	return 0;
}
