-- Google Code Jam 2018 Qualification Round
-- Problem A. Saving The Universe Again

import Control.Monad
import Data.Char
import Data.List
import Text.Printf

readInt = (read <$> getLine) :: IO Int

findSubstring :: Eq a => [a] -> [a] -> Maybe Int
findSubstring pat str = findIndex (isPrefixOf pat) (tails str)

total :: String -> Int -> Int -> Int
total s sum power
  | (length s) == 0 = sum
  | (head s) == 'C' = total (tail s) sum (2 * power)
  | (head s) == 'S' = total (tail s) (sum + power) power
  | otherwise = 0

f :: Int -> String -> Int -> Int
f d s t = do
  if (total (reverse s) 0 1) <= d then t else do
    case findSubstring "SC" s of
      Just x -> f d (((take x s) ++ "CS") ++ (drop (x + 2) s)) (t + 1)
      _ -> -1

solve :: Int -> String -> String
solve d s = do
  let ans = f d (reverse s) 0
  if ans < 0 then "IMPOSSIBLE" else show ans

main :: IO ()
main = do
  t <- readInt
  forM_ [1..t] $ \i -> do
    [d, s] <- words <$> getLine
    putStrLn $ "Case #" ++ (show i) ++ ": " ++ (solve (read d :: Int) s)
