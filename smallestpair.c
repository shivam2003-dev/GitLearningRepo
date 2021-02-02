#include <stdio.h>
#include <stdlib.h>
void merge(int p[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = p[l + i];
    for (j = 0; j < n2; j++)
        R[j] = p[m + 1 + j];
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            p[k] = L[i];
            i++;
        }
        else {
            p[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        p[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        p[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int p[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(p, l, m);
        mergeSort(p, m + 1, r);
        merge(p, l, m, r);
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int size,*p;
        scanf("%d",&size);
        p=(int*)malloc(size*sizeof(int));
        for(int i=0;i<size;i++)
        {
            scanf("%d",p[i]);
        }
       mergeSort(p, 0,size - 1);
        printf("%d\n",(p[0]+p[1]));
    }
	return 0;
}

