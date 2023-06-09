#include <iostream>
#include <vector>


using namespace std;
// TODO: implement a hash table that remembers the insertion order

template <typename T1, typename T2, class Comp = greater<T1>>
class umap{
    vector<T1> keys;
    vector<T2> values;
private:
    
public:
    umap();
    ~umap();
};