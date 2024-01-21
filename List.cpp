#include <iostream>

using namespace std;

template <typename T> class List
{
private:
	struct element
	{
		T data;
		element *next;
	};
	element *head;
public:
	List()
	{
		head = NULL;
	}
	~List()
	{
		while (head != NULL) {
			element *p = head->next;
			delete head;
			head = p;
		}
	}
	void ins_first(T a)
	{
		element *p;
		p = new element;
		p->data = a;
		p->next = head;
		head = p;
	}
	void del_first()
	{
		element *p = head->next;
		delete head;
		head = p;
	}

	void ins_last(T a)
	{
		element *p = head;
		if (head == NULL) ins_first(a);
		while (p->next != NULL) p = p->next;
		element *q;
		q = new element;
		q->data = a;
		q->next = NULL;
		p->next = q;
	}
	void del_last()
	{
		element *p = head;
		while (p->next->next != NULL) p = p->next;
		element *q;
		q = p->next;
		p->next = NULL;
		delete q;
	}
	List(const List& orig)
	{
		cout << "Copy is forbidden\n";
	};
	List operator=(const List &orig)
	{
		cout << "Assidnment is forbidden\n";
		return *this;
	};

	void show()
	{
		element *p = head;
		cout << "list of elements:\n";
		while (p != NULL) {
			cout << p->data << "\n";
			p = p->next;
		}
	}
};

int main()
{
	List <int> s;
	s.ins_first(7);
	s.show();
	s.del_first();
	s.ins_first(5);
	s.ins_first(3);
	s.show();
	s.del_first();
	s.show();
	s.ins_last(10);
	s.show();
	s.del_last();
	s.show();
	List <int> k = s;
	List <int> t;
	t = s;
}