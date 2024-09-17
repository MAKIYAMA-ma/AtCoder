#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 順序付き配列構造体
 */
typedef struct {
    int *array;
    int size;
    int capacity;
} SortedArray;

/**
 * @brief 順序付き配列の初期化関数
 *
 * @param capacity 確保する容量
 *
 * @return 作成した順序付き配列のポインタ
 */
SortedArray* init_sorted_array(int capacity)
{
    SortedArray *arr = (SortedArray*)malloc(sizeof(SortedArray));
    arr->array = (int*)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

/**
 * @brief 順序付き配列に要素を追加する。結果は昇順ソートとする。
 *
 * @param arr 対象の順序付き配列
 * @param value 追加する値
 */
void insert_sorted(SortedArray *arr, int value)
{
    int i;

    if (arr->size == arr->capacity) {
        // あふれるなら拡張する
        arr->capacity *= 2;
        arr->array = (int*)realloc(arr->array, arr->capacity * sizeof(int));
    }

    for (i = arr->size - 1; (i >= 0 && arr->array[i] > value); i--) {
        arr->array[i + 1] = arr->array[i];
    }
    arr->array[i + 1] = value;
    arr->size++;
}

/**
 * @brief 順序付き配列から、指定の値を二分探索する
 *
 * @param arr 対象の順序付き配列
 * @param target 探索する値
 *
 * @return 発見されたIndex。ないなら-1。
 */
int binary_search(SortedArray *arr, int target)
{
    int left = 0;
    int right = arr->size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr->array[mid] == target)
            return mid; // 発見されたIndex
        if (arr->array[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // 発見できなかった
}

/**
 * @brief 順序付き配列から、指定の値以下の最近値を二分探索する
 *
 * @param arr 対象の順序付き配列
 * @param target 探索する値
 *
 * @return 発見されたIndex。ないなら-1。
 */
int find_closest_below_or_equal(SortedArray *arr, int target)
{
    int left = 0;
    int right = arr->size - 1;
    int closest = -1; // 発見できなければこのままreturnされる

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr->array[mid] <= target) {
            closest = mid;
            left = mid + 1; // 右側により近い値がありうるので継続する
        } else {
            right = mid - 1;
        }
    }

    return closest;
}

/**
 * @brief 指定した値を削除する
 *
 * @param arr 対象の順序付き配列
 * @param value 削除する値
 *
 * @return 0:成功/-1:失敗
 */
int delete_value(SortedArray *arr, int value)
{
    int index = binary_search(arr, value);
    if (index == -1) {
        return -1;
    }

    for (int i = index; i < arr->size - 1; i++) {
        arr->array[i] = arr->array[i + 1];
    }

    arr->size--;
    return 0;
}

/**
 * @brief 指定したindexのデータを削除する
 *
 * @param arr 対象の順序付き配列
 * @param index 削除するインデックス
 *
 * @return 0:成功/-1:失敗
 */
int delete_index(SortedArray *arr, int index)
{
    if (index >= arr->size) {
        return -1;
    }

    for (int i = index; i < arr->size - 1; i++) {
        arr->array[i] = arr->array[i + 1];
    }

    arr->size--;
    return 0;
}

/**
 * @brief 指定したindexからnum個のデータを削除する
 *
 * @param arr 対象の順序付き配列
 * @param index 削除するインデックス
 *
 * @return 0:成功/-1:失敗
 */
int delete_index_bulk(SortedArray *arr, int index, int num)
{
    int rest;

    if (index >= arr->size) {
        return -1;
    }

    rest = arr->size - index;
    if(num > rest) {
        arr->size -= rest;
    } else {
        for (int i = index; i < arr->size - num; i++) {
            arr->array[i] = arr->array[i + num];
        }
        arr->size -= num;
    }

    return 0;
}

/**
 * @brief 順序付き配列の内容を表示
 *
 * @param arr 対象の順序付き配列
 */
void print_sorted_array(SortedArray *arr)
{
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}

/**
 * @brief 順序付き配列のメモリを解放する
 *
 * @param arr 対象の順序付き配列
 */
void free_sorted_array(SortedArray *arr)
{
    free(arr->array);
    free(arr);
}

void print_cell(SortedArray **harr, SortedArray **warr, int h, int w)
{
    int k;

    printf("------------------\n");
    printf("harr:\n");
    for(k = 0; k < h; k++) {
        print_sorted_array(harr[k]);
    }
    printf("warr:\n");
    for(k = 0; k < w; k++) {
        print_sorted_array(warr[k]);
    }
    printf("------------------\n");
}

