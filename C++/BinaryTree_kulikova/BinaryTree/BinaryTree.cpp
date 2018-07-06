// BinaryTree.cpp : Defines the entry point for the console application.
//

//����������� ����� remove ��� �������� ���� �� ����� � ���������� � ������� ���������� ���������� ������ ���������� �� ���� ������.

#include "stdafx.h"

class BinaryTree;

class Node
{
	int data;
	int key;

	Node* left;
	Node* right;
	Node* parent; //  ����� � ���������

public:
	Node(int key, int data) : data(data), key(key), left(nullptr), right(nullptr), parent(nullptr)
	{}

	friend ostream& operator<<(ostream& stream, const Node& node)
	{
		stream << node.key << ": " << node.data;
		return stream;
	}

	friend BinaryTree;
};

class BinaryTree
{
	Node* root;
	int size;

	Node* find(int key)// ������� ���� �� ������� ����� ��������� ������� � �������� key
	{
		Node* cur = root;
		while (true)
		{
			if (key < cur->key) // ��������� � ����� �����
			{
				if (cur->left)  // ��������� cur->left �� �������, �.�. ��������� �� �������
				{
					cur = cur->left;
				}
				else
				{
					return cur;
				}
			}
			else if (key > cur->key)
			{
				if (cur->right)
				{
					cur = cur->right;
				}
				else
				{
					return cur;
				}
			}
			else // ����� �����
			{
				return cur;
			}
		}
	}

	void insert(Node* cur, Node* node)
	{
		if (node->key < cur->key)
		{
			cur->left = node;
			node->parent = cur;
		}
		else if (node->key > cur->key)
		{
			cur->right = node;
			node->parent = cur;
		}
		else
		{
			cur->data = node->data;
			delete node;
		}
	}

	void traverse(ostream& stream) const
	{
		traverse(root, stream);
	}

	void traverse(Node* cur, ostream& stream) const
	{
		if (cur) // ���� �� NULL
		{
			traverse(cur->left, stream);
			stream << *cur << endl;
			traverse(cur->right, stream);
		}
	}

public:
	BinaryTree() : root(nullptr), size(0)
	{}


	void add(int key, int data)
	{
		Node* node = new Node(key, data);
		if (!root) // ���� ������ ������
		{
			root = node;
		}
		else
		{
			Node* cur = find(key);	// ����������� ����� ����� ������
			insert(cur, node);
		}
		size++;
	}

	int& operator[](int key)//���������� []
	{
		Node* node = find(key);
		assert(node->key == key);
		return node->data;
	}

	friend ostream& operator<<(ostream& stream, const BinaryTree& tree)//����� � �������
	{
		tree.traverse(stream);
		return stream;
	}

	int at(int key)
	{
		Node* node = find(key);
		return node->key == key ? node->data : NULL;
	}

	void delete_root(Node* node)//�������� �����
	{
		Node* buf_left = node->left;
		Node* buf_node = node;
		node = node->right;

		root = node;
		node->parent = NULL;

		if (root->left == NULL)//���� � ����� ��� ���������
		{
			root->left = buf_left;
			buf_left->parent = root;
		}
		else
		{
			Node* cur = node->left;
			while (cur->left != NULL)
			{
				cur = cur->left;
			}

			cur->left = buf_left;
			buf_left->parent = cur;
		}
		delete buf_node;
	}

	void remove(int key)//�������� �� �������
	{
		Node* node = find(key);//���� ������, ������� ����� �������
		Node* del = node;//���������� ������, ������� ����� �������

		if (node->left == NULL && node->right == NULL)
		{
			if (del == root)
			{
				root = NULL;
				delete node;
				return;
			}
			if (del->parent->left == del)
			{
				del->parent->left = NULL;
			}
			else
			{
				del->parent->right = NULL;
			}

		}
		else if (node->left == NULL || node->right == NULL)//���� � ���� ����� ��� ������ ���� �����������
		{
			Node* buf = NULL;//���������� ������������ ����
			if (node->left != NULL)
			{
				buf = node->left;
			}
			else if (node->right != NULL)
			{
				buf = node->right;
			}

			if (del->parent == NULL)
			{
				root = buf;
				buf->parent = NULL;
			}
			else
			{
				if (del->parent->left == node)
				{
					node->parent->left = buf;
					buf->parent = del->parent;
				}
				else
				{
					node->parent->right = buf;
					buf->parent = del->parent;
				}
			}
		}
		else //node->left != NULL && node->right != NULL
		{
			if (node == root)
			{
				delete_root(node);
				return;
			}
			Node* buf_left = node->left;
			Node*parent_node = node->parent;
			Node* buf_node = node;

			node = node->right;

			if (parent_node->left == buf_node)
			{
				parent_node->left = node;
				node->parent = parent_node;
			}
			else
			{
				parent_node->right = node;
				node->parent = parent_node;
			}

			Node* cur = node;
			while (cur->left != NULL)
			{
				cur = cur->left;
			}
			cur->left = buf_left;
			buf_left->parent = cur;

		}
		delete del;
	}

	void remove_tree(Node* node)//�������� �������� ������
	{
		if (node)
		{
			remove_tree(node->left);
			remove_tree(node->right);
			delete node;
		}
	}

	~BinaryTree()//����������
	{
		remove_tree(root);
	}
};



void test01()
{
	BinaryTree tree;
	tree.add(5, 10);
	tree.add(2, 20);
	tree.add(4, 30);
	tree.add(3, 40);
	tree.add(7, 50);
	tree.add(1, 80);
	tree.add(8, 100);
	tree.add(6, -10);


	cout << tree[5] << endl;

	cout << "Tree" << endl;
	cout << tree << endl;

	cout << "--------------" << endl;
	cout << "delete 4" << endl;
	tree.remove(4);
	cout << tree << endl;


	cout << "--------------" << endl;
	cout << "delete 5" << endl;
	tree.remove(5);
	cout << tree << endl;

	cout << "--------------" << endl;
	cout << "delete 2" << endl;
	tree.remove(2);
	cout << tree << endl;

	cout << "--------------" << endl;
	cout << "delete 7" << endl;
	tree.remove(7);
	cout << tree << endl;

	cout << "--------------" << endl;
	cout << "delete 3" << endl;
	tree.remove(3);
	cout << tree << endl;

	cout << "--------------" << endl;
	cout << "delete 1" << endl;
	tree.remove(1);
	cout << tree << endl;

	cout << "--------------" << endl;
	cout << "delete 8" << endl;
	tree.remove(8);
	cout << tree << endl;

	cout << "--------------" << endl;
	cout << "delete 6" << endl;
	tree.remove(6);
	cout << tree << endl;
}


int main()
{
	test01();
	return 0;
}