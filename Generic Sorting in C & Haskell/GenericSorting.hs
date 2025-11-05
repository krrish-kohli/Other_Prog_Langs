-- GenericSorting.hs
--
-- CECS 342 Assignment 5
-- Krrish Kohli

module GenericSorting where

import Data.List (sort, sortBy, sortOn, intercalate)
import Data.Ord (comparing, Down(..))
import Text.Printf (printf)

--Person type
data Person = Person {name::String, age::Int} deriving (Eq, Show)

--Data Numbers
numbers :: [Double]
numbers = [ 645.41,    37.59,   76.41, 
              5.31, (-34.23),    1.11, 
              1.10,    23.46,  635.47, 
         (-876.32),   467.83,   62.25]

--Data People
people :: [Person]
people =   [ Person "Hal" 20, Person "Susann" 31, Person "Dwight" 19, Person "Kassandra" 21
  , Person "Lawrence" 25, Person "Cindy" 22, Person "Cory" 27, Person "Mac" 19
  , Person "Romana" 27, Person "Doretha" 32, Person "Danna" 20, Person "Zara" 23
  , Person "Rosalyn" 26, Person "Risa" 24, Person "Benny" 28, Person "Juan" 33
  , Person "Natalie" 25]


--Task numbers ascending
sortNumbersAscending :: [Double] -> [Double]
sortNumbersAscending = sort

--Task name ascending
sortPeopleByName :: [Person] -> [Person]
sortPeopleByName = sortOn name

--Task age descending and name ascending
sortPeopleByAgeDescendingNameAscending :: [Person] -> [Person]
sortPeopleByAgeDescendingNameAscending = sortBy (comparing (Down . age) <> comparing name)

-- intercalate ", " ["1.00","2.00","3.00"] == "1.00, 2.00, 3.00"
pNumbers :: [Double] -> String
pNumbers xs = intercalate ", " (map (\x -> printf "%.2f" x) xs) -- map each Double to a String, then "join" with ", "

-- Print a Person as "Name, Age"
pPerson :: Person -> String
pPerson (Person n a) = n ++ ", " ++ show a

-- intercalate "; " ["Hal, 20","Susann, 31"] == "Hal, 20; Susann, 31"
pPeople :: [Person] -> String
pPeople ps = intercalate "; " (map pPerson ps)