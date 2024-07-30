# introsort
Hybrid-stable sorting algorithm that works on all comparable element types (faster than mergesort)

# Sorting Algorithm Benchmarking

This repository contains a C program that benchmarks the performance of different sorting algorithms. The main focus is on comparing Introsort and Mergesort. The program measures the time taken by each algorithm to sort arrays of various sizes.

## Code Overview

### Included Libraries

- `stdio.h`: For input and output functions.
- `stdlib.h`: For dynamic memory allocation and other utility functions.
- `time.h`: For measuring execution time.
- `math.h`: For mathematical functions such as logarithms.
- `string.h`: For memory operations like `memcpy`.

### Constants

- `INSERTION_SORT_THRESHOLD`: The size threshold below which insertion sort is used within Introsort. Set to 16.
- `HEAPSORT_THRESHOLD`: The size threshold below which Heapsort is used. Set to 64.

### Function Prototypes

The following functions are defined:

- `void introsort(int *arr, int low, int high, int depth_limit);`
- `void custom_heapsort(int *arr, int low, int high);`
- `void insertion_sort(int *arr, int low, int high);`
- `int partition(int *arr, int low, int high);`
- `void custom_heapify(int *arr, int low, int high, int i);`
- `void build_custom_heap(int *arr, int low, int high);`
- `void merge(int *arr, int left, int mid, int right);`
- `void merge_sort(int *arr, int left, int right);`
- `void generate_random_array(int *arr, int size);`
- `void print_array(int *arr, int size);`
- `void benchmark_sorting_algorithms(int size, double *results);`

### Sorting Algorithms

#### Introsort

The `introsort` function performs a hybrid sort combining:
- **Quicksort**: For large arrays.
- **Heapsort**: When recursion depth exceeds a threshold.
- **Insertion Sort**: For small arrays.

#### Insertion Sort

The `insertion_sort` function sorts a small subarray using insertion sort, which is efficient for small datasets.

#### Heapsort

The `custom_heapsort` function implements Heapsort with auxiliary functions:
- `custom_heapify`: Maintains the heap property.
- `build_custom_heap`: Constructs the initial heap.

#### Mergesort

The `merge_sort` function implements the Mergesort algorithm, which recursively divides the array and merges sorted subarrays. It relies on the `merge` function to combine two sorted halves.

### Benchmarking

The `benchmark_sorting_algorithms` function benchmarks Introsort and Mergesort by:
- Generating random arrays of various sizes.
- Measuring execution time for each sorting algorithm.
- Averaging the results over multiple runs.

### Main Function

The `main` function performs the following:
- Iterates over different array sizes (powers of 10).
- Calls `benchmark_sorting_algorithms` to measure and print the time taken by Introsort and Mergesort.

## Usage

1. **Compile the Code**:
   Use a C compiler (e.g., `clang`) to compile the source code.

   ```bash
   clang -o introsort introsort.c
   clang -o sorting_benchmark sorting_benchmark.c
   ```

2. **Run the Benchmark**:
   Execute the compiled binary to run the benchmarks.

   ```bash
   ./introsort
   ./sorting_benchmark
   ```

   The program will output the average execution time for each sorting algorithm across various array sizes.

## Notes

- The constant `EXPONENTIAL_RUNS` in the `main` function determines the maximum size of the arrays tested. Adjust this value according to your needs and system capabilities.
- Ensure your system has sufficient memory for large array sizes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please open an issue or pull request to suggest improvements or fixes.

## Contact

For questions or feedback, please reach out to [alvinlu7@gmail.com](mailto:alvinlu7@gmail.com).

---

Happy benchmarking!

This `README.md` provides a comprehensive overview of the code, its functionality, and instructions for compiling and running the benchmark. Feel free to adjust the contact details and other specifics as needed.
