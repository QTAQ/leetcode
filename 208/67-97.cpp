#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Trie
{
private:
	unordered_map<string, bool> ext;
	vector< vector<string> > pre;
public:
	/** Initialize your data structure here. */
	Trie()
	{
		pre.resize(26);
	}

	/** Inserts a word into the trie. */
	void insert(string word)
	{
		if (ext.find(word) == ext.end())
		{
			ext[word] = true;
			pre[word[0] - 97].push_back(word);
		}
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		if (ext.find(word) != ext.end()) return true;
		return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		int idx = prefix[0] - 97;
		if (pre[idx].size() == 0) return false;
		for (int i = 0; i < pre[idx].size(); ++i)
		{
			if (pre[idx][i].size() >= prefix.size() && pre[idx][i].compare(0, prefix.size(), prefix) == 0)
				return true;
		}
		return false;
	}
};
int main()
{
	Trie trie;
	trie.insert("apple");
	trie.search("apple");   // 返回 true
	trie.search("app");     // 返回 false
	trie.startsWith("app"); // 返回 true
	trie.insert("app");
	trie.search("app");     // 返回 true
	return 0;
}