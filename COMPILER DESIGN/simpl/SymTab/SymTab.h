// a symbol table class
class SymTab{
	int capacity, augment;
	void **stuff;
	char **keys;
	int hash(char *x);
	void reallocate(void);
public:
	SymTab(int c = 50); // initialize the capacity
	void add(char *key, void *o);
	void *get(char *key);
	~SymTab(void);
}; // end of SymTab

