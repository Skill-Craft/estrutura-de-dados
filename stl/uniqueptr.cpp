#include <iostream>

using namespace std;


template <typename T>
class UniquePtr{
    private:
        T* ptr;
    public:
        // CONSTRUCTORS

        UniquePtr() noexcept :ptr{nullptr}{}

        UniquePtr(const UniquePtr&) = delete;

        explicit UniquePtr(T* ptr) noexcept: ptr{ptr} {}

        explicit UniquePtr(UniquePtr&& p) noexcept {
            ptr = p.release(); 
        }


        // DESTRUCTOR

        ~UniquePtr(){
            if(ptr) delete ptr;
        }


        // OPERATORS

        UniquePtr& operator=(const UniquePtr&) = delete;
        
        // explicit UniquePtr operator=(T* ptr) noexcept: ptr{ptr}{};

        T &operator*()const noexcept {return *ptr;}

        T* operator->() const noexcept{
            return ptr;
        }
        
        explicit operator bool() const noexcept{
            return static_cast<bool>(ptr);
        }
        bool operator!() const noexcept{
            return 1-(operator bool());
        }

        
        // IMPORTANT METHODS

        T* get()const noexcept{return *ptr;}

        T* release() noexcept{
            T* old = ptr;
            ptr = nullptr;
            return old;
        }

        void reset(T* ptr = nullptr) noexcept{
            // TODO

        }

        void swap(const UniquePtr& p) noexcept {
            T* aux = ptr;
            ptr = p.release();
            p.ptr = aux;
        }


};

int main(){
    UniquePtr<int> p(UniquePtr<int>(new int(10)));
    int* q = p.release();
    cout << *q;
    return 0;
}