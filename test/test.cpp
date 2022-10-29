//
// Created by yjs on 2022/8/13.
//

#include <iostream>
#include <string>


using namespace std;


int main(){
    string str{"azvsddvs"};
    const char * datas=str.data();
    const char * data2=str.c_str();
    cout << datas<<endl;





    return 0;
}