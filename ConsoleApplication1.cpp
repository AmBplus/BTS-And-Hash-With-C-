

# include <iostream>
# include <cstdlib>

using namespace std;

/*

 * Node Declaration

 */

struct node

{

    int info;

    struct node* left;

    struct node* right;

}*root;



/*

 * Class Declaration

 */
int n = 1;
class BinaryTree
{

public:

    void find(int, node**, node**);

    void insert(node*, node*);

    void del(int);

    void case_a(node*, node*);

    void case_b(node*, node*);

    void case_c(node*, node*);

    void preorder(node*);

    void inorder(node*);

    void postorder(node*);

    void display(node*, int);

    int CountNodes(node* root);

    int maxValue(node* node);
    
    int minValue(struct node* node);

    int maxDepth(node* node);
 
    BinaryTree()

    {

        root = NULL;

    }

};

/*

 * Main Contains Menu

 */
void treeFunction();


void Design()
{  
    cout << "\n\n\t   ******************************************************************************\n\n\n";
    cout << "\n\n\t   *********************    WELCOME TO My PROGRAM    ****************************";
    cout << "\n\n\t   ********************     { AMIR MASSOM BEYGI }   *****************************";
    cout << "\n\n\t   ******************    { Student OF Teacher Arhami }    ***********************";
    cout << "\n\n\t   *********************   \3 i HOPE YOU ENJOY IT \3   ****************************\n\n\n";
    cout << "\n\n\t   ******************************************************************************\n\n\n";
}
void StartExit()
{
    int x;
    cout << "\n\t \1 For Use Program Enter 1 and For Exit Enter 0\n ";
    cout << "\n\t \5 continue : 1 \n\t \5 Others = Exit \n";
    cout << "\t \6 Enter : ";
    cin >> x;
    system("cls");
    if (x != 1)
    {
        exit(1);
    }
}
//
// Start Menu
void menu()
{
    int Choice;
    cout << "\n\n \t\t 1 : Tree\n";
    cout << " \t\t 2 : Hash\n";
    cout << " \t\t Other Number : Exit \n";
    cout << " \t\t Choice : ";
    cin >> Choice;
    if (Choice == 1)
    {
        treeFunction();
    }
    else if (Choice == 2)
    {
        
    }
    else
    {
        exit(1);
    }
}
int main()
{
    Design();
    menu();
    return 0;
}



/*

 * Find Element in the Tree

 */

void BinaryTree::find(int item, node** par, node** loc)

{

    node* ptr, * ptrsave;

    if (root == NULL)

    {

        *loc = NULL;

        *par = NULL;

        return;

    }

    if (item == root->info)

    {

        *loc = root;

        *par = NULL;

        return;

    }

    if (item < root->info)

        ptr = root->left;

    else

        ptr = root->right;

    ptrsave = root;

    while (ptr != NULL)

    {

        if (item == ptr->info)

        {

            *loc = ptr;

            *par = ptrsave;

            return;

        }

        ptrsave = ptr;

        if (item < ptr->info)

            ptr = ptr->left;

        else

            ptr = ptr->right;

    }

    *loc = NULL;

    *par = ptrsave;

}



/*

 * Inserting Element into the Tree

 */

void BinaryTree::insert(node* tree, node* newnode)

{

    if (root == NULL)

    {

        root = new node;

        root->info = newnode->info;

        root->left = NULL;

        root->right = NULL;

        cout << "Root Node is Added" << endl;

        return;

    }

    if (tree->info == newnode->info)

    {

        cout << "Element already in the tree" << endl;

        return;

    }

    if (tree->info > newnode->info)

    {

        if (tree->left != NULL)

        {

            insert(tree->left, newnode);

        }

        else

        {

            tree->left = newnode;

            (tree->left)->left = NULL;

            (tree->left)->right = NULL;

            cout << "Node Added To Left" << endl;

            return;

        }

    }

    else

    {

        if (tree->right != NULL)

        {

            insert(tree->right, newnode);

        }

        else

        {

            tree->right = newnode;

            (tree->right)->left = NULL;

            (tree->right)->right = NULL;

            cout << "Node Added To Right" << endl;

            return;

        }

    }

}



