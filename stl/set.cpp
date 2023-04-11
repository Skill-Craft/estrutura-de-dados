#include <iostream>


using namespace std;

template <typename T>
class stack{
    private:
        size_t cp;
        size_t len;
        T *arr;
    public:
        stack(){
            cp = 20;
            arr = new T[cp];
            len = 0;
        }
        T top(){
            if(len){
                return arr[len-1];
            } else throw std::length_error("stack is empty");
        }
        T pop(){
            if(len){
                len--;
                return arr[len];
            } else throw std::length_error("stack is empty");
        }
        void append(T element){
            if(len == cp){
                cp *= 2;
                T *aux = new T[cp];
                for(int i = 0; i < len; i++) aux[i] = arr[i];
            }   
            len++;
            arr[len-1] = element;
        }
        
        size_t capacity(){return cp;}
        size_t lentgh(){return len;}

};

int main(){
    stack<int> st;
    st.append(1);
    cout << st.top() << endl;
    st.append(2);
    cout << st.pop()<< endl;
    cout << st.top()<< endl; 
    cout << st.pop()<< endl;
    cout << st.top()<< endl; 
    return 0;
}