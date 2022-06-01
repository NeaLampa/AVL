class AVL {
private:
    static int data_root;
    int data;
    int height;
    AVL* left;
    AVL* right;
public:
    AVL();
    AVL(int x);
    void set_root(int);
    int get_data();
    AVL* Insert(AVL* root, int x);
    void Inorder(AVL* root);
    bool Search(AVL* root, int x);
    AVL* DeleteNode(AVL* root, int key);
    AVL* minValueNode(AVL* root);
    void Mirror(AVL* root);
    bool isBST(AVL* root);
    AVL* leftRotate(AVL*);
    AVL* rightRotate(AVL*);
    int get_height();
};