#include <iostream>
using namespace std;

int fprintf(FILE *fptr, const char *str);
int fscanf(FILE *fptr, const char *str);

int main(int argc, char *argv[]) {
	int ii=0;
	FILE *fptr = fopen("./pares.txt","w");
	if(fptr==NULL){
		cout<<"Imposible abrir el archivo"<<endl;
		exit(0);
	}
	for(int i=0;i<101;i++){
		if(i%2==0){
			fprintf(fptr,"%d\n",i);
		}
	}
	fclose(fptr);
	cout<<"Numeros guardados"<<endl;
	fopen("./pares.txt","r");
	cout<<"Numeros pares:"<<endl;
	while(!feof(fptr)){
		fscanf(fptr,"%d\n",&ii);
		printf("%d\n",ii);
	}
	fclose(fptr);
	return 0;
}

