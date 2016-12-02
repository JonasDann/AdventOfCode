defmodule Day2 do
    def main(args) do
        input = String.split(elem(File.read("input.txt"), 1), "\r\n")
        keyCode = getKeyCode(input, "", fn(x, y) -> abs(x) > 1 || abs(y) > 1 end,
            fn(x, y) ->
                case {x, y} do
                    {-1,  1} -> "1"
                    { 0,  1} -> "2"
                    { 1,  1} -> "3"
                    {-1,  0} -> "4"
                    { 0,  0} -> "5"
                    { 1,  0} -> "6"
                    {-1, -1} -> "7"
                    { 0, -1} -> "8"
                    { 1, -1} -> "9"
                end
            end)
        IO.puts "Key code: " <> keyCode
        keyCode2 = getKeyCode(input, "", fn(x, y) -> abs(x) + abs(y) > 2 end,
            fn(x, y) ->
                case {x, y} do
                    { 0,  2} -> "1"
                    {-1,  1} -> "2"
                    { 0,  1} -> "3"
                    { 1,  1} -> "4"
                    {-2,  0} -> "5"
                    {-1,  0} -> "6"
                    { 0,  0} -> "7"
                    { 1,  0} -> "8"
                    { 2,  0} -> "9"
                    {-1, -1} -> "A"
                    { 0, -1} -> "B"
                    { 1, -1} -> "C"
                    { 0, -2} -> "D"
                end
            end)
        IO.puts "Second key code: " <> keyCode2
    end

    def getKeyCode(instructions, keys, isAtBorder, keyMap) do
        unless instructions == [] do
            [instruction | remainingInstructions] = instructions
            key = getKey(to_char_list(instruction), 0, 0, isAtBorder, keyMap)
            getKeyCode(remainingInstructions, keys <> key, isAtBorder, keyMap)
        else
            keys
        end
    end

    def getKey(instructions, x, y, isAtBorder, keyMap) do
        unless instructions == [] do
            [instruction | remainingInstructions] = instructions
            {newX, newY} = case instruction do
                ?U -> {x, y + 1}
                ?L -> {x - 1, y}
                ?R -> {x + 1, y}
                ?D -> {x, y - 1}
            end
            if isAtBorder.(newX, newY) do
                getKey(remainingInstructions, x, y, isAtBorder, keyMap)
            else
                getKey(remainingInstructions, newX, newY, isAtBorder, keyMap)
            end
        else
            keyMap.(x, y)
        end
    end


end