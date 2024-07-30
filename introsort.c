#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
<<<<<<< HEAD
#include <string.h> // Include this for memcpy

#define INSERTION_SORT_THRESHOLD 16
#define HEAPSORT_THRESHOLD 64

// Function prototypes
void introsort(int *arr, int low, int high, int depth_limit);
void custom_heapsort(int *arr, int low, int high);
=======
#include <string.h>

#define INSERTION_SORT_THRESHOLD 27

void introsort(int *arr, int low, int high, int depth_limit);
>>>>>>> 5f963bf ([feat] cleaning up for BLAS library)
void insertion_sort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void custom_heapify(int *arr, int low, int high, int i);
void build_custom_heap(int *arr, int low, int high);
<<<<<<< HEAD
void merge(int *arr, int left, int mid, int right);
void merge_sort(int *arr, int left, int right);
void generate_random_array(int *arr, int size);
void print_array(int *arr, int size);
void benchmark_sorting_algorithms(int size, double *results);

// Introsort function
void introsort(int *arr, int low, int high, int depth_limit) {
    int size = high - low + 1;
    if (size <= INSERTION_SORT_THRESHOLD) {
=======
void custom_heapsort(int *arr, int low, int high);
void merge(int *arr, int left, int mid, int right);
void merge_sort(int *arr, int left, int right);
void generate_random_array(int *arr, int size);
void benchmark_sorting_algorithms(int size, double *results);

void introsort(int *arr, int low, int high, int depth_limit) {
    if (high - low + 1 <= INSERTION_SORT_THRESHOLD) {
>>>>>>> 5f963bf ([feat] cleaning up for BLAS library)
        insertion_sort(arr, low, high);
    } else if (depth_limit == 0) {
        custom_heapsort(arr, low, high);
    } else {
        int pi = partition(arr, low, high);
        introsort(arr, low, pi - 1, depth_limit - 1);
        introsort(arr, pi + 1, high, depth_limit - 1);
    }
}

<<<<<<< HEAD
// Insertion sort function
=======
>>>>>>> 5f963bf ([feat] cleaning up for BLAS library)
void insertion_sort(int *arr, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

<<<<<<< HEAD
// Partition function for quicksort
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
=======
int partition(int *arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
>>>>>>> 5f963bf ([feat] cleaning up for BLAS library)
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

<<<<<<< HEAD
// Heapsort functions
void custom_heapify(int *arr, int low, int high, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left <= high && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= high && arr[right] > arr[largest]) {
        largest = right;
    }
=======
void custom_heapify(int *arr, int low, int high, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left <= high && arr[left] > arr[largest]) largest = left;
    if (right <= high && arr[right] > arr[largest]) largest = right;
>>>>>>> 5f963bf ([feat] cleaning up for BLAS library)
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        custom_heapify(arr, low, high, largest);
    }
}

void build_custom_heap(int *arr, int low, int high) {
<<<<<<< HEAD
    int n = high - low + 1;
    for (int i = n / 2 - 1; i >= 0; i--) {
=======
    for (int i = (high - low + 1) / 2 - 1; i >= 0; i--) {
>>>>>>> 5f963bf ([feat] cleaning up for BLAS library)
        custom_heapify(arr, low, high, i);
    }
}

void custom_heapsort(int *arr, int low, int high) {
    build_custom_heap(arr, low, high);
    for (int i = high; i >= low; i--) {
        int temp = arr[low];
        arr[low] = arr[i];
        arr[i] = temp;
        custom_heapify(arr, low, i - 1, 0);
    }
}

<<<<<<< HEAD
// Mergesort functions
void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

=======
void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int *L = (int*)malloc(n1 * sizeof(int)), *R = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
>>>>>>> 5f963bf ([feat] cleaning up for BLAS library)
    free(L);
    free(R);
}

void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

<<<<<<< HEAD
// Utility function to generate random array
void generate_random_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }
}

// Utility function to print the array
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Benchmarking function
void benchmark_sorting_algorithms(int size, double *results) {
    double introsort_avg = 0.0;
    double mergesort_avg = 0.0;

    int MAX_RUNS = 5;

    for (int c = 0; c < MAX_RUNS; c++) {
        int *arr1 = (int*)malloc(size * sizeof(int));
        int *arr2 = (int*)malloc(size * sizeof(int));

        generate_random_array(arr1, size);
        memcpy(arr2, arr1, size * sizeof(int));

        clock_t start, end;
        double time_taken;

        // Benchmark Introsort
        start = clock();
        introsort(arr1, 0, size - 1, 2 * (int)log2(size));
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        introsort_avg += time_taken;

        // Benchmark Mergesort
        start = clock();
        merge_sort(arr2, 0, size - 1);
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        mergesort_avg += time_taken;

        free(arr1);
        free(arr2);
    }

=======
void generate_random_array(int *arr, int size) {
    for (int i = 0; i < size; i++) arr[i] = rand() % 10000;
}

void benchmark_sorting_algorithms(int size, double *results) {
    double introsort_avg = 0.0, mergesort_avg = 0.0;
    int MAX_RUNS = 5;
    for (int c = 0; c < MAX_RUNS; c++) {
        int *arr1 = (int*)malloc(size * sizeof(int)), *arr2 = (int*)malloc(size * sizeof(int));
        generate_random_array(arr1, size);
        memcpy(arr2, arr1, size * sizeof(int));
        clock_t start = clock();
        introsort(arr1, 0, size - 1, 2 * (int)log2(size));
        introsort_avg += (double)(clock() - start) / CLOCKS_PER_SEC;
        start = clock();
        merge_sort(arr2, 0, size - 1);
        mergesort_avg += (double)(clock() - start) / CLOCKS_PER_SEC;
        free(arr1);
        free(arr2);
    }
>>>>>>> 5f963bf ([feat] cleaning up for BLAS library)
    results[0] = introsort_avg / MAX_RUNS;
    results[1] = mergesort_avg / MAX_RUNS;
}

int main() {
<<<<<<< HEAD
    int EXPONENTIAL_RUNS = 10; // Adjusted for feasible runtime
    double results[2];

=======
    int EXPONENTIAL_RUNS = 10;
    double results[2];
>>>>>>> 5f963bf ([feat] cleaning up for BLAS library)
    for (int c = 0; c <= EXPONENTIAL_RUNS; c++) {
        int size = pow(10, c);
        printf("Testing array size: %d\n", size);
        benchmark_sorting_algorithms(size, results);
<<<<<<< HEAD

        printf("Introsort took %f seconds\n", results[0]);
        printf("Mergesort took %f seconds\n", results[1]);
    }

=======
        printf("Introsort took %f seconds\n", results[0]);
        printf("Mergesort took %f seconds\n", results[1]);
    }
>>>>>>> 5f963bf ([feat] cleaning up for BLAS library)
    return 0;
}
