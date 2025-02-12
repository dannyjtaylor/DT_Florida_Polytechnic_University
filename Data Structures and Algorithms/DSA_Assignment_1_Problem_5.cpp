#include <iostream>
void cubes_recurisve(int n);


void cubes_recursive(int n) {
    if(n==1) {
        std::cout << 1 << std::endl;
    }

    else {
        std::cout << cubes_recurisve(n-1) << std::endl;

    }
}



int main(void) {
   /* int n = 5;
    int count = 0;
    for (int i = 0; i<= n; i++) {
        std::cout << "i is " << i << std::endl;
        for (int j = 1; j <= n; j++) {
            std::cout << count << std::endl;
            count++;
            std::cout << "j is" << j << std::endl;
        }
    }*/

   cubes_recursive(1);



    return 0;
}