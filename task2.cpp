#include <iostream>
#include <queue> // для обходу в ширину
using namespace std;

// Клас Node — вузол дерева
class Node {
public:
    int value;
    Node* left;
    Node* right;

    // Конструктор
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Клас BinaryTree — бінарне дерево
class BinaryTree {
private:
    Node* root;

public:
    // Конструктор
    BinaryTree() : root(nullptr) {}

    // Метод вставки значення
    void insert(int val) {
        Node* newNode = new Node(val);

        if (root == nullptr) {
            root = newNode; // якщо дерево порожнє
            return;
        }

        // Використовуємо чергу для пошуку вільного місця
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                return;
            } else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;
                return;
            } else {
                q.push(current->right);
            }
        }
    }

    // Метод обходу дерева в ширину
    void breadthFirstTraversal() const {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->value << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }

        cout << endl;
    }
};

// Головна функція
int main() {
    BinaryTree tree;

    // Вставляємо вузли
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    // Обхід дерева в ширину
    cout << "Breadth-first traversal: ";
    tree.breadthFirstTraversal();

    return 0;
}
