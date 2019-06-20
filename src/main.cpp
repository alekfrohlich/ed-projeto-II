#include <iostream>
#include <fstream>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    unsigned long pos, length;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode()
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->pos = 0;
    pNode->length = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key, int pos, int len)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    
    // mark last node as leaf
    pCrawl->pos = pos;
    pCrawl->length = len;
}

// Returns true if key presents in trie, else
// false
pair<int, int> search(struct TrieNode *root, string key)
{
    pair<int, int> p;
    auto pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
            p.first = -1;
            p.second = -1;
            return p;
        }

        pCrawl = pCrawl->children[index];
    }

    if (pCrawl && pCrawl->length == 0) {
        p.first = 0;
        p.second = 0;
        return p;
    }

    p.first = pCrawl->pos;
    p.first = pCrawl->length;

    return p;
}

int main() {
    
    auto root = getNode();

    string filename;

    cin >> filename;  // entrada

    auto posProx = 0;

    string line;
    ifstream myfile (filename);
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            string word;
            int i;
            for(i=1;i<line.length();i++){
            word+=line[i];
                if(line[i] == ']')
                    break;
            }
            word[i] = '\0';
            auto length = line.length();
            insert(root, word, posProx,length);
            posProx += line.length();
        }
        myfile.close();
    }

    cout << filename << endl;  // esta linha deve ser removida
    
    string word;
    pair<int,int> p;
    while (1) {  // leitura das palavras ate' encontrar "0"
        cin >> word;
        if (word.compare("0") == 0) {
            break;
        }
        cout << word << endl;
        p = search(root, word);
        if(p.first == 0 && p.second == 0)
            printf("is prefix\n");
        else if(p.first == -1)
            printf("is not prefix\n");
        else
            printf("%d %d\n",p.first, p.second );
    }

    return 0;
}

