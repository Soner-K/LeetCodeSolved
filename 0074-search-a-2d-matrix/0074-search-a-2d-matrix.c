bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int8_t      med = 0;
    uint8_t     row = 0;
    uint8_t     left = 0;

    while (med < matrixSize)
    {
        if (matrix[med][matrixColSize[med] - 1] >= target)
            break ;
        else
            med++;
    }
    if (med == matrixSize)
        return (false);
    row = med;
    matrixSize = matrixColSize[row] - 1;
    while (left <= matrixSize)
    {
        med = left + (matrixSize - left) / 2;
        if (matrix[row][med] == target)
            return (true);
        else if (target < matrix[row][med])
            matrixSize = med - 1;
        else
            left = med + 1;
    }
    return (false);
}


