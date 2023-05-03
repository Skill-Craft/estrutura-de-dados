#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>


using namespace std;


class str{
    private:
        char *s;
        size_t len;
        size_t cp;
    
    public:
        static const size_t npos = (size_t)(-1);
        friend ostream& operator<<(ostream& out, str& st);
        // friend istream& operator>>(istream& in, str& s); 
        str();
        str(const str& src);
        str(str&& src);
        str(const char* src);
        str(size_t length, char c);
        ~str(){delete[] s;}
        size_t length(){return len;}
        size_t capacity(){return cp;}
        str operator+(const str& other);
        str& operator+=(const str& other);
        str operator*(size_t repetitions);
        
        str substr(size_t begin, size_t size, size_t step=1);
        str substr(char sentinel, size_t begin=0, size_t step=1);
        str& operator-(const str& substr);
        str copy(size_t begin=0, size_t end=0);
        str find(str& substr);
        str rfind(str& substr);
        str& insert(char c, size_t pos);
        str& insert(const str& s, size_t pos);
        str& push_back();
        str& pop(char c, size_t pos);
        str& pop(const str& s, size_t pos);
        str& pop_back();
        void clear();
        bool empty();
        char& operator[](size_t index);
        char& at(size_t index);
        void swap(str& other);
        char* c_str();
        int compare(str& other);
};

ostream& operator<< (ostream& out, str& st){
    out << st.s;
    return out;
}

str::str(){
    len = 0;
    cp = 40;
    s = new char[cp];
}

str::str(const str& src): len{src.len}, cp{src.cp} {
    s = new char[cp];
    for(size_t i{}; i < len; i++) s[i] = src.s[i];
}

str::str(const char* src){
    char c = src[0];
    while(c != '\0'){
        len++;
        c++;
    }
    cp = len +40;
    s = new char[cp];
    for(size_t i{}; i < len; i++) s[i] = src[i];
}

str::str(str&& src): len{src.len}, cp{src.cp}, s{src.s}{
    src.s = nullptr;
}

str::str(size_t length, char c) : len{length}, cp{length + 40}{
    s = new char[cp];
    for(size_t i{}; i < length; i++) s[i] = c;
}

str str::operator+(const str &other){
    size_t new_len = this->len + other.len;
    size_t new_cp = new_len + 1; // Add space for the null character
    char *new_s = new char[new_cp];
    strcpy(new_s, this->s);
    strcat(new_s, other.s);
    str result(new_s);
    delete[] new_s;
    return result;
}

str& str::operator+=(const str &other){
    this->s = strcat(this->s, other.s);
    return *this;
}
str str::operator*(size_t repetitions){
    str aux;
    for(size_t i = 0; i < repetitions; i++){
        aux += *this;
    }
    return aux;
}

bool str::empty(){
    return len == 0;
}

void str::swap(str& other){
    str temp(other);
    strcpy(other.s, this->s);
    strcpy(this->s, temp.s);
}

char& str::operator[](size_t index){
    if(index < len && index >= 0){
        return s[index];
    } if(index < 0 && index >= -len){ 
        return s[len+index];
    } throw out_of_range("Invalid index");
}

char& str::at(size_t index){
    return operator[](index%len);
}

void str::clear(){
    delete [] s;
    cp = 40;
    len = 0;
    s = new char[cp];
}

char* str::c_str(){
    auto aux = new char[len+1];
    strcpy(aux,s);
    return aux;
}

int str::compare(str& other){
    return strcmp(s,other.s);
}

// str substr(size_t begin, size_t end, size_t step = 1);
// str substr(char sentinel, size_t begin = 0, size_t step = 1);

// str& str::operator-(const str &substr){

// }
// str copy(size_t begin = 0, size_t end = 0);
// str find(str &substr);
// str rfind(str &substr);
// str &insert(char c, size_t pos);
// str &insert(const str &s, size_t pos);
// str &push_back();
// str &pop(char c, size_t pos);
// str &pop(const str &s, size_t pos);
// str &pop_back();


int main(){
    // str a("oioioioi");
    // str b(a*8);
    // cout << b;
    // a.swap(b);
    return 0;
}