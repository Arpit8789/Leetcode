class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long MOD = 1e9+7;

        // prev smaller (strictly smaller on left)
        vector<int> prev(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // next smaller (smaller or equal on right)
        vector<int> next(n);
        while (!st.empty()) st.pop();
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // contribution
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            ans = (ans + (arr[i] * left % MOD) * right % MOD) % MOD;
        }

        return (int)ans;
    }
};
