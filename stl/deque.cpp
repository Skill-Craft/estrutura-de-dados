#include <iostream>
#include <utility>

using namespace std;


enum class Side{
    Front,
    Back
};


template <typename T>
class Deque{
    private:

        T* array;
        size_t sz;
        size_t cp;
        size_t first;
        size_t last;
        

        bool push_back(T val){
            if(sz == cp) {
                reallocate(2*cp);
            }
            array[last++] = val;
            sz++;
            return true;
        }

        bool push_front(T val){
            if(sz == cp){
                reallocate(2*cp);
            } 
            array[first--] = val;
            sz++;
            return true;
        }

        T pop_front(){
            if (is_empty())
                throw runtime_error("array is empty");
            auto val = array[first++];
            sz--;
            return val;
        }

        T pop_back(){
            if (is_empty())
                throw runtime_error("array is empty");
            auto val = array[last--];
            sz--;
            return val;
        }


    public:

        template <typename Ts>
        friend ostream& operator<<(ostream& os, const Deque<Ts>& deque);

        Deque(): array{new T[40]}, sz{}, cp{40}, first{cp-1}, last{} {}

        Deque(size_t cap): cp{cap}, array{new T[cap]}, sz{}, first{cp-1}, last{} {}
        
        Deque(const Deque<T> &other): sz{other.sz}, cp{other.cp}, first{other.first}, last{other.last}{
            T* aux = new T[cp];
            for(size_t i{}; i<sz; i++) aux[i] = other.array[i];
            array = aux;
        }

        Deque(const initializer_list<T> &other): cp{other.size()+20}, sz{}, first{cp-1}, last{}{
            array = new T[cp];
            for(size_t i{}; i<other.size(); i++) push_back(other.begin()[i]);
        }

        Deque(Deque&& other): first{other.first}, sz{other.sz}, cp{other.cp}, last{other.last} {
            array = move(other.array);
        }

        ~Deque(){
            delete[] array;
        }

        bool push(Side side, T val){
            if(side == Side::Front) return push_front(val);
            else return push_back(val);
        }

        T pop(Side side){
            if(side == Side::Front) return pop_front();
            else return pop_back();
        }

        size_t size(){
            return sz;
        }

        size_t capacity(){
            return cp;
        }

        T front(){
            if(!is_empty()) return array[first+1];
            else throw runtime_error("array is empty");
        }

        T back(){
            if (!is_empty()) return array[last-1];
            else throw runtime_error("array is empty");
        }

        void print() const{
            for(size_t i = 1; i <= sz; i++)
                cout << array[(first+i)%cp] << " ";
        }

        void reallocate(size_t new_size){
            cp = new_size;
            auto aux = array;
            array = new T[new_size];
            for(size_t i{}; i < cp; i++)
                array[i] = aux[i];
            first = cp-1;

        }

        bool is_empty(){
            return sz == 0;
        }

        Deque& operator<<(T val){
            push_back(val);
            return *this;
        }

        Deque& operator>>(T val){
            push_front(val);
            return *this;
        }

        // class iterator{
        //
        // };

};


template <typename T>
ostream& operator<<(ostream& os, const Deque<T>& deque){
    deque.print();
    return os;
}


int main(){
    Deque<int> dq(20);
    cout << dq;
    dq.push(Side::Back, 1);
    dq.push(Side::Back, 0);
    dq.push(Side::Back, 3);
    cout << dq << endl;
    dq.push(Side::Front, 4);
    cout << dq << endl;
    dq << 5;
    dq << 5 << 6;
    dq >> 3 >> 4;
    cout << dq;
    // cout << dq.front() << " " << dq.back() << endl;
    return 0;
}