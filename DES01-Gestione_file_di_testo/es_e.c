/** ****************************************************************************************
* \mainpage <es_e.c>
*
* @brief <funzioni che cryptano e decryptano il testo del file base>
* 
* @author <Bianchi Alessio>
* @date <21/11/22> 
* @version 1.0 <21/11/22> Versione iniziale
* @version 1.1 <28/11/22> <aggiunta una variabile KEY alle funzioni>
*/

#include <stdio.h>
#include <stdlib.h>
#define M 50
#define KEY 3

void crypt(char [],char []);
void decrypt(char [],char []);

int main()
{

	char nome_base[]={"base.txt"},nome_crypt[]={"crypt.txt"},nome_decrypt[]={"decrypt.txt"};		//assegna ad ogni stringa il nome del file 

	
 	crypt(nome_base,nome_crypt);
 	
	decrypt(nome_crypt,nome_decrypt);

}

void crypt(char st[],char st1[])			//prende carattere per carattere dal file originale e lo crypta seconda la chiave KEY 
{
	char car;					//dichiarazione c 
	FILE *FileIN,*FileOUT; 		//dichiara i puntatori
	
	FileIN=fopen(st,"r"); 		//apre il file iniziale in read (lettura)
	
	FileOUT=fopen(st1,"w");		//apre il file di uscita in write (scritura)
	
	if (FileIN != NULL && FileOUT != NULL)  //controlla se il puntatore è diverso da NULL 
	{
		while(!feof(FileIN))
		{
		
			car=fgetc(FileIN);			//c prende il carattere dal file iniziale
			
			if(car==' ')	
			{
				car=' ';
				fputc(car,FileOUT);
			}
			else
			{
				if((car>='A' && car<='Z') || (car>='a' && car<='z'))  //controlla se c è compreso da A alla Z e da a alla z
				{
							
					if(car=='X' || car=='Y' || car=='Z' || car=='x' || car=='y' || car=='z')  //controlla se c uguale a x,y, e z maiuscole e minuscole
					{
						car-=26;			//toglie a c 26 nel codice ascii
					}
					
					car+=KEY;			//aggiunge a c 3 nel codice ascii

				
					fputc(car,FileOUT);		//inserisce il carattere preso da c nel file destinazione	
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

void decrypt(char st[],char st1[])				//prende il testo dal file carattere per carattere lo decrypta secondo una chiave(costante KEY) 
{												//il risultato sarà il testo identico a quello originale
	char car;
	FILE *FileIN,*FileOUT;
	
	FileIN=fopen(st,"r");
	FileOUT=fopen(st1,"w");
	
	if (FileIN != NULL && FileOUT != NULL)
	{
		while(!feof(FileIN))
		{
		
			car=fgetc(FileIN);
			
			if(car==' ')
			{
				car=' ';
				fputc(car,FileOUT);
			}
			else
			{
				if((car>='A' && car<'Z') || (car>='a' && car<'z'))
				{
							
					if(car=='A' || car=='B' || car=='C' || car=='a' || car=='b' || car=='c')  //controlla se c uguale a x,y, e z maiuscole e minuscole
					{
						car+=26;			//aggiunge a c 26 nel codice ascii
					}
					
					car-=KEY;			//toglie a c 3 nel codice ascii

				
					fputc(car,FileOUT);		//inserisce il carattere preso da c nel file destinazione
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

