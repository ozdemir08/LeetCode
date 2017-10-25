class LFUCache {
private:
	int capacity;
	dequeue<int, int> cache;
	unordered_map<int, dequeue<int, int>::iterator> keyToCache; 

public:
    LFUCache(int c) {
    	capacity = c;
    }
    
    int get(int key) {
        dequeue<int, int>::iterator it = keyToCache.find(key);
        if(it == keyToCache.end())
        	return -1;
        int key = it -> first;
        int val = it -> second;
        cache.erase(it);
        put(key, val);
        keyToCache[key] = cache.end() - 1;
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */