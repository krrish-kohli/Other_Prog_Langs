-- Main.hs
--
-- CECS 342 Assignment 5
-- Krrish Kohli
-- Generic Sorting In Haskell
-- Tools used:
-- * - Compiler: gcc, ghci, ghc
-- * - Editor: VS Code
-- * - Terminal / Shell: Mac Terminal / bash
-- * - Websites: haskell.org, gemini.com, chatgpt.com, https://en.wikipedia.org/wiki/Generic_programming, https://hackage.haskell.org/package/base-4.21.0.0/docs/Data-Ord.html#v:comparing, https://hackage.haskell.org/package/base-4.21.0.0/docs/Data-List.html#v:intercalate, https://hackage.haskell.org/package/base-4.21.0.0/docs/Data-List.html#v:sortBy


module Main where

import GenericSorting

main :: IO ()
main = do
  putStrLn "CECS 342 Assignment 5"
  putStrLn "Name: Krrish Kohli"
  putStrLn "Generic Sort, Language: Haskell"
  putStrLn ""
  putStrLn "Task a"
  putStrLn "Numbers ascending:"
  putStrLn (pNumbers (sortNumbersAscending numbers))
  putStrLn ""
  putStrLn "Task b"
  putStrLn "People by name ascending (A->Z):"
  putStrLn (pPeople (sortPeopleByName people))
  putStrLn ""
  putStrLn "Task c"
  putStrLn "People by age (desc), tie -> name (asc):"
  putStrLn (pPeople (sortPeopleByAgeDescendingNameAscending people))
  putStrLn ""