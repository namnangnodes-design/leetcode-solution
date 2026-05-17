class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n, -1);
        int e = edges.size();
        prob[start_node] = 1.f;
        for (int j = 0; j < n; j++)
        {
            bool update = false;
            for (int k = 0; k < e; k++)
            {
                int u = edges[k][0];
                int v = edges[k][1];
                double p = succProb[k];
                if (prob[u] < prob[v] * p)
                {
                    update = true;
                    prob[u] = prob[v] * p;
                }
                if (prob[v] < prob[u] * p)
                {
                    update = true;
                    prob[v] = prob[u] * p;
                }
                
            }
            if (!update)
            {
                break;
            }
        }
        return prob[end_node] == -1 ? 0 : prob[end_node];
    }
};
