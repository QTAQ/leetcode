class Solution
{
public:
	double dfs(string &x, string &y, unordered_map<string, vector<int>> &xmap,
				unordered_map<string, vector<int>> &ymap , vector<double>& values,
				vector<vector<string>>& equations, vector<bool> &ck)
	{
		double res = -1;
		auto v = xmap[x];
		for (int i = 0; i < v.size(); ++i)
		{
			if (ck[v[i]]) continue;
			string t = equations[v[i]][1];
			if (t != y)
			{
				ck[v[i]] = true;
				double tmp = dfs(t, y, xmap, ymap, values, equations,ck);
				ck[v[i]] = false;
				if (tmp != -1) return tmp * values[v[i]];
			}
			else return values[v[i]];
		}
		v = ymap[x];
		for (int i = 0; i < ymap[x].size(); ++i)
		{
			if (ck[v[i]]) continue;
			string t = equations[v[i]][0];
			if (t != y)
			{
				ck[v[i]] = true;
				double tmp = dfs(y, t, xmap, ymap, values, equations,ck);
				ck[v[i]] = false;
				if (tmp != -1) return 1.0/(tmp * values[v[i]]);
			}
			else return 1.0/values[v[i]];
		}
		return res;
	}
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
	{
		vector<double> res;
		unordered_map<string, vector<int>> xmap;
		unordered_map<string, vector<int>> ymap;
		unordered_set<string> m;
		vector<bool> ck(equations.size(), false);
		for (int i = 0; i < equations.size(); ++i)
		{
			xmap[equations[i][0]].push_back(i);
			ymap[equations[i][1]].push_back(i);
			m.insert(equations[i][0]);
			m.insert(equations[i][1]);
		}
		for (int i = 0; i < queries.size(); ++i)
		{
			string x = queries[i][0];
			string y = queries[i][1];
			if (x == y)
			{
				int t = -1.0;
				if (m.find(x)!=m.end())
					t = 1.0;
				res.push_back(t);
				continue;
			}
			if (m.find(x)==m.end() || m.find(y)==m.end())
			{
				res.push_back(-1.0);
				continue;
			}
			res.push_back(dfs(x,y, xmap, ymap,values,equations,ck));
		}
		return res;
	}
};