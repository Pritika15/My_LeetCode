class MyHashSet {
public:
    vector<list<int>>vec;
    int size;
    MyHashSet() {
        // size=1000002;
        // vec.resize(size);
        size=1000;
        vec.resize(size);
    }
    int hash(int key)
    {
        return key%size;
    }
    
    list<int>:: iterator search(int key)
    {
        int i=hash(key);
        return find(vec[i].begin(),vec[i].end(),key);
    }
    void add(int key) {
        // vec[key]=1;
        if(contains(key)) return;
        int i=hash(key);
        vec[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i=hash(key);
        vec[i].erase(search(key));
    }
    
    bool contains(int key) {
        // return vec[key];
        int i=hash(key);
        if(search(key)!= vec[i].end()) return true;
        else
            return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */