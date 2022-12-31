#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int placa(int ponto1, int ponto2, int pontovelha, string jogador1, string jogador2){//imprimir o pracla
    cout<<"\t\t\tJOGO DA VELHA\n";
    cout<<jogador1 <<"\n";
    cout<<"pontos: "<<ponto1<<"\n";
    cout<<jogador2 <<"\n";
    cout<<"pontos: "<<ponto2<<"\n";
    cout<<"velha\n";
    cout<<"pontos: "<<pontovelha<<"\n";
}
int tabuleiro(string casa1, string casa2, string casa3, string casa4, string casa5, string casa6, string casa7, string casa8, string casa9){
    cout<<"-----------------\n";
    cout<<"   "<<casa7<<" || "<<casa8<<" || "<<casa9<<"\n";
    cout<<"-----------------\n";
    cout<<"   "<<casa4<<" || "<<casa5<<" || "<<casa6<<"\n";
    cout<<"-----------------\n";
    cout<<"   "<<casa1<<" || "<<casa2<<" || "<<casa3<<"\n";
    cout<<"-----------------\n";
}//imprimir o tabuleiro

int main() {
    int a=0, b=0, x, vitoria=0, ponto1=0, ponto2=0, pontovelha=0, troca=0, aux, jogadavelha=0;
    string jogador1, jogador2, valor="X";
    string casa1=" ", casa2=" ", casa3=" ", casa4=" ", casa5=" ", casa6=" ", casa7=" ", casa8=" ", casa9=" ";

    cout<<"\t\t\tJOGO DA VELHA\n";//faz o inicio da funçao pedindo informaçoes basicas
    cout<<"digite o nome do jogador 1: \n";
    cin>>jogador1;
    cout<<"digite o nome do jogador 2: \n";
    cin>>jogador2;

    system("cls");

    while(a==0){
        system("cls");//limpa tela e depois imprimi o jogo
        placa(ponto1, ponto2, pontovelha, jogador1, jogador2);
        tabuleiro(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9);
        
        aux=0;

        
        if(troca==0){//aqui diz pro jogador 1 inicia, e ja passa a vez pro proximo
            cout<<"digite sua jogada, "<<jogador1 <<"\n";
            cin>>x;
            troca=1;
        }else{
            cout<<"digite sua jogada, "<<jogador2<<"\n";
            cin>>x;
            troca=0;
        }
        //aqui sera feita a comparação se uma casa foi usado, e sera dada seu valor a ela, de acordo com a casa escolhida
        if(x==1 && casa1==" "){
            casa1=valor;
            aux=1;
        }
        if(x==2 && casa2==" "){
            casa2=valor;
            aux=1;
        }
        if(x==3 && casa3==" "){
            casa3=valor;
            aux=1;
        }
        if(x==4 && casa4==" "){
            casa4=valor;
            aux=1;
        }
        if(x==5 && casa5==" "){
            casa5=valor;
            aux=1;
        }
        if(x==6 && casa6==" "){
            casa6=valor;
            aux=1;
        }
        if(x==7 && casa7==" "){
            casa7=valor;
            aux=1;
        }
        if(x==8 && casa8==" "){
            casa8=valor;
            aux=1;
        }
        if(x==9 && casa9==" "){
            casa9=valor;
            aux=1;
        }
        //aux sera 1 somente se uma jogada for aprovada a cima, assim sera somando o valor de jogadas restante para velha, e como foi aprovada o valor de x e o sera trocado
        if(aux==1){
            jogadavelha++;
            if(valor=="X"){
                valor="O";
            }
            else{
                valor="X";
            }
        }else{
            cout<<"jogada invalida\n";//caso a jogada n seja validade ela volta o jogado q ira jogar, informa q n foi validada a jogada
            if(troca==0){
                troca=1;
            }else{
                troca=0;
            }
            system("pause");
        }
        //as proximas linhas compáram as vitoria. caso ocorra a mesma
        if(casa1=="X" && casa2=="X" && casa3=="X" || casa4=="X" && casa5=="X" && casa6=="X" || casa7=="X" && casa8=="X" && casa9=="X" || casa1=="X" && casa4=="X" && casa7=="X" || casa2=="X" && casa5=="X" && casa8=="X" || casa3=="X" && casa6=="X" && casa9=="X" || casa1=="X" && casa5=="X" && casa9=="X" || casa7=="X" && casa5=="X" && casa3=="X"){
            vitoria=1;
        }

        if(casa1=="O" && casa2=="O" && casa3=="O" || casa4=="O" && casa5=="O" && casa6=="O" || casa7=="O" && casa8=="O" && casa9=="O" || casa1=="O" && casa4=="O" && casa7=="O" || casa2=="O" && casa5=="O" && casa8=="O" || casa3=="O" && casa6=="O" && casa9=="O" || casa1=="O" && casa5=="O" && casa9=="O" || casa7=="O" && casa5=="O" && casa3=="O"){
            vitoria=1;
        }
        
        if(vitoria==1){//caso alguem ganhe ele mostrara o resultado
            if(troca==1){
                ponto1++;
            }else{
                ponto2++;
            }
            system("cls");
            placa(ponto1, ponto2, pontovelha, jogador1, jogador2);
            tabuleiro(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9);
            if(troca==1){
                cout<<"parabens ao jogador: "<<jogador1<<"\n";
            }else{
                cout<<"parabens ao jogador: "<<jogador2<<"\n";
            }
            cout<<"1-jogar novamente: \n";//aqui aparecera o menu para esolhe o futuro do jogo
            cout<<"2-reiniciar o jogo: \n";
            cout<<"3-sair: \n";
            cin>>b;
            if(b!=1 && b!=2 && b!=3){
                cout<<"houve um vencedor, reiniciando partida por informa valor fora da tabela\n";
                b=1;
                system("pause");
            }
            
        }

        if(jogadavelha==9 && vitoria==0){//caso ninguem ganhe ele emitira o placa da velha buaaa
            pontovelha++;
            system("cls");
            placa(ponto1, ponto2, pontovelha, jogador1, jogador2);
            tabuleiro(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9);
            cout<<"deu velha buaaaaa\n";
            cout<<"1-jogar novamente: \n";
            cout<<"2-reiniciar o jogo: \n";
            cout<<"3-sair: \n";
            cin>>b;
            if(b!=1 && b!=2 && b!=3){
                cout<<"houve um vencedor, reiniciando partida por informa valor fora da tabela\n";
                b=1;
                system("pause");
            }
        }

        if(b==1){//caso a opiçao joga novamente seja selecionada, ele reiniciara o jogo, resentando o tabuleiro e as funçao de calculo
            vitoria=0;
            casa1=" ", casa2=" ", casa3=" ", casa4=" ", casa5=" ", casa6=" ", casa7=" ", casa8=" ", casa9=" ";
            valor="X";
            b=0;
            jogadavelha=0;
        }
        if(b==2){//caso ele queria joga de novo mais do zero, basta ir na segunda opçao reiciniciando o jogo por completo, sem precisa fecha, sera pedido novos nomes.
            vitoria=0;
            casa1=" ", casa2=" ", casa3=" ", casa4=" ", casa5=" ", casa6=" ", casa7=" ", casa8=" ", casa9=" ";
            ponto1=0;
            ponto2=0;
            pontovelha=0;
            jogadavelha=0;
            valor="X";
            system("cls");
            cout<<"\t\t\tJOGO DA VELHA\n";
            cout<<"digite o nome do jogador 1: \n";
            cin>>jogador1;
            cout<<"digite o nome do jogador 2: \n";
            cin>>jogador2;
            b=0;
        }

        if(b==3){//caso queria sair jo game
            a=1;
        }
        
        
    }
}