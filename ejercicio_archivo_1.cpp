/* 
1. Escriba un programa que cree un archivo binario llamado "datos_personales.txt” que 
pregunte los siguientes datos personales: nombre, apellido, dni, edad, nacionalidad. Luego abrir el archivo y mostrarlo.
*/



#include <iostream>
using namespace std;

int fputc(const char *string, FILE *fp);
char *fgets(char *string, int longitud,FILE *fp);

int main(int argc, char *argv[]) {
	char nombre[20];
	char apellido[20];
	char dni[20];
	char edad[3];
	char nacionalidad[20];
	char cadena[50];
	FILE *fp = fopen("./datos_personales.txt","w");
	if(fp==NULL)
	{
		cout<<"Imposible abrir el archivo"<<endl;
		exit(0);
	}
	
	cout<<"Ingrese el nombre:"<<endl;
	cin>>nombre;
	fputs(nombre,fp);
	cout<<"Ingrese el apellido:"<<endl;
	cin>>apellido;
	fputs(apellido,fp);
	cout<<"Ingrese el DNI:"<<endl;
	cin>>dni;
	fputs(dni,fp);
	cout<<"Ingrese la edad:"<<endl;
	cin>>edad;
	fputs(edad,fp);
	cout<<"Ingrese la nacionalidad:"<<endl;
	cin>>nacionalidad;
	fputs(nacionalidad,fp);
	fclose(fp);
	fp = fopen("./datos_personales.txt","r");
	if(fp==NULL){
		cout<<"Imposible abrir el archivo"<<endl;
		exit(0);
	}
	fgets(cadena,(50+1),fp);
	cout<<"Cadena recuperada: "<<cadena<<endl;
	return 0;
}

