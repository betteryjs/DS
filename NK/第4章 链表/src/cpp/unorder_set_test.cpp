#include <unordered_set>
#include <iostream>


using namespace std;

int main(){
    unordered_set<int> set1{2,4,6};
    unordered_set<int> set2{5,7,6};
    set1.merge(set2);
    for(auto c : set1){
        cout << c<<" ";
    }
    cout<< endl;
    cout<< "have 2 ? "<< set1.contains(2) << endl;

    return 0;

}