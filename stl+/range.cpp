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
        
        
        size_t amount() const{
            if((final_value-initial_value)%step) return (final_value-initial_value)/step+1;
            else return (final_value-initial_value)/step;
        }
        
        vector<T> list(){
            if(arr.empty()) build_array();
            return arr;
        }

        bool next(size_t passages = 1){
            if(iter+passages>=0 && iter+passages <= amount()){
                iter += passages;
                return true;
            } return false;
        }

        bool prev(size_t passages = 1){
            if(iter-passages>=0 && iter-passages <= amount()){
                iter -= passages;
                return true;
            } return false;
        }

        size_t current(){
            return static_cast<T>(initial_value+step*(iter-1));
        }


        class Iterator{
            public:
                Iterator(T curr, T step, size_t maximum) : curr{curr}, step{step}, maximum{maximum} {}

                // TODO: operator+, operator-, operator=, operator-- (both), operator bool, ...

                bool operator==(const Iterator& other) const{
                    return curr==other.curr && step==other.step;
                }

                bool operator!=(const Iterator& other) const{
                    return curr!=other.curr || step!=other.step;
                }

                Iterator& operator+(const T& passages){
                    if(counter + passages <= maximum){
                        curr += step*passages;
                        counter += passages;
                        return *this;
                    } else throw out_of_range("iterator overflow");   
                }

                Iterator& operator++(){
                    if(counter+1<= maximum){
                        curr += step;
                        return *this;
                    } else throw out_of_range("iterator overflow");
                }

                Iterator operator++(int){
                    if(counter + 1 <= maximum){
                        Iterator current(curr,step);
                        curr += step;
                        counter++;
                        return current;
                    } else throw out_of_range("iterator overflow");
                }

                Iterator& operator-(const T& passages){
                    if(counter - passages >= 0){
                        curr -= step*passages;
                        counter -= passages;
                        return *this;
                    } else throw out_of_range("iterator underflow");
                }

                Iterator& operator--(){
                    if(counter - 1 >= 0){
                        curr -= step;
                        counter -= 1;
                        return *this;
                    } else throw out_of_range("iterator underflow");
                }

                Iterator operator--(int){
                }

                T operator*() const{
                    return curr;
                }

            private:
                T curr;
                T step;
                size_t counter;
                size_t maximum;

        };

        Iterator begin() const{
            return Iterator{initial_value, step, amount()};
        }

        Iterator end() const{
            size_t temp = initial_value;
            temp = temp + step*amount();
            return Iterator{temp, step, amount()};
        }

        // iterator vec_begin(){
        //     if(arr.empty()) build_array();
        //     return &arr[0];
        // }

        // iterator vec_end(){
        //     if(arr.empty()) build_array();
        //     return &arr[arr.size()-1];
        // }

        ~Range(){
            
        }

};

class range: public Range<size_t>{
    using Range::Range;
};

// reversed(range)


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
    range r(10,41,5);
    vector<int> v{10,20,30,40,50};
    
    for(auto x: r){
        cout<<x<<endl;
    }
    
    
    return 0;
}

