#include "myinclude.h"

void read(int A[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                scanf("%d", &A[i]);
}

void print(int A[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                printf("%d ", A[i]);
        printf("\n");
}

int max(int A[], int n)
{
        // Энд функцыг хэрэгжүүл
        int max = A[0];
        for(int i = 0; i < n; i++){
                if(A[i] > max){
                        max = A[i];
                }
        }

        return max;
}

int min(int A[], int n)
{
        // Энд функцыг хэрэгжүүл       
        int min = A[0];
        for(int i = 0; i < n; i++){
                if(A[i] < min){
                        min = A[i];
                }
        }

        return min;
}

void copy(int A[], int n, int B[])
{
        // Энд функцыг хэрэгжүүл     
        for(int i = 0; i < n; i++){
                B[i] = A[i];
        }   
}

int find(int A[], int n, int x)
{
        // Энд функцыг хэрэгжүүл     
        for(int i = 0; i < n; i++){
                if(A[i] == x){
                        return i;
                }
        }   
        return -1;
}

int make_set(int A[], int n, int B[])
{
        // Энд функцыг хэрэгжүүл     
        int size = 0;
        int index = 0;

        for(int i = 0; i < n; i++){
                int t = 1;
                for(int j = 0; j < i; j++){
                        if(A[i] == A[j]){
                                t = 0;
                                break;
                        }
                }
                if(t){
                        B[index++] = A[i];
                        size++;
                }
        }
        return size;
}

int union_set(int A[], int n, int B[], int m)
{
        // Энд функцыг хэрэгжүүл     
        copy(A, n, B + m);
        return make_set(B, n + m, A);   
}

int intersection_set(int A[], int n, int B[], int m, int C[])
{
        // Энд функцыг хэрэгжүүл
        int index = 0;
        for (int i = 0; i < n; i++){
                int t = 0;
                for(int j = 0; j < m; j++){
                        if(A[i] == B[j]){
                                t = 1;
                                break;
                        }
                }
                if(t){
                        C[index++] = A[i];
                }
        }
        return index;
}

