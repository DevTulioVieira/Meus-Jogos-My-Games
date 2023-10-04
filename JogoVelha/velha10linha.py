vez=2; empate=0;palavra="X";num=[" "," "," "," "," "," "," "," "," "," "]
while True:
    print("JOGO DA VELHA\n",num[7],"|",num[8],"|",num[9],"\n",num[4],"|",num[5],"|",num[6],"\n",num[1],"|",num[2],"|",num[3])
    if vez==2: vez=1;palavra="X"
    else: vez=2; palavra="O"    
    while True:
        numero=int(input(f"Jogador {vez} digite a jogada: "))
        if numero>0 and numero<10 and num[numero]==" ": num[numero]=palavra;empate+=1;break
    if num[1]==num[2]==num[3]!=" " or num[4]==num[5]==num[6]!=" " or num[7]==num[8]==num[9]!=" " or num[7]==num[4]==num[1]!=" " or num[8]==num[5]==num[2]!=" " or num[9]==num[6]==num[3]!=" " or num[1]==num[5]==num[9]!=" " or num[7]==num[5]==num[3]!=" ": empate=int(input(f"Jogador {vez} ganhou! Deseja jogar novamente? tecle 9: "))
    if empate==9: print("reiniciando partida");num=[" "," "," "," "," "," "," "," "," "," "]; vez=2; vdd=0;empate=0