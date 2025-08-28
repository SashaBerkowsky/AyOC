#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// 1
void hello_world() {
    printf("Hello, world!\n");
}

// 3
void check_size() {
    char c = 100;
    short s = -8712;
    int i = 123456;
    long l = 1234567890;

    unsigned char uc = -100;
    unsigned short us = -7892;
    unsigned int ui = -12398;
    unsigned long ul = -123812485;

    char* pc = &c;
    int* pi = &i;
    void* pv = &l;

    printf("--- signed ---\n");
    printf("char(%lu): %d \n", sizeof(c), c);
    printf("short(%lu): %d \n", sizeof(s), s);
    printf("int(%lu): %d \n", sizeof(i), i);
    printf("long(%lu): %ld \n", sizeof(l), l);

    printf("\n--- unsigned ---\n");
    printf("char(%lu): %u \n", sizeof(uc), uc);
    printf("short(%lu): %u \n", sizeof(us), us);
    printf("int(%lu): %u \n", sizeof(ui), ui);
    printf("long(%lu): %lu \n", sizeof(ul), ul);

    printf("\n--- pointers ---\n");
    printf("char(%lu): %p \n", sizeof(pc), pc);
    printf("int(%lu): %p \n", sizeof(pi), pi);
    printf("void(%lu): %p \n", sizeof(pv), pv);
}

//4
void check_fix_size() {
    int8_t i8 = 127;
    int16_t i16 = 32767;
    int32_t i32 = 2147483647;
    int64_t i64 = 999999999999999999;

    uint32_t ui8 = -256;
    uint32_t ui16 = -65536;
    uint32_t ui32 = 4294967295;
    uint64_t ui64 = 999999999999999999;
    
    int8_t* pi8 = &i8;
    int16_t* pi16 = &i16;
    int32_t* pi32 = &i32;
    int64_t* pi64 = &i64;

    printf("--- signed ---\n");
    printf("8bit(%lu): %d \n", sizeof(i8), i8);
    printf("16bit(%lu): %d \n", sizeof(i16), i16);
    printf("32bit(%lu): %d \n", sizeof(i32), i32);
    printf("64bit(%lu): %ld \n", sizeof(i64), i64);

    printf("\n--- unsigned ---\n");
    printf("8bit(%lu): %u \n", sizeof(ui8), ui8);
    printf("16bit(%lu): %u \n", sizeof(ui16), ui16);
    printf("32bit(%lu): %u \n", sizeof(ui32), ui32);
    printf("64bit(%lu): %lu \n", sizeof(ui64), ui64);

    printf("\n--- pointers ---\n");
    printf("8bit(%lu): %p \n", sizeof(pi8), pi8);
    printf("16bit(%lu): %p \n", sizeof(pi16), pi16);
    printf("32bit(%lu): %p \n", sizeof(pi32), pi32);
    printf("64bit(%lu): %p \n", sizeof(pi64), pi64);
}

// 5
void casting() {
    float f = 0.1;
    double d = (double) f;
    int cf = (int) f;
    int cd = (int) d;

    printf("float(%lu): %.10f\n", sizeof(f), f);
    printf("double(%lu): %.20f\n", sizeof(d), d);
    printf("float to int(%lu): %d\n", sizeof(cf), cf);
    printf("double to int(%lu): %d\n", sizeof(cd), cf);
}

// 6
void mensaje_secreto() {
    int mensaje_secreto[] = { 116, 104, 101, 32, 103, 105, 102, 116, 32, 111,
        102, 32, 119, 111, 114, 100, 115, 32, 105, 115, 32, 116, 104, 101, 32,
        103, 105, 102, 116, 32, 111, 102, 32, 100, 101, 99, 101, 112, 116, 105,
        111, 110, 32, 97, 110, 100, 32, 105, 108, 108, 117, 115, 105, 111, 110
    };

    size_t length = sizeof(mensaje_secreto) / sizeof(int);
    char decoded[length];

    for (int i = 0; i < length; i++) {
        decoded[i] = (char) (mensaje_secreto[i]);
    }

    for (int i = 0; i < length; i++) {
        printf("%c", decoded[i]);
    }
    printf("\n");
}

// 7
void operadores() {
    int a = 5, b = 3, c = 2, d = 1;

    printf("a + b * c / d: %d\n", a + b * c / d);
    printf("a mod b: %d\n", a % b);
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a | b: %d\n", a | b);
    printf("a & b: %d\n", a & b);
    printf("~a: %d\n", ~a);
    printf("a || b: %d\n", a || b);
    printf("a && b: %d\n", a && b);
    printf("a << 1: %d\n", a << 1);
    printf("a >> 1: %d\n", a >> 1);
    printf("a += b: %d\n", a += b);
    printf("a -= b: %d\n", a -= b);
    printf("a *= b: %d\n", a *= b);
    printf("a /= b: %d\n", a /= b);
    printf("a mod= b: %d\n", a %= b);
}

// 8
void diferencia_contadores() {
    const int LIMITE = 5;
    int i = 0;

    printf("--- mostrar pares usando i++ ---\n");
    while (i < LIMITE) {
        if (i % 2 == 0) {
            printf("numero: %d\n", i++);
        } else {
            i++;
        }
    }
    
    i = 0;

    printf("\n--- muestra pares usando ++i? ---\n");
    while (i < LIMITE) {
        if (i % 2 == 0) {
            printf("numero: %d\n", ++i);
        } else {
            i++;
        }
    }
}

// 9
void tres_bit_cmp(int a, int b) {
    int mask = 0b0111;
    int son_iguales = (a & mask) == (b & mask);

    printf("son %s\n", son_iguales == 1 ? "iguales" : "distintos");
}

// 10
void rewrite_as_while() {
    int i = 0;

    while (i < 10) {
        printf("%d\n", i);

        i++;
    }
}

// 11 - aux
void imprimir_arreglo(int* arr, int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%d%s", arr[i], i == length - 1 ? "]\n" : ", ");
    }
}

// 11
void rotar_arreglo(int* arr, int length) {
    int base = arr[0];

    for (int i = 1; i < length; i++) {
        arr[i - 1] = arr[i];
    }

    arr[length - 1] = base;

    imprimir_arreglo(arr, length);
}


// 12
void rotar_arreglo_gen(int* arr, int length, int n) {
    int temp[length];

    for(int i = 0; i < n; i++) {
        temp[i] = arr[length - n + i];
    }

    for(int j = length - 1; j >= n; j--) {
        temp[j] = arr[j - n];
    }

    for (int k = 0; k < length; k++) {
        arr[k] = temp[k];
    }

    imprimir_arreglo(arr, length);
}

// 13
void dice_roll() {
    const int N = 60000000;
    int dice[6] = {0};
    size_t length = 6;

    for (int i = 0; i < N; i++) {
        dice[rand() % 6]++;
    }

    imprimir_arreglo(dice, length);
}

// 14 - shadowing
int global = 5;
void foo() {
    int global = 6;

    printf("%d\n", global);
}

// 15
int factorial(int n) {
    int r = 1;

    for (int i = 1; i <= n; i++) {
        r *= i;
    }

    return r;
}

// 16 - TRISTE
// 17 - FELIZ
// 18 - TRISTE - FELIZ - TRISTE
// cuando el tipo es static no se vuelve a instanciar cada vez que llamo a la funcion, se mantiene

int main() {
    const int EJERCICIO = 15;
    int arr_a[] = {1, 2, 3, 4};
    int arr_b[] = {5, 6, 7, 8};
    const size_t length = 4;

    switch (EJERCICIO) {
        case 1:
            hello_world();
            break;
        case 3:
            check_size();
            break;
        case 4:
            check_fix_size();
            break;
        case 5:
            casting();
            break;
        case 6:
            mensaje_secreto();
            break;
        case 7:
            operadores();
            break;
        case 8:
            diferencia_contadores();
            break;
        case 9:
            tres_bit_cmp(0b0110, 0b1110);
            break;
        case 10:
            rewrite_as_while();
            break;
        case 11:
            rotar_arreglo(arr_a, length);
            break;
        case 12:
            rotar_arreglo_gen(arr_b, length, 3);
            break;
        case 13:
            foo();
            break;
        case 14:
            dice_roll;
            break;
        case 15:
            printf("Factorial de 6: %d\n",factorial(6));
            break;
        default:
            printf("Ejercicio Inexistente\n");
            

    }

    return 0;
}
