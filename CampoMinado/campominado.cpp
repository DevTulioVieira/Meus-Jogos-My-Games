#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <cstdlib>

using namespace std;

typedef struct matrizLista{
    char ponto[10][10];
    int vivo[10][10];
    int num;
    struct matrizLista *prox;
}matriz;

typedef struct Lista{
    matriz *inicio;
    matriz *fim;
}TLista;

void inicializalista(TLista *lista){
    lista->inicio=NULL;
    lista->fim=NULL;
}

int menu(){
    int aux;
    inicio:
    system("cls");
    cout<<"\t\tCampo Minado"<<endl;
    cout<<"1.Jogar uma partida."<<endl;
    cout<<"2.Sair."<<endl;
    cin>>aux;
    if(aux==1 || aux==2){ 
        return aux;
    }else{
        system("cls");
        goto inicio;
    } 
}

int nivel(){
    int aux;
    inicionivel:
    cout<<"1.Facil: Tam 10x10, Bombas 10"<<endl;//so esta funcionando o nivel 1
    cout<<"2.Medio: Tam 50x50, Bombas 50"<<endl;
    cout<<"3.Dificil: Tam 100x100, Bombas 100"<<endl;
    cin>>aux;
    if(aux==1 || aux==2 || aux==3){
        return aux;
    }else{
        system("cls");
        goto inicionivel;
    }
    
}

void bombafacil(TLista *lista, int tam){
    int aux=0, x, y, com=0;
    matriz *novo;
    novo = new matriz;
    novo->prox=NULL;
    srand(time(0));
    
    while(aux<tam){
        iniciobomba:
        x=rand()%10;
        y=rand()%10;
        
        if(novo->ponto[x][y]=='*'){
            goto iniciobomba;
        }
        novo->ponto[x][y]='*';
        aux++;
    }
    novo->num=0;

    if(lista->inicio == NULL){
        lista->inicio = novo;
    }
}

void vetor(TLista *lista, int tam){
    int i, j, soma, vdd;
    matriz *aux;
    aux=lista->inicio;
    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            soma=48;
            vdd=0;
            aux->vivo[i][j]=0;
            if(aux->ponto[i][j]!='*'){
                if(i>0 && i<tam-1 && j>0 && j<tam-1){
                    if(aux->ponto[i-1][j]=='*'){
                        soma+=1;
                    }
                    if(aux->ponto[i-1][j+1]=='*'){
                        soma+=1;
                    }
                    if(aux->ponto[i-1][j-1]=='*'){
                        soma+=1;
                    }
                    if(aux->ponto[i][j+1]=='*'){
                        soma+=1;
                    }
                    if(aux->ponto[i][j-1]=='*'){
                        soma+=1;
                    }
                    if(aux->ponto[i+1][j]=='*'){
                        soma+=1;
                    }
                    if(aux->ponto[i+1][j+1]=='*'){
                        soma+=1;
                    }
                    if(aux->ponto[i+1][j-1]=='*'){
                        soma+=1;
                    }
                }else{
                    if(i==0 && j==0 && vdd==0){//primeiro
                        if(aux->ponto[i+1][j]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i+1][j+1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i][j+1]=='*'){
                            soma+=1;
                        }
                        vdd=1;
                    }
                    if(i==tam-1 && j==0 && vdd==0){//segundo
                        if(aux->ponto[i-1][j]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i-1][j+1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i][j+1]=='*'){
                            soma+=1;
                        }
                        vdd=1;
                    }
                    if(i==0 && j==tam-1 && vdd==0){//terceiro
                        if(aux->ponto[i+1][j]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i+1][j-1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i][j-1]=='*'){
                            soma+=1;
                        }
                        vdd=1;
                    }
                    if(i==tam-1 && j==tam-1 && vdd==0){//quarto
                        if(aux->ponto[i-1][j]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i-1][j-1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i][j-1]=='*'){
                            soma+=1;
                        }
                        vdd=1;
                    }
                
                    if(j==0 && i>0 && i<tam-1 && vdd==0){//primeira lateral
                        if(aux->ponto[i+1][j]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i-1][j]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i+1][j+1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i-1][j+1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i][j+1]=='*'){
                            soma+=1;
                        }
                        vdd=1;
                    }

                    if(j==tam-1 && i>0 && i<tam-1  && vdd==0){//segunda lateral
                        if(aux->ponto[i+1][j]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i-1][j]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i+1][j-1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i-1][j-1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i][j-1]=='*'){
                            soma+=1;
                        }
                        vdd=1;
                    }
                
                    if(i==0 && j>0 && j<tam-1 && vdd==0){//terceira lateral
                        if(aux->ponto[i][j+1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i][j-1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i+1][j+1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i+1][j-1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i+1][j]=='*'){
                            soma+=1;
                        }
                        vdd=1;
                    }

                    if(i==tam-1 && j>0 && j<tam-1 && vdd==0){//quarta lateral
                        if(aux->ponto[i][j+1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i][j-1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i-1][j+1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i-1][j-1]=='*'){
                            soma+=1;
                        }
                        if(aux->ponto[i-1][j]=='*'){
                            soma+=1;
                        }
                        vdd=1;
                    }
                }
                if(soma==48){
                    aux->ponto[i][j]='0';
                }else{
                    aux->ponto[i][j]=soma;
                }    
            }
        }
    }
}

