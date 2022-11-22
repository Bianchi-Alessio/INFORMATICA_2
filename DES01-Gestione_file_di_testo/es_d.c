/****************************************************************************
*   Bianchi Alessio                	4°H                              	    *
*                                                                       	*
*                                                                         	*
*     es	file 2                                            	            *
*                                                                       	*
*                                                                       	*
*              	15/09/22                                                 	*
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main()
{
	char pfile[]={"numeri.txt"};   //dichgiarazione puntatori
	char pfile2[]={"pari.txt"};	
	char pfile3[]={"dispari.txt"};
	
	char c;
	
	FILE *FileIN,*FileOUT,*FileOUT2;   //dichgiarazione file

	
	FileIN=fopen(pfile,"r");  //apertura file in lettura
	FileOUT=fopen(pfile2,"a");  //apertura file in append
	FileOUT2=fopen(pfile3,"a");  //apertura file in append
	
	if (FileIN != NULL && FileOUT != NULL)
	{
		while(!feof(FileIN))  //controlla se il carattere è diverso dalla fine del file
		{
			c=fgetc(FileIN);

			if(c%2==0)  //controlla se il carattere letto e un numero pari o dispari
			{
				fputc(c,FileOUT);				
			}
			
			else
			{
				fputc(c,FileOUT2);				
			}

		}
		fclose(FileIN);  //chiusura di tutti i file 
		fclose(FileOUT);
		fclose(FileOUT2);		
		
	}
	
	else
	printf("\nerrore in apertura file");  //avvisa se c'è un errore nell'apertura del file
	printf("\n");
	system("pause");

}
