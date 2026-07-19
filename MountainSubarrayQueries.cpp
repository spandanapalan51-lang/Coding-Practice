/*
Problem: Mountain Subarray Queries

Given an array and multiple queries [l, r], determine whether
arr[l...r] is a mountain array.

A mountain array is first non-decreasing and then non-increasing.

Time Complexity: O(n + q)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> processQueries(vector<int>& arr,
                                vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> incEnd(n);
        vector<int> decEnd(n);

        // Furthest index reachable while non-decreasing
        incEnd[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1])
                incEnd[i] = incEnd[i + 1];
            else
                incEnd[i] = i;
        }

        // Furthest index reachable while non-increasing
        decEnd[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[i + 1])
                decEnd[i] = decEnd[i + 1];
            else
                decEnd[i] = i;
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int peak = min(incEnd[l], r);

            ans.push_back(decEnd[peak] >= r);
        }

        return ans;
    }
};
