/*
 *	http://olimps.lio.lv/rezultati_sikak.php?queue_id=57252
*/

#include <iostream>
#include <fstream>

using namespace std;

class BinaryTree
{
	struct Node {

		int data;
		Node *left;
		Node *right;

		Node(int newData)
		{
			data = newData;
			left = right = NULL;
		}
	};
	
	Node *root;

	void insert(int data)
	{
		if (!root) {
			root = new Node(data);
			return;
		}

		Node *tmp = root;

		while(tmp != NULL)
		{
			if(data >= tmp->data) 
			{
				if(tmp->right) tmp = tmp->right;
				else {
					tmp->right = new Node(data);
					return;
				}
			} 
			else 
			{
				if(tmp->left) tmp = tmp->left;
				else {
					tmp->left = new Node(data);
					return;
				}
			}
		}		
	}
	
	void inOrderOutput(Node *node, ofstream &output)
	{
		if (node == NULL) return;

		inOrderOutput(node->left, output);

		output << node->data << endl;

		inOrderOutput(node->right, output);
	}

public:

	BinaryTree()
	{
		root = NULL;
	}

	void fillTree(int size, ifstream &input)
	{
		int value;
		for(int i = 0; i < size; i++) {
			input >> value;
			insert(value);
		}
	}

	void inOrderOutput(ofstream &output)
	{
		inOrderOutput(root, output);
	}
};

int main() {

	ifstream input("kartosan.dat"); int size;
	BinaryTree bTree = BinaryTree();

	input >> size;

	bTree.fillTree(size, input);
	input.close();

	ofstream output("kartosan.rez");

    bTree.inOrderOutput(output);
	output.close();
}
