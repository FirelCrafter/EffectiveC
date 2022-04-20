//
//  main.c
//  ChapterFour
//
//  Created by Михаил Щербаков on 08.04.2022.
//

#include <stdio.h>

//MARK: Выражения и операции

/// Выражение — это последовательность операций и операндов, которая вычисляет значение или выполняет какую-то другую задачу.


/*
 int i;
 i = 21; // присваивание
 */


/// Передача одной функции в другугую

/*
 int f(void) {
     return 0;
 }
 void g(int (*func)(void)) {
     if (func() != 0)
         printf("g filed\n");
 }
 g(f); // вызываем g с аргументом в виде указателя на функцию
 */

/// Инкрементные и декрементные операции

/*
 int i = 5;
 int e; // результат выражения
 e = i++; // постфиксный инкремент: i имеет значение 6; e имеет значение 5
 e = i--; // постфиксный декремент: i имеет значение 5; e имеет значение 6
 e = ++i; // префиксный инкремент: i имеет значение 6; e имеет значение 6
 e = --i; // префиксный декремент: i имеет значение 5; e имеет значение 5

 */

/// Порядок выполнения операций

/*
 char abc[] = "abc";
 char xyz[] = "xyz";
 char *p = abc;
 printf("%c", ++*p);
 p = xyz;
 printf("%c", *p++);
 */

/// Порядок вычисления аргументов функции

/*
 int glob;
 int f(void) {
     return glob + 10;
 }
 int g(void) {
     glob = 42
     return glob;
 }
 int main(void) {
     int f_val = f(); // гарантия выполнения порядка
     int g_val = g();
     int max_value = max(f_val, g_val);
 }
 */

/// Точка следования—момент завершения всех побочных эффектов. Эти точки косвенно определяются языком, но можно изменять их местоположение, по-разному описывая логику своей программы.

/*
 int main(int argc, const char * argv[]) {
     int i = 5;
     printf("Result = %d\n", i++ * i++); //Неопределенное поведение
     return 0;
 }
 */

/*
 int main(int argc, const char * argv[]) {
     int i = 5;
     int j = i++; // Таким образом мы просчитываем значения отдельных переменных
     int l = i++; // определяя порядок вычислений самостоятельно (точка следования)
     printf("Result = %d\n", j * l);
     return 0;
 }
 */

//MARK: Операция sizof

/*
 #include <stddef.h>
 bool is_odd(int n) {
 //    return n % 2 == 1;
     return n % 2 != 0;
 }

 int main(int argc, const char * argv[]) {
     int i;
     size_t i_size = sizeof(i);
     size_t int_size = sizeof(int);
     return 0;
 }
 */

//MARK: Операции сдвига

/// Операции сдвига перемещают значение каждого бита операнда цело- численного типа на указанное количество позиций. Эти операции часто используются в системном программировании, где повсеместно приме- няются битовые маски. Операции также могут пригодиться для упаковки и распаковки данных в коде, который работает с сетевыми протоколами или файловыми форматами.


// Операции сдвига вправо
/*
 #include <stddef.h>
 #include <limits.h>
 int main(int argc, const char * argv[]) {
     extern int si1, si2, sresult;
     extern unsigned int ui1, ui2, uresult;
     if ((si2 < 0) || (si2 >= sizeof(int)*CHAR_BIT)) {
         
     } else {
         sresult = si1 >> si2;
     }
     if (ui2 >= sizeof(unsigned int)*CHAR_BIT) {
         
     } else {
         uresult = ui1 >> ui2;
     }
     return 0;
 }
 */

/// Если целое значение имеет знак, то вы должны убедиться в том, что количество сдвигаемых битов не является отрицательным, больше ширины расширенного левого операнда или равным ей. В случае с беззнаковыми целочисленными типами проверку на отрицательные значения можно пропустить, поскольку такие типы не могут быть отрицательными. Похожим образом можно проводить и операции сдвига влево
///

// Использование функции pow
/*
 #include <math.h>
 #include <stdio.h>

 int main(void) {
     int i = 128;
     if (i == pow(2, 7)) {
         puts("equal");
     }
 }
 */

//MARK: Операция _Alingof

/// Операция _Alignof возвращает целочисленную константу, представля- ющую требования к выравниванию объявленного полного объектного типа его операнда.

#include <stdio.h>
#include <stddef.h>
#include <stdalign.h>
#include <assert.h>

int main(void) {
    int arr[4];
    static_assert(_Alignof(arr) == 4, "unexpected alignment"); //статическое утрверждение
    assert(alignof(max_align_t) == 16); // динамическое утверждение
    printf("Alignment of arr = $zu\n", _Alignof(arr));
    printf("Alignment of max_align_t = $zu\n", alignof(max_align_t));
    
}


/*
 int main(int argc, const char * argv[]) {
     // insert code here...
     printf("Hello, World!\n");
     return 0;
 }
 */
