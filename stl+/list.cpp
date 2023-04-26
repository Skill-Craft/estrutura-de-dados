#include <iostream>
#include <vector>


using namespace std;


// TODO: Implement an object that contains all data types (aka string, double, long long, ...)
union object{
    string str;
    double dbl;
    long long ll;

    object(string s): str{s} {}
    object(double d): dbl{d} {}
    object(long long l): ll{l} {}
};


// TODO: recreate Python's list
class list{
    vector<object*> data;

    public:
        list(): data{} {}
};

int main(){
    
    return 0;
}