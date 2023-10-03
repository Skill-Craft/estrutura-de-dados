#include <iostream>
#include <vector>


namespace sort{
    using namespace std;

    template<typename T>
    void bubble_sort(vector<T> arr){
        for(int i=0;i<arr.size()-1;i++){
            for(int j=0;j<arr.size()-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }

    template <typename T>
    vector<T> merge(vector<T> left, vector<T> right){
        auto it1=left.begin(), it2=right.begin();
        vector<T> res;
        while(it1!=left.end() || it2 !=right.end()){
            if(it1 == left.end()){
                res.push_back(*it2);
                it2++;
            } else if(it2 == right.end()){
                res.push_back(*it1);
                it1++;
            } else if(*it1 < *it2){
                res.push_back(*it1);
                it1++;
            } else{
                res.push_back(*it2);
                it2++;
            }
        }
        return res;
    }

    template <typename T>
    vector<T> merge_sort(vector<T> arr){
        if(arr.size() <= 1) return arr;
        int mid = arr.size() / 2;
        vector<int> left(arr.begin(),arr.begin()+mid);
        left = merge_sort(left);
        vector<int> right(arr.begin()+mid,arr.end());
        right = merge_sort(right);
        return merge(left, right);
    }
}

using namespace std;

int main(){
    vector<int> arr{1, 3, 2, 4, 6, 8, 7, 5, 9};
    vector<int> arr2 = sort::merge_sort(arr);
    for(auto i: arr2){
        cout << i << " ";
    }
    sort::bubble_sort(arr);
    for(auto i: arr){
        cout << i << " ";
    }

    cout << endl;
    return 0;
}
