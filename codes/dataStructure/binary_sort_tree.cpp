#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int data;
  Node *left, *right;
  Node(int d) : data(d), left(NULL), right(NULL) {}
};

// BST (Binary Search Tree)
class BST {
public:
  Node *insert(Node *root, int data) {
    if (root == NULL) {
      return new Node(data);
    } else {
      Node *curr;
      if (data <= root->data) {
        curr = insert(root->left, data);
        root->left = curr;
      } else {
        curr = insert(root->right, data);
        root->right = curr;
      }
      return root;
    }
  }

  int getHeight(Node *root) {
    if (root == NULL)
      return -1;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
  }

  // BFS ==> level order transversal
  void levelOrder(Node *root) {
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
      Node *curr = q.front();
      cout << curr->data << " ";
      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
      q.pop();
    }

    cout << endl;
  }

  // DFS ==> pre order
  void preOrder(Node *root) {
    stack<Node *> st;
    st.push(root);
    Node *curr = st.top();

    while (!st.empty()) {
      Node *curr = st.top();
      st.pop();
      cout << curr->data << " ";
      if (curr->right)
        st.push(curr->right);
      if (curr->left)
        st.push(curr->left);
    }

    cout << endl;
  }

  void preOrderRecursive(Node *root) {
    if (root == NULL)
      return;
    cout << root->data << " ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
  }

  void postOrder(Node *root) {
    if (root == NULL)
      return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
  }

  void inOrder(Node *root) {
    if (root == NULL)
      return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
  }

  bool search(Node *root, int data) {
    if (root == NULL)
      return false;
    if (root->data == data)
      return true;
    if (data > root->data)
      return search(root->right, data);
    return search(root->left, data);
  }

  Node *minValueNode(Node *root) {
    Node *curr = root;
    while (curr->left)
      curr = curr->left;

    return curr;
  }

  Node *remove(Node *root, int data) {
    // caso base
    if (root == NULL)
      return root;

    if (data < root->data)
      root->left = remove(root->left, data);
    else if (data > root->data)
      root->right = remove(root->right, data);

    // si el es igual al dato del root, el nodo debe ser removido
    else {
      // Nodo solo con un hijo o ninguno
      if (root->right == NULL) {
        Node *aux = root->left;
        // delete root;
        return aux;
      } else if (root->left == NULL) {
        Node *aux = root->right;
        // delete root;
        return aux;
      }

      // Nodo con 2 hijos: sacamos el sucesor menor del subarbol derecho
      Node *tmp = minValueNode(root->right);
      root->data = tmp->data;
      root->right = remove(root->right, tmp->data);
    }

    return root;
  }
};

int main() {
  fast;
  BST myTree;
  Node *root = NULL;
  int T, data;
  cin >> T;

  while (T--) {
    cin >> data;
    root = myTree.insert(root, data);
  }

  // int height = myTree.getHeight(root);
  // cout << height << endl;

  myTree.levelOrder(root);
  root = myTree.remove(root, 50);
  myTree.levelOrder(root);

  // myTree.preOrder(root);
  // myTree.preOrderRecursive(root);
  // myTree.postOrder(root);
  // myTree.inOrder(root);

  return 0;
}
