/*Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use
the same element twice.
You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]


#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    unordered_map<int, int> hm;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "size of arr" << n << endl;
    for(int i=0;i<n; i++){
        int remaining = target - arr[i];
        if(hm.find(remaining) != hm.end()) {
            cout << hm[remaining] << "==" << i << endl;
        }
        else {
            hm[arr[i]] = i;
        }
    }
    return 0;
}



/*
#######################################################
Write a c++ program to remove duplicate elements from array using hashmap
############################################
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int arr[] = {3,6,1,2,3,4,5,6,7};
    unordered_map<int, bool> hm;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "size of arr" << n << endl;
    for(int i: arr){
        if(hm.find(i) != hm.end() ){
            continue;
        }
        else {
            hm[i] = true;
        }
    }
    for(auto x: hm){
        cout << x.first <<endl;
    }
    cout<< "hashmap size: "<< hm.size()<<endl;
    return 0;
}


===========frequency of numbers=======================
#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int arr[] = {3,6,1,2,3,4,5,6,7};
    unordered_map<int, int> hm;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "size of arr" << n << endl;
    for(int i: arr){
        hm[i]++;
    }
    for(auto x: hm){
        cout << x.first << " -- " << x.second <<endl;
    }
    cout<< "hashmap size: "<< hm.size()<<endl;
    return 0;
}


%Parenthesis balanced or not 
#include <iostream>
#include <stack>
using namespace std;

// Function to check if parentheses are balanced
bool isBalanced(const string& str) {
    stack<char> s;

    // Traverse each character in the string
    for (char ch : str) {
        // If it's an opening bracket, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If it's a closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            // Check if the stack is empty (unmatched closing bracket)
            if (s.empty()) return false;

            // Check for matching opening bracket
            char top = s.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // Mismatch found
            }
            s.pop(); // Pop the matched opening bracket
        }
    }

    // If the stack is empty, the parentheses are balanced
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (isBalanced(expression)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }

    return 0;
}




//TREENODE
#include <iostream>
#include <stack>
using namespace std;

// Define a tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to validate if the tree is a BST using stack and DFS
bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;

    stack<TreeNode*> st;
    TreeNode* current = root;
    long prevValue = -1;

    // In-order traversal using stack
    while (!st.empty() || current != nullptr) {
        // Traverse the left subtree
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        // Process the current node
        current = st.top();
        st.pop();

        // Check if the current node's value is greater than the previous value
        if (current->val <= prevValue) {
            return false; // The tree is not a valid BST
        }
        prevValue = current->val; // Update the previous value

        // Move to the right subtree
        current = current->right;
    }

    return true;
}

int main() {
    // Constructing a sample binary tree:
    //         5
    //        / \
    //       3   7
    //      / \   \
    //     2   4   8

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    // Validate if the tree is a BST
    if (isValidBST(root)) {
        cout << "The tree is a valid Binary Search Tree." << endl;
    } else {
        cout << "The tree is NOT a valid Binary Search Tree." << endl;
    }

    return 0;
}









*/


