#include <bits/stdc++.h>


using namespace std;

vector <vector<int>> permute(vector<int> &nums) {

    int n = nums.size();
    vector <vector<int>> res;
    vector<int> path(n);
    vector<bool> on_path(n);
    function<void(int)> dfs = [&](int i) {

        if (i == n) {
            res.push_back(path);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (!on_path[j]) {
                path[i] = nums[j];
                on_path[j] = true;

                dfs(i + 1);
                on_path[j] = false;


            }

        }

    };
    dfs(0);
    return res;


}


vector <vector<int>> permuteAll(vector<int> &nums) {

    int n = nums.size();
    vector <vector<int>> res;
    vector<int> path(n);
    function<void(int)> dfs = [&](int i) {

        if (i == n) {
            res.push_back(path);
            return;
        }
        for (int j = 0; j < n; ++j) {
            path[i] = nums[j];

            dfs(i + 1);


        }

    };
    dfs(0);
    return res;


}




int main() {

    vector<int> ans{1, 2, 3};
    auto res = permuteAll(ans);
    cout << "count is " << res.size() << endl;
    for (auto re: res) {
        for (auto r: re) {
            cout << r << " ";
        }
        cout << endl;
    }


    return 0;
}
