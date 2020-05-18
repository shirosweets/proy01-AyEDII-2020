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

#ifndef _SET_H_
#define _SET_H_

#include <stdbool.h>   /* Definition of bool      */
#include "type_elem.h" /* Definition of type_elem */

typedef struct s_set * set; // set puntero a estructura s_set (apunta a)

/* CONSTRUCTORS */

// Crea un conjunto vacío.
set set_empty(void);
/*
 * DESC: Crea un conjunto vacío.
 * USAGE: s = set_empty();
 * POS  : {set_is_empty(s)}
 */

// Agrega el elemento 'e' al conjunto 's'.
set set_add(set s, type_elem e);
/*
 * DESC: Agrega el elemento 'e' al conjunto 's'.
 * PRE  : {s!=NULL /\ set_cardinal(s) == N}
 * USAGE: s = set_add(s, e);
 * POS  : {set_cardinal(s) == N + 1 /\ e == set_get(s)}
 */


/* OPERATIONS   */

// Devuelve la cantidad de elementos que tiene 's'.
unsigned int set_cardinal(set s); //
/*
 * DESC: Devuelve la cantidad de elementos que tiene 's'.
 * USAGE: n = set_cardinal(s);
 */

// Devuelve True si 's' es vacío.
bool set_is_empty(set s); //
/*
 * DESC: Devuelve True si 's' es vacío.
 * USAGE: b = set_is_empty(s);
 * POS  : {set_is_empty(s) == (set_cardinal(s) == 0)}
 */

// Devuelve True si el elemento 'e' pertenece al conjunto 's'.
bool set_member(type_elem e, set s);
/*
 * DESC: Devuelve True si el elemento 'e' pertenece al conjunto 's'.
 * PRE  : {s != NULL}
 * USAGE: b = set_member(e, s);
 * POS  : {set_member(e, s)}
 */

// Elimina el elemento 'e' del conjunto 's', en caso que esté.
set set_elim(set s, type_elem e);
/*
 * DESC: Elimina el elemento 'e' del conjunto 's', en caso que esté.
 * PRE  : {s != NULL}
 * USAGE: s = set_elim(s, e);
 * POS  : {set_cardinal(s) == N - 1}
 */

// Agrega a 's' todos los elementos de 's0'.
set set_union(set s, set s0);
/*
 * DESC: Agrega a 's' todos los elementos de 's0'.
 * PRE  : {s != NULL /\ s0 != NULL /\ set_cardinal(s) == N /\ set_cardinal(s0) == M}
 * USAGE: s = set_union(s, s0);
 * POS  : {set_cardinal(s) == N + M}
 */

// Elimina de 's' todos los elementos que NO pertenezcan a 's0'.
set set_inters(set s, set s0);
/*
 * DESC: Elimina de 's' todos los elementos que NO pertenezcan a 's0'.
 * PRE  : {s != NULL /\ s0 != NULL /\ set_cardinal(s) == N /\ s1 = set_copy(s) /\ s1 = dif(s1, s0) /\ set_cardinal(s1) == P}
 * USAGE: s = set_inters(s, s0);
 * POS  : {set_cardinal(s) == N - P}
 */

// Elimina de 's' todos los elementos que pertenecen a 's0'.
set set_dif(set s, set s0);
/*
 * DESC: Elimina de 's' todos los elementos que pertenecen a 's0'.
 * PRE  : {s != NULL /\ s0 != NULL /\ set_cardinal(s0) == M /\ s1 = set_copy(s) /\ s1 = set_inter(s1, s0) /\ set_cardinal(s1) == P}
 * USAGE: s = set_dif(s, s0);
 * POS  : {set_cardinal(s) == N - P}
 */

// Obtiene el primer elemento del conjunto 's'.
type_elem set_get(set s);
/*
 * DESC: Obtiene el primer elemento del conjunto 's'.
 * PRE  : {!is_empty_set(s) /\ s != NULL}
 * USAGE: n = set_get(s);
 * POS  : {set_cardinal(s) == 1 /\ n == set_get(s)}
 */

// Copia el conjunto 's'.
set set_copy(set s);
/*
 * DESC: Copia el conjunto 's'.
 * PRE: {s != NULL}
 * USAGE: s1 = set_copy(s);
 * POS  : {set_cardinal(s) == set_cardinal(s1) /\ s == s1}
 */

// Libera memoria en caso que haya sido pedida.
set set_destroy(set s);
/*
 * DESC: Libera memoria en caso que haya sido pedida.
 * USAGE: s = set_destroy(s);
 * POS  : {set_is_empty(s) == (set_cardinal(s) == 0)}
 */

#endif
