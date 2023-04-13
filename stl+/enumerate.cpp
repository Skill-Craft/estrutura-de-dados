#include <bits/stdc++.h>

using namespace std;

template <typename T>
class enumerate{
    private:
        vector<T> vec;
        vector<size_t> aux;
        vector<pair<size_t,T>> enumerated;
    public:
        enumerate(const vector<T> v) noexcept: vec{v} {
            for(size_t i{}; i < v.size();i++){
                aux.push_back(i);
                enumerated.push_back(pair<size_t,T>(i,v[i]));
            } 
        }
};