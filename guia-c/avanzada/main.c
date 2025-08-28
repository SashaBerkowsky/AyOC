#include <stdio.h>
#include <string.h>
#define EJ 2

// 1
typedef struct {
    char* nombre;
    int vida;
    double ataque;
    double defensa;
} monstruo_t;

void imprimir_monstruo(monstruo_t monstruo) {
    printf("nombre: %s\n", monstruo.nombre);
    printf("vida: %i\n", monstruo.vida);
    printf("vida: %f\n", monstruo.ataque);
    printf("vida: %f\n", monstruo.defensa);
}

void imprimir_monstruos(monstruo_t *monstruos, size_t length) {

    for (int i = 0; i < length; i++) {
        imprimir_monstruo(monstruos[i]);
    }
}

// 2
monstruo_t evolucion(monstruo_t monstruo) {
    monstruo_t evolucion = { 
        monstruo.nombre,
        monstruo.vida,
        monstruo.ataque + 10, 
        monstruo.defensa + 10
    };

    return evolucion;
}

// 3
// x es una variable
// xp puntero donde esta guardado el valor de x
// *xp puntero donde esta guardado el lugar de memoria donde esta el valor de x
void foo(){
    int x = 42;
    int *xp = &x;

    printf("Direccion de x: %p Valor: %d\n", (void*) &x, x);
    printf("Direccion de p: %p Valor: %p\n", (void*) &p, (void*) p);
    printf("Valor de lo que apunta p: %d\n", *p);
}

int main() {
    monstruo_t monstruos[2] = {
        { "murloc", 150, 30, 40},
        { "goblin", 300, 10, 20},
    };
    size_t length = sizeof(monstruos)/sizeof(monstruo_t);

    switch (EJ) {
        case 1:
            imprimir_monstruos(monstruos, length);
            break;
        case 2:
            imprimir_monstruo(evolucion(monstruos[0]));
            break;
        default:
            printf("Ejercicio Inexistente\n");
    }

    

    return 0;
}