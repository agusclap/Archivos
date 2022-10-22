/*4. Escriba un programa que busque dentro del archivo el_quijote.txt
 la cantidad de veces que aparecen las palabras “Quijote”, “Rocinante”
  y “Sancho”. Recuerden descargar el archivo en el mismo lugar donde
   corren el programa.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


int main(void){
    {
    FILE *fptr;
    fptr = fopen("el_quijote.txt","r");
    if(fptr==NULL){
        cout<<"El archivo no existe"<<endl;
        exit(0);
    }
    int quijote,rocinante,sancho = 0;
    char cadena[20];
    while(fscanf(fptr,"%s",&cadena) != EOF){
        if(strcmp(cadena,"Quijote") == 0){
            quijote++;
        }
        if(strcmp(cadena,"Rocinante") == 0){
            rocinante++;
        }
        if(strcmp(cadena,"Sancho") == 0){
            sancho++;
        }
    }
    fclose(fptr);
    cout<<"La cantidad de veces que se repite :"<<endl;
    cout<<"Quijote: "<<quijote<<endl;
    cout<<"Rocinante: "<<rocinante<<endl;
    cout<<"Sancho: "<<sancho<<endl;

    }

    return 0;
}
