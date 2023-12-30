#include <iostream>
#include <ctime>
#include <stdio.h>
#include <vector>

using namespace std;

typedef struct matrizLista{
    int** vivo;
    int linha;
    int coluna;
    int vitoria;
    int bombas;
    int** elementos; 
}m;

int Intrucoes(){
    inicio:
    cout<<"BEM VINDO AO"<<endl;
    cout<<"CAMPO MINADO"<<endl;
    cout<<"1-Jogar"<<endl;
    cout<<"2-Como Jogar"<<endl;
    cout<<"3-Sobre"<<endl;
    cout<<"4-Sair"<<endl;
    int x;
    cin>>x;
    system("cls");
    if(x==1) return 1;
    if(x==2) return 2;
    if(x==3) return 3;
    if(x==4) exit(0);
    goto inicio;
}

int MenuReinicio(){
    mr:
    cout<<"1.Reiniciar Jogo"<<endl;
    cout<<"2.Novo Jogo"<<endl;
    cout<<"3.Sair"<<endl;
    int a;
    cin>>a;
    if (a==1)return 1;
    if (a==2)return 2;
    if (a==3)return 3;
    system("cls");
    goto mr;
}

void Sobre(){
    cout<<"Campo Minado: As regras do Campo Minado sao simples: Se voce descobrir uma mina, o jogo acaba."<<endl;
    cout<<"Se descobrir um quadrado vazio, o jogo continua."<<endl;
    cout<<"Se aparecer um numero, ele informara quantas minas estao escondidas nos oito quadrados que o cercam"<<endl<<endl;
    cout<<"Desenvolvedores: Tulio Vieira da Silva, GitHub: https://github.com/DevTulioVieira/"<<endl;
    cout<<"Disponivel em:   https://github.com/DevTulioVieira/Meus-Jogos-My-Games/tree/main/CampoMinado"<<endl;
    cout<<"Sobre:           Linguagem C++, Editor VsCode Studio, Data Inicio 27/07/2023, Idealizador Tulio Vieira da Silva"<<endl;
    system("pause");
    system("cls");
}

void ComoJogar(){
    system("pause");
    system("cls");
}

int Dificuldade(){
    inicio:
    cout<<"Selecione a dificuldade!"<<endl;
    cout<<"1-Facil"<<endl;
    cout<<"3-Medio"<<endl;
    cout<<"3-Dificil"<<endl;
    cout<<"4-Personalizado"<<endl;
    cout<<"5-Volta"<<endl;
    int x;
    cin>>x;
    system("cls");
    if(x==1) return 1;
    if(x==2) return 2;
    if(x==3) return 3;
    if(x==4) return 4;
    if(x==5) return 5;
    goto inicio;
}

int Modo(){
    inicio:
    cout<<"Selecione o modo!"<<endl;
    cout<<"1-Novo Jogo"<<endl;
    cout<<"2-Reinicia Ultimo Jogo"<<endl;
    cout<<"3-Voltar"<<endl;
    int x;
    cin>>x;
    system("cls");
    if(x==1) return 1;
    if(x==2) return 2;
    if(x==3) return 3;
    goto inicio;
}

void IniciarMatriz(m &matriz, int x, int y){
    matriz.linha = x;
    matriz.coluna = y;

    matriz.elementos = new int*[x];
    matriz.vivo = new int*[x];

    for(int i=0; i<x; i++){
        matriz.elementos[i] = new int[y]();
        matriz.vivo[i] = new int[y]();
    }
}

void LimparMatriz(m &matriz){
    for(int i=0; i<matriz.linha; i++){
        delete[] matriz.elementos[i];
        delete[] matriz.vivo[i];
    }

    delete[] matriz.elementos;    
    delete[] matriz.vivo;    
}

void MostrarMatriz(m &matriz){
    system("cls");
    char caractere = static_cast<char>(254);
    string espaco = " ";
    string esLinha = " ";
    int max=0, correr=0, max2=0, correr2=0;
    if(matriz.coluna>9){
        max2=1;
        espaco+=" ";
    }else{
        if(matriz.coluna>99){
            max2=2;
            espaco+="  ";
        }
    }
    if(matriz.linha>9){
        max=1;
    }else{
        if(matriz.linha>99){
            max=2;
        }
    }

    while(correr<=max){
        cout<<esLinha;
        correr+=1;
    }
    cout<<esLinha;
    for(int i=0; i<matriz.coluna; i++){
        correr2=1;
        cout<<(i+1);
        while(correr2<=max2){
            cout<<esLinha;
            correr2+=1;
        }
    }
    cout<<endl;

    for(int i=0; i<matriz.linha; i++){
        if (i<9){
            correr=0;
        }else{
            if(i<100){
                correr=1;
            }else{
                correr=2;
            }
        }
        cout<<(i+1);
        while(correr<=max){
            cout<<esLinha;
            correr+=1;
        }
        for(int j=0; j<matriz.coluna; j++){
            correr2=1;
            if(matriz.vivo[i][j]==0){
                cout<<caractere;
            }else{   
                if(matriz.elementos[i][j]==9){
                    cout<<"@";
                }else{
                    cout<<matriz.elementos[i][j];
                }
            }
            while(correr2<=max2){
                cout<<esLinha;
                correr2+=1;
            }
        }
        cout<<endl;
    }
}

void AbrirLados(m &matriz, vector<int> vetx, vector<int> vety, int tam){
    vector<int> x;
    vector<int> y;
    for(int i=0; i<tam; i++){
        if((vetx[i]-1)>=0 && (vety[i]-1)>=0 and matriz.elementos[vetx[i]-1][vety[i]-1]!=9){//verificar as aberturas
            if(matriz.vivo[vetx[i]-1][vety[i]-1]==0){
                matriz.vivo[vetx[i]-1][vety[i]-1]=1;
                matriz.vitoria-=1;
                if(matriz.elementos[vetx[i]-1][vety[i]-1]==0){
                    x.push_back(vetx[i]-1);
                    y.push_back(vety[i]-1);
                }
            }
        }
        if((vetx[i]-1)>=0 && matriz.elementos[(vetx[i]-1)][vety[i]]!=9){
            if(matriz.vivo[(vetx[i]-1)][vety[i]]==0){
                matriz.vivo[(vetx[i]-1)][vety[i]]=1;
                matriz.vitoria-=1;
                if(matriz.elementos[(vetx[i]-1)][vety[i]]==0){
                    x.push_back(vetx[i]-1);
                    y.push_back(vety[i]);
                }
            }
        }
        if((vetx[i]-1)>=0 && (vety[i]+1)<matriz.linha && matriz.elementos[(vetx[i]-1)][(vety[i]+1)]!=9){
            if(matriz.vivo[(vetx[i]-1)][(vety[i]+1)]==0){
                matriz.vivo[(vetx[i]-1)][(vety[i]+1)]=1;
                matriz.vitoria-=1;
                if(matriz.elementos[(vetx[i]-1)][(vety[i]+1)]==0){
                    x.push_back(vetx[i]-1);
                    y.push_back(vety[i]+1);
                }
            }
        }
        if((vety[i]-1)>=0 && matriz.elementos[vetx[i]][(vety[i]-1)]!=9){
            if(matriz.vivo[vetx[i]][(vety[i]-1)]==0){
                matriz.vivo[vetx[i]][(vety[i]-1)]=1;
                matriz.vitoria-=1;
                if(matriz.elementos[vetx[i]][(vety[i]-1)]==0){
                    x.push_back(vetx[i]);
                    y.push_back(vety[i]-1);
                }
            }
        }
        if((vety[i]+1)<matriz.coluna && matriz.elementos[vetx[i]][(vety[i]+1)]!=9){
            if(matriz.vivo[vetx[i]][(vety[i]+1)]==0){
                matriz.vivo[vetx[i]][(vety[i]+1)]=1;
                matriz.vitoria-=1;
                if(matriz.elementos[vetx[i]][(vety[i]+1)]==0){
                    x.push_back(vetx[i]);
                    y.push_back(vety[i]+1);
                }
            }
        }
        if((vetx[i]+1)<matriz.coluna && (vety[i]-1)>=0 && matriz.elementos[(vetx[i]+1)][(vety[i]-1)]!=9){
            if(matriz.vivo[(vetx[i]+1)][(vety[i]-1)]==0){
                matriz.vivo[(vetx[i]+1)][(vety[i]-1)]=1;
                matriz.vitoria-=1;
                if(matriz.elementos[(vetx[i]+1)][(vety[i]-1)]==0){
                    x.push_back(vetx[i]+1);
                    y.push_back(vety[i]-1);
                }
            }
        }
        if((vetx[i]+1)<matriz.coluna && matriz.elementos[(vetx[i]+1)][vety[i]]!=9){
            if(matriz.vivo[(vetx[i]+1)][vety[i]]==0){
                matriz.vivo[(vetx[i]+1)][vety[i]]=1;
                matriz.vitoria-=1;
                if(matriz.elementos[(vetx[i]+1)][vety[i]]==0){
                    x.push_back(vetx[i]+1);
                    y.push_back(vety[i]);
                }
            }
        }
        if((vetx[i]+1)<matriz.coluna && (vety[i]+1)<matriz.coluna && matriz.elementos[(vetx[i]+1)][(vety[i]+1)]!=9){
            if(matriz.vivo[(vetx[i]+1)][(vety[i]+1)]==0){
                matriz.vivo[(vetx[i]+1)][(vety[i]+1)]=1;
                matriz.vitoria-=1;
                if(matriz.elementos[(vetx[i]+1)][(vety[i]+1)]==0){
                    x.push_back(vetx[i]+1);
                    y.push_back(vety[i]+1);
                }
            }
        }
    }
    vetx.clear();
    vety.clear();
    tam=x.size();
    if(tam!=0){
        AbrirLados(matriz, x, y, tam);
    }
}

