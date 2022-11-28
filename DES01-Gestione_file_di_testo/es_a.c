/** ****************************************************************************************
* \mainpage <es_a.c>
*
* @brief <trasforma i caratteri nel testo del file in entrata in caratteri maiuscoli nel file di uscita>
* 
* @author <Bianchi Alessio>
* @date <21/11/22> 
* @version 1.0 <21/11/22> Versione iniziale
* @version 1.1 <21/11/22> <nessuna modifica apportata>
*/

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
	
	FileIN=fopen(pfile,"r");
	FileOUT=fopen(pfile2,"a");
	
	if (FileIN != NULL && FileOUT != NULL)  //trova se il carattere letto è diverso da null
	{
		while(!feof(FileIN))   //coninua finche diverso dalla fine del file 
		{
			c=fgetc(FileIN);     //prende ogni carattere e controlla se compreso tra a e z
			if(c>='a' && c<='z')
			c-=32;
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
