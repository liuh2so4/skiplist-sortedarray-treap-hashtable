// CPP program to implement hashing with chaining
#include<bits/stdc++.h>
using namespace std;

class Hash
{
	int BUCKET; // No. of buckets

	// Pointer to an array containing buckets
	list<int> *table;
	public:
	Hash(int b); // Constructor

	~Hash(){
		table->clear();
	}

	// inserts a key into hash table
	void insertItem(int x);

	// deletes a key from hash table
	void searchItem(int key);

	// hash function to map values to key
	int hashFunction(int x) {
		return (x % BUCKET);
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash::insertItem(int x)
{
	int index = hashFunction(x);
	table[index].push_back(x);
}

void Hash::searchItem(int key)
{
	// get the hash index of key
	int index = hashFunction(key);

	// find the key in (index)th list
	list <int> :: iterator i;
	for (i = table[index].begin();i != table[index].end(); i++) {
		if (*i == key)
			break;
	}

	// if key is found in hash table, remove it
	// if (i != table[index].end())
	//	cout<<"searched"<<endl;
}
/*
// function to display hash table
void Hash::displayHash() {
	for (int i = 0; i < BUCKET; i++) {
		cout << i;
		for (auto x : table[i])
			cout << " --> " << x;
		cout << endl;
	}
}
*/

// Driver program
int main()
{

	int num=1024;
	for(int i=10; i<28; ++i){
		int n;
		Hash h(num);
		int *array = new int[num];
		clock_t tinsert;
		tinsert = clock();
		for(int j=0; j<num ; ++j){
			array[j] = rand();
			h.insertItem(array[j]);
		}
		tinsert = clock() - tinsert;
		clock_t tsearch;
		tsearch = clock();
		for(int j=0; j<100000; ++j){
			n=rand();
			h.searchItem(n);
		}
		tsearch = clock() - tsearch;
		delete []array;
		cout<<"hash table,"<<i<<","<<(double)tinsert/CLOCKS_PER_SEC<<","<<(double)tsearch/CLOCKS_PER_SEC<<endl;
		num *= 2;
		h.~Hash();
	}

	// array that contains keys to be mapped
	// int a[] = {15, 11, 27, 8, 12};
	// int n = sizeof(a)/sizeof(a[0]);

	// insert the keys into the hash table
	// Hash h(7); // 7 is count of buckets in
	// hash table
	// for (int i = 0; i < n; i++)
	//	h.insertItem(a[i]);

	// delete 12 from hash table
	// h.deleteItem(12);

	// display the Hash table
	// h.displayHash();

	return 0;
}

