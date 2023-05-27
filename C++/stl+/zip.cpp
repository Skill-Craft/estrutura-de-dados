#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T1, typename T2>
class zip{
    private:
        vector<T1>& v1;
        vector<T2>& v2;
    
    public:

        zip(vector<T1>& v1, vector<T2>& v2): v1(v1), v2(v2) {}
        
        class Iterator{
            private:
                T1* pos1;
                T2*pos2;
            public:
                Iterator(T1* pos1, T2* pos2): pos1(pos1), pos2(pos2) {}
                Iterator& operator++(){pos1++; pos2++; return *this; }
                pair<T1 &, T2 &> operator*() { return pair<T1&, T2&> (*pos1,*pos2); }
                bool operator!=(const Iterator& other) const { return pos1 != other.pos1 && pos2 != other.pos2; }

        };

        Iterator begin() { return Iterator((v1.begin()).operator->(), (v2.begin()).operator->()); }
        Iterator end() { return Iterator((v1.end()).operator->(), (v2.end()).operator->()); }
};

int main(){
    vector<int> num{1,2,3,4,56};
    vector<char> chr{'a','b','c','d','e'};
    zip<int,char> zipado(num,chr);
    for(auto x: zipado) cout << x.first << " " <<x.second << endl;
    return 0;
}
