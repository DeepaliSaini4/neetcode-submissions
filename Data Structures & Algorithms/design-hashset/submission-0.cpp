class MyHashSet {
public:
    vector<bool> meow ;
    MyHashSet() {
        meow = vector<bool>(1000001,false);
    }
    
    void add(int key) {
        meow[key]=true;
    }
    
    void remove(int key) {
        meow[key] = false;
    }
    
    bool contains(int key) {
      return (meow[key]);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */