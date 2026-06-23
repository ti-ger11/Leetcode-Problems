class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto x:s)
        {
            if(x=='('||x=='['||x=='{')
            {
                st.push(x);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                char ch;
                ch=st.top();
                if(x==')')
                {
                    if(ch!='(')
                    {
                        return false;
                    }
                
                }
                else if(x=='}')
                {


                    if(ch!='{')
                    {
                        return false;
                    }
                
                }
                else if(x==']')
                {

                    if(ch!='[')
                    {
                        return false;
                    }
                
                }
                st.pop();
            }
        }

        if(st.empty())
        {
            return true;
        }
        return false;
    }
};