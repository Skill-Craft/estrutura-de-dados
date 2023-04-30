#include <bits/stdc++.h>

using namespace std;

// Each column is a custom vector. Data is inserted using df["name_of_col"] = vector, where df["name_of_col"] is 
// a special vector-like container (Series) and the rhs is any vector-like container 


// template <typename T>
// class Series{
//     private:
//         vector<T> data;

//     public:

//         Series() {}

//         Series(vector<T> x){
//             data = x;
//         }

//         Series(const Series<T>& s): data{s.data} {}

//         Series(Series<T>&& s): data(s.data) {}

//         vector<T> get() const{
//             return data;
//         }

//         void show() const{
//             for(auto x : data){
//                 cout << x << " ";
//             }
//             cout << endl;
//         }

//         void add(T x){
//             data.push_back(x);
//         }

//         void add(const vector<T>& x){
//             data.insert(data.end(), x.begin(), x.end());
//         }

//         void remove(T x){
//             data.erase(find(data.begin(), data.end(), x));
//         }

//         T& operator[](size_t i){
//             return data[i];
//         }

//         Series<T>& operator=(const Series<T>& x){
//             data = x.data;
//             return *this;
//         }

//         Series<T>& operator=(const vector<T>& x){
//             data = x;
//             return *this;
//         }

//         Series<T>& operator=(Series<T>&& x){
//             data = move(x.data);
//             return *this;
//         }

//         Series<T>& operator=(vector<T>&& x){
//             data = move(x);
//             return *this;
//         }

//         Series<T> operator+(T x) const{
//             Series<T> y(*this);
//             for(auto it=y.data.begin(); it!=y.data.end();it++) *it+=x;
//             return y;
//         }

//         Series<T> operator-(T x) const{
//             Series<T> y(*this);
//             for(auto it=y.data.begin(); it!=y.data.end();it++) *it-=x;
//             return y;
//         }

//         Series<T> operator*(T x) const{
//             Series<T> y(*this);
//             for(auto it=y.data.begin(); it!=y.data.end();it++) *it*=x;
//             return y;
//         }

//         Series<T> operator/(T x) const{
//             Series<T> y(*this);
//             for(auto it=y.data.begin(); it!=y.data.end();it++) *it/=x;
//             return y;
//         }
//         // TODO: add operator+, operator-,operator*,operator/ as a operate-in-all-elements ,operator=, ...
// };

bool is_numeric(const string &s){
        return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c){ return !std::isdigit(c);}) == s.end();
}

class series{
    private:
        vector<string> data;
        string type;
        vector<size_t> indices;
        size_t round = (size_t)-1; 

    public:
        string dtype() const{return type;}

        void round_values(size_t sz){ round = sz;}

        series() = delete;

        series(vector<string> x){
            data = x;
            if(is_numeric(x[0])) type = "numeric";
            else type = "string";
            for(size_t i=1;i<=x.size();i++){
                indices.push_back(i);
            }
        }

        series(const initializer_list<string>& init){

        }

        series(const series &s) : data{s.data}, type{s.type}, indices{s.indices} {}

        series(series &&s) : data(s.data), type{s.type}, indices{s.indices} {}

        vector<string> get() const{
            return data;
        }

        void show() const{
            auto default_prec = cout.precision();
            for (size_t i = 0; i < indices.size(); i++){
                if(round != default_prec && round != (size_t)-1){
                    cout << setprecision(round) << fixed;
                }
                if (type == "numeric"){
                    double tmp = stod(data[i]);
                    cout << indices[i] << "       " << tmp << endl;
                } else cout << fixed << indices[i] << "       " << data[i] << endl;
            }
            cout << setprecision(default_prec) << endl;
            cout << "dtype"
                 << "   " << dtype() << endl;
            cout << endl;
        }

        void add(string x){
            data.push_back(x);
            indices.push_back(data.size());
        }

        void add(double x){
            data.push_back(to_string(x));
            indices.push_back(data.size());
        }

        void add(const vector<string> &x){
            data.insert(data.end(), x.begin(), x.end());
            vector<size_t> aux;
            for(size_t i=0; i < x.size(); i++){
                indices.push_back(indices.size()+1);
            }
            indices.insert(indices.end(), aux.begin(), aux.end());
        }

