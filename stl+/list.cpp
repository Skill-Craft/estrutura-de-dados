#include <iostream>
#include <vector>


using namespace std;


// TODO: Implement an object that contains all data types (aka string, double, long long, ...)
class object{
    string str;
    double dbl;
    long long ll;
    int type; 
    public:
        object(string val) : str{val}, type{} {}
        object(double val) : dbl{val}, type{1} {}
        object(long long val) : ll{val}, type{2} {}
        friend ostream& operator<<(ostream& os, object& obj){
            switch(obj.type){
                case 1:
                        return os << obj.str;
                case 2:
                        return os << obj.dbl;
                case 3:
                        return os << obj.ll;
            }
            return os;
        }
};

// TODO: recreate Python's list
class List{
    vector<object*> data;

    public:
        List(): data{} {}
        void push_back(object *obj){
            data.push_back(obj);
        }
};

int main(){
    List list;
    list.push_back(new object("A"));
    list.push_back(new object((3.12)));
    return 0;
}