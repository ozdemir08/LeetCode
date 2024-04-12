class LFUCache {
private:
    int capacity, size, minFreq;	
    unordered_map<int, pair<int, int> > keyToPair;
    unordered_map<int, list<int> > freqToKeys;
    unordered_map<int, list<int>::iterator > keyToIterator;

    // remove all data related to given key
    void remove(int key){
    	int freq = keyToPair[key].second;
    	keyToPair.erase(key);
    	auto it = keyToIterator[key];
    	freqToKeys[freq].erase(it);
    	keyToIterator.erase(key);
    }

    // put key, val, freq and check if minFreq is increased
    void put(int key, int val, int freq){
    	keyToPair[key] = make_pair(val, freq);
    	freqToKeys[freq].push_back(key);
    	keyToIterator[key] = --freqToKeys[freq].end();
        
        if(freqToKeys[minFreq].empty())
            minFreq++;
    }

public:
    LFUCache(int c) {
        capacity = c;
        size = 0;
        minFreq = 1;
    }
    
    int get(int key) {
    	auto pair = keyToPair.find(key);
    	// if key not exists
    	if(pair == keyToPair.end())
    		return -1;
    	int val = pair -> second . first;
    	int freq = pair -> second . second;

    	// increase frequency
    	remove(key);
    	put(key, val, freq + 1);
    	return val;
    }
    
    void put(int key, int value) {
    	int old_val = get(key);

    	// if key not exists, put
    	if(old_val == -1){
    		size++;
            put(key, value, 1);

            // check if cache reached capacity
    		if(size > capacity){
    			// remove the first of minfreq list
    			int remove_key = freqToKeys[minFreq].front();
                remove(remove_key);
    		}
    		minFreq = 1;
	    }
	    // if key exists, increase frequency.
	    else{
	    	int freq = keyToPair[key].second;
	    	remove(key);
	    	put(key, value, freq + 1);
	    }
	}
};