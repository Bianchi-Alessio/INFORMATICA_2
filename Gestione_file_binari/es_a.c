void carica(char st[], int dim)
{
	s_stud buffer[dim];
	int i,j,n;
	FILE *File; 		//dichiara i puntatori
	
	srand(time(NULL));
	
	File=fopen(st,"ab"); 		//apre il file iniziale in read (append)
	if(File!=NULL)
	{
		for(i=0;i<dim;i++)
		{
			//inserimento della stringa come cognome
			printf("inserire il cognome dello studente.\n");
			scanf("%s",buffer[i].cog);
			//inserimento voti
			for(j=0;j<V;j++)
				buffer[i].voti[j]=rand()%10;
			//inserimento data di nascita 
			printf("inserire la data di nascita:\n");
			scanf("%d",&buffer[i].nascita.gg);
			scanf("%s",buffer[i].nascita.mese);
			scanf("%d",&buffer[i].nascita.aa);
			printf("\n");
			fwrite(&buffer,sizeof(struct s_stud),dim,File);
		}
		fclose(File);
	}

}
