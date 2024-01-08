squareAndCube :: Int -> [Int]
squareAndCube n = [n, n*n, n*n*n]


mylist = [2,3]
result = mylist => squareAndCube => squareAndCube

result2 = do
    x <- mylist
    y <- squareAndCube x
    squareAndCube y
