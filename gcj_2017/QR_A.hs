-- Google Code Jam 2017 Qualification Round
-- Problem A. Oversized Pancake Flipper

import Control.Monad
import Data.Char
import Text.Printf

readInt = (read <$> getLine) :: IO Int

rev :: String -> String
rev = map (\c -> if c == '+' then '-'; else '+')

f :: String -> Int -> Int -> Int
f s k t
  | (length s) == 0 = t
  | (head s) == '+' = f (tail s) k t
  | (length s) < k = -1
  | otherwise = f ((rev (take k s)) ++ (drop k s)) k (1 + t)

solve :: String -> Int -> String
solve s k = do
  let ans = f s k 0
  if ans < 0 then "IMPOSSIBLE" else show ans

main :: IO ()
main = do
  t <- readInt
  forM_ [1..t] $ \i -> do
    [s, k] <- words <$> getLine
    putStrLn $ "Case #" ++ (show i) ++ ": " ++ (solve s (read k :: Int))
