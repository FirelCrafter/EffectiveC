//
//  main.c
//  ChapterTen
//
//  Created by Михаил Щербаков on 19.04.2022.
//

#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

//MARK: Непрозрачные типы

/// Неполным называют тип, который описывает идентификатор, но не содержит информацию, необходимую для определения размера или внутреннего устройства объектов этого типа.

//typedef struct collection_type collection_type;
//extern errno_t create_collection(collection_type **result);
//extern void destroy_collection(collection_type *col);
//extern errno_t add_to_collection(collection_type *col, const void *data, size_t byteCount);
//extern errno_t remove_from_collection(collection_type *col, const void *data, size_t byteCount);
//extern errno_t find_in_collection(const collection_type *col, const void *data, size_t byteCount);

// collection_type непрозрачная структура, которая уже определена в collection.h

//MARK: Компоновка

/// Компоновка (линковка) — это процесс, который определяет, является интерфейс публичным или приватным и ссылаются ли какие-либо два идентификатора на одну и ту же сущность.


static int i; // i объявляется с явной внутренней компоновкой
extern void foo(int j) {
    // foo объявляется с явной внешней компоновкой
    // у j нет компоновки, так как это параметр
}


/// Ключевое слово static назначает внутреннюю компоновку только сущностям в области видимости файла. Применение его к переменной на уровне блока породит идентификатор без компоновки, зато этой переменной будет назначен статический срок хранения.
/// Можно создать идентификатор с внешней компоновкой, объявив его с помощью спецификатора класса хранения extern. Но это работает, только если не объявлялась компоновка для данного идентификатора. Ключевое слово extern не оказывает на идентификатор никакого влияния, если ему уже была назначена какая-то компоновка.

//MARK: Программа, определеляющая, является ли число простым


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

// Алгоритм Миллера — Рабина для проверки простоты чисел

static unsigned long long power(unsigned long long x, unsigned long long y,
                                unsigned long long p) {
    unsigned long long result = 1;
    x %= p;
    
    while (y) {
        if (y & 1) result = (result * x) % p;
        y >>= 1;
        x =(x * x) % p;
    }
    return result;
}

static bool miller_rabin_test(unsigned long long d, unsigned long long n) {
    unsigned long long a = 2 + rand() % (n - 4);
    unsigned long long x = power(a, d, n);
    
    if (x == 1 || x == n - 1) return true;
    
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}

// Интерфейс к алгоритму Миллера — Рабина для проверки простоты чисел

bool is_prime(unsigned long long n, unsigned int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;
    
    unsigned long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }
    
    for (; k != 0; --k) {
        if (!miller_rabin_test(d, n)) return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    size_t num_args;
    unsigned long long *vals = convert_command_line_args(argc, argv, &num_args);
    
    if (!vals) return EXIT_FAILURE;
    
    for (size_t i = 0; i < num_args; ++i) {
        printf("%llu is %s.\n", vals[i],
               is_prime(vals[i], 100) ? "probably prime" : "not prime");
    }
    free(vals);
    return EXIT_SUCCESS;
}


//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
