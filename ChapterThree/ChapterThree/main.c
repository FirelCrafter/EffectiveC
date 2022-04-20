//
//  main.c
//  ChapterThree
//
//  Created by Михаил Щербаков on 07.04.2022.
//

#include <stdio.h>

/*
 extern unsigned int ui, sum;
 if (ui > UINT_MAX - sum)
     // too_big()
 else
 sum = sum + ui;
 */


//MARK: Переполнение целочисленных значений

/// Переполнение происходит, когда операция со знаковым целым возвращает значение, которое не может быть представлено итоговым типом.

/*
 #define AbsM(i, flag) ((i) >= 0 ? (i) : ((i) == (flag) ? (flag) : -(i)))
 signed int si = -25; // try INT_MIN to provocate isssue
 signed int abs_si = AbsM(si, INT_MIN);
 if abs_si == INT_MIN {
     goto recover;  // особый случай
 } else {
     printf("%d\n", abs_si);  // выводит 25
 }
 */

int abs(int i) {
  return (i >= 0) ? i : -(unsigned)i; // избегает переполнения
}

int burger = 0xDEADBEEF; // шестнадцатеричная константа

/// Унарная операция вычитания (-) определена и для беззнаковых целочисленных типов. Результат приводится по модулю к числу, на единицу превышающему самое большое значение, которое может быть представлено итоговым типом.


//MARK: Числа с плавающей точкой

/// Язык C поддерживает три типа с плавающей запятой: float, double и long double.

/// Float не является абсолютно точным чиловым типом. Согласно распространенной спецификации IEC 60559 при кодировании типа float один разряд выделяется для знака, восемь — для порядка и еще 23 — для мантиссы (ISO/IEC/IEEE 60559:2011) (32 бита).

/// Тип double имеет более высокую точность, но занимает дополнительное место. При его кодировании один разряд отводится для знака, 11 — для порядка и еще 52 — для мантиссы (64 бита).

/// Типы с плавающей запятой также могут представлять значения, которые не являются числами с плавающей запятой, — такие как положительная и отрицательная бесконечность и NaN (not-a-number, не число). NaN — это значения, которые не соответствуют настоящим числам.


/// макрос fpclassify используется в функции show_classi- fication для определения того, что собой представляет значение с плава- ющей запятой типа double: нормализованное число, ненормализованное число, ноль, бесконечность или NaN.

#include <math.h>

const char *show_classification(double x) {
    switch (fpclassify(x)) {
        case FP_INFINITE:
            return "Inf";
        case FP_NAN:
            return "NaN";
        case FP_NORMAL:
            return "normal";
        case FP_SUBNORMAL:
            return "subnormal";
        case FP_ZERO:
            return "zero";
        default:
            return "unknown";
    }
}

/// Операция приведения типоа используется в случае если есть объект типа float и вы хотите передать его в качестве аргумента функции, которая принимает только объекты типа int

/*
 int si = 5;
 short ss = 8;
 long sl = (long)si; // приведение к типу long
 unsigned short us = (unsigned short)(ss + sl); // приведение к типу unsigned short

 */

/// При приведении к типу с меньшей точностью результат преобразования может не совпасть с исходным значением

//MARK: Безопасное приведение типов

/*
 #include <errno.h>
 #include <limits.h>

 errno_t do_staff(signed long value) {
     if ((value < SCHAR_MIN) || (value > SCHAR_MAX)) {
         return ERANGE;
     }
     signed char sc = (signed char)value; // приведение типов глушит предупреждения
     return sc; //placeholder
 }
 */

/// правило INT31-C из стандарта программирования CERT C





int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
