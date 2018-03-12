#include "genreMap.h"
#include <string>
#include <queue>

template<class genre>
genreMap<genre>::genreMap<genre>()
{
	this->movies = new movieNode[10];
}

template<class genre>
void genreMap<genre>::insert(genre* movie)
{	
	int index = hashFunction(movie.getKey());
	movieNode* target = new MovieNode(movie);
	movieNode *cur = this->movies[index];
	if (cur != nullptr) {
		while (cur.next != nullptr) {
			cur = cur.next;
		}
		cur.next = target;
	}
	else {
		this->movies[index] = target;
	}
}

template<class genre>
genre * genreMap<genre>::find(string key)
{
	int index = hashFunction(key);
	movieNode *cur = this->movies[index];
	while (cur != nullptr) {
		if (key == cur.item.getKey()) {
			return cur.item;
		}
		cur = cur.next;
	}
	return nullptr;
}

template<class genre>
int genreMap<genre>::hashFunction(string key)
{
	return key.length() % 10;
}

template<class genre>
void genreMap<genre>::printInventory(string type)
{
	priority_queue<genre> pq;
	for (int i = 0; i < 10; i++) {
		genre* cur = this->movies[i];
		while (cur != nullptr) {
			pq.push(cur.item);
			cur = cur.next;
		}
	}
	while (!pq.empty()) {
		genre* next = pq.top();
		pq.pop();
		cout << type << ", " << next.getStockCount() << ", " << next.getDirector() <<
			", " << next.getTitle() << ", ";
		if (type == "C") {
			cout << next.getActor();
		}
		cout << next.getReleaseData() << endl;
	}
}
