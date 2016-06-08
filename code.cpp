/****************************************************************************************
从后向前匹配，遇到“.”或相等就向前移动，遇到“*”就分段
*****************************************************************************************/
class WildMatch {
public:
    bool chkWildMatch(string A, int lena, string B, int lenb) 
    {
        // write code here
        int i = lena-1;
        int j = lenb-1;
        while(i >= 0 && j>=0)
        {
            if(A[i] == B[j] || B[j]=='.')
            {
                i--;
                j--;
            }
            else if(B[j]=='*')
            {
                lenb = j;
                j--;
            }
            else
            {
                i = i-j+lenb-2;
                j = lenb-1;
            }
        }
        if(j < 0)
            return 1;
        else 
            return 0;
        
    }
};


