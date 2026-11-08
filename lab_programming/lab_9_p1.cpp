#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class IntervalMerger {
  public:
    vector<vector<double>> double_arr;
    int N;

    IntervalMerger(vector<vector<double>> d_arr, int n) {
        double_arr = d_arr;
        N = n;
    }

    void merger() {
        for (int i = 0; i < N; i += 2) {
            sort(double_arr[i].begin(), double_arr[i].end());
            sort(double_arr[i + 1].begin(), double_arr[i + 1].end());
            cout << double_arr[i][0] << " "
                 << double_arr[i + 1][1] << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<double>> double_arr;

    for (int i = 0; i < n; i++) {
        double value1, value2;
        cin >> value1;
        cin >> value2;
        double_arr.push_back({value1, value2});
    }

    IntervalMerger interval_merger(double_arr, n);
    interval_merger.merger();

    return 0;
}