void mostra(TLista *lista, int tam, int vitoria){
    matriz *aux;
    aux=lista->inicio;
    int count, i, j, ajuda=0;
    if(aux==NULL){
        cout<<"Sem nada!"<<endl;
    }else{
        for(i=0; i<tam; i++){
            count=1;
            if(ajuda==0){
                cout<<"  |0|1|2|3|4|5|6|7|8|9|"<<endl;
                cout<<"  -----Campo Minado----"<<endl;
                ajuda=1;
            }
            cout<<i<<"-|";
            for(j=0; j<tam; j++){
                if(aux->vivo[i][j]==0 && vitoria!=2){
                    cout<<' ';
                }else{
                    cout<<aux->ponto[i][j];
                }
                cout<<"|";
                if(j==9){
                    cout<<endl;
                }
                count++;
            }
        }
    }
}

int jogo(TLista *lista, int tam){
    matriz *aux;
    aux=lista->inicio;
    int vetorx[10];
    int vetory[10];
    int x, y, numero=1, ajuda=0, maximo=1, quantidade=0, numproximo=1;
    int proximo=1, troca=1;
    int vx[10];
    int vy[10];

    cout<<"Digite a linha: ";
    cin>>x;
    cout<<"\nDigite a coluna: ";
    cin>>y;
    
    if(x<0 || x>9 || y<0 || y>9){
        cout<<"Favor inserir valor entra o intervalo (0-9)!"<<endl;
        Sleep(2000);
        system("cls");
        return 0;
    }

    if(aux->ponto[x][y]=='*'){
        return 2;
    }

    if(aux->vivo[x][y]==0){
        aux->vivo[x][y]=1;
        aux->num++;
        system("cls");
        if(aux->ponto[x][y]=='0'){
            vetorx[quantidade]=x;
            vetory[quantidade]=y;
            while(proximo==1){
                proximo=0;
                quantidade=0;
                if(troca==0){
                    troca=1;
                }else{
                    troca=0;
                }
                maximo=numero;
                numero=0;
                while(quantidade<maximo){
                    if(troca==0){
                        x=vetorx[quantidade];
                        y=vetory[quantidade];
                    }else{
                        x=vx[quantidade];
                        y=vy[quantidade];
                    }

                    if((x+1)<tam){//parte de baixo
                        if(aux->ponto[x+1][y]=='0' && aux->vivo[x+1][y]==0){
                            if(troca==1){
                                vetorx[numero]=x+1;
                                vetory[numero]=y;
                            }else{
                                vx[numero]=x+1;
                                vy[numero]=y;
                            }
                            proximo=1;
                            numero++;
                        }
                        if(aux->vivo[x+1][y]==0){
                            aux->vivo[x+1][y]=1;
                            aux->num++;
                        }
                        
                        if((y+1)<tam){
                            if(aux->ponto[x+1][y+1]=='0' && aux->vivo[x+1][y+1]==0){
                                if(troca==1){
                                    vetorx[numero]=x+1;
                                    vetory[numero]=y+1;
                                }else{
                                    vx[numero]=x+1;
                                    vy[numero]=y+1;
                                }
                                proximo=1;
                                numero++;
                            }
                            if(aux->vivo[x+1][y+1]==0){
                                aux->vivo[x+1][y+1]=1;
                                aux->num++;
                            }
                            
                        }
                        if((y-1)>=0){
                            if(aux->ponto[x+1][y-1]=='0' && aux->vivo[x+1][y-1]==0){
                                if(troca==1){
                                    vetorx[numero]=x+1;
                                    vetory[numero]=y-1;
                                }else{
                                    vx[numero]=x+1;
                                    vy[numero]=y-1;
                                }
                                proximo=1;
                                numero++;
                            }
                            if(aux->vivo[x+1][y-1]==0){
                                aux->vivo[x+1][y-1]=1;
                                aux->num++;
                            }
                        }
                    }

                    if((x-1)>=0){//parte de cima
                        if(aux->ponto[x-1][y]=='0' && aux->vivo[x-1][y]==0){
                            if(troca==1){
                                vetorx[numero]=x-1;
                                vetory[numero]=y;
                            }else{
                                vx[numero]=x-1;
                                vy[numero]=y;
                            }
                            proximo=1;
                            numero++;
                        }
                        if(aux->vivo[x-1][y]==0){
                            aux->vivo[x-1][y]=1;
                            aux->num++;
                        }
                        
                        if((y+1)<tam){
                            if(aux->ponto[x-1][y+1]=='0' && aux->vivo[x-1][y+1]==0){
                                if(troca==1){
                                    vetorx[numero]=x-1;
                                    vetory[numero]=y+1;
                                }else{
                                    vx[numero]=x-1;
                                    vy[numero]=y+1;
                                }
                                proximo=1;
                                numero++;
                            }
                            if( aux->vivo[x-1][y+1]==0){
                                aux->vivo[x-1][y+1]=1;
                                aux->num++;
                            }
                        }
                        if((y-1)>=0){
                            if(aux->ponto[x-1][y-1]=='0' && aux->vivo[x-1][y-1]==0){
                                if(troca==1){
                                    vetorx[numero]=x-1;
                                    vetory[numero]=y-1;
                                }else{
                                    vx[numero]=x-1;
                                    vy[numero]=y-1;
                                }
                                proximo=1;
                                numero++;
                            }
                            if(aux->vivo[x-1][y-1]==0){
                                aux->vivo[x-1][y-1]=1;
                                aux->num++;
                            }
                        }
                    }

                    if((y+1)<tam){//parte central
                        if(aux->ponto[x][y+1]=='0' && aux->vivo[x][y+1]==0){
                            if(troca==1){
                                vetorx[numero]=x;
                                vetory[numero]=y+1;
                            }else{
                                vx[numero]=x;
                                vy[numero]=y+1;
                            }
                            proximo=1;
                            numero++;
                        }
                        if(aux->vivo[x][y+1]==0){
                            aux->vivo[x][y+1]=1;
                            aux->num++;
                        }
                    }
                    if((y-1)>=0){//parte central
                        if(aux->ponto[x][y-1]=='0' && aux->vivo[x][y-1]==0){
                            if(troca==1){
                                vetorx[numero]=x;
                                vetory[numero]=y-1;
                            }else{
                                vx[numero]=x;
                                vy[numero]=y-1;
                            }
                            proximo=1;
                            numero++;
                        }
                        if(aux->vivo[x][y-1]==0){
                            aux->vivo[x][y-1]=1;
                            aux->num++;
                        }
                    }
                    quantidade++;
                }
            }
            
        system("cls");
        }
        cout<<aux->num<<endl;
        system("cls");
        if(aux->num==90){
            return 1;
        }
    }else{
        cout<<"A coordenada ja esta a mostra!"<<endl;
        Sleep(1000);
        system("cls");
        return 0;
    } 
    return 0;

}

