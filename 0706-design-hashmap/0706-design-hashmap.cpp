class MyHashMap {
public:
    vector<int>vec;
    int size;
    MyHashMap() {
    size=1000002;
    vec.resize(size);
    for(int i=0;i<size;i++)
        vec[i]= -1;
    }
    
    void put(int key, int value) {
        vec[key]=value;
        
    }
    
    int get(int key) {
        if(vec[key]!= -1)
            return vec[key];
        else
            return -1;
    }
    
    void remove(int key) {
     vec[key]= -1;   
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */