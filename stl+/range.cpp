// Also works as slice
// OBS: initializer_list
#include <iostream>

using namespace std;

template <typename T>
class Range{
    private:
        T initial_value;
        T final_value;
        T step;
        size_t iter;
        T* arr;
        void build_array(){

        }

    public:
        Range(): initial_value{}, final_value{}, step{} {arr = nullptr; iter = 0;}
        // Range(T end, T step = 1): initial_value{}, final_value{end}, step{step} {arr = nullptr; iter = 0;}
        Range(T begin, T end, T step = 1): initial_value{begin}, final_value{end}, step{step} {arr = nullptr; iter = 0;}
        // TODO: move/ copy constructor and operator= and fix the ambiguity 
        
        size_t amount(){
            if((final_value-initial_value)%step) return (final_value-initial_value)/step+1;
            else return (final_value-initial_value)/step;
        }
        
        T*& list() const{
            if(!arr) build_array();
            return arr;
        }

        bool next(size_t passages = 1){
            if(iter < amount()){
                iter += passages;
                return true;
            } return false;
        }

        size_t current(){
            return step*(iter-1);
        }


};

class range: public Range<size_t>{
    // TODO: constructors and operator=
};

int main(){
    Range<size_t> r(0,10,5);
    while(r.next()){
        cout << r.current() << endl;
    }
    return 0;
}