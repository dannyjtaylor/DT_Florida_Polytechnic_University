#include <iostream>


int kthnallest_int(int a[], int size, int k) {
    int i, j, temp,smallest = 0;
    for (i = 0; i < k; i++) {
    smallest = i;
      for (j = i+1; j < size; j++) {
        if (a[j]<a[smallest])
        smallest = j;
      }

      temp = a[i];
      a[i] = a[smallest];
      a[smallest] = temp;
    }
    return a[k-1];
}


void cubes_rec(int n) {
    if (n==1) {
        std::cout << 1;
    }
         else {
         cubes_rec(n-1);
         std::cout << ' ' << n*n*n;
        }
}



int main(void) {

    int arr[7] = {145, 2, 1, 3434834, 188293, 8, 0};
    //std::cout << kthnallest_int(arr,7,3) << std::endl;
    cubes_rec(5);

    return 0;
}