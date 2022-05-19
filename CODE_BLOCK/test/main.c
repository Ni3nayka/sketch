#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <malloc.h>

void f(int a[], int k, int n);                             //Номер 1
                                                           //Номер 2
void nul(int a[], int k);                                           //1
void scan(int a[], int k);                                          //2
void randomich(int a[], int k, int x, int y);                       //3
void print(int a[], int k);                                         //4
void saveTXT(int a[], int k);                                       //5
void scanTXT(int a[], int *k);                                      //6
void del(int a[], int *k, int x, int t);                            //7
void ins(int a[], int *k, int x, int t);                            //8
void equ(int *a1, int *a2, int n);
void sort1(int *m,int n,int *pr,int *sr);                            //Обычная сортировка
void sort2(int *m,int n,int *pr,int *sr);                            //Улучшенная сортировка



int main(void)
{
    int n;
    scanf("%d",&n);
    int a1[n],a2[n];
    scan(a1,n);
    print(a1,n);
    equ(a1,a2,n);
    print(a1,n);

    int *pr,*sr;
    sort1(a1,n,pr,sr);
    print(a1,n);
    printf("Обычная сортировка\n");
    printf("Количество присваиваний: %3d\n",*pr);
    printf("Количество сравнений: %6d\n\n",*sr);

    *pr=0,*sr=0;
    sort2(a2,n,pr,sr);
    printf("Улучшенная сортировка\n");
    printf("Количество присваиваний: %3d\n",*pr);
    printf("Количество сравнений: %6d\n",*sr);



    return 0;
}

void equ(int *a1, int *a2, int n){
    for(int i=0;i<n;i++) *(a2+i)=*(a1+i);
}

void sort1 (int *m,int n,int *pr,int *sr){

}


void sort2(int *m,int n,int *pr,int *sr){
    int v, k, dop;
    for(int i=0;i<n-2;i++){
        if (*(m+i) > *(m+i+1)){
            v= *(m+i+1);
            *pr++;
            for (int j = i+1; j < n-1; j++)
            {
                *(m+j) = *(m+j+1);
                *pr++;
            }
            k=find(m,v,0,i,pr,sr);
            for (int j = k; j < n; j++)
            {
                dop = *(m+j);
                *(m+j) = v;
                v = dop;
                *pr+=3;
            }
        }
        *sr++;
    }
}


int find(int *m,int s,int a,int b,int *pr,int *sr){
    int k=(b-a)/2;
    *pr++;
    if(*(m+k)<=s){
        *sr++;
        if((b-a)==1) {
            *sr++;
            return k;
        }
        else {
            *sr++;
            find(m,s,a,k,pr,sr);
        }
    }
    else{
        if((b-a)==1){
            *sr++;
            if(*(m+b)<=s){
                *sr++;
                return b;
            }
            else{
                *sr++;
                return (b+1);
            }
        }
        else {
            *sr++;
            find(m,s,k,b,pr,sr);
        }
    }

}


void nul(int a[], int k)                                    //1
{
	int i;
	for (i=0; i<k; i++)
		a[i]=0;
}

void scan(int a[], int k)                                   //2
{
    int i;
	for (i=0; i<k; i++)
		scanf("%d",a+i);
}

void randomich(int a[], int k, int x, int y)                //3
{
	int i;
	for (i=0; i<k; i++)
		a[i]=rand()/(RAND_MAX + 1.0)*(y-x+1)+x;
}

void print(int a[], int k)                                  //4
{
	int i;
	for (i=0; i<k; i++)
	{
		printf("%5d",i+1);
	}
	printf("\n");
    for (i=0; i<k; i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n");
	printf("\n");
}

void saveTXT(int a[], int k)                               //5
{
    FILE *f;
	int i;
	f=fopen("massive.txt","w");
	fprintf(f,"%d",a[0]);
	for (i=1;i<k;i++)
		fprintf(f," %d",a[i]);
	fprintf(f,"\n");
	fclose(f);
}

void scanTXT(int a[], int *k)                              //6
{
    FILE *f;
	int i=0;
	f=fopen("massive.txt","r");
	while (!feof(f))
	{
		fscanf(f,"%d",&a[i]);
		i++;
	}
	*k=i;
}

void del(int a[], int *k, int x, int t)                    //7
{
    int i;
	for (i=0;x+i+t-1<*k;i++)
		a[x+i-1]=a[x+i+t-1];
	*k-=t;
	a = (int*)realloc(a, *k * sizeof(int));
}

void ins(int a[], int *k, int x, int t)                    //8
{
	*k+=t;
	a = (int*)realloc(a, *k * sizeof(int));
    int i;
	for (i=*k-1;i>=x;i--)
		a[i]=a[i-t];
	for (i=0;i<t;i++)
		scanf("%d",a+x+i-1);
}


void f(int a[], int k, int n)                              //Номер 1
{
    int i, b[2*n];
	for(i=0;i<n;i++)
		b[i]=a[n+i];
	for(i=0;i<n;i++)
		b[i]=a[n-i-1];
	for(i=0;i<2*n;i++)
		a[i]=b[i];
}
