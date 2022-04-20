//
//  main.c
//  ChapterFive
//
//  Created by Михаил Щербаков on 11.04.2022.
//

#include <stdio.h>

/// Оператор-выражение — произвольное выражение, которое заканчивается точкой с запятой.
//int main(int argc, const char * argv[]) {
//    a = 6;
//    b = 7;
//    c = a + b;
//    ; // нулевое выражение
//    return 0;
//}

/// Составной оператор (или блок) — это список из любого количества опера- торов (начиная с нуля), заключенных в фигурные скобки.

//int main(int argc, const char * argv[]) {
//    {
//        static int count = 0;
//        int a = 6;
//        int c = 4;
//        c += a;
//        ++count;
//    }
//    return 0;
//}

///Оператор if позволяет программистам выполнять другие операторы в зависимости от значения управляющего выражения скалярного типа.

//int main(int argc, const char * argv[]) {
//    bool safediv(int divident, int divisor, int *quotient) {
//        if (!quotient) return false;
//        if ((divisor == 0) || (divided == INT_MIN) && (divisor == -1))
//            return false;
//        quotient = dividend / divisor;
//        return  true;
//    }
//    return 0;
//}

//void printgrade(unsigned int marks) {
//    if (marks >= 90) {
//        puts("YOUR GRADE: A");
//    } else if (marks >= 80) {
//        puts("YOUR GRADE: B");
//    } else if (marks >= 70) {
//        puts("YOUR GRADE: C");
//    } else {
//        puts("YOUR GRADE: Failed");
//    }
//}

/// Из всех операторов, которые идут за if, выполняется лишь один.

//if (condition)
//  conditionally_executed_function();
//unconditionally_executed_function(); // всегда выполняется

//if (condition)
//  conditionally_executed_function();
//  second_conditionally_executed_function(); // ???
//unconditionally_executed_function(); // всегда выполняется

//if (condition) {
//  conditionally_executed_function();
//  second_conditionally_executed_function(); // исправлено
//}
//unconditionally_executed_function(); // всегда выполняется


/// Оператор switch работает точно так же, как лесенка if...else, только управляющее выражение должно иметь целочисленный тип.

//switch (marks/10) {
//  case 10:
//  case 9:
//    puts("YOUR GRADE : A");
//    break;
//  case 8:
//    puts("YOUR GRADE : B");
//    break;
//  case 7:
//    puts("YOUR GRADE : C");
//    break;
//  default:
//    puts("YOUR GRADE : Failed");
//}

/// при объявлении нового компонента в typedef нужно всегда менять switch в функции assignInterestRate. Иначе, interest_rate не присваивается и, когда функция пытается вывести данное значение, происходит чтение неинициализированного участка памяти, можно уберечься от подобных ошибок, добавив в оператор switch метку default.
typedef enum { Savings, Checking, MoneyMarket } AccountType;
void assignInterestRate(AccountType account) {
    double interest_rate;
    switch (account) {
        case Savings:
            interest_rate = 3.0;
            break;
        case Checking:
            interest_rate = 1.0;
            break;
        case MoneyMarket:
            interest_rate = 4.5;
            break;
    }
    printf("Interest rate = %g.\n", interest_rate);
    
    
}

//MARK: Операторы итерирования
///Операторы итерирования позволяют выполнять вложенные (или со- ставные) операторы любое количество раз (начиная с нуля) с учетом критериев завершения. Слово «итерация» происходит от лат. iteratio — «повторение». Вместо «операторов итерирования» обычно используется менее формальный термин — «циклы». Цикл — это «процесс, окончание которого перетекает в его начало».

/// Оператор while делает так, что тело цикла выполняется до тех пор, пока управляющее выражение не станет равным 0.

//void f(unsigned int x) {
//    while (x > 0) {
//        printf("%d\n", x);
//        --x;
//    }
//    return;
//}
//
//void *memset(void *dest, int val, size_t n) {
//    unsigned char *ptr = (unsigned char*)dest;
//    while (n-- > 0)
//        *ptr++ = (unsigned char)val;
//    return dest;
//}

