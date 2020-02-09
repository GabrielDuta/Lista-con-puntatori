#include <stdio.h>
#include <stdlib.h>

struct elemento *inserisci(struct elemento *p);
struct elemento *elimina(struct elemento *p);
void stampa(struct elemento *p);

typedef struct{
    int numero;
}num;

struct elemento{
    num n;
    struct elemento *next;
};

int main()
{
    struct elemento *inizioLista = NULL; //il puntatore ad inizio lista; all'inizio è NULL ma poi quando viene inizializzato punta al primo elemento della lista
    int scelta;                         //per questo motivo ma sempre aggiornato.

    do{
        printf("Scegli opzione:\n1) Aggiungi numero;\n2) Elimina elemento;\n3) Stampa;\n4) Esci.\nInserisci scelta: ");
        scanf("%d", &scelta);
        printf("\n");
        switch(scelta) {
            case 1: inizioLista = inserisci(inizioLista);
                break;
            case 2: inizioLista = elimina(inizioLista);
                break;
            case 3: stampa(inizioLista);
                break;
            default: break;
        }
        system("cls");
    }while(scelta != 4);

}

struct elemento *inserisci(struct elemento *p) {
    struct elemento *puntTemporaneo, *lista = p, *temp;  //puntTemporaneo è usato come appoggio, lista invece è usato per restituire la lista
    int a = 0, scelta;                      //completa quando si sceglie di inserire l'elemento alla fine.


    if(p != NULL) {
        printf("Inserisci numero: ");
        scanf("%d", &a);
        printf("\n");

        /* creazione elementi successivi*/
        // Alloco la memoria necessaria
        puntTemporaneo = (struct elemento *)malloc(sizeof(struct elemento));
        puntTemporaneo->n.numero = a;

        if(p->n.numero > a) { // modifica il primo elemento, serve un caso speciale perchè viene semplicemente modificato il next di puntTemporaneo
            puntTemporaneo->next = p;
            return(puntTemporaneo);//viene restituito questo perchè è il nuovo primo elemento e quindi il puntatore inizioLista deve essere aggiornato
        }
        else {
            while(p->next != NULL && p->next->n.numero < a) //fa scorrere la lista fino a trovare un elemento minore
                p = p->next;
            puntTemporaneo->next = p->next;
            p->next = puntTemporaneo;
            return(lista); //restituisce 'lista' che punta all'inizio della lista e quindi non modifica il puntatore nel main
        }
    }
    else { //inizializza la lista
        printf("Inserisci numero: ");
        scanf("%d", &a);
        printf("\n");
         /* creazione primo elemento */
         // Alloco la memoria necessaria
         puntTemporaneo = (struct elemento *)malloc(sizeof(struct elemento));
         puntTemporaneo->n.numero = a;
         puntTemporaneo->next = NULL;
    }

    return(puntTemporaneo);
}

struct elemento *elimina(struct elemento *p) {
    struct elemento *lista = p;
    int i;

    printf("Inserisci il numero da eliminare: ");
    scanf("%d", &i);
    if(p == NULL)
        printf("Lista vuota\n");
    else if(p->n.numero == i){
        lista = p->next;
        printf("Elemento rimosso!\n");
    }
    else{
        while(p != NULL){
            if(p->next != NULL && p->next->n.numero == i)
                break;
            p = p->next;
        }

        if(p != NULL) {
            p->next = p->next->next;
            printf("Elemento rimosso!\n");
        }
        else
            printf("Elemento non presente nella lista\n");
    }
    system("pause");
    return(lista);
}

void stampa(struct elemento *p) {
    int conta = 1;
    if(p != NULL) {
        while(p != NULL) {
            printf("%d' elemento: %d\n", conta, p->n.numero);
            p = p->next;
            conta++;
        }
    }
    else
        printf("La lista e' vuota\n");
    system("pause");

}
