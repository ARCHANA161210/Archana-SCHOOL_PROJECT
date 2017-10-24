// the interface for printTree

// maximum number of children
#define maxArity_ 4

class treenode{
public:
	int type; // the string name and integer type both identify the contents of the node 
	char *name; 
	int lineNo; // the line on which the token was scanned
	int arity; // indicates how many children the node has
	treenode *children[maxArity_]; // the pointers to the children trees
	void printTree(treenode *t); // prints a tree
	treenode(int t, char *n, int ln);
	void addChild(treenode *x);
}; 

// values for the arity field
enum{Nullary_, Unary_, Binary_, Trinary_, Quatrary_};
