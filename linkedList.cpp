#include <iostream>

struct item {
	item *prior, *post;
	int payload;
}

class doubleLinkedList {
public:

item head;

doubleLinkedList() {
	head.prior = head.post = &head;
}

item* insert(int value) {
	item* newItem = new item(value);
	newItem->payload = value;
	newItem->prior = &head;
	newItem->post  = newItem;
	head.prev = newItem
	head.post = &head;
}

item* insert(int value, item *node) {
	item* newItem = new item(value);
	newItem->payload = value;
	newItem->prior = &node;
	newItem->post  = newItem;
	node->post = &newItem;
}

item* deleteNode(item* node) {
	node->prior->post = node->post;
	node->post->prior = node->prior; 
	delete node;
}

void readList(std::ostream &os) {
	for (item *node = head.post; node != &head; node = node->post) {	
		os << "Item " << node << " has value " << node->payload << "\n";	
	}

}

void unitTest() {
    doubleLinkedList theList;
    theList.insert(1);
    theList.insert(2);
    theList.insert(3);
    theList.insert(4);
    theList.readList(std::cout);
  }
};

int main() {

	doubleLinkedList() theList;
	
	theList.unitTest();

}

}