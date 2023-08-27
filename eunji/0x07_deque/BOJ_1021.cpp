#include <deque>
#include <iostream>
using namespace std;

void copy_dep(deque<int>& D_temp, deque<int>& D){
    for (int i=0; i<D.size(); i++){
        D_temp.push_back(D[i]);
    }
}

int first2last(deque<int>& D, int x){
    int ans = 0;
    while (D.front() != x){
        int temp = D.front();
        D.pop_front();
        D.push_back(temp);
        ans ++;
    }
    return ans;
}
int last2first(deque<int>& D, int x){
    int ans = 0;
    while (D.front() != x){
        int temp = D.back();
        D.pop_back();
        D.push_front(temp);
        ans ++;
    }
    return ans;
}

int main(void){
    int N;
    int M;
    cin >> N >> M;
    deque<int> D;
    int ans = 0;

    for (int i=0; i<N; i++){
        D.push_back(i+1);
    }
    for (int i=0; i<M; i++){
        int tar;
        int step_f = 0;
        int step_b = 0;
        cin >> tar;
        if (D.front() == tar){
            D.pop_front();
        }
        else{
            deque<int> D_temp_f;
            deque<int> D_temp_b;
            copy_dep(D_temp_f, D);
            copy_dep(D_temp_b, D);
            step_f = first2last(D_temp_f, tar);
            step_b = last2first(D_temp_b, tar);
            if (step_f >= step_b){
                ans += last2first(D, tar); 
                D.pop_front();
            } 
            else if (step_f < step_b) {
                ans += first2last(D, tar); 
                D.pop_front();
            }
        }
    }
    cout << ans;
}