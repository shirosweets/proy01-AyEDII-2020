# proy01-AyEDII-2020

-------------------------------------------------------------------------------------------------------------------

                                *** COMANDOS PARA CORRER  EL PROGRAMA ***

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c test_set.c

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c set.c

gcc -Wall -Werror -Wextra -pedantic -no-pie -std=c99 -o test_s list-x86_64.o set.o test_set.o

./test_s

		            *** COMANDOS PARA CORRER  EL PROGRAMA (MEMORY LEAKS)***

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c test_set.c

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c set.c

gcc -Wall -Werror -Wextra -pedantic -no-pie -std=c99 -o test_s list-x86_64.o set.o test_set.o

valgrind --show-reachable=yes --leak-check=full ./test_s

-------------------------------------------------------------------------------------------------------------------

Autor: Valentina Solange, Vispo.

Versión: v3.

-------------------------------------------------------------------------------------------------------------------