void Perdeu(){
    cout<<"Perdeu!"<<endl;//finalizarr game
}

bool VerificarJogada(m &matriz, int linha, int coluna){
    if(matriz.vivo[linha][coluna]==1){
        cout<<"Casa ja aberta! Favor joga novamente!"<<endl;
        return false;
    }
    matriz.vivo[linha][coluna]=1;
    matriz.vitoria-=1;

    if(matriz.elementos[linha][coluna]==9){
        matriz.vitoria=-1;
        return false;
    }
    if(matriz.elementos[linha][coluna]!=0){
        return true;
    }
    vector<int> x={linha};
    vector<int> y={coluna};
    int tam=x.size();
    AbrirLados(matriz, x, y, tam);
    return true;
}

void vitoria(){
    cout<<"Vitoria"<<endl;
}

void reiniciar(m &matriz){
    for(int i=0; i<matriz.linha; i++){
        for(int j=0; j<matriz.linha; j++){
            matriz.vivo[i][j]=0;
        }
    }
    matriz.vitoria=matriz.linha*matriz.coluna-matriz.bombas;
}

void Jogar(m &matriz){
    int linha=-1, coluna;
    while(true){
        inicio:
        MostrarMatriz(matriz);
        if(matriz.vitoria==0){
            vitoria();
            return;
        }
        if(matriz.vitoria==-1){
            Perdeu();
            return;
        }
        if (linha!=-1)cout<<"Ultima Jogada! Linha: "<<linha+1<<"  Coluna: "<<coluna+1<<endl;
        cout<<"Digite a linha:  ";
        cin>>linha;
        cout<<"Digite a coluna: ";
        cin>>coluna;
        linha-=1;
        coluna-=1;
        if(linha<0 or linha>matriz.linha){
            if(coluna<0 or coluna<matriz.coluna){
                cout<<"Favor inserir coordenadas validas!"<<endl;
                system("pause");
                goto inicio;
            }
        }
        if(!VerificarJogada(matriz, linha, coluna)){
            system("cls");
            goto inicio;
        }
    }
}

