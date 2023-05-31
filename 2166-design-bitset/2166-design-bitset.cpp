class Bitset {
public:
    string ans, flipped;
    int set=0,n;
    
    Bitset(int size) {
    ans=string(size,'0');
    flipped=string(size,'1');
    n=size;    
    }
    
    void fix(int idx) {
    if(ans[idx]=='0') set++;
        ans[idx]='1';
        flipped[idx]='0';
    }
    
    void unfix(int idx) {
    if(ans[idx]=='1') set--;
        ans[idx]='0';
        flipped[idx]='1';
    }
    
    void flip() {
       ans.swap(flipped);
        set=n-set;
    }
    
    bool all() {
        return set==n;
    }
    
    bool one() {
        return set>=1;
    }
    
    int count() {
        return set;
    }
    
    string toString() {
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */