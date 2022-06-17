//
// Created by Tomáš Petříček on 16.06.2022.
//

#ifndef CODE_CARRAY_H
#define CODE_CARRAY_H

#include <math.h>

#include "error.h"

// Based on Udemy course:
// - title: Mastering Data Structures & Algorithms using C and C++
// - link: https://www.udemy.com/course/datastructurescncpp/

// EXIT_SUCCESS - result can be used
// EXIT_FAILURE - result can NOT be used
struct Array {
    int* data;
    int size;
    int length;
};

int Array_create(struct Array* arr, const int* vals, int length, int size)
{
    if (length<0 || size<1 || size<length) return INVALID_ARGUMENT;

    arr->size = size;
    arr->length = length;
    arr->data = (int*) malloc(sizeof(int)*size);

    if (arr->data==NULL) return BAD_ALLOCATION;

    for (int i = 0; i<length; i++)
        arr->data[i] = vals[i];

    return EXIT_SUCCESS;
}

int Array_create_empty(struct Array* arr, int size)
{
    if (size<1) return INVALID_ARGUMENT;
    arr->size = size;
    arr->length = 0;

    arr->data = (int*) malloc(sizeof(int)*size);

    if (arr->data==NULL) return BAD_ALLOCATION;

    return EXIT_SUCCESS;
}

void Array_free(struct Array* arr)
{
    free(arr->data);
}

int Array_copy(const struct Array* src, struct Array* dest)
{
    dest->length = src->length;
    dest->size = src->size;
    dest->data = (int*) malloc(dest->size*sizeof(int));

    // unable to allocate
    if (dest->data==NULL) return BAD_ALLOCATION;

    for (int i = 0; i<dest->size; i++)
        dest->data[i] = src->data[i];

    return EXIT_SUCCESS;
}

// time complexity:
// best: O(1) - fill last element
// worst: O(n) - fill all elements
int Array_fill_rest(struct Array* arr, int val)
{
    if (arr->length==arr->size) return FULL;

    for (int i = arr->length; i<arr->size; i++)
        arr->data[i] = val;

    arr->length = arr->size;
    return EXIT_SUCCESS;
}

// time complexity: O(n)
void Array_display(const struct Array* arr)
{
    for (int i = 0; i<arr->length; i++)
        printf("%d ", arr->data[i]);
    printf("\n");
}

// time complexity:
// best: O(1) - last element
// worst: O(n) - first element
int Array_insert(struct Array* arr, unsigned int idx, int val)
{
    if (arr->length==0) return EMPTY;
    if (idx<0 || idx>arr->length-1) return INDEX_OUT_OF_BOUNDS;

    for (int i = arr->length; i>idx; i--) {
        arr->data[i] = arr->data[i-1];
    }
    arr->data[idx] = val;

    if (idx<arr->length && arr->length!=arr->size)
        arr->length++;

    return EXIT_SUCCESS;
}

// time complexity: O(1)
int Array_append(struct Array* arr, int val)
{
    if (arr->length==arr->size) return FULL;

    arr->data[arr->length++] = val;
    return EXIT_SUCCESS;
}

// time complexity:
// - best: O(1) - last element
// - worst: O(n) - first element
int Array_delete(struct Array* arr, int idx)
{
    if (arr->length==0) return EMPTY;
    if (idx<0 || idx>=arr->length) return INDEX_OUT_OF_BOUNDS;

    for (int i = idx; i<arr->length-1; i++)
        arr->data[i] = arr->data[i+1];
    arr->length--;

    return EXIT_SUCCESS;
}

// time complexity:
// - best: O(1) - first element
// - worst: O(n) - last element
// - average: O(n)
int Array_linear_search(const struct Array* arr, int val, int* idx)
{
    for (int i = 0; i<arr->length; i++)
        if (arr->data[i]==val) {
            *idx = i;
            return EXIT_SUCCESS;
        }

    return ELEMENT_NOT_FOUND;
}

// elements in the array have to be sorted
// time complexity:
// - best: O(1)
// - worst: O(log(n))
// - average: O(log(n))
int Array_binary_search(const struct Array* arr, int val, int* idx)
{
    int low = 0;
    int high = arr->length-1;

    while (low<=high) {
        int mid = floor((double) (low+high)/2);

        if (val>arr->data[mid])
            low = mid+1;
        else if (val<arr->data[mid])
            high = mid-1;
        else {
            *idx = mid;
            return EXIT_SUCCESS;
        }
    }

    return ELEMENT_NOT_FOUND;
}

