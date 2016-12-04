defmodule Day3 do
    def main(args) do
        triangles = String.split(elem(File.read("input.txt"), 1), "\r\n")
        IO.puts "Valid triangles count: " <> Integer.to_string(getValidTriangles(triangles, 0))
        IO.puts "Valid column triangles count: " <> Integer.to_string(getValidColumnTriangles(triangles, 0))
    end

    def getValidTriangles(triangles, valid) do
        unless triangles == [] do
            [triangle | remainingTriangles] = triangles
            sides = Enum.sort(extractSides(triangle))
            if isTriangleValid(sides) do
                getValidTriangles(remainingTriangles, valid + 1)
            else
                getValidTriangles(remainingTriangles, valid)
            end
        else
            valid
        end
    end

    def getValidColumnTriangles(rows, valid) do
        unless rows == [] do
            [row1, row2, row3 | remainingRows] = rows
            getValidColumnTriangles(remainingRows, valid + getValidTrianglesFromRows(extractSides(row1), extractSides(row2), extractSides(row3), 0))
        else
            valid
        end
    end

    def getValidTrianglesFromRows(row1, row2, row3, valid) do
        unless row1 == [] do
            if isTriangleValid(Enum.sort([hd(row1), hd(row2), hd(row3)])) do
                getValidTrianglesFromRows(tl(row1), tl(row2), tl(row3), valid + 1)
            else
                getValidTrianglesFromRows(tl(row1), tl(row2), tl(row3), valid)
            end
        else
            valid
        end
    end

    def isTriangleValid(sides) do
        [side1, side2, side3] = sides
        side1 + side2 > side3
    end

    def extractSides(string) do
        Enum.map(String.split(String.trim(string), ~r/[ ]+/), fn(side) -> elem(Integer.parse(side), 0) end)
    end
end