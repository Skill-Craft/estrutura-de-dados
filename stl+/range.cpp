// Also works as slice
// OBS: initializer_list
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Range{
    private:
        T initial_value;
        T final_value;
        T step;
        size_t iter;
        
        vector<T> arr;
        
        typedef const T* iterator;         

        void build_array(){
            while(next()){
                arr.push_back(current());    
            }
        }

    public:
        Range(): initial_value{}, final_value{}, step{}, iter{}, arr{} {}
        // Range(T end, T step = 1): initial_value{}, final_value{end}, step{step}, iter{}, arr{} {}
        Range(T begin, T end, T step = 1): initial_value{begin}, final_value{end}, step{step}, iter{}, arr{} {}
        // TODO: move/ copy constructor and operator= and fix the ambiguity 
        
        
        size_t amount(){
            if((final_value-initial_value)%step) return (final_value-initial_value)/step+1;
            else return (final_value-initial_value)/step;
        }
        
        vector<T> list(){
            if(arr.empty()) build_array();
            return arr;
        }

        bool next(size_t passages = 1){
            if(iter < amount()){
                iter += passages;
                return true;
            } return false;
        }

        size_t current(){
            return static_cast<T>(initial_value+step*(iter-1));
        }

        iterator begin(){
            if(arr.empty()) build_array();
            return &arr[0];
        }

        iterator end(){
            if(arr.empty()) build_array();
            return &arr[arr.size()-1];
        }

        ~Range(){
            
        }

        // vector::reverse_iterator<T> rbegin(){
        //     if(arr.empty()) build_array();
        //     return arr.rbegin();
        // }

        // vector::reverse_iterator<T> rend(){
        //     if(arr.empty()) build_array();
        //     return arr.rend();
        // }

};

class range: public Range<size_t>{
    // TODO: constructors and operator=
    using Range::Range;
};

// Proof of concept: slicing
template<typename T>
class array{
    private:
        vector<T> arr;
    public:
        void push_back(T element) { 
            arr.push_back(element); 
        }
        T operator[](size_t index) const{
            return arr[index];
        }
        vector<T> operator[](Range<size_t>&& r) const{
            vector<T> aux;
            while(r.next()){
                aux.push_back(arr[r.current()]);
            }
            return aux;
        }
};




int main(){
    range r(10,40,5);
    vector<int> v{10,20,30,40,50};
    
    for(auto x: r){
        cout<<x<<endl;
    }
    
    // for(size_t x: r){

    // }
    // array<int> v;
    // vector<int> arr;
    
    // for(int i=0; i<100; i++){
    //     v.push_back(i);
    // }
    // vector<size_t> v2(range(0,100,5).list());
    // v2[0] = 2;
    // for(auto x: r.list()){ cout << x << endl;}
    return 0;
}

