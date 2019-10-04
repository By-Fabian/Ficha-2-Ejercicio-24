#include <iostream>
#include <vector>
#include <iomanip>
#include <random>

using namespace std;

int main() {
    //Dimensiones de la matriz:

    int filas=0;
    int columnas=0;

    cout<<"Ingrese la camtidad de filas: "<<endl;
    cin>>filas;
    cout<<"Ingrese la cantidad decolumnas: "<<endl;
    cin>>columnas;
    cout<<endl;

    //Creacion matriz dinamica I.

    int **matriz=0;
    matriz=new int*[filas];
    for (int i = 0; i <filas; ++i) {
        matriz[i]=new int [columnas];
    }
    //Crear distribucion aleatoria de 0 y 1.

    random_device dev;
    uniform_int_distribution<int> dis(0,1);

    //cout<<distribucion<<endl;

    //Llenar la matriz dinamica I con valores aleatorios entre 0 y 1.

    for (int j = 0; j <filas; ++j) {
        for (int i = 0; i <columnas ; ++i) {
            matriz[j][i]=dis(dev);
        }
    }

    //Imprimir matriz I.

    cout<<"Matriz I: "<<endl;
    cout<<endl;
    for (int k = 0; k <filas ; ++k) {
        for (int i = 0; i <columnas ; ++i) {
            cout<<matriz[k][i];
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //Crear matriz K

    int matrizK[3][3]={{1,0,1},{0,1,0},{1,0,1}};

    //Imprimir matriz K.

    cout<<"Matriz K: "<<endl;
    cout<<endl;
    for (int k = 0; k <3 ; ++k) {
        for (int i = 0; i <3 ; ++i) {
            cout<<matrizK[k][i];
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //Crear Matriz Dinamica IK.

    int **matrizIK=0;
    matrizIK=new int*[filas];
    for (int i = 0; i <filas; ++i) {
        matrizIK[i]=new int [columnas];
    }

    //Llenar Matriz IK:

    for (int j = 0; j <filas; ++j) {
        for (int i = 0; i <columnas ; ++i) {
            matrizIK[j][i]=matriz[j][i];
        }
    }

    //Aplicar filtro de convolución.

    cout<<"Matriz Recortada: "<<endl;

    for (int l = 1; l <filas-1 ; ++l) {
        for (int i = 1; i <columnas-1 ; ++i) {
            cout<<matriz[l][i];
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for (int l = 1; l <filas-1 ; ++l) {
        for (int i = 1; i <columnas-1 ; ++i) {
            matrizIK[l][i]=(matriz[l-1][i-1]*matrizK[0][0]+
                          matriz[l-1][i]*matrizK[0][1]+
                          matriz[l-1][i+1]*matrizK[0][2]+
                          matriz[l][i-1]*matrizK[1][0]+
                          matriz[l][i]*matrizK[1][1]+
                          matriz[l][i+1]*matrizK[1][2]+
                          matriz[l+1][i-1]*matrizK[2][0]+
                          matriz[l+1][i]*matrizK[2][1]+
                          matriz[l+1][i+1]*matrizK[2][2]);
        }
    }
    //Imprimir Matriz IK.

    cout<<"Matriz IK: "<<endl;
    cout<<endl;
    for (int k = 0; k <filas ; ++k) {
        for (int i = 0; i <columnas ; ++i) {
            cout<<matrizIK[k][i];
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;



    return 0;
}