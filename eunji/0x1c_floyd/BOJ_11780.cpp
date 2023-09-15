#include <iostream>
#include <vector>
using namespace std;

#define INF (0x3f3f3f3f)

int main(){
  int n;
  int m;
  int city[102][102];
  vector<int> path[10002];
  
  cin >> n >> m;
  for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++){
      if (i==j) city[i][j] = 0;
      else city[i][j] = INF;
    }
  }
  for (int i=0; i<m; i++){
    int st;
    int ed;
    int cost;
    cin >> st >> ed >> cost;
    if (city[st][ed] > cost) {
      city[st][ed] = cost;
      path[n*(st-1)+ed-1].clear(); // 추가 필요!!!!!!
      path[n*(st-1)+ed-1].push_back(st);
    }
  }
  for (int k=1; k<=n; k++){
    for (int i=1; i<=n; i++){
      for (int j=1; j<=n; j++){
        if (city[i][k] + city[k][j] < city[i][j]){
          city[i][j] = city[i][k] + city[k][j];
          path[n*(i-1)+j-1] = path[n*(i-1)+k-1]; // Copy path[i][k] to path[i][j]
          for (int z=0; z<path[n*(k-1)+j-1].size(); z++){
            path[n*(i-1)+j-1].push_back(path[n*(k-1)+j-1][z]);
          }          
        }
      }
    }
  }
  for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++){
      if (city[i][j] == INF) cout << "0 ";
      else cout << city[i][j] << " ";
    }
    cout << '\n';
  }
  for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++){
      if (i==j || city[i][j] == INF) cout << "0\n";
      else if (path[n*(i-1)+j-1].size() != 0){
        cout << path[n*(i-1)+j-1].size()+1 << " ";
        for (int z=0; z<path[n*(i-1)+j-1].size(); z++){
          cout << path[n*(i-1)+j-1][z] << " ";
        }
        cout << j << "\n";
      }
      else cout << "0\n";
    }
  }

  return 0;
}