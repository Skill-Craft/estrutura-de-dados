#include <iostream>


using namespace std;


template <typename T>
class Tuple{
    private:
        T* arr;
        size_t size;
    public:
        Tuple() = delete;
        
        Tuple(T* arr){
            this->arr = arr;
            // TODO: find size

        }

        Tuple(vector<T> vec){
            arr = new T[vec.size()];
            size = vec.size();
            for(size_t i = 0; i < vec.size(); i++){
                arr[i] = vec[i];
            }
        }

        ~Tuple(){
            delete[] arr;
        };

        T& operator[](size_t i) const{
            return arr[i];
        }

        void print() const{
            for(int i = 0; i < size;i++) cout << arr[i] << endl;
        }

        size_t len() const{
            return size;
        }

        vector<T> to_vector() const{
            return vector<T>(arr);
        }

        operator bool() const{
            return size!= 0;
        }

        bool operator==(const Tuple<T>& other) const{
            // return size == other.size;
        }

};