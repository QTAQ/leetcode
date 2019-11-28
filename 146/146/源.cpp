#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class LRUCache
{
public:
	unordered_map<int, int> dict;
	unordered_map<int, int> idx;
	vector<int> srt;
	LRUCache(int capacity)
	{
		vector<int> a(capacity);
		srt = a;
	}

	int get(int key)
	{
		if (dict.find(key) != dict.end())
		{
			return dict[key];
		}
		return -1;
	}

	void put(int key, int value)
	{

	}
};