#include <stdio.h>

// 1
void hello_world() {
    printf("Hello, world!\n");
}

// 2
void check_size() {
    char c = 100;
    short s = -8712;
    int i = 123456;
    long l = 1234567890;

    unsigned char uc = -100;
    unsigned short us = -7892;
    unsigned int ui = -12398;
    unsigned long ul = -123812485;

    printf("--- signed ---\n");
    printf("char(%lu): %d \n", sizeof(c), c);
    printf("short(%lu): %d \n", sizeof(s), s);
    printf("int(%lu): %d \n", sizeof(i), i);
    printf("long(%lu): %ld \n", sizeof(l), l);

    printf("--- unsigned ---\n");
    printf("char(%lu): %u \n", sizeof(uc), uc);
    printf("short(%lu): %u \n", sizeof(us), us);
    printf("int(%lu): %u \n", sizeof(ui), ui);
    printf("long(%lu): %lu \n", sizeof(ul), ul);
}

int main() {
    check_size();

    return 0;
}
