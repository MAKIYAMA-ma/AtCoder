#include <stdio.h>
#include <stdlib.h>

// 配列の要素を交換する関数
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 配列を分割し、ピボットを中心に要素を並び替える
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // 最後の要素をピボットに選択
    int i = (low - 1);     // 小さい要素のインデックス

    for (int j = low; j < high; j++) {
        // 現在の要素がピボット以下であれば
        if (arr[j] <= pivot) {
            i++; // 小さい要素のインデックスを増やす
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // ピボットを適切な位置に移動
    return (i + 1); // ピボットのインデックスを返す
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high); // 配列を分割し、ピボットのインデックスを取得

        // ピボットの左右で再帰的にクイックソートを実行
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int max(int arr[], int num)
{
    int mx = arr[0];
    int i;
    for(i = 0; i < num; i++) {
        if(mx < arr[i]) {
            mx = arr[i];
        }
    }
    return mx;
}

int min(int arr[], int num)
{
    int mn = arr[0];
    int i;
    for(i = 0; i < num; i++) {
        if(mn > arr[i]) {
            mn = arr[i];
        }
    }
    return mn;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%u ", arr[i]);
    }
    printf("\n");
}

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main (void)
{
    int n;
    int a, b;
    int i, j;
    int today;

    scanf("%d %u %u", &n, &a, &b);
    int d[n];
    for(i = 0; i < n; i++) {
        scanf("%u", &d[i]);
        d[i] = (d[i]%(a+b));
    }
    /* quickSort(d, 0, n-1); */
    qsort(d, n, sizeof(int), cmp);

    /* printArray(d, n); */

#if 1
    for(i = 0; i < n-1; i++) {
        if(d[i + 1] - d[i] > b) {
            printf("Yes\n");
            return 0;
        }
    }
    if(d[0] + a + b - d[n-1] > b) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
#else
    j = 0;
    for (int i = 1; i < n; i++) {
        if(d[j] != d[i]) {
            d[++j] = d[i];
        }
    }
    /* printArray(d, j+1); */
    for(i = 0; i < j; i++) {
        if(d[i + 1] - d[i] > b) {
            printf("Yes\n");
            return 0;
        }
    }
    if(d[0] + a + b - d[j] > b) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
#endif

    return 0;
}
