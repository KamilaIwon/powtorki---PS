#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};
//dodajemy element
struct element* dodaj(struct element*Lista, int a)
{
    struct element * wsk = malloc(sizeof(struct element));
    wsk->i=a;
    wsk->next=Lista;
    return wsk;
};
//tworzymy liste
struct element * utworz()
{
    return NULL;
};
//wyswietlamy liste bez glowy
void wyswietlListeBezGlowy(struct element*Lista)
{
    struct element*temp=Lista;
    if(temp==NULL)
    {
        printf("Lista jest pusta\n");
    }
    while(temp!=NULL)
    {
        printf("%d\n",temp->i);
        temp=temp->next;
    }
    printf("----\n");
}
//znajdujemy minimalny element parzysty
int znajdzminimumparzyste(struct element*Lista)
{
    int minimum;
    struct element*temp=Lista;
    if(temp==NULL)
    {
        return -1;
    }
    while(temp->i %2!=0)
    {
        minimum = temp->i;
        temp=temp->next;
    }


    while(temp!=NULL)
    {
        if((temp->i) < minimum)
        {
            minimum = temp->i;
        }
        temp=temp->next;
    }

    return minimum;
}

//znajdz ostatni element parzysty
int znajdzostniep(struct element*Lista)
{
    int niep;
    struct element*temp=Lista;
    if(temp==NULL)
    {
        return -1;
    }


    while(temp!=NULL)
    {
        if((temp->i) % 2 != 0)
        {
            niep = temp->i;
        }
        temp=temp->next;
    }
    printf("----\n");
    return niep;
}

//znajdz najmniejszy element ujemny
int najniepuj(struct element*Lista)
{
    int niep = 0;
    struct element*temp=Lista;
    if(temp==NULL)
    {
        return 0;
    }


    while(temp!=NULL)
    {
        if((temp->i)<0 && temp->i<niep)
        {
            niep = temp->i;
        }
        temp=temp->next;
    }
    if(niep == 0) return 0;
    return niep;
}


//czyszczenie listy
struct element* wyczysc(struct element *Lista)
{
    struct element * wsk=Lista;
    while(Lista!=NULL)
    {
        Lista=Lista->next;
        free(wsk);
        wsk=Lista;
    }
    return NULL;
}
//dodawanie na koniec
struct element* dodajk(struct element*Lista, int a)
{
    struct element * wsk ;
    if(Lista==NULL)
    {
        wsk=malloc(sizeof(struct element));
        Lista=wsk;
    }
    else
    {
        wsk=Lista;
        while(wsk->next!=NULL)
        {
            wsk=wsk->next;
        }
        wsk->next=malloc(sizeof(struct element));
        wsk=wsk->next;
    }
    wsk->i=a;
    wsk->next=NULL;
    return Lista;
}
//usuwanie elementu a
struct element* usun(struct element* Lista, int a)
{
    if (Lista==NULL)
        return Lista;
    struct element*wsk,*wsk2;
    wsk=Lista;
    if (Lista->i==a)
    {
        Lista=Lista->next;
        free(wsk);
    }
    else
    {
        while((wsk->next!=NULL)&&(wsk->next->i!=a))
        {
            wsk=wsk->next;
        }
        if(wsk->next!=NULL)
        {
            wsk2=wsk->next;
            wsk->next=wsk2->next;
            free(wsk2);
        }
    }
    return Lista;
};

//usun ostatni element nieparzysty
struct element* usunniep(struct element* Lista)
{
    int niep;

    if (Lista==NULL)
        return Lista;

    struct element*wsk,*wsk2;

    struct element*temp=Lista;
    while(temp!=NULL)
    {
        if((temp->i) % 2 != 0)
        {
            niep = temp->i;
        }
        temp=temp->next;
    }
    wsk=Lista;
    if (Lista->i==niep)
    {
        Lista=Lista->next;
        free(wsk);
    }
    else
    {
        while((wsk->next!=NULL)&&(wsk->next->i!=niep))
        {
            wsk=wsk->next;
        }
        if(wsk->next!=NULL)
        {
            wsk2=wsk->next;
            wsk->next=wsk2->next;
            free(wsk2);
        }
    }
    return Lista;
};
//usun pierwszy element ujemny

struct element* usunujem(struct element* Lista)
{
    int ujemn;

