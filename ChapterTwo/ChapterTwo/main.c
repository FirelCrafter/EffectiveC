//
//  main.c
//  ChapterTwo
//
//  Created by Михаил Щербаков on 06.04.2022.
//

#include <stdio.h>

//void swap(int, int); // Объявление переменной

/// Можно объявлять несколько переменных сразу, но это делает код запутанным
/// если они имеют разане типы или явзяются указателями или массивами
///
/// Эти объевления технически будут корректыми":
/// char *src, c;  <-- две переменные имют тип char
/// int x, y[5]
/// int m[12], n[15][3], o[21];
///
/// Но легче понять их так:
///char *src;
///char c;
///int x;
///int y[5];  <-- массив из 5 элементов
///int m[12];
///int n[15][3];  <-- массив из 15 массивов из 3 элементов
///int o[21];

//MARK: функция которая меняет местами числа

/*
void swap(int *pa, int *pb) {
    int t = *pa;
    *pa = *pb;
    *pb = t;
    return;
}

int main(void) {
    int a = 21;
    int b = 17;
    
    swap(&a, &b);
    printf("main: a %d, b = %d\n", a, b);
    return 0;
}

*/




/*
 //MARK: Области видимости
 ///
 int j; // начинается область видимости уровня файла j
 void f(int i) { int j = 1;
 // начинается блочная область видимости i
 // начинается блочная область видимости j
 // перекрывает j в области видимости уровня файла // i ссылается на параметр функции
 i++;
 for (int i = 0; i < 2; i++) { // начинается блочная область видимости i внутри цикла
 int j = 2; // начинается блочная область видимости j перекрывает внешнюю j
 printf("%d\n", j); // внутренняя j в области видимости, выводит 2
 }
 printf("%d\n", j); }
 void g(int j);  //заканчивается блочная область видимости внутренних i и j
 // внешняя j в области видимости, выводит 1
 // заканчивается блочная область видимости i и j
 // j имеет область видимости уровня прототипа перекрывает j уровня файла
 /// Лучше использовать хороший нейминг, особенно когда области видимости большие
 */


//MARK: Счетчик

//void increment(void) {
//    static unsigned int counter = 0;
//    counter++;
//    printf("%d", counter);
//}
//
///*
// /// Статические объекты должны инициализироваться с помощью констант- ного значения, а не переменной
//
// int *func(int i) {
//   const int j = i;  // правильно
//   static int k = j; // ошибка
//   return &k;
// }
// */
//
//int main(void) {
//    for (int i = 0; i < 5; i++) {
//        increment();
//    }
//    return 0;
//}



//MARK: Выравнивание

///Типы объектов имеют требования к выравниванию, ограничивающие адреса, которые могут выделяться для объектов этих типов. Выравнивание (alignment) определяет количество байтов между смежными адресами, в которых может быть сохранен заданный объект.


// Использование ключевого слова _Alignas

/*
 struct S {
     int i; double d; char c;
 };

 int main(void) {
     unsigned char bad_buff[sizeof(struct S)];
     _Alignas(struct S) unsigned char good_buff[sizeof(struct S)];
     
     struct S *bad_s_ptr = (struct S *)bad_buff;
     //неправильное выравнивание указателя
     struct S *good_s_ptr = (struct S *)good_buff;
     // правильное выравниевание указателя
 }
 */

//MARK: ОБъектные типы

// Логические типы
/*
 #include <stbool.h>
 _Bool flag1 = 0;
 bool flag2 = false;
 */

/// Символьные типы
///Язык C определяет три символьных типа: char, signed char и unsigned char. В любой реализации компилятора char имеет те же выравнивание, размер, диапазон, представление и поведение, что и signed char или unsigned char. Тем не менее char — отдельный тип, несовместимый с двумя другими.

/// Численные типы
///Целочисленные типы со знаком можно использовать для представления отрицательных, положительных и нулевых значений. В их число входят signed char, short int, int, long int и long long int.
///Для каждого целочисленного типа со знаком предусмотрен соответствующий беззнаковый целочисленный тип, который занимает столько же места: unsigned char, unsigned short int, unsigned int, unsigned long int и unsigned long long int.

/// Для определения размеров целочисленных типов используем
//#include <limits.h>
//#include <stdint.h>
//#include <inttypes.h>


// Перечисляемые типы
/// позволяет определить тип, который назначает имена (перечислители) целочисленным значениям в ситуациях, когда требуется перечисляемый набор постоянных значений.

/*
 enum day {
     sun, mon, tue, wed, thu, fri, sat
 };
 enum cardinal_points {
     north = 0, east = 90, south = 180, west = 270
 };
 enum months {
     jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
 };

 */

// Типы с плавающей запятой
/// Язык C поддерживает три типа с плавающей запятой: float, double и long double.

// Void
/// Тип void довольно необычен. Ключевое слово void означает «не может содержать никаких значений». Например, с его помощью можно сигнализировать о том, что ваша функция не возвращает значение или не принимает аргументов. С другой стороны, производный тип void * означает, что указатель может ссылаться на любой объект.


//MARK: Функциональные типы

