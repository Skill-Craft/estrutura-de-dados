#include <bits/stdc++.h>


using namespace std;


template <typename T>
class Tensor{
    size_t cp;
    size_t row_sz;
    size_t col_sz;
    size_t dim;
    T* arr;

    Tensor flat;

    public:
        friend ostream& operator<< (ostream& os, const Tensor& t);
        Tensor();
        Tensor(initializer_list_t<T> initializer);
        Tensor(const Tenstor<T>& other);
        Tensor(Tensor<T>&& other);
        Tensor(size_t size, T default_init = (T)0);
        Tensor(size_t size, T first = (T)0, void (*comprehension)(T));
  
        
        Tensor flatten() const;
        size_t capacity() const;
        size_t dim() const;


        class Iterator{

        };

        Iterator begin() const;
        Iterator end() const;


        Tensor operator+(const Tensor& other) const;
        Tensor operator+(T constant) const;
        Tensor operator-(const Tensor& other) const;
        Tensor operator-(T constant) const;
        Tensor operator*(const Tensor& other) const;
        Tensor operator*(T constant) const;
        Tensor operator/(const Tensor& other) const;
        Tensor operator/(T constant) const;
        Tensor operator%(T constant) const;

        Tensor operator++();
        Tensor operator++(int);
        Tensor operator--();
        Tensor operator--(int);

        void operator+=(const Tensor& other);
        void operator+=(T constant);
        void operator-=(const Tensor& other);
        void operator-=(T constant);
        void operator*=(const Tensor& other);
        void operator*=(T constant);
        void operator/=(const Tensor& other);
        void operator/=(T constant);
        void operator%=(T constant);

        Tensor operator>(const Tensor& other) const;
        Tensor operator>(T other) const;
        Tensor operator>=(const Tensor& other) const;
        Tensor operator>=(T other) const;
        Tensor operator<(const Tensor& other) const;
        Tensor operator<(T other) const;
        Tensor operator<=(const Tensor& other) const;
        Tensor operator<=(T other) const;
        Tensor operator==(const Tensor& other) const;
        Tensor operator==(T other) const;
        Tensor operator!=(const Tensor& other) const;
        Tensor operator!=(T other) const;

        Tensor operator<<(Tensor other) const; // push back

        Tensor operator>>(T other) const; // modulo
        Tensor operator>>(Tensor other) const; // pop back

        bool operator!();
        bool operator&&(const Tensor& other);
        bool operator||(const Tensor &other);


        void push_back(T value);
        T pop_back();
        void insert(Iterator it, T value);
        T remove(Iterator it);


        bool any() const;
        bool all() const;


        double dot() const;
        Tensor matmul() const;
        Tensor power() const;

};
