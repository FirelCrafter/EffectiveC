//
//  main.c
//  ChapterNine
//
//  Created by Михаил Щербаков on 18.04.2022.
//

#include <stdio.h>

//MARK: Работа условного предиката

#if defined(_WIN32) // сокращается до #ifdef
#include <Windows.h>
#elif defined(__ANDROID__) // нельзя сокращать
#include <android/log.h>
#endif


//MARK: Генерация ошибки компиляции

#if __STDC__ && __STDC_NO_THREADS__ != 1
#include <threads.h>
#elif POSIX_THREADS == 200809L
#include <pthread.h>
#else
#error Neither <threads.h> nor <pthread.h> is available
#endif

//MARK: Определение макросов

#define ARRAY_SIZE 100
int array[ARRAY_SIZE];


// Многострочные макросы

#define cbrt(x) _Generic((X), \
long double: cbrtl(X), \
default: cbrt(X), \
float: cbrtf(X) \
)



//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
