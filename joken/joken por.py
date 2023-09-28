import random 

continua=0

while continua==0:
    print("Loken porr---suas opcao")
    print('1.Pedra')
    print('2.Papel')
    print('3.tesoura')
    jogada = int(input("Sua jogada: "))
    random.seed()
    num = random.randint(1, 3)

    
    if jogada ==1:
        print('Voce escolheu Pedra')
    elif jogada ==2:
        print('Voce escolheu Papel')
    elif jogada ==3:
        print('Voce escolheu Tesoura')
        
    if num ==1:
        print('Seu oponente escolheu Pedra')
    elif num ==2:
        print('Seu oponente Papel')
    elif num ==3:
        print('Seu oponente Tesoura')
        
    if jogada == num:
        print('Empate')
    if jogada == 1 and num ==2:
        print('Voce perdeu') 
    elif jogada==1 and num == 3:
        print('Voce ganhou')
        
    if jogada == 2 and num ==3:
        print('Voce perdeu') 
    elif jogada==2 and num==1:
        print('Voce ganhou')


    valor=int(input('Joga novamente: (1.s/2.n)'))
    if valor!=1:
        continua=1
    