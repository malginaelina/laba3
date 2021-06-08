#include <gtest/gtest.h>
#include "BinaryTree.h"
#include "Heap.h"

TEST(BinaryTree, Constructor_1) {
    auto* tree = new BinaryTree<int>();
    EXPECT_EQ(tree->GetSize(), 0);
}

TEST(BinaryTree, Constructor_2) {
    BinaryTree<int>* tree = new BinaryTree<int>(2);
    EXPECT_EQ(tree->GetSize(), 1);
}

TEST(BinaryTree, Map) {
    BinaryTree<int>* tree = new BinaryTree<int>();
    BinaryTree<int>* tree2 = new BinaryTree<int>();
    string result = "";
    string str = "2 4 6 8 10 ";
    for(int i=1; i<6; i++)
        tree->Insert(i);
    tree2 = tree->Map(DoubleUp);
    result = tree2->ToString(7);
    EXPECT_EQ(result, str);
}

TEST(BinaryTree, Where) {
    BinaryTree<int>* tree = new BinaryTree<int>();
    BinaryTree<int>* tree2 = new BinaryTree<int>();
    string result = "";
    string str = "1 2 3 4 ";
    for(int i=0; i<5; i++)
        tree->Insert(i);
    tree2 = tree->Where(NotZero);
    result = tree2->ToString(7);
    EXPECT_EQ(result, str);
}

TEST(BinaryTree, Find) {
    BinaryTree<int>* tree = new BinaryTree<int>();
    for(int i=0; i<5; i++)
        tree->Insert(i);
    EXPECT_EQ(tree->Find(2), true);
    EXPECT_EQ(tree->Find(6), false);
}

TEST(BinaryTree, Insert) {
    BinaryTree<int>* tree = new BinaryTree<int>();
    BinaryTree<int>* tree2 = new BinaryTree<int>();
    string result = "";
    string str = "1 2 3 4 5 ";
    for(int i=1; i<5; i++)
        tree->Insert(i);
    tree->Insert(5);
    result = tree->ToString(7);
    EXPECT_EQ(result, str);
}

TEST(BinaryTree, Erase) {
    BinaryTree<int>* tree = new BinaryTree<int>();
    BinaryTree<int>* tree2 = new BinaryTree<int>();
    string result = "";
    string str = "1 2 3 ";
    for(int i=1; i<5; i++)
        tree->Insert(i);
    tree->Erase(4);
    result = tree->ToString(7);
    EXPECT_EQ(result, str);
}

TEST(BinaryTree, SubTree) {
    BinaryTree<int>* tree = new BinaryTree<int>();
    BinaryTree<int>* tree2 = new BinaryTree<int>();
    string result = "";
    string str = "4 5 ";
    for(int i=1; i<6; i++)
        tree->Insert(i);
    tree2 = tree->SubTree(4);
    result = tree2->ToString(7);
    EXPECT_EQ(result, str);
}

TEST(BinaryTree, IsSubTree) {
    BinaryTree<int>* tree = new BinaryTree<int>();
    BinaryTree<int>* tree2 = new BinaryTree<int>();
    for(int i=1; i<6; i++)
        tree->Insert(i);
    tree2->Insert(4);
    tree2->Insert(5);
    EXPECT_EQ(tree->IsSubTree(tree, tree2), true);
}

TEST(Heap, Constructor) {
    BinaryHeap<int>* heap = new BinaryHeap<int>();
    EXPECT_EQ(heap->GetSize(), 0);
}

TEST(Heap, Find) {
    BinaryHeap<int>* heap = new BinaryHeap<int>();
    for(int i=1; i<6; i++)
        heap->Insert(i);
    EXPECT_EQ(heap->Find(2), true);
    EXPECT_EQ(heap->Find(6), false);
}

TEST(Heap, ToString) {
    BinaryHeap<int>* heap = new BinaryHeap<int>();
    for(int i=1; i<6; i++)
        heap->Insert(i);
    string result = "";
    string str = "5 4 2 1 3 ";
    result = heap->ToString();
    EXPECT_EQ(result, str);
}

TEST(Heap, DeleteMax) {
    BinaryHeap<int>* heap = new BinaryHeap<int>();
    for(int i=1; i<6; i++)
        heap->Insert(i);
    int max;
    max = heap->DeleteMax();
    EXPECT_EQ(max, 5);
}

TEST(Heap, Insert) {
    BinaryHeap<int>* heap = new BinaryHeap<int>();
    for(int i=1; i<6; i++)
        heap->Insert(i);
    string result = "";
    string str = "6 4 5 1 3 2 ";
    heap->Insert(6);
    result = heap->ToString();
    EXPECT_EQ(result, str);
}

TEST(Heap, DeleteItem) {
    BinaryHeap<int>* heap = new BinaryHeap<int>();
    for(int i=1; i<6; i++)
        heap->Insert(i);
    string result = "";
    string str = "5 3 2 1 ";
    heap->DeleteItem(4);
    result = heap->ToString();
    EXPECT_EQ(result, str);
}