#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int value;
    node *left;
    node *right;
    node *parent;
};

class BST
{
public:
    node *root;

    BST()
    {
        root = NULL;
    }

    node *CreateNewNode(int value)
    {
        node *NewNode = new node;
        NewNode->value = value;
        NewNode->left = NULL;
        NewNode->right = NULL;
        return NewNode;
    }

    void BFS()
    {
        if (root == NULL)
        {
            return;
        }
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *a = q.front();
            q.pop();
            int l = -1, r = -1;
            if (a->left != NULL)
            {
                l = a->left->value;
                q.push(a->left);
            }
            if (a->right != NULL)
            {
                r = a->right->value;
                q.push(a->right);
            }

            cout << "Node value = " << a->value << " Left Child = " << l;
            cout << " right Child = " << r << "\n";
        }
    }

    void Insert(int value)
    {
        node *a = CreateNewNode(value);
        if (root == NULL)
        {
            root = a;
            return;
        }
        node *cur = root;
        node *prv = NULL;
        while (cur != NULL)
        {
            if (a->value > cur->value)
            {
                prv = cur;
                cur = cur->right;
            }
            else
            {
                prv = cur;
                cur = cur->left;
            }
        }
        if (a->value > prv->value)
        {
            prv->right = a;
        }
        else
        {
            prv->left = a;
        }
    }

    bool Search(int value)
    {
        node *cur = root;
        while (cur != NULL)
        {
            if (value > cur->value)
            {
                cur = cur->right;
            }
            else if (value < cur->value)
            {
                cur = cur->left;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    BST bst;
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);

    bst.BFS();

    cout << bst.Search(1) << '\n';
    cout << bst.Search(7) << '\n';

    return 0;
}