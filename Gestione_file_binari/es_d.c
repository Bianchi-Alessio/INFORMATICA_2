/*******************************************************************************************
* \mainpage <file_record.c>                                                                *
*                                                                                          *
* @brief <funzione che stampa le informazioni presenti in un record>                       *      
*          <restituendo 0 se è presente,-1 se non esistente>                               *
*                                                                                          *
* @author <Bianchi Alessio>                                                                *
* @date <21/12/22>                                                                         *
* @version 1.0 <21/12/22> Versione iniziale                                                *
*******************************************************************************************/
int stampaR(char st[], int dim, int indice)
{
	s_stud buffer[dim];
	int i,n,j;
	float media=0;
	FILE *File; 		//dichiara i puntatori
	
	File=fopen(st,"rb"); 	//apre il file iniziale in read 
	
	for(i=0;i<dim;i++)
	{
		if(i==indice)
		{
			n=fread(buffer,sizeof(struct s_stud),1,File);	
			printf("stampa del record di indice %d",indice);
			printf("lo studente %s ",buffer[i].cog);
			printf("i voti dello studente\n");
			
			for(j=0;j<V;j++)
			{
				printf("%d ",buffer[i].voti[j]);
			}
			printf("\n");
			printf("e nato il:");
			printf("%d / ",buffer[i].nascita.gg);
			printf("%s / ",buffer[i].nascita.mese);
			printf("%d \n",buffer[i].nascita.aa);
			printf("\n");
		}
			fclose(File);
	}
	
}
