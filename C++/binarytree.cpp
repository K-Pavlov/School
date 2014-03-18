#include <iostream>

using namespace std;

template<typename T>
struct Node
{
	Node* left_;
	Node* right_;
	T value_;
	
	Node(T value)
	: value_(value),
	  left_(0),
	  right_(0)
	{
	}
};

template<typename T>
class BinaryTree
{
	Node<T>* root_;

	void delete_tree(Node<T>* node)
	{
		if (node)
		{
			delete_tree(node->left_);
			delete_tree(node->right_);
			delete node;
		}
	}

	Node<T>* copy_tree(const Node<T>* source)
	{
		Node<T>* destination = 0;
		
		if(source)
		{
			destination = new Node<T>(source->value_);
			destination->left_ = copy_tree(source->left_);
			destination->right_ = copy_tree(source->right_);
		}
		
		return destination;
	}

	void print(Node<T>* node)
	{
		if (node)
		{
			cout << node->value_ << endl;
			print(node->left_);
			print(node->right_);
		}
	}
	
public:

	BinaryTree()
	: root_(0)
	{
	}

	~BinaryTree()
	{
		delete_tree(root_);
	}

		

	bool empty() const
	{
		return root_ == 0;
	}

	void create_tree(const T& val, const BinaryTree<T>& left, const BinaryTree<T>& right)
	{
		delete_tree(root_);
		root_ = new Node<T>(val);
		root_->left_ = copy_tree(left.root_);
		root_->right_  = copy_tree(right.root_);
	}

	void print()
	{
		print(root_);
	}
};
int main()
{
	BinaryTree<int> t, t1, t2, t3;
	t.create_tree(3, BinaryTree<int>(), BinaryTree<int>());
	cout << "empty" << t.empty() << endl;
	t1.create_tree(2, BinaryTree<int>(), BinaryTree<int>());

	t2.create_tree(1, t, t1);

	t2.print();
	return 0;
}
