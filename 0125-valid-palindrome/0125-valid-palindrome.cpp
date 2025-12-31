class Solution {
public:
    bool isPalindrome(string s) {

        string ans=s;

        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);

        string s1="",s2="";

        for(auto c:ans)
        {
            if('a'<=c&&c<='z')
            {
                s1+=c;
            }
            else if('0'<=c&&c<='9')
            {
                s1+=c;
            }
        }


        s2=s1;

        reverse(s2.begin(),s2.end());

        cout<<ans<<"   "<<s1;

        if(s1==s2)
        {
            return true;
        }

      

        return false;

    }
};