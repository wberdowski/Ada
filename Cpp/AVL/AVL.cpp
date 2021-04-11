#include <iostream>

using namespace std;

struct Element {
	int idx;
	Element* parent;
	Element* left;
	Element* right;
};

Element* znajdzRodzica(int idx, Element*& tree) {
	if (idx < tree->idx) {
		if (tree->left != NULL) {
			znajdzRodzica(idx, tree->left);
		}
		else {
			return tree;
		}
	}
	else {
		if (tree->right != NULL) {
			znajdzRodzica(idx, tree->right);
		}
		else {
			return tree;
		}
	}
}

void dodaj(int idx, Element*& tree) {
	Element* newElement = new Element();
	newElement->idx = idx;

	if (tree == NULL) {
		tree = newElement;
	}
	else {
		Element* parent = znajdzRodzica(idx, tree);
		if (parent != NULL) {
			if (idx < parent->idx) {
				newElement->parent = parent;
				parent->left = newElement;
			}
			else {
				newElement->parent = parent;
				parent->right = newElement;
			}
		}
	}
}

void wyswietl(Element*& tree) {
	if (tree != NULL) {
		cout << tree->idx;

		if (tree->left != NULL) {
			wyswietl(tree->left);
		}

		if (tree->right != NULL) {
			wyswietl(tree->right);
		}
	}
}

Element* znajdz(int idx, Element*& tree) {
	if (tree == NULL) {
		return tree;
	}

	if (idx == tree->idx) {
		return tree;
	}

	if (idx < tree->idx) {
		return znajdz(idx, tree->left);
	}
	else {
		return znajdz(idx, tree->right);
	}
}

Element* najwiekszeDziecko(Element*& tree) {
	Element* output = tree;

	while (output->right != NULL) {
		output = output->right;
	}

	return output;
}

void usunOdRodzica(Element*& current) {
	int idx = current->idx;

	if (current->parent != NULL) {
		if (current->parent->left != NULL && current->parent->left->idx == idx) {
			current->parent->left = NULL;
		}

		if (current->parent->right != NULL && current->parent->right->idx == idx) {
			current->parent->right = NULL;
		}
	}
}

void usun(int idx, Element*& tree) {
	if (tree == NULL) {
		return;
	}

	Element* current = znajdz(idx, tree);

	if (current == NULL) return;

	if (current->left != NULL && current->right != NULL) {
		Element* biggestChild = najwiekszeDziecko(current->left);

		current->idx = biggestChild->idx;

		usunOdRodzica(biggestChild);

		delete biggestChild;
		biggestChild = NULL;
	}
	else if (current->left != NULL) {
		Element* leftChild = current->left;

		current->idx = leftChild->idx;

		usunOdRodzica(leftChild);

		delete leftChild;
		leftChild = NULL;
	}
	else if (current->right != NULL)
	{
		Element* rightChild = current->right;

		current->idx = rightChild->idx;

		usunOdRodzica(rightChild);


		delete rightChild;
		rightChild = NULL;
	}
	else {
		usunOdRodzica(current);

		delete current;
		current = NULL;
	}

	wyswietl(tree);
}

int main() {
	int op = 0;

	Element* tree = NULL;

	dodaj(12, tree);

	dodaj(6, tree);
	dodaj(62, tree);

	dodaj(104, tree);
	dodaj(26, tree);
	dodaj(8, tree);
	dodaj(3, tree);

	dodaj(69, tree);
	dodaj(29, tree);
	dodaj(14, tree);
	dodaj(10, tree);
	dodaj(7, tree);
	dodaj(4, tree);
	dodaj(1, tree);

	while (true) {
		cin >> op;

		if (op == 1) {
			int idx;

			cin >> idx;

			usun(idx, tree);
		}
		else if (op == 2) {
			return 0;
		}
	}

	return 0;
}