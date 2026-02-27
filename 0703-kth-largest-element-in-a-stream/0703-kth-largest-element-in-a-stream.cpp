class KthLargest {
public:
    vector<int> mh;
    int K;

    void minheapify(vector<int>& a, int i)
    {
        int n = a.size();
        int l = 2*i + 1;
        int r = 2*i + 2;
        int s = i;

        if(l < n && a[l] < a[s])
            s = l;

        if(r < n && a[r] < a[s])
            s = r;

        if(s != i)
        {
            swap(a[i], a[s]);
            minheapify(a, s);
        }
    }

    void buildHeap(vector<int>& a)
    {
        for(int i = a.size()/2 - 1; i >= 0; i--)
            minheapify(a, i);
    }

    KthLargest(int k, vector<int>& nums)
    {
        K = k;

        for(int i=0;i<min(k,(int)nums.size());i++)
            mh.push_back(nums[i]);

        buildHeap(mh);

        for(int i=k;i<nums.size();i++)
        {
            if(nums[i] > mh[0])
            {
                mh[0] = nums[i];
                minheapify(mh,0);
            }
        }
    }

    int add(int val)
    {
        if(mh.size() < K)
        {
            mh.push_back(val);
            buildHeap(mh);
        }
        else if(val > mh[0])
        {
            mh[0] = val;
            minheapify(mh,0);
        }

        return mh[0];
    }
};