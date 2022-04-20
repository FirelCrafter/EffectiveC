//
//  main.c
//  Hello
//
//  Created by Михаил Щербаков on 05.04.2022.
//

#include <stdio.h>
#include <stdlib.h>


//int main(void) {
//    puts("Hello world!");
//    return EXIT_SUCCESS;
//}

int main(void) {
    if (puts("Hello world!") == EOF) {  // Проверка на отрицательное целое число
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
