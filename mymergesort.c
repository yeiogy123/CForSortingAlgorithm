//
// Created by User on 2021/5/5.
//
#include "mysorting.h"
void merge(int data[], int front, int mid, int end){
    int leftSub[mid-front+1],rightSub[end-mid], i, j, k;
    for(i = 0 ; i < mid - front + 1 ; i++)
        leftSub[i] = data[front + i];
    for(j = 0 ; j < end - mid ; j++)
        rightSub[j] = data[mid+1+j];
    i = 0;
    j = 0;
    k = front;
    while(i < mid-front+1 && (j < end-mid)){
        if(leftSub[i] <= rightSub[j]){
            data[k] = leftSub[i];
            i++;
        }else{
            data[k] = rightSub[j];
            j++;
        }
        k++;
    }
    while(i < mid-front+1)
        data[k++] = leftSub[i++];
    while(j < end-mid)
        data[k++] = rightSub[j++];
}
void StringMerge(char data[][StringMax], int front, int mid, int end){
    char leftSub[mid-front+1][StringMax],rightSub[end-mid][StringMax];
    int i, j, k;
    for(i = 0 ; i < mid-front+1;i++)
        strcpy(leftSub[i],data[front+i]);
    for(j = 0 ; j < end - mid ; j++)
        strcpy(rightSub[j],data[mid+1+j]);
    i = 0 ;
    j = 0 ;
    k = front;
    while(i < mid-front+1 && j < end-mid){
        if(strcmp(leftSub[i],rightSub[j])<=0){
            strcpy(data[k],leftSub[i]);
            i++;
        }else{
            strcpy(data[k],rightSub[j]);
            j++;
        }
        k++;
    }
    while( i < mid-front+1){
        strcpy(data[k],leftSub[i]);
        i++;
        k++;
    }
    while( j < end-mid){
        strcpy(data[k],rightSub[j]);
        j++;
        k++;
    }
}
void myMergeSort(int data[], int front, int end){
    if(front < end){
        int mid = (front + end)/2;
        myMergeSort(data,front,mid);
        myMergeSort(data,mid+1,end);
        merge(data,front,mid,end);
    }
}
void myStringMergeSort(char data[][StringMax], int front, int end){
    if(front < end){
        int mid = (front + end)/2;
        myStringMergeSort(data,front,mid);
        myStringMergeSort(data,mid+1,end);
        StringMerge(data,front,mid,end);
    }
}
