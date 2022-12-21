/*******************************************************************************************
* \mainpage <file_record.c>                                                                *
*                                                                                          *
* @brief <funzione che restituisce il numero di record nel file>                           *
*                                                                                          *
* @author <Bianchi Alessio>                                                                *
* @date <21/12/22>                                                                         *
* @version 1.0 <21/12/22> Versione iniziale                                                *
*******************************************************************************************/
int  quantita ( char st[], int dim)
{
	s_stud buffer[dim];										// dichiarazione  record
	int fs,ft,numr;											//fs=fseek / ft=ftell / mentre numr sono i record nel file
	int n= sizeof (buffer[dim-1]);									//n dice quanti byte occupa lo struct
	FILE* File;											
    File= fopen (st,"rb");									
	if (File!= NULL )										 
	{
		fs=fseek (File,0,2);								// il puntatore viene messo alla fine del file
		ft=ftell (File);										// restituisce la posizione del puntatore
		numr=ft/n;											// divido ft con n per trovare quanti record sono
		fclose (File);										// chiusura del file
		return numr;
	}
	else 	
	{
		printf ( "file non esistente \n " );
		return - 1 ;
	}
}
