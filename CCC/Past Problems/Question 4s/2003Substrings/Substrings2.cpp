// A C++ program to find the count of distinct substring
// of a string using trie data structure
#include <bits/stdc++.h>
#define MAX_CHAR 10000
using namespace std;

// A Suffix Trie (A Trie of all suffixes) Node
class SuffixTrieNode
{
public:
	SuffixTrieNode *children[MAX_CHAR];
	SuffixTrieNode() // Constructor
	{
		// Initialize all child pointers as NULL
		for (int i = 0; i < MAX_CHAR; i++)
		children[i] = NULL;
	}

	// A recursive function to insert a suffix of the s
	// in subtree rooted with this node
	void insertSuffix(string suffix);
};

// A Trie of all suffixes
class SuffixTrie
{
	SuffixTrieNode *root;
	int _countNodesInTrie(SuffixTrieNode *);
public:
	// Constructor (Builds a trie of suffies of the given text)
	SuffixTrie(string s)
	{
		root = new SuffixTrieNode();

		// Consider all suffixes of given string and insert
		// them into the Suffix Trie using recursive function
		// insertSuffix() in SuffixTrieNode class
		for (int i = 0; i < s.length(); i++)
			root->insertSuffix(s.substr(i));
	}

	// method to count total nodes in suffix trie
	int countNodesInTrie() { return _countNodesInTrie(root); }
};

// A recursive function to insert a suffix of the s in
// subtree rooted with this node
void SuffixTrieNode::insertSuffix(string s)
{
	// If string has more characters
	if (s.length() > 0)
	{
		// Find the first character and convert it
		// into 0-25 range.
		char cIndex = s.at(0);

		// If there is no edge for this character,
		// add a new edge
		if (children[cIndex] == NULL)
			children[cIndex] = new SuffixTrieNode();

		// Recur for next suffix
		children[cIndex]->insertSuffix(s.substr(1));
	}
}

// A recursive function to count nodes in trie
int SuffixTrie::_countNodesInTrie(SuffixTrieNode* node)
{
	// If all characters of pattern have been processed,
	if (node == NULL)
		return 0;

	int count = 0;
	for (int i = 0; i < MAX_CHAR; i++)
	{
		// if children is not NULL then find count
		// of all nodes in this subtrie
		if (node->children[i] != NULL)
			count += _countNodesInTrie(node->children[i]);
	}

	// return count of nodes of subtrie and plus
	// 1 because of node's own count
	return (1 + count);
}

// Returns count of distinct substrings of str
int countDistinctSubstring(string str)
{
	// Construct a Trie of all suffixes
	SuffixTrie sTrie(str);

	// Return count of nodes in Trie of Suffixes
	return sTrie.countNodesInTrie();
}

// Driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        cout<<countDistinctSubstring(str)<<endl;
    }
	
}


// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;


// class SuffixTrieNode {
//     public:
//         SuffixTrieNode *children[26];
//         SuffixTrieNode(){
//             for(ll i=0; i<26; i++){
//                 children[i]=NULL;
//             }
//         }

//         void insertSuffix(string s){
//             if(s.length()>0){
//                 char cIndex=s.at(0)-'a';

//                 if(children[cIndex]==NULL){
//                     children[cIndex]=new SuffixTrieNode();
//                 }

//                 children[cIndex]->insertSuffix(s.substr(1));
//             }
//         }
// };

// class SuffixTrie {

//     SuffixTrieNode *root;

//     public:
//         SuffixTrie(string s){
//             root = new SuffixTrieNode();
            
//             for(ll i=0; i<s.length(); i++){
//                 root->insertSuffix(s.substr(i));
//             }

//         }

//         int countNodesInTrie(SuffixTrieNode* node){
//             if(node==NULL){
//                 return 0;
//             }

//             int count=0;
//             for(int i=0; i<26; i++){
//                 if(node->children[i]!=NULL){
//                     count+=countNodesInTrie(node->children[i]);
//                 }
//             }

//             return (1+count);
//         }

//         int countDistinctSubstring(){
//             return countNodesInTrie(root);
//         }

// };


// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         string s;
//         cin>>s;
//         SuffixTrie solve(s);
//         cout<<solve.countDistinctSubstring()<<endl;
//     }
// }