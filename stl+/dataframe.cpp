#include <bits/stdc++.h>
#include "../stl/umap.cpp"

using namespace std;

// Each column is a custom vector. Data is inserted using df["name_of_col"] = vector, where df["name_of_col"] is 
// a special vector-like container (Series) and the rhs is any vector-like container 


template <typename T>
class Series{
    private:
        vector<T> data;

    public:

        Series() {}

        Series(vector<T> x){
            data = x;
        }
        vector<T> get() const{
            return data;
        }

        void show() const{
            for(auto x : data){
                cout << x << " ";
            }
            cout << endl;
        }

        void add(T x){
            data.push_back(x);
        }

        void remove(T x){
            data.erase(find(data.begin(), data.end(), x));
        }

        T& operator[](size_t i){
            return data[i];
        }

        Series<T>& operator+(T x) const{
            Series<T> y(*this);
            for(auto element : y.data){
                element += x;
            }
            return y;
        }
        // TODO: add operator+, operator-,operator*,operator/ as a operate-in-all-elements ,operator=, ...
};


class DataFrame{
    
};
