#include <iostream>
using namespace std;

void mostrar(string tablero[3][3]){
    cout<<"-------------"<<endl;
    for(int i=0;i<3;i++){
        cout<<"| ";
        for(int j=0;j<3;j++){
            cout << tablero[i][j] <<" | ";
        }
        cout<<endl;
        cout<<"-------------"<<endl;
    }
}

void ponerFicha(string tablero[3][3],string pos,int turno){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(tablero[i][j]==pos){
                if(turno==1){
                    tablero[i][j]="X";
                }else{ //turno 2
                    tablero[i][j]="O";
                }
            }
        }
    }
    
}

bool comprobar(string tablero[3][3],int turno){
    bool ganar=false;
    int cont1=0;
    int cont2=0;
    int cont3=0;

    while (cont1<3) {//filas
        if(turno==1){
            if(tablero[cont1][0]==tablero[cont1][1] && tablero[cont1][0]==tablero[cont1][2] && tablero[cont1][0]=="X"){
                ganar=true;
            }

        }else{//turno 2
            if(tablero[cont1][0]==tablero[cont1][1] && tablero[cont1][0]==tablero[cont1][2] && tablero[cont1][0]=="O"){
                ganar=true;
            }
        }
        cont1++;
    }

    while (cont2<3 ){//columnas
        if(turno==1){
            if(tablero[0][cont2]==tablero[1][cont2] && tablero[0][cont2]==tablero[2][cont2] && tablero[0][cont2]=="X"){
                ganar=true;
            }
        }else{//turno 2
            if(tablero[0][cont2]==tablero[1][cont2] && tablero[0][cont2]==tablero[2][cont2] && tablero[0][cont2]=="O"){
                ganar=true;
            }
        }
        cont2++;
    }
    
    //diagonales
    if(turno==1){
        if(tablero[0][0]==tablero[1][1] && tablero[0][0]==tablero[2][2] && tablero[0][0]=="X"){
            ganar=true;
        }else if(tablero[0][2]==tablero[1][1] && tablero[0][2]==tablero[2][0] && tablero[0][2]=="X"){
            ganar=true;
        }
    }else{//turno 2
        if(tablero[0][0]==tablero[1][1] && tablero[0][0]==tablero[2][2] && tablero[0][0]=="O"){
            ganar=true;
        }else if(tablero[0][2]==tablero[1][1] && tablero[0][2]==tablero[2][0] && tablero[0][2]=="O"){
            ganar=true;
        }
    }

    return ganar;
}

int main(){
    string tablero[3][3];
    tablero[0][0]="1";
    tablero[0][1]="2";
    tablero[0][2]="3";
    tablero[1][0]="4";
    tablero[1][1]="5";
    tablero[1][2]="6";
    tablero[2][0]="7";
    tablero[2][1]="8";
    tablero[2][2]="9";
    
    mostrar(tablero);

    int cont=0;
    int num_max=9;
    bool ganar=false;
    string posicion;
    int turno;

    while (cont<num_max){
        if(cont%2==0){ //turno jugador 1
            turno=1;
            cout<<"turno del jugador 1"<<endl;
            cout<<"introduccir posicion disponible del tablero donde quieras colocar la ficha:";
            cin>>posicion;

            ponerFicha(tablero,posicion,turno);
            mostrar(tablero);
            ganar=comprobar(tablero,turno);
        }else{ //turno jugador 2
            turno=2;
            cout<<"turno del jugador 2"<<endl;
            cout<<"introduccir posicion disponible del tablero donde quieras colocar la ficha:";
            cin>>posicion;
            
            ponerFicha(tablero,posicion,turno);
            mostrar(tablero);
            ganar=comprobar(tablero,turno);
        }

        if(ganar==true){
            cout<<"Enhorabuena has ganado el juego jugador "<<turno<<endl;
            exit(0);
        }
    
        cont++;
    }

    cout<<"Se acabo el juego"<<endl;

    return 0;
}

