defmodule Day1 do
    def main(args) do
        input = String.split(elem(File.read("input.txt"), 1), ", ")
        shortestManhattanDistance = getShortestManhattanDistance(input, 0, 0, {0, 1})
        IO.puts "Shortest Manhattan distance: " <> Integer.to_string(shortestManhattanDistance)
        firstLocationVisitedTwiceDistance = findFirstLocationVisitedTwiceDistance(input, {0, 1}, [{0, 0}])
        IO.puts "First position visited twice distance: " <> Integer.to_string(firstLocationVisitedTwiceDistance)
    end

    def getShortestManhattanDistance(instructions, x, y, direction) do
        [nextInstruction | remainingInstructions] = instructions
        [turnDirection | steps] = to_char_list(nextInstruction)
        {xDir, yDir} = direction
        newDirection = case turnDirection do
            ?R -> {yDir * -1, xDir     }
            ?L -> {yDir     , xDir * -1}
        end
        intSteps = elem(Integer.parse(to_string(steps)), 0)
        newX = x + elem(newDirection, 0) * intSteps;
        newY = y + elem(newDirection, 1) * intSteps;
        unless remainingInstructions == [] do
            getShortestManhattanDistance(remainingInstructions, newX, newY, newDirection)
        else
            abs(newX) + abs(newY)
        end
    end

    def findFirstLocationVisitedTwiceDistance(instructions, direction, path) do
        [nextInstruction | remainingInstructions] = instructions
        [turnDirection | steps] = to_char_list(nextInstruction)
        {xDir, yDir} = direction
        newDirection = case turnDirection do
            ?R -> {yDir * -1, xDir     }
            ?L -> {yDir     , xDir * -1}
        end
        intSteps = elem(Integer.parse(to_string(steps)), 0)
        {foundFirstLocation, newPath, newX, newY} = step(newDirection, intSteps, path)
        unless foundFirstLocation do
            findFirstLocationVisitedTwiceDistance(remainingInstructions, newDirection, newPath)
        else
            abs(newX) + abs(newY)
        end
    end

    def step(direction, remaining, path) do
        unless remaining == 0 do
            newX = elem(List.last(path), 0) + elem(direction, 0)
            newY = elem(List.last(path), 1) + elem(direction, 1)
            newPosition = {newX, newY}
            if hasAlready(path, newPosition) do
                {true, path, newX, newY}
            else
                step(direction, remaining - 1, path ++ [newPosition])
            end
        else
            {false, path, elem(List.last(path), 0), elem(List.last(path), 1)}
        end
    end

    def hasAlready(path, position) do
        unless path == [] do
            [oldPosition | remainingPath] = path
            if oldPosition == position do
                true
            else
                hasAlready(remainingPath, position)
            end
        else
            false
        end
    end
end