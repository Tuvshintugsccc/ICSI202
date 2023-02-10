#include <stdio.h>

int max(int A[], int n)
{
        // Функцийг хэрэгжүүл
        int i;
        int max = A[0];
        for(i=0; i<n; i++){
                if(max < A[i]){
                        max = A[i];
                }
        }
        return max;
}

int main()
{
        int too[100], n, i, m;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
                scanf("%d", &too[i]);

        m = max(too, n);
        printf("%d\n", m);
        return 0;
}
