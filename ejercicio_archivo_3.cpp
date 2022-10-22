/*3. Escriba un programa que cree un menu de opciones que permita a) abrir un archivo, b) escribir un archivo, c) leer un archivo. 
*/
#include <iostream>
#include <fstream>
using namespace std;

void write(string);
void read();


int main(int argc, char *argv[]) {
	string mensaje;
	ofstream ofs;
	ifstream ifs;
	char opcion,seguir = ' ';
	do{
		cout<<"MENU DE OPCIONES:"<<endl;
		cout<<"a) Abrir un archivo"<<endl;
		cout<<"b) Escribir un archivo"<<endl;
		cout<<"c) Leer un archivo"<<endl;
		cin>>opcion;
		switch(opcion){
		case 'a':
			{
				ofs.open("Archivo.txt");
				ofs.close();
			break;}
		case 'b':
			{
				cout<<"Ingrese un mensaje : [fin = '.']"<<endl;
				cin>>mensaje;
				write(mensaje);
				cout<<"Archivo escrito"<<endl;
				break;
			}
		case 'c':
			{
				read();
				cout<<"\nArchivo Leido"<<endl;
				break;
			}
		default:
			{
				cout<<"Ingrese una opcion correcta"<<endl;
			}
		}
		cout<<"Desea continuar con el programa"<<endl;
		cin>>seguir;
	} while(seguir=='y' || seguir=='Y');
	return 0;
}

void write(string mensaje){
	ofstream ofs;
	ofs.open("Archivo.txt");
	if(ofs.is_open()){
		ofs<<"Mensaje: "<<endl;
		ofs<<mensaje<<endl;
		ofs.close();
	} else{
		cout<<"Error al abrir el archivo"<<endl;
	}
}
void read(){
	string cadena = " ";
	ifstream ifs;
	ifs.open("Archivo.txt");
	cout<<"Contenido del archivo: "<<endl;
	while(!ifs.eof()){
		getline(ifs,cadena);
		cout<<cadena<<endl;
	}
	ifs.close();
}
