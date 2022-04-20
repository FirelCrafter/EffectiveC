//
//  main.c
//  ChapterEight
//
//  Created by Михаил Щербаков on 16.04.2022.
//

#include <stdio.h> // API для работы с потоками
#include <wchar.h> // API для работы с шрокосимвольными потоками

///  Сброс выходного буфера -- программа делает запрос на запись в блочное устройство, такое как диск, драйвер может кэшировать данные в памяти, когда их накопится достаточно для заполнения одного или нескольких блоков, они будут записаны на диск за одну операцию, что улучшит пропускную способность


extern FILE * stdin; // стандартный поток для ввода
extern FILE * stdout; // стандартный поток для вывода
extern FILE * stderr; // стандартный поток для ошибок

/// Стандартный поток вывода (stdout) — то место, куда принято записывать вывод программы. Он обычно связан с терминалом, в котором программа была запущена, но его можно перенаправить в выходной файл или другой поток

// Здесь вывод команды echo перенаправляется в tempfile
//$ echo fred
//fred
//$ echo fred > temfile
//$ cat tempfile
//fred


/// Стандартный поток ввода (stdin) — это общепринятый источник ввода программы. По умолчанию он связан с клавиатурой, но к нему можно перенаправить входной файл

// Содержимое файла fred перенаправляется в stdin команды wc, которая выводит количество символов перевода строки (1), слов (7) и байтов (34) внутри fred.
//$ echo "one two three four five six seven" > fred
//$ wc < fred
//1 7 34

/// Стандартный поток ошибок (stderr) предназначен для записи диагностического вывода. В отличие от stdin и stdout, которые полностью буфeризуются лишь в том случае, если поток не указывает на интерактивное устройство, stderr при первом открытии не является полностью буферизованным, благодаря этому сообщения об ошибках можно просматривать без лишних задержек.

// MARK: Применение байтовых функций ввода/вывода к широкоориентированному потоку или широкосимвольных функций ввода/вывода к байтоориентированному потоку приводит к неопределенному поведению.

/// Функция fopen открывает файл, имя которого передано ей в виде указате- ля на строку filename, и затем соединяет его с потоком. Если такой файл не существует, то fopen его создаст
/// Открытие файла в режиме «для чтения» (путем передачи r в качестве первого символа в аргументе mode) завершается неудачей, если данный файл не существует или его нельзя прочитать. Открытие файла в режиме присоединения (путем передачи a в качестве первого символа в аргументе mode) приводит к тому, что любые данные, которые записываются в файл, добавляются в его конец

FILE *fopen(
            const char * restrict filename,
            const char * restrict mode
            );

