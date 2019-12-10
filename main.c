//memolitasli
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef struct n{
float altdeger;
float ustdeger;
float sinifortalamasi;
int frekans;

struct n *next;

}node;

 void hesap(node * r,float dizi[],int sayi){
int i = 0,k,sayac = 0;
int j =0;
node * iter = r;
float ekd = dizi[0];
float ebd = dizi[sayi];
printf("verileri kacli gruplandirmak istersiniz : ");
scanf("%d",&k);
float c = ((ebd - ekd) + 0.01)/k;
float gad = dizi[0];
float gud = dizi[0] + c - 0.01;
while(j<sayi){
if(r == NULL)
{

    r = (node *)malloc(sizeof(node));
    r->altdeger = dizi[0];
    r->ustdeger = gud;
    r->sinifortalamasi = (gad + gud)/2;
    while(dizi[i] <= gud)
    {
        sayac++;
        i++;
    }
    r->frekans = sayac;
    r->next = NULL;
    sayac = 0;
    gad = gad + c;
    gud = gud + c;
}
else if(r->next == NULL)
{

    node * temp = (node *)malloc(sizeof(node));
    temp->altdeger = gad;
    temp->ustdeger = gud;

    temp->sinifortalamasi = (gad + gud)/2;
    while(dizi[i]<=gud)
    {
        sayac++;
        i++;
    }
    temp->frekans = sayac;
    sayac = 0;
    gud = gud + c;
    gad = gad + c;
    r->next = temp;
    temp->next = NULL;
}


else
{
    sayac  =0;
    node * temp = (node *)malloc(sizeof(node));
    temp->altdeger = gad;
    temp->ustdeger = gud;
    while(dizi[i]<= gud)
    {
        sayac++;
        i++;
    }
    temp->frekans = sayac;
    temp->sinifortalamasi = (gad + gud)/2;
    iter = r;
    while(iter->next != NULL)
        iter = iter->next;
    iter->next = temp;
    temp->next =NULL;
    gad = gad + c;
    gud = gud + c;

}

j++;
}
node * iter2 = r;
printf("AltDeger   UstDeger   S_ort    frekans  \n\n");
for(int i = 0;i<k;i++)
{
    printf("%d %.2f  %.2f  %.2f  %d  \n",i,iter2->altdeger,iter2->ustdeger,iter2->sinifortalamasi,iter2->frekans);
    iter2 = iter2->next;
}

printf("\n\n");
float toplam = 0;
for(int i = 0;i<sayi;i++)
{
    toplam = dizi[i] + toplam;
}
float ortalama = toplam / sayi;
printf("serinin aritmetik ortalamasi : %.2f",toplam/sayi);
//mod hesaplanmasi
float As;
float d1 = 0,d2 = 0;
iter2 = r;
while(iter2->next!= NULL)
{
    if(iter2->next->frekans > d1)
    {
        d2 = iter2->frekans;
        d1 = iter2->next->frekans;
        As = iter2->next->altdeger;
    }
    iter2 = iter2->next;
}
float mod = As + c*(d1)/(d1-d2);
printf("\n mod degeri : %.2f " ,mod);


float medyan;
if(sayi %2 == 1)
    sayi++;
float L;
float F = 0;
iter2 = r;
for(int q = 0;q<sayi/2;q++)
{
    F = F+iter2->frekans;
    iter2 = iter2->next;
}
L = iter2->altdeger;
medyan = L + ((c*(sayi/2) - F)/iter2->frekans);

printf("\n medyan degeri : %.2f ",medyan);


float ss;
float tempdeger = 0;
float frekanstoplami = 0;
iter2  = r;
for(int i = 0;i<sayi;i++)
{
    tempdeger = tempdeger + pow((iter2->sinifortalamasi - ortalama), 2);
    frekanstoplami = frekanstoplami + iter2->frekans;
    iter2 = iter2->next;
}
ss = sqrt(tempdeger/frekanstoplami);
printf("\n serinin varyansi : %.2f",tempdeger / frekanstoplami);
printf("\n serinin standart sapmasi : %.2f \n ", ss);

}

int main()
{
    node * root = NULL;
    int sayi;
    printf("kac adet veri kaydi yapilacak : ");
    scanf("%d",&sayi);
    float dizi[sayi];
       for(int i = 0;i<=sayi-1;i++)
            {
            printf("\n dizinin %d . elemanini giriniz : ",i);
            scanf("%f",&dizi[i]);
            }
    while(1 ==1){

        int secim;
        printf("devam etmek icin bir tusa basiniz...");
        getch();
        system("CLS");
        printf("\n 1-> verileri listeleme \n 2-> tablo olusturma ve verilerin bilgilerini hesaplama \n seciminiz : ");
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:
             for(int i = 0;i<sayi;i++)
            {
                for(int j = 0;j<sayi-i;j++)
                {
                    if(dizi[j]>dizi[j+1])
                    {
                        float temp = dizi[j];
                        dizi[j]=dizi[j+1];
                        dizi[j+1] = temp;

                    }
                }
            }
            for(int k = 0;k<sayi;k++)
            {
                printf(" %.2f ",dizi[k]);
            }
            break;
        case 2:
            hesap(root,dizi,sayi);
            break;

        default :
            printf("\n hatali tuslama yaptiniz...");
        }
    }

    return 0;
}
