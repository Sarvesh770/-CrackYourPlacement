class LRUCache {
public:
    unordered_map<int,int>m;
    unordered_map<int,list<int>::iterator>address;
    list<int>ls;
    int size;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        size =  0;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        list<int>::iterator it = address[key];
        ls.erase(it);
        address.erase(key);
        ls.push_front(key);
        address[key] = ls.begin();
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            ls.erase(address[key]);
            address.erase(key);
            m.erase(key);
            size--;
        }
        if(size == cap){
            int k = ls.back();
            ls.pop_back();
            address.erase(k);
            m.erase(k);
            size--;
        }
        size++;
        ls.push_front(key);
        address[key] = ls.begin();
        m[key] = value;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */