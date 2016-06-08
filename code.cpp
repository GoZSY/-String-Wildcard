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
/****************************************************
 * ************************************************/
 int helper(const char *pa, const char *pb)
{
        if ( *pa=='\0' )
        {
                while(*pb == '*')
                        ++pb;
                if ( *pb )
                        return 0;
                else
                        return 1;
        }
        else if ( *pb == '\0' )
                return 0;
 
        if ( *pa == *pb )
                return helper(++pa, ++pb);
 
        if ( *pb == '.' )
                return helper(++pa, ++pb);
 
        if ( *pb == '*' )
        {
                const char *tmp = pa - 1;
                while ( *(tmp + 1) == *(pa - 1) )
                        tmp++;
                int flag = 0;
                int len = tmp - pa + 1;
                int i;
                for(i=0; i<=len; ++i)
                {
                        flag = flag || helper(pa+i, pb+1);
                }
 
                return flag;
        }
 
        if ( *pa != *pb )
                return 0;
}

