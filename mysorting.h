//
// Created by User on 2021/5/5.
//

#ifndef PD_HW01_MYSORTING_H
#define PD_HW01_MYSORTING_H
#include <string.h>
#define StringMax 100
#define SWAP(X,Y,T) ((T)=(X),(X)=(Y),(Y)=(T))
void myQuickSort(int data[], int first, int last);
void myStringQuickSort(char data[][StringMax], int first, int last);

void myMergeSort(int data[], int front, int end);
void myStringMergeSort(char data[][StringMax], int front, int end);

void merge(int data[], int front, int mid, int end);
void StringMerge(char data[][StringMax], int front, int mid, int end);

void myHeapSort(int data[],int len);
void heapify(int data[],int n,int i);

void myStringHeapSort(char data[][StringMax],int len);
void StringHeapify(char data[][StringMax],int n,int i);
#endif //PD_HW01_MYSORTING_H