// time complexity: O(1)
int Array_get(const struct Array* arr, int idx, int* val)
{
    if (arr->length==0) return EMPTY;
    if (idx<0 || idx>=arr->length) return INDEX_OUT_OF_BOUNDS;

    *val = arr->data[idx];
    return EXIT_SUCCESS;
}

int Array_set(struct Array* arr, int idx, int val)
{
    if (arr->length==0) return EMPTY;
    if (idx<0 || idx>=arr->length) return INDEX_OUT_OF_BOUNDS;

    arr->data[idx] = val;
    return EXIT_SUCCESS;
}

int Array_max(const struct Array* arr, int* max)
{
    if (arr->length==0) return EMPTY;

    *max = arr->data[0];

    for (int i = 1; i<arr->length; i++)
        if (arr->data[i]>*max)
            *max = arr->data[i];

    return EXIT_SUCCESS;
}

// for unsorted array
int Array_min(const struct Array* arr, int* min)
{
    if (arr->length==0) return EMPTY;

    *min = arr->data[0];

    for (int i = 1; i<arr->length; i++)
        if (arr->data[i]<*min)
            *min = arr->data[i];

    return EXIT_SUCCESS;
}

// time complexity: O(n)
int Array_sum(const struct Array* arr, int* sum)
{
    if (arr->length==0) return EMPTY;

    *sum = 0;

    for (int i = 0; i<arr->length; i++)
        *sum += arr->data[i];

    return EXIT_SUCCESS;
}

