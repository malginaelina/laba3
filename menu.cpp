#include "menu.h"
#include "BinaryTree.h"
#include "Heap.h"

using namespace std;

void sep() {
    cout << "-----------------------------------------------------------\n";
}
int ChooseStr(){
    cout << "Choose traversal - N(Node) R(Right) L(Left):\n";
    cout << "   1 - NLR\n";
    cout << "   2 - NRL\n";
    cout << "   3 - LRN\n";
    cout << "   4 - LNR\n";
    cout << "   5 - RLN\n";
    cout << "   6 - RNL\n";
    int ch;
    cin >> ch;
    return ch;
}
///Tree
void PrintTreeMenu(){
    sep();
    cout << "What do you want to do?\n";
    cout << "\t1 - Print data\n";
    cout << "\t2 - Print tree\n";
    cout << "\t3 - Insert element\n";
    cout << "\t4 - Erase element\n";
    cout << "\t5 - Find element\n";
    cout << "\t6 - Map\n";
    cout << "\t7 - Where\n";
    cout << "\t8 - Get Sub tree\n";
    cout << "\t9 - Find Sub Tree\n";
    cout << "\t10 - Balancing\n";
    cout << "\t0 - Exit\n";
    sep();
}
void MenuTreeInt()
{
    int command = 1;
    BinaryTree<int>* tree = new BinaryTree<int>();
    BinaryTree<int>* tree1 = new BinaryTree<int>();
    BinaryTree<int>* tree2 = new BinaryTree<int>();
    int value;

    while (command != 0) {
        PrintTreeMenu();
        cin >> command;
        int i = 1;
        int j = 1;
        int t;
        switch (command)
        {
            case 0:
                break;
            case 1:
                tree->PrintAsArray();
                break;
            case 2:
                cout << "How do you want to print the tree?\n\t1 - As string\n\t2 - As tree\n";
                cin >> t;
                if(t == 1)
                    cout << tree->ToString(ChooseStr()) << endl;
                else if(t == 2)
                    tree->PrintAsTree(tree->GetRoot(), 1);
                break;
            case 3:
                while (i == 1){
                    cout << "Enter value: ";
                    cin >> value;
                    tree->Insert(value);
                    cout << "Insert more?\n\t1- Yes\n\t0 - No\n" << endl;
                    cin >> i;
                }
                break;
            case 4:
                cout << "Enter value: ";
                cin >> value;
                tree->Erase(value);
                break;
            case 5:
                cout << "Enter value: ";
                cin >> value;
                if (tree->Find(value) == 1) cout << "Node exist" << endl;
                else cout<<"Node DON'T exist"<<endl;
                break;
            case 6:
                cout<<"MAP: multiplying data by 2"<<endl;
                tree = tree->Map(DoubleUp);
                break;
            case 7:
                cout<<"WHERE: checks if data != 0;"<<endl;
                tree = tree->Where(NotZero);
                break;
            case 8:
                cout << "Enter value: ";
                cin >> value;
                if (tree->Find(value) == 1) {
                    tree1 = tree->SubTree(value);
                    cout << "\t1 - Print SubTree as string\n    2 - Print SubTree as tree\n";
                    cin >> t;
                    if(t == 1)
                        cout << tree1->ToString(ChooseStr()) << endl;
                    else if(t == 2)
                        tree1->PrintAsTree(tree1->GetRoot(), 1);
                }
                else
                    cout << "Node DON'T exist\n";
                break;
            case 9:
                cout << "Subtree creation:\n";
                while (j == 1){
                    cout << "Enter value: ";
                    cin >> value;
                    tree2->Insert(value);
                    cout << "Insert more?\n\t1 - Yes\n\t0 - No\n";
                    cin >>j;
                }
                cout << "1 - Print SubTree as string\n";
                cout << "2 - Print SubTree as tree\n";
                cin >> t;
                if(t == 1)
                    cout << tree1->ToString(ChooseStr()) << endl;
                else if(t == 2)
                    tree1->PrintAsTree(tree1->GetRoot(), 1);
                if (tree->IsSubTree(tree, tree2))
                    cout << " it is a subtree\n";
                else
                    cout << "it is NOT a subtree\n";
                break;
            case 10:
                tree->BuildBalanceTree(tree->GetRoot());
                break;
            default:
                cout << "Incorrect number!";
                break;
        }
    }
}
void MenuTreeFloat()
{
    int command = 1;
    auto* tree = new BinaryTree<float>();
    BinaryTree<float>* tree1 = new BinaryTree<float>();
    auto* tree2 = new BinaryTree<float>();
    float value;
    while (command != 0) {
        PrintTreeMenu();
        cin >> command;
        int i = 1;
        int j = 1;
        int t;
        switch (command)
        {
            case 0:
                break;
            case 1:
                tree->PrintAsArray();
                break;
            case 2:
                cout << "How do you want to print the tree?\n\t1 - As string\n\t2 - As tree\n";
                cin >> t;
                if(t == 1)
                    cout << tree->ToString(ChooseStr()) << endl;
                else if(t == 2)
                    tree->PrintAsTree(tree->GetRoot(), 1);
                break;
            case 3:
                while (i == 1)
                {
                    cout << "Enter value: ";
                    cin >> value;
                    tree->Insert(value);
                    cout << "Insert more?\n\t1- Yes\n\t0 - No\n" << endl;
                    cin >> i;
                }
                break;
            case 4:
                cout << "Enter value: ";
                cin >> value;
                tree->Erase(value);
                break;
            case 5:
                cout << "Enter value: ";
                cin >> value;
                if (tree->Find(value) == 1) cout << "Node exist" << endl;
                else cout<<"Node DON'T exist"<<endl;
                break;
            case 6:
                cout<<"MAP: multiplying data by 2"<<endl;
                tree = tree->Map(DoubleUp);
                break;
            case 7:
                cout<<"WHERE: checks if data != 0;"<<endl;
                tree = tree->Where(NotZero);
                break;
            case 8:
                cout << "Enter value: ";
                cin >> value;
                if (tree->Find(value) == 1) {
                    tree1 = tree->SubTree(value);
                    cout << "\t1 - Print SubTree as string\n    2 - Print SubTree as tree\n";
                    cin >> t;
                    if(t == 1)
                        cout << tree1->ToString(ChooseStr()) << endl;
                    else if(t == 2)
                        tree1->PrintAsTree(tree1->GetRoot(), 1);
                }
                else
                    cout << "Node DON'T exist\n";
                break;
            case 9:
                cout << "Subtree creation:\n";
                while (j == 1){
                    cout << "Enter value: ";
                    cin >> value;
                    tree2->Insert(value);
                    cout << "Insert more?\n\t1 - Yes\n\t0 - No\n";
                    cin >>j;
                }
                cout << "1 - Print SubTree as string\n";
                cout << "2 - Print SubTree as tree\n";
                cin >> t;
                if(t == 1)
                    cout << tree1->ToString(ChooseStr()) << endl;
                else if(t == 2)
                    tree1->PrintAsTree(tree1->GetRoot(), 1);
                if (tree->IsSubTree(tree, tree2))
                    cout << " it is a subtree\n";
                else
                    cout << "it is NOT a subtree\n";
                break;
            case 10:
                tree->BuildBalanceTree(tree->GetRoot());
                break;
            default:
                cout << "Incorrect number!";
                break;
        }
    }
}
void MenuTreeComplex()
{
    int command = 1;
    BinaryTree<complex>* tree = new BinaryTree<complex>();
    BinaryTree<complex>* tree1;
    BinaryTree<complex>* tree2 = new BinaryTree<complex>();
    complex value;
    float real, im;

    while (command != 0) {
        PrintTreeMenu();
        cin >> command;
        int i = 1;
        int j = 1;
        int t;
        switch (command)
        {
            case 0:
                break;
            case 1:
                tree->PrintAsArray();
                break;
            case 2:
                cout << "How do you want to print the tree?\n\t1 - As string\n\t2 - As tree\n";
                cin >> t;
                if(t == 1)
                    cout << tree->ToString(ChooseStr()) << endl;
                else if(t == 2)
                    tree->PrintAsTree(tree->GetRoot(), 1);
                break;
            case 3:
                while (i == 1)
                {
                    cout << "Enter value:\n";
                    cout << "\tEnter real and imaginary parts of complex number: ";
                    cin >> real >> im;
                    value = complex(real, im);
                    cout << endl;
                    tree->Insert(value);
                    cout << "Insert more?\n\t1- Yes\n\t0 - No\n" << endl;
                    cin >> i;
                }
                break;
            case 4:
                cout << "Enter value:\n";
                cout << "\tEnter real and imaginary parts of complex number: ";
                cin >> real >> im;
                value = complex(real, im);
                cout << endl;
                tree->Erase(value);
                break;
            case 5:
                cout << "Enter value:\n";
                cout << "\tEnter real and imaginary parts of complex number: ";
                cin >> real >> im;
                value = complex(real, im);
                cout << endl;
                if (tree->Find(value) == 1) cout << "Node exist" << endl;
                else cout<<"Node DON'T exist"<<endl;
                break;
            case 6:
                cout<<"MAP: multiplying data by 2"<<endl;
                tree = tree->Map(DoubleUp);
                break;
            case 7:
                cout<<"WHERE: checks if data != 0;"<<endl;
                tree = tree->Where(NotZero);
                break;
            case 8:
                cout << "Enter value:\n";
                cout << "\tEnter real and imaginary parts of complex number: ";
                cin >> real >> im;
                value = complex(real, im);
                cout << endl;
                if (tree->Find(value) == 1) {
                    tree1 = tree->SubTree(value);
                    cout << "\t1 - Print SubTree as string\n    2 - Print SubTree as tree\n";
                    cin >> t;
                    if(t == 1)
                        cout << tree1->ToString(ChooseStr()) << endl;
                    else if(t == 2)
                        tree1->PrintAsTree(tree1->GetRoot(), 1);
                }
                else
                    cout << "Node DON'T exist\n";
                break;
            case 9:
                cout << "Subtree creation:\n";
                while (j == 1){
                    cout << "Enter value:\n";
                    cout << "\tEnter real and imaginary parts of complex number: ";
                    cin >> real >> im;
                    value = complex(real, im);
                    cout << endl;
                    tree2->Insert(value);
                    cout << "Insert more?\n\t1 - Yes\n\t0 - No\n";
                    cin >>j;
                }
                cout << "1 - Print SubTree as string\n";
                cout << "2 - Print SubTree as tree\n";
                cin >> t;
                if(t == 1)
                    cout << tree1->ToString(ChooseStr()) << endl;
                else if(t == 2)
                    tree1->PrintAsTree(tree1->GetRoot(), 1);
                if (tree->IsSubTree(tree, tree2))
                    cout << " it is a subtree\n";
                else
                    cout << "it is NOT a subtree\n";
                break;
            case 10:
                tree->BuildBalanceTree(tree->GetRoot());
                break;
            default:
                cout << "Incorrect number!";
                break;
        }
    }
}
///Heap
void PrintHeapMenu(){
    sep();
    cout << "What do you want to do?\n";
    cout << "\t1 - Print as heap\n";
    cout << "\t2 - Print as string\n";
    cout << "\t3 - Insert element\n";
    cout << "\t4 - Delete element\n";
    cout << "\t5 - Find element\n";
    cout << "\t6 - Get Sub tree\n";
    cout << "\t0 - Exit\n";
    sep();
}
void MenuHeapInt(){
    int command = 1;
    auto* heap = new BinaryHeap<int>();
    int value;
    while (command != 0) {
        PrintHeapMenu();
        cin >> command;
        int i = 1;
        int t;
        switch (command)
        {
            case 0:
                break;
            case 1:
                heap->Print();
                break;
            case 2:
                cout << heap->ToString() << endl;
                break;
            case 3:
                while (i == 1){
                    cout << "Enter value: ";
                    cin >> value;
                    heap->Insert(value);
                    cout << "Insert more?\n\t1- Yes\n\t0 - No\n" << endl;
                    cin >> i;
                }
                break;
            case 4:
                cout << "Enter value: ";
                cin >> value;
                heap->DeleteItem(value);
                break;
            case 5:
                cout << "Enter value: ";
                cin >> value;
                if (heap->Find(value) == 1) cout << "Node exist" << endl;
                else cout<<"Node DON'T exist"<<endl;
                break;
            case 6:
                cout << "Enter value: ";
                cin >> value;
                if (heap->Find(value) == 1) {
                    BinaryHeap<int>* subtree;
                    subtree = heap->SubHeap(value);
                    cout << "   1 - Print SubTree as heap\n    2 - Print SubTree as string\n";
                    cin >> t;
                    if (t == 1)
                        subtree->Print();
                    if (t == 2)
                        cout << subtree->ToString() << endl;
                }
                else
                    cout << "Node DON'T exist\n";
                break;
            default:
                cout << "Incorrect number!";
                break;
        }
    }
}
void MenuHeapFloat(){
    int command = 1;
    auto* heap = new BinaryHeap<float>();
    float value;
    while (command != 0) {
        PrintHeapMenu();
        cin >> command;
        int i = 1;
        int t;
        switch (command)
        {
            case 0:
                break;
            case 1:
                heap->Print();
                break;
            case 2:
                cout << heap->ToString() << endl;
                break;
            case 3:
                while (i == 1)
                {
                    cout << "Enter value: ";
                    cin >> value;
                    heap->Insert(value);
                    cout << "Insert more?\n\t1- Yes\n\t0 - No\n" << endl;
                    cin >> i;
                }
                break;
            case 4:
                cout << "Enter value: ";
                cin >> value;
                heap->DeleteItem(value);
                break;
            case 5:
                cout << "Enter value: ";
                cin >> value;
                if (heap->Find(value) == 1) cout << "Node exist" << endl;
                else cout<<"Node DON'T exist"<<endl;
                break;
            case 6:
                cout << "Enter value: ";
                cin >> value;
                if (heap->Find(value) == 1) {
                    BinaryHeap<float>* subtree;
                    subtree = heap->SubHeap(value);
                    cout << "   1 - Print SubTree as heap\n    2 - Print SubTree as string\n";
                    cin >> t;
                    if (t == 1)
                        subtree->Print();
                    if (t == 2)
                        cout << subtree->ToString() << endl;
                }
                else
                    cout << "Node DON'T exist\n";
                break;
            default:
                cout << "Incorrect number!";
                break;
        }
    }
}
void MenuHeapComplex(){
    int command = 1;
    auto* heap = new BinaryHeap<complex>();
    complex value;
    float real, im;
    while (command != 0) {
        PrintHeapMenu();
        cin >> command;
        int i = 1;
        int t;
        switch (command)
        {
            case 0:
                break;
            case 1:
                heap->Print();
                break;
            case 2:
                cout << heap->ToString() << endl;
                break;
            case 3:
                while (i == 1)
                {
                    cout << "Enter value:\n";
                    cout << "\tEnter real and imaginary parts of complex number: ";
                    cin >> real >> im;
                    value = complex(real, im);
                    cout << endl;
                    heap->Insert(value);
                    cout << "Insert more?\n\t1- Yes\n\t0 - No\n" << endl;
                    cin >> i;
                }
                break;
            case 4:
                cout << "Enter value:\n";
                cout << "\tEnter real and imaginary parts of complex number: ";
                cin >> real >> im;
                value = complex(real, im);
                cout << endl;
                heap->DeleteItem(value);
                break;
            case 5:
                cout << "Enter value:\n";
                cout << "\tEnter real and imaginary parts of complex number: ";
                cin >> real >> im;
                value = complex(real, im);
                cout << endl;
                if (heap->Find(value) == 1) cout << "Node exist" << endl;
                else cout<<"Node DON'T exist"<<endl;
                break;
            case 6:
                cout << "Enter value:\n";
                cout << "\tEnter real and imaginary parts of complex number: ";
                cin >> real >> im;
                value = complex(real, im);
                cout << endl;
                if (heap->Find(value) == 1) {
                    BinaryHeap<complex>* subtree;
                    subtree = heap->SubHeap(value);
                    cout << "   1 - Print SubTree as heap\n    2 - Print SubTree as string\n";
                    cin >> t;
                    if (t == 1)
                        subtree->Print();
                    if (t == 2)
                        cout << subtree->ToString() << endl;
                }
                else
                    cout << "Node DON'T exist\n";
                break;
            default:
                cout << "Incorrect number!";
                break;
        }
    }
}

void Menu()
{
    sep();
    cout << "What data structure do you want to work with?\n";
    cout << "\t1 - Binary tree\n";
    cout << "\t2 - Binary heap\n";
    int structure;
    cin >> structure;
    int type;
    sep();
    cout << "Choose your type:\n";
    cout << "	1 - int\n";
    cout << "	2 - float\n";
    cout << "	3 - complex\n";
    cout << "	0 - exit\n";
    sep();
    cin >> type;
    if(structure == 1){
        switch (type)
        {
            case 0:
                break;
            case 1:
                MenuTreeInt();
                break;
            case 2:
                MenuTreeFloat();
                break;
            case 3:
                MenuTreeComplex();
                break;
            default:
                cout << "Incorrect number!" << endl;
                break;
        }
    }
    else if(structure == 2){
        switch (type)
        {
            case 0:
                break;
            case 1:
                MenuHeapInt();
                break;
            case 2:
                MenuHeapFloat();
                break;
            case 3:
                MenuHeapComplex();
                break;
            default:
                cout << "Incorrect number!" << endl;
                break;
        }
    }
}