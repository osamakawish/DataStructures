#pragma once
#include "dataStructure.h"
#include <unordered_set>
using namespace std;

template <typename T>
class tree :
	public dataStructure
{
public:
	// Constructor and Destructor
	tree(T v) :value(v) {};
	~tree() {};

	// Access tree data.
	T value() { return value; };
	tree<T> root() { tree t = this; while (t.hasParent()) { t = t.parent; } return t; }; // Returns the root of the tree.
	tree<T> prev() { return parent; };
	unordered_set<tree<T>> next() { return children; };
	
	// Tree traits.
	bool hasParent() {};
	bool isRoot() { return prev == this; };
	bool hasChildren() { return !next.empty(); };
	bool isLeaf() { return next.empty(); };
	int degree() { return next.size(); };
	unordered_set<T> values() {}; // Returns all values in tree and subtrees.

	// Work with this node on tree.
	void addParent(tree<T> p) {};
	void insert(T x) {};
	T pop() {};

	// Operators
	bool operator==(tree<T> other) {};
	tree<T> operator--() {};
	unordered_set<tree<T>> operator++() {};

private:
	T value;
	// The parent of this node. Returns this tree iff it is root.
	tree<T> parent = this;
	// The children of this node.
	unordered_set<tree<T>> children = {};
};

