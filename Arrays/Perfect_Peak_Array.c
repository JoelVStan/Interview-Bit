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

// This is the best approach

int Solution::perfectPeak(vector<int> &A) {
    int i;
    int n = A.size();
    int mx[n], mn[n];
    
    mx[0] = A[0];
    mn[n-1] = A[n-1];
    
    int mxx = A[0], mnn = A[n-1];
    
    for (i=1; i<n; i++)
    {
        mxx = max(mxx, A[i]);
        mx[i] = mxx;
    }
    
    for (i=n-2; i>=0; i--)
    {
        mnn = min(mnn, A[i]);
        mn[i] = mnn;
    }
    
    for(int i=1; i<n-1; i++)
    {
      if(mn[i]==mx[i] && mn[i]!=mn[i+1]&& mx[i-1]!=mx[i] && mx[i]==A[i])
      {
        return 1;
      }
    }
    return 0;
}