    if (Lista==NULL)
        return Lista;

    struct element*wsk,*wsk2;

    struct element*temp=Lista;
    while(temp!=NULL)
    {
        if(temp->i < 0)
        {
            ujemn = temp->i;
            break;
        }
    }
    wsk=Lista;
    if (Lista->i==ujemn)
    {
        Lista=Lista->next;
        free(wsk);
    }
    else
    {
        while((wsk->next!=NULL)&&(wsk->next->i!=ujemn))
        {
            wsk=wsk->next;
        }
        if(wsk->next!=NULL)
        {
            wsk2=wsk->next;
            wsk->next=wsk2->next;
            free(wsk2);
        }
    }
    return Lista;
};
//czy suma szescianow elementow listy jest rowna
int rowneszesciany(struct element*Lista1, struct element*Lista2 )
{
    int suma1=0 , suma2 = 0;
    struct element*temp1=Lista1;
    struct element*temp2=Lista2;

    while(temp1!=NULL)
    {
        suma1 += (temp1->i * temp1->i * temp1->i);
        temp1=temp1->next;
    }

    while(temp2!=NULL)
    {
        suma2 += (temp2->i * temp2->i * temp2->i);
        temp2=temp2->next;
    }
    if(suma1==suma2) return 1;
    else
        return 0;
}

//tworzymy tablice z elementami w odwrotnej kolejnosci
int *stworztablice(struct element*Lista)
{
    int *tab = (int*) malloc(sizeof(int*)*5);
    int j = 4;
    struct element*temp1=Lista;
    if (Lista==NULL)
        return NULL;
    while(temp1!=NULL)
    {
        tab[j] = temp1->i;
        j--;
        temp1=temp1->next;
    }
    return tab;
}
//mnozymy kazdy element przez liczbe w
struct element* pomnoz(struct element*Lista, int w)
{
    struct element * wsk=Lista;
    while(wsk!=NULL)
    {
        wsk->i *= w;
        wsk=wsk->next;
    }
    return Lista;
}

int main()
{
    struct element* l1 = utworz();
    l1 = dodaj(l1,-20);
    l1 = dodaj(l1,-15);
    l1 = dodaj(l1,-7);
    l1 = dodaj(l1,-31);
    struct element * wsk = l1;
    while(wsk!=NULL)
    {
        printf("%d\n",wsk->i);
        wsk=wsk->next;
    }
    printf("\n\n najmniejsza parzysta liczba to: %d",znajdzminimumparzyste(l1));
    printf("\n\n ostatnia liczba nieparzysta to: %d",znajdzostniep(l1));
    printf("\n\n lista po: \n");
    l1 = usunniep(l1);
    wyswietlListeBezGlowy(l1);
    l1 = usunujem(l1);
    wyswietlListeBezGlowy(l1);
    struct element* l2 = utworz();
    l2 = dodaj(l2,-1);
    l2 = dodaj(l2,1);
    l2 = dodaj(l2,8);
    l2 = dodaj(l2,-8);
    l2 = dodaj(l2,-4);
    wyswietlListeBezGlowy(l2);

    struct element* l3 = utworz();
    l3 = dodaj(l3,-1);
    l3 = dodaj(l3,1);
    l3 = dodaj(l3,8);
    wyswietlListeBezGlowy(l2);
    printf("\nczy sumy szescianow sa rowne: %d", rowneszesciany(l3,l2));

    printf("\n------------------------\n");

    struct element* l5 = utworz();
    struct element* l7 = utworz();
    l5 = dodaj(l5,11);
    l5 = dodaj(l5,10);
    l5 = dodaj(l5,1);
    wyswietlListeBezGlowy(l5);
    l5 = pomnoz(l5,4);
    wyswietlListeBezGlowy(l5);

    printf("\n------------------------\n");
    wyswietlListeBezGlowy(l2);
    printf("\nnajmniejszy ujemny : %d", najniepuj(l2));

    //tworzymy tablice
    printf("\n------------------------\n");
    wyswietlListeBezGlowy(l2);

    printf("\ntablica : %p", stworztablice(l7));
    int *tablica1 = stworztablice(l2);
    for(int j=0;j<5;j++)
    {
        printf("\n%d", tablica1[j]);
    }
    return 0;
}
