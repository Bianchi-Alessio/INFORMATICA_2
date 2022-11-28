/** ****************************************************************************************
* \mainpage <nome del progetto>
*
* @brief <conta e stampa il numero di caratteri, righe e parole del file nomi.txt>
* 
* @author <Bianchi Alessio>
* @date <21/11/22> 
* @version 1.0 <21/11/22> Versione iniziale
* @version 1.1 <21/11/22> <nessuna modifica apportata>
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main()
{
	int contChar=0,r=0,p=0;
	char file_in[]="nomi.txt";
	char c;
	
	FILE *pfile;
	
	//printf("Nome del file da leggere:");
	//scanf("%s",pfile);
	pfile=fopen(file_in, "r");
	
	while(!feof(pfile)) //controllare la fine del file
	{	
		//leggo il carattere dal file
		c=fgetc(pfile);
		if(c>='a' && c<='z' || c>='A' && c<='Z') 
		{
			contChar++;
		}
		
		if(c==' ' || c==';' || c==',' || c=='.' || c==':' || c=='?' || c=='!' || c=='\n') 
		{
			p++;
		}
		
		if(c=='\n')
		{
			r++;
		}

	}
	fclose(pfile);
	
	printf("Caratteri letti %d\n", contChar );
	printf("\n");
	printf("parole lette %d\n",p);
	printf("\n");
	printf("righe lette %d\n",r);
	system("pause");
}
