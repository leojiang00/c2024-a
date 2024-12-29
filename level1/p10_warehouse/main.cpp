#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

const string INVENTORY_FILE = "D://Users//leojiang//CLionProjects//c2024-a//level1//p10_warehouse//inventory.txt";

map<string, int> load_inventory() {
    map<string, int> inventory;
    ifstream file(INVENTORY_FILE);
    string item;
    int quantity;

    if (file.is_open()) {
        while (file >> item >> quantity) {
            inventory[item] = quantity;
        }
        file.close();
    } else {
        cout << "can't open file." << endl;
    }
    return inventory;
}

void save_inventory(const map<string, int>& inventory) {
    ofstream file(INVENTORY_FILE);
    if (file.is_open()) {
        for (const auto& item : inventory) {
            file << item.first << " " << item.second << endl;
        }
        file.close();
    } else {
        cout << "can't save file" << endl;
    }
}

void display_inventory(const map<string, int>& inventory) {
    cout << "goods list:" << endl;
    for (const auto& item : inventory) {
        cout << "mode: " << item.first << ", number: " << item.second << endl;
    }
}

void add_to_inventory(map<string, int>& inventory, const string& item, int quantity) {
    if (inventory.find(item) != inventory.end()) {
        inventory[item] += quantity;
    } else {
        inventory[item] = quantity;
    }
    cout << "mode " << item << " have already loaded,number:" << quantity << endl;
}

void remove_from_inventory(map<string, int>& inventory, const string& item, int quantity) {
    if (inventory.find(item) != inventory.end() && inventory[item] >= quantity) {
        inventory[item] -= quantity;
        cout << "mode " << item << " have already unloaded,number:" << quantity << endl;
    } else {
        cout << "cant" << endl;
    }
}

int main() {
    map<string, int> inventory = load_inventory();
    while (true) {
        cout << "\nsystem" << endl;
        cout << "1.show the data list" << endl;
        cout << "2. load" << endl;
        cout << "3. unload" << endl;
        cout << "4. quit" << endl;
        int choice;
        cin >> choice;
        cin.ignore(); // 忽略之前读取的换行符

        switch (choice) {
            case 1:
                display_inventory(inventory);
                break;
            case 2: {
                string item;
                int quantity;
                cout << "mode?:"<<endl;
                getline(cin, item); // 正确使用getline
                cout << "number?:"<<endl;
                cin >> quantity;
                add_to_inventory(inventory, item, quantity);
                break;
            }
            case 3: {
                string item;
                int quantity;
                cout << "mode?:";
                getline(cin, item); // 正确使用getline
                cout << "number?:";
                cin >> quantity;
                remove_from_inventory(inventory, item, quantity);
                break;
            }
            case 4:
                save_inventory(inventory);
                cout << "quit and save" << endl;
                return 0;
            default:
                cout << "NO。" << endl;
        }
    }
    return 0;
}