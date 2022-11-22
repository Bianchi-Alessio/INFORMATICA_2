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
#define MAX 50 //lunghezza 

int main()
{
	char pfile[MAX+1];   //definisce i puntatori
	char pfile2[MAX+1];	
	char c;
	
	FILE *FileIN,*FileOUT; 
	
	printf("Nome del file da leggere:");  //scelta del file da aprire
	scanf("%s",pfile);
	printf("Nome del file destinazione:");    //scelta del file destinazione da aprire
	scanf("%s",pfile2);
	
	FileIN=fopen(pfile,"r");		//apertura file in lettura
	FileOUT=fopen(pfile2,"a");		//apertura file in append
	
	if (FileIN != NULL && FileOUT != NULL)  //trova se il carattere letto è diverso da null
	{
		while(!feof(FileIN))   //coninua finche diverso dalla fine del file 
		{
			c=fgetc(FileIN);

			
			fputc(c,FileOUT);
		}
		fclose(FileIN);   //chiusura di entrambi i file
		fclose(FileOUT);
		
	}
	
	else
	printf("\nerrore in apertura file");  //avvisa se c'è un errore nell'apertura file
	printf("\n");
	system("pause");

}