int main(void)
{
    int h, w, q;
    int r, c;
    int i, j;
    int sum;
    int k;

    // 初期化処理
    scanf("%d %d %d", &h, &w, &q);
    sum = h*w;
    SortedArray **harr = (SortedArray**)malloc(sizeof(SortedArray*)*h);
    SortedArray **warr = (SortedArray**)malloc(sizeof(SortedArray*)*w);

    for(i = 0; i < h; i++) {
        harr[i] = init_sorted_array(w);
        for(j = 0; j < w; j++) {
            insert_sorted(harr[i], j+1);
        }
    }
    for(i = 0; i < w; i++) {
        warr[i] = init_sorted_array(h);
        for(j = 0; j < h; j++) {
            insert_sorted(warr[i], j+1);
        }
    }

    print_cell(harr, warr, h, w);

    // クエリ処理
    for(i = 0; i < q; i++) {
        scanf("%d %d", &r, &c);

        // 列方向の処理
        if(harr[r-1]->size > 0) {
            // 列方向にカベが残っている
            int hind = find_closest_below_or_equal(harr[r-1], c);
            printf("hind:%d\n", hind);
            if(hind < 0) {
                // 発見できず->c以下のマスにはカベがない
                // c以上の側のマスは削除
                int tgt = harr[r-1]->array[0];
                delete_index(harr[r-1], 0);
                delete_value(warr[c-1], tgt);
                sum--;
            } else {
                if(harr[r-1]->array[hind] == c) {
                    // 対象の壁が存在する
                    // 対象の壁を削除
                    delete_index(harr[r-1], hind);
                    delete_value(warr[c-1], r);
                    sum--;
                    print_cell(harr, warr, h, w);
                    continue;
                } else {
                    if(hind >= harr[r-1]->size - 1) {
                        // c以上のマスにはカベがない
                        // c以下の側のマスは削除
                        int tgt = harr[r-1]->array[harr[r-1]->size-1];
                        delete_index(harr[r-1], harr[r-1]->size-1);
                        delete_value(warr[c-1], tgt);
                        sum--;
                    } else {
                        // cの前後両方のカベを削除
                        int tgt1 = harr[r-1]->array[hind];
                        int tgt2 = harr[r-1]->array[hind+1];
                        delete_index_bulk(harr[r-1], hind, 2);
                        delete_value(warr[tgt1-1], r);
                        delete_value(warr[tgt2-1], r);
                        sum -= 2;
                    }
                }
            }
        }
        print_cell(harr, warr, h, w);
        // 行方向の処理
        if(warr[c-1]->size > 0) {
            int wind = find_closest_below_or_equal(warr[c-1], r);
            printf("wind:%d\n", wind);
            // 列方向にカベが残っている
            if(wind < 0) {
                // 発見できず->c以下のマスにはカベがない
                // r以上の側のマスは削除
                int tgt = warr[c-1]->array[0];
                delete_index(warr[c-1], 0);
                delete_value(harr[r-1], tgt);
                sum--;
            } else {
                if(warr[c-1]->array[wind] == r) {
                    /* // 対象の壁が存在する */
                    /* // 対象の壁を削除 */
                    /* delete_index(warr[c], wind); */
                    /* delete_value(harr[r], r); */
                    /* sum--; */
                    /* この壁はhのほうの処理で消えている */
                } else {
                    if(wind >= warr[c-1]->size - 1) {
                        // r以上のマスにはカベがない
                        // r以下の側のマスは削除
                        int tgt = warr[c-1]->array[warr[c-1]->size-1];
                        delete_index(warr[c-1], warr[c-1]->size-1);
                        delete_value(harr[r-1], tgt);
                        sum--;
                    } else {
                        // cの前後両方のカベを削除
                        int tgt1 = warr[c-1]->array[wind];
                        int tgt2 = warr[c-1]->array[wind+1];
                        delete_index_bulk(warr[c-1], wind, 2);
                        delete_value(harr[tgt1-1], c);
                        delete_value(harr[tgt2-1], c);
                        sum -= 2;
                    }
                }
            }
        }
        print_cell(harr, warr, h, w);
    }

    printf("%d\n", sum);

    for(i = 0; i < h; i++) {
        free_sorted_array(harr[i]);
    }
    for(i = 0; i < w; i++) {
        free_sorted_array(warr[i]);
    }

    return 0;
}
