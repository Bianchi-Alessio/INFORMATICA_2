/****************************************************************************
*   Bianchi Alessio                	4°H                              	    *
*                                                                       	*
*                                                                         	*
*     es	file 4                                           	            *
*                                                                       	*
*                                                                       	*
*              	21/11/22                                                 	*
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main()
{
	char pfile[]={"numeri.txt"};
	char pfile2[]={"pari.txt"};	
	char pfile3[]={"dispari.txt"};
	
	char c;
	
	FILE *FileIN,*FileOUT,*FileOUT2;

	
	FileIN=fopen(pfile,"r");
	FileOUT=fopen(pfile2,"a");
	FileOUT2=fopen(pfile3,"a");
	
	if (FileIN != NULL && FileOUT != NULL)
	{
		while(!feof(FileIN))
		{
			c=fgetc(FileIN);

			if(c%2==0)
			{
				fputc(c,FileOUT);				
			}
			
			else
			{
				fputc(c,FileOUT2);				
			}

		}
		fclose(FileIN);
		fclose(FileOUT);
		fclose(FileOUT2);		
		
	}
	
	else
	printf("\nerrore in apertura file");
	printf("\n");
	system("pause");

}
