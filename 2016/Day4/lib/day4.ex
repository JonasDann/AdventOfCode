defmodule Day4 do
    def main(args) do
        rooms = String.split(elem(File.read("input.txt"), 1), "\r\n")
        IO.puts "Valid room id sum: " <> Integer.to_string(getValidRoomIDSum(rooms, 0))
        IO.puts "North pole object store id: " <> getNorthPoleObjectStoreID(rooms)
    end

    def getValidRoomIDSum(rooms, sum) do
        unless rooms == [] do
            [room | remainingRooms] = rooms
            getValidRoomIDSum(remainingRooms, sum + getIDIfIsValid(room))
        else
            sum
        end
    end

    def getNorthPoleObjectStoreID(rooms) do
        unless rooms == [] do
            [room | remainingRooms] = rooms
            %{"name" => name, "id" => id, "checksum" => checksum} = Regex.named_captures(~r/(?<name>[a-z,-]+)-(?<id>[0-9]+)\[(?<checksum>[a-z]+)\]/, room)
            if isValidRoom(name, checksum) do
                rotation = rem(elem(Integer.parse(id), 0), 26)
                decryptedName = to_string(Enum.map(to_char_list(name), fn char -> if char == ?- do ?\s else rotChar(char, rotation) end end))
                if String.contains?(decryptedName, "northpole object storage") do
                    id
                else
                    getNorthPoleObjectStoreID(remainingRooms)
                end
            else
                getNorthPoleObjectStoreID(remainingRooms)
            end
        else
            ""
        end
    end

    def rotChar(char, count) do
        unless count == 0 do
            newChar = char + 1
            if newChar > ?z do
                rotChar(?a, count - 1)
            else
                rotChar(newChar, count - 1)
            end
        else
            char
        end
    end

    def isValidRoom(name, checksum) do
        charCountMap = Map.to_list(Enum.reduce(to_char_list(String.replace(name, "-", "")), Map.new(), fn(char, acc) -> Map.update(acc, char, 1, fn(x) -> x + 1 end) end))
        checksum == to_string(Enum.take(Enum.map(Enum.sort(charCountMap, fn {char1, count1}, {char2, count2} -> unless count1 == count2 do count1 > count2 else char1 < char2 end end), fn (element) -> elem(element, 0) end), 5))
    end

    def getIDIfIsValid(room) do
        %{"name" => name, "id" => id, "checksum" => checksum} = Regex.named_captures(~r/(?<name>[a-z,-]+)-(?<id>[0-9]+)\[(?<checksum>[a-z]+)\]/, room)
        if isValidRoom(name, checksum) do
            elem(Integer.parse(id), 0)
        else
            0
        end
    end
end