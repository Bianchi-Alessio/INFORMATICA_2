/****************************************************************************
*   Bianchi Alessio                    4°H                                  *
*                                                                           *
*                                                                           *
*         Funzioni matrici                                                  *
*                                                                           *
*                                                                           *
*                  15/09/22                                                 *
*****************************************************************************/

//inclusione librerie e costanti
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <limits.h>

#define R 10
#define C 10
#define D 10

//dichiarazione funzioni
int menu(void);

void vettore_random(int [],int n);
void matrice_random(int [][C],int r,int c);
void vettore_man(int [],int n);
void matrice_man(int [][C],int r,int c);

int main()
{
	int vet[D],mat[R][C],m,d=D,c=C,r=R; 
	
	m=menu();
	switch(m)
	{
		case 1:
	vettore_random(vet,d);	
		break;
		
		case 2:
	matrice_random(mat,r,c);	
		break;
		
		case 3:
	vettore_man(vet,d);
		break;
		
		case 4:
	matrice_man(mat,r,c);
		break;	
	}	


	return 0;	
	
}
int menu(void)
{
	int scelta;
	printf("scegli 1 per caricare la vettore casualmente\n");
	printf("scegli 2 per caricare la matrice casualmente\n");
	printf("scegli 1 per caricare la vettore manualmente\n");
	printf("scegli 2 per caricare la matrice manualmente\n");
	scanf("%d",&scelta);
	
	system ("cls");
	return scelta;
}
void vettore_random(int v[],int d)
{
	int i;
	
	srand(time(NULL));
	
	for(i=0;i<d;i++)
	{
		v[i]=rand()%1000;
	}
	
	
}
void matrice_random(int m[][C],int r,int c)
{
	int i;
	for(i=0;i<c;i++)
	{
		vettore_random(m[i][],d):	
	}		
}
void vettore_man(int v[],int d)
{
	int i;

	
	for(i=0;i<d;i++)
	{
		scanf("%d",&v[i]);
	}
	
	
}
void matrice_man(m[][C],r,c)
{
	int i;
	for(i=0;i<c;i++)
	{
		vettore_man(m[i][],d):	
	}		
}
