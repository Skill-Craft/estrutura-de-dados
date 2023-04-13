#include <cstdio>
#include <cstdlib>
#include <cstring>
// #include <iostream>


// using namespace std;


class str{
    private:
        char *s;
        size_t len;
        size_t cp;
    
    public:
        const size_t npos = (size_t)(-1);
        // friend ostream& operator<<(ostream& out, str& s);
        // friend istream& operator>>(istream& in, str& s); 
        str();
        str(const str& src);
        str(str&& src);
        size_t lentgh();
        size_t capacity();
        str& operator+(const str& other);
        str& operator+=(const str& other);
        str& operator-(const str& substr);
        str& operator*(size_t repetitions);
        str substr(size_t begin, size_t end, size_t step=1);
        str substr(size_t begin, size_t size, size_t step=1);
        str substr(char sentinel, size_t begin=0, size_t step=1);
        str copy(size_t begin=0, size_t end=0);
        str find(str& substr);
        str rfind(str& substr);
        void clear();
        bool empty();
        char operator[](size_t index);
        char at();
        char back();
        char front();
        void swap();
        char* c_str();
        int compare();

};