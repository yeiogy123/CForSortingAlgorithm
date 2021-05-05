#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "mysorting.h"
#define MAX 1000000
#define StringMax 100
int main() {
    int NumData[MAX];
    char StringData[MAX][StringMax];
    FILE *fp1, *fp2;
    const char NumFile[] = "dataset1.txt";
    const char StringFile[] = "dataset2.txt";
    fp1 = fopen(NumFile,"w");
    fp2 = fopen(StringFile,"w");

    printf("generate random int and string\n");
    srand(1);
    for(int i = 0 ; i < MAX ; i++){
        NumData[i] = rand();
        fprintf(fp1,"%d\n",NumData[i]);
    }
    for(int i = 0 ; i < MAX ; i++){
        for(int j = 0 ; j < StringMax-1 ; j++){
            StringData[i][j] = 'a' + rand()%26;
        }
        StringData[i][StringMax-1] = '\0';
        fprintf(fp2,"%s\n",StringData[i]);
    }


    struct timeval begin,end;
    unsigned long different;
    gettimeofday(&begin,NULL);
    myQuickSort(NumData,0,MAX-1);
    gettimeofday(&end,NULL);
    different = 1000000 * (end.tv_sec - begin.tv_sec) + end.tv_usec - begin.tv_usec;
    printf("QuickSort Time for int is %f \n",(float)different/1000000);
    gettimeofday(&begin,NULL);
    myStringQuickSort(StringData,0,MAX-1);
    gettimeofday(&end,NULL);
    different = 1000000 * (end.tv_sec - begin.tv_sec) + end.tv_usec - begin.tv_usec;
    printf("QuickSort Time for string is %f \n",(float)different/1000000);

    printf("generate random int and string\n");
    srand(1);
    for(int i = 0 ; i < MAX ; i++)
        NumData[i] = rand();
    for(int i = 0 ; i < MAX ; i++){
        for(int j = 0 ; j < StringMax-1 ; j++)
            StringData[i][j] = 'a' + rand()%26;
        StringData[i][StringMax-1] = '\0';
    }


    gettimeofday(&begin,NULL);
    myMergeSort(NumData,0,MAX-1);
    gettimeofday(&end,NULL);
    different = 1000000 * (end.tv_sec - begin.tv_sec) + end.tv_usec - begin.tv_usec;
    printf("MergeSort Time for int is %f \n",(float)different/1000000);
    gettimeofday(&begin,NULL);
    myStringMergeSort(StringData,0,MAX-1);
    gettimeofday(&end,NULL);
    different = 1000000 * (end.tv_sec - begin.tv_sec) + end.tv_usec - begin.tv_usec;
    printf("MergeSort Time for string is %f \n",(float)different/1000000);



    printf("generate random int and string\n");
    srand(1);
    for(int i = 0 ; i < MAX ; i++)
        NumData[i] = rand();
    for(int i = 0 ; i < MAX ; i++){
        for(int j = 0 ; j < StringMax-1 ; j++)
            StringData[i][j] = 'a' + rand()%26;
        StringData[i][StringMax-1] = '\0';
    }


    gettimeofday(&begin,NULL);
    myHeapSort(NumData,MAX);
    gettimeofday(&end,NULL);
    different = 1000000 * (end.tv_sec - begin.tv_sec) + end.tv_usec - begin.tv_usec;
    printf("HeapSort Time for int is %f \n",(float)different/1000000);
    gettimeofday(&begin,NULL);
    myStringHeapSort(StringData,MAX);
    gettimeofday(&end,NULL);
    different = 1000000 * (end.tv_sec - begin.tv_sec) + end.tv_usec - begin.tv_usec;
    printf("HeapSort Time for string is %f \n",(float)different/1000000);
    return 0 ;
}
