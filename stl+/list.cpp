#include <iostream>
#include <vector>


using namespace std;

class Object{
    size_t ull;
    int integer;
    float floatpoint;
    double doublefloating;
    long long int longlong;
    char character;

    enum class Type{
        INTEGER,
        FLOAT,
        DOUBLE,
        LONG,
        UNSIGNED_LONG,
        CHARACTER
    };

    Type type;

    public:

    explicit Object(size_t val): ull(val), integer(), floatpoint(), doublefloating(),
                         longlong(), character(), type(Type::UNSIGNED_LONG) {}

    explicit Object(int val) : ull(), integer(val), floatpoint(), doublefloating(),
                         longlong(), character(), type(Type::INTEGER) {}

    explicit Object(float val) : ull(), integer(), floatpoint(val), doublefloating(),
                         longlong(), character(), type(Type::FLOAT) {}

    explicit Object(double val) : ull(), integer(), floatpoint(), doublefloating(val),
                         longlong(), character(), type(Type::DOUBLE) {}

    explicit Object(long long val) : ull(), integer(), floatpoint(), doublefloating(),
                         longlong(val), character(), type(Type::LONG) {}

    explicit Object(char val) : ull(), integer(), floatpoint(), doublefloating(),
                         longlong(), character(val), type(Type::CHARACTER) {}

    Object(const Object &other) : ull(other.ull), integer(other.integer), floatpoint(other.floatpoint),
                              doublefloating(other.doublefloating),longlong(other.longlong),
                               character(other.character), type(other.type) {}

    Object(Object &&other) : ull(other.ull), integer(other.integer), floatpoint(other.floatpoint),
                              doublefloating(other.doublefloating),longlong(other.longlong),
                               character(other.character), type(other.type) {}

    friend ostream& operator<<(ostream& os, const Object& obj) {
        switch(obj.type) {
            case Type::INTEGER:
                os << obj.integer;
                break;
            case Type::DOUBLE:
                os << obj.doublefloating;
                break;
            case Type::CHARACTER:
                os << obj.character;
                break;
            case Type::LONG:
                os << obj.longlong;
                break;
            case Type::UNSIGNED_LONG:
                os << obj.ull;
                break;
            case Type::FLOAT:
                os << obj.floatpoint;
                break;
        }
        return os;
    }
};

// TODO: recreate Python's list
class list: public vector<Object>{
    public:
        template <typename T>
        void push(T val){
            push_back(Object(val));
        }
};

// class List{
//     vector<Object*> data;

//     public:
//         List(): data{} {}
//         void push_back(Object *obj){
//             data.push_back(obj);
//         }
// };


int main(){
    Object a(10);
    list data;
    data.push_back(a);
    data.push<int>(20);
    cout << data[1];
    return 0;
}