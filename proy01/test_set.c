/* Materia: Algoritmos y Estructura de Datos II - 2020 FAMAF
    PROYECTO 1: TAD Conjunto finito 

Alumna:  
    - Vispo, Valentina Solange

Link de descarga: https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo2:main:proy01_2020.zip

Fecha de entrega: 11/05 23:59:59

Teórico:
Tipos Abstractos de Datos: https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo2:main:2020.05.tipos.abstractos.pdf
TADs Pila y Cola: https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo2:main:2020.06.tipos.abstractos2.pdf
TADs Árboles binarios: https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo2:main:2020.07.abb.pdf

Video presentación del proyecto: https://drive.google.com/file/d/1tmXIOJqICUBQCfdyDUWjGhBeTy1EKt3D/view?usp=sharing

Videos explicativos:
TAD P1: https://youtu.be/f2EXztXim_4
TAD P2: https://youtu.be/0P-T-43s2HM
Pilas y Colas: https://youtu.be/_QH9IY90JZE
*/

#include <stdio.h> /* printf()...           */
#include "set.h"   /* Interfaz del TAD set  */

static void
print_set(set s) {
    /* Muestra por pantalla el contenido de un conjunto de enteros */
    /*
     * Es crucial que las funciones:
     *   - set_copy()
     *   - set_get()
     *   - set_elim()
     *   - set_is_empty()
     *
     * estén bien programadas para que se muestre correctamente.
     */
    set saux=set_copy(s);
    printf("{");
    while (!set_is_empty(saux)) {
        type_elem e;
        e = set_get(saux);
        printf("%i", e);
        saux = set_elim(saux, e);
        if (!set_is_empty(saux))
            printf(", ");
     }
    printf("}");
    saux = set_destroy(saux);
}

static void
show_status(set s, const char *name) {
    /*
     * Muestra por pantalla: - La etiquena 'name'
     *                       - El contendio del conjunto
     *                       - Su longitud
     *                       - Si es o no vacío
     */
    /* Se muestra la etiqueta */
    printf("{ %s == ", name);
    /* Se muestra el contenido del conjunto */
    print_set(s);
    printf(" /\\ ");
    /* Se muestra el cardinal */
    printf("|%s| = %i /\\ ", name, set_cardinal(s));
    /* Se indica si es vacío o no */
    if (set_is_empty(s)) printf("empty"); else printf("not empty");
    printf(" }");
    printf("\n\n");
}

