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

#include <stdbool.h>   /* Definition of bool      */
#include <stdlib.h> /* Librería que me permite usar calloc */
#include <assert.h> /* Librería que me permite usar Assert */

#include "set.h" /* Incluyo la definición de set */
#include "list.h" /* Incluyo la definición de list */

struct s_set{ // Agregado
    list sorted_list;
};

/* CONSTRUCTORS */

// FUNCIONA

// Crea un conjunto vacío.
set set_empty(){
    set saux = calloc(1, sizeof(struct s_set));
    saux->sorted_list = list_empty();
    return saux;
} // FIN set_empty

// FUNCIONA

// Agrega el elemento 'e' al conjunto 's'.
set set_add(set s, type_elem e){
    assert(s!=NULL); 
    set saux = set_copy(s); // Copio 's' en 'saux'
    bool is_member;
    is_member = false;
    unsigned int n;
    n = 0; // Contador
    type_elem d;
    // Encuentro el lugar donde va el elemento
    while(!set_is_empty(saux) && !is_member){
        d = set_get(saux);
        if(d==e){
            is_member = true; // Pertenece
        }
        else if(d<e){
            n = n+1; // Sigo buscando
        }
        saux->sorted_list = list_tail(saux->sorted_list);
    }
    if(!is_member){
        s->sorted_list = list_add_at(s->sorted_list, n, e);
    }
    saux = set_destroy(saux); // Libero memoria
    return s; 
} // FIN set_add

/* OPERATIONS   */

// FUNCIONA

// Devuelve la cantidad de elementos que tiene 's'.
unsigned int set_cardinal(set s) {
    unsigned int n;
    return n = list_length(s->sorted_list);  
} // FIN set_cardinal

// FUNCIONA

// Devuelve True si 's' es vacío.
bool set_is_empty(set s){
    return list_is_empty(s->sorted_list);
} // FIN set_is_empty

// FUNCIONA

// Devuelve True si el elemento 'e' pertenece al conjunto 's'.
bool set_member(type_elem e, set s){
    assert(s!=NULL);
    set saux = set_copy(s); // Copio 's' en 'saux'
    type_elem d;
    bool b;
    b = false; // por default
    // Recorro
    while(!set_is_empty(saux) && !b){
        d = set_get(saux);
        if(d==e){
            b = true; // Pertenece
        }
        saux->sorted_list = list_tail(saux->sorted_list);
    }
    saux = set_destroy(saux); // Libero memoria
    return b;
} // FIN set_member

// FUNCIONA

// Elimina el elemento 'e' del conjunto 's', en caso que esté.
set set_elim(set s, type_elem e){
    assert(s!=NULL);
    set saux = set_copy(s); // Copio 's' en 'saux'
    bool b;
    b = false;
    unsigned int n;
    n = 0; // Contador
    type_elem d;
    while(!set_is_empty(saux) && !b){
        d = set_get(saux);
        if (d==e){
            b = true; // Pertenece
        }
        else if (d<e){
            n = n+1; // Sigo buscando
        }
        saux->sorted_list = list_tail(saux->sorted_list);
    }
    if(b){
        s->sorted_list = list_elim_at(s->sorted_list, n);
    }
    saux = set_destroy(saux); // Libero memoria
    return s;
} // FIN set_elim

// FUNCIONA

// Agrega a 's' todos los elementos de 's0'.
set set_union(set s, set s0){
    assert(s!=NULL && s0!=NULL);
    set saux = set_copy(s0); // Copio 's0' en 'saux'
    type_elem d;
    while(!set_is_empty(saux)){
        d = set_get(saux);
        s = set_add(s, d); // s->sorted_list = list_addr(s->sorted_list, d);
        saux->sorted_list = list_tail(saux->sorted_list);
    }
    saux = set_destroy(saux); // Libero memoria
    return s;
} // FIN set_union

// FUNCIONA

// Elimina de 's' todos los elementos que NO pertenezcan a 's0'.
set set_inters(set s, set s0){
    assert(s!=NULL && s0!=NULL);
    set saux = set_copy(s); // Copio 's' en 'saux'
    type_elem d;
    while(!set_is_empty(saux)){ // Si no es vacío
        d = set_get(saux); //d = list_head(saux->sorted_list);
        if(!set_member(d, s0)){
            set_elim(s, d);
        }
        saux->sorted_list = list_tail(saux->sorted_list);
    }
    saux = set_destroy(saux); // Libero memoria
    return s;
} // FIN set_inters

// FUNCIONA

// Elimina de 's' todos los elementos que pertenecen a 's0'.
set set_dif(set s, set s0){
    assert(s!=NULL && s0!=NULL);
    set saux = set_copy(s0); // Copio 's0' en 'saux'
    type_elem d;
    while(!set_is_empty(saux)){
        d = set_get(saux);
        if(set_member(d, s)){
            set_elim(s, d);
        }
        saux->sorted_list = list_tail(saux->sorted_list);
    }
    saux = set_destroy(saux); // Libero memoria
    return s;
} // FIN set_dif

// FUNCIONA

// Obtiene el primer elemento del conjunto 's'.
type_elem set_get(set s){ 
    assert(s!=NULL && !set_is_empty(s));
    return list_head(s->sorted_list);;
} // FIN set_get

// FUNCIONA

// Copia el conjunto 's'
set set_copy(set s){
    assert(s!=NULL);
    set saux = set_empty();
    saux->sorted_list = list_copy(s->sorted_list);
    return saux;
} // FIN set_copy

// FUNCIONA

// Libera memoria en caso que haya sido pedida.
set set_destroy(set s){
    s->sorted_list = list_destroy(s->sorted_list);
    free(s);
    s = NULL;
    return s;
} // FIN set_destroy