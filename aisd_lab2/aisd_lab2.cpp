#include <iostream>
#include <string>

struct Node {
	std::string data;
	Node *prev = nullptr, *next = nullptr;
};

struct List {
	Node* head = nullptr;
	//size_t size = 0;
	List() {
	}
	List(const List& l) {
		Node* temp = l.head;
		while (temp != nullptr)
		{
			Node* ins = add_(temp->data, temp->prev, temp->next);
			if (head == nullptr) head = ins;
			temp = temp->next;
		}
	}
	void add(std::string data) {
		if (head == nullptr) {
			add_to_beginning(data);
		}
		else {
			Node *last = get_last();
			Node *newNode = add_(data, last, nullptr);
			if (last != nullptr)
				last->next = newNode;
		}
		

	}
	void add_to_beginning(std::string data) {
		Node* newNode = add_(data, nullptr, head);
		if (head != nullptr) head->prev = newNode;
		head = newNode;
	}
	Node* add_(std::string data, Node *prev, Node *next) {
		Node *newNode = new Node;
		newNode->data = data;
		newNode->prev = prev;
		newNode->next = next;
		return newNode;
	}
	Node* get_last() {
		if (head == nullptr)
			return head;
		else {
			Node* t = head;
			while (t->next != nullptr)
				t = t->next;
			return t;
		}

	}
	void print() {
		if (head == nullptr)
			std::cout << "\n";
		else {
			Node* t = head;
			while (t != nullptr) {
				std::cout << t->data << " ";
				t = t->next;
			}
		}

	}
	void print_from_end() {
		if (head == nullptr)
			std::cout << "\n";		
		else {
			Node* t = get_last();
			while (t != nullptr) {
				std::cout << t->data << " ";
				t = t->prev;
			}
		}

	}
};
char lookNext();
List sortTheList(List);

int main()
{
	List l;
	std::cout << "ENTER SOMETNING DIVIDED WITH SPACE\n";
	do {
		std::string t;
		std::cin >> t;
		l.add(t);
	} while (std::cin && (lookNext() != '\n'));
	std::cout << "PRINT FROM BEGINNING\n";
	l.print();
	std::cout << "\nPRINT FROM END\n";
	l.print_from_end();
	std::cout << "\n\nENTER SOMETNING TO BE ADDED TO THE BEGINNING\n";
	std::string t;
	std::cin >> t;
	l.add_to_beginning(t);
	std::cout << "PRINT FROM BEGINNING\n";
	l.print();
	std::cout << "\nPRINT FROM END\n";
	l.print_from_end();
	std::cout << "\n\n";

	std::cout << "\n\nNOW I WILL SORT THE LIST, BOI\n";
	List newL = sortTheList(l);
	newL.print();
	system("pause");
	return 0;
}

List sortTheList(List l) {
	List even, uneven;
	Node* t = l.head;
	while (t != nullptr)
	{
		if (t->data.length() % 2 == 0)
			even.add(t->data);
		else
			uneven.add(t->data);
		t = t->next;
	}
	even.get_last()->next = uneven.head;
	return even;
}
char lookNext() {
	char t = std::cin.get();
	std::cin.unget();
	return t;
}

