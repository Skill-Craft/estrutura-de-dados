#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;


struct NodeHuffman{
    size_t freq;
    char c;
    string code;
    NodeHuffman* left;
    NodeHuffman* right;

    NodeHuffman(size_t freq, char ch): freq(freq), c(ch), code(), left(), right() {}

};


struct Compare{
    bool operator()(const NodeHuffman* a, const NodeHuffman* b) const{
        return a->freq > b->freq;
    }    
};


struct HuffmanTree{
    NodeHuffman* root;
    HuffmanTree(priority_queue<NodeHuffman *, vector<NodeHuffman *>, Compare> &q)
    {
        if(q.size() == 1) throw runtime_error("pointless use of Huffman algorithm");
        while(!q.empty()){
            if(q.size() == 1){
                root = q.top(); 
                q.pop();
                break;
            }
            NodeHuffman* first = q.top(); q.pop();
            NodeHuffman* second = q.top(); q.pop();
            NodeHuffman* aux = new NodeHuffman(first->freq+second->freq, '\0');
            aux->left = first; aux->right = second;
            
            q.push(aux);
        }
        if(!code_emplacing()) throw runtime_error("Could not code Huffman tree nodes");
    }

    bool code_emplacing(){
        return code_assignment(root, "");
    }

    bool code_assignment(NodeHuffman* tracker, string code){
        if(tracker->left == nullptr && tracker->right == nullptr){
            tracker->code = code;
            tracker->code.shrink_to_fit();
            return true;
        } else if(tracker->right == nullptr){
            return code_assignment(tracker->left, code+"0");
        } else if(tracker->left == nullptr){
            return code_assignment(tracker->right, code+"1");
        } else{
            bool b1 = code_assignment(tracker->left, code+"0");
            bool b2 = code_assignment(tracker->right, code+"1");
            return b1 && b2;
        }
    }

    // void show_table(){

    // }

    string encoded_message() const{
        return to_string(18);
    }

};

ostream& operator<<(ostream& os, const HuffmanTree& tree){
    os << tree.encoded_message();
    return os;
}

struct HuffmanEncoder{

    string buffer;
    priority_queue<NodeHuffman *, vector<NodeHuffman *>, Compare> frequencies;
    HuffmanEncoder(string content) : buffer(content){
        frequencies = get_frequencies();
    }

    priority_queue<NodeHuffman *, vector<NodeHuffman *>, Compare> get_frequencies(){
        priority_queue<NodeHuffman*, vector<NodeHuffman*>, Compare> pq;
        map<char,size_t> counter;
        for(auto c: buffer){
            counter[c]++;
        }
        for (auto pr: counter){
            pq.push(new NodeHuffman(pr.second, pr.first));
        }
        return pq;
    }
};


size_t getsizeof(NodeHuffman enc){

}

size_t getsizeof(HuffmanTree enc){

}

size_t getsizeof(HuffmanEncoder enc){

}

int main(){
    NodeHuffman *a = new NodeHuffman(10, 'a');
    NodeHuffman *b = new NodeHuffman(13, 'b');
    NodeHuffman *c = new NodeHuffman(1, 'c');
    NodeHuffman *d = new NodeHuffman(11, 'd');
    priority_queue<NodeHuffman*, vector<NodeHuffman*>, Compare> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);

    HuffmanTree ht(pq);
    cout << sizeof(ht.root->right->left) << endl
         << ht.root->right->left->code << endl
         << sizeof("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    return 0;
}