push = require 'push'

Class = require 'class'

require 'cubo'

WINDOW_WIDTH = 1280
WINDOW_HEIGHT = 720

VIRTUAL_WIDTH = 432
VIRTUAL_HEIGHT = 243

function love.load()
    love.graphics.setDefaultFilter('nearest', 'nearest')

    love.window.setTitle('Game Memoria')

    math.randomseed(os.time())

    PeqquenaFont = love.graphics.newFont('Minecrafter.Reg.ttf', 10)
    GrandeFont = love.graphics.newFont('Minecrafter.Reg.ttf', 20)

    push:setupScreen(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT, {
        fullscreen = false,
        resizable = true,
        vsync = true
    })

    quadro1=Cubo(10, 40,VIRTUAL_WIDTH/2-10, VIRTUAL_HEIGHT/2-25)
    quadro2=Cubo(10, 41+VIRTUAL_HEIGHT/2-25, VIRTUAL_WIDTH/2-10, VIRTUAL_HEIGHT/2-25)
    quadro3=Cubo(VIRTUAL_WIDTH/2+1, 40, VIRTUAL_WIDTH/2-10, VIRTUAL_HEIGHT/2-25)
    quadro4=Cubo(VIRTUAL_WIDTH/2+1 ,41+VIRTUAL_HEIGHT/2-25, VIRTUAL_WIDTH/2-10, VIRTUAL_HEIGHT/2-25)

    dificudade=3

    numeros={}
    i=0
    num=0

    ms=1
    color={1,0,0}
    colorGREEN={0,1,0}
    a=0

    cor1=0
    cor11=0
    cor2=0
    cor22=0
    cor3=0
    cor33=0
    cor4=0
    cor44=0

    gameState = 'start'
end

function love.resize(w, h)
    push:resize(w, h)
end

function love.update(dt)
    if cor11==1 then
        cor11=0
        love.timer.sleep(0.5)
    elseif cor22==1 then
        love.timer.sleep(0.5)
        cor22=0
    else if cor33==1 then
        love.timer.sleep(0.5)
        cor33=0
    elseif cor44==1 then
        love.timer.sleep(0.5)
        cor44=0
    end
    end
end


function love.keypressed(key)
    if key == 'escape' then
        love.event.quit()
    elseif key == 'enter' or key == 'return' then
        if gameState == 'start' then
            gameState = 'inicio'
        elseif gameState == 'inicio' then
            gameState = 'carregando'
        end
    end
end

function love.array()
    numeros[num] = math.random(4)   
    love.graphics.printf(numeros[num], 10, 10, VIRTUAL_WIDTH)
    love:arrayMostra()
end

function love.arrayMostra()
    if numeros[num]==1 then
        cor11=1
        Cubo:update()
    elseif numeros[num]==2 then
        cor22=1
        Cubo:update()
    elseif numeros[num]==3 then
        cor33=1
        Cubo:update()
    elseif numeros[num]==4 then
        cor44=1
        Cubo:update()
    end
    num=num+1
end

function love.draw()

    push:apply('start')

    love.graphics.clear(40/255, 45/255, 52/255, 255/255)

    if gameState == 'start' then
        love.graphics.setFont(PeqquenaFont)
        love.graphics.printf('Jogo da Memoria!', 0, 10, VIRTUAL_WIDTH, 'center')
        love.graphics.printf('Press Enter to jogar!', 0, 20, VIRTUAL_WIDTH, 'center')
    elseif gameState == 'inicio' then
        love.graphics.setFont(PeqquenaFont)
        love.graphics.printf('preste atencao na ordem!', 0, 10, VIRTUAL_WIDTH, 'center')
        love.graphics.printf('Press Enter to jogar!', 0, 20, VIRTUAL_WIDTH, 'center')
    elseif gameState == 'carregando' then
        love.graphics.setFont(PeqquenaFont)
        love.graphics.printf('Memorize!', 0, 10, VIRTUAL_WIDTH, 'center')
        love.graphics.printf('', 0, 10, VIRTUAL_WIDTH, 'center')
        if num<dificudade and a==0 then
            love:array()
            a=1
        else 
            a=0
        end
        if gameState == 'carregando' and num==dificudade then
            gameState = 'jogando'
        end
    elseif gameState == 'jogando' then
        love.graphics.setFont(PeqquenaFont)
        love.graphics.printf('repita!', 0, 10, VIRTUAL_WIDTH, 'center')
    end

    Cubo:update()
    color=Cubo:verde(cor1)
    love.graphics.setColor(color) 
    quadro1:render()
    
    color=Cubo:verde(cor2)
    love.graphics.setColor(color) 
    quadro2:render()

    color=Cubo:verde(cor3)
    love.graphics.setColor(color) 
    quadro3:render()

    color=Cubo:verde(cor4)
    love.graphics.setColor(color) 
    quadro4:render()

    love.graphics.setFont(GrandeFont)
    love.graphics.setColor(0,0,1) 
    love.graphics.printf('1', 15, 47, VIRTUAL_WIDTH)
    love.graphics.printf('2', 15, 47+VIRTUAL_HEIGHT/2-25, VIRTUAL_WIDTH)
    love.graphics.printf('3', VIRTUAL_WIDTH/2+5, 47, VIRTUAL_WIDTH)
    love.graphics.printf('4', VIRTUAL_WIDTH/2+5, 47+VIRTUAL_HEIGHT/2-25, VIRTUAL_WIDTH)

    push:apply('end')
end