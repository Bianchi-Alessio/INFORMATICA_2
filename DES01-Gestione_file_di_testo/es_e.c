/****************************************************************************
*   Bianchi Alessio                	4°H                              	    *
*                                                                       	*
*                                                                         	*
*     es	file 5                                            	            *
*                                                                       	*
*                                                                       	*
*              	21/11/22                                                 	*
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define M 50

void crypt(char [],char []);
void decrypt(char [],char []);

int main()
{

	char st[]={"base.txt"},st1[]={"crypt.txt"},st2[]={"decrypt.txt"};

	
 	crypt(st,st1);
 	
	decrypt(st1,st2);

}

void crypt(char st[],char st1[])
{
	char c;
	FILE *FileIN,*FileOUT;
	
	FileIN=fopen(st,"r");
	
	FileOUT=fopen(st1,"a");
	
	if (FileIN != NULL && FileOUT != NULL)
	{
		while(!feof(FileIN))
		{
		
			c=fgetc(FileIN);
			
			if(c!=' ')	
			{
				if((c>='A' && c<='Z') || (c>='a' && c<='z'))
				{
			
					c+=3;
				
					if(c=='X' || c=='Y' || c=='Z' || c=='x' || c=='y' || c=='z')
					{
						c-=26;
					}
				
					fputc(c,FileOUT);				
				}
			}			
		}
	}

	else
	{
		printf("\nerrore in apertura file");
		printf("\n");
	}
		
	fclose(FileIN);
	fclose(FileOUT);
	
}

void decrypt(char st[],char st1[])
{
	char c;
	FILE *FileIN,*FileOUT;
	
	FileIN=fopen(st,"r");
	FileOUT=fopen(st1,"w");
	
	if (FileIN != NULL && FileOUT != NULL)
	{
		while(!feof(FileIN))
		{
		
			c=fgetc(FileIN);
			
			if(c=='}')	
			{
				c=' ';
				fputc(c,FileOUT);	
			}
			
			else
			{
				if((c>='A' && c<='Z') || (c>='a' && c<='z'))
				{
			
					c-=3;
				
					if((c=='X' || c=='Y' || c=='Z') || (c=='x' || c=='y' || c=='z'))
					{
						c+=26;
					}
				
					fputc(c,FileOUT);
				}
			}
		}
	}
	else
	{
		printf("\nerrore in apertura file");
		printf("\n");
	}
}
