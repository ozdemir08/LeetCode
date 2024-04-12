class RandomizedCollection {
private:
    vector<int> numbers; 
    unordered_map<int, unordered_set<int> > numToIndices; 

public:

    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        numbers.push_back(val);
        bool notExists = numToIndices[val].empty();
        numToIndices[val].insert(numbers.size()-1);
        return notExists;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(numToIndices[val].empty())
            return false;

        int ind = *(numToIndices[val].begin());
        numToIndices[val].erase(ind);

        int lastNum = numbers.back(), lastInd = numbers.size() - 1;
        swap(numbers[ind], numbers.back());
        numbers.pop_back();

        numToIndices[lastNum].insert(ind);
        numToIndices[lastNum].erase(lastInd);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if(numbers.empty())
            return -1;
        int ind = rand()%(numbers.size());
        return numbers[ind];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */