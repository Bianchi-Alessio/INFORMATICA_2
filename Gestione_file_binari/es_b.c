void stampaF(char st[], int dim)
{
	s_stud buffer;
	int i,j,n;
	FILE *File; 		//dichiara i puntatori
	
	File=fopen(st,"rb"); 		//apre il file iniziale in read (lettura)

	
		for(i=0;i<dim;i++)
		{
			n=fread(&buffer,sizeof(struct s_stud),1,File);
			printf("lo studente %s",buffer.cog);
			printf("i voti dello studente\n");
			
			for(j=0;j<V;j++)
				printf("%d / ",buffer.voti[j]);
				
			printf("e nato il:");
			printf("%d / ",buffer.nascita.gg);
			printf("%s / ",buffer.nascita.mese);
			printf("%d \n",buffer.nascita.aa);

		}
		fclose(File);
	}
