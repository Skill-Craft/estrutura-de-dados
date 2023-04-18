#include <iostream>


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

        Vector(const initializer_list<T>& initial){
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

        Vector<T>& operator=(Vector<T> &&__other){
            data = __other.data;
            size = __other.size;
            cp = __other.cp;
            __other.data = nullptr;
            __other.size = 0;
            __other.cp = 0;
            return *this;
        }

        Vector<T>& operator=(const Vector<T>& __other){
            T* aux = new T[__other.size];
            for(size_t i = 0; i < __other.size; i++){
                aux[i] = __other.data[i];
            }
            delete[] data;
            data = aux;
            size = __other.size;
            cp = __other.cp;
            return *this;
        }

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

        void push_back(const initializer_list<T>& __list){
            for(auto it = __list.begin(); it != __list.end();it++){
                push_back(*it);
            }
        }

        void insert(const T& __value, size_t __index){
            if(__index == size){
                push_back(__value);
            } else if(__index == 0){

            } if(__index > size || __index < 0){

            }
            // T* part1 = new T[__index];
            // T* part2 = new T[size - __index];
        }

        void pop_back(){
            size--;
        }

        void erase(size_t __index){
            
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

        size_t capacity(){
            return cp;
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

        void reserve(size_t __new_size){
            cp = __new_size;
        }

        void shrink_to_fit(){
            cp = size;
        }

        T at(long long __index){
            return this->operator[](__index);
        }

        T front(){
            return data[0];
        }

        T back(){
            return data[size-1];
        }

        void swap(Vector<T> & __other){
            Vector<T> tmp = __other;
            __other = *this;
            *this = tmp;
        }

        void print(){
            for(int i=0; i < size; i++) {
                cout << data[i] << endl;
            }
        }
};


int main(){
    Vector<int> v;
    // Vector<int> s;
    v.push_back({1,2,3,4,5,6,6,7});
    // s.push_back({1,2,2,2,2,3,465,4,3});
    v = Vector<int>({1,2,3,5,6});
    cout << v.back() << endl;
    v.print();
    return 0;
}