int main(){
    printf(" ********* Inicio programa *********\n\n");
    
    // REVISAR 
    //   - set_copy()
    //   - set_get()
    //   - set_elim()
    //   - set_is_empty()

// SET_EMPTY //
    printf(" **** set_empty ****\n");
    printf("\n Creo el conjunto 'c1'\n");
    set c1 = set_empty(); // Creo el conjunto 'c1'
    show_status(c1, "Conjunto 'c1");

    printf("\n Creo el conjunto 'c2'\n");
    set c2 = set_empty(); // Creo el conjunto 'c2'
    show_status(c2, "Conjunto 'c2");

    printf("\n Creo el conjunto 'c2'\n");
    set c3 = set_empty(); // Creo el conjunto 'c3'
    show_status(c3, "Conjunto 'c3");

// SET_ADD //
    printf("\n **** set_add ****\n\n");
    printf(" Agrego 9 al conjunto 'c1'\n");
    c1 = set_add(c1, 9); // Agrego un elemento a 'c1'
    show_status(c1, "Conjunto 'c1'");

    printf("\n Agrego 2 y 4 al conjunto 'c2'\n");
    c2 = set_add(set_add(c2, 2), 4); // Agrego dos elementos a 'c2'
    show_status(c2, "Conjunto 'c2'");

    printf("\n Agrego 4, 7 y 9 al conjunto 'c3'\n");
    c3 = set_add(set_add(set_add(c3, 4), 7), 9); // Agrego tres elementos a 'c3'
    show_status(c3, "Conjunto 'c3'");

// SET_CARDINAL //
    printf("\n **** set_cardinal ****\n\n");
    unsigned int n = set_cardinal(c1);
    printf(" La cantidad de elementos de 'c1' es: %d\n", n);

    n = set_cardinal(c2);
    printf(" La cantidad de elementos de 'c2' es: %d\n", n);

    n = set_cardinal(c3);
    printf(" La cantidad de elementos de 'c3' es: %d\n", n);

// SET_IS_EMPTY //
    printf("\n\n **** set_is_empty (1 = true and 0 = false) ****\n\n");
    bool b = set_is_empty(c1);
    printf(" El conjunto 'c1' es vacío: %d\n", b);

    b = set_is_empty(c2);
    printf(" El conjunto 'c2' es vacío: %d\n", b);

    b = set_is_empty(c3);
    printf(" El conjunto 'c3' es vacío: %d\n", b);

    printf("\n Creo el conjunto 'empty'\n");
    set empty = set_empty();
    b = set_is_empty(empty);
    printf(" El conjunto 'empty' es vacío: %d\n", b);

// SET_MEMBER //
     printf("\n **** set_member (1 = true and 0 = false) ****\n\n");
    type_elem e;
    e = 9;
    b = set_member(e, c1);
    printf(" %d pertenece a 'c1': %d\n", e, b);
    show_status(c1, "Conjunto 'c1'");
    e = 1;
    b = set_member(e, c1);
    printf(" %d pertenece a 'c1': %d\n", e, b);
    show_status(c1, "Conjunto 'c1'");

    e = 2;
    b = set_member(e, c2);
    printf(" %d pertenece a 'c2': %d\n", e, b);
    show_status(c2, "Conjunto 'c2'");
    e = 4;
    b = set_member(e, c2);
    printf(" %d pertenece a 'c2': %d\n", e, b);
    show_status(c2, "Conjunto 'c2'");

// SET_ELIM //
    printf("\n **** set_elim ****\n");
    printf("\n Creo el conjunto 'elim1'\n");
    set elim1 = set_empty();
    printf("\n Agrego 5 y 7 al conjunto 'elim1'\n");
    elim1 = set_add(set_add(elim1, 5), 7); // Agrego dos elementos a 'elim1'
    show_status(elim1, "Conjunto 'elim1'");
    e = 5;
    printf(" Elimino %d del conjunto 'elim1'\n", e);
    elim1 = set_elim(elim1, e);
    show_status(elim1, "Conjunto 'elim1'");

// SET_UNION //
    printf("\n **** set_union ****\n");
    printf("\n Creo el conjunto 'union0'\n");
    set union0 = set_empty();
    printf("\n Agrego 8 al conjunto 'union0'\n");
    union0 = set_add(union0, 8); // Agrego un elemento a 'union0'
    show_status(union0, "Conjunto 'union0'");
    printf(" Creo el conjunto 'union1'\n");
    set union1 = set_empty();
    printf("\n Agrego 4 y 6 al conjunto 'union1'\n");
    union1 = set_add(set_add(union1, 4), 6); // Agrego dos elementos a 'union1'
    show_status(union1, "Conjunto 'union1'");
    printf(" Agrego a 'union0' todos los elementos de 'union1'\n");
    union0 = set_union(union0, union1); // Había un error en los argumentos
    show_status(union0, "Conjunto 'union0'");

// SET_INTERS //
    printf("\n **** set_inters ****\n");
    printf("\n Creo el conjunto 'inters1'\n");
    set inters1 = set_empty();
    printf("\nAgrego 1 y 7 al conjunto 'c'\n");
    inters1 = set_add(set_add(inters1, 1), 7); // Agrego dos elementos a 'inters1'
    show_status(inters1, "Conjunto 'inters1'");

    printf(" Creo el conjunto 'inters2'\n");
    set inters2 = set_empty();
    printf("\nAgrego 3 y 7 al conjunto 'inters2'\n");
    inters2 = set_add(set_add(inters2, 3), 7); // Agrego dos elementos a 'inters2'
    show_status(inters2, "Conjunto 'inters2'");

    printf("\n Elimina de 'inters1' todos los elementos que NO pertenezcan a 'inters2'\n");
    inters1 = set_inters(inters1, inters2);
    // Debería mostrarse 'inters1' = {7}
    show_status(inters1, "Conjunto 'inters1'");

// SET_DIF //
    printf("\n **** set_dif ****\n");
    printf("\n Creo el conjunto 'dif1'\n");
    set dif1 = set_empty();
    printf("\n Agrego 1 y 3 al conjunto 'dif1'\n");
    dif1 = set_add(set_add(dif1, 1), 3); // Agrego dos elementos a 'dif1'
    show_status(dif1, "Conjunto 'dif1'");

    printf("\n Creo el conjunto 'dif2'\n");
    set dif2 = set_empty();
    printf("\n Agrego 1 y 2 al conjunto 'dif2'\n");
    dif2 = set_add(set_add(dif2, 1), 2); // Agrego dos elementos a 'dif2'
    show_status(dif2, "Conjunto 'dif2'");

    printf("\n Elimina de 'dif1' todos los elementos que pertenecen a 'dif2'\n");
    dif1 = set_dif(dif1, dif2);
    show_status(dif1, "Conjunto 'dif1'");

// SET_GET //
    printf("\n **** set_get ****\n");
    printf("\n Creo el conjunto 'get'\n");
    set get = set_empty();
    printf("\n Agrego 0 y 9 al conjunto 'get'\n");
    get = set_add(set_add(get, 0), 9); // Agrego dos elementos a 'get'
    show_status(get, "Conjunto 'get'");

    printf(" Obtiene el primer elemento del conjunto 'get'");
    type_elem d = set_get(get);
    printf("\n Elemento de 'get': %d\n", d);

// SET_COPY //
    printf("\n **** set_copy ****\n");
    show_status(get, "Conjunto 'get'");

    printf("\n Copia el conjunto 'get' en 'copy'\n");
    set copy = set_copy(get);
    show_status(copy, "Conjunto 'copy'");

// SET_DESTROY //
    printf("\n **** set_destroy ****\n");

    printf("\n Libera memoria en caso que haya sido pedida\n");

    // Libero 'c1'
    printf("\n Libero 'c1'");
    c1 = set_destroy(c1);

    // Libero 'c2'
    printf("\n Libero 'c2'");
    c2 = set_destroy(c2);

    // Libero 'c3'
    printf("\n Libero 'c3'");
    c3 = set_destroy(c3);

    // Libero 'empty'
    printf("\n Libero 'empty'");
    empty = set_destroy(empty);

    // Libero 'elim1'
    printf("\n Libero 'elim1'");
    elim1 = set_destroy(elim1);

    // Libero 'union0'
    printf("\n Libero 'union0'");
    union0 = set_destroy(union0);

    // Libero 'union1'
    printf("\n Libero 'union1'");
    union1 = set_destroy(union1);

    // Libero 'inters1'
    printf("\n Libero 'inters1'");
    inters1 = set_destroy(inters1);

    // Libero 'inters2'
    printf("\n Libero 'inters2'");
    inters2 = set_destroy(inters2);

    // Libero 'dif1'
    printf("\n Libero 'dif1'");
    dif1 = set_destroy(dif1);

    // Libero 'dif2'
    printf("\n Libero 'dif2'");
    dif2 = set_destroy(dif2);

    // Libero 'get'
    printf("\n Libero 'get'");
    get = set_destroy(get);

    // Libero 'copy'
    printf("\n Libero 'copy'\n");
    copy = set_destroy(copy);

////////////////

    printf("\n ////////////////////////////////////// \n");
    printf("\n Creo el conjunto 'prueba'\n");
    set prueba = set_empty(); // Creo el conjunto vacío 'prueba'
    printf("\n Agrego 5 al conjunto 'prueba'\n");
    prueba = set_add(prueba, 5); // Agrego un elemento a 'prueba'
    show_status(prueba, "Conjunto 'prueba'");
    printf(" Libero 'prueba'\n");
    prueba = set_destroy(prueba);

    printf("\n ********* Fin programa *********\n");
    return 0;
}