/// Можно написать бесконечный цикл, который никогда не заканчивается. Чтобы не сделать этого по случайности, перед началом цикла while обязательно инициализируйте все объекты, фигурирующие в управляющем выражении. Кроме того, убедитесь, что управляющее выражение будет меняться так, что цикл завершится после выполнения нужного вам количества итераций.

/// Оператор do...while похож на while, только вычисление управляющего выражения происходит после каждого выполнения тела цикла, а не перед.

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int count; float quant; char units[21], item[21];
    do {
        count = fscanf(stdin, "%f%20s of %20s", &quant, units, item);
        fscanf(stdin, "$*[^\n]");
    } while (!feof(stdin) && !ferror(stdin));
    return 0;
}

/// Оператор for, вероятно, самая характерная черта языка C. Он позволяет многократно выполнять какую-то операцию и обычно используется в слу- чаях, когда количество итераций известно еще до входа в цикл.

void *memset(void *dest, int val, size_t n) {
    unsigned char *ptr = (unsigned char *)dest;
    for (size_t i = 0; i < n; ++i) {
        *(ptr + i) = val;
    }
    return dest;
}


/// Оператор goto инициирует переход к оператору, перед которым указана заданная метка (в рамках одной и той же функции).

///* выполняемые операторы */ goto метка;
///* пропущенные операторы */
//метка:
///* выполняемые операторы */

/// Операторы goto могут принести пользу,если объединить их в цепочку для освобождения выделенных ресурсов (таких как динамически выделяемая память или открытый файл) в ситуации, когда произошла ошибка и вы должны покинуть функцию. Это происходит в связи с тем, что любое выделение ресурсов может завершиться неудачно, и во избежание утечки необходимо освободить то, что уже было выделено. Если не удается выделить первый ресурс, то такая очистка не требуется, поскольку нам не- чего освобождать. Но если это произойдет со вторым ресурсом, то первый нужно освободить. Аналогично если проваливается выделение третьего ресурса, то освобождения требуют второй и первый и т. д. Эти действия приводят к дублированию и усложнению кода, предназначенного для очистки, что может быть чревато ошибками.

//int do_something(void) {
//    FILE *file1, *file2;
//    object_t *obj;
//    int ret_val = 0;
//
//    file1 = fopen("a_file", "w");
//    if (file1 == NULL) {
//        ret_val = -1;
//        goto FAIL_FILE1;
//    }
//    file2 = fopen("another_fil", "w");
//    if (file2 == NULL) {
//        ret_val = -1;
//        goto FAIL_FILE2;
//    }
//    obj = malloc(sizeof(object_t));
//    if (obj == NULL) {
//        ret_val = -1;
//        goto FAIL_OBJ;
//    }
//
//    free(obj);
//FAIL_OBJ:
//    fclose(file2)
//FAIL_FILE2:
//    fclose(file1)
//FAIL_FILE1:
//    return ret_val;
//}

/// Этот код имеет простой принцип работы: ресурсы выделяются по очереди, задействуются и затем освобождаются в обратном порядке («последним пришел — первым ушел»). Если во время выделения произойдет ошибка, то программа использует goto для перехода на подходящий участок кода и освобождает только те ресурсы, которые были выделены.

/// Чтобы перейти в конец тела цикла и пропустить выполнение любого кода, который остается в текущей итерации, можно использовать оператор continue.


/// Оператор break прерывает выполнение switch или оператора итерирования.

//#include <stdio.h>
//in main(void) {
//    char c;
//    for(:;) {
//        puts("Press Q to quit");
//        c = toupper(getchar());
//        if (c == 'Q') break;
//    }
//}

/// Оператор return прерывает выполнение текущей функции и возвращает управление тому коду, который ее вызвал.

int sum(int x, int y, int z) {
    return x+y+z;
}

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