        void add(const vector<double> &x){
            vector<string> y(x.size());
            transform(x.begin(), x.end(), y.begin(), [](double d) {return to_string(d);});
            data.insert(data.end(), y.begin(), y.end());
            vector<size_t> aux;
            for (size_t i = 0; i < y.size(); i++){
                indices.push_back(indices.size() + 1);
            }
            indices.insert(indices.end(), aux.begin(), aux.end());
        }

        void add(const initializer_list<string>& lst){
            for(size_t i=0; i < lst.size();i++){
                add(lst.begin()[i]);
            }
        }

        void add(const initializer_list<double> &lst){
            for (size_t i = 0; i < lst.size(); i++){
                add(lst.begin()[i]);
            }
        }

        void remove(string x){
            data.erase(find(data.begin(), data.end(), x));
        }

        string &operator[](size_t i){
            return data[i-1];
        }

        series &operator=(const series &x){
            data = x.data;
            type = x.type;
            indices = x.indices;
            return *this;
        }

        series &operator=(const vector<string> &x){
            data = x;
            return *this;
        }

        series &operator=(series &&x){
            data = move(x.data);
            type = move(x.type);
            indices = move(x.indices);
            return *this;
        }

        series &operator=(vector<string> &&x){
            data = move(x);
            return *this;
        }

        void operator+=(double x){
            if(type == "nmueric")
                for (auto it = this->data.begin(); it != this->data.end(); it++)
                    *it = to_string(stod(*it) + x);
        }

        void operator-=(double x){
            if(type == "nmueric")
                for (auto it = this->data.begin(); it != this->data.end(); it++)
                    *it = to_string(stod(*it) + x);
        }

        void operator*=(double x){
            if (type == "numeric")
                for (auto it = this->data.begin(); it != this->data.end(); it++)
                    *it = to_string(stod(*it) * x);
        }

        void operator/=(double x){
            if(type == "nmueric")
                for (auto it = this->data.begin(); it != this->data.end(); it++)
                    *it = to_string(stod(*it) / x);
        }

        series operator+(double x) const{
            series y(*this);
            if(type == "nmueric")
                for (auto it = y.data.begin(); it != y.data.end(); it++)
                    *it = to_string(x + stod(*it));
            return y;
        }

        series operator-(double x) const{
            series y(*this);
            if(type == "nmueric")
                for (auto it = y.data.begin(); it != y.data.end(); it++)
                    *it = to_string(stod(*it) - x);
            return y;
        }

        series operator*(double x) const{
            series y(*this);
            if(type == "nmueric")
                for (auto it = y.data.begin(); it != y.data.end(); it++)
                    *it = to_string(x * stod(*it));
            return y;
        }

        series operator/(double x) const{
            series y(*this);
            if(type == "nmueric")
                for (auto it = y.data.begin(); it != y.data.end(); it++)
                    *it = to_string(stod(*it) / x);
            return y;
        }
};

class DataFrame{
    vector<pair<string,series>> data;

    public:
        DataFrame() = delete;
        // DataFrame(const vector<series>& data): data(data) {}
        // DataFrame(vector<series>&& data): data(data) {}
        // DataFrame(const map<string, vector<string>>& data){

        // }   

        // DataFrame(map<string,vector<string>>&& data){

        // } 

        series operator[](string key){
            for(auto x: data) if(x.first == key) return x.second;
        }

        series operator[](size_t index){
        
        }

        // DataFrame operator[](vector<string>& keys){
        //     for(auto x: keys)
        // }

        // DataFrame operator[](range r){}

                

        //     select_row();
        //     select_column();
        //     friend cross_tables(Dataframe& df1, Dataframe& df2);

        //     append_column();
        //     append_row();
        //     append(axes=0);
        //     DataFrame<T>& operator=(const DataFrame<T>& x){
        //     }

        //     operator[]();
        //     operator=();
        
};


int main(){
    vector<string> lines{"1", "2", "3", "4", "5"};
    series s(lines);
    s.add({1, 2, 3, 4, 5});
    s.round_values(2);
    s*=5;
    cout << s[6] << endl;
    // cout << s.dtype();
    s.show();

    // stod("as");
    return 0;
}