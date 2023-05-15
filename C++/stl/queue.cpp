#include <iostream>


namespace queue{


using namespace std;

template <typename T>
class Queue{
    private:
        size_t cp;
        size_t len;
        T *arr;
        size_t first;
    public:
        Queue(){
            cp = 20;
            arr = new T[cp];
            len = 0;
            first = (size_t)(-1);
        }

        ~Queue(){
            delete[] arr;
        }

        Queue(const Queue& source): len{source.len}, cp{source.cp}{
            arr = new T[cp];
            for(size_t i{}; i < source.len;i++){
                arr[i] = source.arr[i];
            }
        }

        Queue(Queue&& source): len{source.len}, cp{source.cp}{
            arr = source.arr;
            source.arr = nullptr;
        }

        T front(){
            if(first < len){
                return arr[first];
            } else throw std::length_error("queue is empty");
        }

        T back(){
            if(first < len){
                return arr[len-1];
            } else throw std::length_error("queue is empty");
        }

        T pop(){
            if(first < len) return arr[first++];
            else throw std::length_error("queue is empty");
        }

        void push(T element){
            if(len == cp){
                cp *= 2;
                T *aux = new T[cp];
                for(size_t i = 0; i < len; i++) aux[i] = arr[i];
                delete[] arr;
                arr = aux;
            }   
            if(len == 0) first++;
            len++;
            arr[len-1] = element;
        }
        
        size_t capacity(){return cp;}
        
        size_t length(){return len;}

        Queue& operator<<(T element){
            this->push(element);
            return *this;
        }

};

};

using namespace std;
using queue::Queue;

int main(){
    Queue<int> q;
    q << 1 << 2 << 3;
    cout << q.pop();
    cout << q.pop();
    cout << q.pop();

    return 0;
}
