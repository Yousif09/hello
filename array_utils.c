#include <stdlib.h>
#include <stdio.h>

#include "array_utils.h"

void printArray(const int *arr, int n) {
  if(arr == NULL) {
    printf("[null]\n");
    return;
  }
  printf("[ ");
  for(int i=0; i<n-1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d ]\n", arr[n-1]);
  return;
}

void printTable(int **table, int n, int m) {
  if(table == NULL) {
    printf("[null]\n");
    return;
  }
  for(int i=0; i<n; i++) {
    printArray(table[i], m);
  }
  return;
}

int * generateRandomArray(int size) {
  if(size < 0) {
    return NULL;
  }
  int randomArr[size];
  for(int i=0; i<size; i++) {
    randomArr[i] = rand() % 100;
  }
  return randomArr;
}

int getSum(int *arr, int size) {
  if(arr == NULL) {
    return 0;
  }
  int total = 0;
  for(int i=0; i<size; i++) {
    total += arr[i];
    arr[i] = 0;
  }
  return total;
}

void freeTable(int **table, int n) {
  if(table == NULL) {
    return;
  }
  for(int i=0; i<n; i++) {
    free(table[i]);
  }
  free(table);
}

double getMean(const int *arr, int size) {
  if (arr == NULL || size <= 0) return 0.0;
  long long s = 0;
  for (int i = 0; i < size; i++) s += arr[i];
  return (double)s / (double)size;
}

int getMin(const int *arr, int size) {
  if (arr == NULL || size <= 0) return 0;
  int m = arr[0];
  for (int i = 1; i < size; i++) if (arr[i] < m) m = arr[i];
  return m;
}

int getIndexOfMin(const int *arr, int size) {
  if (arr == NULL || size <= 0) return -1;
  int idx = 0;
  for (int i = 1; i < size; i++) if (arr[i] < arr[idx]) idx = i;
  return idx;
}

int getMax(const int *arr, int size) {
  if (arr == NULL || size <= 0) return 0;
  int m = arr[0];
  for (int i = 1; i < size; i++) if (arr[i] > m) m = arr[i];
  return m;
}

int getIndexOfMax(const int *arr, int size) {
  if (arr == NULL || size <= 0) return -1;
  int idx = 0;
  for (int i = 1; i < size; i++) if (arr[i] > arr[idx]) idx = i;
  return idx;
}

int * filterThreshold(const int *arr, int size, int threshold, int *resultSize) {
  if (resultSize) *resultSize = 0;
  if (arr == NULL || size <= 0 || resultSize == NULL) return NULL;

  int count = 0;
  for (int i = 0; i < size; i++) if (arr[i] >= threshold) count++;

  int *out = (int *)malloc(sizeof(int) * count);
  if (out == NULL) return NULL;

  int j = 0;
  for (int i = 0; i < size; i++) if (arr[i] >= threshold) out[j++] = arr[i];

  *resultSize = count;
  return out;
}

int **createMultiplicationTable(int n, int m) {
    if (n <= 0 || m <= 0) return NULL;

  int **table = (int **)malloc(sizeof(int *) * n);
  if (table == NULL) return NULL;

  for (int i = 0; i < n; i++) {
    table[i] = (int *)malloc(sizeof(int) * m);
    if (table[i] == NULL) {
      for (int k = 0; k < i; k++) free(table[k]);
      free(table);
      return NULL;
    }
    for (int j = 0; j < m; j++) table[i][j] = (i + 1) * (j + 1);
  }
  return table;
}
