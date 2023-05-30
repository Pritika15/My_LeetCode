class MyHashMap {
public:
    vector<vector<pair<int,int>>>vec;
    int size=1000;
    MyHashMap() {
     vec.resize(size);   
    }
    int hash(int key)
    {
        return key%size;
    }
    void put(int key, int value) {
        int index=hash(key);
        vector<pair<int,int>> &row=vec[index];
        for(auto itr=row.begin();itr!=row.end();itr++)
        {
            if(itr->first==key)
            {
                itr->second=value;
                return;
            }
        }
        row.push_back(make_pair(key,value));
    }
    
    int get(int key) {
        int index=hash(key);
        vector<pair<int,int>> &row=vec[index];
        for(auto itr=row.begin();itr!=row.end();itr++)
        {
            if(itr->first==key)
            {
                return itr->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index=hash(key);
        vector<pair<int,int>> &row=vec[index];
        for(auto itr=row.begin();itr!=row.end();itr++)
        {
            if(itr->first==key)
            {
                row.erase(itr);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */