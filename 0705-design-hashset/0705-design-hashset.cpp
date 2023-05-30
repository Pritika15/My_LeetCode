class MyHashSet {
public:
    vector<int>vec;
    int size;
    MyHashSet() {
        size=1000002;
        vec.resize(size);
    }
    
    void add(int key) {
        vec[key]=1;
    }
    
    void remove(int key) {
        vec[key]=0;
    }
    
    bool contains(int key) {
        return vec[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */