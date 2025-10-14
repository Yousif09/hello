/**
 * A collection of array and 2-D array utility
 * functions.
 */

/**
 * Prints the given integer array to the standard output
 */
void printArray(const int *arr, int n);

/**
 * Prints the given (n x m) integer table to the standard
 * output.
 */
void printTable(int **table, int n, int m);

/**
 * Generates an array of integers of the given size filled
 * with random integer values between 0 and 100 (exclusive).
 * This function assumes that the random number
 * generator has already been seeded.
 */
int * generateRandomArray(int size);

/**
 * Sums the elements in the given array.
 */
int getSum(int *arr, int size);

/**
 * Frees the given (n x m) table.  Only the first parameter
 * (n, number of rows) is necessary to free the table.
 */
void freeTable(int **table, int n);

/**
 * Compute the arithmetic mean of arr. Returns 0.0 if arr is NULL or size<=0.
 */
double getMean(const int *arr, int size);

/**
 * Return the minimum element in arr. If arr is NULL or size<=0, returns 0.
 */
int getMin(const int *arr, int size);

/**
 * Return the index of the minimum element in arr.
 * Returns -1 if arr is NULL or size<=0.
 */
int getIndexOfMin(const int *arr, int size);

/**
 * Return the maximum element in arr. If arr is NULL or size<=0, returns 0.
 */
int getMax(const int *arr, int size);

/**
 * Return the index of the maximum element in arr.
 * Returns -1 if arr is NULL or size<=0.
 */
int getIndexOfMax(const int *arr, int size);

/**
 * Return a new array of elements from arr that are >= threshold.
 * On success: returns heap array and sets *resultSize; on error: returns NULL and sets *resultSize=0.
 */
int *filterThreshold(const int *arr, int size, int threshold, int *resultSize);

/**
 * Create an n×m table with (i,j) = (i+1)*(j+1); return heap 2D array or NULL on error.
 */
int **createMultiplicationTable(int n, int m);
