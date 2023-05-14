#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <fstream>

using namespace std;


struct NodeHuffman{
    size_t freq;
    char c;
    string code;
    NodeHuffman* left;
    NodeHuffman* right;

    NodeHuffman(size_t freq, char ch): freq(freq), c(ch), code(), left(), right() {}
    ~NodeHuffman() {
        left = nullptr;
        right = nullptr;
    }

};


struct Compare{
    bool operator()(const NodeHuffman* a, const NodeHuffman* b) const{
        return a->freq > b->freq;
    }    
};


struct HuffmanEncoder{
    NodeHuffman* root;
    string message;
    HuffmanEncoder(priority_queue<NodeHuffman *, vector<NodeHuffman *>, Compare> &q, string message): message(message){
        // if(q.size() == 0) throw runtime_error("queue is empty");
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

    ~HuffmanEncoder() {
        // Delete tree
        if(root == nullptr) return;

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
            tracker->code.shrink_to_fit();
            return code_assignment(tracker->left, code+"0");
        } else if(tracker->left == nullptr){
            tracker->code.shrink_to_fit();
            return code_assignment(tracker->right, code+"1");
        } else{
            tracker->code.shrink_to_fit();
            bool b1 = code_assignment(tracker->left, code+"0");
            bool b2 = code_assignment(tracker->right, code+"1");
            return b1 && b2;
        }
    }

    void show_table() const{

    }

    void show_content(NodeHuffman *node) const{

    }

    string query(char c, NodeHuffman* current) const{
        if(current->c == c) return current->code;
        else if(current == nullptr){
            return "\0";
        } else{
            string aux1 = query(c, current->left);
            string aux2 = query(c, current->right);
            return aux1=="\0" ? aux2 : aux1;
        }
    }

    void encode_message(string filepath) const{
        ofstream writer;
        writer.open(filepath,ios::binary);
        if(!writer) throw runtime_error("can't open file " + filepath + " for writing");
        string aux = encoded_msg_string();
        writer.write(aux.c_str(),sizeof(aux.c_str())); // test it later 
        writer.close();
    }

    string encoded_msg_string() const{
        return "\0";
    }

};

struct HuffmanPreprocessor{

    string buffer;
    priority_queue<NodeHuffman *, vector<NodeHuffman *>, Compare> frequencies;

    HuffmanPreprocessor(string content) : buffer(content), frequencies(get_frequencies()) {}

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


ostream& operator<<(ostream& os, const HuffmanEncoder& encoder){
    os << encoder.encoded_msg_string();
    return os;
}


size_t getsizeof(NodeHuffman enc){
    size_t aux = sizeof(enc) + sizeof(enc.code.c_str());
    if(enc.left != nullptr) aux += sizeof(enc.left);
    if(enc.right != nullptr) aux += sizeof(enc.right);
    return aux;
}

size_t getsizeof(HuffmanEncoder enc){
    return getsizeof(*(enc.root)) + sizeof(enc);
}



struct HuffmanDecoder{

    NodeHuffman* root;

    HuffmanDecoder(NodeHuffman* root): root(root) {}
    HuffmanDecoder(HuffmanEncoder enc): root(enc.root) {
        enc.root = nullptr;
    }


    void decode_message(string filepath){}
};



int main(){
    string s = "sdffdgghhjkkj";
    HuffmanPreprocessor alfa(s);
    // alfa.frequencies = alfa.get_frequencies();
    cout << alfa.frequencies.size() << endl;
    HuffmanEncoder beta(alfa.frequencies, s);
    beta.encode_message("helloworld.dat");
    // cout << beta.root->right->left->right->c;
    // pq = alfa.get_frequencies();
    // cout << pq.size() << endl;
        // cout << getsizeof(alfa.tree) << endl<< 100+130+8*15;
        return 0;
}