class Solution {
public:
    bool isMatch(string s, string p) 
    {
        if(p.length()==0)
        {
            if(s.length()==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            bool dp[p.length()][s.length()+1];
            if(p[0]=='*')
            {
                for(int j=0;j<=s.length();j++)
                {
                    dp[0][j]=true;
                }
            }
            else if(p[0]=='?'||p[0]==s[0])
            {
                dp[0][0]=false;
                if(s.length()>=1)
                {
                    dp[0][1]=true;
                    for(int j=2;j<=s.length();j++)
                    {
                        dp[0][j]=false;
                    }
                }
            }
            else
            {
                return false;
            }
            for(int i=1;i<p.length();i++)
            {
                if(p[i]=='*')
                {
                    if(dp[i-1][0]==true)
                    {
                        dp[i][0]=true;
                    }
                    else
                    {
                        dp[i][0]=false;
                    }
                    for(int j=1;j<=s.length();j++)
                    {
                        if(dp[i-1][j]==true||dp[i-1][j-1]==true||dp[i][j-1]==true)
                        {
                            dp[i][j]=true;
                        }
                        else
                        {
                            dp[i][j]=false;
                        }
                    }
                }
                else if(p[i]=='?')
                {
                    dp[i][0]=false;
                    for(int j=1;j<=s.length();j++)
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                }
                else
                {
                    dp[i][0]=false;
                    for(int j=1;j<=s.length();j++)
                    {
                        if(p[i]==s[j-1])
                        {
                            dp[i][j]=dp[i-1][j-1];
                        }
                        else
                        {
                            dp[i][j]=false;
                        }
                    }
                }
            }
            return dp[p.length()-1][s.length()];
        }
    }
};
