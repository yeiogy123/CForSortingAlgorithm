//
// Created by User on 2021/5/5.
//
#include "mysorting.h"
void heapify(int data[],int n,int i){
    int largest = i ;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;
    if(left < n && data[left]>data[largest])
        largest = left;
    if(right < n && data[right] > data[largest])
        largest = right;
    if(largest != i){
        SWAP(data[i],data[largest],temp);
        heapify(data,n,largest);
    }
}
void myHeapSort(int data[], int len){
    int temp;
    for(int i = len/2-1 ; i >= 0 ; i--)
        heapify(data,len,i);
    for(int i = len -1 ; i > 0 ; i--) {
        SWAP(data[0], data[i], temp);
        heapify(data,i,0);
    }
}
void StringHeapify(char data[][StringMax],int n,int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    char temp[StringMax];
    if(left < n && strcmp(data[left],data[largest])>0)
        largest = left;
    if(right < n && strcmp(data[right],data[largest])>0)
        largest = right;
    if(largest != i){
        strcpy(temp,data[i]);
        strcpy(data[i],data[largest]);
        strcpy(data[largest],temp);
        StringHeapify(data,n,largest);
    }
}
void myStringHeapSort(char data[][StringMax],int len){
    char temp[StringMax];
    for(int i = len/2-1 ; i >=0 ; i--)
        StringHeapify(data,len,i);
    for(int i = len-1 ; i > 0 ; i--){
        strcpy(temp,data[0]);
        strcpy(data[0],data[i]);
        strcpy(data[i],temp);
        StringHeapify(data,i,0);
    }
}
