#include <iostream>
#include <string>

struct Node {
	std::string data;
	int prev, next;
};

struct List {
	Node* a;
	size_t reserved, size = 0;
	int head = -1;
	List() {
		reserved = 32;
		a = new Node[reserved];
	}
	List(size_t n0) {
		reserved = n0;
		a = new Node[reserved];
	}
	List(const List& l) {
		memcpy_s(a, l.reserved * sizeof(Node), l.a, l.reserved * sizeof(Node));
		reserved = l.reserved;
		head = l.head;
	}
	void resize() {
		if (reserved == 0) ++reserved;
		size_t newSize = reserved * 2;

		Node* b = new Node[newSize];
		memcpy_s(b, reserved * sizeof(Node), a, reserved * sizeof(Node));
		reserved = newSize;
		delete[] a;
		a = b;
	}
	void add(std::string data) {
		int last = get_last();
		add_(data, last, -1);
		if (last >= 0)
			a[last].next = size - 1;

	}
	void add_to_beginning(std::string data) {
		size_t newId = add_(data, -1, head);
		a[head].prev = newId;
		head = newId;
	}
	size_t add_(std::string data, int prev, int next) {
		if (size == reserved) resize();
		if (size == 0) head = 0;
		a[size] = { data, prev, next };
		size++;
		return size - 1;
	}
	int get_last() {
		if (head == -1)
			return head;
		else {
			int t = head;
			while (a[t].next != -1)
				t = a[t].next;
			return t;
		}

	}
	void print() {
		if (head == -1)
			std::cout << "\n";
		else {
			int t = head;
			while (t != -1) {
				std::cout << a[t].data << " ";
				t = a[t].next;
			}
		}

	}
	void print_from_end() {
		if (head == -1)
			std::cout << "\n";		
		else {
			int t = get_last();
			while (t != -1) {
				std::cout << a[t].data << " ";
				t = a[t].prev;
			}
		}

	}
};
char lookNext();

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
	system("pause");
	return 0;
}

char lookNext() {
	char t = std::cin.get();
	std::cin.unget();
	return t;
}

