class LRUCache {
    typedef list<pair<int,int>> LRULIST;
    typedef list<pair<int,int>>::iterator LRULIST_IT;
public:
    LRUCache(int capacity) {
        _capacity=capacity;
    }
    
    int get(int key) {
        auto mIt=_kItMap.find(key);
        if(mIt == _kItMap.end())
        {
            return -1;
        }
        else
        {
            LRULIST_IT ltIt=mIt->second;
            int value=ltIt->second;

            //调整顺序
             _LRUList.splice(_LRUList.end(),_LRUList,ltIt);

             return value;
        }
    }
    
    void put(int key, int value) {
        //如果不在cache,容量不满，就插入
        auto mIt= _kItMap.find(key);
        if(mIt == _kItMap.end())
        {   
            if(_LRUList.size()>=_capacity)
            {
                //容量满了，删除头
                _kItMap.erase(_LRUList.front().first);
                _LRUList.pop_front();
            }
            _LRUList.push_back(make_pair(key,value));//尾插
            _kItMap[key] = --_LRUList.end(); //list最后一个元素的迭代器
        }
        //如果在就更新一下
        else
        {
            //更新
            LRULIST_IT ltIt=mIt->second;
            ltIt->second=value;
            //调整顺序
            //method1:保存list中的值，然后尾插一个新的，然后更新map
            //method2: splice
            _LRUList.splice(_LRUList.end(),_LRUList,ltIt);
        }
    }

    private:
    list<pair<int,int>>                                _LRUList;//插入删除
    unordered_map<int ,list<pair<int,int>>::iterator>  _kItMap;//找值
    int                                                _capacity;
};