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
#define KEY 3

void crypt(char [],char []);
void decrypt(char [],char []);

int main()
{

	char st[]={"base.txt"},st1[]={"crypt.txt"},st2[]={"decrypt.txt"};		//assegna ad ogni stringa il nome del file 

	
 	crypt(st,st1);
 	
	decrypt(st1,st2);

}

void crypt(char st[],char st1[])
{
	char c;					//dichiarazione c 
	FILE *FileIN,*FileOUT; 		//dichiara i puntatori
	
	FileIN=fopen(st,"r"); 		//apre il file iniziale in read (lettura)
	
	FileOUT=fopen(st1,"w");		//apre il file di uscita in write (scritura)
	
	if (FileIN != NULL && FileOUT != NULL)  //controlla se il puntatore è diverso da NULL 
	{
		while(!feof(FileIN))
		{
		
			c=fgetc(FileIN);			//c prende il carattere dal file iniziale
			
			if(c==' ')	
			{
				c=' ';
				fputc(c,FileOUT);
			}
			else
			{
				if((c>='A' && c<='Z') || (c>='a' && c<='z'))  //controlla se c è compreso da A alla Z e da a alla z
				{
							
					if(c=='X' || c=='Y' || c=='Z' || c=='x' || c=='y' || c=='z')  //controlla se c uguale a x,y, e z maiuscole e minuscole
					{
						c-=26;			//toglie a c 26 nel codice ascii
					}
					
					c+=KEY;			//aggiunge a c 3 nel codice ascii

				
					fputc(c,FileOUT);		//inserisce il carattere preso da c nel file destinazione	
				}
			}			
		}
	}

	else
	{
		printf("\nerrore in apertura file");
		printf("\n");
	}
		
	fclose(FileIN);			//chiude file iniziale
	fclose(FileOUT);		//chiude file destinazione
	
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
			
			if(c==' ')
			{
				c=' ';
				fputc(c,FileOUT);
			}
			else
			{
				if((c>='A' && c<'Z') || (c>='a' && c<'z'))
				{
							
					if(c=='A' || c=='B' || c=='C' || c=='a' || c=='b' || c=='c')  //controlla se c uguale a x,y, e z maiuscole e minuscole
					{
						c+=26;			//aggiunge a c 26 nel codice ascii
					}
					
					c-=KEY;			//toglie a c 3 nel codice ascii

				
					fputc(c,FileOUT);		//inserisce il carattere preso da c nel file destinazione
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
