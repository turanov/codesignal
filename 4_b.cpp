vector<int>ans;
struct Tree{
	int value;
	Tree *leftTree = 0;
	Tree *rightTree = 0;
};
void add(Tree *&tree, int value){
	if(!tree){
		tree = new Tree;
		tree->value = value;
		tree->leftTree = 0;
		tree->rightTree = 0;
		return;
	}else {
		if(tree->value > value){
			add(tree->leftTree,value);
		}
		else {
			add(tree->rightTree,value);
		}
	}
}
void func(Tree *tree){
	if(!tree)return;
	func(tree->rightTree);
	func(tree->leftTree);
	ans.push_back(tree->value);
}
vector<int> Parliament(int n, vector<int> elements) {
    Tree* tree = 0;
	int root = elements[n-1];
	add(tree,root);
	int index1 = 0;
	int index2 = 0;
	for(int i=0;i<n-1;i++){
		if(elements[i]>=root){
			index1 = i;
			break;
		}
	}
	for(int i=n-2;i>=0;i--){
		if(elements[i]<root){
			index2 = i;
			break;
		}
	}
	for(int i=index1-1;i>=0;i--){
		add(tree,elements[i]);
	}
	
	for(int i=n-2;i>index2;i--){
		add(tree,elements[i]);
	}
    func(tree);
	for(size_t i=0;i<ans.size();i++){
		elements[i] = ans[i];
	}
    return elements;
}
