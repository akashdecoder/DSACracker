#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <list>

using namespace std;

class Hash{
    int BUCKET;
    list<int> *table;
public:
    Hash(int V);
    void insertItem(int x);
    void deleteItem(int key);

    int hashFunction(int x){
        return(x % BUCKET);
    }

    void displayHash();
};

Hash::Hash(int b){
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int x){
    int index = hashFunction(x);
    table[index].push_back(x);
}

void Hash::deleteItem(int key){
    int index = hashFunction(key);

    list<int>::iterator i;
    for(i = table[index].begin(); i != table[index].end(); i++){
        if(*i == key) {
            break;
        }
    }
    if(i != table[index].end()) {
        table[index].erase(i);
    }
}

void Hash::displayHash() {
    for(int i=0; i<BUCKET; i++){
        cout << i;
        for(auto x : table[i]){
            cout << " --> " << x;
        }
        cout << endl;
    }
}

int main(){
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a) / sizeof(a[0]);
    Hash h(7);
    for(int i=0; i<n; i++){
        h.insertItem(a[i]);
    }
    cout << "\nOriginal Hashing\n";
    h.displayHash();
    h.deleteItem(12);
    cout << "\nAfter Deletion\n";
    h.displayHash();
    return 0;
}

/*m = Number of slots in hash table
n = Number of keys to be inserted in hash table
Load factor α = n/m 
Expected time to search = O(1 + α)
Expected time to delete = O(1 + α)
Time to insert = O(1)
Time complexity of search insert and delete is O(1) if  α is O(1)*/