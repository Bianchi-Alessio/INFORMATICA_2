/*******************************************************************************************
* \mainpage <file_record.c>                                                                *
*                                                                                          *
* @brief <funzione che stampa tutti i recorde un file>                                     *
*                                                                                          *
* @author <Bianchi Alessio>                                                                *
* @date <21/12/22>                                                            
* @version 1.0 <21/12/22> Versione iniziale                                                *
*******************************************************************************************/
void stampaF(char st[], int dim)
{
	s_stud buffer[dim];
	int i,j,n;
	FILE *File; 		//dichiara i puntatori
	
	File=fopen(st,"rb"); 		//apre il file iniziale in read (lettura)

	
		for(i=0;i<dim;i++)
		{
			n=fread(buffer,sizeof(struct s_stud),dim,File);
			printf("lo studente %s ",buffer[i].cog);
			printf("i voti dello studente\n");
			
			for(j=0;j<V;j++)
				printf("%d ",buffer[i].voti[j]);
				printf("\n");
			printf("e nato il:");
			printf("%d / ",buffer[i].nascita.gg);
			printf("%s / ",buffer[i].nascita.mese);
			printf("%d \n",buffer[i].nascita.aa);
			printf("\n");
		}
		fclose(File);
	}
