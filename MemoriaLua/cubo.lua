Cubo = Class{}

function Cubo:init(x, y, width, height)
    self.x = x
    self.y = y
    self.width = width
    self.height = height
end

function Cubo:update(dt)
    if love.keyboard.isDown('1') then
        cor1=1
    else
        cor1=0
    end

    if love.keyboard.isDown('2') then
        cor2=1
    else
        cor2=0
    end

    if love.keyboard.isDown('3') then
        cor3=1
    else
        cor3=0
    end

    if love.keyboard.isDown('4') then
        cor4=1
    else
        cor4=0
    end

    if cor11==1 then
        cor1=1
    end

    if cor22==1 then
        cor2=1
    end

    if cor33==1 then
        cor3=1
    end

    if cor44==1 then
        cor4=1
    end
end

function Cubo:verde(cor)
    if cor == 1 then
        return {0,1,0}
    else
        return {1,0,0}

    end
end

function Cubo:render()
    love.graphics.rectangle('fill', self.x, self.y, self.width, self.height)
end