/*
6.  Escribir un programa que solicite los datos de un producto 
(nombre del producto, marca, precio unitario, fecha de elaboración, tamaño)
 y lo guarde en un archivo de texto con el nombre “Datos_Producto.txt”.
*/

#include <iostream>
#define TAM 5
using namespace std;

struct producto {
    char name[20];
    char marca[20];
    float precio;
    char fecha[20];
    int tamanio;
};

int main(void){
    struct producto p;
    FILE *fptr;
    char opcion = ' ';
    
        cout<<"Desea agregar un producto ? y/n"<<endl;
        cin>>opcion;
        if(opcion=='y'){
            cout<<"Ingrese el nombre del producto"<<endl;
            cin>>p.name;
            cout<<"Ingrese la marca del producto"<<endl;
            cin>>p.marca;
            cout<<"Ingrese el precio del producto"<<endl;
            cin>>p.precio;
            cout<<"Ingrese la fecha de elaboracion del producto"<<endl;
            cin>>p.fecha;
            cout<<"Ingrese el tamaño del producto"<<endl;
            cin>>p.tamanio;
        } else{
            exit(0);
        }
        fptr = fopen("Datos_Productos.txt","w");
        if(fptr==NULL){
            cout<<"No se puede abrir el archivo"<<endl;
            exit(1);
        }
        fputs(p.name,fptr);
        fprintf(fptr,"\n");
        fputs(p.marca,fptr);
        fprintf(fptr,"\n");
        fprintf(fptr,"%f\n",p.precio);
        fputs(p.fecha,fptr);
        fprintf(fptr,"\n");
        fprintf(fptr,"%d\n",p.tamanio);


    return 0;
}