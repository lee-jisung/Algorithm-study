#include <iostream>
#include <vector>

using namespace std;

int n;
vector<char> tree[27];

void preorder(char c) {
	if (c == '.') return;
	cout << c;
	preorder(tree[c - 'A'][0]);
	preorder(tree[c - 'A'][1]);
}

void inorder(char c) {
	if (c == '.') return;
	inorder(tree[c - 'A'][0]);
	cout << c;
	inorder(tree[c - 'A'][1]);
}

void postorder(char c) {
	if (c == '.') return;
	postorder(tree[c - 'A'][0]);
	postorder(tree[c - 'A'][1]);
	cout << c;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[a - 'A'].push_back(b);
		tree[a - 'A'].push_back(c);
	}

	preorder('A'); cout << "\n";
	inorder('A'); cout << "\n";
	postorder('A'); cout << "\n";

	return 0;
}
