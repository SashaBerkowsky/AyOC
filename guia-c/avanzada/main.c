#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "list.h"

#define EJ 14

// 1
typedef struct {
    char* name;
    int life;
    double attack;
    double defense;
} monster_t;

void print_monster(monster_t monstruo) {
    printf("nombre: %s\n", monstruo.name);
    printf("vida: %i\n", monstruo.life);
    printf("vida: %f\n", monstruo.attack);
    printf("vida: %f\n", monstruo.defense);
}

void print_monsters(monster_t *monstruos, size_t length) {

    for (int i = 0; i < length; i++) {
        print_monster(monstruos[i]);
    }
}

// 2
monster_t evolution(monster_t monstruo) {
    monster_t evolution = { 
        monstruo.name,
        monstruo.life,
        monstruo.attack + 10, 
        monstruo.defense + 10
    };

    return evolution;
}

// 3, 4
// x es una variable
// xp puntero donde esta guardado el valor de x
// *xp puntero donde esta guardado el lugar de memoria donde esta el valor de x
void foo(){
    int x = 42;
    int *xp = &x;

    printf("Direccion de x: %p Valor: %d\n", (void*) &x, x);
    printf("Direccion de p: %p Valor: %p\n", (void*) &xp, (void*) xp);
    printf("Valor de lo que apunta p: %d\n", *xp);
}

// 5: ambos utilizan el mismo dato pero uno lo maneja como un unsigned int y otro como un int, no hay problema con hacer esto mientras que ambos dos sean del mismo tamaño

// 6
void pointer_test() {
    int8_t memoria[] = {2, 3, 7};
    uint8_t *x = (uint8_t*) &memoria;
    int8_t *y = memoria;

    printf("Dir de x: %p; Valor: %d\n", (void*) x, *x);
    printf("Dir de y: %p; Valor: %d\n", (void*) y, *y);
}

// 7: en este caso estaria pasando a y b por referencia con lo cual sus valores pasan al stack y al terminar la funcion se caen del stack pero el valor original de a y b se sostienen con lo cual esta version de swap no hace nada

// 8: str1 no se puede editar ya que es un puntero a un literal con lo cual es un puntero a una posicion de memoria de solo lectura, str2 en cambio es un array de caracteres almacenado en la pila con lo cual si es editable

// 9
void to_uppercase(char s[], size_t length) {
    for (int i = 0; i < length; i++) {
        if(s[i] >= 97 && s[i] <= 122) {
            s[i] -= 32;
        }
    }
}

// 10
void str_examples() {
    char hello[15] = "Hello";
    char hellocpy[15];
    char world[] = ", world!";

    strcpy(hellocpy, hello);

    printf("strcat: %s\n", strcat(hello, world));
    printf("strlen hello: %zu\n", strlen(hello));
    printf("%s == %s ?: %s\n", hellocpy, world, strcmp(hello, world) == 1 ? "YES": "NO");
}

// 12
typedef struct {
    char *name;
    unsigned int age;

} person_t;

person_t *createPerson(char name[], unsigned int age) {
    person_t *person = malloc(sizeof(person_t));

    person->name = name;
    person->age = age;

    return person;
}

void deletePerson(person_t *p) {
    free(p->name);
    free(p);
}

int main() {
    monster_t monstruos[2] = {
        { "murloc", 150, 30, 40},
        { "goblin", 300, 10, 20},
    };
    size_t length = sizeof(monstruos)/sizeof(monster_t);
    char hw[] = "Hello, world!";

    printf("--- EJERCICIO %d ---\n\n", EJ);
    switch (EJ) {
        case 1:
            print_monsters(monstruos, length);
            break;
        case 2:
            print_monster(evolution(monstruos[0]));
            break;
        case 3:
            foo();
            break;
        case 6:
            pointer_test();
            break;
        case 9:
            to_uppercase(hw, sizeof(hw)/sizeof(char));
            printf("Uppercase: %s\n", hw);
            break;
        case 10:
            str_examples();
            break;
        case 12: {
            person_t *me = createPerson("Sasha", 25);
            printf("nombre: %s, edad: %d\n", me->name, me->age);
            free(me->name);
            free(me);
            break;
        }
        case 13: {
            person_t *me = createPerson("Sasha", 25);
            deletePerson(me);
            break;
        }
        case 14: {
            list_t* l = listNew(TypeFAT32);
            fat32_t* f1 = new_fat32();
            fat32_t* f2 = new_fat32();

            listAddFirst(l, f1);
            listAddFirst(l, f2);
            listDelete(l);
            rm_fat32(f1);
            rm_fat32(f2);
            break;
        }
        case 15: {
            list_t* l = listNew(TypeFAT32);
            fat32_t* f1 = new_fat32();
            fat32_t* f2 = new_fat32();

            listAddFirst(l, f1);
            listAddFirst(l, f2);
            listSwap(l, 0, 1);
            listDelete(l);
            rm_fat32(f1);
            rm_fat32(f2);
            break;
        }
        default:
            printf("Ejercicio Inexistente\n");
    }

    

    return 0;
}
