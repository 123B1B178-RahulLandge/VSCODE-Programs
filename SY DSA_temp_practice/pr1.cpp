#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n), u(n);
    vector<int> y(m), v(m);
    vector<bool> red_used(n, false), blue_used(m, false); // Track if a ball is already involved in a collision

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> u[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i] >> v[i];
    }

    int collision_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Skip if either ball is already involved in a collision
            if (red_used[i] || blue_used[j]) continue;

            // Check the collision condition
            if (x[i] * v[j] == y[j] * u[i]) {
                collision_count++;
                red_used[i] = true;  // Mark red ball as used
                blue_used[j] = true; // Mark blue ball as used
                break;               // Stop checking this red ball after collision
            }
        }
    }

    cout << collision_count << endl;
    return 0;
}
