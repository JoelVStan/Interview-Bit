// This is the brute force approach. This fails in the trivial test case.

int Solution::perfectPeak(vector<int> &A) {
    int i, k, j, flag=0;
    int n = A.size();
    for (i=1;i<n-2;i++)
    {
        for(j=i;j>0;j--)
        {
            if(A[i]>A[j])
            {
                flag=1;
            }
        }
        for(k=i;k<n;k++)
        {
            if(A[i]<A[k])
            {
                flag=1;
            }
            else
                flag=0;
        }
    }
    return flag;
    
}
