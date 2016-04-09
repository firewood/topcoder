-- Google Code Jam 2016 Qualification Round
-- Problem A. Counting Sheep

import Control.Monad
import Data.Char
import Text.Printf

readInt = (read <$> getLine) :: IO Int

check :: Int -> Int -> Bool
check d n = elem d $ map digitToInt $ show n

findFirst :: Int -> Int -> Int
findFirst d n = head $ filter (\x -> check d x) [n, n*2..]

solve :: Int -> String
solve n = if n == 0 then "INSOMNIA" else show $ maximum $ map (\d -> findFirst d n) [0..9]

main :: IO ()
main = do
  t <- readInt
  forM_ [1..t] $ \i -> do
    n <- readInt
    printf "Case #%d: %s\n" i $ solve n
