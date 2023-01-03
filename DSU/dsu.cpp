struct dsu {
    vector<int> parent, size, minimum, maximum;

    dsu(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        minimum.resize(n + 1);
        maximum.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            maximum[i] = i;
            minimum[i] = i;
        }
    }

    int get(int a) {
        if (parent[a] == a)
            return a;
        return parent[a] = get(parent[a]);
    }

    void unite(int a, int b) {
        int ulpar_a = get(a);
        int ulpar_b = get(b);
        if (ulpar_a == ulpar_b)
            return;
        if (size[ulpar_a] > size[ulpar_b]) {
            parent[ulpar_b] = ulpar_a;
            size[ulpar_a] += size[ulpar_b];
            minimum[ulpar_a] = min(minimum[ulpar_a], minimum[ulpar_b]);
            maximum[ulpar_a] = max(maximum[ulpar_a], maximum[ulpar_b]);
        }
        else  {
            parent[ulpar_a] = ulpar_b;
            size[ulpar_b] += size[ulpar_a];
            minimum[ulpar_b] = min(minimum[ulpar_a], minimum[ulpar_b]);
            maximum[ulpar_b] = max(maximum[ulpar_a], maximum[ulpar_b]);
        }
    }

    int getMinimum(int a) {
        int par_a = get(a);
        return minimum[par_a];
    }

    int getMaximum(int a) {
        int par_a = get(a);
        return maximum[par_a];
    }
    int getSize(int a) {
        int par_a = get(a);
        return size[par_a];
    }
};