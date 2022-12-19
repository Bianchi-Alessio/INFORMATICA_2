void carica(char st[], int dim)
{
	s_stud buffer;
	int i,j,n;
	FILE *File; 		//dichiara i puntatori
	
	srand(time(NULL));
	
	File=fopen(st,"ab"); 		//apre il file iniziale in read (append)
	if(File!=NULL)
	{
		for(i=0;i<dim;i++)
		{
			n=fread(&buffer,sizeof(struct s_stud),1,File);
			//inserimento della stringa come cognome
			printf("inserire il cognome dello studente.\n");
			scanf("%s",buffer.cog);
			//inserimento voti
			for(j=0;j<V;j++)
				buffer.voti[j]=rand()%10;
			//inserimento data di nascita 
			printf("inserire la data di nascita:\n");
			scanf("%d",&buffer.nascita.gg);
			scanf("%s",buffer.nascita.mese);
			scanf("%d",&buffer.nascita.aa);
			fwrite(&buffer,sizeof(struct s_stud),1,File);
		}
		fclose(File);
	}

}
