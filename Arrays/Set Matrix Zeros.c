void Solution::setZeroes(vector<vector<int> > &matrix) {
  // Brute force
  
   int m = A[0].size();
    int n = A[1].size();
    
    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==0)
            {
                for(int k=i;k<m;k++)
                {
                    A[k][j] = 0;
                }
                for(int l=j;l<n;l++)
                {
                    A[i][l] = 0;
                }
            }
        }
    }
    
    //Optimal
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
    
    
}
