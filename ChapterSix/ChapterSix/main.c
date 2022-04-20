//
//  main.c
//  ChapterSix
//
//  Created by Михаил Щербаков on 14.04.2022.
//

#include <stdio.h>


///  Динамически выделяемая память


//MARK: malloc

/// Функция malloc выделяет место для объекта заданного размера, начальное значение которого невозможно определить.

//#include <stdlib.h>
//
//typedef struct {
//    char c[10];
//    int i;
//    double d;
//} widget;
//
//int main(int argc, const char * argv[]) {
//    widget *p = malloc(sizeof(widget));
//    if (p == NULL) {
//        // ошибка выделения
//    }
//    // продолжение обработки
//    return 0;
//}


// Ошибка инициализации

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main(void) {
//    char *str = (char *)malloc(16);
//    if (str) {
//        strncpy(str, "123456789abcdef", 15);
//        str[15] = '\0';  // Исправление ошибки приведением нулевого байта в конце блока памяти
//        printf("str = %s.\n", str);
//        free(str);
//        return EXIT_SUCCESS;
//    }
//    return EXIT_FAILURE;
//}

//MARK: aligned_alloc

/// Функция aligned_alloc похожа на malloc, но вместе с размером выделяе- мого объекта требует также указать его выравнивание.

//void *aligned_alloc(size_t alignment, size_t size);

//MARK: calloc

/// Функция calloc выделяет место для массива с nmemb объектами, каждый из которых занимает size байт.

//void *calloc(size_t nmemb, size_t size);


//MARK: realloc

/// Функция realloc увеличивает или уменьшает размер ранее выделенного блока памяти.

//void *realloc(void *ptr, size_t size);

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main(int argc, const char * argv[]) {
//    void *p2;
//    void *p = malloc(100);
//    if ((nsize == 0) || (p2 = realloc(p, nsize)) == NULL) {
//        free(p);
//        return NULL;
//    }
//    p = p2;
//    return 0;
//}


//MARK: Уязвимость двойного освобождения

//#include <dirent.h>
//#include <stdlib.h>
//#include <unistd.h>

//int closedir(DIR *dirp) {
//    free(dirp->d_buf);
//    free(dirp);
//    return close(dirp->d_fd); // dirp уже освобожден
//}

/// Указатели на уже освобожденную память называют висячими. Они явля- ются потенциальным источником ошибок (как банановая кожура на полу), поскольку с их помощью можно выполнить запись в память, которую уже освободили, или передать их функции free, что провоцирует уязвимости двойного освобождения.


//MARK: Массив произвольной длины

//#include <stdlib.h>
//
//typedef struct {
//    size_t num;
//    int data[];
//} widget;
//
//void *func(size_t array_size) {
//    widget *p = (widget *)malloc(sizeof(widget) + sizeof(int) * array_size);
//    if (p == NULL) {
//        return NULL;
//    }
//    p->num = array_size;
//    for (size_t i = 0; i < p->num; ++i) {
//        p->data[i] = 17;
//    }
//    return NULL;
//}

//MARK: alloca

//#include <stdlib.h>
//
//void printerr(errno_t errnum) {
//    rsize_t size = strerrorlen_s(errnum) + 1;
//    char *msg = (char *)alloca(size);
//    if (strerror_s(msg, size, errnum) != 0) {
//        fputc(msg, stderr);
//    }
//    else {
//        fputc("unknown error", stderr);
//    }
//
//}

//MARK: Массив переменной длины

//#include <stdlib.h>
//
//void printerr(errno_t errnum) {
//    rsize_t size = strerrorlen_s(errnum) + 1;
//    char msg[size];
//    if (strerror_s(msg, size, errnum) != 0) {
//        fputc(msg, stderr);
//    }
//    else {
//        fputc("unknown error", stderr);
//    }
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void) {
//    size_t size = 12;
//    printf("%zu\n", size);
//    (void)sizeof(int[size++]);
//    printf("%zu\n", size);
//    typedef int foo[size++];
//    printf("%zu\n", size);
//}

//void *memset(void *s, int c, size_t n);

//void *memset_vla(size_t n, char s[n], int c); // VLA объявлен параметром функции

/// Вызывая данную функцию, вы сами должны выделить место для массива, на который указывает s, и убедиться в том, что n будет для него допустимым размером.

int matrix_sum(size_t rows, int m[][4]);

int main(void) {
    int m1[5][4];
    int m2[100][4];
    int m3[2][4];
    printf("%d.\n", matrix_sum(5, m1));
    printf("%d.\n", matrix_sum(100, m2));
    printf("%d.\n", matrix_sum(2, m3));
}


//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
