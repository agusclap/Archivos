/*8.  Escribir un programa que tenga un menÃº de opciones, cada una de ellas una funciÃ³n: 
a. Cargar lista de productos en el archivo de texto . 
b. Leer la lista de productos del archivo de texto . 
Para ello deberÃ¡ crear un vector de estructura llamada "Producto" y de tamaÃ±o 3. 
La estructura "Producto" contendrÃ¡ los siguientes atributos: nombre del producto, marca, precio unitario, fecha de elaboraciÃ³n, tamaÃ±o. 
El archivo se llamarÃ¡ â€œListado_Producto.txtâ€. 
*/

#include <iostream>

using namespace std;

struct producto {
    char nombre[20];
    char marca[20];
    float precio;
    char fecha[20];
    int tamanio;
};

void cargar(FILE *fptr ,struct producto p[3]);
void leer (FILE *fptr,struct producto p[3]);

int main(void){
    FILE *fptr;
    char opcion, seguir = ' ';
    int cont = 0;
    struct producto p[3];
    do{
        cout<<"MENU DE OPCIONES:"<<endl;
        cout<<"a) Cargar lista de productos en el archivo txt"<<endl;
        cout<<"b) Leer la lista de productos del archivo txt"<<endl;
        cin>>opcion;
        switch(opcion){
            case 'a':
            {
                cargar(fptr,p);
                break;
            }
            case 'b':
            {
                leer(fptr,p);
                break;
            }
            default:
            {
                cout<<"Ingrese una opcion existente"<<endl;
            }
            cont++;
        }
        cout<<"Desea continuar cargando max[3] ? y/n"<<endl;
        cin>>seguir;
    }while(seguir=='y' || seguir =='Y' || cont == 3);


    return 0;
}

void cargar(FILE *fptr, struct producto p[3]){
    

    fptr=fopen("Listado_Producto.txt","w");
    for(int i=0;i<3;i++){
        cout<<"Ingrese el nombre del producto"<<endl;
        cin>>p[i].nombre;
        cout<<"Ingrese la marca del producto"<<endl;
        cin>>p[i].marca;
        cout<<"Ingrese el precio del producto"<<endl;
        cin>>p[i].precio;
        cout<<"Ingrese la fecha de elaboracion del producto"<<endl;
        cin>>p[i].fecha;
        cout<<"Ingrese el tamaño del producto"<<endl;
        cin>>p[i].tamanio;
    }
    for(int ii=0;ii<3;ii++){
        fputs(p[ii].nombre,fptr);
        fprintf(fptr,"\t");
        fputs(p[ii].marca,fptr);
        fprintf(fptr,"\t");
        fprintf(fptr,"%f\t",p[ii].precio);
        fputs(p[ii].fecha,fptr);
        fprintf(fptr,"\t");
        fprintf(fptr,"%d\n",p[ii].tamanio);
    }
    fclose(fptr);
}

void leer(FILE *fptr,struct producto p[3]){
    char cadena[20];
    fptr = fopen("Listado_Producto.txt","r");
    if(fptr==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    while(!feof(fptr)){
        fscanf(fptr,"%s\n",&cadena);
        cout<<cadena<<endl;
    }
    
}