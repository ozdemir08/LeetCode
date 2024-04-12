class LRUCache{
public:
    list< pair<int,int> > cache;
    int max_capacity;
    map<int, list< pair<int,int> >::iterator> M;

    LRUCache(int capacity) {
        max_capacity = capacity;
    }

    int get(int key) {
        map<int, list< pair<int,int> >::iterator>::iterator it = M.find(key);
        if(it == M.end())
            return -1;
        int value = it -> second -> second;
        set(key, value);
        return value;
    }

    void set(int key, int value) {
        map<int, list< pair<int,int> >::iterator>::iterator it = M.find(key);
        if(it == M.end()){
            if(cache.size() == max_capacity){
                pair<int,int> del = cache.back();
                cache.pop_back();
                M.erase(M.find(del.first));
            }

        }
        else{
            cache.erase(it -> second);
            M.erase(it);
        }
        cache.push_front(make_pair(key,value));
        M[key] = cache.begin();
    }
};
