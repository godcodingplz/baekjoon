#include <iostream>
using namespace std;

pair<char, char> tree[1001]; // 왼쪽 자식, 오른쪽 자식 저장

// 전위 순회 (Pre-order: Root → Left → Right)
void preOrder(char node){
    if (node == '.') return; // 리프 노드인 경우 리턴
    cout << node; // 현재 노드 방문
    preOrder(tree[node].first); // 왼쪽 자식 방문
    preOrder(tree[node].second); // 오른쪽 자식 방문
}

// 중위 순회 (In-order: Left → Root → Right)
void inOrder(char node){
    if (node == '.') return;
    inOrder(tree[node].first);
    cout << node;
    inOrder(tree[node].second);
}

// 후위 순회 (Post-order: Left → Right → Root)
void postOrder(char node){
    if (node == '.') return;
    postOrder(tree[node].first);
    postOrder(tree[node].second);
    cout << node;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        char parent, child1, child2;
        cin >> parent >> child1 >> child2;
        tree[parent] = {child1, child2}; // 부모 노드에 자식 정보 저장
    }

    // 순회 실행
    preOrder('A');
    
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
    cout << "\n";

    return 0;
}
