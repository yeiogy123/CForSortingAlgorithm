//
// Created by User on 2021/5/5.
//
#include"mysorting.h"
void myQuickSort(int data[], int front, int last){
    int i, j, pivot, temp;
    pivot = data[front];
    if(front<last){
        i = front;
        j = last + 1;
        do{
            do{i++;}
            while(data[i] < pivot);
            do{j--;}
            while(data[j] > pivot);
            if(i < j)
                SWAP(data[i],data[j],temp);
        }while(i < j);
        SWAP(data[front],data[j],temp);
        myQuickSort(data,front,j-1);
        myQuickSort(data,j+1,last);
    }
}
void myStringQuickSort(char data[][StringMax], int front, int last){
    int i, j;
    char *pivot, temp[StringMax];
    pivot = data[front];
    if(front<last){
        i = front;
        j = last + 1;
        do{
            do{i++;}
            while(strcmp(data[i],pivot) < 0);
            do{j--;}
            while(strcmp(data[j],pivot) > 0);
            if(i < j){
                strcpy(temp,data[i]);
                strcpy(data[i],data[j]);
                strcpy(data[j],temp);
            }
        }while(i < j);
        strcpy(temp,data[i]);
        strcpy(data[i],data[j]);
        strcpy(data[j],temp);
        myStringQuickSort(data,front,j-1);
        myStringQuickSort(data,j+1,last);
    }
}
