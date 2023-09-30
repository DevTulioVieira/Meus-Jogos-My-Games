vez=2; empate=0;palavra="X";num=[" "," "," "," "," "," "," "," "," "," "]
while True:
    print("JOGO DA VELHA\n",num[7],"|",num[8],"|",num[9],"\n",num[4],"|",num[5],"|",num[6],"\n",num[1],"|",num[2],"|",num[3])
    if vez==2: vez=1;palavra="X"
    else: vez=2; palavra="O"    
    while True:
        numero=int(input(f"Jogador {vez} digite a jogada: "))
        if numero>0 and numero<10 and num[numero]==" ": num[numero]=palavra;empate+=1;break
    if num[1]=="X" and num[2]=="X" and num[3]=="X" or num[4]=="X" and num[5]=="X" and num[6]=="X" or num[7]=="X" and num[8]=="X" and num[9]=="X" or num[7]=="X" and num[4]=="X" and num[1]=="X" or num[8]=="X" and num[5]=="X" and num[2]=="X" or num[9]=="X" and num[6]=="X" and num[3]=="X" or num[1]=="X" and num[5]=="X" and num[9]=="X" or num[7]=="X" and num[5]=="X" and num[3]=="X" or num[1]=="O" and num[2]=="O" and num[3]=="O" or num[4]=="O" and num[5]=="O" and num[6]=="O" or num[7]=="O" and num[8]=="O" and num[9]=="O" or num[7]=="O" and num[4]=="O" and num[1]=="O" or num[8]=="O" and num[5]=="O" and num[2]=="O" or num[9]=="O" and num[6]=="O" and num[3]=="O" or num[1]=="O" and num[5]=="O" and num[9]=="O" or num[7]=="O" and num[5]=="O" and num[3]=="O": empate=int(input(f"Jogador {vez} ganhou! Deseja jogar novamente? tecle 9: "))
    if empate==9: print("reiniciando partida");num=[" "," "," "," "," "," "," "," "," "," "]; vez=2; vdd=0;empate=0