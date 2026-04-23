class Solution {
public:
    struct TrieNode
    {
        unordered_map<int, TrieNode*> next;
        TrieNode()
        {
        }
    };

    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        int res = 0;
        TrieNode* root = new TrieNode();
        for (int i = 0; i < n; i++)
        {
            TrieNode* cur = root;
            int count = 0;
            for (int j = i; j < n; j++)
            {
                count += nums[j] % p == 0;
                if (count > k) break;
                if (!cur->next.count(nums[j]))
                {
                    cur->next[nums[j]] = new TrieNode();
                    res++;
                }
                cur = cur->next[nums[j]];
            }
        }
        return res;
    }
};
