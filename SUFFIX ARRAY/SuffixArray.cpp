struct suffix_array
{
    vector<int> p, c;

    suffix_array(string &s) {
        int n = s.size() + 1;
        p.resize(n);
        c.resize(n);
    }

    void radix_sort(vector<pair<pair<int, int>, int>> &a) {
        int n = a.size();
        {
            vector<int> cnt(n);
            for (int i = 0; i < n; i++)
                cnt[a[i].first.second]++;
            vector<int> pos(n);
            vector<pair<pair<int, int>, int>> a_new(n);
            pos[0] = 0;
            for (int i = 1; i < n; i++)
                pos[i] = pos[i - 1] + cnt[i - 1];
            for (auto it : a) {
                int x = it.first.second;
                a_new[pos[x]] = it;
                pos[x]++;
            }
            a = a_new;
        }
        {
            vector<int> cnt(n);
            for (int i = 0; i < n; i++)
                cnt[a[i].first.first]++;
            vector<int> pos(n);
            vector<pair<pair<int, int>, int>> a_new(n);
            pos[0] = 0;
            for (int i = 1; i < n; i++)
                pos[i] = pos[i - 1] + cnt[i - 1];
            for (auto it : a) {
                int x = it.first.first;
                a_new[pos[x]] = it;
                pos[x]++;
            }
            a = a_new;
        }
    }
    vector<int> construct_suffix_array(string &s) {
        s += "$";
        int n = s.size();
        // intial configuration for k=0
        {
            vector<pair<char, int>> a(n);
            for (int i = 0; i < n; i++)
                a[i] = {s[i], i};
            sort(a.begin(), a.end());
            for (int i = 0; i < n; i++)
                p[i] = a[i].second;
            c[p[0]] = 0;
            for (int i = 1; i < n; i++)
                if (a[i].first == a[i - 1].first)
                    c[p[i]] = c[p[i - 1]];
                else
                    c[p[i]] = c[p[i - 1]] + 1;
        }
        int k = 0;
        while ((1 << k) < n) {
            // transition from k -> k+1
            vector <pair<pair<int, int>, int>> a(n);
            for (int i = 0; i < n; i++)
                a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
            radix_sort(a);
            for (int i = 0; i < n; i++)
                p[i] = a[i].second;
            c[p[0]] = 0;
            for (int i = 1; i < n; i++)
                if (a[i].first == a[i - 1].first)
                    c[p[i]] = c[p[i - 1]];
                else
                    c[p[i]] = c[p[i - 1]] + 1;
            k++;
        }
        return p;
    }
};
