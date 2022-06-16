#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "carray.h"

int main()
{
    int vals[] = {1, 2, 3, 4, 27};
    struct Array arr;
    int err = Array_create(&arr, vals, 0, 10);
    char err_msg[20];

    if (err) {
        get_error_message(err, err_msg);
        printf("Cannot create array: %s\n", err_msg);
        return err;
    }

    int val = 29;
    err = Array_sorted_insert(&arr, val);

    if (!err) {
        printf("Insert sorted\n");
        Array_display(&arr);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot insert into sorted: %s\n", err_msg);
    }

    int sorted;
    err = Array_sorted(&arr, &sorted);

    if (!err) {
        printf("Is sorted: %d\n", sorted);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot check sorted: %s\n", err_msg);
    }

    // binary search
    int idx = 0;
    val = -1;
    err = Array_binary_search(&arr, val, &idx);

    if (!err) {
        printf("Value: %d is at index: %d\n", val, idx);
    }
    else {
        get_error_message(err, err_msg);
        printf("Binary search element: %s\n", err_msg);
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
        get_error_message(err, err_msg);
        printf("Cannot copy array: %s\n", err_msg);
    }

    // max
    int max = 0;
    err = Array_max(&arr, &max);

    if (!err) {
        printf("Maximum is: %d\n", max);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot find maximum: %s\n", err_msg);
    }

    // sum
    int sum = 0;
    err = Array_sum(&arr, &sum);

    if (!err) {
        printf("Sum is: %d\n", sum);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot calculate sum: %s\n", err_msg);
    }

    // min
    int min = 0;
    err = Array_min(&arr, &min);

    if (!err) {
        printf("Min is: %d\n", min);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot find minimum: %s\n", err_msg);
    }

    // reverse
    err = Array_reverse(&arr);

    if (!err) {
        printf("Reversed:\n");
        Array_display(&arr);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot reverse array: %s\n", err_msg);
    }

    // rotate right
    err = Array_rotate_right(&arr);

    if (!err) {
        printf("Right rotation:\n");
        Array_display(&arr);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot rotate right: %s\n", err_msg);
    }

    // rotate left
    err = Array_rotate_left(&arr);

    if (!err) {
        printf("Left rotation:\n");
        Array_display(&arr);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot rotate left: %s\n", err_msg);
    }

    // shift right
    err = Array_shift_right(&arr);

    if (!err) {
        printf("Right shift:\n");
        Array_display(&arr);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot shift right: %s\n", err_msg);
    }

    // shift left
    err = Array_shift_left(&arr);

    if (!err) {
        printf("Left shift:\n");
        Array_display(&arr);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot shift left: %s\n", err_msg);
    }

    // append an element
    err = Array_append(&arr, 5);

    if (!err) {
        printf("Append:\n");
        Array_display(&arr);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot append: %s\n", err_msg);
    }

    // fill rest
    err = Array_fill_rest(&arr, 6);

    if (!err) {
        printf("Fill rest:\n");
        Array_display(&arr);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot fill rest: %s\n", err_msg);
    }

    // insert an element
    err = Array_insert(&arr, 9, 7);

    if (!err) {
        printf("Insert:\n");
        Array_display(&arr);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot insert: %s\n", err_msg);
    }

    // delete an element
    err = Array_delete(&arr, 200);

    if (!err) {
        printf("Delete:\n");
        Array_display(&arr);
    }
    else {
        get_error_message(err, err_msg);
        printf("Cannot delete: %s\n", err_msg);
    }

    // linear search
    idx = 0;
    val = 9;
    err = Array_linear_search(&arr, val, &idx);

    if (!err) {
        printf("Value: %d is at index: %d", val, idx);
    }
    else {
        get_error_message(err, err_msg);
        printf("Linear search element: %s\n", err_msg);
    }

    Array_free(&arr);
    return EXIT_SUCCESS;
}
