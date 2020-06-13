#include <vector>
#include <map>
#include <queue>
#include <string>

class Array {
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = nums.size();

        std::map<int, int> M;

        for (int i = 0; i < n; i++) {
            M[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int k = target - nums[i];
            auto j = M.find(k);
            if (j != M.end()) {
                return std::vector<int>({ i, j->second });
            }
        }

        return std::vector<int>({ 0 });
    }


    int reverse(int x) {
        std::queue<int> getallen;

        int m = 10;
        int i = x;

        while (i > 1) {
            int a = x % m;
            i = (a - m) / 10;
            getallen.push(a);
        }

        int j = 1;
        int ret = 0;
        while (getallen.size() > 0) {
            int g = getallen.front();
            getallen.pop();
            ret += g * j;
            j *= 10;
        }
    }


    int romanToInt(std::string s) {
        int n = s.size();

        std::map<char, int> R;
        R['I'] = 1;
        R['V'] = 5;
        R['X'] = 10;
        R['L'] = 50;
        R['C'] = 100;
        R['D'] = 500;
        R['M'] = 1000;

        int a = 0;
        int next = 0;

        for (int i = 0; i < n; i++) {
            int j = R[s[i]];

            i++;
            if (i == n) {
                a += j;
                continue;
            }

            int next = R[s[i]];

            if (j < next) {
                a += next - j;
            }
            else {
                a += next + j;
            }
        }

        return a;
    }

    /*
    There are n people whose IDs go from 0 to n - 1 and each person belongs exactly to one group. Given the array groupSizes of length n telling the group size each person belongs to, return the groups there are and the people's IDs each group includes.

    You can return any solution in any order and the same applies for IDs. Also, it is guaranteed that there exists at least one solution. 
    */
    std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes) {
        std::map<int, std::vector<int>> dist;

        for (int i = 0; i < groupSizes.size(); i++) {
            dist[groupSizes[i]].push_back(i);
        }

        std::vector<std::vector<int>> groups;

        for (auto const& i : dist) {
            int n = i.second.size() / i.first;
            for (int j = 0; j < n; j++) {
                auto g = std::vector<int>();
                for (int k = 0; k < i.first; k++) {
                    g.push_back(i.second[j * i.first + k]);
                }

                groups.push_back(g);
            }
        }

        return groups;
    }


    /* Given an array nums and a value val, remove all instances of that value in-place and return the new length.
    */

    int removeElement(std::vector<int>& nums, int val) {
        int k = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                int temp = nums[k];
                nums[k] = nums[i];
                nums[i] = temp;
                k++;
            }
        }

        return k;
    }

};