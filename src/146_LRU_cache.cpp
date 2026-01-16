#include <iostream>
#include <unordered_map>

class DNode {
public:
    DNode(int key, int value) {
        this->key = key;
        this->value = value;
        pre = next = nullptr;
    }

    int key, value;
    DNode *pre, *next;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap_ = capacity;
        head_ = new DNode(-1, -1);
        tail_ = new DNode(-1, -1);
        head_->next = tail_;
        tail_->pre = head_;
    }

    int get(int key) {
        if (u_map_.count(key)) {
            DNode* temp = u_map_[key];
            remove(temp);
            u_map_.erase(key);
            head_insert(temp);
            u_map_[key] = temp;
            return temp->value;
        }

        return -1;
    }

    void put(int key, int value) {
        if (u_map_.count(key)) {
            DNode* temp = u_map_[key];
            remove(temp);
            temp->value = value;
            head_insert(temp);
        } else {
            DNode* ndnode = new DNode(key, value);
            head_insert(ndnode);
            u_map_[key] = ndnode;
            if (u_map_.size() > cap_) {
                DNode* temp = tail_->pre;
                remove(temp);
                u_map_.erase(temp->key);
                delete temp;
            }
        }
    }

private:
    int cap_;
    DNode *head_, *tail_;
    std::unordered_map<int, DNode*> u_map_;

    void remove(DNode* dnode) {
        dnode->pre->next = dnode->next;
        dnode->next->pre = dnode->pre;
    }

    void head_insert(DNode* dnode) {
        DNode* temp = head_->next;
        temp->pre = dnode;
        head_->next = dnode;
        dnode->pre = head_;
        dnode->next = temp;
    }
};

int main(int ragc, char const* argv[]) {

    // LRUCache lru(2);
    // lru.put(1, 1);
    // lru.put(2, 2);
    // std::cout << lru.get(1) << "\n";
    // lru.put(3, 3);
    // std::cout << lru.get(2) << "\n";
    // lru.put(4, 4);
    // std::cout << lru.get(1) << "\n";
    // std::cout << lru.get(3) << "\n";
    // std::cout << lru.get(4) << "\n";

    LRUCache lru(2);
    std::cout << lru.get(2) << "\n";
    lru.put(2, 6);
    std::cout << lru.get(1) << "\n";
    lru.put(1, 5);
    lru.put(1, 2);
    std::cout << lru.get(1) << "\n";
    std::cout << lru.get(2) << "\n";

    // LRUCache lru(2);
    // lru.put(2, 1);
    // lru.put(1, 1);
    // lru.put(2, 3);
    // lru.put(4, 1);
    // std::cout << lru.get(1) << "\n";
    // std::cout << lru.get(2) << "\n";

    return 0;
}

// #include <list>
// #include <iostream>

// class LRUCache {
// public:
//     LRUCache(int capacity) {
//         capacity_ = capacity;
//     }

//     int get(int key) {
//         std::pair<int, int> use = {-1, -1};

//         for (const auto& pair : lru_) {
//             if (pair.first == key) {
//                 use = pair;
//                 lru_.remove(pair);
//                 break;
//             }
//         }
//         if (use.first != -1) {
//             lru_.push_front(use);
//             return use.second;
//         }

//         return -1;
//     }

//     void put(int key, int value) {
//         bool is_find = false;
//         for (auto& pair : lru_) {
//             if (pair.first == key) {
//                 pair.second = value;
//                 is_find = true;
//             }
//             break;
//         }

//         if (!is_find) {
//             if (lru_.size() >= capacity_) {
//                 lru_.pop_back();
//             }
//             lru_.emplace_front(key, value);
//         }
//     }

// private:
//     int capacity_ = 0;
//     std::list<std::pair<int, int>> lru_;
// };

// int main(int ragc, char const* argv[]) {

//     // LRUCache lru(2);
//     // lru.put(1, 1);
//     // lru.put(2, 2);
//     // std::cout << lru.get(1) << "\n";
//     // lru.put(3, 3);
//     // std::cout << lru.get(2) << "\n";
//     // lru.put(4, 4);
//     // std::cout << lru.get(1) << "\n";
//     // std::cout << lru.get(3) << "\n";
//     // std::cout << lru.get(4) << "\n";

//     LRUCache lru(2);
//     std::cout << lru.get(2) << "\n";
//     lru.put(2, 6);
//     std::cout << lru.get(1) << "\n";
//     lru.put(1, 5);
//     lru.put(1, 2);
//     std::cout << lru.get(1) << "\n";
//     std::cout << lru.get(2) << "\n";

//     // lru.put(4, 4);
//     // std::cout << lru.get(1) << "\n";
//     // std::cout << lru.get(3) << "\n";
//     // std::cout << lru.get(4) << "\n";

//     return 0;
// }