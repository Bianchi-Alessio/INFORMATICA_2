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
	char pfile[MAX+1];
	char pfile2[MAX+1];	
	char c;
	
	FILE *FileIN,*FileOUT;
	
	printf("Nome del file da leggere:");
	scanf("%s",pfile);
	printf("Nome del file destinazione:");
	scanf("%s",pfile2);
	
	FileIN=fopen(pfile,"r");
	FileOUT=fopen(pfile2,"a");
	
	if (FileIN != NULL && FileOUT != NULL)
	{
		while(!feof(FileIN))
		{
			c=fgetc(FileIN);

			
			fputc(c,FileOUT);
		}
		fclose(FileIN);
		fclose(FileOUT);
		
	}
	
	else
	printf("\nerrore in apertura file");
	printf("\n");
	system("pause");

}