void GeraBombas(m &matriz){
    int aux=0, x, y;
    srand(time(0));

    while(aux<matriz.bombas){
        iniciobomba:
        x=rand()%10;
        y=rand()%10;
        if(matriz.elementos[x][y]==9){
            goto iniciobomba;
        }
        matriz.elementos[x][y]=9;
        aux++;
    }
    matriz.vitoria=matriz.linha*matriz.coluna-matriz.bombas;
}

void GeraNumeros(m &matriz){
    int aux;
    for(int i=0; i<matriz.linha; i++){
        for(int j=0; j<matriz.coluna; j++){
            aux=0;
            if(matriz.elementos[i][j]!=9){
                if((i-1)>=0 && (j-1)>=0 && matriz.elementos[(i-1)][(j-1)]==9) aux+=1;
                if((i-1)>=0 && matriz.elementos[(i-1)][j]==9) aux+=1;
                if((i-1)>=0 && (j+1)<matriz.linha && matriz.elementos[(i-1)][(j+1)]==9) aux+=1;
                if((j-1)>=0 && matriz.elementos[i][(j-1)]==9) aux+=1;
                if((j+1)<matriz.coluna && matriz.elementos[i][(j+1)]==9) aux+=1;
                if((i+1)<matriz.coluna && (j-1)>=0 && matriz.elementos[(i+1)][(j-1)]==9) aux+=1;
                if((i+1)<matriz.coluna && matriz.elementos[(i+1)][j]==9) aux+=1;
                if((i+1)<matriz.coluna && (j+1)<matriz.coluna && matriz.elementos[(i+1)][(j+1)]==9) aux+=1;
                matriz.elementos[i][j]=aux;
            }
        }
    }
}

int main(){
    int modo, intro, dif, casasLinhas, casasColuna, nova;
    bool modo1=true, modo2=true, modo3=true;
    m matriz;

    while(modo1){
        intro=Intrucoes();
        switch(intro){
            case 1:
                modo2=true;
                while(modo2){
                    modo=Modo();
                    switch(modo){
                        case 1:
                            modo3=true;
                            while(modo3){
                                dif=Dificuldade();
                                switch(dif){
                                    case 1:
                                        if(nova==1){
                                            LimparMatriz(matriz);
                                            cout<<"MAtrizlimpar"<<endl;
                                            system("pause");
                                        }
                                        matriz.bombas=10;
                                        casasLinhas=10;
                                        casasColuna=10;
                                        IniciarMatriz(matriz, casasLinhas, casasColuna);
                                        GeraBombas(matriz);
                                        GeraNumeros(matriz);
                                        Jogar(matriz); 
                                        system("pause");
                                        system("cls");// finalizar ganhar, finalizar vitoria, reiniciar partida
                                        modo3=false;
                                        nova=1;
                                    break;

                                    case 2:
                                        system("cls");
                                    break;

                                    case 3:
                                        system("cls");
                                    break;

                                    case 4:
                                        system("cls");
                                    break;

                                    case 5:
                                        system("cls");
                                        break;
                                    break;

                                    case 6:
                                        system("cls");
                                        break;
                                    break;

                                    default:
                                        system("cls");
                                    break;
                                }
                            }
                        break;

                        case 2:
                            if(modo3==true){
                                cout<<"Nenhuma Partida jogada ainda!"<<endl;
                                cout<<"Favor selecionar um novo jogo!"<<endl;
                                break;
                            } 
                            reiniciar(matriz);
                            Jogar(matriz);
                            system("pause");
                            system("cls"); 
                        break;

                        case 3:
                            modo2=false;
                        break;
                    }
                }
            break;

            case 2:
                ComoJogar();
            break;

            case 3:
                Sobre();
            break;

            case 4:
                exit(0);
            break;

            default:
                system("cls");
            break;
        }
    }

    return 0;
}