/// Функциональные типы являются производными. В данном случае они основаны на типе возвращаемого значения, а также на количестве и типах параметров функции. Тип возвращаемого значения не может быть массивом.

/*
 int f(void); // функция f без параметров, которая возвращает int
 int *fip(void); // fip без списка параметров, возвращает указатель на int
 void g(int i, int j); // возвращает void и принимает по два параметра типа int
 void h(int, int); // возвращает void и принимает по два параметра типа int (не рекомендуется опускать идентификаторы)
 */

/// Прототип - сочетание типа функции и списка с типами ее параметров
//int max(int a, int b) { return a > b ? a : b; }


//MARK: Производные типы

/// Производными называют типы, основанные на других типах. В их число входят указатели, массивы, определения типов, структуры и объединения.

/// Указатель - предоставляет ссылку на объект (сущность)
/*
 int *ip
 char *cp
 void *vp
 */

/// Операция & позволяет получить адрес объекта или функции

/*
 int i = 17;
 int *ip = &i; // вернет указатель типа int
 ip = &*ip; // вернет сам объект
 */

/// Массивы

/*
 void func(int arr[5]);
 int main(void) {
     unsigned int i = 0;
     unsigned int j = 0;
     int arr[3][5]; // двумерный массив (матрица)
     func(arr[i]);
     int x = arr[i][j];
     return 0;
 }
 */


/// Ключевое слово typedef используется для создания псевдонима существующего типа; оно никогда не создает новый тип.


/*
 typedef unsigned int uint_type;
 typedef signed char schar_type, *schar_p, (*fp)(void);
 */


/// Структуры
/// содержат последовательно выделенные объекты-члены


/*
 struct sigrecord {
     int signum;
     char signame[20];
     char sigdesc[100];
 } sigline, *sigline_p;

 sigline.signum = 5;
 strcpy(sigline.signame, "SIGINT");
 strcpy(sigline,sigdesc, "Interrupt from keyboard");

 sigline_p = &sigline;

 sigline_p->signum = 5;
 strcpy(sigline_p->signame, "SIGINT");
 strcpy(sigline_p->sigdesc, "Interrupt from keyboard");
 */


/// Объединения
/// Объединения похожи на структуры, только их члены используют одну и ту же память.

/*
 union {
     struct {
         int type;
     } n;
     struct {
         int type;
         int intnode;
     } ni;
     struct {
         int type;
         double doublenode;
     } nf;
 } u;

 u.nf.type = 1;
 u.nf.doublenode = 3.14;
 */

/// Теги
/// Теги — это специальный механизм именования структур, объединений и перечислений

/*
 struct s { // s - тег
     // blabla
 };

 struct s v;  // экземпляр структуры s
 struct s *p; // указатель на структуру s
 */

/*
 enum day { sun, mon, tue, wed, thu, fri, sat };
 day today;         // ошибка, теги - не типы, их недостаточно для объявления переменной
 enum day tomorrow; // правильно
 */


/// Теги структур можно считать именами типов и определять для них псевдонимы с помощью typedef.

//typedef struct s {int x;} t;

/// Это будет работать всегда, кроме тех случаев, когда структура содержит указатель на саму себя

/*
 typedef struct tnode tnode;
 struct tnode {
     int count;
     struct tnode *left;
     struct tnode *right;
 };
 */

/// Определения типов могут сделать код более понятным не только в случае их использования со структурами

typedef void fv(int), (*pfv)(int);
void (*signal(int, void (*)(int)))(int);
fv *signal(int, fv *);
pfv signal(int, pfv);


// MARK: Квалификаторы типов

/// Тип можно сделать квалифицированным за счет использования одного или нескольких квалификаторов, таких как const, volatile и restrict.

/// Квалифицированная и неквалифицированная версии типа являются взаи- мозаменяемыми в случае использования в качестве аргументов функций, возвращаемых значений и членов объединений.

/*
 const int i = 1;
 i = 2; // не подлежит изменению
 int *ip = (int *)&i;
 *ip = 2;  // неопределенное поведение
 */


/*
 int i = 12;
 const int j = 12;
 const int *ip = &i;
 const int *jp = &j;
 *(int *)ip = 42; // правильно
 *(int *)jp = 42; // неопределенное поведение
 */

/// Использование volatile-квалифицированного типа сообщает компилятору о том, что значение может измениться, и гарантирует, что код будет каждый раз обращаться к часам реального времени (в про- тивном случае эти обращения могут быть удалены в ходе оптимизации или заменены уже считанным и закэшированным значением).

/*
 volatile int port;
 port = port;
 */

void f(unsigned int n, int * restrict p, int * restrict q) {
    while (n-- > 0) {
        *p++ = *q++;
    }
}

/// Поскольку p и q являются restrict-квалифицированными указателями, компилятор может исходить из того, что обращение к объекту через один из этих параметров не приведет к обращению через другой. Это предполо- жение основано исключительно на объявлениях параметров и не требует анализа тела функции. Использование указателей с квалификатором restrict делает код более эффективным, но, чтобы избежать неопределен- ного поведения, программист обязан обеспечить, чтобы участки памяти, на которые они ссылаются, не пересекались.