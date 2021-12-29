#include<bits/stdc++.h>

using namespace std;

const int prime[31] = { 1, 3, 5, 11, 17, 37, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65537, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617, 16777259, 33554467, 67108879, 134217757, 268435459, 536870923, 1073741827};

class Hash
{
	vector<int> *table;
	long int M;
	int r1, r2, r3, r4;
	public:
	Hash(int power=10);
	~Hash(){
		table->clear();
	}
	void insertItem(int x);
	void searchItem(int key);
	int hashFunction(int x);

};

Hash::Hash(int power)
{
	M = prime[power];
	table = new vector<int>[M];
	// cout<<M<<endl;
	r1 = rand() % M;
	r2 = rand() % M;
	r3 = rand() % M;
	r4 = rand() % M;
}

void Hash::insertItem(int x)
{
	int index = hashFunction(x);
	// cout<<"insert "<<index<<endl;
	table[index].push_back(x);
}

void Hash::searchItem(int key)
{
	int index = hashFunction(key);
	// cout<<"index "<<index<<endl;
	vector<int> :: iterator i;
	for (i = table[index].begin();i != table[index].end(); i++) {
		if (*i == key)
			break;
	}

}

int Hash::hashFunction(int x){

	int x4 = x & 255;
	int x3 = x & 65280;
	int x2 = x & 16711680;
	int x1 = x & 2130706432;
	int ans = ((r1 * x1) + (r2 * x2) + (r3 * x3) + (r4 * x4)) % M;
	// cout<<"ans "<<ans<<endl;
	if(ans > 0)
		return ans;
	else
		return 0-ans;


}

int main()
{

	int num=1024;
	for(int i=10; i<28; ++i){
		int n;
		Hash h(i);
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

	return 0;
}

