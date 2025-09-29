-- Main.hs
--
-- CECS 342 Assignment 4
-- Merge sort in Haskell
--
-- Tools used:
-- * - Compiler: gcc
-- * - Editor: VS Code
-- * - Terminal / Shell: Mac Terminal / bash
-- * - Websites: haskell.org, gemini.com, https://en.wikipedia.org/wiki/Merge_sort, https://stackoverflow.com/questions/3938438/merging-two-lists-in-haskell


module Main where

-- Merge two sorted lists into one sorted list.
merge :: Ord a => [a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys)
  | x <= y    = x : merge xs (y:ys)
  | otherwise = y : merge (x:xs) ys

-- Merge sort a list.
msort :: Ord a => [a] -> [a]
msort []  = []
msort [x] = [x]
msort xs  =
  let mid   = length xs `div` 2
      left  = take mid xs
      right = drop mid xs
  in merge (msort left) (msort right)

-- Call a sort function and print input and output.
testSort sort input = do
  putStr "Input:  "
  print input
  putStr "Sorted: "
  print (sort input)

-- Call some tests.
main = do
  putStrLn "CECS 342 Assignment 4"
  putStrLn "Name: Claus Jürgensen"
  putStrLn "Algorithm: merge sort, Language: Haskell"
  
  testSort msort ([]::[Int])
  testSort msort [1]
  testSort msort [3, 2, 1]
  testSort msort [102, -43, 5, 645, 4, 34, -6, 776, 445, 45]
  testSort msort ["the",  "quick",  "brown", "fox",
                  "jumps", "over", "the", "lazy", "dog"]