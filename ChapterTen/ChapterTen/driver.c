//
//  driver.c
//  ChapterTen
//
//  Created by Михаил Щербаков on 19.04.2022.
//

#include "driver.h"
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// Выводим справочный текст в командной строке
static void print_help(void) {
    printf("%s", "primetest num1 [num2 num3 ... numN]\n\n");
    printf("%s", "Test postitve integers for primality. Supports testing");
    printf("%s [2-%llu].\n", "numbers in the range", ULLONG_MAX);
}

// Преобразует строковый аргумент arg в значение unsigned long long,
// на которое ссылается val
// Возвращает true, если преобразование аргументов было успешным,
// и false, если нет

static bool convert_arg(const char *arg, unsigned long long *val) {
    
    char *end;
    
    // strtoll возвращает внутренний индикатор ошибки; очистите errno
    // перед вызовом
    errno = 0;
    *val = strtoull(arg, &end, 10);
    
    // Отслеживаем ошибки, когда вызов возвращает контрольное значение
    // и устанавливает errno
    
    if ((*val == ULLONG_MAX) && errno) return false;
    if (*val == 0 && errno) return false;
    if (end == arg) return false;
    
    // Если мы попали сюда, нам удалось преобразовать аргумент.
    // Но мы хотим допускать только
    // значения больше 1, поэтомы мы отбрасываем все значения <= 1
    if (*val <= 1) return  false;
    return true;
}

static unsigned long long *convert_command_line_args(int argc,
                                                     const char *argv[],
                                                     size_t *num_args) {
    *num_args = 0;
    
    if (argc <= 1) {
        // Непредоставление никаких аргументов командной
        // строки (первый аргумент — это имя исполняемой программы)
        print_help();
        return NULL;
    }
    
    unsigned long long *args = (unsigned long long *)malloc(sizeof(unsigned long long) * (argc - 1));
    bool failed_conversion = (args == NULL);
    for (int i; i < argc && !failed_conversion; ++i) {
        unsigned long long one_arg;
        failed_conversion |= !convert_arg(argv[i], &one_arg);
        args[i - 1] = one_arg;
    }
    
    if (failed_conversion) {
        free(args);
        print_help();
        return NULL;
    }
    
    *num_args = argc - 1;
    return args;
}
