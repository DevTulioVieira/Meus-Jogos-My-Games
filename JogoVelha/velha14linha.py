vez=2; vdd=0; continua=0;valor=0;empate=0;num=[" "," "," "," "," "," "," "," "," "," "]
while continua==0:
    print("JOGO DA VELHA\n",num[7],"|",num[8],"|",num[9],"\n",num[4],"|",num[5],"|",num[6],"\n",num[1],"|",num[2],"|",num[3])
    if vez==2:
        while True:
            jogador1=int(input("Jogador 1 digite a jogada: "))
            if jogador1>0 and jogador1<10 and num[jogador1]==" ": num[jogador1]="O"; vdd=1;vez=1;empate+=1;break
    else: 
        while True:
            jogador2=int(input("Jogador 2 digite a jogada: "))
            if jogador2>0 and jogador2<10 and num[jogador2]==" ": num[jogador2]="X"; vdd=1; vez=2;empate+=1;break         
    if num[1]=="X" and num[2]=="X" and num[3]=="X" or num[4]=="X" and num[5]=="X" and num[6]=="X" or num[7]=="X" and num[8]=="X" and num[9]=="X" or num[7]=="X" and num[4]=="X" and num[1]=="X" or num[8]=="X" and num[5]=="X" and num[2]=="X" or num[9]=="X" and num[6]=="X" and num[3]=="X" or num[1]=="X" and num[5]=="X" and num[9]=="X" or num[7]=="X" and num[5]=="X" and num[3]=="X" or num[1]=="O" and num[2]=="O" and num[3]=="O" or num[4]=="O" and num[5]=="O" and num[6]=="O" or num[7]=="O" and num[8]=="O" and num[9]=="O" or num[7]=="O" and num[4]=="O" and num[1]=="O" or num[8]=="O" and num[5]=="O" and num[2]=="O" or num[9]=="O" and num[6]=="O" and num[3]=="O" or num[1]=="O" and num[5]=="O" and num[9]=="O" or num[7]=="O" and num[5]=="O" and num[3]=="O": valor=int(input(f"Jogador {vez} ganhou! Deseja jogar novamente? tecle 1: "))
    if valor==1 or empate==9:
        print("reiniciando partida");num=[" "," "," "," "," "," "," "," "," "," "];valor=0; vez=2; vdd=0; continua=0