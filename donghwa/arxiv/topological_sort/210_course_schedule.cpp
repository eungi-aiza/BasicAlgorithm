/*
There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return *the ordering of courses you should take to finish all courses*. If there are many valid answers, return **any** of them. If it is impossible to finish all courses, return **an empty array**.

**Example 1:**

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

```

**Example 2:**

```
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

```

**Example 3:**
Input: numCourses = 1, prerequisites = []
Output: [0]
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);
    
    for (const vector<int>& prereq : prerequisites) {
        int course = prereq[0];
        int prereqCourse = prereq[1];
        graph[course].push_back(prereqCourse);  // Reverse the edges
        inDegree[prereqCourse]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> order;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        order.push_back(course);
        
        for (int neighbor : graph[course]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    if (order.size() == numCourses) {
        vector<int> result(order.rbegin(), order.rend());  // Reverse the order to get the correct result
        return result;
    } else {
        return vector<int>();
    }
}

int main() {
    vector<vector<int>> prerequisites1 = {{1, 0}};
    vector<int> result1 = findOrder(2, prerequisites1);
    for (int course : result1) {
        cout << course << " ";
    }
    cout << endl; // Output: 0 1

    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> result2 = findOrder(4, prerequisites2);
    for (int course : result2) {
        cout << course << " ";
    }
    cout << endl; // Output: 0 2 1 3

    vector<vector<int>> prerequisites3;
    vector<int> result3 = findOrder(1, prerequisites3);
    for (int course : result3) {
        cout << course << " ";
    }
    cout << endl; // Output: 0

    return 0;
}
