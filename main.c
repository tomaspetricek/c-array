#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "carray.h"

int main()
{
    int vals[] = {1, 2, 3, 4, 27};
    struct Array arr;
    int err = Array_create(&arr, vals, 5, 10);

    if (!err) {
        Array_display(&arr);
    }else {
        log_error("Cannot create array", err);
        return err;
    }

    int val = 29;
    err = Array_sorted_insert(&arr, val);

    if (!err) {
        printf("Insert sorted\n");
        Array_display(&arr);
    }
    else {
        log_error("Cannot insert into sorted", err);
    }

    int sorted;
    err = Array_sorted(&arr, &sorted);

    if (!err) {
        printf("Is sorted: %d\n", sorted);
    }
    else {
        log_error("Cannot check sorted", err);
    }

    // binary search
    int idx = 0;
    val = -1;
    err = Array_binary_search(&arr, val, &idx);

    if (!err) {
        printf("Value: %d is at index: %d\n", val, idx);
    }
    else {
        log_error("Binary search element", err);
    }

    // copy array
    struct Array arr2;
    err = Array_copy(&arr, &arr2);

    if (!err) {
        printf("Copy:\n");
        Array_display(&arr2);
        Array_free(&arr2);
    }
    else {
        log_error("Cannot copy array", err);
    }

    // max
    int max = 0;
    err = Array_max(&arr, &max);

    if (!err) {
        printf("Maximum is: %d\n", max);
    }
    else {
        log_error("Cannot find maximum", err);
    }

    // sum
    int sum = 0;
    err = Array_sum(&arr, &sum);

    if (!err) {
        printf("Sum is: %d\n", sum);
    }
    else {
        log_error("Cannot calculate sum", err);
    }

    // min
    int min = 0;
    err = Array_min(&arr, &min);

    if (!err) {
        printf("Min is: %d\n", min);
    }
    else {
        log_error("Cannot find minimum", err);
    }

    // reverse
    err = Array_reverse(&arr);

    if (!err) {
        printf("Reversed:\n");
        Array_display(&arr);
    }
    else {
        log_error("Cannot reverse array", err);
    }

    // rotate right
    err = Array_rotate_right(&arr);

    if (!err) {
        printf("Right rotation:\n");
        Array_display(&arr);
    }
    else {
        log_error("Cannot rotate right", err);
    }

    // rotate left
    err = Array_rotate_left(&arr);

    if (!err) {
        printf("Left rotation:\n");
        Array_display(&arr);
    }
    else {
        log_error("Cannot rotate left", err);
    }

    // shift right
    err = Array_shift_right(&arr);

    if (!err) {
        printf("Right shift:\n");
        Array_display(&arr);
    }
    else {
        log_error("Cannot shift right", err);
    }

    // shift left
    err = Array_shift_left(&arr);

    if (!err) {
        printf("Left shift:\n");
        Array_display(&arr);
    }
    else {
        log_error("Cannot shift left", err);
    }

    // append an element
    err = Array_append(&arr, 5);

    if (!err) {
        printf("Append:\n");
        Array_display(&arr);
    }
    else {
        log_error("Cannot append", err);
    }

    // fill rest
    err = Array_fill_rest(&arr, 6);

    if (!err) {
        printf("Fill rest:\n");
        Array_display(&arr);
    }
    else {
        log_error("Cannot fill rest", err);
    }

    // insert an element
    err = Array_insert(&arr, 9, 7);

    if (!err) {
        printf("Insert:\n");
        Array_display(&arr);
    }
    else {
        log_error("Cannot insert", err);
    }

    // delete an element
    err = Array_delete(&arr, 200);

    if (!err) {
        printf("Delete:\n");
        Array_display(&arr);
    }
    else {
        log_error("Cannot delete", err);
    }

    // linear search
    idx = 0;
    val = 9;
    err = Array_linear_search(&arr, val, &idx);

    if (!err) {
        printf("Value: %d is at index: %d", val, idx);
    }
    else {
        log_error("Linear search element", err);
    }

    //int vals2[] = {-6, 3, -8, 10, 5, -7, -9, 12, -4, 2};
    int vals2[] = {1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
    struct Array arr3;
    err = Array_create(&arr3, vals2, 10, 10);

    if (!err) {
        Array_display(&arr3);
    }
    else {
        log_error("Cannot create array", err);
        return EXIT_FAILURE;
    }

    err = Array_sign_partition(&arr3);

    if (!err) {
        printf("Sign partition:\n");
        Array_display(&arr3);
    }
    else {
        log_error("Cannot sign partition", err);
    }

    Array_free(&arr3);

    // merge sorted arrays
    int vals4[] = {0, 1, 3, 3, 4};
    struct Array arr4;
    err = Array_create(&arr4, vals4, 5, 5);

    if (!err) {
        printf("Array 4 created:\n");
        Array_display(&arr4);
    } else {
        log_error("Cannot create array", err);
        return EXIT_FAILURE;
    }

    int vals5[] = {-1, 2, 3, 4};
    struct Array arr5;
    err = Array_create(&arr5, vals5, 4, 4);

    if (!err){
        printf("Array 5 created:\n");
        Array_display(&arr5);
    }else{
        log_error("Cannot create array", err);
        return EXIT_FAILURE;
    }

    struct Array res;
    err = Array_sorted_merge(&arr4, &arr5, &res);

    if (!err) {
        printf("Sorted arrays merged:\n");
        Array_display(&res);
    } else {
        log_error("Cannot merge arrays", err);
    }

    Array_free(&res);


    // union
    int vals6[] = {0, 10, 15, 1, 7};
    struct Array arr6;
    err = Array_create(&arr6, vals6, 5, 5);

    if (!err) {
        printf("Array 6 created:\n");
        Array_display(&arr6);
    } else {
        log_error("Cannot create array", err);
        return EXIT_FAILURE;
    }

    int vals7[] = {0, 9, 12, 100, 1, 10};
    struct Array arr7;
    err = Array_create(&arr7, vals7, 6, 6);

    if (!err){
        printf("Array 7 created:\n");
        Array_display(&arr7);
    }else{
        log_error("Cannot create array", err);
        return EXIT_FAILURE;
    }

    err = Array_union(&arr6, &arr7, &res);

    if (!err) {
        printf("Union of two arrays\n");
        Array_display(&res);
    } else {
        log_error("Cannot make union", err);
    }

    Array_free(&arr6);
    Array_free(&arr7);
    Array_free(&res);

    // sorted union
    int vals8[] = {2, 3, 4, 7, 10};
    struct Array arr8;
    err = Array_create(&arr8, vals8, 5, 5);

    if (!err) {
        printf("Array 8 created:\n");
        Array_display(&arr8);
    } else {
        log_error("Cannot create array", err);
        return EXIT_FAILURE;
    }

    int vals9[] = {0, 1, 2, 3, 4, 7};
    struct Array arr9;
    err = Array_create(&arr9, vals9, 6, 6);

    if (!err){
        printf("Array 9 created:\n");
        Array_display(&arr9);
    }else{
        log_error("Cannot create array", err);
        return EXIT_FAILURE;
    }

    err = Array_sorted_union(&arr8, &arr9, &res);

    if (!err) {
        printf("Union of two sorted arrays\n");
        Array_display(&res);
    } else {
        log_error("Cannot make union", err);
    }

    Array_free(&arr8);
    Array_free(&arr9);
    Array_free(&res);

    Array_free(&arr4);
    Array_free(&arr5);
    Array_free(&arr);

    Array
    return EXIT_SUCCESS;
}