/*

 * Delete Element from the tree

 */

void BinaryTree::del(int item)

{

    node* parent, * location;

    if (root == NULL)

    {

        cout << "Tree empty" << endl;

        return;

    }

    find(item, &parent, &location);

    if (location == NULL)

    {

        cout << "Item not present in tree" << endl;

        return;

    }

    if (location->left == NULL && location->right == NULL)

        case_a(parent, location);

    if (location->left != NULL && location->right == NULL)

        case_b(parent, location);

    if (location->left == NULL && location->right != NULL)

        case_b(parent, location);

    if (location->left != NULL && location->right != NULL)

        case_c(parent, location);

    free(location);

}



/*

 * Case A

 */

void BinaryTree::case_a(node* par, node* loc)

{

    if (par == NULL)

    {

        root = NULL;

    }

    else

    {

        if (loc == par->left)

            par->left = NULL;

        else

            par->right = NULL;

    }

}



/*

 * Case B

 */

void BinaryTree::case_b(node* par, node* loc)

{

    node* child;

    if (loc->left != NULL)

        child = loc->left;

    else

        child = loc->right;

    if (par == NULL)

    {

        root = child;

    }

    else

    {

        if (loc == par->left)

            par->left = child;

        else

            par->right = child;

    }

}

/*

 * Case C

 */

void BinaryTree::case_c(node* par, node* loc)

{

    node* ptr, * ptrsave, * suc, * parsuc;

    ptrsave = loc;

    ptr = loc->right;

    while (ptr->left != NULL)

    {

        ptrsave = ptr;

        ptr = ptr->left;

    }

    suc = ptr;

    parsuc = ptrsave;

    if (suc->left == NULL && suc->right == NULL)

        case_a(parsuc, suc);

    else

        case_b(parsuc, suc);

    if (par == NULL)

    {

        root = suc;

    }

    else

    {

        if (loc == par->left)

            par->left = suc;

        else

            par->right = suc;

    }

    suc->left = loc->left;

    suc->right = loc->right;

}



/*

 * Pre Order Traversal

 */

void BinaryTree::preorder(node* ptr)

{

    if (root == NULL)

    {

        cout << "Tree is empty" << endl;

        return;

    }

    if (ptr != NULL)

    {

        cout << ptr->info << "  ";

        preorder(ptr->left);

        preorder(ptr->right);

    }

}

/*

 * In Order Traversal

 */

void BinaryTree::inorder(node* ptr)

{

    if (root == NULL)

    {

        cout << "Tree is empty" << endl;

        return;

    }

    if (ptr != NULL)

    {

        inorder(ptr->left);

        cout << ptr->info << "  ";

        inorder(ptr->right);

    }

}



/*

 * Postorder Traversal

 */

void BinaryTree::postorder(node* ptr)

{

    if (root == NULL)

    {

        cout << "Tree is empty" << endl;

        return;

    }

    if (ptr != NULL)

    {

        postorder(ptr->left);

        postorder(ptr->right);

        cout << ptr->info << "  ";

    }

}



/*

 * Display Tree Structure

 */

void BinaryTree::display(node* ptr, int level)

{

    int i;

    if (ptr != NULL)

    {

        display(ptr->right, level + 1);

        cout << endl;

        if (ptr == root)

            cout << "Root->:  ";

        else

        {

            for (i = 0; i < level; i++)

                cout << "       ";

        }

        cout << ptr->info;

        display(ptr->left, level + 1);

    }

}
int BinaryTree::CountNodes(node* root)
{
    if (root == NULL)
        return 0;
    if (root->left != NULL)
    {
        n = n + 1;
        n = CountNodes(root->left);
    }
    if (root->right != NULL)
    {
        n = n + 1;
        n = CountNodes(root->right);
    }
    return n;
}
int BinaryTree::maxValue(node* node)
{
    /* loop down to find the rightmost leaf */
    struct node* current = node;
    while (current->right != NULL)
        current = current->right;

    return (current->info);
}
int BinaryTree::minValue(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
        current = current->left;
    }
    return(current->info);
}
int BinaryTree::maxDepth(node* node)
{
    if (node == NULL)
        return -1;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}
