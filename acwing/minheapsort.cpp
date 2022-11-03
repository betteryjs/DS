//
// Created by yjs on 2022/11/3.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class minHeap {
public:

    int heapSize;
    vector<int> heap;

    minHeap( vector<int> & arr) {
        heap.push_back(0);
        // 下标从1开始 heap[0] 不存储元素
        for (const int & a:arr) {
            heap.push_back(a);

        }
        heapSize=(int) heap.size()-2;
        buildHeap();



    }

    void minHeapify(int i) {

        while (2 * i<= heapSize) {
            int leftChild = 2 * i , rightChild = 2 * i + 1, target = leftChild;
            if (leftChild <= heapSize && heap[rightChild] < heap[leftChild]) {
                target = rightChild;
            }
            // target is the min of  the leftChild and rightChild
            if (heap[target] < heap[i]) {
                swap(heap[target], heap[i]);

            } else {
                break;
            }
            i = target;
        }
    }

    void buildHeap() {
        for (int i = heapSize / 2; i >= 1; i--) {
            minHeapify(i);
        }
    }

    int getMin() {
        if((int) heap.size()>=2){
            return heap[1];
        }
    }

    int popFirst(){
        if((int) heap.size()>=2){
            int res=heap[1];
            swap(heap[1], heap[heapSize]);
            heapSize--;
            minHeapify(1);
            return res;
        }


    }


    bool  insertHeap(const int & data){
        heap.resize(heapSize+2);
        heapSize++;
        heap[heapSize]=data;
        // i/2 is parents of i
        int i=heapSize;
        while (i>=1 && heap[i/2]>  heap[i]){
            swap(heap[i], heap[i/2]);
            i=i/2;

        }


    }

    void pprint(){

        for_each(heap.begin()+1, heap.begin()+1+heapSize, [](int & a){ cout << a << " ";});
        cout << endl;

    }



};


int main() {
    vector<int> arr{256,89,78,12,2, 13};
    minHeap * minheap=new minHeap(arr);

    // after build head
    minheap->pprint();

    cout <<"min is  " << minheap->getMin()<< endl;
    minheap->insertHeap(1);
    cout << "after insert data 1 : " ;
    minheap->pprint();
    minheap->insertHeap(7);
    cout << "after insert data 7 : " ;
    minheap->pprint();
    minheap->insertHeap(3);
    cout << "after insert data 7 : " ;
    minheap->pprint();
    cout <<"min is  " << minheap->popFirst()<< endl;
    cout << "after first data  : " ;

    minheap->pprint();











    return 0;
}