//
//  main.c
//  ChapterEleven
//
//  Created by Михаил Щербаков on 20.04.2022.
//

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

//struct packed {
//    unsigned int i;
//    char *p;
//};
//
//static_assert(
//    sizeof(struct packed) == sizeof(unsigned int) + sizeof(char *),
//    "struct packed must not have any padding"
//);


void clear_stdin(void) {
    int c;

    do {
        c = getchar();
        static_assert(UCHAR_MAX < UINT_MAX, "FIO34-C violation");
    } while (c != EOF);
}


//MARK: Использование static_assert для проверки границ

//static const char prefix[] = "Error No: ";
//#define ARRAYSIZE 14
//char str[ARRAYSIZE];
//
//static assert(
//              sizeof (str) > sizeof(prefix),
//              "str must be larger than prefix");
//strcpy(str, prefix);

//void *dup_string(size_t size, char *str) {
//    assert(size <= LIMIT);
//    assert(str != NULL);
//}

//void *dup_string(size_t size, char *str ) {
//assert(size <= LIMIT && "size is larger than the expected limit"); assert(str != NULL && "the caller must ensure str is not null");
//}

int main(int argc, const char * argv[]) {
//    clear_stdin();
    printf("Hello, World!\n");
    return 0;
}
