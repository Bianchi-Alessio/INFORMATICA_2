void ricerca(char st[],char cognome[], int dim)
{
	s_stud buffer;
	int i,n,r,eta;
	float media=0;
	FILE *File; 		//dichiara i puntatori
	
	srand(time(NULL));
	
	File=fopen(st,"rb"); 		//apre il file iniziale in read 
	n=fread(&buffer,sizeof(struct s_stud),1,File);	
	r=strcmp(buffer.cog,cognome);
		if(r==0)
		{
		for(i=0;i<V;i++)
		{
			media+=buffer.voti[i];
		}
		media=media/i;
		eta=2022-buffer.nascita.aa;
		printf("\nlo studente %s ha %d anni \n",buffer.cog,eta);
		printf("la media dei suoi voti %f\n",media);
		media=0;
		fclose(File);
		}
	}
