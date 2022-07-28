void rotateMatrixHelper(vector<vector<int>> &mat, int rowStart, int colStart, int rowEnd, int colEnd)
{
    if(rowStart >= rowEnd or colStart >= colEnd)
    {
        return; 
    }

    if (rowStart >= rowEnd - 1 || colStart >= colEnd - 1)
    { 
        return; 
    }

    int previous = mat[rowStart + 1][colStart]; 
    int current;
        
    for (int i = colStart; i < colEnd; i++) 
    { 
        current = mat[rowStart][i]; 
        mat[rowStart][i] = previous; 
        previous = current; 
    } 

    rowStart++; 

    for (int i = rowStart; i < rowEnd; i++) 
    { 
        current = mat[i][colEnd-1]; 
        mat[i][colEnd-1] = previous; 
        previous = current; 
    } 
    colEnd--; 

    if (rowStart < rowEnd) 
    { 
        for (int i = colEnd - 1; i >= colStart; i--) 
        { 
            current = mat[rowEnd-1][i]; 
            mat[rowEnd-1][i] = previous; 
            previous = current; 
        } 
    } 
    rowEnd--; 

    if (colStart < colEnd) 
    { 
        for (int i = rowEnd-1; i >= rowStart; i--) 
        { 
            current = mat[i][colStart]; 
            mat[i][colStart] = previous; 
            previous = current; 
        } 
    } 
    colStart++; 

    rotateMatrixHelper(mat, rowStart, colStart, rowEnd, colEnd);

}

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
	rotateMatrixHelper(mat, 0, 0, n, m);
}