class Bank {

public:

    vector<long long>bal;
    int n;

    bool isValid(int x)
    {
        if(x<n&&x>=0)
        {
            return true;
        }

        return false;
    }
    Bank(vector<long long>& balance) {

        bal=balance;
        n=balance.size();
        
    }

    
    
    bool transfer(int account1, int account2, long long money) {

        if(isValid(account1-1)&&isValid(account2-1))
        {
            if(money<=bal[account1-1])
            {
                bal[account1-1]-=money;

                bal[account2-1]+=money;

                return true;
                
            }
            else
            {
                return false;
            }

        }

        return false;


        
    }
    
    bool deposit(int account, long long money) {

        if(isValid(account-1))
        {
            bal[account-1]+=money;
            return true;
        }

        return false;
        
    }
    
    bool withdraw(int account, long long money) {

         if(isValid(account-1))
        {
            if(money<=bal[account-1])
            {
                
                bal[account-1]-=money;
                return true;
            }
            else{
                return false;
            }
        }

        return false;
        
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */