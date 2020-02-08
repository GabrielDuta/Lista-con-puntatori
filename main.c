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
    struct elemento *punt, *lista = p, *temp;  //punt è usato come appoggio, lista invece è usato per restituire la lista
    int a = 0, scelta;                      //completa quando si sceglie di inserire l'elemento alla fine.


    if(p != NULL) {
        printf("Inserisci numero: ");
        scanf("%d", &a);
        printf("\n");

        /* creazione elementi successivi*/
        // Alloco la memoria necessaria
        punt = (struct elemento *)malloc(sizeof(struct elemento));
        punt->n.numero = a;

        if(p->n.numero > a) {
            punt->next = p;
            return(punt);
        }
        else {
            while(p->next != NULL && p->next->n.numero < a)
                p = p->next;
            punt->next = p->next;
            p->next = punt;
        }
        return(lista);
    }
    else {
        printf("Inserisci numero: ");
        scanf("%d", &a);
        printf("\n");
         /* creazione primo elemento */
         // Alloco la memoria necessaria
         punt = (struct elemento *)malloc(sizeof(struct elemento));
         punt->n.numero = a;
         punt->next = NULL;
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
    char invio;
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
