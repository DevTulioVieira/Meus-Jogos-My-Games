import os
from time import sleep

cls = lambda: os.system('cls')

palavra = "eduardo"
tam=len(palavra)
teste=""
tes=""
tem=0
vida=5
tenta=""
quebrou=0

for caractere in palavra:
    teste = teste + " "

continua=0

while continua ==0:
    print("Dica: Nome proprio!  num letra:", tam, " num vidas:",vida)
    print("Descubra a palavra |",teste,"|")
    
    while quebrou!=1:
        letra = str(input("Escolha UMA letra: "))
        quebrou=len(letra)
    quebrou=0
        
    for i in range(tam):
        if palavra[i] == letra[0]:
            tes=tes+letra[0]
            tem=1
        else:
            tes=tes+teste[i]
    
    if letra[0]=="1":
        tem=1
        tenta=input("Digita a palavra completa: ")
        if tenta!=palavra:
            vida=0
        else:
            tes=tenta
    
    if tem==0:
        vida-=1
        print("Voce n acertou uma letra")
        sleep(1)
    
    tem=0
    teste=tes
    tes=""
    if teste==palavra:
        print("Voce acertou a palavra!",palavra)
        
        break
    
    if vida==0:
        print("Voce n acertou a palavra a tempo, a respota era: ", palavra)
        break
    cls()