void perdeu(){
    system("cls");
    cout<<"Voce acertou uma bomba!"<<endl;
    system("pause");
    system("cls");
}

void ganhou(){
    cout<<"Good WIN"<<endl;
}

void remover(TLista *lista){
    matriz *aux;
    aux=lista->inicio;
    if(lista->inicio==NULL){
        cout<<"Sem nada"<<endl;
    }else{
        lista->inicio = lista->inicio->prox;
        cout<<"excluido";
        free(aux);
    }
}

int main(){
    int dificuldade, opcao, tamfacil=10, vitoria=0;//variavel de navegaçao
    
    TLista L1;
    inicializalista(&L1);

    for(;;){
        opcao=menu();
        cout<<"Escolha a dificuldade: "<<endl;
        system("cls");
        dificuldade=nivel();
        system("cls");
        switch (dificuldade){
        case 1:
            vitoria=0;
            bombafacil(&L1, tamfacil);
            vetor(&L1, tamfacil);
            mostra(&L1, tamfacil, vitoria);
            while(vitoria==0){
                vitoria=jogo(&L1, tamfacil);
                if(vitoria==0){
                    mostra(&L1, tamfacil, vitoria);
                }else{
                    if(vitoria==1){
                        ganhou();
                        remover(&L1);
                    }else{
                        perdeu();
                        mostra(&L1, tamfacil, vitoria);
                        remover(&L1);
                    }
                }
            }
            system("pause");
            break;
        case 2:
        exit(0);
            break;
        default:
            break;
        }
    }
}