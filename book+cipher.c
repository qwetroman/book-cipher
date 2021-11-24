#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{

	int num,i, z, KLO;
	char massive[776462];
	char *kod, tekst[100];
	FILE *fp_cipher, *fp_cod, *fp_decoded;
	long position, cod_size;
	int n =700+rand()%100;


	srand(time(NULL));
	n = rand();
	
	fp_cod = fopen("Eden.doc.txt", "rb");
	fseek(fp_cod,n,SEEK_SET);

	if (fp_cod != NULL)
	
	
	{
	
		
		printf("You want to code(1) or decode(0): ");
		scanf("%d", &i);
		if (i == 1) {
			fp_decoded=fopen("Tekst.txt","rb");
			printf("Coding has begun\n");
			z=fread(tekst,sizeof(char),100,fp_decoded);
			
			fp_cipher = fopen("Kod.txt","wb");
			for(i=0;i<z;i++){
				num = fread(massive, sizeof(char), 776462, fp_cod);			
   				kod=strchr (massive,tolower(tekst[i]));
   				if (kod==NULL){
				   
      				kod=strchr (massive,".");
      				fprintf(fp_cipher, "%d ", kod-massive+1+n);
      				n=kod-massive+1+n;
      				fseek(fp_cod,n,SEEK_SET);
   				} else{

      				fprintf(fp_cipher, "%d ", kod-massive+1+n); 
      				n=kod-massive+1+n;
      				fseek(fp_cod,n,SEEK_SET);
      				 
			 }
			}
				fclose(fp_cod);
				fclose(fp_decoded);
				fclose(fp_cipher);

		}
		else {
				fp_cipher = fopen("Kod.txt", "r");
				fp_decoded = fopen("Tekst.txt", "w");
				
				fseek(fp_cod, 0, SEEK_END);
				cod_size = ftell(fp_cod);
				while ((fscanf(fp_cipher, "%ld", &position) != EOF)) {
					if (--position <= cod_size) {
						fseek(fp_cod, position, SEEK_SET);
						putc(getc(fp_cod), fp_decoded);
					}else{
						fprintf(fp_decoded,".");
					}
				fclose(fp_cod);
				fclose(fp_decoded);
				fclose(fp_cipher);
}
		}
	}
	else{
		printf("Ooops");
	}
	return 0;
}
