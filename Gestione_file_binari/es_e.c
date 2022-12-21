/*******************************************************************************************
* \mainpage <file_record.c>                                                                *
*                                                                                          *
* @brief <funzione che corregge un record richiesto dall'utente>                           *
*                                                                                          *
* @author <Bianchi Alessio>                                                                *
* @date <21/12/22>                                                                         *
* @version 1.0 <21/12/22> Versione iniziale                                                *
*******************************************************************************************/
void correzione(char st[], int dim,int num)
{
	s_stud buffer[dim];
	int i,n,j;

	FILE *File; 		//dichiara i puntatori
	
	srand(time(NULL));
	
	File=fopen(st,"rb"); 		//apre il file iniziale in read 

		for(i=0;i<dim;i++)
		{
			n=fread(buffer,sizeof(struct s_stud),dim,File);	
			if(i==num)
			{
				printf("inserisci le nuove informazioni:\n");
				printf("nuovo cognome:\n");
				scanf("%s",buffer[i].cog);

				for(j=0;j<V;j++)
				{
					buffer[i].voti[j]=rand()%10;
				}
				printf("\n");
				printf("inserire la nuova data di nascita:\n");
				scanf("%d",&buffer[i].nascita.gg);
				scanf("%s",buffer[i].nascita.mese);
				scanf("%d",&buffer[i].nascita.aa);
			}
			fwrite(&buffer,sizeof(struct s_stud),dim,File);
		}
			fclose(File);

}
