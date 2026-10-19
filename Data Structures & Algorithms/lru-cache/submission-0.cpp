class LRUCache {
    int capacity;
    list<pair<int, int>> mlist;
    unordered_map<int, list<pair<int, int>>::iterator> mmap;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        //lookup key
        auto it = mmap.find(key);
        //if not found return -1
        if(it == mmap.end()) {
            return -1;
        }
        //else found - go to the item location and extract value
        int value = it->second->second;
        //erase existing entry and add that item to front
        mlist.erase(it->second);
        mlist.push_front({key, value});
        //update iterator with the new location of the item
        mmap[key] = mlist.begin();
        //return the value found
        return value;
        
    }
    
    void put(int key, int value) {
        //lookup key
        auto it = mmap.find(key);
        //if found -,
        if (it != mmap.end()) { 
            ////bring to front and update value.
            mlist.erase(it->second);
        } else {
            // if (mmap.size() >= capacity) {
            // ////if on capacity ---- remove last entry from the list
            //     auto lastEntry = mlist.end();
            //     lastEntry--;
            //     mmap.erase(key);
            //     mlist.erase(lastEntry);
            // }
            if (mmap.size() >= capacity) {
                // Get the last item's key to clean up the map
                int keyToRemove = mlist.back().first; 
                
                mmap.erase(keyToRemove); // 1. Erase from map first
                mlist.pop_back();        // 2. Erase from list safely
            }
        }
        ////update iterator with the new location of the item
        mlist.push_front({key, value});
        mmap[key] = mlist.begin();
    }
};
