#include <iostream>
using namespace std;

struct NODE{
    struct NODE *next;
    int data;
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int K;
    cin >> N >> K;
    NODE* curr = (NODE*)malloc(sizeof(NODE));
    curr -> data = 1;
    curr -> next = NULL;
    NODE* start;
    start = curr;
    for (int i=2; i<=N; i++){
        NODE* new_node = (NODE*)malloc(sizeof(NODE));
        new_node -> data = i;
        curr->next = new_node;
        curr = curr->next;
    }
    curr->next = start;

    cout << '<';
    while (curr->next){
        for (int i=0; i<K-1; i++){
            curr = curr->next;
        }
        if (curr->next == curr){
            cout << curr->next->data << ">";
            break;
        }
        cout << curr->next->data << ", ";
        NODE* temp;
        temp = curr->next->next;
        curr->next = temp;
    }
}
