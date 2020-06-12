class RandomizedSet {
public:
    /** Initialize your data structure here. */
    set<int> s;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(isPresent(val)){
            return false;
        }
        s.insert(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(isPresent(val)){
            s.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand()%s.size();
        set<int> :: iterator it = s.begin();
        for(int i = 0;i < idx;i++){
            it++;
        }
        return *it;
    }
    
    bool isPresent(int val){
        return !(s.find(val) == s.end());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
