# Repartiment de tasques

Fase 1: Tasques i Comentaris (tasca.c i tests.c)

L'objectiu és tenir la unitat mínima de dades funcionant.

    Membre 1 (Lectura i Mostra):

        llegeix_nou_comentari() i mostra_comentari().

llegeix_nova_tasca() i mostra_tasca().

Test: Implementar tests_tasca1() (validar lectura/mostra).

Membre 2 (Gestió de dades):

    insereix_comentari() (afegir a la posició 0).

elimina_comentari() (gestió de l'índex i desplaçament).

Test: Implementar tests_tasca2() (validar inserció/eliminació).

Fase 2: Gestió de Carpetes i Dates (carpeta.c i tests.c)

Aquesta és la fase més densa del projecte.

    Membre 1 (Estructura i Cerques):

        llegeix_nova_data(), mostra_data(), llegeix_nova_carpeta() i mostra_carpeta().

cerca_data() i cerca_tasca() (cerques lineals que retornen punters).

Test: Implementar tests_carpeta1().

Membre 2 (Algorismes d'Ordre):

    insereix_nova_data(): Inserció mantenint l'ordre creixent (cronològic).

insereix_nova_tasca(): Inserció mantenint l'ordre decreixent de prioritat.

elimina_tasca() i neteja_dates_buides().

Test: Implementar tests_carpeta2() i tests_carpeta3().

Fase 3: L'Organitzador General (organitzador.c i tests.c)

Gestió del nivell superior de l'aplicació.

    Membre 1 (Visualització Global):

        cerca_carpeta().

mostra_carpetes() i mostra_contingut_carpeta().

Test: Implementar tests_organitzador1().

Membre 2 (Administració de l'Organitzador):

    insereix_nova_carpeta(): Inserció mantenint l'ordre alfabètic.

elimina_carpeta() i neteja_dates_buides_carpetes().

Test: Implementar tests_organitzador2().

Fase 4: Interfície d'Usuari (main.c)

Integració final de totes les peces.

    Membre 1 (Utilitats i Mostra):

        llegeix_text() (funció auxiliar per a títols amb espais).

mostrar_ajuda() i les funcions processa_opcio_... de visualització (S, M, A).

Membre 2 (Control de Flux i Accions):

    Bucle principal main() amb el control d'opcions (switch/case).

Funcions processa_opcio_... que modifiquen dades (N, D, T, I, E, B, C).
