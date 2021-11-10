#include <algorithm>
#include "linkedBinaryTree.hpp"
#include "maxHeap.hpp"
#include "completeWinnerTree.hpp"
#include "player.h"
#include "binarySearchTree.hpp"
#include "AVLTree.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Test linkedBinaryTree
    // using Node_int = binaryTreeNode<int>;
    // Node_int *node1 = new Node_int(1);
    // auto node2 = new Node_int(2);
    // auto node3 = new Node_int(3);
    // auto node4 = new Node_int(4);
    // auto node5 = new Node_int(5);
    // auto node6 = new Node_int(6);
    // auto node7 = new Node_int(7);
    // node1->leftChild = node2;
    // node1->rightChild = node3;
    // node2->leftChild = node4;
    // node2->rightChild = node5;
    // node3->leftChild = node6;
    // node3->rightChild = node7;

    // linkedBinaryTree<int> tree(node1);
    // std::cout << "preorder" << std::endl;
    // tree.preOrder(Visit<int>);
    // std::cout << std::endl;

    // std::cout << "inorder" << std::endl;
    // tree.inOrder(Visit<int>);
    // std::cout << std::endl;

    // std::cout << "postorder" << std::endl;
    // tree.postOrder(Visit<int>);
    // std::cout << std::endl;

    // std::cout << "leverorder" << std::endl;
    // tree.levelOrder(Visit<int>);
    // std::cout << std::endl;

    // std::cout << "Height = " << tree.height() << std::endl;

    // auto arr = new int[11];
    // arr[1] = 20;
    // arr[2] = 12;
    // arr[3] = 35;
    // arr[4] = 15;
    // arr[5] = 10;
    // arr[6] = 80;
    // arr[7] = 30;
    // arr[8] = 17;
    // arr[9] = 2;
    // arr[10] = 1;

    // maxHeap<int> heap(arr, 10);

    // std::cout << heap.top() << std::endl;

    // heap.push(90);
    // std::cout << heap.top() << std::endl;

    // heap.pop();
    // heap.pop();
    // std::cout << heap.top() << std::endl;

    // heap.pop();
    // std::cout << heap.top() << std::endl;

    // int n;
    // cout << "Enter number of players, >= 2" << endl;
    // cin >> n;
    // if (n < 2)
    // {
    //     cout << "Bad input" << endl;
    //     exit(1);
    // }

    // player *thePlayer = new player[n + 1];

    // cout << "Enter player values" << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cin >> thePlayer[i].key;
    //     thePlayer[i].id = i;
    // }

    // completeWinnerTree<player> *w =
    //     new completeWinnerTree<player>(thePlayer, n);
    // cout << "The winner tree is" << endl;
    // w->output();

    // thePlayer[2].key = 0;
    // w->rePlay(2);
    // cout << "Changed player 2 to zero, new tree is" << endl;
    // w->output();

    // thePlayer[3].key = -1;
    // w->rePlay(3);
    // cout << "Changed player 3 to -1, new tree is" << endl;
    // w->output();
    // binarySearchTree<int, char> y;
    // y.insert(pair<int, char>(1, 'a'));
    // y.insert(pair<int, char>(6, 'c'));
    // y.insert(pair<int, char>(4, 'b'));
    // y.insert(pair<int, char>(8, 'd'));
    // cout << "Tree size is " << y.size() << endl;
    // cout << "Elements in ascending order are" << endl;
    // y.ascend();

    // pair<const int, char> *s = y.find(4);
    // cout << "Search for 4 succeeds " << endl;
    // cout << s->first << ' ' << s->second << endl;
    // y.erase(4);
    // cout << "4 deleted " << endl;
    // cout << "Tree size is " << y.size() << endl;
    // cout << "Elements in ascending order are" << endl;
    // y.ascend();

    // s = y.find(8);
    // cout << "Search for 8 succeeds " << endl;
    // cout << s->first << ' ' << s->second << endl;
    // y.erase(8);
    // cout << "8 deleted " << endl;
    // cout << "Tree size is " << y.size() << endl;
    // cout << "Elements in ascending order are" << endl;
    // y.ascend();

    // s = y.find(6);
    // cout << "Search for 6 succeeds " << endl;
    // cout << s->first << ' ' << s->second << endl;
    // y.erase(6);
    // cout << "6 deleted " << endl;
    // cout << "Tree size is " << y.size() << endl;
    // cout << "Elements in ascending order are" << endl;
    // y.ascend();

    // s = y.find(1);
    // cout << "Search for 1 succeeds " << endl;
    // cout << s->first << ' ' << s->second << endl;
    // y.erase(1);
    // cout << "1 deleted " << endl;
    // cout << "Tree size is " << y.size() << endl;
    // cout << "Elements in ascending order are" << endl;
    // y.ascend();
    int arr[] = {3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
#define TBL_SIZE(a) ((sizeof(a)) / (sizeof(a[0])))

    int i, ilen;
    AVLTree<int> *tree = new AVLTree<int>();

    cout << "== 依次添加: ";
    ilen = TBL_SIZE(arr);
    for (i = 0; i < ilen; i++)
    {
        cout << arr[i] << " ";
        tree->insert(arr[i]);
    }

    cout << "\n== 前序遍历: ";
    tree->preOrder();

    cout << "\n== 中序遍历: ";
    tree->inOrder();

    cout << "\n== 后序遍历: ";
    tree->postOrder();
    cout << endl;

    cout << "== 高度: " << tree->height() << endl;
    cout << "== 最小值: " << tree->minimum() << endl;
    cout << "== 最大值: " << tree->maximum() << endl;

    i = 8;
    cout << "\n== 删除根节点: " << i;
    tree->erase(i);

    cout << "\n== 高度: " << tree->height();
    cout << "\n== 中序遍历: ";
    tree->inOrder();
    cout << "\n== 树的详细信息: " << endl;
    return 0;
}
