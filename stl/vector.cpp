#include <iostream>
#include <functional>

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

        Vector(T initial_element, size_t size, function<T,(T)> function): size(size), data(new T[size]), cp(size+20){
            T rec = initial_element;
            for (size_t i = 0; i < size; i++) {
                data[i] = rec;
                rec = function(rec);
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

        void pop_back(){
            size--;
        }

        T& operator[](size_t __index){
            return data[__index];
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

        void resize(size_t __new_size){}
};


int main(){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
    v.push_back(16);
    v.push_back(17);
    v.push_back(18);
    v.push_back(19);
    v.push_back(20);
    v.push_back(21);
    for(int i=0; i < v.length(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}