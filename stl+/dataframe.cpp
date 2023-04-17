#include <bits/stdc++.h>

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

        void add(const vector<T>& x){
            data.insert(data.end(), x.begin(), x.end());
        }

        void remove(T x){
            data.erase(find(data.begin(), data.end(), x));
        }

        T& operator[](size_t i){
            return data[i];
        }

        Series<T>& operator=(const Series<T>& x){
            data = x.data;
            return *this;
        }

        Series<T>& operator+(T x) const{
            Series<T> y(*this);
            for(auto it=y.data.begin(); it!=y.data.end();it++) *it+=x;
            return y;
        }

        Series<T>& operator-(T x) const{
            Series<T> y(*this);
            for(auto it=y.data.begin(); it!=y.data.end();it++) *it-=x;
            return y;
        }

        Series<T>& operator*(T x) const{
            Series<T> y(*this);
            for(auto it=y.data.begin(); it!=y.data.end();it++) *it*=x;
            return y;
        }

        Series<T>& operator/(T x) const{
            Series<T> y(*this);
            for(auto it=y.data.begin(); it!=y.data.end();it++) *it/=x;
            return y;
        }
        // TODO: add operator+, operator-,operator*,operator/ as a operate-in-all-elements ,operator=, ...
};


template<typename T>
class DataFrame{
    // TODO: switch map to an unordered map that remembers insertion order (preferably my own umap),
    // and make it so that series of any data type can be added 
    map<string, Series<T>> cols;
};
