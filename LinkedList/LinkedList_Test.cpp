#include "LinkedList.cpp"
#include <gtest/gtest.h>

TEST(LinkedListTest,InsertFirstElement)
{
	struct node * head = NULL;
	EXPECT_EQ(0, getSizeOfList(head));
	
	head = new node;
	initNode(head, 10);
	EXPECT_EQ(1, getSizeOfList(head));
	EXPECT_EQ(10,getNode(head, 0));
}

TEST(LinkedListTest,AppendElement)
{
	struct node * head = new node;
	initNode(head, 10);
	EXPECT_EQ(1, getSizeOfList(head));
	EXPECT_EQ(10, getNode(head,0));
	
	addNode(head,20);
	EXPECT_EQ(2, getSizeOfList(head));
	EXPECT_EQ(10, getNode(head,0));
	EXPECT_EQ(20, getNode(head,1));

	addNode(head,30);
	EXPECT_EQ(3, getSizeOfList(head));
	EXPECT_EQ(10, getNode(head,0));
	EXPECT_EQ(20, getNode(head,1));
	EXPECT_EQ(30, getNode(head,2));
}

TEST(LinkedListTest,insertNodeAtFront)
{
	struct node * head = new node;

	initNode(head, 10);
	addNode(head,20);
	addNode(head,30);

	insertNodeAtFront(&head,5);
	EXPECT_EQ(4, getSizeOfList(head));
	EXPECT_EQ(5, getNode(head,0));

	insertNodeAtFront(&head,1);
	EXPECT_EQ(5, getSizeOfList(head));
	EXPECT_EQ(1, getNode(head,0));
	EXPECT_EQ(5, getNode(head,1));
	EXPECT_EQ(10, getNode(head,2));
	EXPECT_EQ(20, getNode(head,3));
	EXPECT_EQ(30, getNode(head,4));
}

TEST(LinkedListTest,deleteNode)
{
	struct node * head = new node;

	initNode(head, 10);
	addNode(head,20);
	addNode(head,30);
	insertNodeAtFront(&head,5);
	insertNodeAtFront(&head,1);
	EXPECT_EQ(5, getSizeOfList(head));

	deleteNode(&head,20);
	EXPECT_EQ(4, getSizeOfList(head));

	deleteNode(&head,5);
	EXPECT_EQ(3, getSizeOfList(head));
	
	deleteNode(&head,6);
	EXPECT_EQ(3, getSizeOfList(head));

	EXPECT_EQ(1, getNode(head,0));
	EXPECT_EQ(10, getNode(head,1));
	EXPECT_EQ(30, getNode(head,2));
}

TEST(LinkedListTest,ReverseTheList)
{
	struct node * head = new node;

	initNode(head, 10);
	addNode(head,20);
	addNode(head,30);
	insertNodeAtFront(&head,5);
	insertNodeAtFront(&head,1);
	EXPECT_EQ(5, getSizeOfList(head));
	EXPECT_EQ(1, getNode(head,0));
	EXPECT_EQ(5, getNode(head,1));
	EXPECT_EQ(10, getNode(head,2));
	EXPECT_EQ(20, getNode(head,3));
	EXPECT_EQ(30, getNode(head,4));

	reverse(&head);
	EXPECT_EQ(5, getSizeOfList(head));
	EXPECT_EQ(30, getNode(head,0));
	EXPECT_EQ(20, getNode(head,1));
	EXPECT_EQ(10, getNode(head,2));
	EXPECT_EQ(5, getNode(head,3));
	EXPECT_EQ(1, getNode(head,4));
}

TEST(LinkedListTest,CopyLinkedList)
{
	struct node * head = new node;

	initNode(head, 10);
	addNode(head,20);
	addNode(head,30);
	insertNodeAtFront(&head,5);
	insertNodeAtFront(&head,1);
	EXPECT_EQ(5, getSizeOfList(head));
	EXPECT_EQ(1, getNode(head,0));
	EXPECT_EQ(5, getNode(head,1));
	EXPECT_EQ(10, getNode(head,2));
	EXPECT_EQ(20, getNode(head,3));
	EXPECT_EQ(30, getNode(head,4));

	struct node * newHead = new node;
	copyLinkedList(head,&newHead);	
	EXPECT_EQ(5, getSizeOfList(head));
	EXPECT_EQ(1, getNode(newHead,0));
	EXPECT_EQ(5, getNode(newHead,1));
	EXPECT_EQ(10, getNode(newHead,2));
	EXPECT_EQ(20, getNode(newHead,3));
	EXPECT_EQ(30, getNode(newHead,4));

}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

