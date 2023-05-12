#include <iostream>


using namespace std;


class Node{
    int *value;
    public:
    Node* next;
    Node(int value) : value(new int(value)) {};
    Node(const Node& node){};
    void setval(int v) { *value = v; }
    int getval() {return *value; }
    ~Node() {next = nullptr; delete value;}
};

class LinkedList{
    Node* head;
    Node* tail;
    size_t sz;
    
    public:
        LinkedList(){head = nullptr; tail = nullptr;sz = 0;}
        LinkedList(const LinkedList& other){

        }
        ~LinkedList(){
            if(sz == 0) return;
            else if(sz == 1) delete head;
            else{
                Node* aux = head;
                while(aux != tail){
                    head = aux->next;
                    delete aux;
                    aux = head;
                }
                delete tail;
            }
        }

        virtual void push_back(int val){
            Node* new_node = new Node(val);
            if(sz == 0){
                head = tail = new_node;
                sz++;
                return;
            }
            tail-> next = new_node;
            tail = new_node;
            sz++;
        }

        virtual void push_front(int val){
            Node* new_node = new Node(val);
            if(sz == 0){
                head = tail = new_node;
                sz++;
                return;
            }
            new_node-> next = head;
            head = new_node;
            sz++;
        }
        
        virtual int pop_front(){
            if(sz == 0) throw runtime_error("Empty linked list");
            int val = head->getval();
            Node* aux = head->next;
            delete head;
            head = aux;
            sz--;
            return val;
        }

        virtual int pop_back(){
            if(sz == 0) throw runtime_error("Empty linked list");
            if(sz == 1) return pop_front();
            int val = tail->getval();
            Node* aux = head;
            while(aux -> next != tail) aux = aux -> next;
            delete tail;
            tail = aux;
            tail -> next = nullptr;
            sz--;
            return val;
        }

        virtual void printall(){
            Node* aux = head;
            while(aux != nullptr){
                cout << aux -> getval() << " ";
                aux = aux->next;
            } 
        }

        size_t size() { return sz; }

        virtual int top(){return tail->getval();}
        
        virtual int first(){return head->getval();}

        class Iterator{
            Node* it;
            public:
                Iterator(Node* it) : it(it) {}
                Iterator operator++(int){return Iterator(it ->next);}
                Iterator operator++(){
                    Iterator aux = this->it;
                    ++(*this);
                    return aux;
                }

                Iterator operator+(size_t iter){
                    return *this;
                }

        };

        Iterator begin(){ return Iterator(head); }
        
        Iterator end() { 
            return Iterator(tail); //nullptr? 
        }

};

class Stack: public LinkedList{
        virtual void push_front(int val) override final { throw invalid_argument("not allowed"); }
        virtual int pop_front() override final { throw invalid_argument("not allowed"); }
        virtual int first() override final { throw invalid_argument("not allowed"); }
    public:
        Stack& operator<< (int val) {push_back(val); return *this;}
        Stack& operator>> (int val) {val = pop_back(); return *this;}
};  

class Queue: public LinkedList{
        virtual void push_front(int val) override final {throw invalid_argument("not allowed");}
        virtual int pop_back() override final {throw invalid_argument("not allowed");}
        virtual int top() override final { throw invalid_argument("not allowed"); }
    public:
        Queue& operator<< (int val) {push_back(val); return *this;}
        Queue& operator>> (int val) {val = pop_front(); return *this;}
};

class DoubleLinkedList{

};

int main(){
    Queue  q;
    q << 12 << 13 << 14 << 15;
    q.printall();
    int a, b, c, d;
    q >> a >> b >> c;
    q.printall();
    return 0;
}