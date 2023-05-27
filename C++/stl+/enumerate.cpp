#include <iostream>
#include <map>
#include <vector>

using namespace std;

// TODO: Implement lazy iteration 
template <typename T>
class enumerate{
    private:
        vector<T>& sequence;
    
    public:

        explicit enumerate(vector<T>& sequence) : sequence(sequence) {}
        
        class Iterator{
            private:
                size_t pos;
                vector<T>& sequence;
            public:
                Iterator(size_t pos, vector<T>& seq) : pos(pos), sequence(seq) {}
                
                Iterator& operator++() { pos++; return *this; }
                bool operator!=(const Iterator& other) const { return pos != other.pos; }
                pair<size_t, T&> operator*() { return pair<size_t, T&>(pos,sequence[pos]); }
        };
    Iterator begin(){ return Iterator(0, sequence); }
    Iterator end(){ return Iterator(sequence.size(), sequence); }
};

int main(){
    vector<int> a{1,2,3,4,5,65,6};
    enumerate<int> b(a);

    for(auto x: enumerate<int>(a)){
        x.second = 3;
    }

    for (auto x : b){
        cout << x.second << " ";
    }
}