void treeFunction()
{
    int choice, num;

    BinaryTree BinaryTree;

    node* temp;
    system("cls");

    while (1)

    {


        cout << "-----------------" << endl;

        cout << "Operations on BinaryTree" << endl;

        cout << "-----------------" << endl;

        cout << "1.Insert Element " << endl;

        cout << "2.Delete Element " << endl;

        cout << "3.Inorder Traversal" << endl;

        cout << "4.Preorder Traversal" << endl;

        cout << "5.Postorder Traversal" << endl;

        cout << "6.Display" << endl;

        cout << "7.Find Number Of Node " << endl;

        cout << "8.Max Number in Node " << endl;

        cout << "9.Min Number in Node " << endl;

        cout << "10.Height Of Tree " << endl;

        cout << "11.Back To Menu " << endl;

        cout << "15.Quit" << endl;

        cout << "Enter your choice : ";

        cin >> choice;

        switch (choice)

        {

        case 1:
        {
            temp = new node;

            cout << "Enter the number to be inserted : ";

            cin >> temp->info;
            system("cls");
            BinaryTree.insert(root, temp);
            cout << "\n\n\n";
            break;
        }

        case 2:

        {
            if (root == NULL)

            {
                system("cls");
                cout << "Tree is empty, nothing to delete" << endl;
                cout << "\n\n\n";
                continue;

            }

            cout << "Enter the number to be deleted : ";

            cin >> num;
            system("cls");
            cout << "\n\n";
            BinaryTree.del(num);
            cout << "\n\n\n";
            break;
        }

        case 3:

        {
            system("cls");
            cout << "Inorder Traversal of BinaryTree:" << endl;

            BinaryTree.inorder(root);

            cout << "\n\n\n";

            break;
        }

        case 4:

        {
            system("cls");
            cout << "Preorder Traversal of BinaryTree:" << endl;
            BinaryTree.preorder(root);
            cout << "\n\n\n";

            break;
        }

        case 5:
        {
            system("cls");
            cout << "Postorder Traversal of BinaryTree:" << endl;
            BinaryTree.postorder(root);

            cout << "\n\n\n";

            break;
        }

        case 6:

        {
            system("cls");
            cout << "Display BinaryTree:" << endl;
            if (root == NULL)
            {
                cout << "\n\n Empty Tree !\n\n";
            }
            else
            {
                cout << "\n\n";
                BinaryTree.display(root, 1);
                cout << "\n\n\n";
            }


            break;
        }
        case 7:

        {
            system("cls");
            if (root == NULL)
            {
                cout << "\n\n Tree is empty" << endl;
                cout << "\n\n\n";
            }
            else
            {
                cout << "Node Number : " << BinaryTree.CountNodes(root) << endl;
            }
            break;
        }
        case 8:

        {
            if (root == NULL)
            {
                cout << "\n\n Tree is empty" << endl;
                cout << "\n\n\n";
            }
            else
            {
                cout << "Max Value In Node : " << BinaryTree.maxValue(root) << endl;
            }
            break;
        }
        case 9:

        {
            if (root == NULL)
            {
                cout << "\n\n Tree is empty" << endl;
                cout << "\n\n\n";
            }
            else
            {
                cout << "Max Value In Node : " << BinaryTree.minValue(root) << endl;
            }
            break;
        }
        case 10:

        {
            if (root == NULL)
            {
                cout << "\n\n Tree is empty" << endl;
                cout << "\n\n\n";
            }
            else
            {
                cout << "Height of Tree : " << BinaryTree.maxDepth(root) << endl;
            }

            break;
        }
        case 11:
        {
            menu();
            break;
        }
        case 15:

        {
            exit(1);
        }

        default:

        {
            cout << "Wrong choice" << endl;
        }

        }

    }
}