// Объект FILE нельзя копировать

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void) {
//    FILE my_stdout = *stdout;
//    if (fputs("Hello World!\n", &my_stdout) == EOF) { // может произойти сбой, поскольку в вызове fputs используется копия содержимого stdout
//        return EXIT_FAILURE;
//    }
//    return EXIT_SUCCESS;
//}

/*
 fgetc   fgetwc  Читает символ из потока
 getc    getwc   Читает символ из потока (функция зачастую является макросом)
 getchar getwchar    Читает символ из stdin
 fgets   fgetws  Читает строчку из потока
 fputc   fputwc  Записывает символ в поток
 putc    putwc   Записывает символ в поток (зачастую является макросом)
 fputs   fputws  Записывает строку в поток
 putchar putwchar    Записывает символ в stdout
 puts    —   Записывает строку в stdout
 ungetc  ungetwc Возвращает символ в поток
 scanf   wscanf  Читает форматированный символьный ввод из stdin
 fscanf  fwscanf Читает форматированный символьный ввод из потока
 sscanf  swscanf Читает форматированный символьный ввод из буфера
 printf  wprintf Записывает форматированный символьный вывод в stdout
 fprintf fwprintf    Записывает форматированный символьный вывод в поток
 sprintf swprintf    Записывает форматированный символьный вывод в буфер
 snprintf    —   То же самое, что sprintf с усечением. Функция swprintf также принимает в качестве аргумента длину, но интерпретирует ее не так, как snprintf
 */

int fputs(const char * restrict s, FILE * restrict stream);

int fclose(FILE *stream); // функция закрытия файла

#include <stdio.h>
#include <stdlib.h>

//int main(void) {
//    FILE *fp = fopen("fred.txt", "r");
//    if (fp == NULL) {
//        fputs("Cannot open fred.txt file\n", stderr);
//        return EXIT_FAILURE;
//    }
//    if (fseek(fp, 0, SEEK_END) != 0) {
//        fputs("Seek to end of file failed\n", stderr);
//        return EXIT_FAILURE;
//    }
//    long int fpi = ftell(fp);
//    if (fpi == -1L) {
//        perror("Tell");
//        return EXIT_FAILURE;
//    }
//    printf("file position = %ld\n", fpi);
//    if (fclose(fp) == EOF) {
//        fputs("Failed to close file\n", stderr);
//        return EXIT_FAILURE;
//    }
//    return EXIT_SUCCESS;
//}

// Использование функций fgetpos и fsetpos

//int main(void) {
//    FILE *fp = fopen("fred.txt", "w+");
//    if (fp == NULL) {
//        fputs("Cannot open fred.txt file\n", stderr);
//        return EXIT_FAILURE;
//    }
//    fpos_t pos;
//    if (fgetpos(fp, &pos) != 0) {
//        perror("get position");
//        return EXIT_FAILURE;
//    }
//    if (fputs("abcdefghijmnopqrstuvwxyz", fp) == EOF) {
//        fputs("Cannot write to fred.txt file\n", stderr);
//    }
//    if (fsetpos(fp, &pos) != 0) {
//        perror("set position");
//        return EXIT_FAILURE;
//    }
//    long int fpi = ftell(fp);
//    if (fpi == -1L) {
//        perror("seek");
//        return EXIT_FAILURE;
//    }
//    printf("file position = %ld\n", fpi);
//    if (fputs("0123456789", fp) == EOF) {
//        fputs("Cannot write to fred.txt file\n", stderr);
//    }
//    if (fclose(fp) == EOF) {
//        fputs("Failed to close file\n", stderr);
//        return EXIT_FAILURE;
//    }
//    return EXIT_SUCCESS;
//}

//MARK: Сигнатура функции fwrite

//size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict sream);

// Запись в двоичный файл с использованием прямого ввода/вывода
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sigrecord {
    int signum;
    char signame[10];
    char sigdesc[100];
} sigrecord;

int main(void) {
    int status = EXIT_SUCCESS;
    FILE *fp;
    sigrecord sigrec;
    
    if ((fp = fopen("signals.txt", "wb")) == NULL) {
        fputs("Cannot open signals.txt file\n", stderr);
        return  EXIT_FAILURE;
    }
    
    sigrecord sigrec30 = {30, "USR1", "user-defined signal 1"};
    sigrecord sigrec31 = {
        .signum = 31, .signame = "USR2", .sigdesc = "user-defined signal 2"
    };
    
    size_t size = sizeof(sigrecord);
    
    if (fwrite(&sigrec30, size, 1, fp) != 1) {
        fputs("Cannot write sigrec30 to signals.txt file\n", stderr);
        status = EXIT_FAILURE;
        goto close_files;
    }
    if (fwrite(&sigrec31, size, 1, fp) != 1) {
        fputs("Cannot write sigrec31 to signals.txt file\n", stderr);
        status = EXIT_FAILURE;
    }
    
close_files:
    if (fclose(fp) == EOF) {
        fputs("Failed ti close file\n", stderr);
        status = EXIT_FAILURE;
    }
    
    return status;
    
}
 */

// Чтение из двичного файла с помощью прямого ввода/вывода

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sigrecord {
    int signum;
    char signame[10];
    char sigdesc[100];
} sigrecord;

int main(void) {
    int status = EXIT_SUCCESS;
    FILE *fp;
    sigrecord sigrec;
    size_t size = sizeof(sigrecord);
    
    if ((fp = fopen("signals.txt", "rb")) == NULL) {
        fputs("Cannot open signals.txt file\n", stderr);
        return EXIT_FAILURE;
    }
    
    if (fseek(fp, size, SEEK_SET) != 0) {
        fputs("fseek in signals.txt file failed\n", stderr);
        return EXIT_FAILURE;
        goto close_files;
    }
    
    if (fread(&sigrec, size, 1, fp) != 1) {
        fputs("Cannot read from signals.txt file\n", stderr);
        return EXIT_FAILURE;
        goto close_files;
    }
    
    printf(
           "Signal\n number = %d\n name = %s\n description = %s\n\n",
           sigrec.signum, sigrec.signame, sigrec.sigdesc
           );
    
close_files:
    fclose(fp);
    return status;
    
}

/// Функция rewind устанавливает текущую позицию файла в его начало
// void rewind(FILE *stream);

/// Функция rewind эквивалентна последовательному вызову fseek и clearerr (для очистки индикатора ошибки потока)
// fseek(stream, OL, SEEK_SET);
// clearerr(stram);

/// Не пытайтесь с помощью функций изменять текущую позицию в файлах, открытых в режиме присоединения, так как многие системы либо не обновляют ее в этом режиме либо принудительно сбрасывают ее в конец файла во время записи.


//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
