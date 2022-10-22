/*5. Elaborar el enunciado y la solucion de un ejercio utilizando 
archivos binarios.
Ejercicio: Elaborar un programa que cuente cuantas veces se repite las 
palabras: it y you en el archivo cancion.txt y contar cuantas palabras
 leyo el programa
*/

#include <iostream>
#include <string.h>

using namespace std;

int main (void){
    FILE *fptr;
    fptr = fopen("cancion.txt","r");
    if(fptr == NULL){
        cout<<"No se puedo abrir el archivo"<<endl;
        exit(0);
    }
    int cont,it,you = 0;
    char cadena[20];
    while(fscanf(fptr,"%s",&cadena) != EOF){
        cont++;
        if(strcmp(cadena,"it") == 0){
            it++;
        }
        if(strcmp(cadena,"you") == 0 || strcmp(cadena,"You") == 0){
            you++;
        }
    }

    cout<<"La cantidad de veces que se repite:"<<endl;
    cout<<"It : "<<it<<endl;
    cout<<"You: "<<you<<endl;
    cout<<"Palabras leidas: "<<cont<<endl;

    return 0;
}