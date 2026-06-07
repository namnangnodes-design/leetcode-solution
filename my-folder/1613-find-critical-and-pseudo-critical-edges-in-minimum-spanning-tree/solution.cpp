#include <vector>
#include <algorithm>
#include <numeric> // Thêm thư viện này để dùng std::iota

using namespace std;

class Solution {
public:
    vector<int> mUnion;
    vector<int> mRank; // Thêm rank để tối ưu DSU
    int mN;

    int find(int i) {
        if (mUnion[i] == i) {
            return i;
        }
        return mUnion[i] = find(mUnion[i]);
    }

    bool unite(int a, int b) {
        int findA = find(a);
        int findB = find(b);
        if (findA == findB) {
            return false;
        }
        // Gộp theo rank giúp cây DSU luôn có chiều cao thấp nhất
        if (mRank[findA] < mRank[findB]) {
            mUnion[findA] = findB;
        } else if (mRank[findA] > mRank[findB]) {
            mUnion[findB] = findA;
        } else {
            mUnion[findA] = findB;
            mRank[findB]++;
        }
        mN--;
        return true;
    }

    // Hàm reset nhanh, không cấp phát lại bộ nhớ
    void resetDSU(int n) {
        iota(mUnion.begin(), mUnion.end(), 0); // Gán mUnion[i] = i nhanh chóng
        fill(mRank.begin(), mRank.end(), 0);
        mN = n;
    }

    static bool mCompare(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int eC = edges.size();
        
        // Cấp phát bộ nhớ duy nhất một lần ở đây
        mUnion.resize(n);
        mRank.resize(n);
        
        for (int i = 0; i < eC; i++) {
            edges[i].push_back(i); // Lưu index gốc ở vị trí số 3
        }
        
        sort(edges.begin(), edges.end(), mCompare);
        
        // Tính trọng số MST ban đầu
        resetDSU(n);
        int oW = 0;
        for (int i = 0; i < eC; i++) {
            if (mN == 1) break;
            if (unite(edges[i][0], edges[i][1])) {
                oW += edges[i][2];
            }
        }
        
        vector<int> crit;
        vector<int> nCrit;
        
        for (int i = 0; i < eC; i++) {
            int uI = edges[i][0];
            int vI = edges[i][1];
            int wI = edges[i][2];
            int originIdx = edges[i][3];

            // --- 1. KIỂM TRA CRITICAL ---
            resetDSU(n);
            int weight_ignore = 0;
            for (int j = 0; j < eC; j++) {
                if (j == i) continue;
                if (mN == 1) break;
                if (unite(edges[j][0], edges[j][1])) {
                    weight_ignore += edges[j][2];
                }
            }
            
            // Nếu đồ thị mất liên thông hoặc trọng số tăng lên
            if (mN > 1 || weight_ignore > oW) {
                crit.push_back(originIdx);
                continue; // Đã là Critical thì KHÔNG THỂ là Pseudo-Critical
            }
            
            // --- 2. KIỂM TRA PSEUDO-CRITICAL ---
            // Tối ưu nhỏ: Nếu trọng số cạnh đơn lẻ lớn hơn cả MST, bỏ qua luôn
            if (wI > oW || uI == vI) continue; 

            resetDSU(n);
            int weight_force = wI;
            unite(uI, vI); // Ép cạnh i vào đồ thị trước
            
            for (int j = 0; j < eC; j++) {
                if (j == i) continue;
                if (mN == 1) break;
                if (unite(edges[j][0], edges[j][1])) {
                    weight_force += edges[j][2];
                }
            }
            
            if (weight_force == oW) {
                nCrit.push_back(originIdx);
            }
        }
        
        return {crit, nCrit};
    }
};
