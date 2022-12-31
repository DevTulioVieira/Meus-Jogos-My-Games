import os
import sys
import random
from time import sleep

cls = lambda: os.system('cls')
lista=[]

def main():
    opcao=int(inicio())
    cls()
    if opcao == 2:
        regras()
    elif opcao == 3:
        final()
    else:
        print("*** Atenção vai começa! ***")
        
    x1=0
    x2=0
    x3=0
    x4=0
    vitoria=0
    placa=0
    dificuldade=3
    mostra(x1, x2, x3, x4)
    sleep(2)
    while vitoria == 0:
        sleep(0.5)
        ordem(x1, x2, x3, x4, dificuldade)
        vitoria=start(x1, x2, x3, x4, dificuldade)
        if vitoria == 1:
            perdeu(placa)
        else:
            dificuldade += 1
            placa += 1
            ganhou()

def ordem(x1, x2, x3, x4, dificuldade):
    random.seed()
    while dificuldade>0:
        num=random.randint(1, 4)
        lista.append(num)
        cls()
        if num==1:
            x1=1
        elif num==2:
            x2=1
        elif num==3:
            x3=1
        elif num==4:
            x4=1
        
        mostra(x1, x2, x3, x4)
        sleep(1)
        cls()
        x1=0
        x2=0
        x3=0
        x4=0
        mostra(x1, x2, x3, x4)
        sleep(0.3)
        dificuldade -= 1


def start(x1, x2, x3, x4, dificuldade):

    while dificuldade>0:
        aux=int(input("Digite a posição em ordem que acendeu: "))
        if aux==1:
            x1=1
        elif aux==2:
            x2=1
        elif aux==3:
            x3=1
        elif aux==4:
            x4=1
        vdd=lista.pop(0)
        if aux != vdd:
            return 1
        cls()
        mostra(x1, x2, x3, x4)
        sleep(0.4)
        x1=0
        x2=0
        x3=0
        x4=0
        cls()
        mostra(x1, x2, x3, x4)
        dificuldade -= 1
    
    return 0

    

def inicio():
    print("Bem vindo ao jogo da menmoria!")
    print()
    print("1.Jogar: ")
    print("2.Instruções: ")
    print("3.finalizar: ")
    return input()

def perdeu(placa):
    print("Perdeu!")
    print("Placa: ", placa)
    opcao=int(input("Digite 1 se deseja reiniciar: "))
    if opcao == 1:
        reinicio()
    else:
        final()

def ganhou():
    print("Parabens! vamos de novo °_°")
    sleep(2)
    cls()

def reinicio():
    lista.clear()
    cls()
    main()

def mostra(x1, x2, x3,x4):
    print("*** Jogo da mémoria ***")
    print("---------")
    print("-",x1,"-",x2,"-")
    print("-",x3,"-",x4,"-")
    print("---------")

def final():
    print("Obrigado por jogar!")
    print("Ate a próxima T-T")
    sys.exit()

def regras():
    print("REGRAS")
    print("_Como funciona o jogo: ")
    print("-Aparecera numeros 1, onde eles aparecerem, você jogador")
    print("decora a ordem para infomala depois")
    print("-Sempre que passa de rodada, aumenta 1 nova ordem")
    print("-Use os numeros (1, 2, 3, 4) para informa a casa")
    print("---------" "---------")
    print("- 0 - 0 -" "- 1 - 2 -")
    print("- 0 - 0 -" "- 3 - 4 -")
    print("---------" "---------")
    print("-Sendo os referente as casas")
    print("-Exemplo onde a cas 2 foi ativada, e deve decora a ordem")
    print("---------")
    print("- 0 - 1 -")
    print("- 0 - 0 -")
    print("---------")
    input("Digite uma tecla para retorna ao menu: ")
    cls()
    print("-Bom jogo S2!")
    sleep(2)
    cls()
    main()

if __name__ == "__main__":
    main()