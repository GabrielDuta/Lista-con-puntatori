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
    struct elemento *e;
};

int main()
{
    struct elemento *lista = NULL;
    int scelta;

    do{
        printf("Scegli opzione:\n1) Aggiungi numero;\n2) Elimina elemento;\n3) Stampa;\n4) Esci.\nInserisci scelta: ");
        scanf("%d", &scelta);
        printf("\n");
        switch(scelta) {
            case 1: lista = inserisci(lista);
                break;
            case 2: lista = elimina(lista);
                break;
            case 3: stampa(lista);
                break;
            default: break;
        }
        system("cls");
    }while(scelta != 4);

}

struct elemento *inserisci(struct elemento *p) {
    struct elemento *punt, *lista = p;  //punt è usato come appoggio, lista invece è usato per restituire la lista
    int a, scelta;                      //completa quando si sceglie di inserire l'elemento alla fine.


    if(p != NULL) {
        printf("Dove vuoi inserire l'elemento?\n1) Inizio;\n2) Fine.\nInserisci scelta: ");
        scanf("%d", &scelta);
        printf("Inserisci numero: ");
        scanf("%d", &a);
        printf("\n");

        /* creazione elementi successivi*/
        // Alloco la memoria necessaria
        punt = (struct elemento *)malloc(sizeof(struct elemento));
        punt->n.numero = a;
        if(scelta == 1) {
            punt->e = p;
        }
        else {
            while(p->e != NULL)
                p = p->e;
            punt->e = NULL;
            p->e = punt;
            return(lista);
        }
    }
    else {
        printf("Inserisci numero: ");
        scanf("%d", &a);
        printf("\n");
         /* creazione primo elemento */
         // Alloco la memoria necessaria
         punt = (struct elemento *)malloc(sizeof(struct elemento));
         punt->n.numero = a;
         punt->e = NULL;
    }

    return(punt);
}

struct elemento *elimina(struct elemento *p) {
    struct elemento *lista = p;
    int i;

    printf("Inserisci il numero da eliminare: ");
    scanf("%d", &i);
    if(p == NULL)
        printf("Lista vuota\n");
    else if(p->n.numero == i){
        lista = p->e;
        printf("Elemento rimosso!\n");
    }
    else{
        while(p != NULL){
            if(p->e != NULL && p->e->n.numero == i)
                break;
            p = p->e;
        }

        if(p != NULL) {
            p->e = p->e->e;
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
    char invio;
    if(p != NULL) {
        while(p != NULL) {
            printf("%d' elemento: %d\n", conta, p->n.numero);
            p = p->e;
            conta++;
        }
    }
    else
        printf("La lista e' vuota\n");
    system("pause");

}
