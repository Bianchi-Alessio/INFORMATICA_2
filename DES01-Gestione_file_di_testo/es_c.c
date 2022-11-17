/****************************************************************************
*   Bianchi Alessio                	4°H                              	    *
*                                                                       	*
*                                                                         	*
*     es	file 3                                            	            *
*                                                                       	*
*                                                                       	*
*              	15/09/22                                                 	*
*****************************************************************************/
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
