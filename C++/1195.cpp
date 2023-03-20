#include <iostream>
#include <vector>
using namespace std;
struct Tree{
  Tree* left;
  Tree* right;
  int val;
};
void insert(Tree** root, int x){
  if(*root == NULL){
    (*root) = new Tree;
    (*root)->val = x;
    (*root)->left = (*root)->right = NULL;
  }
  else if(x < (*root)->val){
    insert(&((*root)->left), x);
  }
  else{
    insert(&((*root)->right), x);
  }
}
vector <int> travs;
void printvec(vector <int> travs){
  for(int u = 0; u < travs.size(); u++){
    if(u == travs.size() - 1){
      cout << travs[u] << endl;
    }
    else{
      cout << travs[u] << " ";
    }
  }
}
void pre(Tree* root){
  if(root != NULL){
    travs.push_back(root->val); 
    pre(root->left);
    pre(root->right);
  }
}
void in(Tree* root){
  if(root == NULL) return;
  in(root->left);
  travs.push_back(root->val); 
  in(root->right);
}
void post(Tree* root){
  if(root != NULL){
    post(root->left);
    post(root->right);
    travs.push_back(root->val); 
  }
}
int main(){
  int n; cin >> n;
  for(int t = 1; t <= n; t++){
    Tree* root = NULL;
    int k; cin >> k;
    for(int i = 0; i < k; i++){
      int x; cin >> x;
      insert(&root, x);
    }
    //cout << root->left->right->val << endl;
    cout << "Case " << t << ":" << endl;
    cout << "Pre.: "; pre(root); printvec(travs); travs.clear();
    cout << "In..: "; in(root); printvec(travs); travs.clear();
    cout << "Post: "; post(root); printvec(travs); travs.clear();
    cout << endl;
    free(root);
  }
}
