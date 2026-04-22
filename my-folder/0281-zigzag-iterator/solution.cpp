class ZigzagIterator {
public:
    vector<int> mV;
    size_t i;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        mV.clear();
        i = 0;
        while (i < v1.size() && i < v2.size())
        {
            mV.push_back(v1[i]);
            mV.push_back(v2[i]);
            i++;
        }
        while (i < v1.size())
        {
            mV.push_back(v1[i]);
            i++;
        }
        while (i < v2.size())
        {
            mV.push_back(v2[i]);
            i++;
        }
        i = 0;
    }

    int next() {
        return mV[i++];
    }

    bool hasNext() {
        return i < mV.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
