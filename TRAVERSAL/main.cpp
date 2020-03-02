/*
 
 입력
 
 2
 7
 27 16 9 12 54 36 72
 9 12 16 27 36 54 72
 6
 409 479 10 838 150 441
 409 10 479 150 838 441
 
 출력
 
 12 9 16 36 72 54 27
 10 150 441 838 479 409
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> slice(const vector<int>& v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
    int N = preorder.size();
    if (preorder.empty()) return;
    int root = preorder[0];
    int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    int R = N - 1 - L;
    
    printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));
    printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));
    
    cout << root << ' ';
}

int main(int argc, const char * argv[]) {
    
    int C;
    cin >> C;
    
    while (C--) {
        int N;
        cin >> N;
        
        vector<int> preorder(N);
        vector<int> inorder(N);
        
        for (int i = 0; i < N; i++) {
            cin >> preorder[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> inorder[i];
        }
        
        printPostOrder(preorder, inorder);
        cout << endl;
    }
    
    return 0;
}
