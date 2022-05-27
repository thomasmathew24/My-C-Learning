#include <iostream>

struct Node
{
	int data;
	struct Node* next;
};


int menu()
{
	int option;
	std::cout << "----------------------------------------------------\n";
	std::cout << "------------------------MENU------------------------\n";
	std::cout << "----------------------------------------------------\n";
	std::cout << "\n1.Create Linked List\n2.Display Linked List\n3.Insert At Beginning";
	std::cout << "\n4.Insert At End\n5.Insert After Element\n";
	std::cout << "\n6.Delete From Beginning\n7.Delete From End\n";
	std::cout << "\n8.Delete Element\n9.Exit\n";
	std::cout << "\nEnter Option : ";
	std::cin >> option;
	return option;
}

int GetData()
{
	int data;
	std::cout << "Enter Data : ";
	std::cin >> data;
	return data;
}

void CreateLL(Node* head,int n)
{
	Node* temp = new Node();
	temp = head;
	for (int i = 1; i < n; i++)
	{
		Node* newNode = new Node();

		newNode->data = GetData();
		newNode->next = NULL;

		temp->next = newNode;
		temp = temp->next;
	}
}

void DisplayLL(Node* head)
{
	std::cout << "Display Linked List\n";
	Node* temp;
	temp = head;
	while (temp != NULL)
	{
		std::cout << "Data : " << temp->data << std::endl;
		temp = temp->next;
	}
}

Node* InsertAtBeginning(Node* head)
{
	std::cout << "Insert At Beginning\n";
	Node* newNode = new Node();
	newNode->data = GetData();
	newNode->next = head;
	head = newNode;
	return head;
}

void InsertAtEnd(Node* head)
{
	std::cout << "Insert At End\n";
	Node* newNode = new Node();
	Node* temp;
	temp = head;
	newNode->data = GetData();
	newNode->next = NULL;
	while (temp != NULL)
	{
		temp = temp->next;
		if (temp->next == NULL)
		{
			temp->next = newNode;
			break;
		}
	}

}

void InsertAfterElement(Node* head)
{
	int searchElement;
	Node* temp;
	Node* afterSearchNode;
	temp = head;
	Node* newNode = new Node();
	std::cout << "Enter element in LL after which you want the element inserted : ";
	std::cin >> searchElement;
	newNode->data = GetData();
	newNode->next = NULL;
	while (temp->next != NULL)
	{
		if (temp->data == searchElement)
		{
			afterSearchNode = temp->next;
			temp->next = newNode;
			newNode->next = afterSearchNode;
		}
		temp = temp->next;
	}
}

Node* DeleteFromBeginning(Node* head)
{
	std::cout << "\nDelete First Node\n";
	Node* temp;
	temp = head;
	head = head->next;
	delete temp;

	return head;
}

void DeleteFromEnd(Node* head)
{
	std::cout << "\nDelete Last Node\n";
	Node* temp;
	Node* preLastNode;
	temp = head;
	preLastNode = head;
	while (temp->next != NULL)
	{
		if (temp->next->next == NULL)
			preLastNode = temp;
		temp = temp->next;
	}
	while (1)
	{
		if (temp->next == NULL)
		{
			preLastNode->next = NULL;
			delete temp;
			break;
		}
		temp = temp->next;
	}
}

void DeleteElement(Node* head)
{
	int searchElement;
	Node* temp;
	Node* preDeleteNode = head;
	temp = head;
	std::cout << "Enter element to be deleted : ";
	std::cin >> searchElement;
	while (temp->next != NULL)
	{
		if (temp->next->data == searchElement)
			preDeleteNode = temp;
		if (temp->data == searchElement)
		{
			preDeleteNode->next = temp->next;
			delete temp;
			break;
		}
		temp = temp->next;
	}
}

int main()
{
	int n;
	Node* head = new Node();
	while (1)
	{
		switch (menu())
		{
		case 1: std::cout << "Enter Number Of Nodes : ";
			std::cin >> n;
			head->data = GetData();
			head->next = NULL;
			CreateLL(head, n);
			break;

		case 2: DisplayLL(head);
			break;

		case 3: head = InsertAtBeginning(head);
			break;

		case 4: InsertAtEnd(head);
			break;

		case 5: InsertAfterElement(head);
			break;

		case 6: head = DeleteFromBeginning(head);
			break;

		case 7: DeleteFromEnd(head);
			break;

		case 8: DeleteElement(head);
			break;

		case 9: exit(0);

		default: continue;
		}
		//system("CLS");
	}
}
