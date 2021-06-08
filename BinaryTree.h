#ifndef LABA3_BINARYTREE_H
#define LABA3_BINARYTREE_H
#include <iostream>
#include <vector>
#include "string"
#include "func.h"
#include "cmath"

template<typename T> class Node {
public:
    T data;         // данные
    Node<T> *left;  // левый потомок
    Node<T> *right; // правый потомок
    Node<T>(T val)
    {
        left = nullptr;
        right = nullptr;
        data = val;
    }
    Node<T>()
    {
        left = nullptr;
        right = nullptr;
    }
};

template<typename T> class BinaryTree
{
private:
    Node<T> *root;                 // указатель на корень узла
    int size;                      // количество элементов в дереве
    void PrintTree(Node<T> *, int ch);
    void DeleteTree(Node<T> *);
    string ToStrLNP(Node<T>* curr , string result);
    string ToStrLPN(Node<T>* curr , string result);
    string ToStrNPL(Node<T>* curr , string result);
    string ToStrNLP(Node<T>* curr , string result);
    string ToStrPLN(Node<T>* curr , string result);
    string ToStrPNL(Node<T>* curr , string result);
    string ToStrTest(Node<T>* curr , string result);
    BinaryTree<T>* MapHelper(T (fun)(T), Node<T>* original, BinaryTree<T>* result);
    BinaryTree<T>* WhereHelper(bool (fun)(T), Node<T>* original, BinaryTree<T>* result);
    Node<T> *FindValue  (const T &target);
    Node<T> *FindValueHelper(Node<T> *curr, const T &val) const;
    bool IsEqual(Node<T>* root1, Node<T>* root2, bool result);
public:
    BinaryTree();
    BinaryTree(T value);
    ~BinaryTree();

    void PrintAsArray();
    void PrintAsTree(Node<T>* node, int level);

    ///базовые функции
    bool Find(T value); //поиск
    void Insert(T value); //ставка
    void Erase(T value); //удаление

    string ToString(int ch);
    BinaryTree<T>* Map(T (fun)(T));
    BinaryTree<T>* Where(bool (fun)(T));
    BinaryTree<T> *SubTree(const T &target);
    bool IsSubTree(BinaryTree<T>* tree1, BinaryTree<T>* tree2);
    int GetSize();
    Node<T> *GetRoot();

    Node<T> *BuildBalanceTree(Node<T> *root);
    Node<T> *BuildTree(vector<Node<T>*> &nodes, int start, int end);
    void СreateVector(Node<T> *root, vector<Node<T>*> &nodes);

};

template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
    size = 0;
}

template<typename T> BinaryTree<T>::BinaryTree(T value) : size(1)
{
    root = new Node<T>(value);
    size = 1;
}

template<typename T> BinaryTree<T>::~BinaryTree()
{
    DeleteTree(root);
}

template<typename T> int BinaryTree<T>::GetSize()
{
    return size;
}

template<typename T> Node<T>* BinaryTree<T>::GetRoot()
{
    return root;
}

template<typename T> void BinaryTree<T>::DeleteTree(Node<T> *curr)
{
    if (curr)
    {
        DeleteTree(curr->left);
        DeleteTree(curr->right);
        delete curr;
    }
}

template<typename T> void BinaryTree<T>::PrintAsArray()
{
    PrintTree(root, 1);
    cout << endl;
}

///Базовые функции
template<typename T> bool BinaryTree<T>::Find(T value)
{
    Node<T> * curr = root;
    while (curr && curr->data != value)
    {
        if (curr->data > value)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return curr != nullptr;
}

template<typename T> void BinaryTree<T>::Insert(T value)
{
    if(!root)
        root = new Node<T>(value);
    else{
        Node<T> * curr = root;
        while (curr && curr->data != value)
        {
            if (curr->data > value && curr->left == nullptr)
            {
                curr->left = new Node<T>(value);
                ++size;
                return;
            }
            if (curr->data < value && curr->right == nullptr)
            {
                curr->right = new Node<T>(value);
                ++size;
                return;
            }
            if (curr->data > value)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

}

template<typename T> void BinaryTree<T>::Erase(T value)
{
    Node<T> * curr = root;
    Node<T> * parent = nullptr;
    while (curr && curr->data != value)
    {
        parent = curr;
        if (curr->data > value)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (!curr)
        return;
    if (curr->left == nullptr)
    {
        // Вместо curr подвешивается его правое поддерево
        if (parent && parent->left == curr)
            parent->left = curr->right;
        if (parent && parent->right == curr)
            parent->right = curr->right;
        --size;
        delete curr;
        return;
    }
    if (curr->right == nullptr)
    {
        // Вместо curr подвешивается его левое поддерево
        if (parent && parent->left == curr)
            parent->left = curr->left;
        if (parent && parent->right == curr)
            parent->right = curr->left;
        --size;
        delete curr;
        return;
    }
    // У элемента есть два потомка, тогда на место элемента поставим
    // наименьший элемент из его правого поддерева
    Node<T> * replace = curr->right;
    while (replace->left)
        replace = replace->left;
    T replace_value = replace->data;
    Erase(replace_value);
    curr->data = replace_value;
}

/// обходы
template<typename T>
void BinaryTree<T>::PrintAsTree(Node<T>* node, int level)
{
    if(node)
    {
        PrintAsTree(node->left, level + 1);
        for(int i = 0; i < level; i++)
            cout<<"   ";
        print(node->data);
        cout << endl;
        PrintAsTree(node->right, level + 1);
    }
}

template<typename T>
void BinaryTree<T>::PrintTree(Node<T>* curr, int ch)
{
    if (curr) // Проверка на ненулевой указатель
    {
        switch(ch){
            case 1:
                print(curr->data);
                cout << " ";
                PrintTree(curr->left, 1);
                PrintTree(curr->right, 1);
                break;
            case 2:
                print(curr->data);
                cout << " ";
                PrintTree(curr->right, 2);
                PrintTree(curr->left, 2);
                break;
            case 3:
                PrintTree(curr->left, 3);
                PrintTree(curr->right, 3);
                print(curr->data);
                cout << " ";
                break;
            case 4:
                PrintTree(curr->left, 4);
                print(curr->data);
                cout << " ";
                PrintTree(curr->right, 4);
                break;
            case 5:
                PrintTree(curr->right, 5);
                PrintTree(curr->left, 5);
                print(curr->data);
                cout << " ";
                break;
            case 6:
                PrintTree(curr->right, 6);
                print(curr->data);
                cout << " ";
                PrintTree(curr->left, 6);
                break;
            default:
                break;
        }
    }
    else
        return;
}

template<typename T>
string BinaryTree<T>::ToStrTest(Node<T> * curr, string result)
{
    if (curr)
    {
        result = ToStrTest(curr->left, result);
        result += ToStr((curr->data)) + " ";
        result = ToStrTest(curr->right, result);
    }
    return result;
}

template<typename T>
string BinaryTree<T>::ToStrLNP(Node<T> * curr, string result)
{
    if (curr)
    {
        result += " ( ";
        result = ToStrLNP(curr->left, result);
        result += " ) { " + ToStr((curr->data)) + " } [ ";
        result = ToStrLNP(curr->right, result);
        result += " ] ";

    }
    return result;
}

template<typename T>
string BinaryTree<T>::ToStrLPN(Node<T> * curr, string result)
{
    if (curr)
    {
        result += " ( ";
        result = ToStrLPN(curr->left, result);
        result += " ) [ ";
        result = ToStrLPN(curr->right, result);
        result += " ] { " + ToStr((curr->data)) + " } ";

    }
    return result;
}

template<typename T>
string BinaryTree<T>::ToStrNPL(Node<T> * curr, string result)
{
    if (curr)
    {
        result += " { " + ToStr((curr->data)) + " } [ ";
        result = ToStrNPL(curr->right, result);
        result += " ] ( ";
        result = ToStrNPL(curr->left, result);
        result += " ) ";
    }
    return result;
}

template<typename T>
string BinaryTree<T>::ToStrNLP(Node<T> * curr, string result)
{
    if (curr)
    {
        result += " { " + ToStr((curr->data)) + " } ( ";
        result = ToStrNLP(curr->left, result);
        result += " ) [ ";
        result = ToStrNLP(curr->right, result);
        result += " ] ";
    }
    return result;
}

template<typename T>
string BinaryTree<T>::ToStrPLN(Node<T> * curr, string result)
{
    if (curr)
    {
        result += " [ ";
        result = ToStrPLN(curr->left, result);
        result += " ] ( ";
        result += " ) < " + ToStr((curr->data)) + " > [ ";
        result = ToStrPLN(curr->right, result);
        result += " ] ";

    }
    return result;
}

template<typename T>
string BinaryTree<T>::ToStrPNL(Node<T> * curr, string result)
{
    if (curr)
    {
        result += " ( ";
        result = ToStrPNL(curr->left, result);
        result += " ) < " + ToStr((curr->data)) + " > [ ";
        result = ToStrPNL(curr->right, result);
        result += " ] ";

    }
    return result;
}

template<typename T>
string BinaryTree<T>::ToString(int ch)
{
    string result = "";
    switch (ch)
    {
        case 1:
            result = ToStrLNP(root , result);
            return result;
        case 2:
            result = ToStrNPL(root , result);
            return result;
        case 3:
            result = ToStrLPN(root , result);
            return result;
        case 4:
            result = ToStrNLP(root , result);
            return result;
        case 5:
            result = ToStrPLN(root , result);
            return result;
        case 6:
            result = ToStrPNL(root , result);
            return result;
        case 7:
            result = ToStrTest(root, result);
            return result;
        default:
            result = "Wrong choice!";
            return result;
    }

}

///map
template<typename T>
BinaryTree<T>* BinaryTree<T>::Map(T (fun)(T)) //возвращает результат функции fun, примененной ко всем элементам
{
    auto *result = new BinaryTree<T>();
    result = MapHelper(fun, root, result);
    return result;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::MapHelper(T (fun)(T), Node<T>* original, BinaryTree<T>* result)
{
    if (original != nullptr) {
        result->Insert(fun(original->data));
        result = MapHelper(fun, original->left, result);
        result = MapHelper(fun, original->right, result);
    }
    return result;
}

///where
template<typename T>
BinaryTree<T>* BinaryTree<T>::Where(bool(fun)(T)) //возращает значения, удовлетворяющие условию fun
{
    auto* result = new BinaryTree<T>();
    result = WhereHelper(fun, root , result);
    return result;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::WhereHelper(bool(fun)(T), Node<T>* original, BinaryTree<T>* result)
{
    if (original != nullptr) {
        if (fun(original->data))
            result->Insert(original->data);
        result = WhereHelper(fun, original->left, result);
        result = WhereHelper(fun, original->right, result);
    }
    return result;
}

///извлечение поддерева

template<typename T>
bool BinaryTree<T>::IsSubTree(BinaryTree<T>* tree1, BinaryTree<T>* tree2) // ïåðåäåëåàòü
{
    bool result = false;
    result = IsEqual(tree1->GetRoot(), tree2->GetRoot(), result);
    return result;
}

template<typename T>
bool BinaryTree<T>::IsEqual(Node<T>* root1, Node<T>* root2, bool result)
{
    if (root2 == nullptr) {
        return true;
    }
    else if ((root1 == nullptr) && (root2 != nullptr)) {
        return false;
    }
    else if (root1 != nullptr) {
        if ((root1->data) == (root2->data)) {
            if (IsEqual(root1->left, root2->left, result) && IsEqual(root1->right, root2->right, result)) {
                return true;
            }
        }
        result = IsEqual(root1->left, root2, result) || IsEqual(root1->right, root2, result);
    }
    return result;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::SubTree(const T &target) {

    Node<T>* Node = FindValue(target);

    auto* newTree = new BinaryTree<T>();
    newTree->root = Node;

    return newTree;
}
template<typename T>
Node<T>* BinaryTree<T>::FindValue(const T &target){

    if(root->data == target) {
        return root;
    }
    else
        return FindValueHelper(root, target);
}
template<typename T>
Node<T>* BinaryTree<T>::FindValueHelper(Node<T> *curr, const T &val) const {

    if (curr == nullptr)
        return NULL;
    if (val < curr->data)
        return FindValueHelper(curr->left, val);
    else if (val > curr->data)
        return FindValueHelper(curr->right, val);
    else
        return curr;
}

///балансировка
template<typename T>
void BinaryTree<T>::СreateVector(Node<T>* r, vector<Node<T>*> &nodes)
{
    if(r == nullptr)
        return;
    СreateVector(r->left, nodes);
    nodes.push_back(r);
    СreateVector(r->right, nodes);
}

template<typename T>
Node<T>* BinaryTree<T>::BuildTree(vector<Node<T>*> &nodes, int start, int end)
{
    if(start > end)
        return nullptr;
    int mid = (start + end)/2;
    Node<T>* r = nodes[mid];
    r->left = BuildTree(nodes, start, mid - 1);
    r->right = BuildTree(nodes, mid + 1, end);
    root = r;
    return r;
}

template<typename T>
Node<T>* BinaryTree<T>::BuildBalanceTree(Node<T>* r)
{
    vector<Node<T>*> nodes;
    СreateVector(r, nodes);
    int n = nodes.size();
    return BuildTree(nodes, 0, n - 1);
}


#endif //LABA3_BINARYTREE_H
