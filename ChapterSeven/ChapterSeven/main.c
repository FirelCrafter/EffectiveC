//
//  main.c
//  ChapterSeven
//
//  Created by Михаил Щербаков on 15.04.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>


/// Тип char следует использовать для символов (в этом случае наличие или отсутствие знака не имеет значения), но не для целочисленных данных (где знак играет важную роль). Данный тип позволяет безопасно представлять семибитные кодировки, такие как US-ASCII. В подобных кодировках старший бит всегда равен 0, поэтому вам не нужно беспокоиться о расширении знака, когда значение типа char приводится к int и в текущей реализации имеет знак.
/// Тип char также можно использовать для представления восьмибитных кодировок наподобие Extended ASCII, ISO/IEC 8859, EBCDIC и UTF-8, но в реализациях, в которых char является восьмибитным типом со знаком, это чревато проблемами. Например, следующий код выводит строку end of file при обнаружении конца файла:

//char c = 'ÿ'; // extended char
//if (c == EOF) puts("end of file");

/// Если в качестве исполняемой кодировки используется ISO/IEC 8859-1, то маленькая буква латинского алфавита y с диерезисом (ÿ) будет иметь код 255 (0xFF). В реализациях, в которых char имеет знак, буква c будет расширена до signed int, что сделает символ ÿ неотличимым от индикатора конца файла, так как они оба будут иметь одно и то же представление.

// Приведение С к unsigned char с повышением разрядности для безопасной isdigit

//char c = 'ÿ';
//if (isdigit((unsigned char)c)) {
//    puts("c is a digit");
//}

//#if __STDC_UTF_16__ != 1
//#error "__STDC_UTF_16__ not defined"
//#endif
//
//int main(void) {
//    setlocale(LC_ALL, "en_US.utf8");
//    char input[] = u8"I ♥ s!";
//    const size_t input_size = sizeof(input);
//    char output[input_size];
//
//    char *p_input = input;
//    char *p_end = input + input_size;
//    size_t code;
//    mbstate_t state = {0};
//    puts(input);
//    while ((code = mbrtoc16(output, p_input, p_end-p_input, &state))) {
//        if (code == (size_t)-1)
//                 break; // -1 – обнаружена некорректная последовательность
//                        // единиц кодирования
//               else if (code == (size_t)-2)
//                 break; // -2 – пропущенные элементы в последовательности
//                        // единиц кодирования
//               else if (code == (size_t)-3)
//                   output; // -3 – верхняя часть суррогатной пары
//               else {
//                   output;
//                   p_input += code;
//               }
//    }
//    size_t output_size = output - output + 1;
//    printf("Converted to %zu UTF-16 code units: [ ", output_size);
//    for(size_t x = 0; x < output_size; ++x) printf("%#x ", output[x]);
//    puts("]");
//}

//char str[100] = "Here comes the sun";
//size_t str_size = sizeof(str); // размер строки (100)
//size_t str_len = strlen(str); // длина строки (18)


// Динамическое выделение памяти для узкосимвольных и широкосимвольных функций

//int main(int argc, const char * argv[]) {
//    char str1[] = "Here comes the sun";
//    char *str2 = malloc(strlen(str1) + 1);
//    wchar_t wstr1[] = L"Here comes the sun";
//    wchar_t *wstr2 = malloc((wcslen(str1) + 1) * sizeof(wchar_t));
//    return 0;
//}

int main(int argc, const char * argv[]) {
    char str[100] = "Here comes the sun";
    size_t str_size = strlen(str) + 1;
    char *dest = (char *)malloc(str_size);
    if (dest) {
        strcpy(dest, str);
    } else {
        // error
    }
    return 0;
}


//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
