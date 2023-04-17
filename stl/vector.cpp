#include <iostream>
// #include "../stl+/range.cpp"

using namespace std;


template<typename T>
class Vector{
    private:
        T* data;
        size_t size;
        size_t cp;
        static constexpr size_t init_cp = 20;

    public:
        Vector(): size{}, cp{init_cp}, data{new T[init_cp]} {}

        Vector(T base_element, size_t size): size(size), data(new T[size]), cp(size+20) {
            for (size_t i = 0; i < size; i++) {
                data[i] = base_element;
            }
        }

        Vector(T initial_element, size_t size, T (*fn)(T)): size(size), cp(size+20), data(new T[cp]){
            T rec = initial_element;
            for (size_t i = 0; i < size; i++) {
                data[i] = rec;
                rec = fn(rec);
            }
        }

        Vector(initializer_list<T>& initial){
            size = initial.size();
            cp = initial.size()+20;
            data = new T[cp];
            for (size_t i = 0; i < size; i++) {
                data[i] = initial.begin()[i];
            }
        }
        
        Vector(Vector<T> &&__other){
            data = __other.data;
            size = __other.size;
            cp = __other.cp;
            __other.data = nullptr;
            __other.size = 0;
            __other.cp = 0;
        }

        Vector(const Vector<T>& __other){
            size = __other.size;
            cp = __other.cp;
            data = new T[size];
            for(size_t i = 0; i < size; i++){
                data[i] = __other.data[i];
            }
        }

        // Vector() slicing type

        ~Vector(){
            delete[] data;
        }

        Vector<T>& operator=(Vector<T> &&__other){}

        Vector<T>& operator=(const Vector<T>& __other){}

        void push_back(const T& __value){
            if(size == cp){
                T* temp = new T[cp * 2];
                for(size_t i = 0; i < size; i++){
                    temp[i] = data[i];
                }
                delete[] data;
                data = temp;
                cp *= 2;
            }
            data[size++] = __value;
        }

        void push_back(initializer_list<T>& __list){

        }

        void insert(const T& __value, size_t __index){}

        void pop_back(){
            size--;
        }

        void remove(size_t __index){
            
        }

        T& operator[](long long __index){
            if(__index <= size && __index >=0){
                return data[__index];
            } else if(__index < 0 && __index >=-size){
                return data[size+__index];
            }
            else throw out_of_range("index out of range");
        }

        size_t length(){
            return size;
        }

        bool empty(){
            return size == 0;
        }

        void clear(){
            size = 0;
            cp = 0;
        }

        void resize(size_t __new_size){
            if(__new_size >= cp){
                T* temp = new T[cp * 2];
                for(size_t i = 0; i < size; i++){
                    temp[i] = data[i];
                }
                delete[] data;
                data = temp;
                cp *= 2;
            } 
            if(__new_size < size){

            } else{

            }
        }
};


int main(){
    Vector<int> v(1,4,[] (int arg){return arg+2;});
    for(int i=0; i < v.length(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}