int Array_avg(const struct Array* arr, int* avg)
{
    if (arr->length==0) return EMPTY;

    int sum = 0;
    Array_sum(arr, &sum);
    *avg = sum/arr->length;
    return EXIT_SUCCESS;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// time complexity: O(n)
int Array_reverse(struct Array* arr)
{
    for (int i = 0; i<arr->length/2; i++)
        swap(&arr->data[i], &arr->data[arr->length-1-i]);

    return EXIT_SUCCESS;
}

int Array_shift_left(struct Array* arr)
{
    if (arr->length==0) return EMPTY;

    for (int i = 1; i<arr->length; i++) {
        arr->data[i-1] = arr->data[i];
    }
    arr->data[arr->length-1] = 0;
    return EXIT_SUCCESS;
}

int Array_shift_right(struct Array* arr)
{
    if (arr->length==0) return EMPTY;

    for (int i = arr->length-1; i>0; i--) {
        arr->data[i] = arr->data[i-1];
    }
    arr->data[0] = 0;

    return EXIT_SUCCESS;
}

int Array_rotate_right(struct Array* arr)
{
    if (arr->length==0) return EMPTY;

    int last = arr->data[arr->length-1];
    Array_shift_right(arr);
    arr->data[0] = last;

    return EXIT_SUCCESS;
}

int Array_rotate_left(struct Array* arr)
{
    if (arr->length==0) return EMPTY;

    int first = arr->data[0];
    Array_shift_left(arr);
    arr->data[arr->length-1] = first;

    return EXIT_SUCCESS;
}

// array is sorted in ascending order
int Array_sorted_insert(struct Array* arr, int val)
{
    if (arr->length==arr->size) return FULL;

    int i = arr->length-1;

    for (; arr->data[i]>val && i>=0; i--)
        arr->data[i+1] = arr->data[i];

    arr->data[i+1] = val;
    arr->length++;
    return EXIT_SUCCESS;
}

// check if array is sorted in ascending order
// time complexity:
// - best: O(1) - first 2 not sorted
// - worst: O(n) - is sorted
int Array_sorted(const struct Array* arr, int* sorted)
{
    if (arr->length==0) return EMPTY;

    *sorted = 1;

    for (int i = 0; i<arr->length-1; i++)
        if (arr->data[i]>arr->data[i+1]) {
            *sorted = 0;
            return EXIT_SUCCESS;
        }

    return EXIT_SUCCESS;
}

// time complexity: O(n)
int Array_sign_partition(struct Array* arr)
{
    if (arr->length==0) return EMPTY;

    int neg_idx = 0;
    int pos_idx = arr->length-1;

    while (neg_idx<pos_idx) {
        while (arr->data[neg_idx]<0 && neg_idx<arr->length)
            neg_idx++;

        while (arr->data[pos_idx]>=0 && pos_idx>=0)
            pos_idx--;

        if (neg_idx<pos_idx)
            swap(&arr->data[neg_idx], &arr->data[pos_idx]);
    }

    return EXIT_SUCCESS;
}

// desc: merges together two sorted arrays in a single array
// time complexity: O(n)
// note: append error should not happen if all assumptions hold thus there is no need for checking for it
int Array_sorted_merge(const struct Array* fst, const struct Array* snd, struct Array* res)
{
    int size = fst->length+snd->length;
    int err = Array_create_empty(res, size);

    if (err) {
        log_error("Cannot create result array", err);
        return EXIT_FAILURE;
    }

    int fst_idx = 0, snd_idx = 0;

    while (fst_idx<fst->length && snd_idx<snd->length) {
        if (fst->data[fst_idx]<=snd->data[snd_idx])
            Array_append(res, fst->data[fst_idx++]);
        else
            Array_append(res, snd->data[snd_idx++]);
    }

    // copy remaining elements from first array
    for (; fst_idx<fst->length; fst_idx++)
        Array_append(res, fst->data[fst_idx]);

    // copy remaining elements from second element
    for (; snd_idx<snd->length; snd_idx++)
        Array_append(res, snd->data[snd_idx]);

    return EXIT_SUCCESS;
}

// desc:
// - creates union of elements from first and second array
// - array must contain unique elements
// time complexity: O(n^2)
int Array_union(const struct Array* fst, const struct Array* snd, struct Array* res)
{
    int err;
    if (fst->length==0) {
        err = Array_copy(snd, res);

        if (err) {
            log_error("Cannot copy first array", err);
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }
    else if (snd->length==0) {
        err = Array_copy(fst, res);

        if (err) {
            log_error("Cannot copy second array", err);
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }

    int size = fst->length+snd->length;
    err = Array_create_empty(res, size);

    if (err) {
        log_error("Cannot create empty result array", err);
        return EXIT_FAILURE;
    }

    // copy first array
    for (int i = 0; i<fst->length; i++)
        Array_append(res, fst->data[i]);

    int idx;
    for (int i = 0; i<snd->length; i++) {
        err = Array_linear_search(res, snd->data[i], &idx); // O(n)

        if (err==ELEMENT_NOT_FOUND)
            Array_append(res, snd->data[i]);
    }

    return EXIT_SUCCESS;
}

// desc:
// - creates union of elements from first and second array
// - array must contain unique elements and must be sorted
// time complexity: 0(n+m)
int Array_sorted_union(const struct Array* fst, const struct Array* snd, struct Array* res)
{
    int err;
    if (fst->length==0) {
        err = Array_copy(snd, res);

        if (err) {
            log_error("Cannot copy first array", err);
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }
    else if (snd->length==0) {
        err = Array_copy(fst, res);

        if (err) {
            log_error("Cannot copy second array", err);
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }

    int size = fst->length+snd->length;
    err = Array_create_empty(res, size);

    if (err) {
        log_error("Cannot create result array", err);
        return EXIT_FAILURE;
    }

    int fst_idx = 0, snd_idx = 0;

    while (fst_idx<fst->length && snd_idx<snd->length) {
        if (fst->data[fst_idx]<snd->data[snd_idx])
            Array_append(res, fst->data[fst_idx++]);
        else if (fst->data[fst_idx]==snd->data[snd_idx]) {
            Array_append(res, fst->data[fst_idx++]);
            snd_idx++;
        }
        else {
            Array_append(res, snd->data[snd_idx++]);
        }
    }

    // copy remaining elements from first array
    for (; fst_idx<fst->length; fst_idx++)
        Array_append(res, fst->data[fst_idx]);

    // copy remaining elements from second element
    for (; snd_idx<snd->length; snd_idx++)
        Array_append(res, snd->data[snd_idx]);

    return EXIT_SUCCESS;
}

// desc:
// - creates an array containing elements that are in both arrays
// - first and second array have to be arrays with unique elements
// time complexity: O(m*n) ~= O(n^2)
int Array_intersection(const struct Array* fst, const struct Array* snd, struct Array* res)
{
    int err;

    if (fst->length==0 || snd->length==0) {
        err = Array_create_empty(res, 1);

        if (err) {
            log_error("Cannot create result array", err);
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }

    int size = fst->length+snd->length;
    err = Array_create_empty(res, size);

    if (err) {
        log_error("Cannot create result array", err);
        return EXIT_FAILURE;
    }

    int idx;
    for (int fst_idx = 0; fst_idx<fst->length; fst_idx++) {
        err = Array_linear_search(snd, fst->data[fst_idx], &idx); // O(n)

        if (!err) Array_append(res, fst->data[fst_idx]);
    }

    return EXIT_SUCCESS;
}

// desc:
// time complexity:
void Array_difference(const struct Array* fst, const struct Array* snd, struct Array* res)
{

}

#endif //CODE_CARRAY_H
