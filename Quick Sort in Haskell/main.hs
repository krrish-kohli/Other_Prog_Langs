{-
 Main.hs

 CECS 342 Assignment 1
 Quick sort in Haskell

 Tools used:
 * - Compiler: gcc
 * - Editor: VS Code
 * - Terminal / Shell: Mac Terminal / bash
 * - Websites: haskell.org, chatgpt.com, https://en.wikipedia.org/wiki/Quicksort, https://stackoverflow.com/questions/26474892/haskell-main-function, https://stackoverflow.com/questions/67551824/how-to-make-a-multiline-comment-in-haskell
-}

module Main where

-- Quick sort a list.
qsort :: Ord a => [a] -> [a]
qsort []     = []
qsort (p:xs) = qsort [x | x <- xs, x <= p] ++ [p] ++ qsort [x | x <- xs, x > p]

-- Call a sort function and print input and output.
testSort sort input = do
  putStr "Input:  "
  print input
  putStr "Sorted: "
  print (sort input)

-- Call some tests.
main = do
  putStrLn "CECS 342 Assignment 1"
  putStrLn "Name: Krrish Kohli" 
  putStrLn "Algorithm: quick sort, Language: Haskell"
  
  testSort qsort ([]::[Int])
  testSort qsort [1]
  testSort qsort [3, 2, 1]
  testSort qsort [102, -43, 5, 645, 4, 34, -6, 776, 445, 45]
  testSort qsort ["the",  "quick",  "brown", "fox",
                  "jumps", "over", "the", "lazy", "dog"]
